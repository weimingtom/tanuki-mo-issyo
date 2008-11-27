/*******************************************************************************/
/**
 * @file KeyboardDeviceDI8.cpp.
 * 
 * @brief DirectInput �L�[�{�[�h���̓f�o�C�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"KeyboardDeviceDI8.h"
#include	<cassert>


namespace {

	/** �L�[�萔�z�� */
	static const unsigned int KeyboardKeys[] = {
		0,					/**< 0		����������Ă��Ȃ�			*/
		DIK_ESCAPE,			/**< 1		�G�X�P�[�v�L�[				*/
		DIK_1,				/**< 2		1�L�[						*/
		DIK_2,				/**< 3		2�L�[						*/
		DIK_3,				/**< 4		3�L�[						*/
		DIK_4,				/**< 5		4�L�[						*/
		DIK_5,				/**< 6		5�L�[						*/
		DIK_6,				/**< 7		6�L�[						*/
		DIK_7,				/**< 8		7�L�[						*/
		DIK_8,				/**< 9		8�L�[						*/
		DIK_9,				/**< 10		9�L�[						*/
		DIK_0,				/**< 11		0�L�[						*/
		DIK_MINUS,			/**< 12		-�L�[						*/
		DIK_EQUALS,			/**< 13		=�L�[						*/
		DIK_BACK,			/**< 14		�o�b�N�X�y�[�X�L�[			*/
		DIK_TAB,			/**< 15		�^�u�L�[					*/
		DIK_Q,				/**< 16		q�L�[						*/
		DIK_W,				/**< 17		w�L�[						*/
		DIK_E,				/**< 18		e�L�[						*/
		DIK_R,				/**< 19		r�L�[						*/
		DIK_T,				/**< 20		t�L�[						*/
		DIK_Y,				/**< 21		y�L�[						*/
		DIK_U,				/**< 22		u�L�[						*/
		DIK_I,				/**< 23		i�L�[						*/
		DIK_O,				/**< 24		o�L�[						*/
		DIK_P,				/**< 25		p�L�[						*/
		DIK_LBRACKET,		/**< 26		���p����					*/
		DIK_RBRACKET,		/**< 27		�E�p����					*/
		DIK_RETURN,			/**< 28		���^�[���L�[				*/
		DIK_LCONTROL,		/**< 29		��Ctrl�L�[					*/
		DIK_A,				/**< 30		a�L�[						*/
		DIK_S,				/**< 31		s�L�[						*/
		DIK_D,				/**< 32		d�L�[						*/
		DIK_F,				/**< 33		f�L�[						*/
		DIK_G,				/**< 34		g�L�[						*/
		DIK_H,				/**< 35		h�L�[						*/
		DIK_J,				/**< 36		j�L�[						*/
		DIK_K,				/**< 37		k�L�[						*/
		DIK_L,				/**< 38		l�L�[						*/
		DIK_SEMICOLON,		/**< 39		,�L�[						*/
		DIK_APOSTROPHE,		/**< 40		:�L�[						*/
		DIK_GRAVE,			/**< 41		`�L�[						*/
		DIK_LSHIFT,			/**< 42		��SHIFT�L�[					*/
		DIK_BACKSLASH,		/**< 43		\�L�[						*/
		DIK_Z,				/**< 44		z�L�[						*/
		DIK_X,				/**< 45		x�L�[						*/
		DIK_C,				/**< 46		c�L�[						*/
		DIK_V,				/**< 47		v�L�[						*/
		DIK_B,				/**< 48		b�L�[						*/
		DIK_N,				/**< 49		n�L�[						*/
		DIK_M,				/**< 50		m�L�[						*/
		DIK_COMMA,			/**< 51		,�L�[						*/
		DIK_PERIOD,			/**< 52		.�L�[						*/
		DIK_SLASH,			/**< 53		/�L�[						*/
		DIK_RSHIFT,			/**< 54		�ESHIFT�L�[					*/
		DIK_MULTIPLY,		/**< 55		�e���L�[��*�L�[				*/
		DIK_LMENU,			/**< 56		��Alt�L�[					*/
		DIK_SPACE,			/**< 57		�X�y�[�X�L�[				*/
		DIK_CAPITAL,		/**< 58		CapsLock�L�[				*/
		DIK_F1,				/**< 59		F1�L�[						*/
		DIK_F2,				/**< 60		F2�L�[						*/
		DIK_F3,				/**< 61		F3�L�[						*/
		DIK_F4,				/**< 62		F4�L�[						*/
		DIK_F5,				/**< 63		F5�L�[						*/
		DIK_F6,				/**< 64		F6�L�[						*/
		DIK_F7,				/**< 65		F7�L�[						*/
		DIK_F8,				/**< 66		F8�L�[						*/
		DIK_F9,				/**< 67		F9�L�[						*/
		DIK_F10,			/**< 68		F10�L�[						*/
		DIK_NUMLOCK,		/**< 69		NumLock�L�[					*/
		DIK_SCROLL,			/**< 70		�X�N���[���L�[				*/
		DIK_NUMPAD7,		/**< 71		�e���L�[��7					*/
		DIK_NUMPAD8,		/**< 72		�e���L�[��8					*/
		DIK_NUMPAD9,		/**< 73		�e���L�[��9					*/
		DIK_SUBTRACT,		/**< 74		�e���L�[�́[�L�[			*/
		DIK_NUMPAD4,		/**< 75		�e���L�[��4					*/
		DIK_NUMPAD5,		/**< 76		�e���L�[��5					*/
		DIK_NUMPAD6,		/**< 77		�e���L�[��6					*/
		DIK_ADD,			/**< 78		�e���L�[�́{�L�[			*/
		DIK_NUMPAD1,		/**< 79		�e���L�[��1					*/
		DIK_NUMPAD2,		/**< 80		�e���L�[��2					*/
		DIK_NUMPAD3,		/**< 81		�e���L�[��3					*/
		DIK_NUMPAD0,		/**< 82		�e���L�[��0					*/
		DIK_DECIMAL,		/**< 83		�e���L�[��.�L�[				*/
		DIK_OEM_102,		/**< 84		�p�ꁕ�ƌ��102�L�[�{�[�h	*/
		DIK_F11,			/**< 85		F11�L�[						*/
		DIK_F12,			/**< 86		F12�L�[						*/
		DIK_F13,			/**< 87		F13�L�[(NEC-PC98�p)			*/
		DIK_F14,			/**< 88		F14�L�[(NEC-PC98�p)			*/
		DIK_F15,			/**< 89		F15�L�[(NEC-PC98�p)			*/
		DIK_KANA,			/**< 90		�J�i�L�[					*/
		DIK_CONVERT,		/**< 91		���{��L�[�{�[�h�̃L�[		*/
		DIK_NOCONVERT,		/**< 92		���{��L�[�{�[�h�̃L�[		*/
		DIK_YEN,			/**< 93		\�L�[						*/
		DIK_NUMPADEQUALS,	/**< 94		PC98�e���L�[�̃L�[			*/
		DIK_PREVTRACK,		/**< 95		�O�̃g���b�N�L�[			*/
		DIK_AT,				/**< 96		���{��L�[�{�[�h�̃L�[		*/
		DIK_COLON,			/**< 97		���{��L�[�{�[�h�̃L�[		*/
		DIK_UNDERLINE,		/**< 98		_�L�[						*/
		DIK_KANJI,			/**< 99		�����L�[					*/
		DIK_STOP,			/**< 100	PC98�p�L�[					*/
		DIK_AX,				/**< 101	���{��L�[�{�[�h�̃L�[		*/
		DIK_UNLABELED,		/**< 102	���{��L�[�{�[�h�̃L�[		*/
		DIK_NEXTTRACK,		/**< 103	���̃g���b�N�L�[			*/
		DIK_NUMPADENTER,	/**< 104	�e���L�[�̃G���^�[�L�[		*/
		DIK_RCONTROL,		/**< 105	�ECtrl�L�[					*/
		DIK_MUTE,			/**< 106	�~���[�g�L�[				*/
		DIK_CALCULATOR,		/**< 107	�d��L�[					*/
		DIK_PLAYPAUSE,		/**< 108	�ꎞ��~�L�[				*/
		DIK_MEDIASTOP,		/**< 109	���f�B�A��~�L�[			*/
		DIK_VOLUMEDOWN,		/**< 110	���ʃ_�E���L�[				*/
		DIK_VOLUMEUP,		/**< 111	���ʃA�b�v�L�[				*/
		DIK_WEBHOME,		/**< 112	�E�F�u�z�[���y�[�W�L�[		*/
		DIK_NUMPADCOMMA,	/**< 113	�e���L�[��.�L�[				*/
		DIK_DIVIDE,			/**< 114	�e���L�[��/�L�[				*/
		DIK_SYSRQ,			/**< 115	SysRq�L�[					*/
		DIK_RMENU,			/**< 116	�E���j���[�L�[				*/
		DIK_PAUSE,			/**< 117	�|�[�Y�L�[					*/
		DIK_HOME,			/**< 118	�z�[���L�[					*/
		DIK_UP,				/**< 119	���L�[						*/
		DIK_PRIOR,			/**< 120	PageUp�L�[					*/
		DIK_LEFT,			/**< 121	���L�[						*/
		DIK_RIGHT,			/**< 122	���L�[						*/
		DIK_END,			/**< 123	End�L�[						*/
		DIK_DOWN,			/**< 124	���L�[						*/
		DIK_NEXT,			/**< 125	Next�L�[					*/
		DIK_INSERT,			/**< 126	Insert�L�[					*/
		DIK_DELETE,			/**< 127	�f���[�g�L�[				*/
		DIK_LWIN,			/**< 128	��Windows�L�[				*/
		DIK_RWIN,			/**< 129	�EWindows�L�[				*/
		DIK_APPS,			/**< 130	�A�v���P�[�V�����L�[		*/
		DIK_POWER,			/**< 131	�d���L�[					*/
		DIK_SLEEP,			/**< 132	�X���[�v�L�[				*/
		DIK_WAKE,			/**< 133	�E�F�[�N�A�b�v�L�[			*/
		DIK_WEBSEARCH,		/**< 134	WEB�����L�[					*/
		DIK_WEBFAVORITES,	/**< 135	���C�ɓ���L�[				*/
		DIK_WEBREFRESH,		/**< 136	�E�F�u���t���b�V���L�[		*/
		DIK_WEBSTOP,		/**< 137	���f�B�A�I���L�[			*/
		DIK_WEBFORWARD,		/**< 138	�E�F�u��ɐi�ރL�[			*/
		DIK_WEBBACK,		/**< 139	�E�F�u�O�ɖ߂�L�[			*/
		DIK_MYCOMPUTER,		/**< 140	�}�C�R���s���[�^�L�[		*/
		DIK_MAIL,			/**< 141	���[���L�[					*/
		DIK_MEDIASELECT,	/**< 142	���f�B�A�I���L�[			*/
	};

	/** �L�[���� */
	static const unsigned int KEYBOARDKEY_COUNT = sizeof( KeyboardKeys ) / sizeof( unsigned int );
}

