/*******************************************************************************/
/**
 * @file FileInputC.cpp.
 * 
 * @brief C�X�^�C���t�@�C�����̓N���X�\�[�X�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FileInputC.h"
#include	"Ngl/Vector2.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Color4.h"
#include	"Ngl/Matrix4.h"
#include	"Ngl/Quaternion.h"
#include	"Ngl/Sphere.h"
#include	<sstream>
#include	<algorithm>
#include	<cstring>
#include	<cassert>

using namespace Ngl;

/*==== �萔�錾 =============================================================*/

const int FileInputC::MAX_BUFFER_SIZE	= 1024;	// �ǂݍ��݃o�b�t�@�T�C�Y

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
FileInputC::FileInputC():
	isFileLoaded_( false ),				// �ǂݍ��ݒ���
	file_( 0 ),							// �t�@�C���\����
	delimiter_( " \n\r\t," ),			// �f���~�^����
	readType_( STREAM_READ_TYPE_10 )	// �t�@�C���ǂݍ��݃^�C�v
{}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �J���t�@�C����.
 * @param[in] flag �ǂݎ��t���O.
 */
FileInputC::FileInputC(std::string fileName ):
	fileName_( fileName ),				// �t�@�C����
	isFileLoaded_( false ),				// �ǂݍ��ݒ���
	file_( 0 ),							// �t�@�C���\����
	delimiter_( " \n\r\t," ),			// �f���~�^����
	readType_( STREAM_READ_TYPE_10 )	// �t�@�C���ǂݍ��݃^�C�v
{
	open( fileName_  );
}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
FileInputC::~FileInputC()
{
	if( isFileLoaded_ == true ){
		// �t�@�C�������
		close();
	}
}



/*===========================================================================*/
/**
 * @brief �t�@�C�����J��
 * 
 * @param[in] fileName �J���t�@�C����.
 * @return �Ȃ�.
 * @throw Ngl::FileOpenException
 */
void FileInputC::open(std::string fileName)
{
	// �t�@�C������ݒ肷��
	fileName_ = fileName;

	// �t�@�C�����J��
	fopen_s( &file_, fileName_.c_str(), "r" );
	
	// �J���Ă��Ȃ���
	if( file_ == 0 ){
		// ��O�𓊂���
		std::string info = "File Open Error" + fileName;
		throw FILE_OPEN_EXCEPTION( info );
	}

	// �t�@�C���ǂݍ��ݏ�Ԃɂ���
	isFileLoaded_ = true;
}



/*===========================================================================*/
/**
 * @brief �t�@�C�������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FileInputC::close()
{
	//�I�u�W�F�N�g���쐬����Ă��邩
	if( file_ != 0 ){
		fclose( file_ );
	}

	// �ǂݍ��݃t���O�𖳌��ɂ���
	isFileLoaded_ = false;
}



/*===========================================================================*/
/**
 * @brief �t�@�C����Open�ł��Ȃ�������
 * 
 * @param[in] �Ȃ�.
 * @retval true �J���Ȃ�����.
 * @retval false �J����.
 */
bool FileInputC::isOpenFailed()
{
	return isFileLoaded_;
}	



/*===========================================================================*/
/**
 * @brief �t�@�C���̃A�N�Z�X�G���[���N���������ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �A�N�Z�X�G���[.
 * @retval false �A�N�Z�X����.
 */
bool FileInputC::isError() const
{
	if( ferror( file_ ) != 0 ){
		return true;
	}
	return false;
}



/*===========================================================================*/
/**
 * @brief �t�@�C�����d�n�e�܂ŒB���������ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true EOF.
 * @retval false �t�@�C���̓r��.
 */
bool FileInputC::isEOF() const
{
	if( feof( file_ ) != 0 ){
		return true;
	}
	return false;
}



/*===========================================================================*/
/**
 * @brief �ǂݔ�΂�������ݒ肷��
 * 
 * @param[in] skipChara �ǂݔ�΂�����.
 * @return �Ȃ�.
 */
void FileInputC::setSkipCharacter(std::string skipChara)
{
	delimiter_ += skipChara;
}



/*===========================================================================*/
/**
 * @brief �s���܂œǂݔ�΂�
 * 
 * @param[in] �Ȃ�.
 * @retval true �ǂݔ�΂�����.
 * @retval false �ǂݔ�΂�������.
 */
bool FileInputC::skipToLineEnd()
{
	// EOF���ǂ���
	while ( feof( file_ ) == 0 ){
		// �G���[��Ԃł��邩�H
		if( ferror( file_ ) != 0 ){
			return	false;
		}
		// ���s�R�[�h�����͂����܂ŃX�L�b�v����
		if( fgetc( file_ ) == '\n' ){
			return	true;
		}
	}
	return	false;
}



