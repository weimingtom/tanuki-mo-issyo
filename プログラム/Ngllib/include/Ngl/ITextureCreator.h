/*******************************************************************************/
/**
 * @file ITextureCreator.h.
 * 
 * @brief �e�N�X�`���쐬�N���X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTURECREATOR_H_
#define _NGL_ITEXTURECREATOR_H_

#include	"IRenderer.h"
#include	<string>

namespace Ngl{


// �e�N�X�`���t�B���^�C���^�[�t�F�[�X
class ITextureFilter;

/**
 * @interface ITextureCreator�D
 * @brief �e�N�X�`���쐬�N���X�C���^�[�t�F�[�X.
 */
class ITextureCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ITextureCreator() {}


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����쐬
	 * 
	 * @param[in] name �쐬�����\�[�X��.
	 * @return �쐬�����e�N�X�`���̃|�C���^.
	 */
	virtual ITexture* create( const std::string& name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �����_���[��ݒ�
	 * 
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setRenderer( IRenderer* renderer ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �쐬�ł���t�@�C���g���q�����擾
	 * 
	 * @warning "."���܂܂��A�S�ăA���t�@�x�b�g�������̊g���q����Ԃ�.
	 *
	 * @param[in] �Ȃ�.
	 * @return �g���q��.
	 */
	virtual std::string extension() = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���t�B���^��ݒ肷��
	 * 
	 * @warning �ݒ肵���C���X�^���X�̍폜�͍s���܂���.
	 *
	 * @param[in] filter �ݒ肷��t�B���^.
	 * @return �Ȃ�.
	 */
	virtual void setFilter( ITextureFilter* filter ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/