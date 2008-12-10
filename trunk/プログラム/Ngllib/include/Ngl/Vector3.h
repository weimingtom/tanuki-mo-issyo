/*******************************************************************************/
/**
 * @file Vector3.h.
 * 
 * @brief 3�����x�N�g���\���̃w�b�_�t�@�C��.
 *
 * @date 2008/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR3_
#define _NGL_VECTOR3_

#include	"Vector2.h"

#ifdef __cplusplus
namespace Ngl{


// �s��\���̂̑O���Q��
struct Matrix4;

#endif

/**
 * @struct Vector3.
 * @brief 3�����x�N�g���\���́D
 */
typedef struct Vector3
{
	/**	x����	*/
	float	x;

	/**	y����	*/
	float	y;

	/**	z����	*/
	float	z;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Vector3();

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] X x�l.
	 * @param[in] Y y�l.
	 * @param[in] Z z�l.
	 */
	Vector3(float X, float Y, float Z);


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �������z��.
	 */
	Vector3( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief 0.0�ɏ���������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void zero();
	
	
	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] X x�l.
	 * @param[in] Y y�l.
	 * @param[in] Z z�l.
	 * @return �Ȃ�.
	 */
	void initialize( float X, float Y, float Z );
	
	
	/*=========================================================================*/
	/**
	 * @brief �m���������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �m����.
	 */
	float length() const;


	/*=========================================================================*/
	/**
	 * @brief �m���������߂�(���[�g���Ƃ�Ȃ�)
	 * 
	 * @param[in] �Ȃ�.
	 * @return �m����(�Q��a�̂�).
	 */
	float lengthSq() const;


	/*=========================================================================*/
	/**
	 * @brief ���K������
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���K�������x�N�g��.
	 */
	Vector3& normalize();


	/*=========================================================================*/
	/**
	 * @brief ���ς����߂�
	 * 
	 * @param[in] v �v�Z����x�N�g��.
	 * @return ���ς̒l.
	 */
	float dot( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief �O�ς̒l�����߂�
	 * 
	 * @param[in] v �v�Z����x�N�g��.
	 * @return �O�ς̒l.
	 */
	Vector3 cross( const Vector3& v ) const;


	/*=========================================================================*/
	/**
	 * @brief �p�ƕ��ʊp����x�N�g�������߂�
	 * 
	 * @param[in] elevation �p.
	 * @param[in] direction ���ʊp.
	 * @return ���߂��x�N�g��.
	 */
	Vector3& fromEleDir( float elevation, float direction );
	
	
	/*=========================================================================*/
	/**
	 * @brief �s�b�`�p�ƃ��[�p����x�N�g�������߂�
	 * 
	 * @param[in] pitch �s�b�`�p.
	 * @param[in] yaw ���[�p.
	 * @return ���߂��x�N�g��.
	 */
	Vector3& fromPitchYaw( float pitch, float yaw );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�̋��������߂�
	 * 
	 * @param[in] other ���������߂�x�N�g��.
	 * @return �x�N�g���̋���.
	 */
	float distance( const Vector3& other );

	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�̋��������߂�(���[�g�����Ȃ�)
	 * 
	 * @param[in] other ���������߂�x�N�g��.
	 * @return �x�N�g���̋���(�Q��a�̂�).
	 */
	float distanceSq( const Vector3& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�����p�x�����߂�
	 * 
	 * @param[in] other �p�x�����߂鑊��x�N�g��.
	 * @return �p�x.
	 */
	float innerDegree( const Vector3& other );


	/*=========================================================================*/
	/**
	 * @brief �ʖ@�������߂�
	 * 
	 * @param[in] vec1 ���_.
	 * @param[in] vec2 ���_.
	 * @return �@���x�N�g��.
	 */
	Vector3 calculateNoamal( const Vector3& vec1, const Vector3& vec2 );

	
	/*=========================================================================*/
	/**
	 * @brief �����̕������̌v�Z���s��
	 * 
	 * @param[in] p �x�N�g��1.
	 * @param[in] v �x�N�g��2.
	 * @param[in] t �W��.
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector3 linearEquation( const Vector3& p, const Vector3& v, float t );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g���̐��`��Ԃ��s��
	 * 
	 * @param[in] min �ŏ��l.
	 * @param[in] max �ő�l.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector3& lerp( const Vector3& min, const Vector3& max, float t );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g����2����Ԃ��s��
	 * 
	 * @param[in] v1 ��ԗv�f3�����x�N�g��.
	 * @param[in] v2 ��ԗv�f3�����x�N�g��.
	 * @param[in] v3 3�����x�N�g��.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector3& quadratic( const Vector3& v1, const Vector3& v2, const Vector3& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g�������W�ϊ�����
	 * 
	 * @param[in] matrix �ϊ��s��.
	 * @return ����.
	 */
	Vector3& transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief �@���x�N�g�������W�ϊ�����
	 * 
	 * @param[in] matrix �ϊ��s��.
	 * @return ����.
	 */
	Vector3& transformNormal( const Matrix4& matrix );

	
	/*=========================================================================*/
	/**
	 * @brief xy�l����2�����x�N�g�����쐬����
	 * 
	 * @param[in] �Ȃ�.
	 * @return 2�����x�N�g��.
	 */
	Vector2 xy();
	
	
	/*=========================================================================*/
	/**
	 * @brief �{���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ӗ��Ȃ�.
	 */
	Vector3	operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t�x�N�g��.
	 */
	Vector3	operator - () const;


	/*=========================================================================*/
	/**
	 * @brief +=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator += ( const Vector3& v);


	/*=========================================================================*/
	/**
	 * @brief -=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator -= ( const Vector3& v );


	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ��Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator *= ( const Vector3& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ��Z����X�J���[.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator *= ( float s );
	

	/*=========================================================================*/
	/**
	 * @brief /=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator /= ( const Vector3& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����X�J���[.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector3& operator /= ( float s );


	/*=========================================================================*/
	/**
	 * @brief float*���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g�����l.
	 */
	operator float* () const;


	/*=========================================================================*/
	/**
	 * @brief const float*���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g�����l.
	 */
	operator const float* () const;


#endif


} NGLvector3;


#ifdef __cplusplus


/** �[���x�N�g�� */
static const Vector3 VECTOR3_ZERO = Vector3( 0.0f, 0.0f, 0.0f );

/** �P�ʃx�N�g�� */
static const Vector3 VECTOR3_IDENTITY = Vector3( 1.0f, 1.0f, 1.0f );

/** ������x�N�g�� */
static const Vector3 VECTOR3_UP = Vector3( 0.0f, 1.0f, 0.0f );


}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator + ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator - ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��1.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator * ( const Ngl::Vector3& v, float s );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator * ( float s, const Ngl::Vector3& v );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator / ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector3 operator / ( const Ngl::Vector3& v, float s );


/*=========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator < ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator > ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief <=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator <= ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


/*=========================================================================*/
/**
 * @brief >=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator >= ( const Ngl::Vector3& v1, const Ngl::Vector3& v2 );


#endif


#endif

/*========= EOF =============================================================*/