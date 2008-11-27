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

	// 頂点カラーを設定
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// ビュー変換行列を作成
	Ngl::Matrix4 matView = GetTransformMatrix( MAT_VIEW );
	
	// 射影変換行列を作成
	Ngl::Matrix4 matProj = GetTransformMatrix( MAT_PROJECTION );
	
	// モデルビュープロジェクション行列を作成
	Matrix4 g_ModelViewProjection = desc.matrix * matView * matProj;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// テクニックを設定
	std::string technique = desc.techniqueName.c_str();
	if( desc.blendFunc == BLEND_ADD ){
		technique += "Add";
	}
	ef->technique( technique.c_str() );

	// ポリゴンのサイズを設定( ワールド座標 )
	quad_.setSize( desc.rect );

	// テクスチャIDが設定されているか
	if( desc.textureID != TEXTUREID_NONE ){
		// テクスチャを取得
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];

		// テクスチャ座標を設定
		if( desc.srcRect != Ngl::RECT_ZERO ){
			quad_.setSrcRect( desc.srcRect, tex->desc().width, tex->desc().height );
		}
		else{
			// フルサイズのテクスチャ座標を設定
			Rect rect( 0.0f, 0.0f, (float)tex->desc().width, (float)tex->desc().height );
			quad_.setSrcRect( rect, tex->desc().width, tex->desc().height );
		}

		// エフェクトにテクスチャを設定
		ef->setTexture( desc.textureName.c_str(), tex );
	}
	else{
		quad_.setSrcRect( Ngl::RECT_TEXCOORD );
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
	// エフェクトを取得
	Ngl::IEffect* ef = effectManager_[ desc.effectID ]->getEffect();

	// 頂点カラーを設定
	ef->setVector( "g_Color", desc.color.r, desc.color.g, desc.color.b, desc.color.a );

	// ビュー変換行列を作成
	Ngl::Matrix4 matView;
	matView.setIdentitiy();

	// 正射影変換行列を作成
	Ngl::Matrix4 matProj;
	matProj.setOrthoRH( -0.5f, 0.5f, -0.5f, 0.5f, -1.0f, 1.0f );

	// モデルビュープロジェクション行列を作成
	Matrix4 g_ModelViewProjection = matView * matProj;
	ef->setMatrix( "g_ModelViewProjectionMatrix", (float*)g_ModelViewProjection );

	// テクニックを設定
	ef->technique( desc.techniqueName.c_str() );

	// テクスチャIDが設定されているか
	if( desc.textureID != TEXTUREID_NONE ){
		// テクスチャを取得
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];

		// テクスチャ座標を設定
		if( desc.srcRect != Ngl::RECT_ZERO ){
			quad_.setSrcRect( desc.srcRect, tex->desc().width, tex->desc().height );
		}
		else{
			// フルサイズのテクスチャ座標を設定
			Rect rect( 0.0f, 0.0f, (float)tex->desc().width, (float)tex->desc().height );
			quad_.setSrcRect( rect, tex->desc().width, tex->desc().height );
		}

		// エフェクトにテクスチャを設定
		ef->setTexture( desc.textureName.c_str(), tex );
	}
	else{
		quad_.setSrcRect( Ngl::RECT_TEXCOORD );
	}


	// ポリゴンのサイズを設定( スクリーン座標 )
	if( desc.rect != Ngl::RECT_ZERO ){
		quad_.setSize2D( desc.rect, WINDOW_WIDTH, WINDOW_HEIGHT );
	}
	else if( desc.textureID != TEXTUREID_NONE ){
		// テクスチャを取得
		Ngl::ITexture* tex = textureManager_[ desc.textureID ];
		quad_.setSize2D( 
			Rect( 
				0.0f, 0.0f, 
				static_cast< float >( tex->desc().width ), 
				static_cast< float >( tex->desc().height) ), 
				WINDOW_WIDTH, WINDOW_HEIGHT
				);
	}
	else{
		quad_.setSize2D( desc.rect, WINDOW_WIDTH, WINDOW_HEIGHT );
	}

	// ポリゴンを描画
	quad_.draw( renderer_, ef );
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

	// octクラスを作成
	Ngl::Oct::MapMeshOct* oct = new Ngl::Oct::MapMeshOct( renderer_, creator );
	oct->loadFromFile( filename );

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