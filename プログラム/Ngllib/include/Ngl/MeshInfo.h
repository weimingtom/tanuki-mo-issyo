/*******************************************************************************/
/**
 * @file MeshInfo.h.
 * 
 * @brief メッシュ情報構造体定義.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESHINFO_H_
#define _NGL_MESHINFO_H_

namespace Ngl{


/**
 * @struct MeshInfo.
 * @brief メッシュ情報構造体.
 */
struct MeshInfo
{
	/** 頂点数 */
	unsigned int		numVertices;

	/** 頂点インデックス数 */
	unsigned int		numIndices;

	/** サブセット数 */
	unsigned int		numSubsets;

	/** マテリアルデータ数 */
	unsigned int		numMaterials;

	/** 頂点ウェイト数 */
	unsigned int		numWeights;

	/** 行列インデックスがあるか */
	bool				hasMatrixIndices;

	/** テクスチャデータがあるマテリアルがあるか */
	bool				hasTexture;

	/** テクスチャ座標系データがあるか */
	bool				hasTextureSpace;

	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	MeshInfo():
		numVertices( 0 ),
		numIndices( 0 ),
		numSubsets( 0 ),
		numMaterials( 0 ),
		numWeights( 0 ),
		hasMatrixIndices( false ),
		hasTexture( false ),
		hasTextureSpace( false )
	{}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/