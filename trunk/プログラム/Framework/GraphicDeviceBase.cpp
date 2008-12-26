/*******************************************************************************/
/**
 * @file GraphicDeviceBase.cpp.<br>
 * 
 * @brief グラフィックデバイス基底クラスソースファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GraphicDeviceBase.h"
#include	<Ngl/TextureFilterColorKey.h>
#include	<Ngl/TextureFilterColorKeyAuto.h>
#include	<Ngl/DDS/TextureCreatorDDS.h>
#include	<Ngl/Msh/MshExCreator.h>
#include	<Ngl/Msh/SklCreator.h>
#include	<Ngl/Msh/AnmCreator.h>
#include	<Ngl/Oct/MapMeshOct.h>
#include	<Ngl/EffectExtension.h>
#include	<Ngl/IMesh.h>
#include	<Ngl/IEffect.h>
#include	<Ngl/Utility.h>
#include	<cassert>

#include	<Ngl/OpenGL/Texture2DGL.h>

/**
 * @brief コンストラクタ<br>
 * 
 * @param[in] frame フレームワーク.
 */
GraphicDeviceBase::GraphicDeviceBase( Ngl::IFrameWork& frame ):
	frame_( frame ),
	renderer_( 0 )
{
	// デフォルトのライトパラメータを設定
	LightDesc ld;
	ld.ambientColor = Ngl::COLOR4_WHITE;
	ld.diffuseColor = Ngl::COLOR4_WHITE;
	ld.specularColor = Ngl::COLOR4_WHITE;

	lightContainer_[ 0 ] = ld;
}



/**
 * @brief デストラクタ<br>
 * 
 * @param[in] なし.
 */
GraphicDeviceBase::~GraphicDeviceBase()
{}

	

/**
 * @brief 終了処理<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::End()
{
	// 四角形ポリゴンを削除
	quad_.end();

	// リソースを全て削除
	ClearResource();

	// レンダラーを削除
	delete renderer_;
}
	
	

/**
 * @brief ビューポートの設定<br>
 * 
 * @param[in] desc ビューポート記述子.
 * @return なし.
 */
void GraphicDeviceBase::Viewport(const ViewportDesc& desc)
{
	renderer_->setViewport( desc );
}



/**
 * @brief ビューポートを取得<br>
 * 
 * @param[in] なし.
 * @return ビューポート記述子.
 */
const ViewportDesc& GraphicDeviceBase::Viewport()
{
	return renderer_->getViewport();
}
	
	

/**
 * @brief 画面を消去<br>
 * 
 * @param[in] color 消去するカラー.
 * @return なし.
 */
void GraphicDeviceBase::Clear( const Color4& color )
{
	// カラーバッファを消去
	renderer_->clearColorBuffer( color.r, color.g, color.b, color.a );

	// デプスステンシルバッファの消去
	renderer_->clearDepthStencilBuffer( true, true );
}



/**
 * @brief 透視変換行列を設定<br>
 * 
 * @param[in] fov 視野角.
 * @param[in] aspect 画面のアスペクト比.
 * @param[in] znear 近クリップ面.
 * @param[in] zfar 遠クリップ面.
 * @return なし.
 */
void GraphicDeviceBase::Perspective(float fov, float aspect, float znear, float zfar)
{
	matProjection_.setPerspectiveRH( fov, aspect, znear, zfar );
}



/**
 * @brief 視野変換行列を設定<br>
 * 
 * @param[in] eye 始点位置.
 * @param[in] at 注視点位置.
 * @param[in] up 上方向のベクトル
 * @return なし.
 */
void GraphicDeviceBase::LookAt(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	matView_.setLookAtRH( eye, at, up );
}



/**
 * @brief 指定の座標変換行列を取得<br>
 * 
 * @param[in] flag 取得する座標変換行列のフラグ.
 * @return なし.
 */
Matrix4 GraphicDeviceBase::GetTransformMatrix(TransformType flag)
{
	switch( flag )
	{
	case MAT_VIEW:
		return matView_;
		break;
	case MAT_PROJECTION:
		return matProjection_;
		break;
	default:
		return Ngl::MATRIX4_IDENTITY;
		break;
	}
}

	

