/*******************************************************************************/
/**
 * @file GraphicDeviceBase.cpp.<br>
 * 
 * @brief �O���t�B�b�N�f�o�C�X���N���X�\�[�X�t�@�C��.<br>
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
 * @brief �R���X�g���N�^<br>
 * 
 * @param[in] frame �t���[�����[�N.
 */
GraphicDeviceBase::GraphicDeviceBase( Ngl::IFrameWork& frame ):
	frame_( frame ),
	renderer_( 0 )
{
	// �f�t�H���g�̃��C�g�p�����[�^��ݒ�
	LightDesc ld;
	ld.ambientColor = Ngl::COLOR4_WHITE;
	ld.diffuseColor = Ngl::COLOR4_WHITE;
	ld.specularColor = Ngl::COLOR4_WHITE;

	lightContainer_[ 0 ] = ld;
}



/**
 * @brief �f�X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
GraphicDeviceBase::~GraphicDeviceBase()
{}

	

/**
 * @brief �I������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::End()
{
	// �l�p�`�|���S�����폜
	quad_.end();

	// ���\�[�X��S�č폜
	ClearResource();

	// �����_���[���폜
	delete renderer_;
}
	
	

/**
 * @brief �r���[�|�[�g�̐ݒ�<br>
 * 
 * @param[in] desc �r���[�|�[�g�L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Viewport(const ViewportDesc& desc)
{
	renderer_->setViewport( desc );
}



/**
 * @brief �r���[�|�[�g���擾<br>
 * 
 * @param[in] �Ȃ�.
 * @return �r���[�|�[�g�L�q�q.
 */
const ViewportDesc& GraphicDeviceBase::Viewport()
{
	return renderer_->getViewport();
}
	
	

