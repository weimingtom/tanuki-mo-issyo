/*******************************************************************************/
/**
 * @file Utility.cpp.
 * 
 * @brief ���[�e�B���e�B�[�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Utility.h"
#include	<cstring>
#include	<cstdlib>
#include	<clocale>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �t���p�X�̃t�@�C��������t�@�C������؂�o��( �g���q�Ȃ� )
 * 
 * @param[in] fileName �؂�o���t�@�C����.
 * @return �؂�o�����t�@�C����.
 */
std::string Utility::getFileName( const char* fileName )
{
	char fname[_MAX_FNAME ];
	_splitpath( fileName, NULL, NULL, fname, NULL );

	std::string fileNameExt = fname;

	return fileNameExt;
}

	
	
/*===========================================================================*/
/**
 * @brief �g���q��؂�o��( .���܂܂Ȃ� )
 * 
 * @param[in] fileName �؂�o���t�@�C����.
 * @return �؂�o�����g���q.
 */
std::string Utility::getFileExtension(const char *fileName)
{
	char ext[_MAX_FNAME ];
	_splitpath( fileName, NULL, NULL, NULL, ext );

	// .��؂藎�Ƃ�
	std::string fileNameExt = ext;
	fileNameExt.erase( 0, 1 );
	
	return fileNameExt;
}



/*===========================================================================*/
/**
 * @brief �t�@�C���p�X�̃h���C�u����؂�o��
 * 
 * @param[in] fileName �؂�o���t�@�C����.
 * @return �؂�o�����p�X.
 */
std::string Utility::getFilePathDrave(const char *fileName)
{
	char drive[_MAX_DRIVE ];
	char dir[_MAX_DIR ];
	_splitpath( fileName, drive, dir, NULL, NULL );

	return std::string( drive );
}




/*===========================================================================*/
/**
 * @brief �t�@�C���p�X�̃f�B���N�g������؂�o��
 * 
 * @param[in] fileName �؂�o���t�@�C����.
 * @return �؂�o�����f�B���N�g��.
 */
std::string Utility::getFilePathDir(const char *fileName)
{
	char drive[_MAX_DRIVE ];
	char dir[_MAX_DIR ];
	_splitpath( fileName, drive, dir, NULL, NULL );

	return std::string( dir );
}



/*=========================================================================*/
/**
 * @brief char����wchar_t�֕ϊ�����
 * 
 * @param[in] src �ϊ�����const char�^������.
 * @param[in] dest �ϊ��f�[�^���i�[����wchar_t�^������.
 * @return �Ȃ�.
 */
void Utility::multiByteToWideChar( const char* src, wchar_t* dest )
{
	// ���P�[����ݒ�
	setlocale( LC_ALL, "ja" );
	
	// �������ϊ����ăR�s�[
	size_t len = 0;
	mbstowcs_s( &len, dest, strlen( src ) + 1, src, 1024 ); 
}

	
	
/*========= EOF =============================================================*/