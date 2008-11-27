/*******************************************************************************/
/**
 * @file IInputStream.h.
 * 
 * @brief ���̓X�g���[���C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IINPUTSTREAM_H_
#define _NGL_IINPUTSTREAM_H_

#include	"Exception.h"

namespace Ngl{


/**
 * @enum StreamReadType.
 * @brief �X�g���[���ǂݍ��݃^�C�v�񋓌^.
 */
enum StreamReadType
{
	STREAM_READ_TYPE_8	= 0,	/**< 8�i���ǂݍ���	*/
	STREAM_READ_TYPE_10,		/**< 10�i���ǂݍ���	*/
	STREAM_READ_TYPE_16			/**< 16�i���ǂݍ���	*/
};


/**
 * @enum SeekFlug.
 * @brief �t�@�C���̃V�[�N�ʒu�t���O�񋓌^.
 */
enum SeekFlug
{
	SEEKFLUG_BEG	= 0,	/**< �擪		*/
	SEEKFLUG_CUR,			/**< ���݈ʒu	*/
	SEEKFLUG_END			/**< ����		*/
};


/**
 * @interface IInputStream�D
 * @brief ���̓X�g���[���C���^�[�t�F�[�X.
 */
class IInputStream
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IInputStream() {}


	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( char�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( char& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( string�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( std::string& data ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( short�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( short& data ) = 0;
		 
		 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned short�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned short& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( int�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( int& data ) = 0;
		 
		 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned int�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned int& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( long�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( long& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( unsigned long�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( unsigned long& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( float�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( float& data ) = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �f�[�^��ǂݍ��� ( double�^�f�[�^��ǂݍ��� )
	 * 
	 * @param[out] data �f�[�^��ݒ肷��ϐ�.
	 * @return �ǂݍ��񂾃f�[�^.
	 * @throw Ngl::InputStreamException �ǂݍ��ݗ�O.
	 */
	virtual void read( double& data ) = 0;


	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^�p )
	 * 
	 * @param[out] func �}�j�s�����[�^�̊֐��|�C���^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	virtual IInputStream& operator >> ( IInputStream& (*func)(IInputStream&) ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��o�C�g�����ǂݍ���
	 * 
	 * @param[in] dest �ǂݍ��񂾃f�[�^���i�[����f�[�^.
	 * @param[in] size �ǂݍ��ރT�C�Y.
	 * @return �Ȃ�.
	 */
	virtual void read( char* dest, unsigned int size ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��ʒu�ɃV�[�N����
	 * 
	 * @param[in] offset �ړ�����ʒu.
	 * @param[in] flag �V�[�N�t���O.
	 * @return �Ȃ�.
	 */
	virtual void seek( unsigned int offset, SeekFlug flag ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���݈ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���݈ʒu�̃o�C�g��.
	 */
	virtual unsigned int tell() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���ǂݍ��݃^�C�v��ݒ肷��
	 * 
	 * @param[out] type �ݒ肷��ǂݍ��݃^�C�v.
	 * @return �Ȃ�.
	 */
	virtual void readType( StreamReadType type ) = 0; 
	

	/*=========================================================================*/
	/**
	 * @brief �X�g���[���ǂݍ��݃^�C�v���擾����
	 * 
	 * @param[out] �Ȃ�.
	 * @return �X�g���[���^�C�v.
	 */
	virtual StreamReadType readType() = 0;


	/*=========================================================================*/
	/**
	 * @brief �X�g���[�������擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �X�g���[����.
	 */
	virtual  const std::string& streamName() const = 0;


	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] value ���͂���f�[�^.
	 * @return ���͌�̃X�g���[��.
	 */
	template< class Value >
	void operator >> ( Value& value )
	{
		read( value );
	}

};

} // namespace Ngl


#endif

/*===== EOF ==================================================================*/