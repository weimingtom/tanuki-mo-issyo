/*******************************************************************************/
/**
 * @file Collision.cpp.
 * 
 * @brief 衝突判定クラスソースファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Collision.h"
#include	"Ngl/MathUtility.h"
#include	"Ngl/Line3.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief 球体と球体の衝突判定
 * 
 * @param[in] center1 球体1の3D頂点座標配列.
 * @param[in] radius1 球体1の半径値.	
 * @param[in] center2 球体2の3D頂点座標配列.
 * @param[in] radius2 球体2の半径値.	
 * @retval true 衝突していた.
 * @retval false 衝突していなかった.
 */
bool Collision::sphereAndSphere
( 
	const Ngl::Vector3&	center1, 
	float				radius1, 
	const Ngl::Vector3&	center2, 
	float				radius2
)
{
	// 球体間の距離を求める
	Vector3 v = center1 - center2;
	float distance = v.length();

	// 2つの球体の半径を加算した値よりも小さいか
	if( distance <= ( radius1 + radius2 ) ){
		return true;
	}
	
	return false;
}



/*===========================================================================*/
/**
 * @brief 球体を衝突しない座標へ補正する
 * 
 * @param[out] center 球体の3D中心位置座標.
 * @param[in] radius 球体の半径.
 * @param[in] intersect 3D交点座標. 
 * @return なし.
 */
void Collision::sphereRevisePosition
( 
	Ngl::Vector3&		center, 
	float				radius,
	const Ngl::Vector3&	intersect
)
{
	// 交点から中心までのベクトルを求める
	Vector3 offset = center - intersect;
	offset.normalize();

	// 交差している部分を補正する
	offset *= ( radius - Ngl::sqrt( Ngl::sqr( center.distanceSq( intersect ) ) ) );

	Vector3 result = center;
	result += offset;

	center = result;
}



/*=========================================================================*/
/**
 * @brief 球体と線の衝突判定
 * 
 * @param[in] center 球体の3D頂点座標配列.
 * @param[in] radius 球体の半径値.	
 * @param[in] rayPos 線の3D位置座標配列.
 * @param[in] rayDir 線の方向3Dベクトル配列.	
 * @retval true 衝突していた.
 * @retval false 衝突していなかった.
 */
bool Collision::sphereAndRay
(
	const Ngl::Vector3&	center, 
	float				radius, 
	const Ngl::Vector3&	rayPos, 
	const Ngl::Vector3&	rayDir
)
{
	// 球体の中心から線へのベクトルを求める
	Vector3 v = rayPos - center;

	float a = rayDir.lengthSq();
	float b = v.dot( rayDir );
	float c = v.lengthSq() - Ngl::sqr( radius );

	float d = Ngl::sqr( b ) - a * c;
	if( d < 0.0f ){
		return false;
	}
	
	return true;
}


	
/*=========================================================================*/
/**
 * @brief 線分と線分の衝突判定
 * 
 * @param[in] a1 判定する線分1の始点3D座標.
 * @param[in] a2 判定する線分1の終点3D座標.
 * @param[in] b1 判定する線分2の始点3D座標.
 * @param[in] b2 判定する線分2の終点3D座標.
 * @param[in] isRay 無限線分かどうか.
 * @param[in] epsilon 閾値.
 * @return 衝突判定結果構造体.
 */
