/*******************************************************************************/
/**
 * @file Quaternion.h.
 * 
 * @brief �N�H�[�^�j�I���\���̃w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_QUATERNION_H_
#define _NGL_QUATERNION_H_

#include	<Ngl/Vector3.h>
#include	<Ngl/Matrix4.h>

namespace Ngl{

/**
 * @struct Quaternion
 * @brief �N�H�[�^�j�I���\���́D
 */
struct Quaternion
{
	/** x���� */
	float x;

	/** y���� */
	float y;

	/** z���� */
	float z;

	/** ��]�p�x */
	float w;

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Quaternion();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] X x����.
	 * @param[in] Y y����.
	 * @param[in] Z z����.
	 * @param[in] W w����.
	 */
	Quaternion( float X, float Y, float Z, float W );

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] aNgle ��]�p�x.
	 * @param[in] axis ��.
	 */
	Quaternion( float aNgle, const Vector3& axis );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] m ��]�s��.
	 */
	Quaternion( const Matrix4& m );
	

	/*=========================================================================*/
	/**
	 * @brief �P�ʃN�H�[�^�j�I��������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �P�ʃN�H�[�^�j�I���������N�H�[�^�j�I��.
	 */
	Quaternion& setIdentity();


	/*=========================================================================*/
	/**
	 * @brief ���K��������
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���K�������N�H�[�^�j�I��.
	 */
	Quaternion& normalize();


	/*=========================================================================*/
	/**
	 * @brief ���ς����߂�
	 * 
	 * @param[in] q ���ς����߂�N�H�[�^�j�I��.
	 * @return ���ς̒l.
	 */
	float dot( const Ngl::Quaternion& q ) const;


	/*=========================================================================*/
	/**
	 * @brief ���������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �����̒l.
	 */
	float length() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �t�N�H�[�^�j�I��������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t�N�H�[�^�j�I���������N�H�[�^�j�I��.
	 */
	Quaternion& inverse();


	/*=========================================================================*/
	/**
	 * @brief ��]�p�x����N�H�[�^�j�I�����擾����
	 * 
	 * @param[in] aNgle ��]�p�x.
	 * @param[in] vx x����.
	 * @param[in] vy y����.
	 * @param[in] vz z����.
	 * @return �擾�����N�H�[�^�j�I��.
	 */
	Quaternion& fromRotate( float aNgle, float vx, float vy, float vz );


	/*=========================================================================*/
	/**
	 * @brief ��]�p�x����N�H�[�^�j�I�����擾����
	 * 
	 * @param[in] aNgle ��]�p�x.
	 * @param[in] axis ��.
	 * @return �擾�����N�H�[�^�j�I��.
	 */
	Quaternion& fromRotate( float aNgle, const Vector3& axis );

	
	/*=========================================================================*/
	/**
	 * @brief ���[�E�s�b�`�E���[������N�H�[�^�j�I�����擾����
	 * 
	 * @param[in] yaw ���[�p.
	 * @param[in] pitch �s�b�`�p.
	 * @param[in] roll ���[���p.
	 * @return �擾�����N�H�[�^�j�I��.
	 */
	Quaternion& fromYawPitchRoll( float yaw, float pitch, float roll );


	/*=========================================================================*/
	/**
	 * @brief ��]�s���ݒ肷��
	 * 
	 * @param[in] mat ��]�s��.
	 * @return �ݒ肵���N�H�[�^�j�I��.
	 */
	Quaternion& setMatrix( const Matrix4& mat );


	/*=========================================================================*/
	/**
	 * @brief �����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���̒l.
	 */
	Vector3 getAxis() const;


	/*=========================================================================*/
	/**
	 * @brief �p�x���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�x�̒l.
	 */
	float getANgle() const;


	/*=========================================================================*/
	/**
	 * @brief ���[�p���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�p�̒l.
	 */
	float getYaw() const;


	/*=========================================================================*/
	/**
	 * @brief �s�b�`�p���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �s�b�`�p�̒l.
	 */
	float getPitch() const;


	/*=========================================================================*/
	/**
	 * @brief ���[���p���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[���p�̒l.
	 */
	float getRoll() const;
	

	/*=========================================================================*/
	/**
	 * @brief ���`��Ԃ���
	 * 
	 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I���P.
	 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I���Q.
	 * @param[in] t ��Ԓl.
	 * @return �Ȃ�.
	 */
	Quaternion& lerp( const Quaternion& q1, const Quaternion& q2, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���`���`��Ԃ���
	 * 
	 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I���P.
	 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I���Q.
	 * @param[in] t ��Ԓl.
	 * @return �Ȃ�.
	 */
	Quaternion& slerp( const Quaternion& q1, const Quaternion& q2, float t );
	

	/*=========================================================================*/
	/**
	 * @brief 2����Ԃ���
	 * 
	 * @param[in] q1 ��ԗv�f�̃N�H�[�^�j�I��1.
	 * @param[in] q2 ��ԗv�f�̃N�H�[�^�j�I��2.
	 * @param[in] q3 ��ԗv�f�̃N�H�[�^�j�I��3.
	 * @param[in] t �⊮�x.
	 * @return �⊮�����N�H�[�^�j�I��.
	 */
	Quaternion& quadratic( const Quaternion& q1, const Quaternion& q2, const Quaternion& q3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief + ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion operator + () const;


	/*=========================================================================*/
	/**
	 * @brief - ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion operator - () const;

	
	/*=========================================================================*/
	/**
	 * @brief += ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] q ���Z����N�H�[�^�j�I��.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion& operator += ( const Quaternion& q );
	
	
	/*=========================================================================*/
	/**
	 * @brief -= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] q ���Z����N�H�[�^�j�I��.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion& operator -= ( const Quaternion& q );


	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] q ���Z����N�H�[�^�j�I��.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion& operator *= ( const Quaternion& q );


	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����X�J���[.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion& operator *= ( float s );


	/*=========================================================================*/
	/**
	 * @brief /= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����X�J���[.
	 * @return ���Z���ʂ̃N�H�[�^�j�I��.
	 */
	Quaternion& operator /= ( float s );

};

}	// namespace Ngl

/*=========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Ngl::Quaternion operator + ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Ngl::Quaternion operator - ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Ngl::Quaternion operator * ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Ngl::Quaternion operator * ( const Ngl::Quaternion& q, float s );


/*=========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] q ���Z����N�H�[�^�j�I��.
 * @return ���Z���ʂ̃N�H�[�^�j�I��.
 */
Ngl::Quaternion operator * ( float s, const Ngl::Quaternion& q );


/*=========================================================================*/
/**
 * @brief == ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return true ��v���Ă��� false ��v���Ă��Ȃ�.
 */
bool operator == ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


/*=========================================================================*/
/**
 * @brief != ���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] q1 ���Z����N�H�[�^�j�I��1.
 * @param[in] q2 ���Z����N�H�[�^�j�I��2.
 * @return true ��v���Ă��Ȃ� false ��v���Ă���.
 */
bool operator != ( const Ngl::Quaternion& q1, const Ngl::Quaternion& q2 );


#endif

/*===== EOF ==================================================================*/