/*******************************************************************************/
/**
 * @file Plane.h.
 * 
 * @brief ���ʍ\���̃w�b�_�t�@�C��.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_PLANE_H_
#define _NGL_PLANE_H_

#include	"Vector3.h"

namespace Ngl{


/**
 * @struct Plane.
 * @brief ���ʍ\���́D
 */
struct Plane
{
	/** �ʖ@��x���� */
	float x;

	/** �ʖ@��y���� */
	float y;

	/** �ʖ@��z���� */
	float z;

	/** ���_����̋��� */
	float d;

	/**
	 * @enum PlanePositionFlags.
	 * @brief �ʒu�֌W�񋓌^.
	 */
	enum PlanePositionFlags
	{
		FRONT_PLANE = 0,	/**< ���ʂ̑O	*/
		BEHIND_PLANE,		/**< ���ʂ̌��	*/
		ON_PLANE,			/**< ���ʏ�		*/
		INTERSECTS_PLANE	/**< ���ʂƌ���	*/
	};
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Plane();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �z��̐擪�|�C���^.
	 */
	Plane ( float* other );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] X �ʖ@��x����.
	 * @param[in] Y �ʖ@��y����.
	 * @param[in] Z �ʖ@��z����.
	 * @param[in] D ���_����̋���.
	 */
	Plane( float X, float Y, float Z, float D );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] N �@���x�N�g��.
	 * @param[in] D ���_����̋���.
	 */
	Plane( const Ngl::Vector3& N, float D );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] P ���ʏ�̍��W.
	 * @param[in] N �@���x�N�g��.
	 */
	Plane( const Ngl::Vector3& P, const Ngl::Vector3 N );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] v1 ���W1.
	 * @param[in] v2 ���W2.
	 * @param[in] v3 ���W3.
	 */
	Plane( const Ngl::Vector3& v1, const Ngl::Vector3& v2, const Ngl::Vector3& v3 );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���ʂ𐳋K������
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���K����������.
	 */
	Plane& normalize();


	/*=========================================================================*/
	/**
	 * @brief ���ʏ�̈ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ʒu���W.
	 */
	Ngl::Vector3 getPoint() const;


	/*=========================================================================*/
	/**
	 * @brief ���ʂƃx�N�g���̓��ς����߂�
	 * 
	 * @param[in] v ���ς����߂�x�N�g�� .
	 * @return ����.
	 */
	float dot( const Ngl::Vector3& v ) const;

	
	/*=========================================================================*/
	/**
	 * @brief ���ʂƍ��W�Ƃ̋��������߂�
	 * 
	 * @param[in] v ���������߂�x�N�g�� .
	 * @return ����.
	 */
	float distance( const Ngl::Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief ���ʂƍ��W�̈ʒu�֌W��Ԃ�
	 * 
	 * @param[in] pos ���ׂ���W.
	 * @return �ʒu�֌W.
	 */
	PlanePositionFlags getClassifyPoint( const Ngl::Vector3& pos );


	/*=========================================================================*/
	/**
	 * @brief ���ʂƋ��̂̈ʒu�֌W��Ԃ�
	 * 
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʒu�֌W.
	 */
	PlanePositionFlags getClassifySphere( const Ngl::Vector3& center, float radius );

	
	/*=========================================================================*/
	/**
	 * @brief ���ʂƐ������������邩���ׂ�
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return true �������Ă���, false �������Ă��Ȃ�.
	 */
	bool intersectLine( const Ngl::Vector3& line0, const Ngl::Vector3& line1 );


	/*=========================================================================*/
	/**
	 * @brief ���ʂƐ���������������W�����߂�
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @param[in] retVec �������Ă��Ȃ��������ɖ߂�x�N�g��.
	 * @return ��_���W.
	 */
	Ngl::Vector3 intersectLinePosition
	(
		const Ngl::Vector3& line0,
		const Ngl::Vector3& line1,
		const Ngl::Vector3& retVec
	);
	
	
	/*=========================================================================*/
	/**
	 * @brief ���ʂƃ��C���������邩���ׂ�
	 * 
	 * @param[in] rayPos ���C�̎n�_.
	 * @param[in] rayDir ���C�̕���.
	 * @return true �������Ă���, false �������Ă��Ȃ�.
	 */
	bool intersectRay( const Ngl::Vector3& rayPos, const Ngl::Vector3& rayDir );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���ʂƃ��C�̌�_���W�����߂�
	 * 
	 * @param[in] rayPos ���C�̎n�_.
	 * @param[in] rayDir ���C�̕���.
	 * @param[in] retVec �������Ă��Ȃ��������ɖ߂�x�N�g��.
	 * @return ��_���W.
	 */
	Ngl::Vector3 intersectRayPositon
	(
		const Ngl::Vector3& rayPos,
		const Ngl::Vector3& rayDir,
		const Ngl::Vector3& retVec
	);
	
	
	/*=========================================================================*/
	/**
	 * @brief ���ʏ�̍��W�ƕ��ʂ̖@���x�N�g�����畽�ʂ��쐬����
	 * 
	 * @param[in] point ���ʏ�̍��W.
	 * @param[in] normal ���ʂ̖@���x�N�g��.
	 * @return �쐬��������.
	 */
	Plane& createFromPointNormal( const Ngl::Vector3& point, const Ngl::Vector3& normal );


	/*=========================================================================*/
	/**
	 * @brief ���ʏ��3�̍��W���畽�ʂ��쐬����
	 * 
	 * @param[in] v1 ���W1.
	 * @param[in] v2 ���W2.
	 * @param[in] v3 ���W3.
	 * @return �쐬��������.
	 */
	Plane& createFromPoints( const Ngl::Vector3& v1, const Ngl::Vector3& v2, const Ngl::Vector3& v3 );


	/*=========================================================================*/
	/**
	 * @brief == ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] other ���Z���镽��.
	 * @retval true ��v���Ă���.
	 * @retval false ��v���Ă��Ȃ�.
	 */
	bool operator == ( const Ngl::Plane& other );

	
	/*=========================================================================*/
	/**
	 * @brief != ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] other ���Z���镽��.
	 * @retval true ��v���Ă��Ȃ�.
	 * @retval false ��v���Ă���.
	 */
	bool operator != ( const Ngl::Plane& other );

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/