/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( char�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( char& data )
{
	try{
		 readTextFile( "%c", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>char]";
		throw e;
	}
}


/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( string�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( std::string& data )
{
	 static std::string readData;	// �ǂݎ��string�^
	 static bool findFlag = false;	// �ǂݔ�΂���

	 char s[ MAX_BUFFER_SIZE ];

	 try{
		readTextFile( "%s", s );
	 }
	 catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>string]";
		throw e;
	 }

	 data = s;
}



/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( short�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( short& data )
{
	try{
		switch( readType_ ){
		// 8�i���ǂݍ���
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10�i���œǂݍ���
		case STREAM_READ_TYPE_10:
			readTextFile( "%hd", &data );
			break;
		default:
			assert( false );
		}
	 }
	 catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>short]";
		throw e;
	 }

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

	 
	 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned short�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( unsigned short& data )
{
	try{
		readTextFile( "%hu", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned short]";
		throw e;
	}

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( int�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( int& data )
{
	try{
		switch( readType_ ){
		// 8�i���ǂݍ���
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10�i���ǂݍ���
		case STREAM_READ_TYPE_10:
			readTextFile( "%d", &data );
			break;
		// 16�i���œǂݍ���
		case STREAM_READ_TYPE_16:
			readTextFile( "%x", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>int]";
		throw e;
	}

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

	 
	 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned int�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( unsigned int& data )
{
	try{
		switch( readType_ ){
		// 8�i���ǂݍ���
		case STREAM_READ_TYPE_8:
			readTextFile( "%o", &data );
			break;
		// 10�i���ǂݍ���
		case STREAM_READ_TYPE_10:
			readTextFile( "%u", &data );
			break;
		// 16�i���œǂݍ���
		case STREAM_READ_TYPE_16:
			readTextFile( "%x", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned int]";
		throw e;
	}

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( long�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( long& data )
{
	try{
		switch( readType_ ){
		// 8�i���ǂݍ���
		case STREAM_READ_TYPE_8:
			readTextFile( "%lo", &data );
			break;
		// 10�i���ǂݍ���
		case STREAM_READ_TYPE_10:
			readTextFile( "%ld", &data );
			break;
		// 16�i���œǂݍ���
		case STREAM_READ_TYPE_16:
			readTextFile( "%lx", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>long]";
		throw e;
	}

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( unsigned long�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( unsigned long& data )
{
	try{
		 switch( readType_ ){
		// 8�i���ǂݍ���
		case STREAM_READ_TYPE_8:
			readTextFile( "%lo", &data );
			break;
		// 10�i���ǂݍ���
		case STREAM_READ_TYPE_10:
			readTextFile( "%lu", &data );
			break;
		// 16�i���œǂݍ���
		case STREAM_READ_TYPE_16:
			readTextFile( "%lx", &data );
			break;
		default:
			assert( false );
		}
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>unsigned long]";
		throw e;
	}

	// 10�i���ǂݍ��݂ɏ�����
	readType_ = STREAM_READ_TYPE_10;
}

 
 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( float�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( float& data )
{
	try{
		readTextFile( "%f", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>float]";
		throw e;
	}
}

 
 
/*=========================================================================*/
/**
 * @brief �f�[�^��ǂݍ��� ( double�^�f�[�^��ǂݍ��� )
 * 
 * @param[out] data �f�[�^��ݒ肷��ϐ�.
 * @return �ǂݍ��񂾃f�[�^.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::read( double& data )
{
	try{
		readTextFile( "%lf", &data );
	}
	catch( Ngl::FileReadException& e ){
		e += "[FileInputC] : [operator>>double]";
		throw e;
	}
}

	
	

/*=========================================================================*/
/**
 * @brief �w��o�C�g�����ǂݍ���
 * 
 * @param[in] dest �ǂݍ��񂾃f�[�^���i�[����f�[�^.
 * @param[in] size �ǂݍ��ރT�C�Y.
 * @return �Ȃ�.
 */
void FileInputC::read( char* dest, unsigned int size )
{
	fread( dest, size, 1, file_ );
}



/*=========================================================================*/
/**
 * @brief �w��ʒu�ɃV�[�N����
 * 
 * @param[in] offset �ړ�����ʒu.
 * @param[in] flag �V�[�N�t���O.
 * @return �Ȃ�.
 */
void FileInputC::seek( unsigned int offset, SeekFlug flag )
{
	int cflag = SEEK_SET;
	switch( flag )
	{
	case SEEKFLUG_BEG:
		cflag = SEEK_SET;
		break;
	case SEEKFLUG_CUR:
		cflag = SEEK_CUR;
		break;
	case SEEKFLUG_END:
		cflag = SEEK_END;
		break;
	}

	fseek( file_, offset, cflag );
}

	
	
/*=========================================================================*/
/**
 * @brief ���݈ʒu���擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���݈ʒu�̃o�C�g��.
 */
unsigned int FileInputC::tell()
{
	unsigned int size = ftell( file_ );

	// �G���[�����邩
	if( isError() == true ){
		throw FILE_READ_EXCEPTION( "tell Error" );
	}

	return size;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �X�g���[�������擾����
 * 
 * @param[in] �Ȃ�.
 * @return �X�g���[����.
 */
const std::string& FileInputC::streamName() const
{
	 return fileName_;
}
	 


/*=========================================================================*/
/**
 * @brief �X�g���[���ǂݍ��݃^�C�v���擾����
 * 
 * @param[out] �Ȃ�.
 * @return �X�g���[���^�C�v.
 */
StreamReadType FileInputC::readType()
{
	return readType_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^�p )
 * 
 * @param[out] func �}�j�s�����[�^�̊֐��|�C���^.
 * @return ���̓X�g���[���̎Q��.
 */
IInputStream& FileInputC::operator >> ( IInputStream& (*func)(IInputStream&) )
{
	return (*func)(*this);
}

	
	
/*=========================================================================*/
/**
 * @brief �X�g���[���ǂݍ��݃^�C�v��ݒ肷��
 * 
 * @param[out] type �ݒ肷��ǂݍ��݃^�C�v.
 * @return �Ȃ�.
 */
void FileInputC::readType( StreamReadType type )
{
	readType_ = type;
}



/*===========================================================================*/
/**
 * @brief �e�L�X�g�t�@�C������f�[�^��ǂݎ��
 * 
 * @param[in] format �ǂݎ��`��.
 * @param[in] input �ǂݍ��񂾃f�[�^��ۑ�����f�[�^.
 * @retval true �ǂݎ�萬��.
 * @retval false �ǂݎ�莸�s.
 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
 */
void FileInputC::readTextFile(const char *format, void *input)
{
	char buffer[ MAX_BUFFER_SIZE ];

	// �������ǂݍ���
	if( readBuffer( buffer ) == false ){
		std::string info;
		info = "File Read Error!!" + fileName_;
		throw FileReadException( info, "FileInputC", "readTextFile" );
	}

	// �w��̃t�H�[�}�b�g�ɕϊ�����
	if( sscanf( buffer, format, input ) == 0 ){
		std::stringstream info;
		std::string fm = format;
		info << "Format Convert Error!!" << fm << fileName_;
		throw FileReadException( info.str(), "FileInputC", "readTextFile" );
	}
}



/*===========================================================================*/
/**
 * @brief �o�b�t�@��ǂݎ��
 * 
 * @param[in] buf �ǂݍ��񂾃o�b�t�@��ۑ�����f�[�^.
 * @retval true �ǂݎ�萬��.
 * @retval false �ǂݎ�莸�s.
 */
bool FileInputC::readBuffer(char *buf)
{
	// �G���[��Ԃ�
	if( isError() == true ){
		return false;
	}

	// EOF��
	if( isEOF() == true ){
		return false;
	}

	char	c;	// �ǂݎ�蕶��

	// �f���~�^�������X�L�b�v
	if( readSkipDelimiter( &c ) == false ){
		return false;
	}

	*buf++ = c;

	// �f���~�^�܂œǂݎ��
	int		ic		= 0;	// �ǂݎ��������
	bool	success = true;	// �ǂݎ��t���O
	while( true ){
		// 1�����ǂݍ���
		ic = fgetc( file_ );
		
		// EOF��
		if( isEOF() == true ){
			success = true;
			break;
		}

		// �G���[��
		if( isError() == true ){
			success = false;
			break;
		}

		// �f���~�^������
		if( isDelimiter( ic ) == true ){
			success = true;
			break;
		}

		*buf++ = (char)ic;
	}
	*buf = '\0';

	// ���ʂ�Ԃ�
	return success;
}



/*===========================================================================*/
/**
 * @brief �f���~�^�����ƃR�����g�������X�L�b�v����1�����ǂݎ��
 * 
 * @param[in] buf �ǂݍ��񂾕�����ۑ�����f�[�^.
 * @retval true �ǂݎ�萬��.
 * @retval false �ǂݎ�莸�s.
 */
bool FileInputC::readSkipDelimiter(char *buf)
{
	int	c = 0;				// �ǂݎ��������
	bool success = true;	// �ǂݎ��t���O

	// �f���~�^�������X�L�b�v
	do{
		// 1�����ǂݎ��
		c = fgetc( file_ );
		
		// EOF��
		if( isEOF() == true ){
			success = true;
			break;
		}

		// �G���[���ǂ���
		if( isError() == true ){
			success = false;
			break;
		}

		// �R�����g�����邩
		if( c == '#' ){
			// �R�����g�s�͍s���܂ŃX�L�b�v
			skipToLineEnd();

			c = '\n';
		}
	}while( isDelimiter( c ) == true );

	// EOF�܂��̓G���[��
	if( isEOF() == true || isError() == true ){
		return false;
	}

	*buf = (char)c;

	return true;
}



/*========= EOF =============================================================*/