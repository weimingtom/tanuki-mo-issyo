/*******************************************************************************/
/**
 * @file MapMeshOct.h.
 * 
 * @brief Oct Oct形式マップメッシュクラスヘッダファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OCT_MAPMESHOCT_H_
#define _NGL_OCT_MAPMESHOCT_H_

#include	"Ngl/Frustum.h"
#include	"Ngl/Collision.h"
#include	"Ngl/IMapMesh.h"
#include	"Ngl/IMesh.h"
#include	"Ngl/IMeshCreator.h"
#include	"Ngl/IInputStream.h"
#include	"Ngl/IRenderer.h"

namespace Ngl{


namespace Oct{


/**
 * @class MapMeshOct．
 * @brief Oct Oct形式マップメッシュクラス.
 */
class MapMeshOct : public IMapMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 * @warning メッシュ作成者はMapMeshOctクラスで削除されます.
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 * @param[in] creator メッシュ作成者.
	 */
	MapMeshOct( IRenderer* renderer, IMeshCreator* creator );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~MapMeshOct();


	/*=========================================================================*/
	/**
	 * @brief ファイルからデータを読み込む
	 * 
	 * @param[in] fileName ファイル名.
	 * @return なし.
	 */
	void loadFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームからデータを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return なし.
	 */
	virtual void loadFromStream( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データを作成
	 * 
	 * @param[in] inputSignature 入力シグネチャ記述子の参照.
	 * @return なし.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature );

	
	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] effect エフェクトのポインタ.
	 * @param[in] matProj 4x4透視変換行列構造体の参照.
	 * @param[in] matView 4x4視野変換行列構造体の参照.
	 * @return なし.
	 */
	virtual void draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView );


	/*===========================================================================*/
	/**
	 * @brief 線分との衝突判定
	 * 
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 3D線との衝突判定
	 * 
	 * @param[in] rayPos レイの始点.
	 * @param[in] rayDir レイの方向.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& MapMeshOct::collisionRay( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief 球体との衝突判定
	 * 
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突結果構造体の参照.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius );

private:

	/** リーフノードフラグ */
	static const int LEAFNODE_FLAG = 1;

private:

	/**
	 * @struct NodeInfo.
	 * @brief Oct ノード情報構造体
	 */
	struct NodeInfo
	{
		/** 面データ情報番号 */
		int	faceGroupIndex;

		/** 面データグループ数 */
		int faceGroupCount;
	};

	/**
	 * @struct Node.
	 * @brief Oct オクツリーノード構造体.
	 */
	struct Node
	{
		/** リーフノードフラグ */
		bool					leafNodeFlag;

		/** ノードの幅 */
		Vector3			posMin;

		/** ノードの中心点 */
		Vector3			posMax;

		/** ノードのメッシュデータ */
		IMesh*			mesh;

		/** 子ノードへのポインタ */
		Node*			nodes[8];

		/** ノード情報 */
		NodeInfo		info;
	};

private:

	/*=========================================================================*/
	/**
	 * @brief ノードデータを読み込む
	 * 
	 * @param[in] stream 入力ストリームの参照.
	 * @param[in] node データを設定するオクツリーノードのポインタ.
	 * @return なし.
	 */
	void loadNodeData( IInputStream& stream, Node* node );
	
	
	/*=========================================================================*/
	/**
	 * @brief ノードを描画
	 * 
	 * @param[in] effect エフェクトのポインタ.
	 * @param[in] node 描画するノード構造体の参照.
	 * @return なし.
	 */
	void drawNode( IEffect* effect, Node& node );
	
	
	/*=========================================================================*/
	/**
	 * @brief 解放処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();


	/*===========================================================================*/
	/**
	 * @brief ノードと線分の衝突判定
	 * 
	 * @param[in] node オクツリーノードの参照.
	 * @param[in] line0 線分の始点.
	 * @param[in] line1 線分の終点.
	 * @return 面データ衝突結果構造体の参照.
	 */
	const PlaneCollisionReport& collisionNodeAndLine( Node& node, const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief ノードとレイの衝突判定
	 * 
	 * @param[in] node ノード.
	 * @param[in] rayPos レイの位置.
	 * @param[in] rayDir レイの方向.
	 * @return 面データ衝突結果構造体の参照.
	 */
	const PlaneCollisionReport& collisionNodeAndRay( Node& node, const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief ノードと球体の衝突判定
	 * 
	 * @param[in] node ノード.
	 * @param[in] center 球体の中心座標.
	 * @param[in] radius 球体の半径.
	 * @return 面データ衝突結果構造体の参照.
	 */
	const PlaneCollisionReport& collisionNodeAndSphere( MapMeshOct::Node& node, const float* center, float radius );

private:

	/** レンダラークラスのポインタ */
	IRenderer*				renderer_;

	/** メッシュ作成者 */
	IMeshCreator*			meshCreator_;

	/** メッシュデータ */
	IMesh*					mesh_;

	/** ノード数 */
	unsigned int			nodeCount_;

	/** ノード */
	Node*					nodes_;

	/** 視錐台 */
	Frustum					frustum_;

	/** 衝突判定 */
	Collision				collision_;

};

} // namespace Oct

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/