const LineCollisionReport& Collision::lineAndLine
(
	const Ngl::Vector3& a1, 
	const Ngl::Vector3& a2, 
	const Ngl::Vector3& b1, 
	const Ngl::Vector3& b2,
	bool				isRay,
	float				epsilon
)
{
	// 結果リポートを初期化
	lineReport_ = LINECOLLISIONREPORT_NOT_COLLISION;

	// 線分a, bのベクトルを求める
	Vector3 VA = a2 - a1;
	Vector3 VB = b2 - b1;

	// 線分a, bの２乗和を求める
	float l11 = VA.lengthSq();
	float l22 = VB.lengthSq();

	// aの長さが閾値未満か( 点と線分の判定 )
	if( l11 < FLT_EPSILON ){
		// 線分aの始点座標に最も近い線分b上の座標を求める
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, VB, a1, isRay, lineReport_.intersectPosB, dammy );
	}
	// bの長さが閾値未満か( 点と線分の判定 )
	else if( l22 < FLT_EPSILON ){
		// 線分bの始点座標に最も近い線分a上の座標を求める
		float dammy = 0.0f;
		findNearestPointOnLineSegment( a1, VA, b1, isRay, lineReport_.intersectPosA, dammy );
	}
	// 線分aと、線分bが閾値よりも大きい
	else{
		Vector3 AB = b1 - a1;
		float l12 = -VA.dot( VB );
		float detL = l11 * l22 - Ngl::sqr( l12 );

		if( Ngl::abs( detL ) < FLT_EPSILON ){
			// 線分bの視点座標に最も近い線分a上の座標を求める
			findNearestPointOfParallelLineSegments(
				a1, a2, VA,
				b1, b1, VB,
				isRay,
				lineReport_.intersectPosA,
				lineReport_.intersectPosB
				);
		}
		else{
			float ra = VA.dot( AB );
			float rb = -VB.dot( AB );
			float t = ( l11 * rb - ra * l12 ) / detL;
			float s = ( ra - l12 * t ) / l11;
			lineReport_.intersectPosA.linearEquation( a1, VA, s );
			lineReport_.intersectPosB.linearEquation( a2, VB, t );

			// 有限線分で、どちらかの線分が少し離れているか
			if( ( isRay == false ) && 
				( Ngl::outOfRange( s, 0.0f, 1.0f ) == true || Ngl::outOfRange( t, 0.0f, 1.0f ) == true )
				){
				// 有限線分同士の最も近い点の調整をする
				adjustNearestPoint(
					a1, VA,
					b1, VB,
					s, t,
					lineReport_.intersectPosA,
					lineReport_.intersectPosB
					);
			}
		}
	}

	// 最も近い点同士の距離がの閾値よりも短い場合は衝突している
	if( lineReport_.intersectPosA.distanceSq( lineReport_.intersectPosB ) <= Ngl::sqr( epsilon ) ){
		return lineReport_;
	}

	// 衝突していなかった
	return LINECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*=========================================================================*/
/**
 * @brief 線分と、指定座標の最も隣接する線分上の座標を求める
 * 
 * @param[in] linePos 線分の座標.
 * @param[in] lineVec 線分の方向.
 * @param[in] point 調べたい座標.
 * @param[in] isRay 無限線分か.
 * @param[out] np 線分上の隣接する座標.
 * @param[out] parameter 直線の方程式パラメータ.
 * @return なし.
 */
void Collision::findNearestPointOnLineSegment
(
	const Ngl::Vector3& linePos,
	const Ngl::Vector3& lineVec,
	const Ngl::Vector3& point,
	bool				isRay,
	Ngl::Vector3&		np,
	float&				parameter
)
{
	// 線分のベクトルの長さを求める
	float distance = lineVec.lengthSq();

	// 線分のベクトルの長さよりが閾値よりも小さいか
	if( distance < FLT_EPSILON ){
		// 線分の視点が最も近い点( 線分を点として扱う )
		np = linePos;
		parameter = 0.0f;
	}

	// 線分の視点から、点へのベクトルを求める
	Vector3 vLP = point - linePos;

	// 線分上の調べたい座標に最も近い座標のパラメータを求める
	float t = lineVec.dot( vLP ) / distance;

	// 有限線分か
	if( isRay == false ){
		t = Ngl::clamp( t, 0.0f, 1.0f );
	}

	// 求めたパラメータから最も近い座標を求める
	np.linearEquation( linePos, lineVec, t );
	parameter = t;
}

	

/*=========================================================================*/
/**
 * @brief 線分同士が交差しない場合の、線分同士で最も近い点を求める
 * 
 * @param[in] a1 判定する線分aの始点3D座標.
 * @param[in] a2 判定する線分aの終点3D座標.
 * @param[in] va 線分aの始点から終点へのベクトル.
 * @param[in] b1 判定する線分bの始点3D座標.
 * @param[in] b2 判定する線分bの終点3D座標.
 * @param[in] vb 線分bの始点から終点へのベクトル.
 * @param[in] isRay 無限線分かどうか.
 * @param[out] pa 線分a上の、線分bに最も近い3D座標.
 * @param[out] pb 線分b上の、線分aに最も近い3D座標.
 * @return なし.
 */