/**
 * @brief ��ʂ�����<br>
 * 
 * @param[in] color ��������J���[.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Clear( const Color4& color )
{
	// �J���[�o�b�t�@������
	renderer_->clearColorBuffer( color.r, color.g, color.b, color.a );

	// �f�v�X�X�e���V���o�b�t�@�̏���
	renderer_->clearDepthStencilBuffer( true, true );
}



/**
 * @brief �����ϊ��s���ݒ�<br>
 * 
 * @param[in] fov ����p.
 * @param[in] aspect ��ʂ̃A�X�y�N�g��.
 * @param[in] znear �߃N���b�v��.
 * @param[in] zfar ���N���b�v��.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Perspective(float fov, float aspect, float znear, float zfar)
{
	matProjection_.setPerspectiveRH( fov, aspect, znear, zfar );
}



/**
 * @brief ����ϊ��s���ݒ�<br>
 * 
 * @param[in] eye �n�_�ʒu.
 * @param[in] at �����_�ʒu.
 * @param[in] up ������̃x�N�g��
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LookAt(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	matView_.setLookAtRH( eye, at, up );
}



/**
 * @brief �w��̍��W�ϊ��s����擾<br>
 * 
 * @param[in] flag �擾������W�ϊ��s��̃t���O.
 * @return �Ȃ�.
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
 * @brief �l�p�`�|���S����`��<br>
 * 
 * @param[in] desc �l�p�`�|���S���L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Render( const QuadDesc& desc )
{
	// �G�t�F�N�g���擾
	Ngl::IEffect* ef = effectManager_[ desc.effectID ]->getEffect();

	// �g��k���s����쐬
	float width		= desc.rect.right - desc.rect.left;
	float height	= desc.rect.bottom - desc.rect.top;
	width = width;
	height = -height;
	Vector2 size( width, height );
	Ngl::Matrix4 matScale;
	matScale.setScale( width, height, 1.0f );

	// �`��ʒu���W�����߂�
	Vector3 pos;
	pos.x = desc.rect.left;
	pos.y = desc.rect.top;
	
	// ���s�ړ��s����쐬
	Ngl::Matrix4 matPos;
	matPos.setTranslate( pos );
	
	// ���f���r���[�v���W�F�N�V�����s����쐬
	Matrix4 g_ModelViewProjection = matScale * matPos * desc.matrix * matView_ * matProjection_;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// �F��ݒ�
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// �e�N�j�b�N��ݒ�
	std::string technique = desc.techniqueName.c_str();
	if( desc.blendFunc == BLEND_ADD ){
		technique += "Add";
	}
	ef->technique( technique.c_str() );

	// �e�N�X�`��ID���ݒ肳��Ă��邩
	if( desc.textureID != 0 ){
		// �e�N�X�`�����擾
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];

		// ���[�U�[�w��̃e�N�X�`�����W��ݒ�
		if( desc.srcRect != Rect( 0.0f, 0.0f, 0.0f, 0.0f ) ){
			ef->setVector(
				"g_TextureRect",
				desc.srcRect.left	/ tex->desc().width,
				desc.srcRect.top	/ tex->desc().height,
				desc.srcRect.right	/ tex->desc().width,
				desc.srcRect.bottom / tex->desc().height
				);
		}
		// �t���T�C�Y�̃e�N�X�`�����W��ݒ�
		else{
			ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);
		}

		// �G�t�F�N�g�Ƀe�N�X�`����ݒ�
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

	// �|���S����`��
	quad_.draw( renderer_, ef );
}



/**
 * @brief 2D�X�v���C�g��`��<br>
 * 
 * @param[in] desc �X�v���C�g�L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Render( const SpriteDesc& desc )
{
	/*
	// �G�t�F�N�g���擾
	Ngl::IEffect* ef = effectManager_[ desc.effectID ]->getEffect();

	// �r���[�ϊ��s����쐬
	Ngl::Matrix4 matView;
	matView.setIdentitiy();

	// ���ˉe�ϊ��s����쐬
	Ngl::Matrix4 matProj;
	matProj.setOrthoRH( -0.5f, 0.5f, 0.5f, -0.5f, -1.0f, 1.0f );

	// �g��k���s����쐬
	float swidth	= desc.rect.right - desc.rect.left;
	float sheight	= desc.rect.bottom - desc.rect.top;
	float width = swidth * ( 1.0f / WINDOW_WIDTH );	// 3D�̍��W�n�ɕϊ�
	float height = sheight * ( 1.0f / WINDOW_HEIGHT );	// 3D�̍��W�n�ɕϊ�
	Ngl::Matrix4 matScale;
	matScale.setScale( width, height, 1.0f );

	// �`��ʒu���W�����߂�
	Vector3 pos;
	pos.x = desc.rect.left;
	pos.y = -desc.rect.top;
	
	// ���s�ړ��s����쐬
	Ngl::Matrix4 matPos;
	pos.x = ( pos.x * ( 1.0f / WINDOW_WIDTH ) ) - 0.5f;		// 3D�̍��W�n�ɕϊ�
	pos.y = ( pos.y * ( 1.0f / WINDOW_HEIGHT ) ) + 0.5f;	// 3D�̍��W�n�ɕϊ�
	matPos.setTranslate( pos );

	// ���S���W�����߂�
	Vector3 inPos( 0.5f, -0.5f, 0.0f );
	inPos.x -= (desc.center.x / swidth);
	inPos.y += (desc.center.y / sheight);
	Ngl::Matrix4 matInPos;
	matInPos.setTranslate( inPos );

	// ��]�s����쐬
	Ngl::Matrix4 matRotateZ;
	matRotateZ.setRotateZ( desc.angle );

	// ���f���r���[�v���W�F�N�V�����s����쐬
	Matrix4 g_ModelViewProjection = matInPos * matRotateZ * matScale * matPos * matView * matProj;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// �X�v���C�g�̐F��ݒ�
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// �e�N�j�b�N��ݒ�
	ef->technique( desc.techniqueName.c_str() );

	// �e�N�X�`��ID���ݒ肳��Ă��邩
	if( desc.textureID != 0 ){
		// �e�N�X�`�����擾
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];
		Ngl::OpenGL::Texture2DGL* t = static_cast< Ngl::OpenGL::Texture2DGL* >( tex );
		t->texture();

		// ���[�U�[�w��̃e�N�X�`�����W��ݒ�
		if( desc.srcRect != Rect( 0.0f, 0.0f, 0.0f, 0.0f ) ){
			ef->setVector(
				"g_TextureRect",
				desc.srcRect.left	/ tex->desc().width,
				desc.srcRect.top	/ tex->desc().height,
				desc.srcRect.right	/ tex->desc().width,
				desc.srcRect.bottom / tex->desc().height
				);
		}
		// �t���T�C�Y�̃e�N�X�`�����W��ݒ�
		else{
			ef->setVector( 
				"g_TextureRect",
				Ngl::RECT_TEXCOORD.left,
				Ngl::RECT_TEXCOORD.top,
				Ngl::RECT_TEXCOORD.right,
				Ngl::RECT_TEXCOORD.bottom
				);
		}

		// �G�t�F�N�g�Ƀe�N�X�`����ݒ�
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

	// �|���S����`��
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
 * @brief �Q�[�W��`��<br>
 * 
 * @param[in] desc �Q�[�W�L�q�q.
 * @return �Ȃ�.
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
 * @brief �e�L�X�g��`��<br>
 * 
 * @param[in] desc �e�L�X�g�L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Render(const TextDesc &desc)
{
	HFONT			hFont;
	BYTE*			pBitmap;
	SIZEL			BitmapSize;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );
	glPushMatrix();

	/* �e�N�X�`���𖳌��ɂ��� */
	glDisable( GL_TEXTURE_2D );
	glDisable( GL_TEXTURE_1D );

	if(( desc.color.r == 0.0f) && (desc.color.g == 0.0f) && (desc.color.b == 0) && (desc.color.a == 0.0f))
	{
		glColor4f(desc.color.r, desc.color.g, desc.color.b, desc.color.a);
	}

	/* �t�H���g���쐬���� */
	hFont = CreateFontHandler( desc.code, desc.size, desc.font.c_str() );

	/* �r�b�g�}�b�v�t�H���g�̍쐬 */
	if ( CreateStringBitmapFont( 
			hFont, desc.string.c_str(), &pBitmap, &BitmapSize ) == true )
	{
		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		/* �r�b�g�}�b�v�t�H���g��`�悷�� */
		glRasterPos2f(desc.position.x, desc.position.y + BitmapSize.cy );
		glBitmap( BitmapSize.cx, BitmapSize.cy, 0.0f, 0.0f, 0.0f, 0.0f, pBitmap );

		/* �r�b�g�}�b�v�t�H���g�̉�� */
		free( pBitmap );
	}

	/* �t�H���g�����ł����� */
	DeleteObject( hFont );

	/* �����_�����O���[�h�̕��A */
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

	/* �t�H���g�̑�����ݒ肷�� */
	Bold    = ( ( FontCode & FONT_CODE_BOLD      ) != 0 ) ? FONT_CODE_BOLD: FONT_CODE_NORMAL;
	bItalic = ( ( FontCode & FONT_CODE_ITALIC    ) != 0 ) ? true: false;
	bUline  = ( ( FontCode & FONT_CODE_UNDERLINE ) != 0 ) ? true: false;
	bSout   = ( ( FontCode & FONT_CODE_STRIKEOUT ) != 0 ) ? true: false;

	/* �f�o�C�X�R���e�L�X�g�̎擾 */
	hDC = wglGetCurrentDC();

	/* �t�H���g���쐬���� */
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

	/* ������̒��������߂� */
	if ( ( len = lstrlen( pString ) ) == 0 )
	{
		return	false;
	}

	/* �f�o�C�X�R���e�L�X�g���擾 */
	hDC = wglGetCurrentDC();


	/* ���݂̃f�o�C�X�R���e�L�X�g�̃t�H���g�n���h�����擾 */
	hFontOld = (HFONT)SelectObject( hDC, hFont );

	/* �r�b�g�}�b�v������̃T�C�Y���擾���� */
	GetTextExtentPoint32( hDC, pString, len, pBitmapSize );

	/* �r�b�g�}�b�v���쐬���� */
	memset( &bmp, 0, sizeof( BITMAP ) );
	bmp.bmWidth      = pBitmapSize->cx;
	bmp.bmHeight     = pBitmapSize->cy;
	bmp.bmWidthBytes = ( ( pBitmapSize->cx + 7 ) / 8 + 1 ) & (~1);
	bmp.bmPlanes     = 1;
	bmp.bmBitsPixel  = 1;
	bmp.bmBits       = calloc( bmp.bmWidthBytes * pBitmapSize->cy, sizeof(BYTE) );
	hbmp = CreateBitmapIndirect( &bmp );

	/* �r�b�g�}�b�v�C���[�W��������� */
	free( bmp.bmBits );

	/* �r�b�g�}�b�v���쐬�ł������H */
	if ( hbmp == 0 )
	{
		/* �t�H���g�n���h���𕜋A���� */
		SelectObject( hDC, hFontOld );

		return	false;
	}

	/* �������f�o�C�X�R���e�L�X�g���쐬���� */
	if ( ( hMemDC = CreateCompatibleDC( hDC ) ) == 0 )
	{
		/* �t�H���g�n���h���𕜋A���� */
		SelectObject( hDC, hFontOld );

		/* �r�b�g�}�b�v��������� */
		DeleteObject( hbmp );

		return	false;
	}

	/* ���݂̃������f�o�C�X�R���e�X�g�̃r�b�g�}�b�v�n���h�����擾 */
	hPrevBmp = (HBITMAP)SelectObject( hMemDC, hbmp );

	/* ������̔w�i�F�����ɐݒ� */
	SetBkColor( hMemDC, RGB( 0, 0, 0 ) );

	/* �w�i�F�œh��Ԃ� */
	SetBkMode( hMemDC, OPAQUE );

	/* ������̃J���[�̐ݒ� */
	SetTextColor( hMemDC, RGB( 255, 255, 255 ) );

	/* ���݂̃������f�o�C�X�R���e�X�g�̃t�H���g�n���h�����擾 */
	hPrevFont = (HFONT)SelectObject( hMemDC, hFont );

	/* �e�L�X�g��`�悷�� */
	TextOut( hMemDC, 0, 0, pString, len );

	/* �r�b�g�}�b�v�̎擾 */
	GetObject( hbmp, sizeof(bi), &bi );

	/* �r�b�g�}�b�v�C���[�W�̍쐬 */
	CreateBitmapBits( hMemDC, hbmp, ppBitmap, &BitsSize );

	/* �r�b�g�}�b�v�C���[�W�̃T�C�Y���v�Z���� */
	pBitmapSize->cx = ( ( bi.bmWidth + 31 )& ( ~31 ) );
	pBitmapSize->cy = bi.bmHeight;

	/* �������f�o�C�X�R���e�X�g�̃t�H���g�n���h���𕜋A */
	SelectObject( hMemDC, hPrevFont );

	/* �������f�o�C�X�R���e�X�g�̃r�b�g�}�b�v�n���h���𕜋A */
	SelectObject( hMemDC, hPrevBmp );

	/* �������f�o�C�X�e�L�X�g���폜 */
	DeleteDC( hMemDC );

	/* �t�H���g�n���h���𕜋A���� */
	SelectObject( hDC, hFontOld );

	/* �r�b�g�}�b�v���폜���� */
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

	/* �r�b�g�}�b�v���̍쐬 */
	binf = (BITMAPINFO *)&bic;

	/* �r�b�g�}�b�v���擾���� */
	GetObject( hBmp, sizeof(bi), &bi );

	/* �r�b�g�}�b�v�C���[�W�̃T�C�Y���v�Z���� */
	*pBitsSize = bi.bmHeight * ( ( ( bi.bmWidth + 31 ) & (~31)) / 8 );

	/* �r�b�g�}�b�v�̃C���[�W�𐶐����� */
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

	/* �r�b�g�}�b�v�C���[�W�̎擾 */
	GetDIBits( hDC, hBmp, 0, bi.bmHeight, *ppBits, binf, DIB_RGB_COLORS );
}
	
