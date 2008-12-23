/*******************************************************************************/
/**
 * @file GraphicDeviceBase.h.<br>
 * 
 * @brief グラフィックデバイス基底クラスヘッダファイル.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GRAPHICDEVICEBASE_H_
#define _GRAPHICDEVICEBASE_H_

#include	"EffectParameter.h"

#include	"IGraphicDevice.h"
#include	<Ngl/PolygonQuad.h>
#include	<Ngl/AnimationController.h>
#include	<Ngl/Manager/ObjectManager.h>
#include	<Ngl/IEffectExtension.h>
#include	<Ngl/IFramework.h>
#include	<Ngl/IMesh.h>
#include	<Ngl/IMapMesh.h>
#include	<map>
#include	<windows.h>


/**
 * @brief グラフィックデバイス基底クラス
 */
class GraphicDeviceBase : public IGraphicDevice
{
protected:

	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] frame フレームワーク.
	 */
	GraphicDeviceBase( Ngl::IFrameWork& frame );

		
	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~GraphicDeviceBase();

public:

	/**
	 * @brief 終了処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void End();
	
	
	/**
	 * @brief ビューポートの設定<br>
	 * 
	 * @param[in] desc ビューポート記述子.
	 * @return なし.
	 */
	virtual void Viewport( const ViewportDesc& desc );

	
	/**
	 * @brief ビューポートを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ビューポート記述子.
	 */
	virtual const ViewportDesc& Viewport();
	
	
	/**
	 * @brief 画面を消去<br>
	 * 
	 * @param[in] color 消去するカラー.
	 * @return なし.
	 */
	virtual void Clear( const Color4& color );
	
	
	/**
	 * @brief 透視変換行列を設定<br>
	 * 
	 * @param[in] fov 視野角.
	 * @param[in] aspect 画面のアスペクト比.
	 * @param[in] znear 近クリップ面.
	 * @param[in] zfar 遠クリップ面.
	 * @return なし.
	 */
	virtual void Perspective( float fov, float aspect, float znear, float zfar );
		
	
	/**
	 * @brief 視野変換行列を設定<br>
	 * 
	 * @param[in] eye 始点位置.
	 * @param[in] at 注視点位置.
	 * @param[in] up 上方向のベクトル
	 * @return なし.
	 */
	virtual void LookAt( const Vector3& eye, const Vector3& at, const Vector3& up );

	
	/**
	 * @brief 指定の座標変換行列を取得<br>
	 * 
	 * @param[in] flag 取得する座標変換行列のフラグ.
	 * @return なし.
	 */
	virtual Matrix4 GetTransformMatrix( TransformType flag );

	
	/**
	 * @brief 四角形ポリゴンを描画<br>
	 * 
	 * @param[in] desc 四角形ポリゴン記述子.
	 * @return なし.
	 */
	virtual void Render( const QuadDesc& desc );

	
	/**
	 * @brief 2Dスプライトを描画<br>
	 * 
	 * @param[in] desc スプライト記述子.
	 * @return なし.
	 */
	virtual void Render( const SpriteDesc& desc );

	/**
	 * @brief ゲージを描画<br>
	 * 
	 * @param[in] desc ゲージ記述子.
	 * @return なし.
	 */
	virtual void Render( const GaugeDesc& desc );

	/**
	 * @brief テキストを描画<br>
	 * 
	 * @param[in] desc テキスト記述子.
	 * @return なし.
	 */
	virtual void Render( const TextDesc& desc );

	HFONT CreateFontHandler(unsigned int FontCode, unsigned int FontPoint, const char* pFontName);
	bool CreateStringBitmapFont(HFONT hFont,const char* pString, BYTE** ppBitmap, PSIZEL pBitmapSize);
	void CreateBitmapBits(HDC hDC, HBITMAP hBmp, BYTE** ppBits,DWORD* pBitsSize);
	
	
	/**
	 * @brief メッシュを読み込む<br>
	 * 
	 * @param[in] id 割り当てるメッシュリソースID.
	 * @param[in] filename メッシュファイル名.
	 * @return なし.
	 */
	virtual void LoadMesh( unsigned int id, std::string filename );
	
	/**
	 * @brief メッシュを描画<br>
	 * 
	 * @param[in] desc メッシュ記述子.
	 * @return なし.
	 */
	virtual void Render( const MeshDesc& desc );
	
	
	/**
	 * @brief 指定IDのメッシュを消去<br>
	 * 
	 * @param[in] id 消去するメッシュリソースID.
	 * @return なし.
	 */
	virtual void RemoveMesh( unsigned int id );
	
	
	/**
	 * @brief すべてのメッシュを消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearMesh();
	
	
	/**
	 * @brief スキンメッシュを描画<br>
	 * 
	 * @param[in] desc スキンメッシュ記述子.
	 * @return なし.
	 */
	virtual void Render( const MeshSkinDesc& desc );

	
	/**
	 * @brief スケルトンデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename スケルトンデータファイル名.
	 * @return なし.
	 */
	virtual void LoadSkeleton( unsigned int id, std::string filename );

	
	/**
	 * @brief 指定IDのスケルトンを消去<br>
	 * 
	 * @param[in] id 消去するスケルトンID.
	 * @return なし.
	 */
	virtual void RemoveSkeleton( unsigned int id );
		
	
	/**
	 * @brief スケルトンを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearSkeleton();
	
		
	/**
	 * @brief アニメーションデータを読み込む<br>
	 * 
	 * @param[in] if 割り当てるリソースID.
	 * @param[in] filename アニメーションデータファイル名.
	 * @return なし.
	 */
	virtual void LoadAnimation( unsigned int id, std::string filename );

		
	/**
	 * @brief 指定IDのアニメーションデータを消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void RemoveAnimation( unsigned int id );

		
	/**
	 * @brief アニメーションデータを全消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearAnimation();

	
	/**
	 * @brief スケルトンデータとアニメーションデータの合成行列を取得<br>
	 * 
	 * @param[in] sklID スケルトンID.
	 * @param[in] anmID アニメーションID.
	 * @param[in] anmNo アニメーション番号.
	 * @param[in] anmTimer アニメーションタイマー.
	 * @return 合成した行列配列.
	 */
	virtual Matrix4* CalculateBoneMatrices( unsigned int sklID, unsigned int anmID, unsigned int anmNo, float anmTimer );

	
	/**
	 * @brief テクスチャを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename テクスチャファイル名.
	 * @param[in] colorkeyFlag カラーキーフラグ.
	 * @param[in] colorkey カラーキー.
	 * @return なし.
	 */
	virtual void LoadTexture( unsigned int id, std::string filename, ColorkeyFlag colorkeyFlag=COLORKEYFLAG_NONE, Color4 colorkey=Color4( 0.0f, 0.0f, 0.0f, 1.0f ) );

	
	/**
	 * @brief テクスチャを作成<br>
	 * 
	 * @param[in] id 割り当てるテクスチャID.
	 * @param[in] desc テクスチャ作成記述子.
	 * @return なし.
	 */
	virtual void CreateTexture( unsigned int id, const TextureDesc& desc );

	
	/**
	 * @brief 指定IDのテクスチャを消去<br>
	 * 
	 * @param[in] id 消去するテクスチャID.
	 * @return なし.
	 */
	virtual void RemoveTexture( unsigned int id );

		
	/**
	 * @brief テクスチャを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearTexture();

	
	/**
	 * @brief テクスチャ記述子を取得<br>
	 * 
	 * @param[in] id 記述子を取得するテクスチャのID.
	 * @return テクスチャ記述子.
	 */
	virtual const TextureDesc& GetTextureDesc( unsigned int id );
	
	
	/**
	 * @brief テクスチャをレンダーターゲットに設定<br>
	 * 
	 * @param[in] renderTexID レンダーターゲットとして使用するテクスチャID.
	 * @param[in] depthTexID デプスステンシルバッファとして使用するテクスチャID.
	 * @return なし.
	 */
	virtual void SetRenderTarget( unsigned int renderTexID, unsigned int depthTexID );

	
	/**
	 * @brief レンダーターゲットを元に戻す<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ResetRenderTarget();
	
	
	/**
	 * @brief エフェクトデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename エフェクトファイル名.
	 * @return なし.
	 */
	virtual void LoadEffect( unsigned int id, std::string filename );
	
	
	/**
	 * @brief 指定IDのエフェクトを消去する<br>
	 * 
	 * @param[in] id 消去するエフェクトID.
	 * @return なし.
	 */
	virtual void RemoveEffect( unsigned int id );		
		
	
	/**
	 * @brief エフェクトを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearEffect();
	
	
	/**
	 * @brief エフェクトパラメータを取得<br>
	 * 
	 * @param[in] id パラメータを取得するエフェクトID.
	 * @return エフェクトパラメータ.
	 */
	virtual IEffectParameter& GetEffectVariable( unsigned int id );

	
	/**
	 * @brief エフェクトにテクスチャを設定<br>
	 * 
	 * @param[in] effectID テクスチャを設定するエフェクトID.
	 * @param[in] texID 設定するテクスチャID.
	 * @return なし.
	 */
	virtual void SetTextureToEffect( unsigned int effectID, unsigned int texID, std::string paramName );

	
	/**
	 * @brief オクツリーデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename オクツリーファイル名.
	 * @return なし.
	 */
	virtual void LoadOctree( unsigned int id, const std::string& filename );
	
	
	/**
	 * @brief オクツリーデータを描画する<br>
	 * 
	 * @param[in] desc オクツリー記述子.
	 * @return なし.
	 */
	virtual void RenderOctree( const MeshDesc& desc );
	
	
	/**
	 * @brief 指定のオクツリーデータを削除<br>
	 * 
	 * @param[in] id 削除するリソースID.
	 * @return なし.
	 */
	virtual void RemoveOctree( unsigned int id );


	/**
	 * @brief オクツリーデータをすべて削除<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearOctree();
	 
	 
	 /**
	 * @brief リソースをすべて削除する
	 *
	 * @param[in] なし
	 * @return	なし
	 */
	virtual void ClearResource();
	
	
	/**
	 * @brief レンダラークラスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual Ngl::IRenderer& Renderer();


	/**
	 * @brief スケルトンの姿勢変換行列を計算する
	 *
	 * @param[in] desc スキンメッシュ記述子
	 * @param[in] parentMatrix 親の変換行列
	 * @param[in] matrices 計算結果を格納する行列配列へのポインタ
	 * @return	なし
	 */
	virtual void CalculateOrientation( const MeshSkinDesc& desc, const Matrix4& parentMatrix, Matrix4* matrices );


	/**
	 * @brief 指定アニメーションの終了タイムを取得する
	 *
	 * @param[in] id アニメーションID
	 * @param[in] no アニメーション番号
	 * @return	終了タイム
	 */
	virtual unsigned int GetAnimationEndTime( unsigned int id, unsigned int no );

	
	/**
	 * @brief ライトを取得する<br>
	 * 
	 * @param[in] index ライト番号.
	 * @return なし.
	 */
	virtual const LightDesc& GetLight( unsigned int index );


	/**
	 * @brief ライトを取得する<br>
	 * 
	 * @param[in] index ライト番号.
	 * @return なし.
	 */
	virtual void SetLight( unsigned int index, const LightDesc& desc );

