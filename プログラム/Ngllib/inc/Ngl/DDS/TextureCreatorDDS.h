/*******************************************************************************/
/**
 * @file TextureCreatorDDS.h.
 * 
 * @brief DDS �e�N�X�`���쐬�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DDS_TEXTURECREATORDDS_H_
#define _NGL_DDS_TEXTURECREATORDDS_H_

#include	"Ngl/ITextureCreator.h"
#include	"DDSFile.h"
#include	<string>

namespace Ngl{


namespace DDS{


/**
 * @class TextureCreatorDDS�D
 * @brief DDS �e�N�X�`���쐬�N���X.
 */
class TextureCreatorDDS : public ITextureCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 */
	TextureCreatorDDS( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~TextureCreatorDDS();


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����쐬
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�����e�N�X�`���̃|�C���^.
	 */
	virtual ITexture* create( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief �����_���[��ݒ�
	 * 
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void setRenderer( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief �쐬�ł���t�@�C���g���q�����擾
	 * 
	 * @warning "."���܂܂��A�S�ăA���t�@�x�b�g�������̊g���q����Ԃ�.
	 *
	 * @param[in] �Ȃ�.
	 * @return �g���q��( "dds" ).
	 */
	virtual std::string extension();


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���t�B���^��ݒ肷��
	 * 
	 * @warning �ݒ肵���C���X�^���X�̍폜�͍s���܂���.
	 *
	 * @param[in] filter �ݒ肷��t�B���^.
	 * @return �Ȃ�.
	 */
	virtual void setFilter( ITextureFilter* filter );

private:

	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���t�H�[�}�b�g�ɕϊ�
	 * 
	 * @param[in] ddpf DDS�s�N�Z���t�H�[�}�b�g�\���̂̎Q��.
	 * @return �ϊ������e�N�X�`���t�H�[�}�b�g.
	 */
	TextureFormat toTextureFormat( const DDSFile::PixelFormat& ddpf );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���^�C�v�ɕϊ�
	 * 
	 * @param[in] caps DDS�⏕�t���O�\���̂̎Q��.
	 * @return �ϊ������e�N�X�`���^�C�v.
	 */
	TextureType toTextureType( const DDSFile::Caps2& caps );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���L�q�q�ɕϊ�
	 * 
	 * @param[in] descDDS DDS�T�[�t�F�[�X�L�q�q�̎Q��.
	 * @return �ϊ������e�N�X�`���L�q�q.
	 */
	TextureDesc toTextureDesc( const DDSFile::SurfaceDesc& descDDS );

private:

	/** �����_���[�N���X */
	IRenderer*		renderer_;

	/** DDS�t�@�C���N���X�̃|�C���^ */
	DDSFile*		dds_;

	/** �e�N�X�`���t�B���^ */
	ITextureFilter*	filter_;

	/** �e�N�X�`���t�@�C���� */
	std::string		fileName_;

};

} // namespace DDS

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/