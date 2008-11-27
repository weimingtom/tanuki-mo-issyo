/*******************************************************************************/
/**
 * @file IMapMesh.h.
 * 
 * @brief マップメッシュインターフェース定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMAPMESH_H_
#define _NGL_IMAPMESH_H_

#include	"IInputStream.h"
#include	"IEffect.h"
#include	"Ngl/CollisionReport.h"
#include	"Matrix4.h"

namespace Ngl{


/**
 * @interface IMapMesh．
 * @brief マップメッシュインターフェース.
 */
class IMapMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IMapMesh() {}


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームからデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return なし.
	 */
	virtual void loadFromStream( IInputStream& stream ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データを作成
	 * 
	 * @param[in] inputSignature 入力シグネチャ記述子の参照.
	 * @return なし.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] effect エフェクトのポインタ.
	 * @param[in] matProj 4x4透視変換行列構造体の参照.
	 * @param[in] matView 4x4視野変換行列構造体の参照.
	 * @return なし.
	 */
	virtual void draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] rayPos レイの始点.
	 * @param[in] rayDir レイの方向.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/