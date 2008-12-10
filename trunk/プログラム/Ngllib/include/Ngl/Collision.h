/*******************************************************************************/
/**
 * @file Collision.h.
 * 
 * @brief �Փ˔���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLLISION_H_
#define _NGL_COLLISION_H_

#include	"CollisionReport.h"

namespace Ngl{


/**
 * @class Collision�D
 * @brief �Փ˔���N���X.
 */
class Collision
{

public:

	/*=========================================================================*/
	/**
	 * @brief ���̂Ƌ��̂̏Փ˔���
	 * 
	 * @param[in] center1 ����1��3D���_���W.
	 * @param[in] radius1 ����1�̔��a�l.	
	 * @param[in] center2 ����2��3D���_���W.
	 * @param[in] radius2 ����2�̔��a�l.	
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�����.
	 */
	bool sphereAndSphere
	(
		const Ngl::Vector3&	center1, 
		float				radius1, 
		const Ngl::Vector3&	center2, 
		float				radius2
	);


	/*===========================================================================*/
	/**
	 * @brief ���̂��Փ˂��Ȃ����W�֕␳����
	 * 
	 * @param[out] center ���̂�3D���S�ʒu���W.
	 * @param[in] radius ���̂̔��a.
	 * @param[in] intersect 3D��_���W. 
	 * @return �Ȃ�.
	 */
	void Collision::sphereRevisePosition
	( 
		Ngl::Vector3&		center, 
		float				radius,
		const Ngl::Vector3&	intersect
	);


	/*=========================================================================*/
	/**
	 * @brief ���̂�3D���̏Փ˔���
	 * 
	 * @param[in] center ���̂�3D���_���W�z��.
	 * @param[in] radius ���̂̔��a�l.	
	 * @param[in] rayPos ����3D�ʒu���W�z��.
	 * @param[in] rayDir ���̕���3D�x�N�g���z��.	
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�����.
	 */
	bool sphereAndRay
	(
		const Ngl::Vector3&	center, 
		float				radius, 
		const Ngl::Vector3&	rayPos, 
		const Ngl::Vector3&	rayDir
	);


	/*=========================================================================*/
	/**
	 * @brief 3D������3D�����̏Փ˔���
	 * 
	 * @param[in] a1 ���肷�����1�̎n�_3D���W.
	 * @param[in] a2 ���肷�����1�̏I�_3D���W.
	 * @param[in] b1 ���肷�����2�̎n�_3D���W.
	 * @param[in] b2 ���肷�����2�̏I�_3D���W.
	 * @param[in] isRay �����������ǂ���.
	 * @param[in] epsilon 臒l.
	 * @return �Փ˔��茋�ʍ\����.
	 */
	const LineCollisionReport& lineAndLine
	(
		const Ngl::Vector3& a1, 
		const Ngl::Vector3& a2, 
		const Ngl::Vector3& b1, 
		const Ngl::Vector3& b2,
		bool				isRay,
		float				epsilon
	);


	/*=========================================================================*/
	/**
	 * @brief 3D�����ƁA�w����W�̍ł��אڂ��������̍��W�����߂�
	 * 
	 * @param[in] linePos �����̍��W.
	 * @param[in] lineVec �����̕���.
	 * @param[in] point ���ׂ������W.
	 * @param[in] isRay ����������.
	 * @param[out] np ������̗אڂ�����W.
	 * @param[out] parameter �����̕������p�����[�^.
	 * @return �Ȃ�.
	 */
	void findNearestPointOnLineSegment
	(
		const Ngl::Vector3& linePos,
		const Ngl::Vector3& lineVec,
		const Ngl::Vector3& point,
		bool				isRay,
		Ngl::Vector3&		np,
		float&				parameter
	);
	