protected:

	/** メッシュ管理者型 */
	typedef Ngl::ObjectManager< unsigned int, Ngl::IMesh* >				MeshManager;

	/** テクスチャ管理者型 */
	typedef Ngl::ObjectManager< unsigned int, Ngl::ITexture* >			TextureManager;

	/** エフェクト管理者型 */
	typedef Ngl::ObjectManager< unsigned int, Ngl::IEffectExtension* >	EffectManager;

	/** オクツリー管理者型 */
	typedef Ngl::ObjectManager< unsigned int, Ngl::IMapMesh* >			OctreeManager;

	/** ライト記述子コンテナ型 */
	typedef std::map< unsigned int, LightDesc >							LightContainer;

public:

	/** エフェクトファイル拡張子名 */
	std::string						effectExtName_;

protected:

	/** フレームワーククラスの参照 */
	Ngl::IFrameWork&				frame_;

	/** レンダラークラスのポインタ */
	Ngl::IRenderer*					renderer_;

	/** 透視変換行列 */
	Matrix4							matProjection_;

	/** 視野変換行列 */
	Matrix4							matView_;

	/** メッシュ管理者 */
	MeshManager						meshManager_;

	/** テクスチャ管理者 */
	TextureManager					textureManager_;
	
	/** エフェクト管理者 */
	EffectManager					effectManager_;

	/** オクツリー管理者 */
	OctreeManager					octreeManager_;

	/** アニメーションコントローラ */
	Ngl::AnimationController		animationController_;

	/** 四角形ポリゴン */
	Ngl::PolygonQuad				quad_;

	/** エフェクトパラメータ */
	EffectParameter					effectParameter_;

	/** ライトコンテナ */
	LightContainer					lightContainer_;

};

#endif

/*===== EOF ==================================================================*/