/**
 * @brief 四角形ポリゴンを描画<br>
 * 
 * @param[in] desc 四角形ポリゴン記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render( const QuadDesc& desc )
{
	// エフェクトを取得
	Ngl::IEffect* ef = effectManager_[ desc.effectID ]->getEffect();

	// 拡大縮小行列を作成
	float width		= desc.rect.right - desc.rect.left;
	float height	= desc.rect.bottom - desc.rect.top;
	width = width;
	height = -height;
	Vector2 size( width, height );
	Ngl::Matrix4 matScale;
	matScale.setScale( width, height, 1.0f );

	// 描画位置座標を求める
	Vector3 pos;
	pos.x = desc.rect.left;
	pos.y = desc.rect.top;
	
	// 平行移動行列を作成
	Ngl::Matrix4 matPos;
	matPos.setTranslate( pos );
	
	// モデルビュープロジェクション行列を作成
	Matrix4 g_ModelViewProjection = matScale * matPos * desc.matrix * matView_ * matProjection_;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// 色を設定
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// テクニックを設定
	std::string technique = desc.techniqueName.c_str();
	if( desc.blendFunc == BLEND_ADD ){
		technique += "Add";
	}
	ef->technique( technique.c_str() );

	// テクスチャIDが設定されているか
	if( desc.textureID != 0 ){
		// テクスチャを取得
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];

		// ユーザー指定のテクスチャ座標を設定
		if( desc.srcRect != Rect( 0.0f, 0.0f, 0.0f, 0.0f ) ){
			ef->setVector(
				"g_TextureRect",
				desc.srcRect.left	/ tex->desc().width,
				desc.srcRect.top	/ tex->desc().height,
				desc.srcRect.right	/ tex->desc().width,
				desc.srcRect.bottom / tex->desc().height
				);
		}
		// フルサイズのテクスチャ座標を設定
		else{
			ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);
		}

		// エフェクトにテクスチャを設定
		ef->setTexture( desc.textureName.c_str(), tex );
	}
	else{
		ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);
	}

	// ポリゴンを描画
	quad_.draw( renderer_, ef );
}



/**
 * @brief 2Dスプライトを描画<br>
 * 
 * @param[in] desc スプライト記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render( const SpriteDesc& desc )
{
	/*
	// エフェクトを取得
	Ngl::IEffect* ef = effectManager_[ desc.effectID ]->getEffect();

	// ビュー変換行列を作成
	Ngl::Matrix4 matView;
	matView.setIdentitiy();

	// 正射影変換行列を作成
	Ngl::Matrix4 matProj;
	matProj.setOrthoRH( -0.5f, 0.5f, 0.5f, -0.5f, -1.0f, 1.0f );

	// 拡大縮小行列を作成
	float swidth	= desc.rect.right - desc.rect.left;
	float sheight	= desc.rect.bottom - desc.rect.top;
	float width = swidth * ( 1.0f / WINDOW_WIDTH );	// 3Dの座標系に変換
	float height = sheight * ( 1.0f / WINDOW_HEIGHT );	// 3Dの座標系に変換
	Ngl::Matrix4 matScale;
	matScale.setScale( width, height, 1.0f );

	// 描画位置座標を求める
	Vector3 pos;
	pos.x = desc.rect.left;
	pos.y = -desc.rect.top;
	
	// 平行移動行列を作成
	Ngl::Matrix4 matPos;
	pos.x = ( pos.x * ( 1.0f / WINDOW_WIDTH ) ) - 0.5f;		// 3Dの座標系に変換
	pos.y = ( pos.y * ( 1.0f / WINDOW_HEIGHT ) ) + 0.5f;	// 3Dの座標系に変換
	matPos.setTranslate( pos );

	// 中心座標を求める
	Vector3 inPos( 0.5f, -0.5f, 0.0f );
	inPos.x -= (desc.center.x / swidth);
	inPos.y += (desc.center.y / sheight);
	Ngl::Matrix4 matInPos;
	matInPos.setTranslate( inPos );

	// 回転行列を作成
	Ngl::Matrix4 matRotateZ;
	matRotateZ.setRotateZ( desc.angle );

	// モデルビュープロジェクション行列を作成
	Matrix4 g_ModelViewProjection = matInPos * matRotateZ * matScale * matPos * matView * matProj;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// スプライトの色を設定
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// テクニックを設定
	ef->technique( desc.techniqueName.c_str() );

	// テクスチャIDが設定されているか
	if( desc.textureID != 0 ){
		// テクスチャを取得
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];
		Ngl::OpenGL::Texture2DGL* t = static_cast< Ngl::OpenGL::Texture2DGL* >( tex );
		t->texture();

		// ユーザー指定のテクスチャ座標を設定
		if( desc.srcRect != Rect( 0.0f, 0.0f, 0.0f, 0.0f ) ){
			ef->setVector(
				"g_TextureRect",
				desc.srcRect.left	/ tex->desc().width,
				desc.srcRect.top	/ tex->desc().height,
				desc.srcRect.right	/ tex->desc().width,
				desc.srcRect.bottom / tex->desc().height
				);
		}
		// フルサイズのテクスチャ座標を設定
		else{
			ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);
		}

		// エフェクトにテクスチャを設定
		ef->setTexture( desc.textureName.c_str(), tex );
	}
	else{
		ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);	
	}

	// ポリゴンを描画
	quad_.draw( renderer_, ef );
	*/

	Vector2 m_size;
	m_size.x = desc.rect.right - desc.rect.left;
	m_size.y = desc.rect.bottom - desc.rect.top;
	Rect srcRect = Rect(0.0f, 0.0f, 1.0f, 1.0f);

	if(desc.textureID != 0)
	{
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];
		Ngl::OpenGL::Texture2DGL* t = static_cast< Ngl::OpenGL::Texture2DGL* >( tex );
		glBindTexture(GL_TEXTURE_2D, t->texture());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glEnable(GL_TEXTURE_2D);

		if(desc.srcRect.left != 0) srcRect.left = desc.srcRect.left / t->desc().width;
		if(desc.srcRect.top != 0) srcRect.top = desc.srcRect.top / t->desc().height;
		if(desc.srcRect.right != 0) srcRect.right = desc.srcRect.right / t->desc().width;
		if(desc.srcRect.bottom != 0) srcRect.bottom = desc.srcRect.bottom / t->desc().height;
	}
	
	glPushMatrix();

	glTranslatef(desc.rect.left, desc.rect.top, 0.0f);
	glRotatef(desc.angle, 0.0f, 0.0f, 1.0f);

	if(desc.reverse == true)
	{
		glDisable( GL_CULL_FACE );
	} else
	{
		glEnable( GL_CULL_FACE );
	}
	glDepthMask( GL_FALSE );
	glBegin(GL_QUADS);
		glColor4f(desc.color.r, desc.color.g, desc.color.b, desc.color.a);

		glTexCoord2f( srcRect.left, srcRect.top);
		if(!desc.reverse)
		{
			glVertex3f( 0.0f, 0.0f, 0.0f);
		} else
		{
			glVertex3f( m_size.x, 0.0f, 0.0f);
		}

		glTexCoord2f( srcRect.left, srcRect.bottom);
		if(!desc.reverse)
		{
			glVertex3f( 0.0f, m_size.y, 0.0f);
		} else
		{
			glVertex3f( m_size.x, m_size.y, 0.0f);
		}

		glTexCoord2f( srcRect.right, srcRect.bottom);
		if(!desc.reverse)
		{
			glVertex3f( m_size.x, m_size.y, 0.0f);
		} else
		{
			glVertex3f( 0.0f, m_size.y, 0.0f);
		}

		glTexCoord2f( srcRect.right, srcRect.top);
		if(!desc.reverse)
		{
			glVertex3f( m_size.x, 0.0f, 0.0f);
		} else
		{
			glVertex3f( 0.0f, 0.0f, 0.0f);
		}

	glEnd();
	glDepthMask( GL_TRUE );

	glPopMatrix();
}

