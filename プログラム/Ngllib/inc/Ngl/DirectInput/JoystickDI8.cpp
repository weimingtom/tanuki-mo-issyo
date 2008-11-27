/*******************************************************************************/
/**
 * @file JoystickDI8.cpp.
 * 
 * @brief DirectInput �W���C�X�e�B�b�N�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/07/26.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"JoystickDI8.h"
#include	<cassert>

namespace{

	/** �W���C�X�e�B�b�N�L�[ */
	const static int JOY_NONE		= 0x0000U;				/**< ����������Ă��Ȃ�			*/
	const static int JOY_LEFT 		= 0x8000U;				/**< �W���C�X�e�B�b�N����		*/
	const static int JOY_RIGHT		= 0x4000U;				/**< �W���C�X�e�B�b�N���E		*/
	const static int JOY_UP			= 0x2000U;				/**< �W���C�X�e�B�b�N����		*/
	const static int JOY_DOWN		= 0x1000U;				/**< �W���C�X�e�B�b�N����		*/
	const static int JOY_LEFTDOWN	= JOY_DOWN | JOY_LEFT;	/**< �W���C�X�e�B�b�N���΂߉�	*/
	const static int JOY_RIGHTDOWN	= JOY_DOWN | JOY_RIGHT;	/**< �W���C�X�e�B�b�N�E�΂߉�	*/
	const static int JOY_LEFTUP		= JOY_UP   | JOY_LEFT;	/**< �W���C�X�e�B�b�N���΂ߏ�	*/
	const static int JOY_RIGHTUP	= JOY_UP   | JOY_RIGHT;	/**< �W���C�X�e�B�b�N���΂߉�	*/
	const static int JOY_BUTTON_1	= 0x0001U;				/**< �W���C�X�e�B�b�N�{�^��1	*/
	const static int JOY_BUTTON_2	= 0x0002U;				/**< �W���C�X�e�B�b�N�{�^��2	*/
	const static int JOY_BUTTON_3	= 0x0004U;				/**< �W���C�X�e�B�b�N�{�^��3	*/
	const static int JOY_BUTTON_4	= 0x0008U;				/**< �W���C�X�e�B�b�N�{�^��4	*/
	const static int JOY_BUTTON_5	= 0x0010U;				/**< �W���C�X�e�B�b�N�{�^��5	*/
	const static int JOY_BUTTON_6	= 0x0020U;				/**< �W���C�X�e�B�b�N�{�^��6	*/
	const static int JOY_BUTTON_7	= 0x0040U;				/**< �W���C�X�e�B�b�N�{�^��7	*/
	const static int JOY_BUTTON_8	= 0x0080U;				/**< �W���C�X�e�B�b�N�{�^��8	*/
	const static int JOY_BUTTON_9	= 0x0100U;				/**< �W���C�X�e�B�b�N�{�^��9	*/
	const static int JOY_BUTTON_10	= 0x0200U;				/**< �W���C�X�e�B�b�N�{�^��10	*/

	/** �ϊ��L�[�z�� */
	static const unsigned int joystickKey[] = {
		JOY_NONE,		/**< 0  ����������Ă��Ȃ�			*/
		JOY_LEFT,		/**< 1  �W���C�X�e�B�b�N����		*/
		JOY_RIGHT,		/**< 2  �W���C�X�e�B�b�N���E		*/
		JOY_UP,			/**< 3  �W���C�X�e�B�b�N����		*/
		JOY_DOWN,		/**< 4  �W���C�X�e�B�b�N����		*/
		JOY_LEFTDOWN,	/**< 5  �W���C�X�e�B�b�N���΂߉�	*/
		JOY_RIGHTDOWN,	/**< 6  �W���C�X�e�B�b�N�E�΂߉�	*/
		JOY_LEFTUP,		/**< 7  �W���C�X�e�B�b�N���΂ߏ�	*/
		JOY_RIGHTUP,	/**< 8  �W���C�X�e�B�b�N���΂߉�	*/
		JOY_BUTTON_1,	/**< 9  �W���C�X�e�B�b�N�{�^��1		*/
		JOY_BUTTON_2,	/**< 10 �W���C�X�e�B�b�N�{�^��2		*/
		JOY_BUTTON_3,	/**< 11 �W���C�X�e�B�b�N�{�^��3		*/
		JOY_BUTTON_4,	/**< 12 �W���C�X�e�B�b�N�{�^��4		*/
		JOY_BUTTON_5,	/**< 13 �W���C�X�e�B�b�N�{�^��5		*/
		JOY_BUTTON_6,	/**< 14 �W���C�X�e�B�b�N�{�^��6		*/
		JOY_BUTTON_7,	/**< 15 �W���C�X�e�B�b�N�{�^��7		*/
		JOY_BUTTON_8,	/**< 16 �W���C�X�e�B�b�N�{�^��8		*/
		JOY_BUTTON_9,	/**< 17 �W���C�X�e�B�b�N�{�^��9		*/
		JOY_BUTTON_10	/**< 18 �W���C�X�e�B�b�N�{�^��10	*/
	};

	/** ���肷��΂߃L�[���X�g */
	static const unsigned int diagonalKeyList[] = {
		5, 6, 7, 8
	};
}

