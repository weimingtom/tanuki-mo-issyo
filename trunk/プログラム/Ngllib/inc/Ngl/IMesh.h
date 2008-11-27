/*******************************************************************************/
/**
 * @file IMesh.h.
 * 
 * @brief メッシュインターフェース定義.
 *
 * @date 2008/06/27.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_I_MESH_SKIN_H_
#define _NGL_I_MESH_SKIN_H_

#include	"IMeshCollision.h"
#include	"IInputStream.h"
#include	"IRenderer.h"
#include	"MeshInfo.h"
#include	"EffectOutputDesc.h"

namespace Ngl{


/**
 * @interface IMesh．
 * @brief スキンメッシュインターフェース.
 */
class IMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IMesh(){}
	
	
	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] effect エフェクトのポインタ.
	 * @return なし.
	 */
	virtual void draw( IEffect* effect ) = 0;


	/*=========================================================================*/
	/**
	 * @brief サブセットを描画
	 * 
	 * @param[in] faceNo 面データ番号.
	 * @param[in] effect エフェクト.
	 * @return なし.
	 */
	virtual void drawSubset( unsigned int faceNo, IEffect* effect ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief メッシュ情報を取得
	 * 
	 * @param[in] なし.
	 * @return メッシュ情報構造体.
	 */
	virtual const MeshInfo& info() const = 0;


	/*=========================================================================*/
	/**
	 * @brief エフェクト出力記述子を取得
	 * 
	 * @param[in] なし.
	 * @return エフェクト出力記述子.
	 */
	virtual const EffectOutputDesc& effectOutputDesc() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief エフェクト出力記述子を設定
	 * 
	 * @param[in] desc エフェクト出力記述子.
	 * @return なし.
	 */
	virtual void effectOutputDesc( const EffectOutputDesc& desc ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データを作成
	 * 
	 * @param[in] inputSignature 入力シグネチャ記述子の参照.
	 * @return なし.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと線分との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndLine( int faceNo, const float* line0, const float* line1 ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと3D線との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと球体との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndSphere( int faceNo, const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/