/**
 * @brief ゲージを描画<br>
 * 
 * @param[in] desc ゲージ記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render(const GaugeDesc &desc_)
{
	SpriteDesc sd;

	GaugeDesc desc = desc_;

	if (desc.textureRec1 == Rect(0,0,0,0))
	{
		desc.textureRec1 = Rect(0,0,(float)GetTextureDesc(desc.texture1).width,(float)GetTextureDesc(desc.texture1).height);
	}
	if (desc.textureRec2 == Rect(0,0,0,0))
	{
		desc.textureRec2 = Rect(0,0,(float)GetTextureDesc(desc.texture2).width,(float)GetTextureDesc(desc.texture2).height);
	}

	sd.textureID = desc.texture2;
	
	sd.rect = Rect(desc.position.x,desc.position.y,desc.position.x+desc.size.x,desc.position.y+desc.size.y);
	sd.srcRect = Rect(desc.textureRec2.left,desc.textureRec2.top,desc.textureRec2.right,desc.textureRec2.bottom);
	Render( sd );

	sd.textureID = desc.texture1;
	
	sd.rect = Rect(desc.position.x,desc.position.y,desc.position.x+(desc.size.x/desc.max*desc.point),desc.position.y+desc.size.y);
	sd.srcRect = Rect(desc.textureRec1.left,desc.textureRec1.top,desc.textureRec1.left+(desc.max/(desc.textureRec1.right-desc.textureRec1.left)*desc.point),desc.textureRec1.bottom);
	Render( sd );
}

/**
 * @brief テキストを描画<br>
 * 
 * @param[in] desc テキスト記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render(const TextDesc &desc)
{
	HFONT			hFont;
	BYTE*			pBitmap;
	SIZEL			BitmapSize;

	/* 各種レンダリングモードの退避 */
	glPushAttrib( GL_ENABLE_BIT );
	glPushMatrix();

	/* テクスチャを無効にする */
	glDisable( GL_TEXTURE_2D );
	glDisable( GL_TEXTURE_1D );

	if(( desc.color.r == 0.0f) && (desc.color.g == 0.0f) && (desc.color.b == 0) && (desc.color.a == 0.0f))
	{
		glColor4f(desc.color.r, desc.color.g, desc.color.b, desc.color.a);
	}

	/* フォントを作成する */
	hFont = CreateFontHandler( desc.code, desc.size, desc.font.c_str() );

	/* ビットマップフォントの作成 */
	if ( CreateStringBitmapFont( 
			hFont, desc.string.c_str(), &pBitmap, &BitmapSize ) == true )
	{
		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		/* ビットマップフォントを描画する */
		glRasterPos2f(desc.position.x, desc.position.y + BitmapSize.cy );
		glBitmap( BitmapSize.cx, BitmapSize.cy, 0.0f, 0.0f, 0.0f, 0.0f, pBitmap );

		/* ビットマップフォントの解放 */
		free( pBitmap );
	}

	/* フォントを消滅させる */
	DeleteObject( hFont );

	/* レンダリングモードの復帰 */
	glPopMatrix();
	glPopAttrib();
}

