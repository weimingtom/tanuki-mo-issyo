/*******************************************************************************/
/**
 * @file FileInputC.h.
 * 
 * @brief C�X�^�C���t�@�C�����̓N���X�w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FILE_INPUT_C_H_
#define _NGL_FILE_INPUT_C_H_

#include	"IInputStream.h"
#include	<string>
#include	<cstdio>

namespace Ngl{


/**
 * @class FileInputC.
 * @brief C�X�^�C���t�@�C�����̓N���X�D
 *
 * C����̃t�@�C�����͊֐����g�p�����N���X�ł��B<br>
 * �A�X�L�[�`���̃e�L�X�g�t�@�C����ǂݍ��ނ��Ƃ��ł��܂��B<br>
 * (�o�C�i���t�@�C���ǂݍ��ݔ�Ή�)<br>
 * '#'�̕������R�����g�����Ƃ��ĔF�����܂��B<br>
 * �w��̃f���~�^�����Ńg�[�N���������s���܂��B<br>
 */
class FileInputC : public IInputStream
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	FileInputC();
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �J���t�@�C����.
	 */
	FileInputC( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~FileInputC();

	
	/*=========================================================================*/
	/**
	 * @brief �t�@�C�����J��
	 * 
	 * @param[in] fileName �J���t�@�C����.
	 * @return �Ȃ�.
	 * @throw Ngl::FileOpenException �t�@�C���I�[�v����O.
	 */
	void open( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief �t�@�C�������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void close();
		 
		 
	/*=========================================================================*/
	/**
	 * @brief �t�@�C����Open�ł��Ȃ�������
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �J���Ȃ�����.
	 * @retval false �J����.
	 */
	bool isOpenFailed();
		
	
	/*=========================================================================*/
	/**
	 * @brief �t�@�C���̃A�N�Z�X�G���[���N���������ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �A�N�Z�X�G���[.
	 * @retval false �A�N�Z�X����.
	 */
	 bool isError() const;


	/*=========================================================================*/
	/**
	 * @brief �t�@�C�����d�n�e�܂ŒB���������ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true EOF.
	 * @retval false �t�@�C���̓r��.
	 */
	 bool isEOF() const;


	/*=========================================================================*/
	/**
	 * @brief �ǂݔ�΂�������ݒ肷��
	 * 
	 * @param[in] skipChara �ǂݔ�΂�����.
	 * @return �Ȃ�.
	 */
	 void setSkipCharacter( std::string skipChara );

	 
	/*=========================================================================*/
	/**
	 * @brief �s���܂œǂݔ�΂�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �ǂݔ�΂�����.
	 * @retval false �ǂݔ�΂�������.
	 */
	 bool skipToLineEnd();
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( char�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( char& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( string�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( std::string& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( short�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( short& data );
		 
		 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned short�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned short& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( int�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( int& data );
		 
		 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned int�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned int& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( long�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( long& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned long�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned long& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( float�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( float& data );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( double�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	virtual void read( double& data );


	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^�p )
	 * 
	 * @param[out] func �}�j�s�����[�^�̊֐��|�C���^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	virtual IInputStream& operator >> ( IInputStream& (*func)(IInputStream&) );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��o�C�g�����ǂݍ���
	 * 
	 * @param[in] dest �ǂݍ��񂾃f�[�^���i�[����f�[�^.
	 * @param[in] size �ǂݍ��ރT�C�Y.
	 * @return �Ȃ�.
	 */
	virtual void read( char* dest, unsigned int size );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��ʒu�ɃV�[�N����
	 * 
	 * @param[in] offset �ړ�����ʒu.
	 * @param[in] flag �V�[�N�t���O.
	 * @return �Ȃ�.
	 */
	virtual void seek( unsigned int offset, SeekFlug flag );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���݈ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���݈ʒu�̃o�C�g��.
	 */
	virtual unsigned int tell();
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���ǂݍ��݃^�C�v��ݒ肷��
	 * 
	 * @param[out] type �ݒ肷��ǂݍ��݃^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void readType( StreamReadType type ); 
	

	/*=========================================================================*/
	/**
	 * @brief �X�g���[���ǂݍ��݃^�C�v���擾����
	 * 
	 * @param[out] �Ȃ�.
	 * @return �X�g���[���^�C�v.
	 */
	virtual StreamReadType readType(); 


	/*=========================================================================*/
	/**
	 * @brief �X�g���[�������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �X�g���[����.
	 */
	virtual  const std::string& streamName() const;

private:

	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g�t�@�C������f�[�^��ǂݎ��
	 * 
	 * @param[in] format �ǂݎ��`��.
	 * @param[in] input �ǂݍ��񂾃f�[�^��ۑ�����f�[�^.
	 * @retval true �ǂݎ�萬��.
	 * @retval false �ǂݎ�莸�s.
	 * @throw Ngl::FileReadException �t�@�C���ǂݍ��ݗ�O.
	 */
	void readTextFile( const char* format, void* input );


	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@��ǂݎ��
	 * 
	 * @param[in] buf �ǂݍ��񂾃o�b�t�@��ۑ�����f�[�^.
	 * @return true �ǂݎ�萬��.
	 * @retval false �ǂݎ�莸�s.
	 */
	bool readBuffer( char* buf );


	/*=========================================================================*/
	/**
	 * @brief �f���~�^�����ƃR�����g�������X�L�b�v����1�����ǂݎ��
	 * 
	 * @param[in] buf �ǂݍ��񂾕�����ۑ�����f�[�^.
	 * @retval true �ǂݎ�萬��.
	 * @retval false �ǂݎ�莸�s.
	 */
	bool readSkipDelimiter( char* buf );


	/*=========================================================================*/
	/**
	 * @brief �f���~�^���������肷��
	 * 
	 * @param[in] c ���肷�镶��.
	 * @retval true �f���~�^����������.
	 * @retval false �f���~�^��������Ȃ�����.
	 */
	inline bool isDelimiter( int c )
	{
		bool tmp;
		( strchr( delimiter_.c_str(), c ) != 0 ) ? tmp=true : tmp=false;
		return tmp;
	}

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	FileInputC( const FileInputC& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h(�R�s�[�֎~����)
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	FileInputC& operator = ( const FileInputC& other );

private:

	/** �ǂݍ��݃o�b�t�@�T�C�Y */
	const static int MAX_BUFFER_SIZE;

private:

	/** �ǂݍ��ݒ��̃t�@�C���� */
	std::string				fileName_;

	/** �ǂݎ�蒆�� */
	bool					isFileLoaded_;

	/** �t�@�C���\���� */
	FILE*					file_;

	/** �f���~�^���� */
	std::string				delimiter_;

	/** �t�@�C���ǂݍ��݃^�C�v */
	StreamReadType			readType_;						

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/