using namespace Ngl;
using namespace Ngl::DirectInput;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
KeyboardDeviceDI8::KeyboardDeviceDI8() :
	inputDevice_( 0 ),	// DirectInput�f�o�C�X
	keyDevice_( 0 )		// �L�[�{�[�h�f�o�C�X
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
KeyboardDeviceDI8::~KeyboardDeviceDI8()
{
	release();
}

	
	
/*===========================================================================*/
/**
 * @brief ���̓f�o�C�X�̍쐬
 * 
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
bool KeyboardDeviceDI8::create( HWND hwnd )
{
	// �o�b�t�@���m��
	ZeroMemory( keyState_, sizeof( keyState_ ) );
	newKeyBuf_ = keyState_[0];
	oldKeyBuf_ = keyState_[1];

	HRESULT hr = DI_OK;

	// DirectInput�I�u�W�F�N�g�̍쐬
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );

	// DirectInputDevice�I�u�W�F�N�g�̍쐬
	hr = inputDevice_->CreateDevice( GUID_SysKeyboard, &keyDevice_, 0 );
	assert( hr == DI_OK );

	// �f�o�C�X���L�[�{�[�h�ɐݒ�
	hr = keyDevice_->SetDataFormat( &c_dfDIKeyboard );
	assert( hr == DI_OK );

	// �������x���̐ݒ�
	hr = keyDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND );
	assert( hr == DI_OK );

	// �f�o�C�X���擾����
	keyDevice_->Acquire();

	return true;
}



/*===========================================================================*/
/**
 * @brief �L�[����ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool KeyboardDeviceDI8::loadKeyState()
{
	// �A�N�Z�X�����擾�ł������H
	if( getReacquire() == true ){
		HRESULT result; // �擾����

		// �Â��o�b�t�@�ƐV�����o�b�t�@�����ւ���
		BYTE* tmp	= newKeyBuf_;
		newKeyBuf_	= oldKeyBuf_;
		oldKeyBuf_	= tmp;

		// �L�[�̏�Ԃ��擾����
		result = keyDevice_->GetDeviceState(
			sizeof(BYTE)*DIRECTINPUTKEYBOARDKEY_COUNT,	// �f�[�^�T�C�Y
			(LPVOID)newKeyBuf_							// �L�[�o�b�t�@
			);

		// �擾�ł�����
		if( SUCCEEDED( result ) ){
			// �擾����
			return true;
		}
		else{
			// �擾���s
			return false;
		}
	}

	// �擾�ł��Ȃ�����
	return false;
}



/*=========================================================================*/
/**
 * @brief ���̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �e���̏�ԃx�N�g��.
 */