HFONT GraphicDeviceBase::CreateFontHandler(unsigned int FontCode, unsigned int FontPoint, const char* pFontName)
{
	HFONT		hFont;
	DWORD		Bold;
	bool		bItalic;
	bool		bUline;
	bool		bSout;
	HDC			hDC;

	/* フォントの属性を設定する */
	Bold    = ( ( FontCode & FONT_CODE_BOLD      ) != 0 ) ? FONT_CODE_BOLD: FONT_CODE_NORMAL;
	bItalic = ( ( FontCode & FONT_CODE_ITALIC    ) != 0 ) ? true: false;
	bUline  = ( ( FontCode & FONT_CODE_UNDERLINE ) != 0 ) ? true: false;
	bSout   = ( ( FontCode & FONT_CODE_STRIKEOUT ) != 0 ) ? true: false;

	/* デバイスコンテキストの取得 */
	hDC = wglGetCurrentDC();

	/* フォントを作成する */
	hFont = CreateFont
	(
		FontPoint, 0, 0, 0,
		Bold, bItalic, bUline, bSout,
		SHIFTJIS_CHARSET,
		OUT_STROKE_PRECIS,
		CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		pFontName
	);

	return	hFont;
}

bool GraphicDeviceBase::CreateStringBitmapFont(HFONT hFont,const char* pString, BYTE** ppBitmap, PSIZEL pBitmapSize)
{

	HDC				hDC;
	BITMAP			bmp;
	HBITMAP			hbmp;
	HFONT			hFontOld;
	HBITMAP			hPrevBmp;
	HFONT			hPrevFont;
	HDC				hMemDC;
	DWORD			BitsSize;
	BITMAP			bi;
	int				len;

	/* 文字列の長さを求める */
	if ( ( len = lstrlen( pString ) ) == 0 )
	{
		return	false;
	}

	/* デバイスコンテキストを取得 */
	hDC = wglGetCurrentDC();


	/* 現在のデバイスコンテキストのフォントハンドラを取得 */
	hFontOld = (HFONT)SelectObject( hDC, hFont );

	/* ビットマップ文字列のサイズを取得する */
	GetTextExtentPoint32( hDC, pString, len, pBitmapSize );

	/* ビットマップを作成する */
	memset( &bmp, 0, sizeof( BITMAP ) );
	bmp.bmWidth      = pBitmapSize->cx;
	bmp.bmHeight     = pBitmapSize->cy;
	bmp.bmWidthBytes = ( ( pBitmapSize->cx + 7 ) / 8 + 1 ) & (~1);
	bmp.bmPlanes     = 1;
	bmp.bmBitsPixel  = 1;
	bmp.bmBits       = calloc( bmp.bmWidthBytes * pBitmapSize->cy, sizeof(BYTE) );
	hbmp = CreateBitmapIndirect( &bmp );

	/* ビットマップイメージを解放する */
	free( bmp.bmBits );

	/* ビットマップが作成できたか？ */
	if ( hbmp == 0 )
	{
		/* フォントハンドラを復帰する */
		SelectObject( hDC, hFontOld );

		return	false;
	}

	/* メモリデバイスコンテキストを作成する */
	if ( ( hMemDC = CreateCompatibleDC( hDC ) ) == 0 )
	{
		/* フォントハンドラを復帰する */
		SelectObject( hDC, hFontOld );

		/* ビットマップを解放する */
		DeleteObject( hbmp );

		return	false;
	}

	/* 現在のメモリデバイスコンテストのビットマップハンドラを取得 */
	hPrevBmp = (HBITMAP)SelectObject( hMemDC, hbmp );

	/* 文字列の背景色を黒に設定 */
	SetBkColor( hMemDC, RGB( 0, 0, 0 ) );

	/* 背景色で塗りつぶす */
	SetBkMode( hMemDC, OPAQUE );

	/* 文字列のカラーの設定 */
	SetTextColor( hMemDC, RGB( 255, 255, 255 ) );

	/* 現在のメモリデバイスコンテストのフォントハンドラを取得 */
	hPrevFont = (HFONT)SelectObject( hMemDC, hFont );

	/* テキストを描画する */
	TextOut( hMemDC, 0, 0, pString, len );

	/* ビットマップの取得 */
	GetObject( hbmp, sizeof(bi), &bi );

	/* ビットマップイメージの作成 */
	CreateBitmapBits( hMemDC, hbmp, ppBitmap, &BitsSize );

	/* ビットマップイメージのサイズを計算する */
	pBitmapSize->cx = ( ( bi.bmWidth + 31 )& ( ~31 ) );
	pBitmapSize->cy = bi.bmHeight;

	/* メモリデバイスコンテストのフォントハンドラを復帰 */
	SelectObject( hMemDC, hPrevFont );

	/* メモリデバイスコンテストのビットマップハンドラを復帰 */
	SelectObject( hMemDC, hPrevBmp );

	/* メモリデバイステキストを削除 */
	DeleteDC( hMemDC );

	/* フォントハンドラを復帰する */
	SelectObject( hDC, hFontOld );

	/* ビットマップを削除する */
	DeleteObject( hbmp );

	return	true;
}

