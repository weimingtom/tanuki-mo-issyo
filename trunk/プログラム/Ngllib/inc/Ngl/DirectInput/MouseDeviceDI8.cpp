/*******************************************************************************/
/**
 * @file MouseDeviceDI8.cpp.
 * 
 * @brief DirectInput �}�E�X���̓f�o�C�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/06/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"MouseDeviceDI8.h"
#include	<cassert>

namespace {

	/** �}�E�X�̃{�^���萔 */
	const static int MOUSEBUTTON_NONE	= 0x0000U;	/**< ����������Ă��Ȃ�	*/
	const static int MOUSEBUTTON_1		= 0x0001U;	/**< ���{�^��			*/
	const static int MOUSEBUTTON_2		= 0x0002U;	/**< �E�{�^��			*/
	const static int MOUSEBUTTON_3		= 0x0004U;	/**< �z�C�[��			*/
	const static int MOUSEBUTTON_4		= 0x0008U;	/**< �g���{�^��1		*/

	/** @brief �ϊ��L�[�z�� */
	static const unsigned int mouseKeys[] = {
		MOUSEBUTTON_NONE,	/**< 0 ����������Ă��Ȃ�	*/
		MOUSEBUTTON_1,		/**< 1 ���{�^��				*/
		MOUSEBUTTON_2,		/**< 2 �E�{�^��				*/
		MOUSEBUTTON_3,		/**< 3 �z�C�[��				*/
		MOUSEBUTTON_4		/**< 4 �g���{�^��1			*/
	};

	/** �}�E�X�L�[���� */
	static const unsigned int MOUSEKEY_COUNT = sizeof( mouseKeys ) / sizeof( unsigned int );

}

using namespace Ngl;
using namespace Ngl::DirectInput;

/*==== �萔�錾 =============================================================*/

const float MouseDeviceDI8::RATIO_DEFAULT = 1.0f;	// �f�t�H���g�̃}�E�X�ړ��䗦


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MouseDeviceDI8::MouseDeviceDI8() :
	inputDevice_( 0 ),			// Direct�C���v�b�g�f�o�C�X
	mouseDevice_( 0 ),			// Mouse�C���v�b�g�f�o�C�X
	nowBtn_( 0 ),				// ���̃}�E�X�̏��
	oldBtn_( 0 ),				// �O�̃}�E�X�̏��
	clip_( 0, 0, 640, 480 ),	// �}�E�X�̈ړ��\�͈�
	ratio_( RATIO_DEFAULT )		// �}�E�X�̈ړ��䗦
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MouseDeviceDI8::~MouseDeviceDI8()
{
	release();
}



/*===========================================================================*/
/**
 * @brief �}�E�X���̓f�o�C�X�̍쐬
 * 
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @retval true �쐬����.
 * @retval false �쐬���s.
 */
bool MouseDeviceDI8::create(HWND hwnd)
{
	HRESULT hr = DI_OK;	// ���s����
	
	// DirectInput�I�u�W�F�N�g�̍쐬
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );
	
	// DiRectInputDevice�I�u�W�F�N�g�̍쐬
	hr = inputDevice_->CreateDevice( GUID_SysMouse, &mouseDevice_, NULL );
	assert( hr == DI_OK );

	// �f�o�C�X���}�E�X�ɐݒ�
	hr = mouseDevice_->SetDataFormat( &c_dfDIMouse2 );
	assert( hr == DI_OK );
	 
	// �������x���̐ݒ�
	hr = mouseDevice_->SetCooperativeLevel( hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );
	assert( hr == DI_OK );
	 
	// �A�N�Z�X�����擾����
	 mouseDevice_->Acquire();

	return true;
}




/*=========================================================================*/
/**
 * @brief �L�[����ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool MouseDeviceDI8::loadKeyState()
{
	// �}�E�X���̓ǂݎ��
	readMouseData();

	// �ړ��ʂ��v�Z���č��W��ݒ肷��
	position_.x += ( ltm_.x * ratio_ );
	position_.y += ( ltm_.y * ratio_ );
	position_.z += ( ltm_.z * ratio_ );

	// �}�E�X�ʒu���N���b�s���O
	clipMouseCursor();

	return true;
}



/*=========================================================================*/
/**
 * @brief ���̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �e���̏�ԃx�N�g��.
 */
