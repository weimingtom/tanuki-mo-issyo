/*******************************************************************************/
/**
 * @file IGraphicDevice.h.<br>
 * 
 * @brief グラフィックデバイスインターフェース定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IGRAPHICDEVICE_H_
#define _IGRAPHICDEVICE_H_

#include	"IEffectParameter.h"
#include	"QuadDesc.h"
#include	"SpriteDesc.h"
#include	"MeshDesc.h"
#include	"MeshSkinDesc.h"
#include	"LightDesc.h"
#include	"Define/Define.h"
#include	<Ngl/IRenderer.h>
#include	<string>

/**
 * @brief 座標変換行列タイプ列挙型
 */
enum TransformType
{
	MAT_VIEW = 0,	/**< 視野変換行列 */
	MAT_PROJECTION	/**< 透視変換行列 */
};


/**
 * @brief カラーキーフラグ
 */
enum ColorkeyFlag
{
	COLORKEYFLAG_NONE,	/**< カラーキーなし			*/
	COLORKEYFLAG_AUTO,	/**< カラーキーを自動で設定	*/
	COLORKEYFLAG_USER	/**< カラーキーをユーザ設定	*/
};


/**
 * @brief グラフィックデバイスインターフェース.
 */
class IGraphicDevice
{

protected:

	/**
	 * @brief デストラクタ
	 */
	virtual ~IGraphicDevice(){}

public:

	/**
	 * @brief ビューポートの設定<br>
	 * 
	 * @param[in] desc ビューポート記述子.
	 * @return なし.
	 */
	virtual void Viewport(const ViewportDesc& desc) = 0;

	
	/**
	 * @brief ビューポートを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ビューポート記述子.
	 */
	virtual const ViewportDesc& Viewport() = 0;
	
	
	/**
	 * @brief 画面を消去<br>
	 * 
	 * @param[in] color 消去するカラー.
	 * @return なし.
	 */
	virtual void Clear( const Color4& color ) = 0;

	
	/**
	 * @brief 透視変換行列を設定<br>
	 * 
	 * @param[in] fov 視野角.
	 * @param[in] aspect 画面のアスペクト比.
	 * @param[in] znear 近クリップ面.
	 * @param[in] zfar 遠クリップ面.
	 * @return なし.
	 */
	virtual void Perspective(float fov, float aspect, float znear, float zfar) = 0;
	
	
	/**
	 * @brief 視野変換行列を設定<br>
	 * 
	 * @param[in] eye 始点位置.
	 * @param[in] at 注視点位置.
	 * @param[in] up 上方向のベクトル
	 * @return なし.
	 */
	virtual void LookAt(const Vector3& eye, const Vector3& at, const Vector3& up) = 0;

	
	/**
	 * @brief 指定の座標変換行列を取得<br>
	 * 
	 * @param[in] flag 取得する座標変換行列のフラグ.
	 * @return なし.
	 */
	virtual Matrix4 GetTransformMatrix(TransformType flag) = 0;

	
	/**
	 * @brief 四角形ポリゴンを描画<br>
	 * 
	 * @param[in] desc 四角形ポリゴン記述子.
	 * @return なし.
	 */
	virtual void Render( const QuadDesc& desc ) = 0;
	
	
	/**
	 * @brief 2Dスプライトを描画<br>
	 * 
	 * @param[in] desc スプライト記述子.
	 * @return なし.
	 */virtual void Render( const SpriteDesc& desc ) = 0;
	
	
	/**
	 * @brief メッシュを読み込む<br>
	 * 
	 * @param[in] id 割り当てるメッシュリソースID.
	 * @param[in] filename メッシュファイル名.
	 * @return なし.
	 */
	virtual void LoadMesh(unsigned int id, std::string filename) = 0;
	
	
	/**
	 * @brief メッシュを描画<br>
	 * 
	 * @param[in] desc メッシュ記述子.
	 * @return なし.
	 */
	virtual void Render(const MeshDesc& desc) = 0;
 
	
	/**
	 * @brief 指定IDのメッシュを消去<br>
	 * 
	 * @param[in] id 消去するメッシュリソースID.
	 * @return なし.
	 */
	virtual void RemoveMesh(unsigned int id) = 0;

	
	/**
	 * @brief すべてのメッシュを消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearMesh() = 0;
	
	
	/**
	 * @brief スキンメッシュを描画<br>
	 * 
	 * @param[in] desc スキンメッシュ記述子.
	 * @return なし.
	 */
	virtual void Render(const MeshSkinDesc& desc) = 0;

	
	/**
	 * @brief スケルトンデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename スケルトンデータファイル名.
	 * @return なし.
	 */
	virtual void LoadSkeleton(unsigned int id, std::string filename) = 0;

	
	/**
	 * @brief 指定IDのスケルトンを消去<br>
	 * 
	 * @param[in] id 消去するスケルトンID.
	 * @return なし.
	 */
	virtual void RemoveSkeleton(unsigned int id) = 0;
	
	
	/**
	 * @brief スケルトンを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearSkeleton() = 0;
	
	
	/**
	 * @brief アニメーションデータを読み込む<br>
	 * 
	 * @param[in] if 割り当てるリソースID.
	 * @param[in] filename アニメーションデータファイル名.
	 * @return なし.
	 */
	virtual void LoadAnimation(unsigned int id, std::string filename) = 0;

	
	/**
	 * @brief 指定IDのアニメーションデータを消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void RemoveAnimation(unsigned int id) = 0;

	
	/**
	 * @brief アニメーションデータを全消去<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearAnimation() = 0;

	
	/**
	 * @brief スケルトンデータとアニメーションデータの合成行列を取得<br>
	 * 
	 * @param[in] sklID スケルトンID.
	 * @param[in] anmID アニメーションID.
	 * @param[in] anmNo アニメーション番号.
	 * @param[in] anmTimer アニメーションタイマー.
	 * @return 合成した行列配列.
	 */
	virtual Matrix4* CalculateBoneMatrices( unsigned int sklID, unsigned int anmID, unsigned int anmNo, float anmTimer ) = 0;
	
	
	/**
	 * @brief テクスチャを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename テクスチャファイル名.
	 * @param[in] colorkeyFlag カラーキーフラグ.
	 * @param[in] colorkey カラーキー.
	 * @return なし.
	 */
	virtual void LoadTexture( unsigned int id, std::string filename, ColorkeyFlag colorkeyFlag=COLORKEYFLAG_NONE, Color4 colorkey=Color4( 0.0f, 0.0f, 0.0f, 1.0f ) ) = 0;
	
	
	/**
	 * @brief テクスチャを作成<br>
	 * 
	 * @param[in] id 割り当てるテクスチャID.
	 * @param[in] desc テクスチャ作成記述子.
	 * @return なし.
	 */
	virtual void CreateTexture( unsigned int id, const TextureDesc& desc ) = 0;

	
	/**
	 * @brief 指定IDのテクスチャを消去<br>
	 * 
	 * @param[in] id 消去するテクスチャID.
	 * @return なし.
	 */
	virtual void RemoveTexture( unsigned int id ) = 0;

	
	/**
	 * @brief テクスチャを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearTexture() = 0;
	
	
	/**
	 * @brief テクスチャ記述子を取得<br>
	 * 
	 * @param[in] id 記述子を取得するテクスチャのID.
	 * @return テクスチャ記述子.
	 */
	virtual const TextureDesc& GetTextureDesc( unsigned int id ) = 0;
	
	
	/**
	 * @brief テクスチャをレンダーターゲットに設定<br>
	 * 
	 * @param[in] renderTexID レンダーターゲットとして使用するテクスチャID.
	 * @param[in] depthTexID デプスステンシルバッファとして使用するテクスチャID.
	 * @return なし.
	 */
	virtual void SetRenderTarget( unsigned int renderTexID, unsigned int depthTexID ) = 0;

	
	/**
	 * @brief レンダーターゲットを元に戻す<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ResetRenderTarget() = 0;

	
	/**
	 * @brief エフェクトデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename エフェクトファイル名.
	 * @return なし.
	 */
	virtual void LoadEffect(unsigned int id, std::string filename) = 0;
	
	
	/**
	 * @brief 指定IDのエフェクトを消去する<br>
	 * 
	 * @param[in] id 消去するエフェクトID.
	 * @return なし.
	 */
	virtual void RemoveEffect(unsigned int id) = 0;		
	
	
	/**
	 * @brief エフェクトを全消去する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearEffect() = 0;
	
	
	/**
	 * @brief エフェクトパラメータを取得<br>
	 * 
	 * @param[in] id パラメータを取得するエフェクトID.
	 * @return エフェクトパラメータ.
	 */
	virtual IEffectParameter& GetEffectVariable( unsigned int id ) = 0;

	
	/**
	 * @brief エフェクトにテクスチャを設定<br>
	 * 
	 * @param[in] effectID テクスチャを設定するエフェクトID.
	 * @param[in] texID 設定するテクスチャID.
	 * @return なし.
	 */
	virtual void SetTextureToEffect( unsigned int effectID, unsigned int texID, std::string paramName ) = 0;

	
	/**
	 * @brief オクツリーデータを読み込む<br>
	 * 
	 * @param[in] id 割り当てるリソースID.
	 * @param[in] filename オクツリーファイル名.
	 * @return なし.
	 */
	virtual void LoadOctree( unsigned int id, const std::string& filename ) = 0;
	
	
	/**
	 * @brief オクツリーデータを描画する<br>
	 * 
	 * @param[in] desc オクツリー記述子.
	 * @return なし.
	 */
	virtual void RenderOctree( const MeshDesc& desc ) = 0;
	
	
	/**
	 * @brief 指定のオクツリーデータを削除<br>
	 * 
	 * @param[in] id 削除するリソースID.
	 * @return なし.
	 */
	virtual void RemoveOctree( unsigned int id ) = 0;


