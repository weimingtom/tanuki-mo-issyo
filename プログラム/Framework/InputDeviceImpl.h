/*******************************************************************************/
/**
 * @file InputDeviceImpl.h.<br>
 * 
 * @brief ���̓f�o�C�X�����N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _INPUTDEVICEIMPL_H_
#define _INPUTDEVICEIMPL_H_

#include	"IInputDevice.h"
#include	<Ngl/InputDeviceManager.h>
#include	<windows.h>

/**
 * @brief ���̓f�o�C�X�����N���X.
 */
class InputDeviceImpl : public IInputDevice
{
public:

	
	/**
	 * @brief �R���X�g���N�^.
	 *
	 * param[in] �Ȃ�.
	 */
	InputDeviceImpl();

	
	/**
	 * @brief �f�X�g���N�^.
	 *
	 * param[in] �Ȃ�.
	 */
	virtual ~InputDeviceImpl();

	
	/**
	 * @brief �쐬����<br>
	 * 
	 * @param[in] hwnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	void Create( HWND hwnd );
	
	
	/**
	 * @brief �I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void End();
	
	
	/**
	 * @brief �A�N�e�B�u�̃f�o�C�X��ύX����<br>
	 * 
	 * @param[in] connectID �A�N�e�B�u�ɂ���f�o�C�X�́A�ύX����ڑ��f�o�C�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void ChangeActiveDevice( unsigned int connectID=0 );

	
	/**
	 * @brief �A�N�e�B�u�̓��̓f�o�C�X���擾����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
	 */
	virtual unsigned int GetActiveInputDeviceNo();
	
	
	/**
	 * @brief �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ�.
	 */
	virtual unsigned int GetActiveConnectDeviceNo();
	
	
	/**
	 * @brief ���̓f�o�C�X�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual unsigned int GetDeviceCount();
	
	
	/**
	 * @brief �A�N�e�B�u�f�o�C�X�́A�ڑ��f�o�C�X�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ڑ��f�o�C�X��.
	 */
	virtual unsigned int GetConnectDeviceCount();
	
	
	/**
	 * @brief ��������̃L�[��������Ă��邩���ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual bool GetKeyDown();

	
	/**
	 * @brief �w�肵���L�[��������Ă��邩���ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true ������Ă���.
	 * @retval false ������Ă��Ȃ�����.
	 */
	virtual bool GetKeyDown( unsigned int key );

	
	/**
	 * @brief ������Ă���L�[�𒲂ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���L�[.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual unsigned int GetDownKey();


	/**
	 * @brief ��������̃L�[�������ꂽ�����ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool GetKeyRelease();

	
	/**
	 * @brief �w�肵���L�[�������ꂽ�����ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool GetKeyRelease( unsigned int key );

	
	/**
	 * @brief �����ꂽ�L�[�𒲂ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �����ꂽ�L�[.
	 * @retval 0 ������Ă��Ȃ��B
	 */
	virtual unsigned int GetReleaseKey();

	
	/**
	 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �^�C�v���ꂽ.
	 : @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool GetKeyTrigger();

	
	/**
	 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �^�C�v���ꂽ.
	 * @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool GetKeyTrigger( unsigned int key );

	
	/**
	 * @brief �^�C�v���ꂽ�L�[���擾����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
	 * @retval 0 �^�C�v����Ă��Ȃ�.
	 */
	virtual unsigned int GetTriggerKey();

	
	/**
	 * @brief ���͂��X�V����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void Reload();
	
	
	/**
	 * @brief �I���L�[�������ꂽ��<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool IsInputEndKey();

private:

	/**
	 * @brief �L�[���Q�[���L�[�ɕϊ�����<br>
	 * 
	 * @param[in] key �ϊ�����W���C�X�e�B�b�N�L�[�萔.
	 * @return �ϊ���̃Q�[���L�[.
	 */
	unsigned int ConvertKey( unsigned int key );
	
	/**
	 * @brief �Q�[���L�[����ϊ�����<br>
	 * 
	 * @param[in] key �ϊ�����Q�[���L�[�萔.
	 * @return �ϊ���̃L�[.
	 */
	unsigned int ConvertGameKey( unsigned int key );
	
	/**
	 * @brief �W���C�X�e�B�b�N�L�[���Q�[���L�[�ɕϊ�����<br>
	 * 
	 * @param[in] key �ϊ�����W���C�X�e�B�b�N�L�[�萔.
	 * @return �ϊ���̃Q�[���L�[.
	 */
	unsigned int ConvertJoystickKey( unsigned int key );


	/**
	 * @brief �L�[�{�[�h�L�[���Q�[���L�[�ɕϊ�����<br>
	 * 
	 * @param[in] key �ϊ�����L�[�{�[�h�L�[�萔.
	 * @return �ϊ���̃Q�[���L�[.
	 */
	unsigned int ConvertKeyboardKey( unsigned int key );

private:

	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	InputDeviceImpl( const InputDeviceImpl& other );


	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )<br>
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g
	 */
	InputDeviceImpl& operator = ( const InputDeviceImpl& other );
	
private:

	/** ���̓f�o�C�X�Ǘ��� */
	Ngl::InputDeviceManager		inputDeviceManager_;
};

#endif

/*========= End of File =====================================================*/