void Collision::findNearestPointOfParallelLineSegments
(
	const Ngl::Vector3& a1, 
	const Ngl::Vector3& a2,
	const Ngl::Vector3& va,
	const Ngl::Vector3& b1, 
	const Ngl::Vector3& b2,
	const Ngl::Vector3& vb,
	bool				isRay,
	Ngl::Vector3&		pa,
	Ngl::Vector3&		pb
)
{
	// 線分a上の座標で、最も線分bの始点に近い座標を求める
	float s1 = 0.0f;
	findNearestPointOnLineSegment( a1, va, b1, true, pa, s1 );

	// 無限線分か
	if( isRay == true ){
		// 無限線分の場合は、線分bの始点が最も近い座標
		pb = b1;

		return;
	}

	// 線分a上の座標で、最も線分bの終点に近い座標を求める
	float s2 = 0.0f;
	Vector3 tmpPoint;
	findNearestPointOnLineSegment( a1, va, b2, true, tmpPoint, s2 );

	if( ( s1 < 0.0f ) && ( s2 < 0.0f ) ){
		pa = a1;
		pb = ( s1 < s2 ) ? b2 : b1;
	}
	else if( ( s1 > 1.0f ) && ( s2 > 1.0f ) ){
		pa = a2;
		pb = ( s1 < s2 ) ? b1 : b2;
	}
	else{
		float t = 0.5f * ( Ngl::clamp( s1, 0.0f, 1.0f ) + Ngl::clamp( s2, 0.0f, 1.0f ) );
		pa.linearEquation( a1, va, t );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, vb, pa, true, pb, dammy );
	}
}
	
	

/*=========================================================================*/
/**
 * @brief 線分同士の、最も近い座標の調整をする
 * 
 * @param[in] a1 判定する線分aの始点3D座標.
 * @param[in] va 線分aの始点から終点へのベクトル.
 * @param[in] b1 判定する線分bの始点3D座標.
 * @param[in] vb 線分bの始点から終点へのベクトル.
 * @param[in] s 線分aの直線方程式パラメータ.
 * @param[in] t 線分bの直線方程式パラメータ.
 * @param[out] pa 線分a上の、線分bに最も近い3D座標.
 * @param[out] pb 線分b上の、線分aに最も近い3D座標.
 * @return なし.
 */
void Collision::adjustNearestPoint
(
	const Ngl::Vector3& a1,
	const Ngl::Vector3& va,
	const Ngl::Vector3& b1,
	const Ngl::Vector3& vb,
	float				s,
	float				t,
	Ngl::Vector3&		pa,
	Ngl::Vector3&		pb
)
{
	if( Ngl::outOfRange( s, 0.0f, 1.0f ) == true && Ngl::outOfRange( t, 0.0f, 1.0f ) == true ){
		s = Ngl::clamp( s, 0.0f, 1.0f );
		pa.linearEquation( a1, va, s );
		findNearestPointOnLineSegment( b1, vb, pa, true, pb, t );

		if( Ngl::outOfRange( t, 0.0f, 1.0f ) == true ){
			t = Ngl::clamp( t, 0.0f, 1.0f );
			pb.linearEquation( b1, vb, t );
			float dammy = 0.0f;
			findNearestPointOnLineSegment( a1, va, pb, false, pa, dammy );
			findNearestPointOnLineSegment( b1, vb, pa, false, pb, dammy );
		}
	}
	else if( Ngl::outOfRange( s, 0.0f, 1.0f ) == true ){
		s = Ngl::clamp( s, 0.0f, 1.0f );
		pa.linearEquation( a1, va, s );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, vb, pa, false, pb, dammy );
	}
	else{
		t = Ngl::clamp( t, 0.0f, 1.0f );
		pb.linearEquation( b1, vb, t );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( a1, va, pb, false, pa, dammy );
	}
}

	
	
/*===========================================================================*/
/**
 * @brief 線分がボックス内に存在するかチェックする
 * 
 * @param[in] min ボックスの最小座標.
 * @param[in] max ボックスの最大座標.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @retval true 存在する.
 * @retval false 存在しない.
 */
