/*******************************************************************************/
/**
 * @file Matrix4.h.
 * 
 * @brief 4x4�s��\���̃w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATRIX4_H_
#define _NGL_MATRIX4_H_

#include	"Vector3.h"


#ifdef __cplusplus
namespace Ngl{


// �N�H�[�^�j�I���\����
struct Quaternion;
#endif


/**
 * @struct Matrix4
 * @brief 4x4�s��\���́D
 */
typedef struct Matrix4
{
	/** �s�񐬕� */
	float m[4][4];


#ifdef __cplusplus

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Matrix4();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] m11�`m44 �s�񐬕�.
	 */
	Matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44
			);

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �������s��l.
	 */
	Matrix4( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief �P�ʍs��̐ݒ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	Matrix4& setIdentitiy();

	
	/*=========================================================================*/
	/**
	 * @brief �]�u�s������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���߂��]�u�s��.
	 */
	Matrix4& transpose();


	/*=========================================================================*/
	/**
	 * @brief �t�s����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���߂��t�s��.
	 */
	Matrix4 getInverse() const;

	
	/*=========================================================================*/
	/**
	 * @brief �t�s������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���߂��t�s��.
	 */
	Matrix4& inverse();
	
	
	/*=========================================================================*/
	/**
	 * @brief �g��k���s��̐ݒ�(�E����W�n)
	 * 
	 * @param[in] x x�����̊g��䗦.
	 * @param[in] y y�����̊g��䗦.
	 * @param[in] z z�����̊g��䗦.
	 * @return �ݒ肵���s��.
	 */
	Matrix4& setScale( float x, float y, float z );
	
	
	/*=========================================================================*/
	/**
	 * @brief �g��k���s��̐ݒ�(�E����W�n)
	 * 
	 * @param[in] v �g��k�����x�N�g��.
	 * @return �ݒ肵���s��.
	 */
	Matrix4& setScale( const Vector3& v);

	
	/*=========================================================================*/
	/**
	 * @brief x������̉�]�s���ݒ�(�E����W�n)
	 * 
	 * @param[in] aNgle �p�x.
	 * @return �ݒ肵����]�s��.
	 */
	Matrix4& setRotateX( float aNgle );


	/*=========================================================================*/
	/**
	 * @brief y������̉�]�s���ݒ�(�E����W�n)
	 * 
	 * @param[in] aNgle �p�x.
	 * @return �ݒ肵����]�s��.
	 */
	Matrix4& setRotateY( float aNgle );


	/*=========================================================================*/
	/**
	 * @brief z������̉�]�s���ݒ�(�E����W�n)
	 * 
	 * @param[in] aNgle �p�x.
	 * @return �ݒ肵����]�s��.
	 */
	Matrix4& setRotateZ( float aNgle ); // z������̉�]

	
	/*=========================================================================*/
	/**
	 * @brief ���[�E�s�b�`�E���[�������]�s������߂�(�E����W�n)
	 * 
	 * @param[in] yaw ���[.
	 * @param[in] pitch �s�b�`.
	 * @param[in] role ���[��.
	 * @return �ݒ肵�����W.
	 */
	Matrix4& setRotateFromYawPitchRole( float yaw, float pitch, float role );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��s���ݒ�
	 * 
	 * @param[in] x x�����̈ړ���.
	 * @param[in] y y�����̈ړ���.
	 * @param[in] z z�����̈ړ���.
	 * @return �ݒ肵�����s�ړ��s��.
	 */
	Matrix4& setTranslate( float x, float y, float z );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��s���ݒ�
	 * 
	 * @param[in] v ���s�ړ�����.
	 * @return �ݒ肵�����s�ړ��s��.
	 */
	Matrix4& setTranslate( const Vector3& v );

	
	/*=========================================================================*/
	/**
	 * @brief �����ϊ��s��̐ݒ�(�E����W�n)
	 * 
	 * @param[in] fov ����p.
	 * @param[in] aspect �A�X�y�N�g��.
	 * @param[in] zNear �߃N���b�v��.
	 * @param[in] zFar ���N���b�v��.
	 * @return �ݒ肵�������ϊ��s��.
	 */
	Matrix4& setPerspectiveRH( float fov, float aspect, float zNear, float zFar );

	
	/*=========================================================================*/
	/**
	 * @brief �����ϊ��s��̐ݒ�(������W�n)
	 * 
	 * @param[in] fov ����p.
	 * @param[in] aspect �A�X�y�N�g��.
	 * @param[in] zNear �߃N���b�v��.
	 * @param[in] zFar ���N���b�v��.
	 * @return �ݒ肵�������ϊ��s��.
	 */
	Matrix4& setPerspectiveLH( float fov, float aspect, float zNear, float zFar );
	
	
	/*=========================================================================*/
	/**
	 * @brief ����ϊ��s���ݒ�(�E����W�n)
	 * 
	 * @param[in] eye ���_�̈ʒu.
	 * @param[in] at �����_.
	 * @param[in] up ������̃x�N�g��.
	 * @return �ݒ肵������ϊ��s��.
	 */
	Matrix4& setLookAtRH( const Vector3& eye, const Vector3& at, const Vector3& up );


	/*=========================================================================*/
	/**
	 * @brief ����ϊ��s���ݒ�(������W�n)
	 * 
	 * @param[in] eye ���_�̈ʒu.
	 * @param[in] at �����_.
	 * @param[in] up ������̃x�N�g��.
	 * @return �ݒ肵������ϊ��s��.
	 */
	Matrix4& setLookAtLH(const Vector3& eye, const Vector3& at, const Vector3& up);


	/*=========================================================================*/
	/**
	 * @brief ���ˉe�ϊ��s���ݒ�(�E����W�n)
	 * 
	 * @param[in] left �N���b�v�ʂ̍����̍��W.
	 * @param[in] right �N���b�v�ʂ̉E���̍��W.
	 * @param[in] bottom �N���b�v�ʂ̉����̍��W.
	 * @param[in] top �N���b�v�ʂ̏㑤�̍��W.
	 * @param[in] zNear �߃N���b�v�ʂ̍��W.
	 * @param[in] zFar ���N���b�v�ʂ̍��W.
	 * @return �ݒ肵���ϊ��s��.
	 */
	Matrix4& setOrthoRH( float left, float right, float top, float bottom, float zNear, float zFar );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���ˉe�ϊ��s���ݒ�(������W�n)
	 * 
	 * @param[in] left �N���b�v�ʂ̍����̍��W.
	 * @param[in] right �N���b�v�ʂ̉E���̍��W.
	 * @param[in] bottom �N���b�v�ʂ̉����̍��W.
	 * @param[in] top �N���b�v�ʂ̏㑤�̍��W.
	 * @param[in] zNear �߃N���b�v�ʂ̍��W.
	 * @param[in] zFar ���N���b�v�ʂ̍��W.
	 * @return �ݒ肵���ϊ��s��.
	 */
	Matrix4& setOrthoLH( float left, float right, float top, float bottom, float zNear, float zFar );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ�
	 *
	 * �x�N�g���ƍs��s��̊|���Z������.
	 * 
	 * @param[in] v ��Z����3�����x�N�g��.
	 * @return ���Z���ʂ�3�����x�N�g��.
	 */
	Vector3 transform( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ�.
	 *
	 * �x�N�g���ƍs��s��̊|���Z������ ���̌��ʂ� w = 1 �Ɏˉe����.
	 * 
	 * @param[in] v ��Z����3�����x�N�g��.
	 * @return ���Z���ʂ�3�����x�N�g��.
	 */
	Vector3 transformCoord( const Vector3& v ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ�
	 *
	 * �@���x�N�g���p�ŉ�]�݂̂ŕ��s�ړ��͂����Ȃ�.
	 * 
	 * @param[in] v ��Z����3�����x�N�g��.
	 * @return ���Z���ʂ�3�����x�N�g��.
	 */
	Vector3 transformNormal( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief ���[���p�����߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[���p.
	 */
	float getRole() const;


	/*=========================================================================*/
	/**
	 * @brief �s�b�`�p�����߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �s�b�`�p.
	 */
	float getPitch() const;


	/*=========================================================================*/
	/**
	 * @brief ���[�p�����߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���[�p.
	 */
	float getYaw() const;


	/*=========================================================================*/
	/**
	 * @brief x���ʒu��ݒ肷��
	 * 
	 * @param[in] axisX �����̈ʒu���W.
	 * @return �Ȃ�.
	 */
	Matrix4& setAxisX( const Vector3& axisX );


	/*=========================================================================*/
	/**
	 * @brief y���ʒu��ݒ肷��
	 * 
	 * @param[in] axisY y���̈ʒu���W.
	 * @return �Ȃ�.
	 */
	Matrix4& setAxisY( const Vector3& axisY );


	/*=========================================================================*/
	/**
	 * @brief z���ʒu��ݒ肷��
	 * 
	 * @param[in] axisZ z���̈ʒu���W.
	 * @return �Ȃ�.
	 */
	Matrix4& setAxisZ( const Vector3& axisZ );


	/*=========================================================================*/
	/**
	 * @brief �ʒu���W��ݒ肷��
	 * 
	 * @param[in] position �ʒu���W.
	 * @return �Ȃ�.
	 */
	Matrix4& setPosition( const Vector3& position );
	
	
	/*=========================================================================*/
	/**
	 * @brief x���ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �����̈ʒu���W.
	 */
	Vector3 getAxisX() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief y���ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return y���̈ʒu���W.
	 */
	Vector3 getAxisY() const;

	
	/*=========================================================================*/
	/**
	 * @brief z���ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return z���̈ʒu���W.
	 */
	Vector3 getAxisZ() const;

	
	/*=========================================================================*/
	/**
	 * @brief �ʒu���W���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ʒu���W.
	 */
	Vector3 getPosition() const;

	
	/*=========================================================================*/
	/**
	 * @brief �N�H�[�^�j�I������s������߂�
	 * 
	 * @param[in] q �N�H�[�^�j�I��.
	 * @return �s��.
	 */
	Matrix4& fromQuaternion( const Quaternion& q );
	
	
	/*=========================================================================*/
	/**
	 * @brief +���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z���ʂ�Matrix4.
	 */
	Matrix4 operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z���ʂ�Matrix4.
	 */
	Matrix4 operator - () const;
	
	
	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] m2 ������邷��s��.
	 * @return ����������ʂ̍s��.
	 */
	Matrix4& operator = ( const Matrix4& m2 );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h(�E����W�n)
	 * 
	 * @param[in] m2 ��Z����s��.
	 * @return ���Z���ʂ̍s��.
	 */
	Matrix4& operator *= ( const Matrix4& m2 );


	/*=========================================================================*/
	/**
	 * @brief float* ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g�����l.
	 */
	operator float* () const;


	/*=========================================================================*/
	/**
	 * @brief float* ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g�����l.
	 */
	operator const float* () const;


#endif


} NGLmatrix4;


#ifdef __cplusplus


/** ��s�� */
static const Matrix4 MATRIX4_ZERO = Matrix4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
	);


/** �P�ʍs�� */
static const Matrix4 MATRIX4_IDENTITY = Matrix4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
	);

}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ��r����s��.
 * @param[in] m2 ��r����s��.
 * @return ��r���ʂ̍s��.
 */
bool operator == ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ��r����s��.
 * @param[in] m2 ��r����s��.
 * @return ��r���ʂ̍s��.
 */
bool operator != ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Ngl::Matrix4 operator + ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Ngl::Matrix4 operator - ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Ngl::Matrix4 operator * ( const Ngl::Matrix4& m1, const Ngl::Matrix4& m2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] v ���Z����3�����x�N�g��.
 * @param[in] m ���Z����s��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v, const Ngl::Matrix4& m );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m ���Z����s��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Ngl::Matrix4 operator * ( const Ngl::Matrix4& m, float s );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] m ���Z����s��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Ngl::Matrix4 operator * ( float s, const Ngl::Matrix4& m );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m ���Z����s��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Ngl::Matrix4 operator / ( const Ngl::Matrix4& m, float s );


#endif


#endif


/*========= EOF =============================================================*/