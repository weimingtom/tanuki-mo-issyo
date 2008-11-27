/*******************************************************************************/
/**
 * @file InputDeviceImpl.cpp.<br>
 * 
 * @brief ���̓f�o�C�X�����N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/07/20.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"InputDeviceImpl.h"
#include	<Ngl/DirectInput/KeyboardDeviceDI8.h>
#include	<Ngl/DirectInput/JoystickDeviceDI8.h>
#include	<Ngl/DirectInput/JoystickKeyDI8.h>
#include	<Ngl/DirectInput/KeyboardKeyDI8.h>
#include	<Ngl/DirectInput/MouseKeyDI8.h>

namespace{
	static const InputDeviceID inputDeviceIDArray[] = {
		INPUTDEVICEID_KEYBOARD,
		INPUTDEVICEID_JOYSTICK
	};

	static const unsigned int joykeys[] = {
		Ngl::DirectInput::JOYSTICKKEYDI8_NONE,		//  GAMEKEY_NONE,		/**<	���͂Ȃ�	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_UP,		//  GAMEKEY_UP,			/**<	��			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_DOWN,		//  GAMEKEY_DOWN,		/**<	��			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHT,		//  GAMEKEY_LEFT,		/**<	��			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFT,		//  GAMEKEY_RIGHT,		/**<	�E			*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFTUP,	//  GAMEKEY_LEFTUP,		/**<	����		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHTUP,	//  GAMEKEY_RIGHTUP,	/**<	�E��		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_LEFTDOWN,	//  GAMEKEY_LEFTDOWN,	/**<	����		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_RIGHTDOWN,	//  GAMEKEY_RIGHTDOWN,	/**<	�E��		*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_1,	//  GAMEKEY_CANNCEL,	/**<	�{�^���P	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_2,	//  GAMEKEY_CIRCLE,		/**<	�{�^���Q	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_3,	//  GAMEKEY_TRIANGLE,	/**<	�{�^���R	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_4,	//  GAMEKEY_QUAD,		/**<	�{�^���S	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_5,	//  GAMEKEY_L1,			/**<	�{�^���T	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_6,	//  GAMEKEY_L2,			/**<	�{�^���U	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_7,	//  GAMEKEY_R1,			/**<	�{�^���V	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_8,	//  GAMEKEY_R2,			/**<	�{�^���W	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_9,	//  GAMEKEY_START,		/**<	�{�^���X	*/ 
		Ngl::DirectInput::JOYSTICKKEYDI8_BUTTON_10	//  GAMEKEY_SELECT,		/**<	�{�^���P�O	*/ 
	};

	static const unsigned int keyboardkey[] = {
		Ngl::DirectInput::KEYBOARDKEYDI8_NONE,	// GAMEKEY_NONE,		/**<	���͂Ȃ�	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_UP,	// GAMEKEY_UP,			/**<	��			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_DOWN,	// GAMEKEY_DOWN,		/**<	��			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_LEFT,		/**<	��			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_RIGHT,		/**<	�E			*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_LEFTUP,		/**<	����		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_RIGHTUP,		/**<	�E��		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_LEFT,	// GAMEKEY_LEFTDOWN,	/**<	����		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_RIGHT,	// GAMEKEY_RIGHTDOWN,	/**<	�E��		*/
		Ngl::DirectInput::KEYBOARDKEYDI8_A,		// GAMEKEY_CANNCEL,		/**<	�{�^���P	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_S,		// GAMEKEY_CIRCLE,		/**<	�{�^���Q	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_D,		// GAMEKEY_TRIANGLE,	/**<	�{�^���R	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_F,		// GAMEKEY_QUAD,		/**<	�{�^���S	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_Z,		// GAMEKEY_L1,			/**<	�{�^���T	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_X,		// GAMEKEY_L2,			/**<	�{�^���U	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_C,		// GAMEKEY_R1,			/**<	�{�^���V	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_V,		// GAMEKEY_R2,			/**<	�{�^���W	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_J,		// GAMEKEY_START,		/**<	�{�^���X	*/
		Ngl::DirectInput::KEYBOARDKEYDI8_K		// GAMEKEY_SELECT,		/**<	�{�^���P�O	*/
	};
}

using namespace Ngl;
using namespace Ngl::DirectInput;

