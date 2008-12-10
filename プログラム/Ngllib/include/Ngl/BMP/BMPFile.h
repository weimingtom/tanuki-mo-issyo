/*******************************************************************************/
/**
 * @file BMPFile.h.
 * 
 * @brief BMP �r�b�g�}�b�v�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_BMPFILE_H_
#define _NGL_BMP_BMPFILE_H_

#include	"BitMap.h"
#include	"IBMPPixel.h"
#include	"Ngl/SmartPtr.h"
#include	<fstream>
#include	<vector>
#include	<map>
#include	<memory>


namespace Ngl{


// �e�N�X�`���t�B���^
class ITextureFilter;

namespace BMP{


/**
 * @class BMPFile�D
 * @brief BMP �r�b�g�}�b�v�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X.
 */
class BMPFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	BMPFile();
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �t�@�C����.
	 */
	BMPFile( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~BMPFile();


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
	 * @brief �r�b�g�}�b�v���\���̂��擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �r�b�g�}�b�v���\����.
	 */
	const BitMapInfoHeader& desc();
	
	
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
	 * @brief �s�N�Z���N���X��ݒ肷��
	 * 
	 * bitCount���̃r�b�g�}�b�v�̃s�N�Z���f�[�^�����N���X��ݒ肵�܂��B
	 *
	 * @param[in] pixel �ݒ肷��s�N�Z���N���X.
	 * @param[in] bitCount �֐���ݒ肷��r�b�g�}�b�v.
	 * @return �Ȃ�.
	 */
	void setBMPPixel( IBMPPixel* pixel, BitCount bitCount );
	
	
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
	unsigned char& operator[] ( unsigned int index );

private:

	/*=========================================================================*/
	/**
	 * @brief �f�t�H���g�̃s�N�Z�������N���X��o�^
	 * 
	 * @param[in] �Ȃ�.
	 * @retval �Ȃ�.
	 */
	void setDefaultPixelFunc();

	
	/*=========================================================================*/
	/**
	 * @brief �r�b�g�}�b�v�t�@�C���w�b�_��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @retval �Ȃ�.
	 * @throw std::ios::failure �ǂݍ��݃G���[.
	 */
	void readFileHeader( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief �r�b�g�}�b�v�t�@�C������ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @retval �Ȃ�.
	 * @throw std::ios::failure �ǂݍ��݃G���[.
	 */
	void readFileInfo( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief �J���[�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @retval �Ȃ�.
	 * @throw std::ios::failure �ǂݍ��݃G���[.
	 */
	void readRGBQuad( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief �C���[�W�T�C�Y�����߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval �C���[�W�T�C�Y.
	 */
	unsigned int calcImageSize();


	/*=========================================================================*/
	/**
	 * @brief �J���[�f�[�^�������߂�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval �J���[�f�[�^��.
	 */
	unsigned int calcColorCount();


	/*=========================================================================*/
	/**
	 * @brief �C���[�W�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @retval �Ȃ�.
	 * @throw std::ios::failure �ǂݍ��݃G���[.
	 */
	void loadImage( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���̃t�B���^����������
	 * 
	 * @param[in] texel �e�N�Z���f�[�^.
	 * @retval �Ȃ�.
	 */
	void setFilter( BYTE* texel );

private:

	/** �s�N�Z���f�[�^�z��^ */
	typedef std::vector< unsigned char >		PixelArray;

	/** �ǂݍ��݊֐��|�C���^�^ */
	typedef SmartPtr< IBMPPixel >				PixelFuncPtr;

	/** �ǂݍ��݊֐����X�g */
	typedef std::map< BitCount, PixelFuncPtr >	PixelFuncList;

private:

	/** �e�N�X�`���t�B���^ */
	ITextureFilter*	filter_;

	/** �s�N�Z���f�[�^�z�� */
	PixelArray		pixelArray_;

	/** BMP�\���� */
	BitMap			bmp_;

	/** �ǂݍ��݊֐����X�g */
	PixelFuncList	pixelFuncList_;

	/** ���݂̃s�N�Z���֐� */
	PixelFuncPtr	pixelFunc_;

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/