/*******************************************************************************/
/**
 * @file Sphere.cpp.
 * 
 * @brief 球体構造体ソースファイル.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Sphere.h"
#include	"Ngl/Collision.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Sphere::Sphere():
	radius( 0.0f )
{}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] Center 中心座標.
 * @param[in] Radius 半径値.
 */
Sphere::Sphere( const Vector3& Center, const float Radius ):
	center( Center ),
	radius( Radius )
{}

	
	
/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] Center 中心座標配列.
 * @param[in] Radius 半径値.
 */
Sphere::Sphere( const float* Center, const float Radius ):
	center( Center ),
	radius( Radius )
{}

	
/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] X 中心座標のX座標.
 * @param[in] Y 中心座標のX座標.
 * @param[in] Z 中心座標のX座標.
 * @param[in] Radius 半径値.
 * @return なし.
 */
void Sphere::initialize( float X, float Y, float Z, float Radius )
{
	center.initialize( X, Y, Z );
	radius = Radius;
}
	
	
	
/*=========================================================================*/
/**
 * @brief 初期化する
 * 
 * @param[in] Center 中心座標.
 * @param[in] Radius 半径値.
 * @return なし.
 */
void Sphere::initialize( const Vector3& Center, float Radius )
{
	center = Center;
	radius = Radius;
}

	
	
/*=========================================================================*/
/**
 * @brief 単位球に設定
 * 
 * @param[in] なし.
 * @return なし.
 */
void Sphere::setIdentity()
{
	// 中心位置を原点に設定
	center = VECTOR3_ZERO;

	// 半径を1.0fに設定
	radius = 1.0f;
}

	
	
/*=========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] otherCenter 判定する球体の中心座標.
 * @param[in] otherRadius 判定する球体の半径値.
 * @retval true 衝突していた.
 * @retval false 衝突していない.
 */
bool Sphere::collision( const Vector3& otherCenter, const float otherRadius )
{
	Collision collision;
	return collision.sphereAndSphere( center, radius, otherCenter, otherRadius );
}


	
/*=========================================================================*/
/**
 * @brief 球体との衝突判定
 * 
 * @param[in] other 判定する球体.
 * @retval true 衝突していた.
 * @retval false 衝突していない.
 */
bool Sphere::collision( const Sphere& other )
{
	return collision( other.center, other.radius );
}

	
	
/*===== EOF ==================================================================*/