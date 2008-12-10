/*******************************************************************************/
/**
 * @file main.cpp.<br>
 * 
 * @brief ���C���֐���`�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"ApplicationRunnerNglGL.h"

// ���������[�N�`�F�b�N�ݒ�
#ifdef _DEBUG
#include	<crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#pragma comment( linker, "/entry:mainCRTStartup" )

/*=========================================================================*/
/**
 * ���C���֐�<br>
 * 
 * @param[in] argc �R�}���h������.
 * @param[in] argv �R�}���h����.
 * @return 0.
 */
int main( int argc, char* argv[] )
{
	// ���������[�N�`�F�b�N��L���ɂ���
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// �Q�[���t���[���L�q�q��ݒ�
	Ngl::FrameWorkDesc desc;
	desc.windowWidth		= WINDOW_WIDTH;
	desc.windowHeight		= WINDOW_HEIGHT;
	desc.windowTitle		= "GameFrame";
	
	// �t���X�N���[���ɐݒ�
	//desc.isFullScreenMode	= true;
	
	ApplicationRunnerNglGL app( desc, argc, argv );

	// �Q�[�����J�n
	app.runApp();

	return 0;
}



/*===== EOF ==================================================================*/