/*******************************************************************************/
/**
 * @file Ray.h.
 * 
 * @brief 3�������������\���̃w�b�_�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RAY_H_
#define _NGL_RAY_H_

#include	"Vector3.h"

#ifdef __cplusplus
#include "CollisionReport.h"

namespace Ngl{


// ���̍\����
struct Sphere;
#endif


/**
 * @struct Ray�D
 * @brief 3�������������\����.
 */
typedef struct Ray
{
	/** �n�_���W */
	Vector3	position;

	/** ���� */
	Vector3	direction;
	

#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Ray();

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] pos �n�_���W.
	 * @param[in] dir �����x�N�g��.
	 */
	Ray( const Vector3& pos, const Vector3& dir );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] pos �n�_���W�z��.
	 * @param[in] dir �����x�N�g���z��.
	 */
	Ray( const float* pos, const float* dir );
	
	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] x �n�_x���W.
	 * @param[in] y �n�_y���W.
	 * @param[in] z �n�_z���W.
	 * @param[in] DirX �����x�N�g��x���W.
	 * @param[in] DirY �����x�N�g��y���W.
	 * @param[in] DirZ �����x�N�g��z���W.
	 * @return �Ȃ�.
	 */
	void initialize( float x, float y, float z, float DirX, float DirY, float DirZ );


	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] pos �n�_���W.
	 * @param[in] dir �����x�N�g��.
	 * @return �Ȃ�.
	 */
	void initialize( const Vector3& pos, const Vector3& dir );

	
	/*=========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���肷�鋅�̂̒��S���W.
	 * @param[in] radius ���肷�鋅�̂̔��a.
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�.
	 */
	bool collision( const Vector3& center, float radius );
		
		
	/*=========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] sphere ���肷�鋅��.
	 * @retval true �Փ˂��Ă���.
	 * @retval false �Փ˂��Ă��Ȃ�.
	 */
	bool collision( const Sphere& sphere );
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] pos ���肷��3D���̈ʒu.
	 * @param[in] dir ���肷��.
	 * @param[in] epsilon 臒l.
	 * @return �Փ˔��茋�ʍ\����.
	 */
	const LineCollisionReport& collision( const Vector3& pos, const Vector3& dir, float epsilon );
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] other ���肷��3D��.
	 * @param[in] epsilon 臒l.
	 * @return �Փ˔��茋�ʍ\����.
	 */
	const LineCollisionReport& collision( const Ray& other, float epsilon );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���������Ǝw����W�̂����Ƃ��߂����������̍��W�����߂�
	 * 
	 * @param[in] x ���߂����ʒu��x���W.
	 * @param[in] y ���߂����ʒu��y���W.
	 * @param[in] z ���߂����ʒu��z���W.
	 * @return �ł��߂����W.
	 */
	Vector3 findNearestPosition( float x, float y, float z );

#endif


} NGLray;


#ifdef __cplusplus
} // namespace Ngl
#endif


#endif

/*===== EOF ==================================================================*/