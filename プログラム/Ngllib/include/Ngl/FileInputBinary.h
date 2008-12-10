/*******************************************************************************/
/**
 * @file FileInputBinary.h.
 * 
 * @brief �o�C�i���t�@�C�����̓N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FILEINPUTBINARY_H_
#define _NGL_FILEINPUTBINARY_H_

#include	"IInputStream.h"
#include	<fstream>

namespace Ngl{


/**
 * @class FileInputBinary�D
 * @brief �o�C�i���t�@�C�����̓N���X.
 *
 * ���g���G���f�B�A�������istd::fstream) �Ńo�C�i���f�[�^��ǂݍ��݂܂�.
 */
class FileInputBinary : public IInputStream
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	FileInputBinary();
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �J���t�@�C����.
	 */
	FileInputBinary( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief �t�@�C�����J��
	 * 
	 * @param[in] fileName �J���t�@�C����.
	 * @return �Ȃ�.
	 * @throw Ngl::FileOpenEception �t�@�C���I�[�v����O.
	 */
	void open( const std::string& fileName );


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

	// �t�@�C�����̓X�g���[��
	std::ifstream	ifStream_;

	/** �t�@�C���ǂݍ��݃^�C�v */
	StreamReadType	readType_;	

	// �t�@�C����
	std::string		fileName_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/