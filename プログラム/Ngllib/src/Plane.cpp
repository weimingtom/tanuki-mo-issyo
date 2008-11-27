/*******************************************************************************/
/**
 * @file Plane.cpp.
 * 
 * @brief 平面構造体ソースファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Plane.h"
#include	"Ngl/MathUtility.h"
#include	<cfloat>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
Plane::Plane() :
	x( 0.0f ),
	y( 0.0f ),
	z( 0.0f ),
	d( 0.0f )
{}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] other 配列の先頭ポインタ.
 */
Plane::Plane(float *other)
{
	x = other[0];
	y = other[1];
	z = other[2];
	d = other[3];
}
	
	
	
/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] X 面法線x成分.
 * @param[in] Y 面法線y成分.
 * @param[in] Z 面法線z成分.
 * @param[in] D 原点からの距離.
 */
Plane::Plane(float X, float Y, float Z, float D) :
	x( X ),
	y( Y ),
	z( Z ),
	d( D )
{}



/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] N 法線ベクトル.
 * @param[in] D 原点からの距離.
 */
Plane::Plane(const Ngl::Vector3 &N, float D) :
	x( N.x ),
	y( N.y ),
	z( N.z ),
	d( D )
{}
	
	
	
/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] P 平面上の座標.
 * @param[in] N 法線ベクトル.
 */
Plane::Plane(const Ngl::Vector3 &P, const Ngl::Vector3 N)
{
	createFromPointNormal( P, N );
}
	
	
	
/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] v1 座標1.
 * @param[in] v2 座標2.
 * @param[in] v3 座標3.
 */
Plane::Plane(const Ngl::Vector3 &v1, const Ngl::Vector3 &v2, const Ngl::Vector3 &v3)
{
	createFromPoints( v1, v2, v3 );
}



/*===========================================================================*/
/**
 * @brief 平面を正規化する
 * 
 * @param[in] なし .
 * @return 正規化した平面.
 */
Plane& Plane::normalize()
{
	// 法線ベクトルの長さを求める
	float length =	Ngl::sqr( x )
				  + Ngl::sqr( y )
				  + Ngl::sqr( z );

	// 長さが0以外か
	if( length != 0 ){
		x /= length;
		y /= length;
		z /= length;
		d /= length;
	}

	return *this;
}


/*===========================================================================*/
/**
 * @brief 平面上の位置を取得する
 * 
 * @param[in] なし .
 * @return 位置座標.
 */
Ngl::Vector3 Plane::getPoint() const
{
	Ngl::Vector3 tmp;
	tmp.x = x * -d;
	tmp.y = y * -d;
	tmp.z = z * -d;

	return tmp;
}



/*===========================================================================*/
/**
 * @brief 平面とベクトルの内積を求める
 * 
 * @param[in] v 内積を求めるベクトル .
 * @return 内積.
 */
float Plane::dot(const Ngl::Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z;
}



/*===========================================================================*/
/**
 * @brief 平面と座標との距離を求める
 * 
 * @param[in] v 距離を求めるベクトル .
 * @return 距離.
 */
float Plane::distance(const Ngl::Vector3 &v) const
{
	return x * v.x + y * v.y + z * v.z + d;
}



/*===========================================================================*/
/**
 * @brief 平面と座標の位置関係を返す
 * 
 * @param[in] pos 調べる座標.
 * @return 位置関係.
 */
Plane::PlanePositionFlags Plane::getClassifyPoint(const Ngl::Vector3 &pos)
{
	// 座標との距離を求める
	float dis = distance( pos );

	// 平面の前面に点が存在するか
	if( dis > FLT_EPSILON ){
		return FRONT_PLANE;
	}

	// 平面の背面に点が存在するか
	if( dis < -FLT_EPSILON ){
		return BEHIND_PLANE;
	}

	// 平面状に点が存在する
	return ON_PLANE;
}



/*===========================================================================*/
/**
 * @brief 平面と球体の位置関係を返す
 * 
 * @param[in] center 球体の中心座標.
 * @param[in] radius 球体の半径.
 * @return 位置関係.
 */
Plane::PlanePositionFlags Plane::getClassifySphere(const Ngl::Vector3 &center, float radius)
{
	// 中心座標との距離を求める
	float dis = distance( center );

	// 平面と球体が交差しているか
	if( Ngl::abs( dis ) < radius ){
		return INTERSECTS_PLANE;
	}

	// 平面の前面に球体が存在しているか
	if( dis >= radius ){
		return FRONT_PLANE;
	}

	// 平面の背後に球体が存在していた
	return BEHIND_PLANE;
}



/*===========================================================================*/
/**
 * @brief 平面と線分が交差するか調べる
 * 
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @retval true 交差している.
 * @retval false 交差していない.
 */