	/**
	 * @brief オクツリーデータをすべて削除<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void ClearOctree() = 0;
	
	
	/**
	 * @brief リソースをすべて削除する
	 *
	 * @param[in] なし
	 * @return	なし
	 */
	virtual void ClearResource() = 0;

	
	/**
	 * @brief レンダラークラスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual Ngl::IRenderer& Renderer() = 0;


	/**
	 * @brief スケルトンの姿勢変換行列を計算する
	 *
	 * @param[in] desc スキンメッシュ記述子
	 * @param[in] parentMatrix 親の変換行列
	 * @param[in] matrices 計算結果を格納する行列配列へのポインタ
	 * @return	なし
	 */
	virtual void CalculateOrientation( const MeshSkinDesc& desc, const Matrix4& parentMatrix, Matrix4* matrices ) = 0;


	/**
	 * @brief 指定アニメーションの終了タイムを取得する
	 *
	 * @param[in] id アニメーションID
	 * @param[in] no アニメーション番号
	 * @return	終了タイム
	 */
	virtual unsigned int GetAnimationEndTime( unsigned int id, unsigned int no ) = 0;

	
	/**
	 * @brief ライトを取得する<br>
	 * 
	 * @param[in] index ライト番号.
	 * @return なし.
	 */
	virtual const LightDesc& GetLight( unsigned int index ) = 0;


	/**
	 * @brief ライトを取得する<br>
	 * 
	 * @param[in] index ライト番号.
	 * @return なし.
	 */
	virtual void SetLight( unsigned int index, const LightDesc& desc ) = 0;

};

#endif

/*========= End of File =====================================================*/