Vector3 KeyboardDeviceDI8::readAxisState()
{
	return Vector3( 0.0f, 0.0f, 0.0f );
}
	
	
	
/*=========================================================================*/
/**
 * @brief �ڑ��f�o�C�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �ڑ��f�o�C�X��.
 */
unsigned int KeyboardDeviceDI8::getConnectDeviceCount()
{
	// 1�����ڑ����Ȃ��̂ŁA���1��Ԃ�.
	return 1;
}



/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�ɂ���f�o�C�X��ύX����
 * 
 * @param[in] no �ύX����f�o�C�X�ԍ�.
 * @return �Ȃ�.
 */
void KeyboardDeviceDI8::setActiveDevice( unsigned int no )
{
	// 1�����ڑ����Ȃ��̂ŁA�ύX���������Ȃ��B
}

	
	
/*=========================================================================*/
/**
 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
 */
unsigned int KeyboardDeviceDI8::getActiveDeviceNo()
{
	// 1�����ڑ����Ȃ��̂ŁA���0��Ԃ�.
	return 0;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �L���L�[�����擾
 *
 * @retval true �擾����.
 * @retval false �擾���s.
 */
unsigned int KeyboardDeviceDI8::getKeyCount()
{
	return KEYBOARDKEY_COUNT;
}

	
	
/*===========================================================================*/
/**
 * @brief ��������̃L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return ������Ă���  0 ����������Ă��Ȃ�.
 */
bool KeyboardDeviceDI8::getKeyDown()
{
	// �L�[��������Ă��邩���ׂ�
	if( getDownKey() != 0 ){
		// ����������Ă����B
		return true;
	}

	// ����������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief �w�肵���L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return true ������Ă���  false ������Ă��Ȃ�����.
 */
bool KeyboardDeviceDI8::getKeyDown( unsigned int key )
{
	// �L�[���𒴂��Ă��邩
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// �L�[��ϊ�
	key = convertKey( key );

	// ������Ă��邩�H
	if( ( newKeyBuf_[key] & 0x80 ) != 0 ){
		// ������Ă���
		return true;
	}

	// ������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief ������Ă���L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return ������Ă���L�[  0 ����������Ă��Ȃ��ꍇ.
 */
unsigned int KeyboardDeviceDI8::getDownKey()
{
	// �S�L�[�Ɣ���
	for( int i=0; i<DIRECTINPUTKEYBOARDKEY_COUNT; i++ ){
		// ������Ă��邩
		if( ( newKeyBuf_[i] & 0x80 ) != 0 ){
			// ������Ă���
			return convertDI8Key( i );
		}
	}

	// ������Ă��Ȃ�����
	return 0;
}



/*===========================================================================*/
/**
 * @brief ��������̃L�[�������ꂽ�����ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return true �����ꂽ, false ������Ă��Ȃ�.
 */
bool KeyboardDeviceDI8::getKeyRelease()
{
	// ������Ă���L�[�����邩���ׂ�
	int key = getReleaseKey();

	// �����ꂽ�L�[�����邩
	if( key != 0 ){
		return true;
	}

	// ������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief �w�肵���L�[�������ꂽ�����ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @return true �����ꂽ, false ������Ă��Ȃ�.
 */
bool KeyboardDeviceDI8::getKeyRelease( unsigned int key )
{
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// �L�[��ϊ�
	key = convertKey( key );

	// �L�[�𒲂ׂ�
	if( ( oldKeyBuf_[ key ] & ~newKeyBuf_[ key ] & 0x80 ) != 0 ){
		// ������Ă���
		return true;
	}

	// ������Ă��Ȃ�
	return false;
}



/*===========================================================================*/
/**
 * @brief �����ꂽ�L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return key �����ꂽ�L�[.
 */
unsigned int KeyboardDeviceDI8::getReleaseKey()
{
	// ���ׂẴL�[�Œ��ׂ�
	for( int i=0; i<DIRECTINPUTKEYBOARDKEY_COUNT; i++ ){
		// ������Ă�����
		if( getKeyRelease( i ) == true ){
			return i;
		}
	}

	// ����������Ă��Ȃ��̂�0��Ԃ�
	return 0;
}



/*===========================================================================*/
/**
 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
 * 
 * @param[in] �Ȃ�.
 * @return true �^�C�v���ꂽ, false �^�C�v����Ă��Ȃ�.
 */
bool KeyboardDeviceDI8::getKeyTrigger()
{
	// ������Ă���L�[�����邩���ׂ�
	int key = getTriggerKey();

	// �����ꂽ�L�[�����邩
	if( key != 0 ){
		return true;
	}

	// ������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
 * 
 * @param[in] ���ׂ�L�[.
 * @return true �^�C�v���ꂽ, false �^�C�v����Ă��Ȃ�.
 */
bool KeyboardDeviceDI8::getKeyTrigger( unsigned int key )
{
	if( key >= KEYBOARDKEY_COUNT ){
		return false;
	}

	// �L�[��ϊ�
	key = convertKey( key );

	// �L�[�𒲂ׂ�
	if( ( ~oldKeyBuf_[ key ] & newKeyBuf_[ key ] & 0x80 ) != 0 ){
		// ������Ă���
		return true;
	}

	// �^�C�v����Ă��Ȃ�
	return false;
}



/*===========================================================================*/
/**
 * @brief �^�C�v���ꂽ�L�[���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �^�C�v���ꂽ�L�[.
 */
unsigned int KeyboardDeviceDI8::getTriggerKey()
{
	// ���ׂẴL�[�Œ��ׂ�
	for( int i=0; i<KEYBOARDKEY_COUNT; i++ ){
		// ������Ă�����
		if( getKeyTrigger( i ) == true ){
			return i;
		}
	}

	// ����������Ă��Ȃ��̂�0��Ԃ�
	return 0;
}



/*===========================================================================*/
/**
 * @brief �A�N�Z�X���̍Ď擾
 * 
 * @param[in] �Ȃ�.
 * @return true �擾����  false �擾���s.
 */
bool KeyboardDeviceDI8::getReacquire()
{
	HRESULT result;

	// �A�N�Z�X�����擾����
	result = keyDevice_->Acquire();

	if( SUCCEEDED( result ) ){
		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief �L�[�{�[�h�f�o�C�X���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void KeyboardDeviceDI8::release()
{
	// �L�[�{�[�h�f�o�C�X�����
	if( keyDevice_ != 0 ) {
		keyDevice_->Unacquire();
		keyDevice_->Release();
		keyDevice_ = 0;
	}

	// ���̓f�o�C�X�����
	if( inputDevice_ != 0 ){
		inputDevice_->Release();
		inputDevice_ = 0;
	}
}



/*=========================================================================*/
/**
 * @brief �L�[��ϊ�����
 * 
 * @param[in] key �ϊ�����L�[.
 * @return �ϊ���̃L�[.
 */
unsigned int KeyboardDeviceDI8::convertKey( unsigned int key )
{
	// �L�[�����I�[�o�[���Ă��邩
	if( key >= KEYBOARDKEY_COUNT ){
		return 0;
	}

	return KeyboardKeys[ key ];
}



/*=========================================================================*/
/**
 * @brief DI8�L�[�ɕϊ�����
 * 
 * @param[in] key �ϊ�����L�[.
 * @return �ϊ����DI8�L�[.
 */
unsigned int KeyboardDeviceDI8::convertDI8Key( unsigned int key )
{
	// �L�[�����I�[�o�[���Ă��邩
	if( key >= DIRECTINPUTKEYBOARDKEY_COUNT ){
		return 0;
	}

	// �L�[������
	for( int i=0; i<KEYBOARDKEY_COUNT; ++i ){
		if( KeyboardKeys[ i ] == key ){
			return i;
		}
	}

	return KEYBOARDKEYDI8_NONE;
}

	
	
/*========= EOF =============================================================*/