/*******************************************************************************/
/**
 * @file FrameWorkDesc.h.
 * 
 * @brief �t���[�����[�N�L�q�q�\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRAMEWORKDESC_H_
#define _NGL_FRAMEWORKDESC_H_

#include	<string>

namespace Ngl{

static const int FRAMEWORK_DEFAULT_WIDTH	= 640;	/**< �f�t�H���g�̃E�B���h�E�̕�		*/
static const int FRAMEWORK_DEFAULT_HEIGHT	= 480;	/**< �f�t�H���g�̃E�B���h�E�̍���	*/

/**
 * @struct FrameWorkDesc�D
 * @brief �t���[�����[�N�L�q�q�\����.
 */
struct FrameWorkDesc
{

	/** �E�B���h�E�^�C�g�� */
	std::string	windowTitle;

	/** �E�B���h�E��x���W */
	int			posX;

	/** �E�B���h�E��y���W */
	int			posY;

	/** �E�B���h�E�̕� */
	int			windowWidth;

	/** �E�B���h�E�̍��� */
	int			windowHeight;

	/** �t���X�N���[�����[�h */
	bool		isFullScreenMode;


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	FrameWorkDesc():
		posX( 0 ),
		posY( 0 ),
		windowWidth( FRAMEWORK_DEFAULT_WIDTH ),
		windowHeight( FRAMEWORK_DEFAULT_HEIGHT ),
		isFullScreenMode( false )
	{}

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/