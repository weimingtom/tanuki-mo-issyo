/*******************************************************************************/
/**
 * @file Mesh.h.
 * 
 * @brief メッシュクラスヘッダファイル.
 *
 * @date 2008/10/09.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESH_H_
#define _NGL_MESH_H_

#include	"Ngl/MeshCollision.h"
#include	"Ngl/IMesh.h"
#include	"Ngl/ITextureCreator.h"
#include	<map>
#include	<vector>
#include	<string>

namespace Ngl{


/**
 * @class Mesh.
 * @brief メッシュクラス.
 */
class Mesh : public IMesh
{
public:

	/**
	 * @struct VertexFormat.
	 * @brief 頂点フォーマット構造体.
	 */
	struct VertexFormat
	{
		/** 頂点数 */
		unsigned int	numVertices;

		/** 頂点インデックス数 */
		unsigned int	numIndices;

		/** 頂点ウェイト数 */
		unsigned int	numWeights;

		/** 行列インデックスを持っているか */
		bool			hasMatrixIndices;

		/** テクスチャ座標系データを持っているか */
		bool			hasTextureSpace;
	};

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] renderer レンダラー.
	 */
	Mesh( IRenderer* renderer );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~Mesh();


	/*=========================================================================*/
	/**
	 * @brief 頂点フォーマットを設定
	 * 
	 * @param[in] format 頂点フォーマット構造体.
	 * @return なし.
	 */
	void setVertexFormat( const VertexFormat& format );
	
	
	/*=========================================================================*/
	/**
	 * @brief バッファデータを設定
	 * 
	 * @warning 設定したバッファはMeshクラスで削除されます。
	 *
	 * @param[in] buf 設定するバッファのポインタ.
	 * @param[in] type 設定するバッファのストリームタイプ.
	 * @return なし.
	 */
	void setBuffer( IBuffer* buf, StreamType type );
	
	
	/*=========================================================================*/
	/**
	 * @brief インデックスバッファデータを設定
	 * 
	 * @warning 設定したバッファはMeshクラスで削除されます。
	 *
	 * @param[in] buf 設定するバッファのポインタ.
	 * @return なし.
	 */
	void setIndexBuffer( IBuffer* buf );
	
	
	/*=========================================================================*/
	/**
	 * @brief マテリアルデータを設定
	 * 
	 * Meshクラスに設定した順番で、マテリアル番号が自動的に設定されます。
	 *
	 * @warning 設定したマテリアルはMeshクラスで削除されます。
	 * @warning テクスチャが設定されていた場合は、ともに削除されます。
	 *
	 * @param[in] material 設定するマテリアルのポインタ.
	 * @return なし.
	 */
	void setMaterial( MeshMaterial* material );
	
	
	/*=========================================================================*/
	/**
	 * @brief 面データグループを設定
	 * 
	 * Meshクラスに設定した順番で、面データグループ番号が自動的に設定されます。
	 *
	 * @warning 設定した面データグループはMeshクラスで削除されます。
	 *
	 * @param[in] face 設定する面データグループのポインタ.
	 * @return なし.
	 */
	void setFaceGroup( FaceGroup* face );
	
	
	/*=========================================================================*/
	/**
	 * @brief 衝突判定データを作成する
	 *
	 * 設定されている頂点バッファとインデックスバッファから衝突判定データを作成します。<br>
	 * どちらかのバッファしか設定されていない場合は、作成されません。<br>
	 *
	 * @param[in] なし.
	 * @return なし.
	 */
	void createCollisionData();
	
	
	/*=========================================================================*/
	/**
	 * @brief 解放処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();

public:
	
	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] effect エフェクトのポインタ.
	 * @return なし.
	 */
	virtual void draw( IEffect* effect );

	
	/*=========================================================================*/
	/**
	 * @brief サブセットを描画
	 * 
	 * @param[in] faceNo 面データ番号.
	 * @param[in] effect エフェクト.
	 * @return なし.
	 */
	virtual void drawSubset( unsigned int faceNo, IEffect* effect );

	
	/*=========================================================================*/
	/**
	 * @brief メッシュ情報を取得
	 * 
	 * @param[in] なし.
	 * @return メッシュ情報構造体.
	 */
	virtual const MeshInfo& info() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief エフェクト出力記述子を取得
	 * 
	 * @param[in] なし.
	 * @return エフェクト出力記述子.
	 */
	virtual const EffectOutputDesc& effectOutputDesc() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief エフェクト出力記述子を設定
	 * 
	 * @param[in] desc エフェクト出力記述子.
	 * @return なし.
	 */
	virtual void effectOutputDesc( const EffectOutputDesc& desc );
	

	/*=========================================================================*/
	/**
	 * @brief 指定面データを取得する
	 *
	 * @param[in] faceNo 取得する面データ番号.
	 * @return 面データ構造体.
	 */
	virtual const FaceGroup& getFaceGroups( unsigned int faceNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief 指定メッシュマテリアルデータを取得する
	 *
	 * @param[in] matNo 取得するメッシュマテリアル番号.
	 * @return メッシュマテリアル構造体.
	 */
	virtual const MeshMaterial& getMaterial( unsigned int matNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief インデックスバッファを取得
	 * 
	 * @param[in] なし.
	 * @return インデックスバッファポインタ.
	 */
	virtual IBuffer* getIndexBuffer();
	
	
	/*=========================================================================*/
	/**
	 * @brief 頂点バッファを取得
	 * 
	 * @param[in] stream 取得するバッファの種類.
	 * @return 頂点バッファポインタ.
	 */
	virtual IBuffer* getVertexBuffer( StreamType stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データを作成
	 * 
	 * @param[in] inputSignature 入力シグネチャ記述子の参照.
	 * @return なし.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature );

	
	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと線分との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndLine( int faceNo, const float* line0, const float* line1 );

	
	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと3D線との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] rayPos 3D線の始点座標.
	 * @param[in] rayDir 3D線の方向.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir );

	
	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius );


	/*===========================================================================*/
	/**
	 * @brief 指定の面データグループと球体との衝突判定
	 * 
	 * @param[in] faceNo 面データグループ番号.
	 * @param[in] center 球体の中心位置.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突パラメーター.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndSphere( int faceNo, const float* center, float radius );

private:
	
	/*=========================================================================*/
	/**
	 * @brief 頂点ストリームデータを設定
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void setVertexStream();


	/*=========================================================================*/
	/**
	 * @brief ストリームタイプを設定する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void setStreamType();

	
	/*=========================================================================*/
	/**
	 * @brief ストリームタイプからセマンティックを取得
	 * 
	 * @param[in] type ストリームタイプ.
	 * @return なし.
	 */
	VertexSemantic getSemantic( StreamType type );

	
	/*=========================================================================*/
	/**
	 * @brief ストリームタイプから頂点セマンティックを取得
	 * 
	 * @param[in] type ストリームタイプ.
	 * @return なし.
	 */
	VertexType getType( StreamType type );

	
	/*=========================================================================*/
	/**
	 * @brief ストリームタイプから1要素の要素数を取得
	 * 
	 * @param[in] type ストリームタイプ.
	 * @return なし.
	 */
	unsigned int getStride( StreamType type );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ (コピー禁止)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	Mesh( const Mesh& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード (コピー禁止)
	 * 
	 * @param[in] other コピー元のオブジェクト.
	 * @return コピー結果のオブジェクト.
	 */
	Mesh& operator = ( const Mesh& other );	

private:

	// バッファデータリスト型
	typedef std::map< StreamType, IBuffer* >	BufferList;

	// マテリアルデータ配列型
	typedef std::vector< MeshMaterial* >		MaterialArray;

	// 面データ配列型
	typedef std::vector< FaceGroup* >			FaceGroupArray;

	/** ストリームタイプ配列型 */
	typedef std::vector< StreamType >			StreamTypeArray;

	/** ストリーム記述子配列型 */
	typedef std::vector< VertexStreamDesc >		StreamDescArray;

private:

	/** レンダラークラスのポインタ */
	IRenderer*			renderer_;

	/** メッシュ情報フラグ */
	unsigned int		meshInfo_;

	/** インデックスバッファ */
	IBuffer*			indexBuffer_;

	/** バッファリスト */
	BufferList			bufferList_;

	/** マテリアルデータ配列 */
	MaterialArray		materialArray_;

	/** 面データグループ配列 */
	FaceGroupArray		faceGroupArray_;

	/** 頂点宣言データ */
	IVertexDeclaration*	vertexDeclaration_;

	/** ストリーム配列 */
	StreamTypeArray		streamTypeArray_;

	/** ストリーム記述子配列 */
	StreamDescArray		streamDescArray_;

	/** メッシュ情報構造体 */
	MeshInfo			info_;

	/** エフェクト出力記述子構造体 */
	EffectOutputDesc	effectOutputDesc_;

	/** メッシュ衝突判定クラス */
	MeshCollision		collision_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/