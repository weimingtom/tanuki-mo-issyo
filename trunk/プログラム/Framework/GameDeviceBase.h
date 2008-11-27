/*******************************************************************************/
/**
 * @file GameDeviceBase.h.<br>
 * 
 * @brief �Q�[���f�o�C�X���N���X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEDEVICEBASE_H_
#define _GAMEDEVICEBASE_H_

#include	"IGameDevice.h"
#include	<Ngl/IFrameWork.h>


/**
 * @brief �Q�[���f�o�C�X���N���X
 * @tparam Graphic �O���t�B�b�N�f�o�C�X.
 * @tparam Input ���̓f�o�C�X.
 * @tparam Sound �T�E���h�f�o�C�X.
 */
template
<
	class Graphic,
	class Input,
	class Sound
>
class GameDeviceBase : public IGameDevice
{
public:

	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	GameDeviceBase():
		frame_( 0 ),
		graphics_( 0 ),
		sound_( 0 ),
		input_( 0 )
	{}

	
	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~GameDeviceBase()
	{}
	
	
	/**
	 * @brief �쐬����<br>
	 * 
	 * @param[in] frame �t���[�����[�N.
	 * @return �Ȃ�.
	 */
	void Create( Ngl::IFrameWork& frame )
	{
		CreateDevice( frame );

		// �E�B���h�E�n���h����ۑ�
		frame_ = &frame;
	}

	
	/**
	 * @brief �X�V����<br>
	 * 
	 * @param[in] frameTimer �t���[�������␳�l.
	 * @return �Ȃ�.
	 */
	virtual void Update( float frameTimer )
	{
		// �L�[���͂��擾����
		input_->Reload();

		// �T�E���h�f�o�C�X���X�V����
		sound_->Update( frameTimer );
	}

	
	/**
	 * @brief �I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void End()
	{
		graphics_->End();

		delete graphics_;
		delete sound_;
		delete input_;
	}
	
	
	/**
	 * @brief �O���t�B�b�N�f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �O���t�B�b�N�f�o�C�X.
	 */
	virtual IGraphicDevice& GetGraphicDevice()
	{
		return *graphics_;
	}

	
	/**
	 * @brief �T�E���h�f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �T�E���h�f�o�C�X.
	 */
	virtual ISoundDevice& GetSoundDevice()
	{
		return *sound_;
	}
	
	
	/**
	 * @brief ���̓f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���̓f�o�C�X.
	 */
	virtual IInputDevice& GetInputDevice()
	{
		return *input_;
	}

	
	/**
	 * @brief �E�B���h�E�n���h�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�n���h��.
	 */
	virtual void* GetHWND()
	{
		return frame_->getHWND();
	}

	
	/**
	 * @brief �E�B���h�E�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E��.
	 */
	virtual int GetWindowWidth()
	{
		return frame_->desc().windowWidth;
	}

	
	/**
	 * @brief �E�B���h�E�̍������擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�̍���.
	 */
	virtual int GetWindowHeight()
	{
		return frame_->desc().windowHeight;
	}


	/**
	 * @brief �Q�[�����I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void Exit()
	{
		frame_->exit();
	}
	
protected:

	/**
	 * @brief �f�o�C�X�̍쐬����<br>
	 * 
	 * @param[in] frame �t���[�����[�N.
	 * @return �Ȃ�.
	 */
	virtual void CreateDevice( Ngl::IFrameWork& frame ) = 0;

private:

	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	GameDeviceBase( const GameDeviceBase& other );


	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g
	 */
	GameDeviceBase& operator = ( const GameDeviceBase& other );

protected:

	/** �t���[�����[�N */
	Ngl::IFrameWork*	frame_;

	/** �O���t�B�b�N�f�o�C�X */
	Graphic*			graphics_;

	/** �T�E���h�f�o�C�X */
	Sound*				sound_;

	/** ���̓f�o�C�X */
	Input*				input_;

};

#endif

/*===== EOF ==================================================================*/