/*******************************************************************************/
/**
 * @file Rect.h.
 * 
 * @brief ��`�\���̃w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RECT_H_
#define _NGL_RECT_H_

#ifdef __cplusplus
namespace Ngl{
#endif


/**
 * @struct Rect
 * @brief ��`�\���́D
 */
typedef struct Rect
{

	/** �����W */
	float left;

	/** ����W */
	float top;

	/** �E���W */
	float right;

	/** �����W */
	float bottom;


#ifdef __cplusplus


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Rect();


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] L ���[�ʒu.
	 * @param[in] T ��[�ʒu.
	 * @param[in] R �E�[�ʒu.
	 * @param[in] B ���[�ʒu.
	 */
	Rect( float L, float T, float R, float B );


	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] L ���[�ʒu.
	 * @param[in] T ��[�ʒu.
	 * @param[in] R �E�[�ʒu.
	 * @param[in] B ���[�ʒu.
	 * @return �Ȃ�.
	 */
	void initialize( float L, float T, float R, float B );


	/*=========================================================================*/
	/**
	 * @brief �ʒu���W, ���ƍ��������`�����߂�
	 * 
	 * @param[in] L ����ʒux���W.
	 * @param[in] T ����ʒuy���W.
	 * @param[in] Width �E�[�ʒu.
	 * @param[in] Height ���[�ʒu.
	 * @return �Ȃ�.
	 */
	void fromSize( float L, float T, float Width, float Height );


#endif


} NGLrect;


#ifdef __cplusplus


/** ���` */
static const Rect RECT_ZERO = Rect( 0.0f, 0.0f, 0.0f, 0.0f );

/** �f�t�H���g�̃e�N�X�`�����W */
static const Rect RECT_TEXCOORD = Rect( 0.0f, 0.0f, 1.0f, 1.0f );


} // namespace Ngl


/*=========================================================================*/
/**
 * @brief == ���Z�q�I�[�o�[���[�h
 *
 * �����l�̋�`����r����B
 * 
 * @param[in] r1 ��r�����`1.
 * @param[in] r2 ��r�����`2.
 * @retval true �����l.
 * @retval false �Ⴄ�l.
 */
bool operator == ( const Ngl::Rect& r1, const Ngl::Rect& r2 );


/*=========================================================================*/
/**
 * @brief != ���Z�q�I�[�o�[���[�h
 *
 * �Ⴄ�l�̋�`����r����B
 * 
 * @param[in] r1 ��r�����`1.
 * @param[in] r2 ��r�����`2.
 * @retval true �Ⴄ�l.
 * @retval false �����l.
 */
bool operator != ( const Ngl::Rect& r1, const Ngl::Rect& r2 );


#endif


#endif

/*===== EOF ==================================================================*/