/**
 * @brief ���b�V����ǂݍ���<br>
 * 
 * @param[in] id ���蓖�Ă郁�b�V�����\�[�XID.
 * @param[in] filename ���b�V���t�@�C����.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadMesh(unsigned int id, std::string filename)
{
	// �ȑO�̃��b�V���f�[�^���폜
	RemoveMesh( id );

	// �g���q�𔲂��o��
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	// �t���p�X�̃t�@�C�������쐬
	std::string ffn = "Resource/Model/" + filename;

	// mshex�t�@�C����
	Ngl::IMesh* mesh = NULL;
	if( ext == "mshex" || ext == "msh"){
		Ngl::Msh::MshExCreator mshCreator( renderer_ );
		mshCreator.setTextureCreator( new Ngl::DDS::TextureCreatorDDS( renderer_ ) );
		mesh = mshCreator.createFromFile( ffn );
	}

	assert( mesh != NULL );

	// �Ǘ��҂ɒǉ�
	meshManager_.add( id, mesh );
}



/**
 * @brief ���b�V����`��<br>
 * 
 * @param[in] desc ���b�V���L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Render(const MeshDesc& desc)
{
	// �w��̃��b�V�����擾
	Ngl::IMesh* mesh = meshManager_[ desc.meshID ];

	// �w��̃G�t�F�N�g���擾
	Ngl::IEffect* effect = effectManager_[ desc.effectID ]->getEffect();

	// �G�t�F�N�g�e�N�j�b�N��ݒ�
	effect->technique( desc.techniqueName.c_str() );

	// �G�t�F�N�g�p�����[�^���擾
	IEffectParameter& param = GetEffectVariable( desc.effectID );

	// ���W�ϊ��s���ݒ�
	param.SetTransform( desc.matrix );

	// ���C�g�̈ʒu��ݒ�
	param.SetLightPositionEye( lightContainer_[ desc.lightNo ].position );

	// ���C�g�̃p�����[�^��ݒ�
	param.SetAmbientLightColor( lightContainer_[ desc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.lightNo ].specularColor );

	Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.isSetMaterial;
	eod.isOutTexture = desc.isSetTexture;
	mesh->effectOutputDesc( eod );

	// ���_���C�A�E�g��ݒ�
	mesh->setVertexDeclaration( effect->inputSigneture( desc.techniqueName.c_str() ) );
	
	// ���b�V����`��
	mesh->draw( effect );
}



/**
 * @brief �w��ID�̃��b�V��������<br>
 * 
 * @param[in] id �������郁�b�V�����\�[�XID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveMesh(unsigned int id)
{
	meshManager_.remove( id );
}



/**
 * @brief ���ׂẴ��b�V��������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearMesh()
{
	meshManager_.clear();
}



/**
 * @brief �X�L�����b�V����`��<br>
 * 
 * @param[in] desc �X�L�����b�V���L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::Render(const MeshSkinDesc& desc)
{
	// �X�P���g���ƃA�j���[�V�����̍����s����擾
	Matrix4* transformMatrices = CalculateBoneMatrices(
		desc.skeletonID,
		desc.animationID,
		desc.animationNo,
		desc.animationTimer
		);

	// �w��̃G�t�F�N�g���擾
	Ngl::IEffect* effect = effectManager_[ desc.meshDesc.effectID ]->getEffect();

	// �����s����V�F�[�_�[�ɓn��
	int boneCount = animationController_.getSkeletonNumBones( desc.skeletonID );
	effect->setMatrixArray( "g_BoneMatrices", (float*)transformMatrices, boneCount );

	// �G�t�F�N�g�p�����[�^���擾
	IEffectParameter& param = GetEffectVariable( desc.meshDesc.effectID );

	// ���W�ϊ��s���ݒ�
	param.SetTransform( desc.meshDesc.matrix );

	// ���C�g�̈ʒu��ݒ�
	param.SetLightPositionEye( lightContainer_[ desc.meshDesc.lightNo ].position );

	// ���C�g�̃p�����[�^��ݒ�
	param.SetAmbientLightColor( lightContainer_[ desc.meshDesc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.meshDesc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.meshDesc.lightNo ].specularColor );
	
	// �G�t�F�N�g�e�N�j�b�N��ݒ�
	effect->technique( desc.meshDesc.techniqueName.c_str() );

	// ���b�V���f�[�^���擾
	Ngl::IMesh* mesh = meshManager_[ desc.meshDesc.meshID ];

	Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.meshDesc.isSetMaterial;
	eod.isOutTexture = desc.meshDesc.isSetTexture;
	mesh->effectOutputDesc( eod );

	// ���_���C�A�E�g��ݒ�
	mesh->setVertexDeclaration( effect->inputSigneture( desc.meshDesc.techniqueName.c_str() ) );
	
	// ���b�V����`��
	mesh->draw( effect );
}



/**
 * @brief �X�P���g���f�[�^��ǂݍ���<br>
 * 
 * @param[in] id ���蓖�Ă郊�\�[�XID.
 * @param[in] filename �X�P���g���f�[�^�t�@�C����.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadSkeleton(unsigned int id, std::string filename)
{
	// �t���p�X�̃t�@�C�������쐬
	std::string ffn = "Resource/Model/" + filename;

	Ngl::Msh::SklCreator creator;
	Ngl::ISkeleton* skl = creator.createFromFile( ffn );
	animationController_.addSkeleton( id, skl );
}



/**
 * @brief �w��ID�̃X�P���g��������<br>
 * 
 * @param[in] id ��������X�P���g��ID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveSkeleton(unsigned int id)
{
	animationController_.removeSkeleton( id );
}



/**
 * @brief �X�P���g����S��������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearSkeleton()
{
	animationController_.clearSkeleton();
}



/**
 * @brief �A�j���[�V�����f�[�^��ǂݍ���<br>
 * 
 * @param[in] if ���蓖�Ă郊�\�[�XID.
 * @param[in] filename �A�j���[�V�����f�[�^�t�@�C����.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadAnimation(unsigned int id, std::string filename)
{
	// �t���p�X�̃t�@�C�������쐬
	std::string ffn = "Resource/Model/" + filename;

	Ngl::Msh::AnmCreator creator;
	Ngl::IAnimation* anm = creator.createFromFile( ffn );
	animationController_.addAnimation( id, anm );
}



/**
 * @brief �w��ID�̃A�j���[�V�����f�[�^������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveAnimation(unsigned int id)
{
	animationController_.removeAnimation( id );
}



/**
 * @brief �A�j���[�V�����f�[�^��S����<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearAnimation()
{
	animationController_.clearAnimation();
}



/**
 * @brief �X�P���g���f�[�^�ƃA�j���[�V�����f�[�^�̍����s����擾<br>
 * 
 * @param[in] sklID �X�P���g��ID.
 * @param[in] anmID �A�j���[�V����ID.
 * @param[in] anmNo �A�j���[�V�����ԍ�.
 * @param[in] anmTimer �A�j���[�V�����^�C�}�[.
 * @return ���������s��z��.
 */