bool Collision::lineIsInsideBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& line0,
	const Vector3& line1
)
{
	// ボックスが完全に外側に存在しているか
	if( lineIsOutsideBox( min, max, line0, line1 ) == true ){
		return false;
	}

	// 始点がボックス内に存在するか
	if( ( line0.x >= min.x && line0.x <= max.x ) &&
		( line0.y >= min.y && line0.y <= max.y ) &&
		( line0.z >= min.z && line0.z <= max.z )
		){
		return true;
	}

	// 終点がボックス内に存在するか
	if( ( line1.x >= min.x && line1.x <= max.x ) &&
		( line1.y >= min.y && line1.y <= max.y ) &&
		( line1.z >= min.z && line1.z <= max.z )
		){
		return true;
	}

	// 線分の方向を求める
	Vector3 dir = line1 - line0;
	dir.normalize();

	// 線分がボックスと交差するか
	return rayIsIntersectBox( min, max, line0, dir );
}



/*===========================================================================*/
/**
 * @brief 線分がボックスの外にあるかチェックする
 * 
 * @param[in] min ボックスの最小座標.
 * @param[in] max ボックスの最大座標.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点.
 * @retval true 存在する.
 * @retval false 存在しない.
 */
bool Collision::lineIsOutsideBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& line0,
	const Vector3& line1
)
{
	// 完全にボックスよりも外にあるか
	if( ( line0.x < min.x && line1.x < min.x ) ||
		( line0.y < min.y && line1.y < min.y ) ||
		( line0.z < min.z && line1.z < min.z ) ||
		( line0.x > max.x && line1.x > max.x ) ||
		( line0.y > max.y && line1.y > max.y ) ||
		( line0.z > max.z && line1.z > max.z )
		){
		return true;
	}

	// ボックスの内側に存在している
	return false;
}
	
	

/*===========================================================================*/
/**
 * @brief レイとボックスが交差するかチェックする
 * 
 * @param[in] min ボックスの最小座標.
 * @param[in] max ボックスの最大座標.
 * @param[in] rayPos レイの位置.
 * @param[in] rayDir レイの方向.
 * @retval true 交差する.
 * @retval false 交差しない.
 */
