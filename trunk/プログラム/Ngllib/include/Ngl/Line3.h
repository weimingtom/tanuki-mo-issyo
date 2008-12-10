/*******************************************************************************/
/**
 * @file Line3.h.
 * 
 * @brief 3次元線分構造体ヘッダファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_LINE_H_
#define _NGL_LINE_H_

#include	"Vector3.h"

#ifdef __cplusplus
#include "CollisionReport.h"

namespace Ngl{
#endif


/**
 * @struct Line3．
 * @brief 3次元線分構造体.
 */
typedef struct Line3
{
	/** 始点座標 */
	Vector3	begin;

	/** 終点座標 */
	Vector3 end;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	Line3();


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] Begin 開始位置3D座標.
	 * @param[in] End 終了位置3D座標.
	 */
	Line3( const Vector3& Begin, const Vector3& End );
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] Begin 開始位置座標配列.
	 * @param[in] End 終了位置座標配列.
	 */
	Line3( const float* Begin, const float* End );
	
	
	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] x 始点x座標.
	 * @param[in] y 始点y座標.
	 * @param[in] z 始点z座標.
	 * @param[in] eX 終点x座標.
	 * @param[in] eY 終点y座標.
	 * @param[in] eZ 終点z座標.
	 * @return なし.
	 */
	void initialize( float x, float y, float z, float eX, float eY, float eZ );

	
	/*=========================================================================*/
	/**
	 * @brief 初期化する
	 * 
	 * @param[in] Begin 開始位置3D座標.
	 * @param[in] End 終了位置3D座標.
	 * @return なし.
	 */
	void initialize( const Vector3& Begin, const Vector3& End );
	

	/*=========================================================================*/
	/**
	 * @brief 線分のベクトルを求める
	 * 
	 * @param[in] なし.
	 * @return 線分のベクトル.
	 */
	Vector3 getVector();
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D線分との衝突判定
	 * 
	 * @param[in] otherBegin 判定する3D線分の始点座標.
	 * @param[in] otherEnd 判定する3D線分の終点座標.
	 * @param[in] epsilon 判定の閾値.
	 * @return 衝突判定結果構造体.
	 */
	const LineCollisionReport& collision( const Vector3& otherBegin, const Vector3& otherEnd, float epsilon ); 
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D線分との衝突判定
	 * 
	 * @param[in] other 判定する3D線分.
	 * @param[in] epsilon 判定の閾値.
	 * @return 衝突判定結果構造体.
	 */
	const LineCollisionReport& collision( const Line3& other, float epsilon ); 
	
	
	/*=========================================================================*/
	/**
	 * @brief 線分と、指定座標の最も隣接する線分上の座標パラメータを求める
	 * 
	 * @param[in] x, 求める座標のx座標.
	 * @param[in] y, 求める座標のy座標.
	 * @param[in] z, 求める座標のz座標.
	 * @return 座標パラメータ.
	 */
	float getNearestPointParameter( float x, float y, float z );


	/*=========================================================================*/
	/**
	 * @brief 線分と、指定座標に最も隣接する線分上の座標を求める
	 * 
	 * @param[in] x, 求める座標のx座標.
	 * @param[in] y, 求める座標のy座標.
	 * @param[in] z, 求める座標のz座標.
	 * @return 最も隣接する座標.
	 */
	Vector3 findNearestPoint( float x, float y, float z );

#endif


} NGLline3;

#ifdef __cplusplus
} // namespace Ngl
#endif


#endif

/*===== EOF ==================================================================*/