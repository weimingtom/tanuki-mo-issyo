/*******************************************************************************/
/**
 * @file TextureCreatorDDS.cpp.
 * 
 * @brief DDS �e�N�X�`���쐬�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DDS/TextureCreatorDDS.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DDS;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 */
TextureCreatorDDS::TextureCreatorDDS( IRenderer* renderer ):
	renderer_( renderer ),
	dds_( 0 ),
	filter_( 0 )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
TextureCreatorDDS::~TextureCreatorDDS()
{
	delete dds_;
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`�����쐬
 * 
 * @param[in] fileName �t�@�C����.
 * @return �쐬�����e�N�X�`���̃|�C���^.
 */
ITexture* TextureCreatorDDS::create( const std::string& fileName )
{
	// �����_���[���o�^����Ă��邩
	assert( renderer_ != 0 );

	// �����f�[�^�̍쐬�v����������?
	if( fileName_ == fileName && dds_ != 0 ){
		// �e�N�X�`���쐻�L�q�q�ɕϊ�
		TextureDesc descTex = toTextureDesc( dds_->desc() );

		// �e�N�X�`�����쐬
		return renderer_->createTexture( descTex, &dds_[ 0 ] );
	}

	// �ȑO�̃f�[�^���폜
	delete dds_;
	dds_ = 0;

	// �t�@�C������o�^
	fileName_ = fileName;

	// DDS�t�@�C�����쐬
	dds_ = new DDSFile();

	// �e�N�X�`���t�B���^��ݒ�
	if( filter_ != 0 ){
		dds_->setFilter( filter_ );
	}

	// DDS�t�@�C����ǂݍ���
	dds_->loadFromFile( fileName_.c_str() );

	// �e�N�X�`���쐻�L�q�q�ɕϊ�
	TextureDesc descTex = toTextureDesc( dds_->desc() );

	// �e�N�X�`�����쐬
	return renderer_->createTexture( descTex, &(*dds_)[ 0 ] );
}



/*=========================================================================*/
/**
 * @brief �����_���[��ݒ�
 * 
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 * @return �Ȃ�.
 */
void TextureCreatorDDS::setRenderer( IRenderer* renderer )
{
	renderer_ = renderer;
}



/*=========================================================================*/
/**
 * @brief �쐬�ł���t�@�C���g���q�����擾( .���܂܂Ȃ��g���q�� )
 * 
 * @warning "."���܂܂��A�S�ăA���t�@�x�b�g�������̊g���q����Ԃ�.
 *
 * @param[in] �Ȃ�.
 * @return �g���q��( "dds" ).
 */
std::string TextureCreatorDDS::extension()
{
	return "dds";
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
void TextureCreatorDDS::setFilter( ITextureFilter* filter )
{
	filter_ = filter;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �e�N�X�`���t�H�[�}�b�g�ɕϊ�
 * 
 * @param[in] ddpf DDS�s�N�Z���t�H�[�}�b�g�\���̂̎Q��.
 * @return �ϊ������e�N�X�`���t�H�[�}�b�g.
 */
TextureFormat TextureCreatorDDS::toTextureFormat( const DDSFile::PixelFormat& ddpf )
{
	// L8�t�H�[�}�b�g��
	if( ( ddpf.dwFlags & DDSFile::FORMAT_LUMINANCE ) != 0 ){
		return TEXTURE_FORMAT_I8;
	}

	// DXT�t�H�[�}�b�g��
	if( ( ddpf.dwFlags & DDSFile::FORMAT_FOURCC ) != 0 ){
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT1 ){
			return TEXTURE_FORMAT_DXT1;
		}
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT3 ){
			return TEXTURE_FORMAT_DXT3;
		}
		if( ddpf.dwFourCC == DDSFile::FORMAT_DXT5 ){
			return TEXTURE_FORMAT_DXT5;
		}
	}

	// ABGR�t�H�[�}�b�g��
	assert( ( ddpf.dwFlags & DDSFile::FORMAT_RGB ) != 0
		&& ddpf.dwRGBBitCount		== 32
		&& ddpf.dwRBitMask			== 0x000000ff
		&& ddpf.dwGBitMask			== 0x0000ff00
		&& ddpf.dwBBitMask			== 0x00ff0000
		&& ddpf.dwRGBAlphaBitMask	== 0xff000000
		);

	return TEXTURE_FORMAT_RGBA8;
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���^�C�v�ɕϊ�
 * 
 * @param[in] caps DDS�⏕�t���O�\���̂̎Q��.
 * @return �ϊ������e�N�X�`���^�C�v.
 */
TextureType TextureCreatorDDS::toTextureType( const DDSFile::Caps2& caps )
{
	if( ( caps.dwCaps2 & DDSFile::CAPS2_CUBEMAP ) == DDSFile::CAPS2_CUBEMAP ){
		return TEXTURE_TYPE_CUBE;
	}

	if( ( caps.dwCaps2 & DDSFile::CAPS2_VOLUME ) != 0 ){
		return TEXTURE_TYPE_3D;
	}

	return TEXTURE_TYPE_2D;
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���L�q�q�ɕϊ�
 * 
 * @param[in] descDDS DDS�T�[�t�F�[�X�L�q�q�̎Q��.
 * @return �ϊ������e�N�X�`���L�q�q.
 */
TextureDesc TextureCreatorDDS::toTextureDesc( const DDSFile::SurfaceDesc& descDDS )
{
	TextureDesc descTex;
	descTex.type		= toTextureType( descDDS.ddsCaps );
	descTex.format		= toTextureFormat( descDDS.ddpfPixelFormat );
	descTex.width		= descDDS.dwWidth;
	descTex.height		= descDDS.dwHeight;
	
	if( descTex.type == TEXTURE_TYPE_3D ){
		descTex.depth = descDDS.dwDepth;
	}

	descTex.mipLevels = 1;
	if( ( descDDS.dwFlags & DDSFile::FLAG_MIPMAPCOUNT ) != 0 ){
		descTex.mipLevels = descDDS.dwMipMapCount;
	}

	descTex.renderTarget = false;

	return descTex;
}

	
	
/*===== EOF ==================================================================*/