/**
 * purpose : �R���X�g���N�^.
 *
 * param[in] �Ȃ�.
 */
InputDeviceImpl::InputDeviceImpl()
{}



/**
 * purpose : �f�X�g���N�^.
 *
 * param[in] �Ȃ�.
 */
InputDeviceImpl::~InputDeviceImpl()
{
	inputDeviceManager_.clear();
}



/**
 * purpose : �쐬����<br>
 * 
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
void InputDeviceImpl::Create( HWND hwnd )
{
	// �e����̓f�o�C�X���쐬
	KeyboardDeviceDI8* key = new KeyboardDeviceDI8();
	key->create( hwnd );

	JoystickDeviceDI8* joy = new JoystickDeviceDI8();
	joy->create( hwnd );

	inputDeviceManager_.regist( INPUTDEVICEID_KEYBOARD, key	);
	inputDeviceManager_.regist( INPUTDEVICEID_JOYSTICK,	joy	);
}



/**
 * purpose : �I������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void InputDeviceImpl::End()
{
	inputDeviceManager_.clear();
}

	


/**
 * purpose : �A�N�e�B�u�̃f�o�C�X��ύX����<br>
 * 
 * @param[in] connectID �A�N�e�B�u�ɂ���f�o�C�X�́A�ύX����ڑ��f�o�C�X�ԍ�.
 * @return �Ȃ�.
 */
void InputDeviceImpl::ChangeActiveDevice( unsigned int connectID )
{
	// �ڑ��f�o�C�X��ύX
	inputDeviceManager_.setActiveDevice( INPUTDEVICEID_JOYSTICK );
	inputDeviceManager_.changeActiveConnectDevice( connectID );
}



/**
 * purpose : �A�N�e�B�u�̓��̓f�o�C�X���擾����<br>
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
 */
unsigned int InputDeviceImpl::GetActiveInputDeviceNo()
{
	return inputDeviceManager_.getActiveDeviceNo();
}



/**
 * purpose : �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ����擾<br>
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ�.
 */
unsigned int InputDeviceImpl::GetActiveConnectDeviceNo()
{
	return inputDeviceManager_.getActiveConnectDeviceNo();
}



/**
 * purpose : ���̓f�o�C�X�����擾<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
unsigned int InputDeviceImpl::GetDeviceCount()
{
	return inputDeviceManager_.getDeviceCount();
}



/**
 * purpose : �A�N�e�B�u�f�o�C�X�́A�ڑ��f�o�C�X�����擾<br>
 * 
 * @param[in] �Ȃ�.
 * @return �ڑ��f�o�C�X��.
 */
unsigned int InputDeviceImpl::GetConnectDeviceCount()
{
	return inputDeviceManager_.getConnectDeviceCount();
}



/**
 * purpose : ��������̃L�[��������Ă��邩���ׂ�<br>
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���.
 * @retval 0 ����������Ă��Ȃ�.
 */
