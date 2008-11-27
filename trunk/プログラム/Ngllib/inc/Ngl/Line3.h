/*******************************************************************************/
/**
 * @file Line3.h.
 * 
 * @brief 3���������\���̃w�b�_�t�@�C��.
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
 * @struct Line3�D
 * @brief 3���������\����.
 */
typedef struct Line3
{
	/** �n�_���W */
	Vector3	begin;

	/** �I�_���W */
	Vector3 end;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Line3();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] Begin �J�n�ʒu3D���W.
	 * @param[in] End �I���ʒu3D���W.
	 */
	Line3( const Vector3& Begin, const Vector3& End );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] Begin �J�n�ʒu���W�z��.
	 * @param[in] End �I���ʒu���W�z��.
	 */
	Line3( const float* Begin, const float* End );
	
	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] x �n�_x���W.
	 * @param[in] y �n�_y���W.
	 * @param[in] z �n�_z���W.
	 * @param[in] eX �I�_x���W.
	 * @param[in] eY �I�_y���W.
	 * @param[in] eZ �I�_z���W.
	 * @return �Ȃ�.
	 */
	void initialize( float x, float y, float z, float eX, float eY, float eZ );

	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] Begin �J�n�ʒu3D���W.
	 * @param[in] End �I���ʒu3D���W.
	 * @return �Ȃ�.
	 */
	void initialize( const Vector3& Begin, const Vector3& End );
	

	/*=========================================================================*/
	/**
	 * @brief �����̃x�N�g�������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �����̃x�N�g��.
	 */
	Vector3 getVector();
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D�����Ƃ̏Փ˔���
	 * 
	 * @param[in] otherBegin ���肷��3D�����̎n�_���W.
	 * @param[in] otherEnd ���肷��3D�����̏I�_���W.
	 * @param[in] epsilon �����臒l.
	 * @return �Փ˔��茋�ʍ\����.
	 */
	const LineCollisionReport& collision( const Vector3& otherBegin, const Vector3& otherEnd, float epsilon ); 
	
	
	/*=========================================================================*/
	/**
	 * @brief 3D�����Ƃ̏Փ˔���
	 * 
	 * @param[in] other ���肷��3D����.
	 * @param[in] epsilon �����臒l.
	 * @return �Փ˔��茋�ʍ\����.
	 */
	const LineCollisionReport& collision( const Line3& other, float epsilon ); 
	
	
	/*=========================================================================*/
	/**
	 * @brief �����ƁA�w����W�̍ł��אڂ��������̍��W�p�����[�^�����߂�
	 * 
	 * @param[in] x, ���߂���W��x���W.
	 * @param[in] y, ���߂���W��y���W.
	 * @param[in] z, ���߂���W��z���W.
	 * @return ���W�p�����[�^.
	 */
	float getNearestPointParameter( float x, float y, float z );


	/*=========================================================================*/
	/**
	 * @brief �����ƁA�w����W�ɍł��אڂ��������̍��W�����߂�
	 * 
	 * @param[in] x, ���߂���W��x���W.
	 * @param[in] y, ���߂���W��y���W.
	 * @param[in] z, ���߂���W��z���W.
	 * @return �ł��אڂ�����W.
	 */
	Vector3 findNearestPoint( float x, float y, float z );

#endif


} NGLline3;

#ifdef __cplusplus
} // namespace Ngl
#endif


#endif

/*===== EOF ==================================================================*/