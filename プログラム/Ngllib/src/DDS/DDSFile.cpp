/*******************************************************************************/
/**
 * @file DDSFile.cpp.
 * 
 * @brief DDS�t�H�[�}�b�g�摜�t�@�C���ǂݍ��݃N���X�\�[�X�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.10.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DDS/DDSFile.h"
#include	"Ngl/FileInputBinary.h"
#include	"Ngl/ITextureFilter.h"
#include	<memory>

using namespace Ngl;
using namespace Ngl::DDS;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
DDSFile::DDSFile():
	filter_( 0 )
{}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �t�@�C����.
 */
DDSFile::DDSFile( const char* fileName ):
	filter_( 0 )
{
	loadFromFile( fileName );
}



/*=========================================================================*/
/**
 * @brief �摜�t�@�C������f�[�^��ǂݍ���
 * 
 * @param[in] fileName �t�@�C����.
 * @return �Ȃ�.
 */
void DDSFile::loadFromFile( const char* fileName )
{
	FileInputBinary ifStream;
	try{
		ifStream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "DDSFile", "loadFromFile" );
	}

	loadFromStream( ifStream );
}



/*=========================================================================*/
/**
 * @brief ���̓X�g���[������f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �Ȃ�.
 */
void DDSFile::loadFromStream( IInputStream& stream )
{	
	try{
		// �t�@�C���T�C�Y�����߂�
		stream.seek( 0, SEEKFLUG_END );
		DWORD fileSize = stream.tell();
		stream.seek( 0, SEEKFLUG_BEG );

		// �}�W�b�N�i���o�[�̓ǂݍ���
		DWORD magicNumber = 0;
		stream.read( reinterpret_cast< char* >( &magicNumber ), sizeof( DWORD ) );
		if( magicNumber != DDS_MAGIC_NUMBER ){
			throw FileReadException( "Is Not DDSFile", "DDSFile", "loadFromStream" );
		}

		// �L�q�q�̓ǂݍ���
		stream.read( reinterpret_cast< char* >( &desc_ ), sizeof( SurfaceDesc ) );

		// �T�[�t�F�[�X�f�[�^�̓ǂݍ���
		surface_.resize( fileSize - sizeof( DWORD ) - sizeof( SurfaceDesc ) );
		stream.read( reinterpret_cast< char* >( &surface_[0] ), (std::streamsize)surface_.size() );

		// �t�B���^������������
		if( filter_ != 0 ){
			for( unsigned int i=0; i<surface_.size(); i+=4 ){
				(*filter_)( static_cast< unsigned char* >( &surface_[ i ] ) );
			}
		}
	}
	catch( InputStreamException& e ){
		e.add( "DDSFile", "loadFromStream" );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief �T�[�t�F�[�X�L�q�q���擾
 * 
 * @param[in] �Ȃ�.
 * @return �T�[�t�F�[�X�L�q�q�̎Q��.
 */
const DDSFile::SurfaceDesc& DDSFile::desc()
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief �f�[�^�T�C�Y���擾
 * 
 * @param[in] �Ȃ�.
 * @return �f�[�^�T�C�Y.
 */
unsigned int DDSFile::size() const
{
	return ( unsigned int )surface_.size();
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
void DDSFile::setFilter( ITextureFilter* filter )
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
DDSFile::BYTE& DDSFile::operator[] ( unsigned int index )
{
	return surface_[ index ];
}



/*===== EOF ==================================================================*/