bool InputDeviceImpl::GetKeyDown()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyDown();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : �w�肵���L�[��������Ă��邩���ׂ�<br>
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true ������Ă���.
 * @retval false ������Ă��Ȃ�����.
 */
bool InputDeviceImpl::GetKeyDown( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyDown( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : ������Ă���L�[�𒲂ׂ�<br>
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���L�[.
 * @retval 0 ����������Ă��Ȃ�.
 */
unsigned int InputDeviceImpl::GetDownKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getDownKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : ��������̃L�[�������ꂽ�����ׂ�<br>
 * 
 * @param[in] �Ȃ�.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool InputDeviceImpl::GetKeyRelease()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyRelease();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : �w�肵���L�[�������ꂽ�����ׂ�<br>
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool InputDeviceImpl::GetKeyRelease( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyRelease( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : �����ꂽ�L�[�𒲂ׂ�<br>
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �����ꂽ�L�[.
 * @retval 0 ������Ă��Ȃ��B
 */
unsigned int InputDeviceImpl::GetReleaseKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getReleaseKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : �Ȃɂ�����̃L�[���^�C�v���ꂽ��<br>
 * 
 * @param[in] �Ȃ�.
 * @retval true �^�C�v���ꂽ.
 : @retval false �^�C�v����Ă��Ȃ�.
 */
bool InputDeviceImpl::GetKeyTrigger()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyTrigger();
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : �w��̃L�[���^�C�v���ꂽ�����ׂ�<br>
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �^�C�v���ꂽ.
 * @retval false �^�C�v����Ă��Ȃ�.
 */
bool InputDeviceImpl::GetKeyTrigger( unsigned int key )
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		bool result = inputDeviceManager_.getKeyTrigger( ConvertGameKey( key ) );
		if( result == true ){
			return true;
		}
	}
	return false;
}



/**
 * purpose : �^�C�v���ꂽ�L�[���擾����<br>
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
 * @retval 0 �^�C�v����Ă��Ȃ�.
 */
unsigned int InputDeviceImpl::GetTriggerKey()
{
	for( int i=0; i<2; i++ ){
		inputDeviceManager_.setActiveDevice( inputDeviceIDArray[ i ] );
		unsigned int key = ConvertKey( inputDeviceManager_.getTriggerKey() );
		if( key != GAMEKEY_NONE ){
			return key;
		}
	}
	return GAMEKEY_NONE;
}



/**
 * purpose : ���͂��X�V����<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void InputDeviceImpl::Reload()
{
	inputDeviceManager_.loadKeyState();	
}



/**
 * purpose : �I���L�[�������ꂽ��<br>
 * 
 * @param[in] �Ȃ�.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool InputDeviceImpl::IsInputEndKey()
{
	// ���̓f�o�C�X���W���C�p�b�h�ɐݒ�
	int active = inputDeviceManager_.getActiveDeviceNo();
	inputDeviceManager_.setActiveDevice( INPUTDEVICEID_JOYSTICK );

	// �p�b�h��9�ԃ{�^����10�ԃ{�^����������������Ă��邩
	bool result = false;
	if( inputDeviceManager_.getKeyDown( JOYSTICKKEYDI8_BUTTON_10 ) == true ){
		if( inputDeviceManager_.getKeyDown( JOYSTICKKEYDI8_BUTTON_9 ) == true ){
			result = true;
		}
	}

	// ���̓f�o�C�X���A�N�e�B�u�ɖ߂�
	inputDeviceManager_.setActiveDevice( active );

	// ���ʂ�Ԃ�
	return result;
}



/**
 * purpose : �L�[���Q�[���L�[�ɕϊ�����<br>
 * 
 * @param[in] key �ϊ�����W���C�X�e�B�b�N�L�[�萔.
 * @return �ϊ���̃Q�[���L�[.
 */
unsigned int InputDeviceImpl::ConvertKey( unsigned int key )
{
	if( GetActiveInputDeviceNo() == INPUTDEVICEID_KEYBOARD ){
		return ConvertKeyboardKey( key );
	}
	else{
		return ConvertJoystickKey( key );
	}
}


	
/**
 * purpose : �Q�[���L�[����ϊ�����<br>
 * 
 * @param[in] key �ϊ�����Q�[���L�[�萔.
 * @return �ϊ���̃L�[.
 */
unsigned int InputDeviceImpl::ConvertGameKey( unsigned int key )
{
	if( GetActiveInputDeviceNo() == INPUTDEVICEID_KEYBOARD ){
		return keyboardkey[ key ];
	}
	else{
		return joykeys[ key ];
	}
}

	
	
/**
 * purpose : �W���C�X�e�B�b�N�L�[���Q�[���L�[��ϊ�����<br>
 * 
 * @param[in] key �ϊ�����W���C�X�e�B�b�N�L�[�萔.
 * @return �ϊ���̃Q�[���L�[.
 */
unsigned int InputDeviceImpl::ConvertJoystickKey( unsigned int key )
{
	

	for( int i=0; i<GAMEKEY_COUNT; ++i ){
		if( joykeys[ i ] == key ){
			return i;
		}
	}

	return GAMEKEY_NONE;
}

	
	
/**
 * purpose : �L�[�{�[�h�L�[���Q�[���L�[�ɕϊ�����<br>
 * 
 * @param[in] key �ϊ�����L�[�{�[�h�L�[�萔.
 * @return �ϊ���̃Q�[���L�[.
 */
unsigned int InputDeviceImpl::ConvertKeyboardKey( unsigned int key )
{
	for( int i=1; i<GAMEKEY_COUNT; ++i ){
		if( keyboardkey[ i ] == key ){
			return i;
		}
	}

	return GAMEKEY_NONE;
}

	
	
/*========= End of File =====================================================*/