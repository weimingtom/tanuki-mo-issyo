/*******************************************************************************/
/**
 * @file MouseDeviceDI8.h.
 * 
 * @brief DirectInput �}�E�X���̓f�o�C�X�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_MOUSEDEVICEDI8_H_
#define _NGL_DIRECTINPUT_MOUSEDEVICEDI8_H_

#include	"DirectInput.h"
#include	"Ngl/IInputDevice.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Rect.h"


namespace Ngl{


namespace DirectInput{


/**
 * @class MouseDeviceDI8.
 * @brief DirectInput �}�E�X���̓f�o�C�X�N���X�D
 */
class MouseDeviceDI8 : public IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	MouseDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~MouseDeviceDI8();


	/*=========================================================================*/
	/**
	 * @brief �}�E�X���̓f�o�C�X�̍쐬
	 * 
	 * @param[in] hwnd �E�B���h�E�n���h��.
	 * @retval true �쐬����.
	 * @retval false �쐬���s.
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
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�E�X�J�[�\���̈ړ��\�͈͂�ݒ肷��
	 * 
	 * @param[in] clip �ړ��\�͈�.
	 * @return �Ȃ�.
	 */
	void setMouseCursorClip( const Rect& clip );


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�̈ړ��䗦��ݒ肷��
	 * 
	 * @param[in] ratio �ړ��䗦.
	 * @return �Ȃ�.
	 */
	void setMouseCursorRatio( float ratio );


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�̈ʒu���W��ݒ肷��
	 * 
	 * @param[in] x x���W.
	 * @param[in] y y���W.
	 * @param[in] z z���W.
	 * @return �Ȃ�.
	 */
	void setMousePosition( int x, int y, int z );
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�E�X�J�[�\���̈ړ��ʂ��擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �J�[�\���̊e�����̈ړ���.
	 */
	inline Ngl::Vector3& getCursorVelocity()
	{
		return ltm_;
	}


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�J�[�\���̈ʒu���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �J�[�\���̈ʒu���W.
	 */
	inline Ngl::Vector3& getMouseCursorPosition()
	{
		return position_;
	}


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�J�[�\���̈ړ��\�͈͂��擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �J�[�\���̈ړ��\�͈�.
	 */
	inline Ngl::Rect& getMouseCursorClip()
	{
		return clip_;
	}


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�̈ړ��䗦���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �}�E�X�̈ړ��䗦.
	 */
	inline float getMouseCursorRatio()
	{
		return ratio_;
	}

private:

	/*=========================================================================*/
	/**
	 * @brief �}�E�X���͏��̎擾
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	void readMouseData();
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�E�X���W���N���b�s���O
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clipMouseCursor();
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�E�X�̃A�N�Z�X���̍Ď擾
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	bool getReacquire();


	/*=========================================================================*/
	/**
	 * @brief �}�E�X�f�o�C�X���������
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

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ (�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	MouseDeviceDI8( MouseDeviceDI8& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h (�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����MouseDeviceDI8.
	 * @return �R�s�[���ʂ�MouseDeviceDI8.
	 */
	MouseDeviceDI8& operator = ( MouseDeviceDI8& other );

public:

	/** �}�E�X�̃f�t�H���g�̈ړ��䗦 */
	static const float RATIO_DEFAULT;

private:

	/** DirectInput�I�u�W�F�N�g */
	LPDIRECTINPUT8			inputDevice_;

	/** DirectInputDevice�I�u�W�F�N�g */
	LPDIRECTINPUTDEVICE8	mouseDevice_;

	/** ���݂̃}�E�X�J�[�\���ʒu���W */
	Ngl::Vector3			position_;

	/** �O�񂩂�̃J�[�\���ړ��� */
	Ngl::Vector3			ltm_;

	/** ���݂̃}�E�X�{�^���̏�� */
	int						nowBtn_;

	/** �O��̃}�E�X�{�^���̏�� */
	int						oldBtn_;

	/** �}�E�X�̈ړ��͈� */
	Ngl::Rect				clip_;

	/** �}�E�X�J�[�\���̈ړ��䗦 */
	float					ratio_;

};

}	// namespace DirectInput

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/