using namespace Ngl;
using namespace Ngl::DirectInput;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
JoystickDI8::JoystickDI8():
	padDevice_( NULL ),
	oldBuf_( 0 ),
	newBuf_( 0 )
{
	for( int i=0; i<2; ++i ){
		state_[i] = 0;
	}
}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
JoystickDI8::~JoystickDI8()
{
	// �������
	release();
}



/*===========================================================================*/
/**
 * @brief �f�o�C�X���쐬����
 * 
 * @param[in] di �C���v�b�g�f�o�C�X.
 * @param[in] inst �C���X�^���X.
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool JoystickDI8::create(LPDIRECTINPUT8 di, LPCDIDEVICEINSTANCE inst, HWND hwnd)
{
	HRESULT hr = DI_OK; // ���s����

	// �uDirectInput�f�o�C�X�v�I�u�W�F�N�g�̍쐬
    hr = di->CreateDevice( inst->guidInstance, &padDevice_, 0 );
	assert( hr == DI_OK );

	// �o�b�t�@���m��
	ZeroMemory( state_, sizeof( state_ ) );
	newBuf_ = &state_[0];
	oldBuf_ = &state_[1];

	// �f�[�^�t�H�[�}�b�g�̐ݒ�
	hr = padDevice_->SetDataFormat( &c_dfDIJoystick2 );
	assert( hr == DI_OK );

	// �������x���̐ݒ�
	hr = padDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );
	assert( hr == DI_OK );
	
	// �W���C�X�e�B�b�N�̂w���̐ݒ�
	DIPROPRANGE	prop;
	prop.diph.dwSize		= sizeof( prop );
	prop.diph.dwHeaderSize	= sizeof( prop.diph );
	prop.diph.dwObj			= DIJOFS_X;
	prop.diph.dwHow			= DIPH_BYOFFSET;
	prop.lMin				= -1000;
	prop.lMax				= +1000;
	hr = padDevice_->SetProperty( DIPROP_RANGE, &prop.diph );
	assert( hr == DI_OK );

	// �W���C�X�e�B�b�N�̂x���̐ݒ�
	prop.diph.dwObj			= DIJOFS_Y;
	hr = padDevice_->SetProperty( DIPROP_RANGE, &prop.diph );
	assert( hr == DI_OK );
	
	// x���̖����\�[���̐ݒ�
	hr = setDevProperty( DIPROP_DEADZONE, DIJOFS_X, DIPH_BYOFFSET, 5000 );
	assert( hr == DI_OK );

	// y���̖����]�[���̐ݒ�
	hr = setDevProperty( DIPROP_DEADZONE, DIJOFS_Y, DIPH_BYOFFSET, 5000 );
	assert( hr == DI_OK );

	// �A�N�Z�X���̎擾���s��
	getReacquire();

	// �쐬����
    return true;
}



/*===========================================================================*/
/**
 * @brief ��Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @retval true ����.
 : @retval false ���s.
 */