Matrix4* GraphicDeviceBase::CalculateBoneMatrices( unsigned int sklID, unsigned int anmID, unsigned int anmNo, float anmTimer )
{
	// �X�P���g�����o�C���h
	animationController_.bindSkeleton( sklID );

	// �A�j���[�V�������o�C���h
	animationController_.bindAnimation( anmID, anmNo, anmTimer );

	return animationController_.transform();
}
	
	

/**
 * @brief �e�N�X�`����ǂݍ���<br>
 * 
 * @param[in] id ���蓖�Ă郊�\�[�XID.
 * @param[in] filename �e�N�X�`���t�@�C����.
 * @param[in] colorkeyFlag �J���[�L�[�t���O.
 * @param[in] colorkey �J���[�L�[.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadTexture( unsigned int id, std::string filename, ColorkeyFlag colorkeyFlag, Color4 colorkey )
{
	// �ȑO�̃f�[�^���폜
	RemoveTexture( id );

	// �g���q�𔲂��o��
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	std::string ffn = "Resource/Texture/" + filename;

	Ngl::ITexture* tex = NULL;

	// DDS�t�@�C����
	if( ext == "dds" ){
		Ngl::ITextureFilter* filter = 0;
		Ngl::TextureFilterColorKey ck( colorkey );
		Ngl::TextureFilterColorKeyAuto cka;

		// �J���[�L�[�������ݒ肩
		if( colorkeyFlag == COLORKEYFLAG_AUTO ){
			filter = &cka;
		}

		// �J���[�L�[�����[�U�ݒ肩
		if( colorkeyFlag == COLORKEYFLAG_USER ){
			filter = &ck;
		}

		Ngl::DDS::TextureCreatorDDS ddsTex( renderer_ );
		ddsTex.setFilter( filter );
		tex = ddsTex.create( ffn.c_str() );
	}

	assert( tex != NULL );

	// �~�b�v�}�b�v���쐬
	renderer_->generateMipmap( tex );

	// �Ǘ��҂ɒǉ�
	textureManager_.add( id, tex );
}
	
	
	
/**
 * @brief �e�N�X�`�����쐬<br>
 * 
 * @param[in] id ���蓖�Ă�e�N�X�`��ID.
 * @param[in] desc �e�N�X�`���쐬�L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::CreateTexture( unsigned int id, const TextureDesc& desc )
{
	textureManager_.add( id, renderer_->createTexture( desc ) );
}

	

/**
 * @brief �w��ID�̃e�N�X�`��������<br>
 * 
 * @param[in] id ��������e�N�X�`��ID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveTexture( unsigned int id )
{
	textureManager_.remove( id );
}



/**
 * @brief �e�N�X�`����S��������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearTexture()
{
	textureManager_.clear();
}
	
	

/**
 * @brief �e�N�X�`���L�q�q���擾<br>
 * 
 * @param[in] id �L�q�q���擾����e�N�X�`����ID.
 * @return �e�N�X�`���L�q�q.
 */
