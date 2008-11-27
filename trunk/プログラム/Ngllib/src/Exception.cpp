/*******************************************************************************/
/**
 * @file Exception.cpp.
 * 
 * @brief ��O�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Exception.h"
#include	"Ngl/Utility.h"
#include	<iostream>
#include	<sstream>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] mes ��O��񕶎���.
 */
Exception::Exception( const std::string& mes ):
	mes_( mes )
{}



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
Exception::Exception( const std::string& mes, std::string file, int line )
{
	
	std::string fname = file;

	// �t���p�X�̃t�@�C��������t�@�C������؂�o��
	fname = Utility::getFileName( file.c_str() );
	fname += ".";
	fname += Utility::getFileExtension( file.c_str() );

	// ��������쐬
	std::stringstream ss;
	ss << mes << "\n[" << fname << "] : [" << line << "]";
	mes_ = ss.str();
}



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
Exception::Exception( const std::string& mes, const std::string& className, const std::string& methodName )
{
	std::stringstream ss;
	ss << mes << "\n[" << className << "] : [" << methodName << "]";
	mes_ = ss.str();
}

	
	
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Exception::~Exception()
{}



/*=========================================================================*/
/**
 * @brief ��O��񕶎����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ��O��񕶎���.
 */
const char* Exception::what()
{
	return mes_.c_str();
}



/*=========================================================================*/
/**
 * @brief ��O��񕶎����擾����( string�N���X )
 * 
 * @param[in] �Ȃ�.
 * @return ��O��񕶎���.
 */
const std::string& Exception::str()
{
	return mes_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief ��O����ǉ�����
 * 
 * @param[in] mes �ǉ�������.
 * @return �Ȃ�.
 */
void Exception::add( const std::string& mes )
{
	mes_ = mes_ + "\n" + mes; 
}



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
void Exception::add( std::string file, int line )
{
	std::string fname = file;

	// �t���p�X�̃t�@�C��������t�@�C������؂�o��
	fname = Utility::getFileName( file.c_str() );
	fname += ".";
	fname += Utility::getFileExtension( file.c_str() );

	std::stringstream ss;
	ss << "\n" << "[" << fname << "] : [" << line << "]";
	mes_ += ss.str();
}



/*=========================================================================*/
/**
 * @brief ��O����ǉ�����
 * 
 * "\n[className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
 *
 * @param[in] className ��O�̔��������N���X��.
 * @param[in] methodName ��O�̔��������֐���.
 */
void Exception::add( const std::string& className, const std::string& methodName )
{
	std::stringstream ss;
	ss << "\n[" << className << "] : [" << methodName << "]";
	mes_ += ss.str();
}



/*=========================================================================*/
/**
 * @brief ��O�����R���\�[���ɏo�͂���
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Exception::outputConsol()
{
	std::cout << mes_  << std::endl;
}

	
	
/*=========================================================================*/
/**
 * @brief += ���Z�q�I�[�o�[���[�h
 *
 * ��O����ǉ�����
 * 
 * @param[in] mes �ǉ�������.
 * @return �Ȃ�.
 */
void Exception::operator += ( const std::string& mes )
{
	add( mes );
}



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
Ngl::Exception& operator + ( Ngl::Exception& ext, const std::string& mes )
{
	ext += mes;

	return ext;
}



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
Ngl::Exception& operator + ( const std::string& mes, Ngl::Exception& ext )
{
	return ext + mes;
}



/*===== EOF ==================================================================*/