bool JoystickDI8::loadKeyState()
{
	// �f�o�C�X���쐬�ł��Ă��Ȃ���
	assert( padDevice_ != NULL );

	// �W���C�X�e�B�b�N�Ƀ|�[�����O�̎w�����o��
	padDevice_->Poll();

	// �W���C�X�e�B�b�N�f�[�^�[�̓ǂݍ���
	DIJOYSTATE2 js;
	HRESULT hr = padDevice_->GetDeviceState( sizeof( js ), &js );

	// �ǂݍ��߂Ȃ�������
	if( hr != DI_OK ){
		// �w��̃G���[��
		if( ( hr == DIERR_INPUTLOST ) || ( hr == DIERR_NOTACQUIRED ) ){
			// �A�N�Z�X�����Ď擾����
			getReacquire();
		}

		return false;
	}

	int joy_state = 0;	// ���͏�ԕϐ�

	// �����L�[�̃`�F�b�N
	if ( js.lX < 0 ) 
	{
		// ���������ꂽ
		joy_state |= JOY_LEFT;
	}
	else if ( js.lX > 0 )
	{
		// �E�������ꂽ
		joy_state |= JOY_RIGHT;
	}
	if ( js.lY < 0 )
	{
		// �オ�����ꂽ
		joy_state |= JOY_UP;
	}
	else if ( js.lY > 0 )
	{
		// ���������ꂽ
		joy_state |= JOY_DOWN;
	}

	// �{�^���̃`�F�b�N
	int bmask = JOY_BUTTON_1;
	for ( int i = 0; i < BUTTON_MAX; i++ )
	{
		if ( ( js.rgbButtons[i] & 0x80 ) != 0 )
		{
			joy_state |= bmask;
		}
		bmask <<= 1;
	}

	// �o�b�t�@�̓���ւ�
	int* tmp	= newBuf_;
	newBuf_		= oldBuf_;
	oldBuf_		= tmp;

	// ��Ԃ�ۑ�����
	*newBuf_ = joy_state;

	return true;
}



/*===========================================================================*/
/**
 * @brief ���̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �e���̏�ԃx�N�g��.
 */
Vector3 JoystickDI8::readAxisState()
{
	// �W���C�X�e�B�N�Ƀ|�[�����O�̎w�����o��
	padDevice_->Poll();

	// �W���C�X�e�B�b�N�̃f�[�^��ǂݍ���
	DIJOYSTATE js;
	HRESULT hr = padDevice_->GetDeviceState( sizeof( DIJOYSTATE ), &js );

	// �������ǂݍ��߂Ȃ�������
	if( hr != DI_OK ){
		if( ( hr == DIERR_INPUTLOST ) || ( hr == DIERR_NOTACQUIRED ) ){
			// �A�N�Z�X�����Ď擾����
			getReacquire();

			return Vector3( 0.0f, 0.0f, 0.0f );
		}
	}

	// ���̏�Ԃ��擾����
	Vector3 tmp;
	tmp.x = static_cast<float>(js.lX);
	tmp.y = static_cast<float>(js.lY);
	tmp.z = static_cast<float>(js.lZ);

	// �쐬�����x�N�g����Ԃ�
	return tmp;
}



/*=========================================================================*/
/**
 * @brief ��������̃L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���.
 * @retval 0 ����������Ă��Ȃ�.
 */
bool JoystickDI8::getKeyDown()
{
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyDown( i ) == true ){
			// ���͂���Ă���
			return true;
		}
	}
	// �������͂���Ă��Ȃ�����
	return false;
}



