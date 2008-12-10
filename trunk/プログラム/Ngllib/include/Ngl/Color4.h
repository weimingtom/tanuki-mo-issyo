/*******************************************************************************/
/**
 * @file Color4.h.
 * 
 * @brief RGBA�J���[�\���̃w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLOR4_H_
#define _NGL_COLOR4_H_

#ifdef __cplusplus
namespace Ngl{
#endif


/**
 * @struct Color4
 * @brief RGBA�J���[�\���́D
 */
typedef struct Color4
{
	/** r���� */
	float	r;

	/** g���� */
	float	g;

	/** g���� */
	float	b;

	/** a���� */
	float	a;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Color4();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] R �Ԑ���.
	 * @param[in] G �ΐ���.
	 * @param[in] B ����.
	 * @param[in] A �A���t�@����
	 */
	Color4(float R, float G, float B, float A);


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] other �J���[�z��̃|�C���^.
	 */
	Color4( float* other );


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
	 * @param[in] R �Ԑ���.
	 * @param[in] G �ΐ���.
	 * @param[in] B ����.
	 * @param[in] A �A���t�@����
	 * @return �Ȃ�.
	 */
	void initialize( float R, float G, float B, float A );

	
	/*=========================================================================*/
	/**
	 * @brief 255�`0�͈̔͂ɃN�����v
	 * 
	 * @param[in] �Ȃ�.
	 * @return �N�����v���ꂽcolor.
	 */
	Color4& saturate();


	/*=========================================================================*/
	/**
	 * @brief 16�i���̒l�ɕϊ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ϊ������l.
	 */
	unsigned long changeHexaDecimal() const;


	/*=========================================================================*/
	/**
	 * @brief RGB�l����J���[��ݒ肷��
	 * @param[in] R �Ԑ���.
	 * @param[in] G �ΐ���.
	 * @param[in] B ����.
	 * @return �ϊ������l.
	 */
	Color4& setColorOfRGB( int R, int G, int B );

	
	/*=========================================================================*/
	/**
	 * @brief RGBA�l����J���[��ݒ肷��
	 * @param[in] R �Ԑ���.
	 * @param[in] G �ΐ���.
	 * @param[in] B ����.
	 * @param[in] A �A���t�@����.
	 * @return �ϊ������l.
	 */
	Color4& setColorOfRGBA( int R, int G, int B, int A );

	
	/*=========================================================================*/
	/**
	 * @brief + ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z����color�̒l.
	 */
	Color4 operator + () const;


	/*=========================================================================*/
	/**
	 * @brief - ���Z�q�I�[�o�[���[�h, ��F�����߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���Z����color�̒l.
	 */
	Color4 operator - () const;

	
	/*=========================================================================*/
	/**
	 * @brief += ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] c2 ���Z����J���[.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator += (const Color4& c2);
	

	/*=========================================================================*/
	/**
	 * @brief -= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] c2 ���Z����J���[.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator -= (const Color4& c2);
	
	
	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] c2 ���Z����J���[.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator *= (const Color4& c2);


	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����l.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator *= (float s);
	
	
	/*=========================================================================*/
	/**
	 * @brief *= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����l.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator *= (int s);
	
	
	/*=========================================================================*/
	/**
	 * @brief /= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] c2 ���Z����J���[.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator /= (const Color4& c2);
	
	
	/*=========================================================================*/
	/**
	 * @brief /= ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] s ���Z����l.
	 * @return ���Z����color�̒l.
	 */
	Color4& operator /= (int s);


	/*=========================================================================*/
	/**
	 * @brief float* ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g����float�^�̒l.
	 */
	operator float *() const;


	/*=========================================================================*/
	/**
	 * @brief const float* ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] �Ȃ�.
	 * @return �L���X�g����const float*�^�̒l.
	 */
	operator const float *() const;


#endif


} NGLcolor4;


#ifdef __cplusplus


/** �z���C�g */
static const Ngl::Color4 COLOR4_WHITE = Ngl::Color4( 1.0f, 1.0f, 1.0f, 1.0f );

/** �� */
static const Ngl::Color4 COLOR4_RED = Ngl::Color4( 1.0f, 0.0f, 0.0f, 1.0f );

/** �� */
static const Ngl::Color4 COLOR4_GREEN = Ngl::Color4( 0.0f, 1.0f, 0.0f, 1.0f );

/** �� */
static const Ngl::Color4 COLOR4_BLUE = Ngl::Color4( 0.0f, 0.0f, 1.0f, 1.0f );

/** �� */
static const Ngl::Color4 COLOR4_BLACK = Ngl::Color4( 0.0f, 0.0f, 0.0f, 1.0f );


}	// namespace Ngl


/*===========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Ngl::Color4 operator + (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief - ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Ngl::Color4 operator - (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c1 ���Z����J���[.
 * @param[in] c2 ���Z����J���[.
 * @return ���Z��������.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c1, const Ngl::Color4& c2);


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @param[in] c ���Z����J���[.
 * @return ���Z��������.
 */
const Ngl::Color4 operator * (float s, const Ngl::Color4& c);


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c, float s);


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] s ���Z����l.
 * @param[in] c ���Z����J���[.
 * @return ���Z��������.
 */
const Ngl::Color4 operator * (int s, const Ngl::Color4& c);


/*===========================================================================*/
/**
 * @brief * ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Ngl::Color4 operator * (const Ngl::Color4& c, int s);


/*===========================================================================*/
/**
 * @brief / ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] c ���Z����J���[.
 * @param[in] s ���Z����l.
 * @return ���Z��������.
 */
const Ngl::Color4 operator / (const Ngl::Color4& c, int s);


#endif


#endif

/*========= EOF =============================================================*/