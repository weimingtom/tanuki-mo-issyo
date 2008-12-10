/*******************************************************************************/
/**
 * @file BMPFile.cpp.
 * 
 * @brief BMP �r�b�g�}�b�v�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/BMP/BMPFile.h"
#include	"Ngl/BMP/DefaultBMPPixel2Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel4Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel8Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel24Bit.h"
#include	"Ngl/BMP/DefaultBMPPixel32Bit.h"
#include	"Ngl/FileInputBinary.h"
#include	"Ngl/MathUtility.h"
#include	"Ngl/ITextureFilter.h"
#include	<memory>
#include	<iostream>

using namespace Ngl;
using namespace Ngl::BMP;

/*==== �֐��̃v���g�^�C�v�錾 ===============================================*/

/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C���̕��̃o�C�g�������߂�
 * 
 * @param[in] width �r�b�g�}�b�v��.
 * @param[in] bits �r�b�g��.
 * @return �r�b�g�}�b�v�t�@�C���̕��̃o�C�g��.
 */
unsigned int calcBmpWidthSize( unsigned int width, unsigned int bits );


/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C���̕��̃p�f�B���O�l�����߂�br>
 * 
 * @param[in] width �r�b�g�}�b�v��.
 * @param[in] bits �r�b�g��.
 * @return �r�b�g�}�b�v�t�@�C���̕��̃p�f�B���O�l.
 */
unsigned int calcWidthPadding( unsigned int width, unsigned int bits );


/*==== �֐���` =============================================================*/

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
BMPFile::BMPFile():
	filter_( 0 )
{
	// �f�t�H���g�̃s�N�Z��������o�^
	setDefaultPixelFunc();
}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �t�@�C����.
 */
BMPFile::BMPFile( const char* fileName ):
	filter_( 0 )
{
	// �f�t�H���g�̃s�N�Z��������o�^
	setDefaultPixelFunc();

	// �t�@�C����ǂݍ���
	loadFromFile( fileName );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
BMPFile::~BMPFile()
{}



/*=========================================================================*/
/**
 * @brief �摜�t�@�C������f�[�^��ǂݍ���
 * 
 * @param[in] fileName �t�@�C����.
 * @return �Ȃ�.
 */
void BMPFile::loadFromFile( const char* fileName )
{
	FileInputBinary stream;

	// �t�@�C�����J��
	try{
		stream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "BMPFile", "loadFromFile" );
		e.outputConsol();
	}

	// �f�[�^��ǂݍ���
	loadFromStream( stream );
}



/*=========================================================================*/
/**
* @brief ���̓X�g���[������f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �Ȃ�.
 */