/*=========================================================================*/
/**
 * @brief �w�肵���L�[��������Ă��邩���ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true ������Ă���.
 * @retval false ������Ă��Ȃ�����.
 */
bool JoystickDI8::getKeyDown( unsigned int key )
{
	// �L�[��ϊ�����
	int conKey = convertKey( key );

	// �΂߃L�[�����ׂ�
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// �΂߃L�[����
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( *newBuf_ ) == conKey ){
			return true;
		}
	}

	// �ق��̃L�[����
	if( isDia == false && ( *newBuf_ & conKey ) != 0 ){
		// ������Ă���
		return true;
	}

	// ������Ă��Ȃ�
	return false;
}



/*=========================================================================*/
/**
 * @brief ������Ă���L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���L�[.
 * @retval 0 ����������Ă��Ȃ�.
 */
unsigned int JoystickDI8::getDownKey()
{
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyDown( i ) == true ){
			// ���͂�Ԃ�
			return i;
		}
	}
	// �������͂���Ă��Ȃ�����
	return 0;
}



/*=========================================================================*/
/**
 * @brief ��������̃L�[�������ꂽ�����ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool JoystickDI8::getKeyRelease()
{
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyRelease( i ) == true ){
			// ���͂���Ă���
			return true;
		}
	}
	// �������͂���Ă��Ȃ�����
	return false;
}



/*=========================================================================*/
/**
 * @brief �w�肵���L�[�������ꂽ�����ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool JoystickDI8::getKeyRelease( unsigned int key )
{
	int conKey = convertKey( key );

	// �΂߃L�[�����ׂ�
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// ����o�b�t�@���쐬
	int tmp = *oldBuf_ & ~*newBuf_;

	// �΂߃L�[����
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( tmp ) == conKey ){
			return true;
		}
	}

	// �ق��̃L�[����
	if( isDia == false && ( tmp & conKey ) != 0 ){
		// ������Ă���
		return true;
	}
	// ������Ă��Ȃ�
	return false;
}



/*=========================================================================*/
/**
 * @brief �����ꂽ�L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �����ꂽ�L�[.
 * @retval 0 ������Ă��Ȃ��B
 */
unsigned int JoystickDI8::getReleaseKey()
{
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyRelease( i ) == true ){
			// ���͂�Ԃ�
			return i;
		}
	}
	// �������͂���Ă��Ȃ�����
	return 0;
}



/*=========================================================================*/
/**
 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
 * 
 * @param[in] �Ȃ�.
 * @retval true �^�C�v���ꂽ.
 : @retval false �^�C�v����Ă��Ȃ�.
 */
bool JoystickDI8::getKeyTrigger()
{
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyTrigger( i ) == true ){
			// ���͂���Ă���
			return true;
		}
	}
	// �������͂���Ă��Ȃ�����
	return false;
}



/*=========================================================================*/
/**
 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �^�C�v���ꂽ.
 * @retval false �^�C�v����Ă��Ȃ�.
 */
bool JoystickDI8::getKeyTrigger( unsigned int key )
{
	int conKey = convertKey( key );

	// �΂߃L�[�����ׂ�
	bool isDia = false;
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( key == diagonalKeyList[i] ){
			isDia = true;
		}
	}

	// ����o�b�t�@���쐬
	int tmp = ~*oldBuf_ & *newBuf_;

	// �΂߃L�[����
	for( int i=0; i<DIAGONALCROSSKEY_MAX; i++ ){
		if( isDia == true && judgementDiagonalKey( tmp ) == conKey ){
			return true;
		}
	}
	
	// ���̑��̃L�[����
	if( isDia == false && ( tmp & conKey ) != 0 ){
		// �^�C�v����Ă���
		return true;
	}
	// �^�C�v����Ă��Ȃ�
	return false;
}



/*=========================================================================*/
/**
 * @brief �^�C�v���ꂽ�L�[���擾����
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
 * @retval 0 �^�C�v����Ă��Ȃ�.
 */