	/*=========================================================================*/
	/**
	 * @brief 3D�������m���������Ȃ��ꍇ�́A�������m�ōł��߂��_�����߂�
	 * 
	 * @param[in] a1 ���肷�����a�̎n�_3D���W.
	 * @param[in] a2 ���肷�����a�̏I�_3D���W.
	 * @param[in] va ����a�̎n�_����I�_�ւ̃x�N�g��.
	 * @param[in] b1 ���肷�����b�̎n�_3D���W.
	 * @param[in] b2 ���肷�����b�̏I�_3D���W.
	 * @param[in] vb ����b�̎n�_����I�_�ւ̃x�N�g��.
	 * @param[in] isRay �����������ǂ���.
	 * @param[out] pa ����a��́A����b�ɍł��߂�3D���W.
	 * @param[out] pb ����b��́A����a�ɍł��߂�3D���W.
	 * @return �Ȃ�.
	 */
	void findNearestPointOfParallelLineSegments
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
	);

	
	/*=========================================================================*/
	/**
	 * @brief 3D�������m�́A�ł��߂����W�̒���������
	 * 
	 * @param[in] a1 ���肷�����a�̎n�_3D���W.
	 * @param[in] va ����a�̎n�_����I�_�ւ̃x�N�g��.
	 * @param[in] b1 ���肷�����b�̎n�_3D���W.
	 * @param[in] vb ����b�̎n�_����I�_�ւ̃x�N�g��.
	 * @param[in] s ����a�̒����������p�����[�^.
	 * @param[in] t ����b�̒����������p�����[�^.
	 * @param[out] pa ����a��́A����b�ɍł��߂�3D���W.
	 * @param[out] pb ����b��́A����a�ɍł��߂�3D���W.
	 * @return �Ȃ�.
	 */
	void adjustNearestPoint
	(
		const Ngl::Vector3& a1,
		const Ngl::Vector3& va,
		const Ngl::Vector3& b1,
		const Ngl::Vector3& vb,
		float				s,
		float				t,
		Ngl::Vector3&		pa,
		Ngl::Vector3&		pb
	);
	
	
	/*===========================================================================*/
	/**
	 * @brief 3D�������{�b�N�X���ɑ��݂��邩�`�F�b�N����
	 * 
	 * @param[in] min �{�b�N�X�̍ŏ����W.
	 * @param[in] max �{�b�N�X�̍ő���W.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @retval true ���݂���.
	 * @retval false ���݂��Ȃ�.
	 */
	bool lineIsInsideBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& line0,
		const Vector3& line1
	);


	/*===========================================================================*/
	/**
	 * @brief 3D�������{�b�N�X�̊O�ɂ��邩�`�F�b�N����
	 * 
	 * @param[in] min �{�b�N�X�̍ŏ����W.
	 * @param[in] max �{�b�N�X�̍ő���W.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @retval true ���݂���.
	 * @retval false ���݂��Ȃ�.
	 */
	bool lineIsOutsideBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& line0,
		const Vector3& line1
	);

	
	/*===========================================================================*/
	/**
	 * @brief 3D���ƃ{�b�N�X���������邩�`�F�b�N����
	 * 
	 * @param[in] min �{�b�N�X�̍ŏ����W.
	 * @param[in] max �{�b�N�X�̍ő���W.
	 * @param[in] rayPos ���C�̈ʒu.
	 * @param[in] rayDir ���C�̕���.
	 * @retval true ��������.
	 * @retval false �������Ȃ�.
	 */
	bool rayIsIntersectBox
	(
		const Vector3& min,
		const Vector3& max,
		const Vector3& rayPos,
		const Vector3& rayDir
	);


	/*===========================================================================*/
	/**
	 * @brief ���C�ƃ{�b�N�X�̉��炩�̖ʂ��������邩�`�F�b�N����
	 * 
	 * @param[in] min �{�b�N�X�̍ŏ����W.
	 * @param[in] max �{�b�N�X�̍ő���W.
	 * @param[in] rayPos ���C�̈ʒu.
	 * @param[in] rayDir ���C�̕���.
	 * @param[in] numerator ���q.
	 * @param[in] denominator ����.
	 * @retval true ��������.
	 * @retval false �������Ȃ�.
	 */
	bool isIntersect
	(
		const Vector3&	min,
		const Vector3&	max,
		const Vector3&	rayPos,
		const Vector3&	rayDir,
		float			numerator,
		float			denominator
	);


	/*===========================================================================*/
	/**
	 * @brief ���̂��{�b�N�X���ɑ��݂��邩�`�F�b�N����
	 * 
	 * @param[in] min �{�b�N�X�̍ŏ����W.
	 * @param[in] max �{�b�N�X�̍ő���W.
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @retval true ���݂���.
	 * @retval false ���݂��Ȃ�.
	 */
	bool sphereIsInsideBox
	(
		const Vector3&	min,
		const Vector3&	max,
		const Vector3&	center,
		float			radius
	);

	
	/*===========================================================================*/
	/**
	 * @brief �|���S���Ɛ����Ƃ̏Փ˔���
	 * 
	 * @param[in] vert ���_�z��ւ̃|�C���^.
	 * @param[in] numVertices ���_��.
	 * @param[in] planeParam ���ʕ������p�����[�^�[.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_
	 * return param �Փ˃p�����[�^�[
	 */
	const PlaneCollisionReport& polygonAndLine
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	line0,
		const Vector3&	line1
	);


	/*===========================================================================*/
	/**
	 * @brief �|���S����3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] vert ���_�z��ւ̃|�C���^.
	 * @param[in] numVertices ���_��.
	 * @param[in] planeParam ���ʕ������p�����[�^�[.
	 * @param[in] rayPos ���C�̎n�_.
	 * @param[in] rayDir ���C�̕���.
	 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
	 */
	const PlaneCollisionReport& polygonAndRay
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	rayPos,
		const Vector3&	rayDir
	);


	/*===========================================================================*/
	/**
	 * @brief �|���S���Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] vert ���_�z��ւ̃|�C���^.
	 * @param[in] numVertices ���_��.
	 * @param[in] planeParam ���ʕ������p�����[�^�[.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
	 */
	const PlaneCollisionReport& polygonAndSphere
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		Plane&			planeParam,
		const Vector3&	center,
		float			radius
	);


	/*===========================================================================*/
	/**
	 * @brief �|���S���̃G�b�W�Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] vert ���_�z��ւ̃|�C���^.
	 * @param[in] numVertices ���_��.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
	 */
	const PlaneCollisionReport& Collision::polygonEdgeAndSphere
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		const Vector3&	center,
		float			radius
	);


	/*===========================================================================*/
	/**
	 * @brief �|���S�������Ɍ�_�����݂��邩
	 * 
	 * @param[in] vert ���_�z��ւ̃|�C���^.
	 * @param[in] numVertices ���_��.
	 * @param[out] point ��_���W. 
	 * @retval true ���݂���.
	 * @retval false ���݂��Ȃ�.
	 */
	bool isInsidePolygon
	(
		const Vector3*	vert,
		unsigned int	numVertices,
		const Vector3&	point
	);

private:

	/** �Փ˔��茋�ʍ\���� */
	CollisionReport			report_;

	/** 3D�����Փ˔��茋�ʍ\���� */
	LineCollisionReport		lineReport_;

	/** �ʃf�[�^�Փ˔���\���� */
	PlaneCollisionReport	planeReport_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/