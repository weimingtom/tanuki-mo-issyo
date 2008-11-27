/*******************************************************************************/
/**
 * @file Line3.cpp.
 * 
 * @brief 3次元線分構造体ソースファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Line3.h"
#include	"Ngl/Collision.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/MathUtility.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Line3::Line3()
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] Begin 開始位置3D座標.
 * @param[in] End 終了位置3D座標.
 */
Line3::Line3( const Vector3& Begin, const Vector3& End ):
	begin( Begin ),
	end( End )
{}
	
	

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] Begin 開始位置座標配列.
 * @param[in] End 終了位置座標配列.
 */
Line3::Line3( const float* Begin, const float* End )
{
	begin.initialize( Begin[ 0 ], Begin[ 1 ], Begin[ 2 ] );
	end.initialize( End[ 0 ], End[ 1 ], End[ 2 ] );
}

	
		
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
void Line3::initialize( float x, float y, float z, float eX, float eY, float eZ )
{
	begin.initialize( x, y, z );
	end.initialize( eX, eY, eZ );
}


	
/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] Begin 開始位置3D座標.
 * @param[in] End 終了位置3D座標.
 * @return なし.
 */
void Line3::initialize( const Vector3& Begin, const Vector3& End )
{
	begin = Begin;
	end = End;
}
	
	

/*=========================================================================*/
/**
 * @brief 線分のベクトルを求める
 * 
 * @param[in] なし.
 * @return 線分のベクトル.
 */
Vector3 Line3::getVector()
{
	Vector3 result = begin - end;
	return result;
}	
	
	
	
/*=========================================================================*/
/**
 * @brief 3D線分との衝突判定
 * 
 * @param[in] otherBegin 判定する3D線分の始点座標.
 * @param[in] otherEnd 判定する3D線分の終点座標.
 * @param[in] epsilon 判定の閾値.
 * @return 衝突判定結果構造体.
 */
const LineCollisionReport& Line3::collision( const Vector3& otherBegin, const Vector3& otherEnd, float epsilon )
{
	Collision collision;
	return collision.lineAndLine( begin, end, otherBegin, otherEnd, false, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D線分との衝突判定
 * 
 * @param[in] other 判定する3D線分.
 * @param[in] epsilon 判定の閾値.
 * @return 衝突判定結果構造体.
 */
const LineCollisionReport&  Line3::collision( const Line3& other, float epsilon )
{
	return collision( other.begin, other.end, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 線分と、指定座標の最も隣接する線分上の座標パラメータを求める
 * 
 * @param[in] x, 求める座標のx座標.
 * @param[in] y, 求める座標のy座標.
 * @param[in] z, 求める座標のz座標.
 * @return 座標パラメータ.
 */
float Line3::getNearestPointParameter( float x, float y, float z )
{
	// 線分のベクトルを求める
	Vector3 vec = getVector();

	// ベクトルの長さを求める
	float length = vec.lengthSq();

	// 線分の長さが閾値よりも小さいか
	if( length < FLT_EPSILON ){
		return 0.0f;
	}

	// 線分の始点から指定座標へのベクトルを求める
	Vector3 point( x, y, z );
	Vector3 lp = point - begin;

	// 調べたい座標に最も近い座標へのパラメータを求める
	float t = vec.dot( lp ) / length;

	// パラメータをクランプ
	return clamp( t, 0.0f, 1.0f );
}



/*=========================================================================*/
/**
 * @brief 線分と、指定座標に最も隣接する線分上の座標を求める
 * 
 * @param[in] x, 求める座標のx座標.
 * @param[in] y, 求める座標のy座標.
 * @param[in] z, 求める座標のz座標.
 * @return 最も隣接する座標.
 */
Vector3 Line3::findNearestPoint( float x, float y, float z )
{
	// 最も近い座標へのパラメータを求める
	float t = getNearestPointParameter( x, y, z );

	// 求めたパラメータから最も近い座標を求める
	Vector3 result;
	result.linearEquation( begin, getVector(), t );

	return result;
}

	
	
/*===== EOF ==================================================================*/