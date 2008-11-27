/*******************************************************************************/
/**
 * @file JoystickDI8.h.
 * 
 * @brief DirectInput �W���C�X�e�B�b�N�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUT_JOYSTICKDI8_H_
#define _NGL_INPUT_JOYSTICKDI8_H_

#include	"DirectInput.h"
#include	"Ngl/Vector3.h"
#include	<vector>

namespace Ngl{


namespace DirectInput{

/**
 * @class JoystickDI8.
 * @brief DirectInput �W���C�X�e�B�b�N�N���X�D
 */
class JoystickDI8
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	JoystickDI8();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~JoystickDI8();
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X���쐬����
	 * 
	 * @param[in] di �C���v�b�g�f�o�C�X.
	 * @param[in] inst �C���X�^���X.
	 * @param[in] hwnd �E�B���h�E�n���h��.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	bool create( LPDIRECTINPUT8 di, LPCDIDEVICEINSTANCE inst, HWND hwnd );
	
	
	/*=========================================================================*/
	/**
	 * @brief ��Ԃ�ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true ����.
	 * @retval false ���s.
	 */
	bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief ���̏�Ԃ�ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e���̏�ԃx�N�g��.
	 */
	Vector3 readAxisState();

	
	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	bool getKeyDown();


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true ������Ă���.
	 * @retval false ������Ă��Ȃ�����.
	 */
	bool getKeyDown( unsigned int key );
	
	
	/*=========================================================================*/
	/**
	 * @brief ������Ă���L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���L�[.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	unsigned int getDownKey();


	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	bool getKeyRelease();


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	bool getKeyRelease( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief �����ꂽ�L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �����ꂽ�L�[.
	 * @retval 0 ������Ă��Ȃ��B
	 */
	unsigned int getReleaseKey();


	/*=========================================================================*/
	/**
	 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �^�C�v���ꂽ.
	 : @retval false �^�C�v����Ă��Ȃ�.
	 */
	bool getKeyTrigger();


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �^�C�v���ꂽ.
	 * @retval false �^�C�v����Ă��Ȃ�.
	 */
	bool getKeyTrigger( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief �^�C�v���ꂽ�L�[���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
	 * @retval 0 �^�C�v����Ă��Ȃ�.
	 */
	unsigned int getTriggerKey();
	
	
	/*=========================================================================*/
	/**
	 * @brief �A�N�Z�X���̍Ď擾
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	bool getReacquire();

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
	 * @brief �v���p�e�B�̐ݒ�
	 * 
	 * @param[in] guid �ݒ�Ώۂ̎��ʎq.
	 * @param[in] obj �ݒ肷�鍀��.
	 * @param[in] how �ݒ�l�̕��@.
	 * @param[in] val �ݒ�l.
	 * @return �Ȃ�.
	 */
	HRESULT setDevProperty( REFGUID guid, DWORD obj, DWORD how, DWORD val );


	/*=========================================================================*/
	/**
	 * @brief �΂ߓ��͔���
	 * 
	 * @param[in] buf ���肷��o�b�t�@.
	 * @return ���͂��ꂽ�L�[.
	 */
	int judgementDiagonalKey( int buf );


	/*=========================================================================*/
	/**
	 * @brief ���͂��ꂽ�L�[��ϊ�����
	 * 
	 * @param[in] key �ϊ�����L�[.
	 * @return �ϊ���̃L�[.
	 */
	unsigned int convertKey( unsigned int key );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 */
	JoystickDI8( const JoystickDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h �R�s�[�֎~����
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 * @return �R�s�[���ʂ̃I�u�W�F�N�g.
	 */
	JoystickDI8& operator = ( const JoystickDI8& other );

public:

	/** �ő�W���C�X�e�B�b�N�{�^���� */
	static const int BUTTON_MAX = 10;

	/** �\���L�[���ő吔 */
	static const int CROSSKEY_MAX = 4;

	/** �΂ߏ\���L�[���ő吔 */
	static const int DIAGONALCROSSKEY_MAX = 4;

	/** �L�[�̍��v�� */
	static const int JOYSTICKKEY_MAX = BUTTON_MAX + CROSSKEY_MAX + DIAGONALCROSSKEY_MAX;

private:

	/** DirectInputDevice�I�u�W�F�N�g */
	LPDIRECTINPUTDEVICE8	padDevice_;

	/** �Â��W���C�X�e�B��N�̃o�b�t�@ */
	int*					oldBuf_;

	/** �V�����W���C�X�e�B��N�̃o�b�t�@ */
	int*					newBuf_;

	/** �W���C�X�e�B��N�̏�� */
	int						state_[2];

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/