bool Collision::rayIsIntersectBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& rayPos,
	const Vector3& rayDir
)
{
	// ボックスの何らかの面がレイと交差するか調べる
	if( isIntersect( min, max, rayPos, rayDir, -rayPos.y + max.y,  rayDir.y ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.y - min.y, -rayDir.y ) == true ||
		isIntersect( min, max, rayPos, rayDir, -rayPos.x + max.x,  rayDir.x ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.x - min.x, -rayDir.x ) == true ||
		isIntersect( min, max, rayPos, rayDir, -rayPos.z + max.z,  rayDir.z ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.z - min.z, -rayDir.z ) == true
		){
		// 交差していた
		return true;
	}

	// 交差していなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief レイとボックスの何らかの面が交差するかチェックする
 * 
 * @param[in] min ボックスの最小座標.
 * @param[in] max ボックスの最大座標.
 * @param[in] rayPos レイの位置.
 * @param[in] rayDir レイの方向.
 * @param[in] numerator 分子.
 * @param[in] denominator 分母.
 * @retval true 交差する.
 * @retval false 交差しない.
 */
bool Collision::isIntersect
(
	const Vector3&	min,
	const Vector3&	max,
	const Vector3&	rayPos,
	const Vector3&	rayDir,
	float			numerator,
	float			denominator
)
{
	// 線分と面が平行か
	if( denominator == 0.0f ){
		return false;
	}

	// 交点を求める
	Vector3 v;
	v.linearEquation( rayPos, rayDir, numerator / denominator );

	const float MACH_FACTOR = 0.0001f;

	// 交点がボックス内に存在するか
	if( v.x >= ( min.x - MACH_FACTOR ) && v.x <= ( max.x + MACH_FACTOR ) &&
		v.y >= ( min.y - MACH_FACTOR ) && v.y <= ( max.y + MACH_FACTOR ) &&
		v.z >= ( min.z - MACH_FACTOR ) && v.z <= ( max.z + MACH_FACTOR )
		){
		return true;
	}

	// どの面とも交差していなかった
	return false;
}



/*===========================================================================*/
/**
 * @brief 球体がボックス内に存在するかチェックする
 * 
 * @param[in] min ボックスの最小座標.
 * @param[in] max ボックスの最大座標.
 * @param[in] center 球体の中心座標.
 * @param[in] radius 球体の半径.
 * @retval true 存在する.
 * @retval false 存在しない.
 */
bool Collision::sphereIsInsideBox
(
	const Vector3&	min,
	const Vector3&	max,
	const Vector3&	center,
	float			radius
)
{
	float distanceSq = 0.0f;

	// x座標を調べる
	if( center.x > max.x ){
		distanceSq += Ngl::sqr( center.x - max.x );
	}
	else if( center.x < min.x ){
		distanceSq += Ngl::sqr( min.x - center.x );
	}

	// y座標を調べる
	if( center.y > max.y ){
		distanceSq += Ngl::sqr( center.y - max.y );
	}
	else if( center.y < min.y ){
		distanceSq += Ngl::sqr( min.y - center.y );
	}

	// z座標を調べる
	if( center.z > max.z ){
		distanceSq += Ngl::sqr( center.z - max.z );
	}
	else if( center.z < min.z ){
		distanceSq += Ngl::sqr( min.z - center.z );
	}

	// 距離が半径よりも同じか短いか
	if( distanceSq <= Ngl::sqr( radius ) ){
		// ボックスの中に球体が存在する
		return true;
	}
	// ボックスの外に球体が存在する
	return false;
}



/*===========================================================================*/
/**
 * @brief ポリゴンと線分との衝突判定
 * 
 * @param[in] vert 頂点配列へのポインタ.
 * @param[in] numVertices 頂点数.
 * @param[in] planeParam 平面方程式パラメーター.
 * @param[in] line0 線分の始点.
 * @param[in] line1 線分の終点
 * return param 衝突パラメーター
 */
const PlaneCollisionReport& Collision::polygonAndLine
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	line0,
	const Vector3&	line1
)
{
	// 衝突リポートを初期化
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// 平面とラインが衝突していないか
	if( planeParam.intersectLine( line0, line1 ) == false ){
		// パラメーターをそのまま返す
		return planeReport_;
	}

	// 交点座標を求める
	Vector3 tmpIntersect = planeParam.intersectLinePosition( line0, line1, tmpIntersect );

	// 交点がポリゴン内に存在するか
	if( isInsidePolygon( vert, numVertices, tmpIntersect ) == true ){
		// 衝突パラメーターを設定する
		planeReport_.isCollision	= true;
		planeReport_.intersect		= tmpIntersect;
		planeReport_.distanceSq		= tmpIntersect.distance( line0 );
		planeReport_.planeParam		= planeParam;
	}

	// パラメーターを返す
	return planeReport_;
}
	
	
	
/*===========================================================================*/
/**
 * @brief ポリゴンと3D線との衝突判定
 * 
 * @param[in] vert 頂点配列へのポインタ.
 * @param[in] numVertices 頂点数.
 * @param[in] planeParam 平面方程式パラメーター.
 * @param[in] rayPos レイの始点.
 * @param[in] rayDir レイの方向.
 * @return 平面データ衝突パラメーター.
 */