unsigned int JoystickDI8::getTriggerKey()
{	
	// ���͂���Ă��邩���ׂ�
	for( int i=0; i<JOYSTICKKEY_MAX; i++ ){
		if( getKeyTrigger( i ) == true ){
			// ���͂�Ԃ�
			return i;
		}
	}
	// �������͂���Ă��Ȃ�����
	return 0;
}



/*===========================================================================*/
/**
 * @brief �A�N�Z�X���̍Ď擾
 * 
 * @param[in] �Ȃ�.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool JoystickDI8::getReacquire()
{
	HRESULT hr = DI_OK;	// ����

	if( padDevice_ != 0 ){
		// DirectX�W���C�X�e�B�b�N�f�o�C�X�̃T�N�Z�X�����擾����
		hr = padDevice_->Acquire();

		// ����������
		if( hr == DI_OK ){
			// �擾�ɐ�������
			return true;
		}
		// �擾�Ɏ��s����
		else{
			if( hr == DIERR_NOTINITIALIZED ){
				MessageBoxA( 0, "Device is not initialized", 0, MB_OK );
			}
			return false;
		}
	}
	// �擾���s
	return false;
}



/*===========================================================================*/
/**
 * @brief �W���C�X�e�B�b�N�f�o�C�X���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void JoystickDI8::release()
{
	// �f�o�C�X���ݒ肳��Ă��邩
	if( padDevice_ != 0 ){
		// �A�N�Z�X����������
		padDevice_->Unacquire();

		// �f�o�C�X���������
		padDevice_->Release();

		padDevice_ = 0;
	}
}



/*===========================================================================*/
/**
 * @brief �v���p�e�B�̐ݒ�
 * 
 * @param[in] guid �ݒ�Ώۂ̎��ʎq.
 * @param[in] obj �ݒ肷�鍀��.
 * @param[in] how �ݒ�l�̕��@.
 * @param[in] val �ݒ�l.
 * @return ����.
 */
HRESULT JoystickDI8::setDevProperty( REFGUID guid, DWORD obj, DWORD how, DWORD val )
{
	DIPROPDWORD dipdw;
	dipdw.diph.dwSize		= sizeof( dipdw );
	dipdw.diph.dwHeaderSize	= sizeof( dipdw.diph );
	dipdw.diph.dwObj		= obj;
	dipdw.diph.dwHow		= how;
	dipdw.dwData			= val;

	return padDevice_->SetProperty( guid, &dipdw.diph );
}



/*=========================================================================*/
/**
 * @brief �΂ߓ��͔���
 * 
 * @param[in] buf ���肷��o�b�t�@.
 * @return ������Ă����L�[.
 */
int JoystickDI8::judgementDiagonalKey( int buf )
{
	// ���΂ߏオ������Ă��邩
	if( JOY_LEFT & buf && JOY_UP & buf ){
		return JOY_LEFTUP;
	}

	// ���΂߉���������Ă��邩
	if( JOY_LEFT & buf && JOY_DOWN & buf ){
		return JOY_LEFTDOWN;
	}

	// �E�΂ߏオ������Ă��邩
	if( JOY_RIGHT & buf && JOY_UP & buf ){
		return JOY_RIGHTUP;
	}

	// �E�΂߉���������Ă��邩
	if( JOY_RIGHT & buf && JOY_DOWN & buf ){
		return JOY_RIGHTDOWN;
	}

	// �΂߂͉�����Ă��Ȃ�����
	return 0;
}

	
	
/*=========================================================================*/
/**
 * @brief ���͂��ꂽ�L�[��ϊ�����
 * 
 * @param[in] key �ϊ�����L�[.
 * @return �ϊ���̃L�[.
 */
unsigned int JoystickDI8::convertKey( unsigned int key )
{
	// �ő吔�𒴂��Ă��邩
	if( key >= JOYSTICKKEYDI8_COUNT ){
		return 0;
	}

	return joystickKey[ key ];
}

	
	
/*========= EOF =============================================================*/