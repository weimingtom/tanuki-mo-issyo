/*******************************************************************************/
/**
 * @file Frustum.cpp.
 * 
 * @brief ������N���X�\�[�X�t�@�C��.
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
 * @brief ����ϊ��s��A�����ϊ��s�񂩂王������쐬����
 * 
 * @param[in] view ����ϊ��s��.
 * @param[in] proj �����ϊ��s��.
 * @return �Ȃ�.
 */
void Frustum::createFromMatrices(const Matrix4 &view, const Matrix4 &proj)
{
	// ����ϊ��s��Ɠ����ϊ��s�����Z����
	Matrix4 clip = view * proj;

	// �N���b�s���O�v���[�����v�Z����
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

	// �N���b�s���O�v���[���𐳋K������
	for( int i=0; i<6; i++ ){
		mPlanes[i].normalize();
	}
}



/*===========================================================================*/
/**
 * @brief �_����������ɑ��݂��邩���ׂ�
 * 
 * @param[in] point ���ׂ�_.
 * @retval true ���݂��Ă���.
 * @retval false ���݂��Ă��Ȃ�.
 */
bool Frustum::isPointInside(const Vector3 &point)
{
	for( int i=0; i<6; i++ ){
		// �N���b�s���O�v���[���̔w�ʂɍ��W�����݂��邩
		if( mPlanes[i].getClassifyPoint( point ) == Plane::BEHIND_PLANE ){
			// ������̊O�ɍ��W�����݂���
			return false;
		}
	}
	// ������̓����ɑ��݂���
	return true;
}



/*===========================================================================*/
/**
 * @brief �{�b�N�X����������ɂ��邩���ׂ�
 * 
 * @param[in] p1 �{�b�N�X�̍��W1.
 * @param[in] p2 �{�b�N�X�̍��W2.
 * @return true ���݂��Ă���, false ���݂��Ă��Ȃ�.
 */
bool Frustum::isBoxInside(const Vector3 &p1, const Vector3 &p2)
{
	// �{�b�N�X�̊e���_�����߂�
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
		// �{�b�N�X�̑S���_���N���b�v�v���[���̊O���ɑ��݂��邩
		if( mPlanes[i].getClassifyPoint( vertices[0] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[1] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[2] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[3] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[4] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[5] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[6] ) != Plane::BEHIND_PLANE ) continue;
		if( mPlanes[i].getClassifyPoint( vertices[7] ) != Plane::BEHIND_PLANE ) continue;
		// �O���ɑ��݂��Ă���
		return false;
	}

	// ������̓����Ƀ{�b�N�X�����݂��Ă�
	return true;
}



/*===========================================================================*/
/**
 * @brief ���̂���������ɂ��邩���ׂ�
 * 
 * @param[in] center ���̂̒��S���W.
 * @param[in] radius ���̂̔��a.
 * @retval true ���݂��Ă���.
 * @retval false ���݂��Ă��Ȃ�.
 */
bool Frustum::isSphereInside(const Vector3 &center, float radius)
{
	for( int i=0; i<6; i++ ){
		// �N���b�s���O�v���[���̔w��ɋ��̂����݂��邩s
		if( mPlanes[i].getClassifySphere( center, radius ) == Plane::BEHIND_PLANE ){
			// �O���ɑ��݂��Ă���
			return false;
		}
	}
	// ������̓����ɑ��݂��Ă���
	return true;
}



/*========= EOF =============================================================*/