void GraphicDeviceBase::CreateBitmapBits(HDC hDC, HBITMAP hBmp, BYTE** ppBits,DWORD* pBitsSize)
{
	BITMAP			bi;
	struct
	{
		BITMAPINFOHEADER bih;
		RGBQUAD col[2];
	} bic;
	BITMAPINFO* 	binf;

	/* ビットマップ情報の作成 */
	binf = (BITMAPINFO *)&bic;

	/* ビットマップを取得する */
	GetObject( hBmp, sizeof(bi), &bi );

	/* ビットマップイメージのサイズを計算する */
	*pBitsSize = bi.bmHeight * ( ( ( bi.bmWidth + 31 ) & (~31)) / 8 );

	/* ビットマップのイメージを生成する */
	*ppBits = (BYTE*)calloc( *pBitsSize, sizeof(BYTE) );

	binf->bmiHeader.biSize          = sizeof( binf->bmiHeader );
	binf->bmiHeader.biWidth         = bi.bmWidth;
	binf->bmiHeader.biHeight        = bi.bmHeight;
	binf->bmiHeader.biPlanes        = 1;
	binf->bmiHeader.biBitCount      = 1;
	binf->bmiHeader.biCompression   = BI_RGB;
	binf->bmiHeader.biSizeImage     = *pBitsSize;
	binf->bmiHeader.biXPelsPerMeter = 1;
	binf->bmiHeader.biYPelsPerMeter = 1;
	binf->bmiHeader.biClrUsed       = 0;
	binf->bmiHeader.biClrImportant  = 0;

	/* ビットマップイメージの取得 */
	GetDIBits( hDC, hBmp, 0, bi.bmHeight, *ppBits, binf, DIB_RGB_COLORS );
}
	
/**
 * @brief メッシュを読み込む<br>
 * 
 * @param[in] id 割り当てるメッシュリソースID.
 * @param[in] filename メッシュファイル名.
 * @return なし.
 */
void GraphicDeviceBase::LoadMesh(unsigned int id, std::string filename)
{
	// 以前のメッシュデータを削除
	RemoveMesh( id );

	// 拡張子を抜き出す
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	// フルパスのファイル名を作成
	std::string ffn = "Resource/Model/" + filename;

	// mshexファイルか
	Ngl::IMesh* mesh = NULL;
	if( ext == "mshex" || ext == "msh"){
		Ngl::Msh::MshExCreator mshCreator( renderer_ );
		mshCreator.setTextureCreator( new Ngl::DDS::TextureCreatorDDS( renderer_ ) );
		mesh = mshCreator.createFromFile( ffn );
	}

	assert( mesh != NULL );

	// 管理者に追加
	meshManager_.add( id, mesh );
}



/**
 * @brief メッシュを描画<br>
 * 
 * @param[in] desc メッシュ記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render(const MeshDesc& desc)
{
	// 指定のメッシュを取得
	Ngl::IMesh* mesh = meshManager_[ desc.meshID ];

	// 指定のエフェクトを取得
	Ngl::IEffect* effect = effectManager_[ desc.effectID ]->getEffect();

	// エフェクトテクニックを設定
	effect->technique( desc.techniqueName.c_str() );

	// エフェクトパラメータを取得
	IEffectParameter& param = GetEffectVariable( desc.effectID );

	// 座標変換行列を設定
	param.SetTransform( desc.matrix );

	// ライトの位置を設定
	param.SetLightPositionEye( lightContainer_[ desc.lightNo ].position );

	// ライトのパラメータを設定
	param.SetAmbientLightColor( lightContainer_[ desc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.lightNo ].specularColor );

	Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.isSetMaterial;
	eod.isOutTexture = desc.isSetTexture;
	mesh->effectOutputDesc( eod );

	// 頂点レイアウトを設定
	mesh->setVertexDeclaration( effect->inputSigneture( desc.techniqueName.c_str() ) );
	
	// メッシュを描画
	mesh->draw( effect );
}



/**
 * @brief 指定IDのメッシュを消去<br>
 * 
 * @param[in] id 消去するメッシュリソースID.
 * @return なし.
 */
void GraphicDeviceBase::RemoveMesh(unsigned int id)
{
	meshManager_.remove( id );
}



/**
 * @brief すべてのメッシュを消去<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearMesh()
{
	meshManager_.clear();
}



/**
 * @brief スキンメッシュを描画<br>
 * 
 * @param[in] desc スキンメッシュ記述子.
 * @return なし.
 */
