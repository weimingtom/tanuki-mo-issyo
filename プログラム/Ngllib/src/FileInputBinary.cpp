/*******************************************************************************/
/**
 * @file FileInputBinary.cpp.
 * 
 * @brief �o�C�i���t�@�C�����̓N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FileInputBinary.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
FileInputBinary::FileInputBinary()
{}


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �J���t�@�C����.
 */
FileInputBinary::FileInputBinary( const std::string& fileName )
{
	open( fileName );
}



/*=========================================================================*/
/**
 * @brief �t�@�C�����J��
 * 
 * @param[in] fileName �J���t�@�C����.
 * @return �Ȃ�.
 * @throw Ngl::FileOpenEception �t�@�C���I�[�v����O.
 */
void FileInputBinary::open( const std::string& fileName )
{
	// �t�@�C������ۑ�
	fileName_ = fileName;

	// ��O��L���ɂ���
	ifStream_.exceptions( std::ifstream::eofbit | std::ifstream::failbit | std::ifstream::badbit );
	
	try{
		ifStream_.open( fileName.c_str(), std::ios::in | std::ios::binary );
	}
	catch( std::ios::failure& e ){
		throw Ngl::FileOpenException( e.what() );
	}
}



/*=========================================================================*/
/**
 * @brief �t�@�C�������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FileInputBinary::close()
{
	ifStream_.close();
}



/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( char�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( char& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( char ) );
}



/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( string�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( std::string& data )
{
}



/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( short�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( short& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( short ) );
}

	 
	 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned short�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( unsigned short& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned short ) );
}


 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( int�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( int& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( data ) );
}


	 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned int�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( unsigned int& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned int ) );
}


 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( long�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( long& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( long ) );
}


 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned long�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( unsigned long& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( unsigned long ) );
}


 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( float�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( float& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( float ) );
}

 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( double�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputBinary::read( double& data )
{
	ifStream_.read( reinterpret_cast< char* >( &data ), sizeof( double ) );
}


/*=========================================================================*/
/**
 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^�p )
 * 
 * @param[out] func �}�j�s�����[�^�̊֐��|�C���^.
 * @return ���̓X�g���[���̎Q��.
 */
IInputStream& FileInputBinary::operator >> ( IInputStream& (*func)(IInputStream&) )
{
	return (*func)(*this);
}



/*=========================================================================*/
/**
 * @brief �w��o�C�g�����ǂݍ���
 * 
 * @param[in] dest �ǂݍ��񂾃f�[�^���i�[����f�[�^.
 * @param[in] size �ǂݍ��ރT�C�Y.
 * @return �Ȃ�.
 */
void FileInputBinary::read( char* dest, unsigned int size )
{
	ifStream_.read( dest, size );
}



/*=========================================================================*/
/**
 * @brief �w��ʒu�ɃV�[�N����
 * 
 * @param[in] offset �ړ�����ʒu.
 * @param[in] flag �V�[�N�t���O.
 * @return �Ȃ�.
 */
void FileInputBinary::seek( unsigned int offset, SeekFlug flag )
{
	std::ios_base::seek_dir way = std::ios::beg;
	switch( flag )
	{
	case SEEKFLUG_BEG:
		way = std::ios::beg;
		break;
	case SEEKFLUG_CUR:
		way = std::ios::cur;
		break;
	case SEEKFLUG_END:
		way = std::ios::end;
		break;
	}
	ifStream_.seekg( offset, way );
}



/*=========================================================================*/
/**
 * @brief ���݈ʒu���擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���݈ʒu�̃o�C�g��.
 */
unsigned int FileInputBinary::tell()
{
	return ifStream_.tellg();
}



/*=========================================================================*/
/**
 * @brief �X�g���[���ǂݍ��݃^�C�v��ݒ肷��
 * 
 * @param[out] type �ݒ肷��ǂݍ��݃^�C�v.
 * @return �Ȃ�.
 */
void FileInputBinary::readType( StreamReadType type )
{
	readType_ = type;
}



/*=========================================================================*/
/**
 * @brief �X�g���[���ǂݍ��݃^�C�v���擾����
 * 
 * @param[out] �Ȃ�.
 * @return �X�g���[���^�C�v.
 */
StreamReadType FileInputBinary::readType()
{
	return readType_;
}



/*=========================================================================*/
/**
 * @brief �X�g���[�������擾����
 * 
 * @param[in] �Ȃ�.
 * @return �X�g���[����.
 */
const std::string& FileInputBinary::streamName() const
{
	return fileName_;
}



/*===== EOF ==================================================================*/