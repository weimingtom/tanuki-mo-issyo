/*******************************************************************************/
/**
 * @file KeyboardDeviceDI8.h.
 * 
 * @brief DirectInput �L�[�{�[�h���̓f�o�C�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYBOARDUDEVICEDI8_H_
#define _NGL_KEYBOARDUDEVICEDI8_H_

#include	"DirectInput.h"
#include	"Ngl/IInputDevice.h"


namespace Ngl{


namespace DirectInput{


/**
 * @class KeyboardDeviceDI8.
 * @brief DirectInput �L�[�{�[�h���̓f�o�C�X�N���X�D
 */
class KeyboardDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	KeyboardDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~KeyboardDeviceDI8();
	

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
	 * @brief �L�[����ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	virtual bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief ���̏�Ԃ�ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e���̏�ԃx�N�g��.
	 */
	virtual Vector3 readAxisState();
	
	
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

private:

	/*=========================================================================*/
	/**
	 * @brief �A�N�Z�X���̍Ď擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return true �擾����  false �擾���s.
	 */
	bool getReacquire();


	/*=========================================================================*/
	/**
	 * @brief �L�[�{�[�h�f�o�C�X���������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �L�[��ϊ�����
	 * 
	 * @param[in] key �ϊ�����L�[.
	 * @return �ϊ���̃L�[.
	 */
	unsigned int convertKey( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief DI8�L�[�ɕϊ�����
	 * 
	 * @param[in] key �ϊ�����L�[.
	 * @return �ϊ����DI8�L�[.
	 */
	unsigned int convertDI8Key( unsigned int key );

private:

	/** DirectInput�L�[�{�[�h�L�[�� */
	static const int DIRECTINPUTKEYBOARDKEY_COUNT = 256;

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	KeyboardDeviceDI8( KeyboardDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 * @return �R�s�[���ʂ̃I�u�W�F�N�g.
	 */
	KeyboardDeviceDI8& operator = ( KeyboardDeviceDI8& other );

private:

	/** DirectInput�I�u�W�F�N�g */
	LPDIRECTINPUT8			inputDevice_;

	/** DirectInputDevice�I�u�W�F�N�g */
	LPDIRECTINPUTDEVICE8	keyDevice_;

	/** �Â��L�[�{�[�h�̃o�b�t�@ */
	BYTE*					oldKeyBuf_;

	/** �V�����L�[�{�[�h�̃o�b�t�@ */
	BYTE*					newKeyBuf_;

	/** �L�[�{�[�h�̏�� */
	BYTE					keyState_[2][DIRECTINPUTKEYBOARDKEY_COUNT];

};

} // namespace DirectInput

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/