void GraphicDeviceBase::Render(const MeshSkinDesc& desc)
{
	// スケルトンとアニメーションの合成行列を取得
	Matrix4* transformMatrices = CalculateBoneMatrices(
		desc.skeletonID,
		desc.animationID,
		desc.animationNo,
		desc.animationTimer
		);

	// 指定のエフェクトを取得
	Ngl::IEffect* effect = effectManager_[ desc.meshDesc.effectID ]->getEffect();

	// 合成行列をシェーダーに渡す
	int boneCount = animationController_.getSkeletonNumBones( desc.skeletonID );
	effect->setMatrixArray( "g_BoneMatrices", (float*)transformMatrices, boneCount );

	// エフェクトパラメータを取得
	IEffectParameter& param = GetEffectVariable( desc.meshDesc.effectID );

	// 座標変換行列を設定
	param.SetTransform( desc.meshDesc.matrix );

	// ライトの位置を設定
	param.SetLightPositionEye( lightContainer_[ desc.meshDesc.lightNo ].position );

	// ライトのパラメータを設定
	param.SetAmbientLightColor( lightContainer_[ desc.meshDesc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.meshDesc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.meshDesc.lightNo ].specularColor );
	
	// エフェクトテクニックを設定
	effect->technique( desc.meshDesc.techniqueName.c_str() );

	// メッシュデータを取得
	Ngl::IMesh* mesh = meshManager_[ desc.meshDesc.meshID ];

	Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.meshDesc.isSetMaterial;
	eod.isOutTexture = desc.meshDesc.isSetTexture;
	mesh->effectOutputDesc( eod );

	// 頂点レイアウトを設定
	mesh->setVertexDeclaration( effect->inputSigneture( desc.meshDesc.techniqueName.c_str() ) );
	
	// メッシュを描画
	mesh->draw( effect );
}



/**
 * @brief スケルトンデータを読み込む<br>
 * 
 * @param[in] id 割り当てるリソースID.
 * @param[in] filename スケルトンデータファイル名.
 * @return なし.
 */
void GraphicDeviceBase::LoadSkeleton(unsigned int id, std::string filename)
{
	// フルパスのファイル名を作成
	std::string ffn = "Resource/Model/" + filename;

	Ngl::Msh::SklCreator creator;
	Ngl::ISkeleton* skl = creator.createFromFile( ffn );
	animationController_.addSkeleton( id, skl );
}



/**
 * @brief 指定IDのスケルトンを消去<br>
 * 
 * @param[in] id 消去するスケルトンID.
 * @return なし.
 */
void GraphicDeviceBase::RemoveSkeleton(unsigned int id)
{
	animationController_.removeSkeleton( id );
}



/**
 * @brief スケルトンを全消去する<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearSkeleton()
{
	animationController_.clearSkeleton();
}



/**
 * @brief アニメーションデータを読み込む<br>
 * 
 * @param[in] if 割り当てるリソースID.
 * @param[in] filename アニメーションデータファイル名.
 * @return なし.
 */
void GraphicDeviceBase::LoadAnimation(unsigned int id, std::string filename)
{
	// フルパスのファイル名を作成
	std::string ffn = "Resource/Model/" + filename;

	Ngl::Msh::AnmCreator creator;
	Ngl::IAnimation* anm = creator.createFromFile( ffn );
	animationController_.addAnimation( id, anm );
}



/**
 * @brief 指定IDのアニメーションデータを消去<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::RemoveAnimation(unsigned int id)
{
	animationController_.removeAnimation( id );
}



/**
 * @brief アニメーションデータを全消去<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearAnimation()
{
	animationController_.clearAnimation();
}



/**
 * @brief スケルトンデータとアニメーションデータの合成行列を取得<br>
 * 
 * @param[in] sklID スケルトンID.
 * @param[in] anmID アニメーションID.
 * @param[in] anmNo アニメーション番号.
 * @param[in] anmTimer アニメーションタイマー.
 * @return 合成した行列配列.
 */
Matrix4* GraphicDeviceBase::CalculateBoneMatrices( unsigned int sklID, unsigned int anmID, unsigned int anmNo, float anmTimer )
{
	// スケルトンをバインド
	animationController_.bindSkeleton( sklID );

	// アニメーションをバインド
	animationController_.bindAnimation( anmID, anmNo, anmTimer );

	return animationController_.transform();
}
	
	

/**
 * @brief テクスチャを読み込む<br>
 * 
 * @param[in] id 割り当てるリソースID.
 * @param[in] filename テクスチャファイル名.
 * @param[in] colorkeyFlag カラーキーフラグ.
 * @param[in] colorkey カラーキー.
 * @return なし.
 */
