/*******************************************************************************/
/**
 * @file JoystickDeviceDI8.h.
 * 
 * @brief DirectInput �W���C�X�e�B�b�N���̓f�o�C�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_JOYSTICKDEVICEDI8_H_
#define _NGL_DIRECTINPUT_JOYSTICKDEVICEDI8_H_

#include	"DirectInput.h"
#include	"JoystickDI8.h"
#include	"Ngl/IInputDevice.h"
#include	"Ngl/Vector3.h"
#include	<vector>

namespace Ngl{


namespace DirectInput{


/**
 * @class JoystickDeviceDI8.
 * @brief DirectInput �W���C�X�e�B�b�N���̓f�o�C�X�N���X�D
 */
class JoystickDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	JoystickDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~JoystickDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief ���̓f�o�C�X�̍쐬
	 * 
	 * @param[in] hwnd �E�B���h�E�n���h��.
	 * @return �Ȃ�.
	 */
	bool create( HWND hwnd );


	/*=========================================================================*/
	/**
	 * @brief �w��̃W���C�X�e�B�b�N���玲�̏�Ԃ�ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e���̏�ԃx�N�g��.
	 */
	virtual Vector3 readAxisState();

	
	/*=========================================================================*/
	/**
	 * @brief �L�[����ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	virtual bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief �ڑ��f�o�C�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ڑ��f�o�C�X��.
	 */
	virtual unsigned int getConnectDeviceCount();

	
	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�ɂ���f�o�C�X��ύX����
	 * 
	 * @param[in] no �ύX����f�o�C�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setActiveDevice( unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
	 */
	virtual unsigned int getActiveDeviceNo();
	
	
	/*=========================================================================*/
	/**
	 * @brief �L���L�[�����擾
	 *
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	virtual unsigned int getKeyCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual bool getKeyDown();


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true ������Ă���.
	 * @retval false ������Ă��Ȃ�����.
	 */
	virtual bool getKeyDown( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief ������Ă���L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���L�[.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual unsigned int getDownKey();


	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool getKeyRelease();


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool getKeyRelease( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief �����ꂽ�L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �����ꂽ�L�[.
	 * @retval 0 ������Ă��Ȃ��B
	 */
	virtual unsigned int getReleaseKey();


	/*=========================================================================*/
	/**
	 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �^�C�v���ꂽ.
	 : @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool getKeyTrigger();


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �^�C�v���ꂽ.
	 * @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool getKeyTrigger( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief �^�C�v���ꂽ�L�[���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
	 * @retval 0 �^�C�v����Ă��Ȃ�.
	 */
	virtual unsigned int getTriggerKey();
	
	
	/*=========================================================================*/
	/**
	 * @brief �ڑ�����Ă���W���C�X�e�B�b�N�̐��𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�b�h�̐�.
	 */
	virtual unsigned int getCount();


	/*=========================================================================*/
	/**
	 * @brief �w��ԍ��̃W���C�X�e�B�b�N�����݂��Ă��邩���ׂ�
	 * 
	 * @param[in] no ���ׂ�W���C�X�e�B�b�N�ԍ�.
	 * @retval true ���݂��Ă�.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	virtual bool isJoyDeviceExists( unsigned int no );

private:
	
	/*=========================================================================*/
	/**
	 * @brief �W���C�X�e�B�b�N�f�o�C�X���������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �o�^����Ă���W���C�X�e�B�b�N�̃A�N�Z�X���̍Ď擾
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	void getReacquire();
	
	
	/*=========================================================================*/
	/**
	* @brief �f�o�C�X���쐬����
	* 
	* @param[in] pdinst �C���X�^���X.
	* @param[in] hnd �n���h��.
	* @return DIENUM_CONTINUE �񋓂𑱂���.
	*/
	static BOOL FAR PASCAL enumJoysticksCallback( LPCDIDEVICEINSTANCE pdinst, LPVOID hnd );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	JoystickDeviceDI8( JoystickDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 * @return �R�s�[���ʂ̃I�u�W�F�N�g.
	 */
	JoystickDeviceDI8& operator = ( JoystickDeviceDI8& other );

public:

	/** �W���C�X�e�B�b�N�f�o�C�X�̍ő吔 */
	static const int JOYSTIC_MAX = 8;

private:

	/** �W���C�X�e�B�b�N�z��^ */
	typedef std::vector< JoystickDI8* >	JoystickList;

private:

	/** DirectInput�I�u�W�F�N�g */
	LPDIRECTINPUT8		inputDevice_;

	/** �W���C�X�e�B�b�N���X�g */
	JoystickList		joystickList_;

	/** �E�B���h�E�n���h�� */
	HWND				joyHwnd_;

	/** �A�N�e�B�u�ȃW���C�X�e�B�b�N�ԍ� */
	unsigned int		activeJoystickNo_;

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/