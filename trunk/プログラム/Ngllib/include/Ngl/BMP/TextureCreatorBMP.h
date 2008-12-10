/*******************************************************************************/
/**
 * @file TextureCreatorBMP.h.
 * 
 * @brief BMP �e�N�X�`���쐬�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_TEXTURECREATORBMP_H_
#define _NGL_BMP_TEXTURECREATORBMP_H_

#include	"BMPFile.h"
#include	"Ngl/ITextureCreator.h"


namespace Ngl{


namespace BMP{


/**
 * @class TextureCreatorBMP�D
 * @brief BMP �e�N�X�`���쐬�N���X.
 */
class TextureCreatorBMP : public ITextureCreator
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 */
	TextureCreatorBMP( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~TextureCreatorBMP();


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
	 * @param[in] �Ȃ�.
	 * @return �g���q��.
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
	
	
	/*=========================================================================*/
	/**
	 * @brief �s�N�Z���N���X��ݒ肷��
	 * 
	 * bitCount�r�b�g�̃r�b�g�}�b�v�̃s�N�Z���f�[�^�����N���X��ݒ肵�܂��B
	 *
	 * @param[in] pixel �ݒ肷��s�N�Z���N���X.
	 * @param[in] bitCount �֐���ݒ肷��r�b�g�}�b�v.
	 * @return �Ȃ�.
	 */
	void setBMPPixel( IBMPPixel* pixel, BitCount bitCount );

private:

	/** �e�N�X�`���t�B���^ */
	ITextureFilter*	filter_;

	/** �����_���[�N���X */
	IRenderer*		renderer_;

	/** �e�N�X�`���t�@�C���� */
	std::string		fileName_;

	/** �r�b�g�}�b�v�t�@�C���N���X */
	BMPFile			bmp_;


};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/