void GraphicDeviceBase::LoadTexture( unsigned int id, std::string filename, ColorkeyFlag colorkeyFlag, Color4 colorkey )
{
	// 以前のデータを削除
	RemoveTexture( id );

	// 拡張子を抜き出す
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	std::string ffn = "Resource/Texture/" + filename;

	Ngl::ITexture* tex = NULL;

	// DDSファイルか
	if( ext == "dds" ){
		Ngl::ITextureFilter* filter = 0;
		Ngl::TextureFilterColorKey ck( colorkey );
		Ngl::TextureFilterColorKeyAuto cka;

		// カラーキーが自動設定か
		if( colorkeyFlag == COLORKEYFLAG_AUTO ){
			filter = &cka;
		}

		// カラーキーがユーザ設定か
		if( colorkeyFlag == COLORKEYFLAG_USER ){
			filter = &ck;
		}

		Ngl::DDS::TextureCreatorDDS ddsTex( renderer_ );
		ddsTex.setFilter( filter );
		tex = ddsTex.create( ffn.c_str() );
	}

	assert( tex != NULL );

	// ミップマップを作成
	renderer_->generateMipmap( tex );

	// 管理者に追加
	textureManager_.add( id, tex );
}
	
	
	
/**
 * @brief テクスチャを作成<br>
 * 
 * @param[in] id 割り当てるテクスチャID.
 * @param[in] desc テクスチャ作成記述子.
 * @return なし.
 */
void GraphicDeviceBase::CreateTexture( unsigned int id, const TextureDesc& desc )
{
	textureManager_.add( id, renderer_->createTexture( desc ) );
}

	

/**
 * @brief 指定IDのテクスチャを消去<br>
 * 
 * @param[in] id 消去するテクスチャID.
 * @return なし.
 */
void GraphicDeviceBase::RemoveTexture( unsigned int id )
{
	textureManager_.remove( id );
}



/**
 * @brief テクスチャを全消去する<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearTexture()
{
	textureManager_.clear();
}
	
	

/**
 * @brief テクスチャ記述子を取得<br>
 * 
 * @param[in] id 記述子を取得するテクスチャのID.
 * @return テクスチャ記述子.
 */
const TextureDesc& GraphicDeviceBase::GetTextureDesc( unsigned int id )
{
	return textureManager_[ id ]->desc();
}
	
	
	
/**
 * @brief テクスチャをレンダーターゲットに設定<br>
 * 
 * @param[in] renderTexID レンダーターゲットとして使用するテクスチャID.
 * @param[in] depthTexID デプスステンシルバッファとして使用するテクスチャID.
 * @return なし.
 */
void GraphicDeviceBase::SetRenderTarget( unsigned int renderTexID, unsigned int depthTexID )
{
	Ngl::ITexture* renderTex = textureManager_[ renderTexID ];
	renderer_->setRenderTargets(
		&renderTex,
		1,
		textureManager_[ depthTexID ]
	);
}



/**
 * @brief レンダーターゲットを元に戻す<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ResetRenderTarget()
{
	renderer_->resetRenderTargets();
}
	
	

/**
 * @brief エフェクトデータを読み込む<br>
 * 
 * @param[in] id 割り当てるリソースID.
 * @param[in] filename エフェクトファイル名.
 * @return なし.
 */
void GraphicDeviceBase::LoadEffect(unsigned int id, std::string filename)
{
	// 前のデータを削除
	RemoveEffect( id );

	// 拡張子を抜き出す
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	// フルパスのファイル名を作成
	filename = "Resource/Effect/" + filename;

	// 拡張子がない
	if( ext == "" ){
		// ファイルパスと拡張子を含むファイル名を作成
		filename = filename + effectExtName_;
	}

	// エフェクトのインスタンスを作成
	Ngl::IEffectExtension* ef = new Ngl::EffectExtension( filename.c_str(), renderer_ );
	assert( ef != NULL );

	// エフェクトを登録
	effectManager_.add( id, ef );
}



/**
 * @brief 指定IDのエフェクトを消去する<br>
 * 
 * @param[in] id 消去するエフェクトID.
 * @return なし.
 */
void GraphicDeviceBase::RemoveEffect(unsigned int id)
{
	effectManager_.remove( id );
}
	


/**
 * @brief エフェクトを全消去する<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearEffect()
{
	effectManager_.clear();
}



/**
 * @brief エフェクトパラメータを取得<br>
 * 
 * @param[in] id パラメータを取得するエフェクトID.
 * @return エフェクトパラメータ.
 */
IEffectParameter& GraphicDeviceBase::GetEffectVariable( unsigned int id )
{
	assert( id != EFFECTID_NONE );

	// パラメータを設定
	effectParameter_.Initialize( id, effectManager_[ id ], this );
	return effectParameter_;
}

	

/**
 * @brief エフェクトにテクスチャを設定<br>
 * 
 * @param[in] effectID テクスチャを設定するエフェクトID.
 * @param[in] texID 設定するテクスチャID.
 * @return なし.
 */
void GraphicDeviceBase::SetTextureToEffect( unsigned int effectID, unsigned int texID, std::string paramName )
{
	// エフェクトを取得
	Ngl::IEffect* effect = effectManager_[ effectID ]->getEffect();

	// テクスチャを取得
	Ngl::ITexture* tex = textureManager_[ texID ];

	// エフェクトにテクスチャを設定
	effect->setTexture( paramName.c_str(), tex );
}


