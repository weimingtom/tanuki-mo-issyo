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
#include	"Material.h"
#include	"IInputStream.h"
#include	"IRenderer.h"
#include	"MeshInfo.h"
#include	"EffectOutputDesc.h"

namespace Ngl{


/**
 * @enum StreamType.
 * @brief ストリーム列挙型.
 */
enum StreamType
{
	STREAM_TYPE_VERTEX		= 0,	/**< 頂点データ						*/
	STREAM_TYPE_NORMAL		= 1,	/**< 法線データ						*/
	STREAM_TYPE_DIFFUSE		= 2,	/**< 拡散反射光カラーデータ			*/
	STREAM_TYPE_SPECULAR	= 3,	/**< 鏡面反射光カラーデータ			*/
	STREAM_TYPE_TEXCOORD	= 4,	/**< テクスチャ座標データ			*/
	STREAM_TYPE_BLENDWEIGHT	= 5,	/**< 頂点ウェイトデータ				*/
	STREAM_TYPE_MATRIXINDEX	= 6,	/**< マトリクスインデックスデータ	*/
	STREAM_TYPE_TANGENT		= 7,	/**< 接ベクトルデータ				*/
	STREAM_TYPE_BINORMAL	= 8,	/**< 従法線ベクトルデータ			*/

	STREAM_TYPE_COUNT				/**< ストリーム数					*/
};


/**
 * @struct MeshMaterial.
 * @brief メッシュ用マテリアルデータ構造体.
 */
struct MeshMaterial
{
	/** テクスチャデータを持っているか */
	bool			hasTexture;

	/** マテリアルデータ */
	Material		material;

	/** テクスチャデータ */
	ITexture*		texture;

	MeshMaterial():
		hasTexture( false ),
		texture( 0 )
	{}
};


/**
 * @struct FaceGroup.
 * @brief Msh 面データグループ構造体.
 */
struct FaceGroup
{
	/** 面情報フラグ */
	unsigned int	faceInfo;

	/** マテリアルナンバー */
	unsigned int	materialNo;

	/** 頂点インデックス数 */
	unsigned int	numIndices;

	/** 頂点インデックス開始位置 */
	unsigned int	startIndices;
};


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
	 * @brief 指定面データを取得する
	 *
	 * @param[in] faceNo 取得する面データ番号.
	 * @return 面データ構造体.
	 */
	virtual const FaceGroup& getFaceGroups( unsigned int faceNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定メッシュマテリアルデータを取得する
	 *
	 * @param[in] matNo 取得するメッシュマテリアル番号.
	 * @return メッシュマテリアル構造体.
	 */
	virtual const MeshMaterial& getMaterial( unsigned int matNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief インデックスバッファを取得
	 * 
	 * @param[in] なし.
	 * @return インデックスバッファポインタ.
	 */
	virtual IBuffer* getIndexBuffer() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 頂点バッファを取得
	 * 
	 * @param[in] stream 取得するバッファの種類.
	 * @return 頂点バッファポインタ.
	 */
	virtual IBuffer* getVertexBuffer( StreamType stream ) = 0;
	
	
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