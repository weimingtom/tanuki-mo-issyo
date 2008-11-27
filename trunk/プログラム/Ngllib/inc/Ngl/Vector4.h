/*******************************************************************************/
/**
 * @file Vector4.h.
 * 
 * @brief 4�����x�N�g���\���̃w�b�_�t�@�C��.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR4_H_
#define _NGL_VECTOR4_H_


#ifdef __cplusplus
namespace Ngl{

// 3�����x�N�g��
struct Vector3;

// 4x4�\����
struct Matrix4;

#endif


/**
 * @struct Vector4�D
 * @brief 4�����x�N�g���\����.
 */
typedef struct Vector4 
{
	/**	x����	*/
	float	x;

	/**	y����	*/
	float	y;

	/**	z����	*/
	float	z;

	/** w���� */
	float	w;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Vector4();

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] X x�l.
	 * @param[in] Y y�l.
	 * @param[in] Z z�l.
	 * @param[in] W w�l.
	 */
	Vector4( float X, float Y, float Z, float W );


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] V 3�����x�N�g��.
	 * @param[in] W w�l.
	 */
	Vector4( const Vector3& V, float W=0.0f );

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �������z��.
	 */
	Vector4( float* other );


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
	 * @param[in] W w�l.
	 * @return �Ȃ�.
	 */
	void initialize( float X, float Y, float Z, float W );


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
	Vector4& normalize();


	/*=========================================================================*/
	/**
	 * @brief ���ς����߂�
	 * 
	 * @param[in] v �v�Z����x�N�g��.
	 * @return ���ς̒l.
	 */
	float dot( const Vector4& v ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�ƕ��ʊp����x�N�g�������߂�
	 * 
	 * @param[in] elevation �p.
	 * @param[in] direction ���ʊp.
	 * @return ���߂��x�N�g��.
	 */
	Vector4& fromEleDir( float elevation, float direction );
	
	
	/*=========================================================================*/
	/**
	 * @brief �s�b�`�p�ƃ��[�p����x�N�g�������߂�
	 * 
	 * @param[in] pitch �s�b�`�p.
	 * @param[in] yaw ���[�p.
	 * @return ���߂��x�N�g��.
	 */
	Vector4& fromPitchYaw( float pitch, float yaw );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�̋��������߂�
	 * 
	 * @param[in] other ���������߂�x�N�g��.
	 * @return �x�N�g���̋���.
	 */
	float distance( const Vector4& other );

	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�̋��������߂�(���[�g�����Ȃ�)
	 * 
	 * @param[in] other ���������߂�x�N�g��.
	 * @return �x�N�g���̋���(�Q��a�̂�).
	 */
	float distanceSq( const Vector4& other );
	
	
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
	 * @brief �����̕������̌v�Z���s��
	 * 
	 * @param[in] p �x�N�g��1.
	 * @param[in] v �x�N�g��2.
	 * @param[in] t �W��.
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector4 linearEquation( const Vector4& p, const Vector4& v, float t );

	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g���̐��`��Ԃ��s��
	 * 
	 * @param[in] min �ŏ��l.
	 * @param[in] max �ő�l.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector4& lerp( const Vector4& min, const Vector4& max, float t );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g����2����Ԃ��s��
	 * 
	 * @param[in] v1 ��ԗv�f4�����x�N�g��.
	 * @param[in] v2 ��ԗv�f4�����x�N�g��.
	 * @param[in] v3 ��ԗv�f4�����x�N�g��.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector4& quadratic( const Vector4& v1, const Vector4& v2, const Vector4& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g�������W�ϊ�����
	 * 
	 * @param[in] matrix �ϊ��s��.
	 * @return ����.
	 */
	Vector4& transform( const Matrix4& matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief �{���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ӗ��Ȃ�.
	 */
	Vector4	operator + () const;


	/*=========================================================================*/
	/**
	 * @brief -���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t�x�N�g��.
	 */
	Vector4	operator - () const;


	/*=========================================================================*/
	/**
	 * @brief +=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator += ( const Vector4& v);


	/*=========================================================================*/
	/**
	 * @brief -=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator -= ( const Vector4& v );


	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ��Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator *= ( const Vector4& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ��Z����X�J���[.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator *= ( float s );
	

	/*=========================================================================*/
	/**
	 * @brief /=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator /= ( const Vector4& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����X�J���[.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector4& operator /= ( float s );

	
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


} NGLvector4;


#ifdef __cplusplus


/** �[���x�N�g�� */
static const Vector4 VECTOR4_ZERO = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );

/** �P�ʃx�N�g�� */
static const Vector4 VECTOR4_IDENTITY = Vector4( 1.0f, 1.0f, 1.0f, 1.0f );


} // namespace Ngl

/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator + ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator - ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��1.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( const Ngl::Vector4& v, float s );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] v ���Z����x�N�g��.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator * ( float s, const Ngl::Vector4& v );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v ���Z����x�N�g��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector4 operator / ( const Ngl::Vector4& v, float s );


/*=========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator < ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator > ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief <=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator <= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


/*=========================================================================*/
/**
 * @brief >=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator >= ( const Ngl::Vector4& v1, const Ngl::Vector4& v2 );


#endif


#endif

/*===== EOF ==================================================================*/