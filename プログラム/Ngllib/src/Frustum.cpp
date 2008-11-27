/*******************************************************************************/
/**
 * @file Frustum.cpp.
 * 
 * @brief 視錐台クラスソースファイル.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Frustum.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief 視野変換行列、透視変換行列から視錐台を作成する
 * 
 * @param[in] view 視野変換行列.
 * @param[in] proj 透視変換行列.
 * @return なし.
 */
void Frustum::createFromMatrices(const Matrix4 &view, const Matrix4 &proj)
{
	// 視野変換行列と透視変換行列を乗算する
	Matrix4 clip = view * proj;

	// クリッピングプレーンを計算する
	mPlanes[CLIP_PLANE_RIGHT].x = clip.m[0][3] - clip.m[0][0];
	mPlanes[CLIP_PLANE_RIGHT].y = clip.m[1][3] - clip.m[1][0];
	mPlanes[CLIP_PLANE_RIGHT].z = clip.m[2][3] - clip.m[2][0];
	mPlanes[CLIP_PLANE_RIGHT].d = clip.m[3][3] - clip.m[3][0];

	mPlanes[CLIP_PLANE_LEFT].x = clip.m[0][3] + clip.m[0][0];
	mPlanes[CLIP_PLANE_LEFT].y = clip.m[1][3] + clip.m[1][0];
	mPlanes[CLIP_PLANE_LEFT].z = clip.m[2][3] + clip.m[2][0];
	mPlanes[CLIP_PLANE_LEFT].d = clip.m[3][3] + clip.m[3][0];

	mPlanes[CLIP_PLANE_BOTTOM].x = clip.m[0][3] + clip.m[0][1];
	mPlanes[CLIP_PLANE_BOTTOM].y = clip.m[1][3] + clip.m[1][1];
	mPlanes[CLIP_PLANE_BOTTOM].z = clip.m[2][3] + clip.m[2][1];
	mPlanes[CLIP_PLANE_BOTTOM].d = clip.m[3][3] + clip.m[3][1];

	mPlanes[CLIP_PLANE_TOP].x = clip.m[0][3] - clip.m[0][1];
	mPlanes[CLIP_PLANE_TOP].y = clip.m[1][3] - clip.m[1][1];
	mPlanes[CLIP_PLANE_TOP].z = clip.m[2][3] - clip.m[2][1];
	mPlanes[CLIP_PLANE_TOP].d = clip.m[3][3] - clip.m[3][1];

	mPlanes[CLIP_PLANE_FAR].x = clip.m[0][3] - clip.m[0][2];
	mPlanes[CLIP_PLANE_FAR].y = clip.m[1][3] - clip.m[1][2];
	mPlanes[CLIP_PLANE_FAR].z = clip.m[2][3] - clip.m[2][2];
	mPlanes[CLIP_PLANE_FAR].d = clip.m[3][3] - clip.m[3][2];

	mPlanes[CLIP_PLANE_NEAR].x = clip.m[0][3] + clip.m[0][2];
	mPlanes[CLIP_PLANE_NEAR].y = clip.m[1][3] + clip.m[1][2];
	mPlanes[CLIP_PLANE_NEAR].z = clip.m[2][3] + clip.m[2][2];
	mPlanes[CLIP_PLANE_NEAR].d = clip.m[3][3] + clip.m[3][2];

	// クリッピングプレーンを正規化する
	for( int i=0; i<6; i++ ){
		mPlanes[i].normalize();
	}
}



/*===========================================================================*/
/**
 * @brief 点が視錐台内に存在するか調べる
 * 
 * @param[in] point 調べる点.
 * @retval true 存在している.
 * @retval false 存在していない.
 */
bool Frustum::isPointInside(const Vector3 &point)
{
	for( int i=0; i<6; i++ ){
		// クリッピングプレーンの背面に座標が存在するか
		if( mPlanes[i].getClassifyPoint( point ) == Plane::BEHIND_PLANE ){
			// 視錐台の外に座標が存在する
			return false;
		}
	}
	// 視錐台の内側に存在する
	return true;
}



/*===========================================================================*/
/**
 * @brief ボックスが視錐台内にあるか調べる
 * 
 * @param[in] p1 ボックスの座標1.
 * @param[in] p2 ボックスの座標2.
 * @return true 存在している, false 存在していない.
 */
bool Frustum::isBoxInside(const Vector3 &p1, const Vector3 &p2)
{
	// ボックスの各頂点を求める
	Vector3 vertices[8] = {
		Vector3( p1.x, p1.y, p1.z ),
		Vector3( p2.x, p1.y, p1.z ),
		Vector3( p1.x, p2.y, p1.z ),
		Vector3( p2.x, p2.y, p1.z ),
		Vector3( p1.x, p1.y, p2.z ),
		Vector3( p2.x, p1.y, p2.z ),
		Vector3( p1.x, p2.y, p2.z ),
		Vector3( p2.x, p2.y, p2.z )
	};

	for( int i=0; i<6; i++ ){
		// ボックスの全頂点がクリッププレーンの外側に存在するか
		if( mPlanes[i].getClassifyPoint( vertices[0] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[1] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[2] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[3] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[4] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[5] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[6] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[7] ) != Plane::BEHIND_PLANE ) continue;
		// 外側に存在している
		return false;
	}

	// 視錐台の内側にボックスが存在してる
	return true;
}



/*===========================================================================*/
/**
 * @brief 球体が視錐台内にあるか調べる
 * 
 * @param[in] center 球体の中心座標.
 * @param[in] radius 球体の半径.
 * @retval true 存在している.
 * @retval false 存在していない.
 */
bool Frustum::isSphereInside(const Vector3 &center, float radius)
{
	for( int i=0; i<6; i++ ){
		// クリッピングプレーンの背後に球体が存在するかs
		if( mPlanes[i].getClassifySphere( center, radius ) == Plane::BEHIND_PLANE ){
			// 外側に存在している
			return false;
		}
	}
	// 視錐台の内側に存在している
	return true;
}



/*========= EOF =============================================================*/