void BMPFile::loadFromStream( IInputStream& stream )
{
	// �r�b�g�}�b�v�t�@�C���w�b�_��ǂݍ���
	try{
		readFileHeader( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// �r�b�g�}�b�v����ǂݍ���
	try{
		readFileInfo( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// �C���[�W�T�C�Y�����߂�
	bmp_.infoHeader.biSizeImage = calcImageSize();

	// �J���[�f�[�^��ǂݍ���
	try{
		readRGBQuad( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}

	// �C���[�W�f�[�^��ǂݍ���
	try{
		loadImage( stream );
	}
	catch( Ngl::InputStreamException& e ){
		e.add( "BMPFile", "loadFromStream" );
		e.outputConsol();
		return;
	}
}
	
	
	
/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v���\���̂��擾
 * 
 * @param[in] �Ȃ�.
 * @return �r�b�g�}�b�v���\����.
 */
const BitMapInfoHeader& BMPFile::desc()
{
	return bmp_.infoHeader;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �f�[�^�T�C�Y���擾
 * 
 * @param[in] �Ȃ�.
 * @return �f�[�^�T�C�Y.
 */
unsigned int BMPFile::size() const
{
	return static_cast< unsigned int >( pixelArray_.size() );
}



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
void BMPFile::setBMPPixel( IBMPPixel* pixel, BitCount bitCount )
{
	pixelFuncList_[ bitCount ] = PixelFuncPtr( pixel );
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
void BMPFile::setFilter( ITextureFilter* filter )
{
	filter_ = filter;
}

	
	
/*=========================================================================*/
/**
 * purpose [] ���Z�q�I�[�o�[���[�h: 
 * 
 * �s�N�Z���f�[�^���擾����.
 *
 * @param[in] index �擾����f�[�^�̃C���f�b�N�X�ԍ�.
 * @return �s�N�Z���f�[�^�z��̎Q��.
 */
unsigned char& BMPFile::operator[] ( unsigned int index )
{
	return pixelArray_[ index ];
}



/*=========================================================================*/
/**
 * @brief �f�t�H���g�̃s�N�Z�������N���X��o�^
 * 
 * @param[in] �Ȃ�.
 * @retval �Ȃ�.
 */
void BMPFile::setDefaultPixelFunc()
{
	// �f�t�H���g�̊֐����쐬
	pixelFuncList_[ BITCOUNT_2 ]	= PixelFuncPtr( new DefaultBMPPixel2Bit() );
	pixelFuncList_[ BITCOUNT_4 ]	= PixelFuncPtr( new DefaultBMPPixel4Bit() );
	pixelFuncList_[ BITCOUNT_8 ]	= PixelFuncPtr( new DefaultBMPPixel8Bit() );
	pixelFuncList_[ BITCOUNT_24 ]	= PixelFuncPtr( new DefaultBMPPixel24Bit() );
	pixelFuncList_[ BITCOUNT_32 ]	= PixelFuncPtr( new DefaultBMPPixel32Bit() );

}
	
	
	
/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C���w�b�_��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @retval �Ȃ�.
 * @throw std::ios::failure �ǂݍ��݃G���[.
 */
void BMPFile::readFileHeader( IInputStream& stream )
{
	try{
		stream >> bmp_.fileHeader.bfType;
		stream >> bmp_.fileHeader.bfSize;
		stream >> bmp_.fileHeader.bfReserved1;
		stream >> bmp_.fileHeader.bfReserved2; 
		stream >> bmp_.fileHeader.bfOffBits;
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readFileHeader" );
		throw e;
	}

	// �r�b�g�}�b�v�t�@�C���ł͂Ȃ���
	if( bmp_.fileHeader.bfType != BITMAPFLAG ){
		throw InputStreamException( "Is Not BitmapFile", "BMPFile", "readFileHeader" );
	}
}


	
/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C������ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @retval �Ȃ�.
 * @throw std::ios::failure �ǂݍ��݃G���[.
 */
void BMPFile::readFileInfo( IInputStream& stream )
{
	try{
		stream >> bmp_.infoHeader.biSize;		
		stream >> bmp_.infoHeader.biWidth;		
		stream >> bmp_.infoHeader.biHeight;		
		stream >> bmp_.infoHeader.biPlanes;		
		stream >> bmp_.infoHeader.biBitCount;	
		stream >> bmp_.infoHeader.biCompression;
		stream >> bmp_.infoHeader.biSizeImage;	
		stream >> bmp_.infoHeader.biXPelsPerMeter; 
		stream >> bmp_.infoHeader.biYPelsPerMeter;
		stream >> bmp_.infoHeader.biClrUsed;		
		stream >> bmp_.infoHeader.biClrImportant;
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readFileInfo" );
		throw e;
	}

}

	 
	 
/*=========================================================================*/
/**
 * @brief �J���[�f�[�^��ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @retval �Ȃ�.
 * @throw std::ios::failure �ǂݍ��݃G���[.
 */
void BMPFile::readRGBQuad( IInputStream& stream )
{
	// �J���[�f�[�^�����擾
	unsigned int ncolor = calcColorCount();

	// �J���[�f�[�^�����݂��Ȃ�
	if ( ncolor == 0 ){
		return;
	}

	try{
		for( unsigned int i=0; i<ncolor; ++i ){
			stream.read( reinterpret_cast< char* >( &bmp_.rgbQuad[ i ] ), sizeof( RGBQuad ) );
		}
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "readRGBQuad" );
		throw e;
	}

}

	 
	 
/*=========================================================================*/
/**
 * @brief �C���[�W�T�C�Y�����߂�
 * 
 * @param[in] �Ȃ�.
 * @retval �C���[�W�T�C�Y.
 */
unsigned int BMPFile::calcImageSize()
{
	// ���������̏ꍇ�͐�����
	int height = bmp_.infoHeader.biHeight;
	height = ( height < 0 ) ? -height: height;

	// ���ƍ������|��������ƃo�C�g���ɂȂ�
	return	calcBmpWidthSize( bmp_.infoHeader.biWidth, bmp_.infoHeader.biBitCount ) * height;
}
	 
	 
	 
/*=========================================================================*/
/**
 * @brief �J���[�f�[�^�������߂�
 * 
 * @param[in] �Ȃ�.
 * @retval �J���[�f�[�^��.
 */
unsigned int BMPFile::calcColorCount()
{
	unsigned int ncolor = 0;	// �J���[��
	
	// �r�b�g�J�E���g��8�ȉ���
	if ( bmp_.infoHeader.biBitCount <= 8 ){
		// �J���[�e�[�u���̃f�[�^�����w�肳��Ă��Ȃ���
		if ( bmp_.infoHeader.biClrUsed == 0 ){
			// �f�[�^�������߂�
			ncolor = 1 << bmp_.infoHeader.biBitCount;
		}
		else{
			// �w�肳��Đ�����
			ncolor = bmp_.infoHeader.biClrUsed;
		}
	}

	return	ncolor;
}
	 
	 
	 
/*=========================================================================*/
/**
 * @brief �C���[�W�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @retval �Ȃ�.
 * @throw std::ios::failure �ǂݍ��݃G���[.
 */
void BMPFile::loadImage( IInputStream& stream )
{
	try{
		// �C���[�W�f�[�^�܂ŃV�[�N����
		stream.seek( bmp_.fileHeader.bfOffBits, SEEKFLUG_BEG );

		// �����̐�Βl�����߂�
		LONG height = Ngl::abs( bmp_.infoHeader.biHeight );
		
		// �s�N�Z���T�C�Y��ݒ�
		pixelArray_.resize( sizeof( DWORD ) * height * bmp_.infoHeader.biWidth );

		// ���̃p�f�B���O�l�����߂�
		LONG pad = calcWidthPadding( bmp_.infoHeader.biWidth, bmp_.infoHeader.biBitCount );

		// �s�N�Z����ǂݍ��ފ֐���ݒ�
		pixelFunc_ = pixelFuncList_[ (BitCount)bmp_.infoHeader.biBitCount ];

		// for each �r�b�g�}�b�v�̍���
		for ( LONG y = 0; y < height; y++ ){
			// �e�N�Z�����擾
			unsigned char* texel = &pixelArray_[ ( height-1 - y ) * bmp_.infoHeader.biWidth * 4 ];

			// for each �r�b�g�}�b�v�̕�
			for ( LONG x = 0; x < bmp_.infoHeader.biWidth; x++ ){
				// �s�N�Z���f�[�^��ݒ肷��
				(*pixelFunc_)( texel, stream, bmp_, x, y );

				// �t�B���^����������
				setFilter( texel );

				// ���̃e�N�Z���ֈړ�
				texel += 4;
			}
			// �p�f�B���O�����X�L�b�v����
			stream.seek( pad, SEEKFLUG_CUR );
		}
	}
	catch( InputStreamException& e ){
		e.add( "BMPFile", "loadImage" );
		throw e;
	}

}
	
	
	
/*=========================================================================*/
/**
 * @brief �e�N�X�`���̃t�B���^����������
 * 
 * @param[in] texel �e�N�Z���f�[�^.
 * @retval �Ȃ�.
 */
void BMPFile::setFilter( BYTE* texel )
{
	if( filter_ == 0 ){
		return;
	}

	// �e�N�Z������������
	(*filter_)( texel );
}

	
	
/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C���̕��̃o�C�g�������߂�
 * 
 * @param[in] width �r�b�g�}�b�v��.
 * @param[in] bits �r�b�g��.
 * @return �r�b�g�}�b�v�t�@�C���̕��̃o�C�g��.
 */
unsigned int calcBmpWidthSize( unsigned int width, unsigned int bits )
{
	return ( (width)*(bits) + ( ( 32 - (width)*(bits) ) & 0x01f ) ) >> 3;
}



/*=========================================================================*/
/**
 * @brief �r�b�g�}�b�v�t�@�C���̕��̃p�f�B���O�l�����߂�br>
 * 
 * @param[in] width �r�b�g�}�b�v��.
 * @param[in] bits �r�b�g��.
 * @return �r�b�g�}�b�v�t�@�C���̕��̃p�f�B���O�l.
 */
unsigned int calcWidthPadding( unsigned int width, unsigned int bits )
{
	return ( 32 - ( width * bits ) & 0x01f ) >> 3;
}



/*===== EOF ==================================================================*/