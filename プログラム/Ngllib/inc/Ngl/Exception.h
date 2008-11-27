/*******************************************************************************/
/**
 * @file Exception.h.
 * 
 * @brief ��O�N���X��`.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_EXCEPTION_H_
#define _NGL_EXCEPTION_H_

#include	<string>

namespace Ngl{


/**
 * @interface Exception�D
 * @brief ��O�N���X.
 */
class Exception
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] mes ��O��񕶎���.
	 */
	Exception( const std::string& mes );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * "mes\n[file] : [line]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 * �t�@�C�����Ƀp�X���܂܂�Ă����ꍇ�́A�t�@�C�����݂̂��o�͂��܂��B
	 * 
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	Exception( const std::string& mes, std::string file, int line );
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * "mes\n[className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	Exception( const std::string& mes, const std::string& className, const std::string& methodName );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~Exception();


	/*=========================================================================*/
	/**
	 * @brief ��O��񕶎����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��O��񕶎���.
	 */
	virtual const char* what();


	/*=========================================================================*/
	/**
	 * @brief ��O��񕶎����擾����( string�N���X )
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��O��񕶎���.
	 */
	virtual const std::string& str();
	
	
	/*=========================================================================*/
	/**
	 * @brief ��O����ǉ�����
	 * 
	 * @param[in] mes �ǉ�������.
	 * @return �Ȃ�.
	 */
	virtual void add( const std::string& mes );

	
	/*=========================================================================*/
	/**
	 * @brief ��O����ǉ�����
	 *
	 * "\n[file] : [line]"�̌`�̕�������Ƃ��ď���ǉ����܂��B
	 * �t�@�C�����Ƀp�X���܂܂�Ă����ꍇ�́A�t�@�C�����݂̂��o�͂��܂��B
	 * 
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	virtual void add( std::string file, int line );
	
	
	/*=========================================================================*/
	/**
	 * @brief ��O����ǉ�����
	 * 
	 * "\n[className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	virtual void add( const std::string& className, const std::string& methodName );

	
	/*=========================================================================*/
	/**
	 * @brief ��O�����R���\�[���ɏo�͂���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void outputConsol();
	
	
	/*=========================================================================*/
	/**
	 * @brief += ���Z�q�I�[�o�[���[�h
	 *
	 * ��O����ǉ�����
	 * 
	 * @param[in] mes �ǉ�������.
	 * @return �Ȃ�.
	 */
	virtual void operator += ( const std::string& mes );

private:

	/** ��O��񕶎��� */
	std::string		mes_;

};


/** �t�@�C�����ƍs�������o�^�}�N�� */
#define EXCEPTION( msg ) Ngl::Exception(msg, __FILE__, __LINE__)

/** �t�@�C�����ƍs����񎩓��ǉ��}�N�� */
#define ADDEXCEPTIONINFO_FILELINE( exception ) exception.add(__FILE__, __LINE__)


/**
 * @class InputStreamException.
 * @brief ���̓X�g���[����O�N���X�D
 */
class InputStreamException : public Exception
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] msg �G���[���b�Z�[�W.
	 */
	InputStreamException( const std::string& msg ) :
		Exception( msg )	// �W����O�N���X
	{}


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * "mes \n [file] : [line]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 * 
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	InputStreamException( const std::string& mes, std::string file, int line ):
		Exception( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * "mes \n [className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	InputStreamException( const std::string& mes, const std::string& className, const std::string& methodName ):
		Exception( mes, className, methodName )
	{}

};


/** �t�@�C�����ƍs�������o�^�}�N�� */
#define INPUT_STREAM_EXCEPTION( msg ) Ngl::InputStreamException(msg, __FILE__, __LINE__)


/**
 * @class FileOpenException.
 * @brief �t�@�C���I�[�v����O�N���X�D
 */
class FileOpenException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] msg �G���[���b�Z�[�W.
	 */
	FileOpenException( const std::string& msg ) :
	  InputStreamException( msg )	// �W����O�N���X
	{}


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * "mes \n [file] : [line]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 * 
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	FileOpenException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * "mes \n [className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	FileOpenException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};


/** �t�@�C�����ƍs�������o�^�}�N�� */
#define FILE_OPEN_EXCEPTION( msg ) Ngl::FileOpenException(msg, __FILE__, __LINE__)


/**
 * @class FileReadException.
 * @brief �t�@�C���ǂݍ��ݗ�O�N���X�D
 */
class FileReadException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] msg �G���[���b�Z�[�W.
	 */
	FileReadException( const std::string& msg ) :
	  InputStreamException( msg )	// �W����O�N���X
	{}


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * "mes \n [file] : [line]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 * 
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	FileReadException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * "mes \n [className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	FileReadException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};


/** �t�@�C�����ƍs�������o�^�}�N�� */
#define FILE_READ_EXCEPTION( msg ) Ngl::FileReadException(msg, __FILE__, __LINE__)


} // namespace Ngl


/*=========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 *
 * ��O����ǉ�����
 * 
 * @param[in] ext �ǉ������O.
 * @param[in] mes �ǉ�������.
 * @return �Ȃ�.
 */
Ngl::Exception& operator + ( Ngl::Exception& ext, const std::string& mes );


/*=========================================================================*/
/**
 * @brief + ���Z�q�I�[�o�[���[�h
 *
 * ��O����ǉ�����
 * 
 * @param[in] ext �ǉ������O.
 * @param[in] mes �ǉ�������.
 * @return �Ȃ�.
 */
Ngl::Exception& operator + ( const std::string& mes, Ngl::Exception& ext );


#endif

/*===== EOF ==================================================================*/