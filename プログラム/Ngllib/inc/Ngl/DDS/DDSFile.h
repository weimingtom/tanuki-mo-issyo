/*******************************************************************************/
/**
 * @file DDSFile.h.
 * 
 * @brief DDS DDS�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DDS_DDSFILE_H_
#define _NGL_DDS_DDSFILE_H_

#include	"Ngl/IInputStream.h"
#include	<vector>

namespace Ngl{


// �e�N�X�`���t�B���^
class ITextureFilter;

namespace DDS{


/**
 * @class DDSFile.
 * @brief DDS DDS�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X.
 *
 * A8B8G8R8�t�H�[�}�b�g��DDS�t�@�C���̂ݑΉ�.
 */
class DDSFile
{
public:

	/** ��������8bit�^ */
	typedef unsigned char BYTE;

	/** ��������32bit�^ */
	typedef unsigned int DWORD;

	
	/**
	 * @struct PixelFormat.
	 * @brief DDS DDS�t�@�C���s�N�Z���t�H�[�}�b�g�\����
	 */
	struct PixelFormat
	{
		DWORD			dwSize;
		DWORD			dwFlags;
		DWORD			dwFourCC;
		DWORD			dwRGBBitCount;
		DWORD			dwRBitMask;
		DWORD			dwGBitMask;
		DWORD			dwBBitMask;
		DWORD			dwRGBAlphaBitMask;
	};


	/**
	 * @struct Caps2.
	 * @brief DDS DDS�t�@�C���⏕�t���O�\����.
	 */
	struct Caps2
	{
		DWORD			dwCaps1;
		DWORD			dwCaps2;
		DWORD			dwReserved[2];
	};

	
	/**
	 * @struct SurfaceDesc.
	 * @brief DDS �T�[�t�F�[�X�L�q�q.
	 */
	struct SurfaceDesc
	{
		DWORD			dwSize;
		DWORD			dwFlags;
		DWORD			dwHeight;
		DWORD			dwWidth;
		DWORD			dwPitchOrLinearSize;
		DWORD			dwDepth;
		DWORD			dwMipMapCount;
		DWORD			dwReserved1[11];
		PixelFormat		ddpfPixelFormat;
		Caps2			ddsCaps;
		DWORD			dwReserved2;
	};

	/** DDS�t�@�C���}�W�b�N�i���o�[ */
	static const DWORD DDS_MAGIC_NUMBER		= 0x20534444;

	/** DDS�t���O */
	static const DWORD FLAG_CAPS			= 0x00000001;
	static const DWORD FLAG_HEIGHT			= 0x00000002;
	static const DWORD FLAG_WIDTH			= 0x00000004;
	static const DWORD FLAG_PITCH			= 0x00000008;
	static const DWORD FLAG_PIXELFORMAT		= 0x00001000;
	static const DWORD FLAG_MIPMAPCOUNT		= 0x00020000;
	static const DWORD FLAG_LINEARSIZE		= 0x00080000;
	static const DWORD FLAG_DEPTH			= 0x00800000;

	/** �s�N�Z���t�H�[�}�b�g */
	static const DWORD FORMAT_LUMINANCE		= 0x00020000;
	static const DWORD FORMAT_RGB			= 0x00000040;
	static const DWORD FORMAT_ALPHAPIXELS	= 0x00000001;
	static const DWORD FORMAT_FOURCC		= 0x00000004;
	static const DWORD FORMAT_DXT1			= 0x31545844;
	static const DWORD FORMAT_DXT3			= 0x33545844;
	static const DWORD FORMAT_DXT5			= 0x35545844;

	/** �⏕�t���O */
	static const DWORD CAPS1_ALPHA			= 0x00000002;
	static const DWORD CAPS1_MIPMAP			= 0x00400000;
	static const DWORD CAPS1_COMPLEX		= 0x00000008;
	static const DWORD CAPS1_TEXTURE		= 0x00001000;
	static const DWORD CAPS2_CUBEMAP		= 0x0000fe00;
	static const DWORD CAPS2_VOLUME			= 0x00200000;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	DDSFile();

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �t�@�C����.
	 */
	DDSFile( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief �摜�t�@�C������f�[�^��ǂݍ���
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �Ȃ�.
	 */
	void loadFromFile( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �Ȃ�.
	 */
	void loadFromStream( IInputStream& stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief �T�[�t�F�[�X�L�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �T�[�t�F�[�X�L�q�q�̎Q��.
	 */
	const SurfaceDesc& desc();

	
	/*=========================================================================*/
	/**
	 * @brief �f�[�^�T�C�Y���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �f�[�^�T�C�Y.
	 */
	unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���t�B���^��ݒ肷��
	 * 
	 * @warning �ݒ肵���C���X�^���X�̍폜�͍s���܂���.
	 *
	 * @param[in] filter �ݒ肷��t�B���^.
	 * @return �Ȃ�.
	 */
	void setFilter( ITextureFilter* filter );
	
	
	/*=========================================================================*/
	/**
	 * purpose [] ���Z�q�I�[�o�[���[�h: 
	 * 
	 * �s�N�Z���f�[�^���擾����.
	 *
	 * @param[in] index �擾����f�[�^�̃C���f�b�N�X�ԍ�.
	 * @return �s�N�Z���f�[�^�z��̎Q��.
	 */
	DDSFile::BYTE& operator [] ( unsigned int index );

private:

	/** �T�[�t�F�[�X�^ */
	typedef std::vector< BYTE >	Surface;

private:

	/** �e�N�X�`���t�B���^ */
	ITextureFilter*	filter_;

	/** �T�[�t�F�[�X�L�q�q */
	SurfaceDesc		desc_;

	/** �T�[�t�F�[�X */
	Surface			surface_;

};

} // namespace DDS

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/