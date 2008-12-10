/*******************************************************************************/
/**
 * @file Utility.h.
 * 
 * @brief ���[�e�B���e�B�[�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_UTIITY_H_
#define _NGL_UTIITY_H_

#include	<string>

namespace Ngl{

/**
 * @class Utility
 * @brief ���[�e�B���e�B�[�N���X�D
 */
class Utility
{

public:

	/*=========================================================================*/
	/**
	 * @brief �t���p�X�̃t�@�C��������t�@�C������؂�o��( �g���q�Ȃ� )
	 * 
	 * @param[in] fileName �؂�o���t�@�C����.
	 * @return �؂�o�����t�@�C����.
	 */
	static std::string getFileName( const char* fileName );
	
	
	/*=========================================================================*/
	/**
	 * @brief �g���q��؂�o��( .���܂܂Ȃ� )
	 * 
	 * @param[in] fileName �؂�o���t�@�C����.
	 * @return �؂�o�����g���q.
	 */
	static std::string getFileExtension( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief �t�@�C���p�X�̃h���C�u����؂�o��
	 * 
	 * @param[in] fileName �؂�o���t�@�C����.
	 * @return �؂�o�����p�X.
	 */
	static std::string getFilePathDrave( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief �t�@�C���p�X�̃f�B���N�g������؂�o��
	 * 
	 * @param[in] fileName �؂�o���t�@�C����.
	 * @return �؂�o�����f�B���N�g��.
	 */
	static std::string getFilePathDir( const char* fileName );


	/*=========================================================================*/
	/**
	 * @brief char����wchar_t�֕ϊ�����
	 * 
	 * @param[in] src �ϊ�����const char�^������.
	 * @param[in] dest �ϊ��f�[�^���i�[����wchar_t�^������.
	 * @return �Ȃ�.
	 */
	static void multiByteToWideChar( const char* src, wchar_t* dest );

};

}	// namespace ngl

#endif

/*===== EOF ==================================================================*/