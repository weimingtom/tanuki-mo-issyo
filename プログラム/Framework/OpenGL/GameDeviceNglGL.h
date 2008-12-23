/*******************************************************************************/
/**
 * @file GameDeviceNglGL.h.<br>
 * 
 * @brief NGL���C�u����OpenGL�Q�[���f�o�C�X�����N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEDEVICENGLGL_H_
#define _GAMEDEVICENGLGL_H_

#include	<Ngl/OpenGL/FrameWorkGLUT.h>
#include	"GameDeviceBase.h"
#include	"GraphicDeviceNglGL.h"
#include	"SoundDeviceDS.h"
#include	"InputDeviceImpl.h"
#include	"IGameDevice.h"
#include	"Define/GaugeDesc.h"
#include	"Define/TextDesc.h"

/**
 * @brief NGL���C�u����OpenGL�Q�[���f�o�C�X�����N���X.
 */
class GameDeviceNglGL : public GameDeviceBase< GraphicDeviceNglGL, InputDeviceImpl, SoundDeviceDS >
{
public:

	/*=========================================================================*/
	/**
	 * �R���X�g���N�^<br>
	 * 
	 * @param[in] ������ ��������.
	 */
	GameDeviceNglGL();
	
	
	/*=========================================================================*/
	/**
	 * �쐬����<br>
	 * 
	 * @param[in] frame �t���[�����[�N.
	 * @return �Ȃ�.
	 */
	virtual void CreateDevice( Ngl::IFrameWork& frame );

private:

	/*=========================================================================*/
	/**
	 * �R�s�[�R���X�g���N�^( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	GameDeviceNglGL( const GameDeviceNglGL& other );


	/*=========================================================================*/
	/**
	 * = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g
	 */
	GameDeviceNglGL& operator = ( const GameDeviceNglGL& other );

};

#endif

/*===== EOF ==================================================================*/