const TextureDesc& GraphicDeviceBase::GetTextureDesc( unsigned int id )
{
	return textureManager_[ id ]->desc();
}
	
	
	
/**
 * @brief �e�N�X�`���������_�[�^�[�Q�b�g�ɐݒ�<br>
 * 
 * @param[in] renderTexID �����_�[�^�[�Q�b�g�Ƃ��Ďg�p����e�N�X�`��ID.
 * @param[in] depthTexID �f�v�X�X�e���V���o�b�t�@�Ƃ��Ďg�p����e�N�X�`��ID.
 * @return �Ȃ�.
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
 * @brief �����_�[�^�[�Q�b�g�����ɖ߂�<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ResetRenderTarget()
{
	renderer_->resetRenderTargets();
}
	
	

/**
 * @brief �G�t�F�N�g�f�[�^��ǂݍ���<br>
 * 
 * @param[in] id ���蓖�Ă郊�\�[�XID.
 * @param[in] filename �G�t�F�N�g�t�@�C����.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadEffect(unsigned int id, std::string filename)
{
	// �O�̃f�[�^���폜
	RemoveEffect( id );

	// �g���q�𔲂��o��
	std::string ext = Ngl::Utility::getFileExtension( filename.c_str() );

	// �t���p�X�̃t�@�C�������쐬
	filename = "Resource/Effect/" + filename;

	// �g���q���Ȃ�
	if( ext == "" ){
		// �t�@�C���p�X�Ɗg���q���܂ރt�@�C�������쐬
		filename = filename + effectExtName_;
	}

	// �G�t�F�N�g�̃C���X�^���X���쐬
	Ngl::IEffectExtension* ef = new Ngl::EffectExtension( filename.c_str(), renderer_ );
	assert( ef != NULL );

	// �G�t�F�N�g��o�^
	effectManager_.add( id, ef );
}



/**
 * @brief �w��ID�̃G�t�F�N�g����������<br>
 * 
 * @param[in] id ��������G�t�F�N�gID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveEffect(unsigned int id)
{
	effectManager_.remove( id );
}
	


/**
 * @brief �G�t�F�N�g��S��������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearEffect()
{
	effectManager_.clear();
}



/**
 * @brief �G�t�F�N�g�p�����[�^���擾<br>
 * 
 * @param[in] id �p�����[�^���擾����G�t�F�N�gID.
 * @return �G�t�F�N�g�p�����[�^.
 */