Vector3 MouseDeviceDI8::readAxisState()
{
	// �}�E�X�J�[�\���̈ʒu���W��Ԃ�
	return getMouseCursorPosition();
}



/*=========================================================================*/
/**
 * @brief �ڑ��f�o�C�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �ڑ��f�o�C�X��.
 */
unsigned int MouseDeviceDI8::getConnectDeviceCount()
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
void MouseDeviceDI8::setActiveDevice( unsigned int no )
{
	// �f�o�C�X��1�Ȃ̂ŁA�ύX���������Ȃ�.
}



/*=========================================================================*/
/**
 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
 */
unsigned int MouseDeviceDI8::getActiveDeviceNo()
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
unsigned int MouseDeviceDI8::getKeyCount()
{
	return MOUSEKEY_COUNT;
}


	
/*=========================================================================*/
/**
 * @brief ��������̃L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���.
 * @retval 0 ����������Ă��Ȃ�.
 */
bool MouseDeviceDI8::getKeyDown()
{
	// �����ꂽ�{�^�������݂��邩���ׂ�
	if( getDownKey() != MOUSEBUTTON_NONE ){
		// �����ꂽ�{�^��������
		return true;
	}
	// �����ꂽ�{�^�������݂��Ȃ�
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
bool MouseDeviceDI8::getKeyDown( unsigned int key )
{
	// �L�[��ϊ�
	unsigned int conKey = convertKey( key );

	// �L�[���Ɣ���
	if( ( nowBtn_ & conKey ) != 0 ){
		// ������Ă���
		return true;
	}
	// ������Ă��Ȃ�����
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
unsigned int MouseDeviceDI8::getDownKey()
{
	// �����ꂽ�{�^�������邩���ׂ�
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// ������Ă��邩���ׂ�
		if( getKeyDown( i ) == true ){
			return i;
		}
	}
	// ����������Ă��Ȃ�����
	return MOUSEBUTTON_NONE;
}



/*=========================================================================*/
/**
 * @brief ��������̃L�[�������ꂽ�����ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool MouseDeviceDI8::getKeyRelease()
{
	// �����ꂽ�{�^�������邩
	if( getReleaseKey() != MOUSEBUTTON_NONE ){
		// �����ꂽ�{�^����������
		return true;
	}
	// �����ꂽ�{�^������������
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
bool MouseDeviceDI8::getKeyRelease( unsigned int key )
{
	// �L�[��ϊ�����
	unsigned int conKey = convertKey( key );

	if( ( ( oldBtn_ & ~nowBtn_ ) & conKey ) != 0 ){
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
unsigned int MouseDeviceDI8::getReleaseKey()
{
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// ������Ă��邩���ׂ�
		if( getKeyRelease( i ) == true ){
			return i;
		}
	}
	// ����������Ă��Ȃ�����
	return MOUSEBUTTON_NONE;
}



/*=========================================================================*/
/**
 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
 * 
 * @param[in] �Ȃ�.
 * @retval true �^�C�v���ꂽ.
 : @retval false �^�C�v����Ă��Ȃ�.
 */
bool MouseDeviceDI8::getKeyTrigger()
{
	// �����ꂽ�{�^�������邩
	if( getTriggerKey() != MOUSEBUTTON_NONE ){
		// �����ꂽ�{�^����������
		return true;
	}
	// �����ꂽ�{�^������������
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
bool MouseDeviceDI8::getKeyTrigger( unsigned int key )
{
	// �L�[��ϊ�����
	unsigned int conKey = convertKey( key );

	if( ( ( ~oldBtn_ & nowBtn_ ) & conKey ) != 0 ){
		return true;
	}
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
unsigned int MouseDeviceDI8::getTriggerKey()
{
	for( int i=0; i<MOUSEKEY_COUNT; ++i ){
		// ������Ă��邩���ׂ�
		if( getKeyTrigger( i ) == true ){
			return i;
		}
	}
	// ����������Ă��Ȃ�����
	return MOUSEBUTTON_NONE;
}



/*===========================================================================*/
/**
 * @brief �}�E�X�J�[�\���̈ړ��\�͈͂�ݒ肷��
 * 
 * @param[in] clip �ړ��\�͈�.
 * @return �Ȃ�.
 */
void MouseDeviceDI8::setMouseCursorClip(const Rect& clip)
{
	clip_ = clip;
}



/*===========================================================================*/
/**
 * @brief �}�E�X�̈ړ��䗦��ݒ肷��
 * 
 * @param[in] ratio �ړ��䗦.
 * @return �Ȃ�.
 */
void MouseDeviceDI8::setMouseCursorRatio(float ratio)
{
	ratio_ = ratio;
}



/*===========================================================================*/
/**
 * @brief �}�E�X�̈ʒu���W��ݒ肷��
 * 
 * @param[in] x x���W.
 * @param[in] y y���W.
 * @param[in] z z���W.
 * @return �Ȃ�.
 */
void MouseDeviceDI8::setMousePosition(int x, int y, int z)
{
	position_.x = static_cast< float >( x );
	position_.y = static_cast< float >( y );
	position_.z = static_cast< float >( z );
}



/*===========================================================================*/
/**
 * @brief �}�E�X���͏��̎擾
 * 
 * @param[in] �Ȃ�.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
void MouseDeviceDI8::readMouseData()
{
	// �O��̏�Ԃ�ۑ�
	oldBtn_ = nowBtn_;

	DIMOUSESTATE2 dims = {}; // �}�E�X�f�[�^�\����

	// �}�E�X�̏�񂪎擾�ł�����
	HRESULT result = mouseDevice_->GetDeviceState( sizeof( DIMOUSESTATE2 ), &dims );
	if( result == DI_OK ){
		// �ړ��ʂ��擾����
		ltm_.x = static_cast< float >( dims.lX );
		ltm_.y = static_cast< float >( dims.lY );
		ltm_.z = static_cast< float >( dims.lZ );

		// �����ꂽ�{�^�����擾����
		nowBtn_ = 0;
		if( ( dims.rgbButtons[0] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_1;
		}
		if( ( dims.rgbButtons[1] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_2;
		}
		if( ( dims.rgbButtons[2] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_3;
		}
		if( ( dims.rgbButtons[3] & 0x80 ) != 0 ){
			nowBtn_ |= MOUSEBUTTON_4;
		}

	}
	// �ǂݎ��Ɏ��s����
	else{
		// �A�N�Z�X�����Ď擾����
		getReacquire();

		// �{�^����ǂݎ��s�ɐݒ�
		nowBtn_ = MOUSEBUTTON_NONE;
	}
}



/*===========================================================================*/
/**
 * @brief �}�E�X���W���N���b�s���O
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MouseDeviceDI8::clipMouseCursor()
{
	// x���W���N���b�v����
	if( position_.x < clip_.left ){
		position_.x = static_cast< float >( clip_.left );
	}
	else if( position_.x > clip_.right ){
		position_.x = static_cast< float >( clip_.right );
	}

	// y���W���N���b�v����
	if( position_.y < clip_.top ){
		position_.y = static_cast< float >( clip_.top );
	}
	else if( position_.y > clip_.bottom ){
		position_.y = static_cast< float >( clip_.bottom );
	}
}



/*===========================================================================*/
/**
 * @brief �}�E�X�̃A�N�Z�X���̍Ď擾
 * 
 * @param[in] �Ȃ�.
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool MouseDeviceDI8::getReacquire()
{
	HRESULT result;

	// �A�N�Z�X�����擾����
	result = mouseDevice_->Acquire();

	if( SUCCEEDED( result ) ){
		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief �}�E�X�f�o�C�X���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MouseDeviceDI8::release()
{
	// DirectInputDevice�I�u�W�F�N�g�̉��
	if( mouseDevice_ != NULL ){
		mouseDevice_->Unacquire();
		mouseDevice_->Release();
		mouseDevice_ = NULL;
	}

	// �f�o�C�X�����
	if( inputDevice_ != NULL ){
		inputDevice_->Release();
		inputDevice_ = NULL;
	}
}



/*=========================================================================*/
/**
 * @brief �L�[��ϊ�����
 * 
 * @param[in] key �ϊ�����L�[.
 * @return �ϊ���̃L�[.
 */
unsigned int MouseDeviceDI8::convertKey( unsigned int key )
{
	if( key >= MOUSEKEY_COUNT ){
		return 0;
	}

	return mouseKeys[ key ];
}

	
	
/*========= EOF =============================================================*/