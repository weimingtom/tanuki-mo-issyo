/*******************************************************************************/
/**
 * @file Ray.cpp.
 * 
 * @brief 3次元無限線分構造体定義ソースファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Ray.h"
#include	"Ngl/Sphere.h"
#include	"Ngl/Collision.h"
#include	"Ngl/Vector3.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Ray::Ray()
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] pos 始点座標.
 * @param[in] dir 方向ベクトル.
 */
Ray::Ray( const Vector3& pos, const Vector3& dir ):
	position( pos ),
	direction( dir )
{}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] pos 始点座標配列.
 * @param[in] dir 方向ベクトル配列.
 */
Ray::Ray( const float* pos, const float* dir ):
	position( pos ),
	direction( dir )
{}

	
	
/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] x 始点x座標.
 * @param[in] y 始点y座標.
 * @param[in] z 始点z座標.
 * @param[in] DirX 方向ベクトルx座標.
 * @param[in] DirY 方向ベクトルy座標.
 * @param[in] DirZ 方向ベクトルz座標.
 * @return なし.
 */
void Ray::initialize( float x, float y, float z, float DirX, float DirY, float DirZ )
{
	// 位置座標を初期化
	position.initialize( x, y, z );

	// 方向を初期化
	direction.initialize( DirX, DirY ,DirZ );
}



/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] pos 始点座標.
 * @param[in] dir 方向ベクトル.
 * @return なし.
 */
void Ray::initialize( const Vector3& pos, const Vector3& dir )
{
	position = pos;
	direction = dir;
}


	
/*=========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] center 判定する球体の中心座標.
 * @param[in] radius 判定する球体の半径.
 * @retval true 衝突している.
 * @retval false 衝突していない.
 */
bool Ray::collision( const Vector3& center, float radius )
{
	Collision collision;
	return collision.sphereAndRay( center, radius, position, direction );
}

	
	
/*=========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] sphere 判定する球体.
 * @retval true 衝突している.
 * @retval false 衝突していない.
 */
bool Ray::collision( const Sphere& sphere )
{
	return collision( sphere.center, sphere.radius );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D線との衝突判定
 * 
 * @param[in] pos 判定する3D線の位置.
 * @param[in] dir 判定する.
 * @param[in] epsilon 閾値.
 * @return 衝突判定結果構造体.
 */
const LineCollisionReport&  Ray::collision( const Vector3& pos, const Vector3& dir, float epsilon )
{
	Collision collision;
	return collision.lineAndLine( position, direction, pos, dir, true, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 3D線との衝突判定
 * 
 * @param[in] other 判定する3D線.
 * @param[in] epsilon 閾値.
 * @return 衝突判定結果構造体.
 */
const LineCollisionReport& Ray::collision( const Ray& other, float epsilon )
{
	return collision( other.position, other.direction, epsilon );
}

	
	
/*=========================================================================*/
/**
 * @brief 無限直線と指定座標のもっとも近い無限直線の座標を求める
 * 
 * @param[in] x 求めたい位置のx座標.
 * @param[in] y 求めたい位置のy座標.
 * @param[in] z 求めたい位置のz座標.
 * @return 最も近い座標.
 */
Vector3 Ray::findNearestPosition( float x, float y, float z )
{
	// 無限直線の長さを求める
	float length = direction.lengthSq();

	// 線分のベクトルの長さが閾値よりも小さいか
	if( length < FLT_EPSILON ){
		// 始点が一番近い
		return position;
	}

	// 無限直線の始点から指定座標へのベクトルを求める
	Vector3 point = Vector3( x, y, z );
	Vector3 lp =  point - position;

	// 無限直線上の調べたい座標に最も近い座標を求める
	float t = direction.dot( lp ) / length;
	Vector3 result;
	return result.linearEquation( point, direction, t );
}

	
	
/*===== EOF ==================================================================*/