IEffectParameter& GraphicDeviceBase::GetEffectVariable( unsigned int id )
{
	assert( id != EFFECTID_NONE );

	// �p�����[�^��ݒ�
	effectParameter_.Initialize( id, effectManager_[ id ], this );
	return effectParameter_;
}

	

/**
 * @brief �G�t�F�N�g�Ƀe�N�X�`����ݒ�<br>
 * 
 * @param[in] effectID �e�N�X�`����ݒ肷��G�t�F�N�gID.
 * @param[in] texID �ݒ肷��e�N�X�`��ID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::SetTextureToEffect( unsigned int effectID, unsigned int texID, std::string paramName )
{
	// �G�t�F�N�g���擾
	Ngl::IEffect* effect = effectManager_[ effectID ]->getEffect();

	// �e�N�X�`�����擾
	Ngl::ITexture* tex = textureManager_[ texID ];

	// �G�t�F�N�g�Ƀe�N�X�`����ݒ�
	effect->setTexture( paramName.c_str(), tex );
}


/**
 * @brief �I�N�c���[�f�[�^��ǂݍ���<br>
 * 
 * @param[in] id ���蓖�Ă郊�\�[�XID.
 * @param[in] filename �I�N�c���[�t�@�C����.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::LoadOctree( unsigned int id, const std::string& filename )
{
	// msh�N���G�C�^�[���쐬
	Ngl::Msh::MshExCreator* creator = new Ngl::Msh::MshExCreator( renderer_ );
	creator->setTextureCreator( new Ngl::DDS::TextureCreatorDDS( renderer_ ) );

	// �t���p�X�̃t�@�C�������쐬
	std::string ffn = "Resource/Model/" + filename;

	// oct�N���X���쐬
	Ngl::Oct::MapMeshOct* oct = new Ngl::Oct::MapMeshOct( renderer_, creator );
	oct->loadFromFile( ffn );

	octreeManager_.add( id,  oct );
}
	
	
/**
 * @brief �I�N�c���[�f�[�^��`�悷��<br>
 * 
 * @param[in] desc �I�N�c���[�L�q�q.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RenderOctree( const MeshDesc& desc )
{
	
	// �w��̃G�t�F�N�g�t�@�C�����擾
	Ngl::IEffect* effect = effectManager_[ desc.effectID ]->getEffect();

	// �I�N�c���[�f�[�^���擾
	Ngl::IMapMesh* mesh = octreeManager_[ desc.meshID ];

	// �G�t�F�N�g�e�N�j�b�N��ݒ�
	effect->technique( desc.techniqueName.c_str() );

	// �G�t�F�N�g�p�����[�^���擾
	IEffectParameter& param = GetEffectVariable( desc.effectID );

	// ���W�ϊ��s���ݒ�
	param.SetTransform( desc.matrix );

	// ���C�g�̈ʒu��ݒ�
	param.SetLightPositionEye( lightContainer_[ desc.lightNo ].position );

	// ���C�g�̃p�����[�^��ݒ�
	param.SetAmbientLightColor( lightContainer_[ desc.lightNo ].ambientColor );
	param.SetDiffuseLightColor( lightContainer_[ desc.lightNo ].diffuseColor );
	param.SetSpecularLightColor( lightContainer_[ desc.lightNo ].specularColor );

	/*Ngl::EffectOutputDesc eod;
	eod.isOutMaterial = desc.isSetMaterial;
	eod.isOutTexture = desc.isSetTexture;
	mesh->effectOutputDesc( eod );*/

	// ���_���C�A�E�g��ݒ�
	mesh->setVertexDeclaration( effect->inputSigneture( desc.techniqueName.c_str() ) );
	
	// �I�N�c���[��`��
	octreeManager_[ desc.meshID ]->draw( effect, matProjection_, matView_ );

}


