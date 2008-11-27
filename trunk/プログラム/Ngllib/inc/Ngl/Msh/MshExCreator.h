/*******************************************************************************/
/**
 * @file MshExCreator.h.
 * 
 * @brief Msh msh,mshex形式メッシュファイル作成クラスヘッダファイル.
 *
 * @date 2008/10/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_MSHEXCREATOR_H_
#define _NGL_MSH_MSHEXCREATOR_H_

#include	"Ngl/IMeshCreator.h"


namespace Ngl{

// メッシュクラス
class Mesh;


namespace Msh{


/**
 * @class MshExCreator．
 * @brief Msh msh,mshex形式メッシュファイル読み込みクラス.
 */
class MshExCreator : public IMeshCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] renderer レンダラー.
	 */
	MshExCreator( IRenderer* renderer );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~MshExCreator();

	
	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したメッシュクラス.
	 */
	IMesh* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームから作成する
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したメッシュクラス.
	 */
	IMesh* createFromStream( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief テクスチャ作成クラスを設定
	 * 
	 * @warning 設定したクラスはMshExCreatorクラスで削除されます.
	 *
	 * @param[in] creator テクスチャ作成クラスのポインタ.
	 * @return なし.
	 */
	void setTextureCreator( ITextureCreator* creator );

private:

	/*=========================================================================*/
	/**
	 * @brief メッシュデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return なし.
	 */
	void loadMeshData( IInputStream& stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief マテリアルデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] mesh メッシュ.
	 * @return なし.
	 */
	void loadMaterial( IInputStream& stream, Mesh* mesh );

	
	/*=========================================================================*/
	/**
	 * @brief 面データを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] mesh メッシュ.
	 * @return なし.
	 */
	void loadFaceGroup( IInputStream& stream, Mesh* mesh );

	
	/*=========================================================================*/
	/**
	 * @brief インデックスデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したバッファ.
	 */
	IBuffer* loadIndices( IInputStream& stream );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点データを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] numElements 1要素の要素数.
	 * @return 作成したバッファ.
	 */
	IBuffer* loadVertexBuffer( IInputStream& stream, unsigned int numElements );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点ウェイトデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したバッファ.
	 */
	IBuffer* loadVertexWeight( IInputStream& stream );

	
	/*=========================================================================*/
	/**
	 * @brief マトリクスインデックスデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したバッファ.
	 */
	IBuffer* loadMatrixIndex( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief 頂点フォーマットを設定
	 * 
	 * @param[in] mesh メッシュ.
	 * @return なし.
	 */
	void setVertexFormat( Mesh* mesh );

private:

	/** データが書き込まれていない */
	static const int NOTWRITTEN		= 0;

	/** データが書き込まれている */
	static const int WRITTEN		= 1;

	/** テクスチャデータが存在するか */
	static const int TEXTUREMAPPED	= 1 << 0;

	/** メッシュフラグ最大数 */
	static const int MESHFLAG_MAX	= 8;

private:

	/**
	 * @enum MeshFlagType
	 * @brief メッシュフラグタイプ列挙型.
	 */
	enum MeshFlagType
	{
		MESHFLAGTYPE_VERTEX				= 0,	/**< 頂点データがあるか				*/
		MESHFLAGTYPE_NORMAL				= 1,	/**< 法線データがあるか				*/
		MESHFLAGTYPE_DIFFUSECOLORS		= 2,	/**< 拡散反射光カラーデータがあるか	*/
		MESHFLAGTYPE_SPECULARCOLORS		= 3,	/**< 鏡面反射光カラーデータがあるか	*/
		MESHFLAGTYPE_NUMTEXCOORDS		= 4,	/**< テクスチャ座標データ数			*/
		MESHFLAGTYPE_NUMWEIGHTS			= 5,	/**< 頂点ウェイト数					*/
		MESHFLAGTYPE_MATRIXINDICES		= 6,	/**< 行列インデックスデータがあるか	*/
		MESHFLAGTYPE_TEXTURESPACE		= 7		/**< テクスチャ座標系データがあるか	*/
	};

private:

	/** レンダラー */
	IRenderer*			renderer_;

	/** テクスチャ作成者 */
	ITextureCreator*	textureCreator_;

	/** テクスチャ座標系データがあるか	*/
	bool				hasTextureSpace_;

	/** マテリアル数 */
	unsigned int		numMaterials_;

	/** 面データ数 */
	unsigned int		numFaceGroups_;

	/** 頂点データ数 */
	unsigned int		numVertices_;

	/** インデックスデータ数 */
	unsigned int		numIndices_;

	/** 頂点ウェイト数 */
	unsigned int		numWeights_;

	/** メッシュフラグ配列 */
	unsigned int		meshFlag[ MESHFLAG_MAX ];

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/