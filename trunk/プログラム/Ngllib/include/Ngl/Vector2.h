/*******************************************************************************/
/**
 * @file Vector2.h.
 * 
 * @brief �Q�����x�N�g���\���̃w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef	_NGL_VECTOR2_H_
#define	_NGL_VECTOR2_H_


#ifdef __cplusplus
namespace Ngl{
#endif

/**
 * @struct Vector2.
 * @brief 2�����x�N�g���\���́D
 */
typedef struct Vector2
{
	/** x���� */
	float		x;

	/** y���� */
	float		y;

	
#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Vector2();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �z��̃|�C���^.
	 */
	Vector2( const float* other );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] X x����.
	 * @param[in] Y y����.
	 */
	Vector2( float X, float Y );

	
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
	 * @param[in] X x����.
	 * @param[in] Y y����.
	 * @return �Ȃ�.
	 */
	void initialize( float X, float Y );
	
	
	/*=========================================================================*/
	/**
	 * @brief �m���������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	float length() const;


	/*=========================================================================*/
	/**
	 * @brief ���K������
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���K�������x�N�g��.
	 */
	Vector2& normalize();


	/*=========================================================================*/
	/**
	 * @brief ���ς����߂�
	 * 
	 * @param[in] v ���ς����߂�x�N�g��.
	 * @return ����.
	 */
	float dot( const Vector2& v ) const;


	/*=========================================================================*/
	/**
	 * @brief �x�N�g�����m�̋��������߂�
	 * 
	 * @param[in] other ���������߂�x�N�g��.
	 * @return �x�N�g���̋���.
	 */
	float distance( const Ngl::Vector2& other );

	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g���̐��`��Ԃ��s��
	 * 
	 * @param[in] min �ŏ��l.
	 * @param[in] max �ő�l.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector2& lerp( const Vector2& min, const Vector2& max, float t );


	/*=========================================================================*/
	/**
	 * @brief �x�N�g����2����Ԃ��s��
	 * 
	 * @param[in] v1 ��ԗv�f2�����x�N�g��.
	 * @param[in] v2 ��ԗv�f2�����x�N�g��.
	 * @param[in] v3 2�����x�N�g��.
	 * @param[in] t ��Ԓl( 0.0f�`1.0f ).
	 * @return ���ʂ̃x�N�g��.
	 */
	Vector2& quadratic( const Vector2& v1, const Vector2& v2, const Vector2& v3, float t );
	
	
	/*=========================================================================*/
	/**
	 * @brief + ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	Vector2  operator + () const;
	
	
	/*=========================================================================*/
	/**
	 * @brief - ���Z�q�I�[�o�[���[�h �t�x�N�g�������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	Vector2  operator - () const;


	/*=========================================================================*/
	/**
	 * @brief += ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector2&  operator += ( const Vector2& v );


	/*=========================================================================*/
	/**
	 * @brief -= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector2&  operator -= ( const Vector2& v );


	/*=========================================================================*/
	/**
	 * @brief *=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ��Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector2& operator *= ( const Vector2& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ��Z����X�J���[�l.
	 * @return ��Z���ʂ̃x�N�g��.
	 */
	Vector2&  operator *= ( float s );


	/*=========================================================================*/
	/**
	 * @brief /=���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] v ���Z����x�N�g��.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector2& operator /= ( const Vector2& v );
	
	
	/*=========================================================================*/
	/**
	 * @brief /= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����X�J���[�l.
	 * @return ���Z���ʂ̃x�N�g��.
	 */
	Vector2&  operator /= ( float s );


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
	 * @brief float*���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g�����l.
	 */
	operator const float* () const;


#endif


} NGLvector2;


#ifdef __cplusplus


/** �[���x�N�g�� */
static const Vector2 VECTOR2_ZERO = Vector2( 0.0f, 0.0f );

/** ������x�N�g�� */
static const Vector2 VECTOR2_UP = Vector2( 0.0f, 1.0f );

}	// namespace Ngl

/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator + ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator - ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator * ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ��Z����x�N�g��.
 * @param[in] s ��Z����X�J���[�l.
 * @return ��Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator * ( const Ngl::Vector2& v, float s );


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ��Z����X�J���[.
 * @param[in] v ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator * ( float s, const Ngl::Vector2& v );


/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h�@�񃁃��o�֐�
 * 
 * @param[in] v1 ���Z����x�N�g��1.
 * @param[in] v2 ���Z����x�N�g��2.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator / ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*===========================================================================*/
/**
 * @brief / ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v ���Z����x�N�g��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ̃x�N�g��.
 */
const Ngl::Vector2 operator / ( const Ngl::Vector2& v, float s );


/*=========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator == ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l, false �Ⴄ�l.
 */
bool operator != ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator < ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator > ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief <=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator <= ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


/*=========================================================================*/
/**
 * @brief >=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] v1 ��r����3�����x�N�g��1.
 * @param[in] v2 ��r����3�����x�N�g��2.
 * @return true �����l,
 */
bool operator >= ( const Ngl::Vector2& v1, const Ngl::Vector2& v2 );


#endif


#endif

/*===== EOF ==================================================================*/