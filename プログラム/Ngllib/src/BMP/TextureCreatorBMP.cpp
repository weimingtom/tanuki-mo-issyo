/*******************************************************************************/
/**
 * @file TextureCreatorBMP.cpp.
 * 
 * @brief BMP �e�N�X�`���쐬�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/BMP/TextureCreatorBMP.h"

using namespace Ngl;
using namespace Ngl::BMP;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 */
TextureCreatorBMP::TextureCreatorBMP( IRenderer* renderer ):
	renderer_( renderer ),
	filter_( 0 )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureCreatorBMP::~TextureCreatorBMP()
{}



/*=========================================================================*/
/**
 * @brief �e�N�X�`�����쐬
 * 
 * @param[in] fileName �t�@�C����.
 * @return �쐬�����e�N�X�`���̃|�C���^.
 */
ITexture* TextureCreatorBMP::create( const std::string& fileName )
{
	// �t�B���^���ݒ肳��Ă��邩
	if( filter_ != 0 ){
		bmp_.setFilter( filter_ );
	}

	// BMP�t�@�C�����쐬
	bmp_.loadFromFile( fileName.c_str() );

	// �e�N�X�`���L�q�q���쐬
	TextureDesc td;
	td.format		= TEXTURE_FORMAT_RGBA8;
	td.type			= TEXTURE_TYPE_2D;
	td.width		= bmp_.desc().biWidth;
	td.height		= bmp_.desc().biHeight;
	td.mipLevels	= 1;
	td.usage		= TEXTURE_USAGE_IMMUTABLE;

	// �e�N�X�`���f�[�^���쐬
	ITexture* tex = renderer_->createTexture( td, &bmp_[ 0 ] );

	return tex;
}



/*=========================================================================*/
/**
 * @brief �����_���[��ݒ�
 * 
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 * @return �Ȃ�.
 */
void TextureCreatorBMP::setRenderer( IRenderer* renderer )
{
	renderer_ = renderer;
}



/*=========================================================================*/
/**
 * @brief �쐬�ł���t�@�C���g���q�����擾
 * 
 * @warning "."���܂܂��A�S�ăA���t�@�x�b�g�������̊g���q����Ԃ�.
 * @param[in] �Ȃ�.
 * @return �g���q��.
 */
std::string TextureCreatorBMP::extension()
{
	return "bmp";
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���t�B���^��ݒ肷��
 * 
 * @warning �ݒ肵���C���X�^���X�̍폜�͍s���܂���.
 *
 * @param[in] filter �ݒ肷��t�B���^.
 * @return �Ȃ�.
 */
void TextureCreatorBMP::setFilter( ITextureFilter* filter )
{
	bmp_.setFilter( filter );
}
	
	
	
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
void TextureCreatorBMP::setBMPPixel( IBMPPixel* pixel, BitCount bitCount )
{
	bmp_.setBMPPixel( pixel, bitCount );
}
	
	
	
/*===== EOF ==================================================================*/