/**
 * @brief �w��̃I�N�c���[�f�[�^���폜<br>
 * 
 * @param[in] id �폜���郊�\�[�XID.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::RemoveOctree( unsigned int id )
{
	octreeManager_.remove( id );
}


/**
 * @brief �I�N�c���[�f�[�^�����ׂč폜<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::ClearOctree()
{
	octreeManager_.clear();
}
	
	
/**
 * @brief ���\�[�X�����ׂč폜����
 *
 * @param[in] �Ȃ�
 * @return	�Ȃ�
 */
void GraphicDeviceBase::ClearResource()
{
	// ���b�V�����폜
	ClearMesh();

	// �G�t�F�N�g���폜
	ClearEffect();

	// �e�N�X�`�����폜
	ClearTexture();
}

	
	
/**
 * @brief �����_���[�N���X���擾<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
Ngl::IRenderer& GraphicDeviceBase::Renderer()
{
	return *renderer_;
}

	
	
/**
 * @brief �X�P���g���̎p���ϊ��s����v�Z����
 *
 * @param[in] desc �X�L�����b�V���L�q�q
 * @param[in] parentMatrix �e�̕ϊ��s��
 * @param[in] matrices �v�Z���ʂ��i�[����s��z��ւ̃|�C���^
 * @return	�Ȃ�
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
 * @brief �w��A�j���[�V�����̏I���^�C�����擾����
 *
 * @param[in] id �A�j���[�V����ID
 * @param[in] no �A�j���[�V�����ԍ�
 * @return	�I���^�C��
 */
unsigned int GraphicDeviceBase::GetAnimationEndTime( unsigned int id, unsigned int no )
{
	return animationController_.getEndAnimationTimer( id, no );
}

	
	
/**
 * @brief ���C�g���擾����<br>
 * 
 * @param[in] index ���C�g�ԍ�.
 * @return �Ȃ�.
 */
const LightDesc& GraphicDeviceBase::GetLight( unsigned int index )
{
	return lightContainer_[ index ];
}



/**
 * @brief ���C�g���擾����<br>
 * 
 * @param[in] index ���C�g�ԍ�.
 * @return �Ȃ�.
 */
void GraphicDeviceBase::SetLight( unsigned int index, const LightDesc& desc )
{
	lightContainer_[ index ] = desc;
}


	
/*===== EOF ==================================================================*/