/*******************************************************************************/
/**
 * @file GameDeviceNglGL.cpp.<br>
 * 
 * @brief NGL���C�u����OpenGL�Q�[���f�o�C�X�����N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GameDeviceNglGL.h"
#include	<cassert>

/*=========================================================================*/
/**
 * �R���X�g���N�^<br>
 * 
 * @param[in] ������ ��������.
 */
GameDeviceNglGL::GameDeviceNglGL()
{}
	
	
	
/*=========================================================================*/
/**
 * �쐬����<br>
 * 
 * @param[in] frame �t���[�����[�N.
 * @return �Ȃ�.
 */
void GameDeviceNglGL::CreateDevice( Ngl::IFrameWork& frame )
{
	graphics_ = new GraphicDeviceNglGL( static_cast< Ngl::OpenGL::FrameWorkGLUT& >( frame ) );
	graphics_->Create( &frame );

	sound_ = new SoundDeviceDS();
	sound_->Create( static_cast< HWND >( frame.getHWND() ) );

	input_ = new InputDeviceImpl();
	input_->Create( static_cast< HWND >( frame.getHWND() ) );
}



/*===== EOF ==================================================================*/