bool Plane::intersectLine(const Ngl::Vector3 &line0, const Ngl::Vector3 &line1)
{
	// 平面と始点との距離を求める
	float distance1 = distance( line0 );

	// 平面と終点との距離を求める
	float distance2 = distance( line1 );

	// 始点と終点の距離が同符号の場合は交差しない
	if( ( distance1 * distance2 ) > 0 ){
		return false;
	}

	return true;
}



/*===========================================================================*/
/**
 * @brief 平面と線分が交差するか調べる
 * 
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @retval true 交差している.
 * @retval false 交差していない.
 */
Ngl::Vector3 Plane::intersectLinePosition
(
	const Ngl::Vector3 &line0,
	const Ngl::Vector3 &line1,
	const Ngl::Vector3 &retVec
)
{
	// 平面と線分が交点を持たないか
	if( intersectLine( line0, line1 ) == false ){
		return retVec;
	}

	// 線分の方向を求める
	Ngl::Vector3 dir = line1 - line0;

	// 平面と線分との交点を求める
	return intersectRayPositon( line0, dir, retVec );
}



/*===========================================================================*/
/**
 * @brief 平面とレイが交差するか調べる
 * 
 * @param[in] rayPos レイの始点.
 * @param[in] rayDir レイの方向.
 * @retval true 交差している.
 * @retval false 交差していない.
 */
bool Plane::intersectRay(const Ngl::Vector3 &rayPos, const Ngl::Vector3 &rayDir)
{
	// レイの方向を正規化する
	Ngl::Vector3 normal( rayDir );
	normal.normalize();

	// 平面と直線が平行か
	if( dot( normal ) == 0.0f ){
		return false;
	}

	return true;
}



/*===========================================================================*/
/**
 * @brief 平面とレイの交点座標を求める
 * 
 * @param[in] rayPos レイの始点.
 * @param[in] rayDir レイの方向.
 * @param[in] retVec 交差していなかった時に戻るベクトル.
 * @retval true 交差している.
 * @retval false 交差していない.
 */
Ngl::Vector3 Plane::intersectRayPositon
(
	const Ngl::Vector3 &rayPos,
	const Ngl::Vector3 &rayDir,
	const Ngl::Vector3 &retVec
)
{
	// レイの方向を正規化する
	Ngl::Vector3 normal( rayDir );
	normal.normalize();

	// 分母を求める
	float denominator = dot( normal );

	// 平面と直線が平行か
	if( denominator == 0.0f ){
		return retVec;
	}

	// 分子を求める
	float numerator = -distance( rayPos );

	// 始点と平面の距離を求める
	float dis = numerator / denominator;

	// 交点を求める
	Ngl::Vector3 intersect;
	intersect.linearEquation( rayPos, normal, dis );

	return intersect;
}



/*===========================================================================*/
/**
 * @brief 平面上の座標と平面の法線ベクトルから平面を作成する
 * 
 * @param[in] point 平面状の座標.
 * @param[in] normal 平面の法線ベクトル.
 * @return 作成した平面.
 */
Plane& Plane::createFromPointNormal(const Ngl::Vector3 &point, const Ngl::Vector3 &normal)
{
	x = normal.x;
	y = normal.y;
	z = normal.z;
	d = -normal.dot( point );

	return *this;
}



/*===========================================================================*/
/**
 * @brief 平面上の3つの座標から平面を作成する
 * 
 * @param[in] v1 座標1.
 * @param[in] v2 座標2.
 * @param[in] v3 座標3.
 * @return 作成した平面.
 */
Plane& Plane::createFromPoints(const Ngl::Vector3 &v1, const Ngl::Vector3 &v2, const Ngl::Vector3 &v3)
{
	// 法線ベクトルを求める
	Ngl::Vector3 normal = v1;
	normal = normal.calculateNoamal( v2, v3 );

	// 法線ベクトルと座標から平面を求める
	return createFromPointNormal( v1, normal );
}



/*===========================================================================*/
/**
 * @brief == 演算子オーバーロード
 * 
 * @param[in] other 演算する平面.
 * @retval true 一致している.
 * @retval false 一致していない.
 */
bool Plane::operator ==(const Ngl::Plane &other)
{
	return ( x == other.x && y == other.y && z == other.z && d == other.d );
}



/*===========================================================================*/
/**
 * @brief != 演算子オーバーロード
 * 
 * @param[in] other 演算する平面.
 * @retval true 一致していない.
 * @retval false 一致している.
 */
bool Plane::operator !=(const Ngl::Plane &other)
{
	return !(*this == other);
}



/*========= EOF =============================================================*/