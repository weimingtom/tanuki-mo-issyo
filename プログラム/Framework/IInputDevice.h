/*******************************************************************************/
/**
 * @file IInputDevice.h.<br>
 * 
 * @brief ���̓f�o�C�X�C���^�[�t�F�[�X.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IINPUTDEVICE_H_
#define _IINPUTDEVICE_H_

#include "Define/Define.h"

/**
 * @enum InputDeviceID
 * @brief ���̓f�o�C�XID�񋓌^.
 */
enum InputDeviceID
{
	INPUTDEVICEID_KEYBOARD	= 0,	/**< �L�[�{�[�h�f�o�C�X			*/
	INPUTDEVICEID_JOYSTICK	= 1,	/**< �W���C�X�e�B�b�N�f�o�C�X	*/
};

/**
 * @brief ���̓f�o�C�X�C���^�[�t�F�[�X.
 */
class IInputDevice
{
protected:

	/**
	 * @brief �f�X�g���N�^.
	 */
	virtual ~IInputDevice(){}

public:
	
	/**
	 * @brief �A�N�e�B�u�̃f�o�C�X��ύX����<br>
	 * 
	 * @param[in] connectID �A�N�e�B�u�ɂ���f�o�C�X�́A�ύX����ڑ��f�o�C�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void ChangeActiveDevice( unsigned int connectID=0 ) = 0;

	
	/**
	 * @brief �A�N�e�B�u�̓��̓f�o�C�X���擾����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
	 */
	virtual unsigned int GetActiveInputDeviceNo() = 0;
	
	
	/**
	 * @brief �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ�.
	 */
	virtual unsigned int GetActiveConnectDeviceNo() = 0;
	
	
	/**
	 * @brief ���̓f�o�C�X�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual unsigned int GetDeviceCount() = 0;
	
	
	/**
	 * @brief �A�N�e�B�u�f�o�C�X�́A�ڑ��f�o�C�X�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ڑ��f�o�C�X��.
	 */
	virtual unsigned int GetConnectDeviceCount() = 0;
	
		
	/**
	 * @brief ��������̃L�[��������Ă��邩���ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual bool GetKeyDown() = 0;


	/**
	 * @brief �w�肵���L�[��������Ă��邩���ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true ������Ă���.
	 * @retval false ������Ă��Ȃ�����.
	 */
	virtual bool GetKeyDown( unsigned int key ) = 0;


	/**
	 * @brief ������Ă���L�[�𒲂ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���L�[.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual unsigned int GetDownKey() = 0;


	/**
	 * @brief ��������̃L�[�������ꂽ�����ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool GetKeyRelease() = 0;


	/**
	 * @brief �w�肵���L�[�������ꂽ�����ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool GetKeyRelease( unsigned int key ) = 0;


	/**
	 * @brief �����ꂽ�L�[�𒲂ׂ�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �����ꂽ�L�[.
	 * @retval 0 ������Ă��Ȃ��B
	 */
	virtual unsigned int GetReleaseKey() = 0;


	/**
	 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �^�C�v���ꂽ.
	 : @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool GetKeyTrigger() = 0;


	/**
	 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�<br>
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �^�C�v���ꂽ.
	 * @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool GetKeyTrigger( unsigned int key ) = 0;


	/**
	 * @brief �^�C�v���ꂽ�L�[���擾����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
	 * @retval 0 �^�C�v����Ă��Ȃ�.
	 */
	virtual unsigned int GetTriggerKey() = 0;

	
	/**
	 * @brief ���͂��X�V����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void Reload() = 0;

	
	/**
	 * @brief �I���L�[�������ꂽ��<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool IsInputEndKey() = 0;
};

#endif

/*========= End of File =====================================================*/