/**
 * @brief オクツリーデータを読み込む<br>
 * 
 * @param[in] id 割り当てるリソースID.
 * @param[in] filename オクツリーファイル名.
 * @return なし.
 */
void GraphicDeviceBase::LoadOctree( unsigned int id, const std::string& filename )
{
	// mshクリエイターを作成
	Ngl::Msh::MshExCreator* creator = new Ngl::Msh::MshExCreator( renderer_ );
	creator->setTextureCreator( new Ngl::DDS::TextureCreatorDDS( renderer_ ) );

	// フルパスのファイル名を作成
	std::string ffn = "Resource/Model/" + filename;

	// octクラスを作成
	Ngl::Oct::MapMeshOct* oct = new Ngl::Oct::MapMeshOct( renderer_, creator );
	oct->loadFromFile( ffn );

	octreeManager_.add( id,  oct );
}
	
	
/**
 * @brief オクツリーデータを描画する<br>
 * 
 * @param[in] desc オクツリー記述子.
 * @return なし.
 */
void GraphicDeviceBase::RenderOctree( const MeshDesc& desc )
{
	
	// 指定のエフェクトファイルを取得
	Ngl::IEffect* effect = effectManager_[ desc.effectID ]->getEffect();

	// オクツリーデータを取得
	Ngl::IMapMesh* mesh = octreeManager_[ desc.meshID ];

	// エフェクトテクニックを設定
	effect->technique( desc.techniqueName.c_str() );

	// エフェクトパラメータを取得
	IEffectParameter& param = GetEffectVariable( desc.effectID );

	// 座標変換行列を設定
	param.SetTransform( desc.matrix );

	// ライトの位置を設定
	param.SetLightPositionEye( lightContainer_[ desc.lightNo ].position );

	// ライトのパラメータを設定
	param.SetAmbientLightColor( lightContainer_[ desc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.lightNo ].specularColor );

	/*Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.isSetMaterial;
	eod.isOutTexture = desc.isSetTexture;
	mesh->effectOutputDesc( eod );*/

	// 頂点レイアウトを設定
	mesh->setVertexDeclaration( effect->inputSigneture( desc.techniqueName.c_str() ) );
	
	// オクツリーを描画
	octreeManager_[ desc.meshID ]->draw( effect, matProjection_, matView_ );

}


/**
 * @brief 指定のオクツリーデータを削除<br>
 * 
 * @param[in] id 削除するリソースID.
 * @return なし.
 */
void GraphicDeviceBase::RemoveOctree( unsigned int id )
{
	octreeManager_.remove( id );
}


/**
 * @brief オクツリーデータをすべて削除<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
void GraphicDeviceBase::ClearOctree()
{
	octreeManager_.clear();
}
	
	
/**
 * @brief リソースをすべて削除する
 *
 * @param[in] なし
 * @return	なし
 */
void GraphicDeviceBase::ClearResource()
{
	// メッシュを削除
	ClearMesh();

	// エフェクトを削除
	ClearEffect();

	// テクスチャを削除
	ClearTexture();
}

	
	
/**
 * @brief レンダラークラスを取得<br>
 * 
 * @param[in] なし.
 * @return なし.
 */
Ngl::IRenderer& GraphicDeviceBase::Renderer()
{
	return *renderer_;
}

	
	
/**
 * @brief スケルトンの姿勢変換行列を計算する
 *
 * @param[in] desc スキンメッシュ記述子
 * @param[in] parentMatrix 親の変換行列
 * @param[in] matrices 計算結果を格納する行列配列へのポインタ
 * @return	なし
 */
void GraphicDeviceBase::CalculateOrientation( const MeshSkinDesc& desc, const Matrix4& parentMatrix, Matrix4* matrices )
{
	Ngl::AnimationBindDesc abd;
	abd.id		= desc.animationID;
	abd.no		= desc.animationNo;
	abd.fTime	= desc.animationTimer;

	animationController_.calculateOrientation( abd, desc.skeletonID, parentMatrix, matrices );
}	



/**
 * @brief 指定アニメーションの終了タイムを取得する
 *
 * @param[in] id アニメーションID
 * @param[in] no アニメーション番号
 * @return	終了タイム
 */
unsigned int GraphicDeviceBase::GetAnimationEndTime( unsigned int id, unsigned int no )
{
	return animationController_.getEndAnimationTimer( id, no );
}

	
	
/**
 * @brief ライトを取得する<br>
 * 
 * @param[in] index ライト番号.
 * @return なし.
 */
const LightDesc& GraphicDeviceBase::GetLight( unsigned int index )
{
	return lightContainer_[ index ];
}



/**
 * @brief ライトを取得する<br>
 * 
 * @param[in] index ライト番号.
 * @return なし.
 */
void GraphicDeviceBase::SetLight( unsigned int index, const LightDesc& desc )
{
	lightContainer_[ index ] = desc;
}


	
/*===== EOF ==================================================================*/