const PlaneCollisionReport& Collision::polygonAndRay
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	rayPos,
	const Vector3&	rayDir
)
{
	// 衝突リポートを初期化
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// 平面とレイが衝突していないか
	if( planeParam.intersectRay( rayPos, rayDir ) == false ){
		// パラメーターをそのまま返す
		return planeReport_;
	}

	// 交点を取得する
	Vector3 tmpIntersect = planeParam.intersectRayPositon( rayPos, rayDir, tmpIntersect );

	// 交点がポリゴン内に存在するか
	if( isInsidePolygon( vert, numVertices, tmpIntersect ) == true ){
		// 衝突パラメーターを設定する
		planeReport_.isCollision	= true;
		planeReport_.intersect		= tmpIntersect;
		planeReport_.distanceSq		= tmpIntersect.distanceSq( tmpIntersect );
		planeReport_.planeParam		= planeParam;
	}
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief ポリゴンと球体との衝突判定
 * 
 * @param[in] vert 頂点配列へのポインタ.
 * @param[in] numVertices 頂点数.
 * @param[in] planeParam 平面方程式パラメーター.
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 平面データ衝突パラメーター.
 */
const PlaneCollisionReport& Collision::polygonAndSphere
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	center,
	float			radius
)
{
	// 衝突リポートを初期化
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// 球体がポリゴン平面と交差するか調べる
	if( planeParam.getClassifySphere( center, radius ) != Plane::INTERSECTS_PLANE ){
		// 交差しない場合は衝突しない
		return planeReport_;
	}

	// ポリゴン平面と球体の中心座標までの相対座標をもとめる
	float disCenter = planeParam.distance( center );

	// オフセットのベクトルを求める
	Vector3 offset;
	offset.x = planeParam.x * disCenter;
	offset.y = planeParam.y * disCenter;
	offset.z = planeParam.z * disCenter;

	// ポリゴン平面上に球体の中心位置を補正する
	Vector3 spherePos = center - offset;

	// ポリゴンの平面状に球体の中心座標が存在するか
	if( isInsidePolygon( vert, numVertices, spherePos ) == true ){
		// 衝突パラメーターを設定する
		planeReport_.isCollision	= true;
		planeReport_.intersect		= spherePos;
		planeReport_.distanceSq		= disCenter;
		planeReport_.planeParam		= planeParam;

		return planeReport_;
	}

	// ポリゴンエッジと球体の衝突判定
	const PlaneCollisionReport& param = polygonEdgeAndSphere( vert, numVertices, center, radius );

	// ポリゴンと球体のエッジが衝突しているか
	if( param.isCollision == true ){
		// パラメーターを返す
		return param;
	}

	// 衝突していなかった
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief ポリゴンのエッジと球体との衝突判定
 * 
 * @param[in] vert 頂点配列へのポインタ.
 * @param[in] numVertices 頂点数.
 * @param[in] center 球体の中心位置.
 * @param[in] radius 球体の半径.
 * @return 平面データ衝突パラメーター.
 */
const PlaneCollisionReport& Collision::polygonEdgeAndSphere
(
	const Vector3*	vert,
	unsigned int	numVertices,
	const Vector3&	center,
	float			radius
)
{
	// 全頂点と判定する
	for( unsigned int i=0; i<numVertices; i++ ){
		// 球体の中心座標とポリゴンを結ぶ線分を求める
		Line3 li( vert[i], vert[ (i+1) % numVertices ] );

		// 線分に最も近い座標を求める
		Vector3 point = li.findNearestPoint( center.x, center.y, center.z );

		// 線分上の座標と球体の中心との距離を求める
		float distanceSq = point.distanceSq( center );

		// 距離が半径よりも短いか
		if( distanceSq < Ngl::sqr( radius ) ){
			planeReport_.isCollision = true;
			planeReport_.distanceSq = distanceSq;
			planeReport_.intersect = point;
			planeReport_.planeParam.createFromPoints( vert[0], vert[1], vert[2] );

			return planeReport_;
		}
	}

	// 衝突していない
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief ポリゴン内部に交点が存在するか
 * 
 * @param[in] vert 頂点配列へのポインタ.
 * @param[in] numVertices 頂点数.
 * @param[out] point 交点座標. 
 * @retval true 存在する.
 * @retval false 存在しない.
 */
bool Collision::isInsidePolygon
(
	const Vector3*	vert,
	unsigned int	numVertices,
	const Vector3&	point
)
{
	// ポリゴンの各頂点と交点を結ぶ線分の角度の合計を求める
	float angle = 0.0f;
	for( unsigned int i=0; i<numVertices; i++ ){
		Vector3 v1 = vert[ i ] - point;
		Vector3 v2 = vert[ (i+1) % numVertices ] - point;

		// 頂点と交点との距離を求める
		float lenV1 = v1.length();
		float lenV2 = v2.length();

		// どちらかの距離が誤差許容範囲未満か
		float much_factor = 0.0001f;
		if( lenV1 < much_factor || lenV2 < much_factor ){
			// 衝突していた
			return true;
		}

		// 二つのベクトルのなす角度を求める
		float cosTheta = v1.dot( v2 ) / ( lenV1 * lenV2 );

		// 角度の合計を求める
		angle += Ngl::acos( Ngl::clamp( cosTheta, -1.0f, 1.0f ) );
	}

	// 合計した角度が360度以上か
	float much_factor = 0.99f;
	if( angle >= ( 360.0f * much_factor ) ){
		// 衝突していた
		return true;
	}
	// 衝突していなかった
	return false;
}



/*===== EOF ==================================================================*/