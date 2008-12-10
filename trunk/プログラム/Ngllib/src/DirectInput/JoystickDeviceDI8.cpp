/*******************************************************************************/
/**
 * @file JoystickDeviceDI8.cpp.
 * 
 * @brief DirectInput �W���C�X�e�B�b�N���̓f�o�C�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/07/26.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DirectInput/JoystickDeviceDI8.h"
#include	"Ngl/DirectInput/JoystickDI8.h"
#include	<algorithm>
#include	<functional>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DirectInput;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
JoystickDeviceDI8::JoystickDeviceDI8():
	inputDevice_( 0 ),		// DirectInput�f�o�C�X
	joyHwnd_( 0 ),			// �E�B���h�E�n���h��
	activeJoystickNo_( 0 )	// �A�N�e�B�u�ȃW���C�X�e�B�b�N�ԍ�
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
JoystickDeviceDI8::~JoystickDeviceDI8()
{
	// �f�o�C�X���폜
	JoystickList::iterator itor = joystickList_.begin();
	while( itor != joystickList_.end() ){
		delete *itor;
		itor = joystickList_.erase( itor );
	}

	// �f�o�C�X���쐬����Ă��邩
	if( inputDevice_ != 0 ){
		// �������
		release();
		inputDevice_ = 0;
	}
}



/*===========================================================================*/
/**
 * @brief ���̓f�o�C�X�̍쐬
 * 
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @return �Ȃ�.
 */
bool JoystickDeviceDI8::create(HWND hwnd)
{
	// �E�B���h�E�n���h����ݒ�
	joyHwnd_ = hwnd;

	HRESULT hr = DI_OK; // ���s����

	// DirectInput�I�u�W�F�N�g�̍쐬
	hr = DirectInput8Create( GetModuleHandle( 0 ), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&inputDevice_, 0 );
	assert( hr == DI_OK );
	
	// �R���g���[���[��񋓂���
	hr = inputDevice_->EnumDevices( DI8DEVCLASS_GAMECTRL, JoystickDeviceDI8::enumJoysticksCallback, this, DIEDFL_ATTACHEDONLY );
	assert( hr == DI_OK );

	 return true;
}



/*===========================================================================*/
/**
 * @brief �w��̃W���C�X�e�B�b�N���玲�̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �e���̏�ԃx�N�g��.
 */
Vector3 JoystickDeviceDI8::readAxisState()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->readAxisState();
	}

	return Vector3( 0.0f, 0.0f, 0.0f );
}



/*===========================================================================*/
/**
 * @brief �o�^����Ă���W���C�X�e�B�b�N�̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
bool JoystickDeviceDI8::loadKeyState()
{
	std::for_each(
		joystickList_.begin(),
		joystickList_.end(),
		std::mem_fun( &JoystickDI8::loadKeyState )
		);

	return true;
}



/*=========================================================================*/
/**
 * @brief �ڑ��f�o�C�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �ڑ��f�o�C�X��.
 */
unsigned int JoystickDeviceDI8::getConnectDeviceCount()
{
	return getCount();
}



/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�ɂ���f�o�C�X��ύX����
 * 
 * @param[in] no �ύX����f�o�C�X�ԍ�.
 * @return �Ȃ�.
 */
void JoystickDeviceDI8::setActiveDevice( unsigned int no )
{
	if( no < getCount() ){
		activeJoystickNo_ = no;
	}
}



/*=========================================================================*/
/**
 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
 */
unsigned int JoystickDeviceDI8::getActiveDeviceNo()
{
	return activeJoystickNo_;
}
	
	

/*=========================================================================*/
/**
 * @brief �L���L�[�����擾
 *
 * @retval true �擾����.
 * @retval false �擾���s.
 */
unsigned int JoystickDeviceDI8::getKeyCount()
{
	return JoystickDI8::JOYSTICKKEY_MAX;
}

	
	
/*=========================================================================*/
/**
 * @brief ��������̃L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���.
 * @retval 0 ����������Ă��Ȃ�.
 */
bool JoystickDeviceDI8::getKeyDown()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyDown();
	}

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
bool JoystickDeviceDI8::getKeyDown( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyDown( key );
	}

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
unsigned int JoystickDeviceDI8::getDownKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getDownKey();
	}
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
bool JoystickDeviceDI8::getKeyRelease()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyRelease();
	}
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
bool JoystickDeviceDI8::getKeyRelease( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyRelease( key );
	}
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
unsigned int JoystickDeviceDI8::getReleaseKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getReleaseKey();
	}
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
bool JoystickDeviceDI8::getKeyTrigger()

{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyTrigger();
	}
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
bool JoystickDeviceDI8::getKeyTrigger( unsigned int key )
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getKeyTrigger( key );
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
unsigned int JoystickDeviceDI8::getTriggerKey()
{
	if( isJoyDeviceExists( activeJoystickNo_ ) ){
		return joystickList_[ activeJoystickNo_ ]->getTriggerKey();
	}
	return 0;
}



/*===========================================================================*/
/**
 * @brief �ڑ�����Ă���W���C�X�e�B�b�N�̐��𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @return �p�b�h�̐�.
 */
/*===========================================================================*/
unsigned int JoystickDeviceDI8::getCount()
{
	return static_cast< unsigned int >( joystickList_.size() );
}



/*===========================================================================*/
/**
 * @brief �w��ԍ��̃W���C�X�e�B�b�N�����݂��Ă��邩���ׂ�
 * 
 * @param[in] no ���ׂ�W���C�X�e�B�b�N�ԍ�.
 * @retval true ���݂��Ă�.
 * @retval false ���݂��Ă��Ȃ�.
 */
/*===========================================================================*/
bool JoystickDeviceDI8::isJoyDeviceExists(unsigned int no)
{
	// ���X�g�S�̗̂v�f���Ɣ�r����
	if( static_cast< int >( joystickList_.size() ) > no ){
		// ���݂��Ă���
		return true;
	}
	// ���݂��Ă��Ȃ�
	return false;
}



/*===========================================================================*/
/**
 * @brief �W���C�X�e�B�b�N�f�o�C�X���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
/*===========================================================================*/
void JoystickDeviceDI8::release()
{
	// �o�^����Ă���W���C�X�e�B�b�N���������
	JoystickList::iterator i = joystickList_.begin();
	while( i != joystickList_.end() ){
		delete *i;

		i = joystickList_.erase( i );
	}

	// DirectX�C���v�b�g�f�o�C�X�I�u�W�F�N�g���������
	inputDevice_->Release();
	inputDevice_ = 0;
}



/*===========================================================================*/
/**
 * @brief �o�^����Ă���W���C�X�e�B�b�N�̃A�N�Z�X���̍Ď擾
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
/*===========================================================================*/
void JoystickDeviceDI8::getReacquire()
{
	std::for_each(
		joystickList_.begin(),
		joystickList_.end(),
		std::mem_fun( &JoystickDI8::getReacquire )
		);
}



/*===========================================================================*/
/**
 * @brief �f�o�C�X���쐬����
 * 
 * @param[in] pdinst �C���X�^���X.
 * @param[in] hnd �n���h��.
 * @return DIENUM_CONTINUE �񋓂𑱂���.
 */
/*===========================================================================*/
BOOL FAR PASCAL JoystickDeviceDI8::enumJoysticksCallback(LPCDIDEVICEINSTANCE pdinst, LPVOID hnd)
{
	JoystickDeviceDI8*	inputDevice	= static_cast< JoystickDeviceDI8* >( hnd );
	LPDIRECTINPUT8		pdi			= inputDevice->inputDevice_;

	// �f�o�C�X�N���X���쐬����
	JoystickDI8* device = new JoystickDI8();
	if( device->create( pdi, pdinst, inputDevice->joyHwnd_ ) == false ){
		return DIENUM_CONTINUE;
	}

	// �o�^�����ő吔�𒴂��Ă��Ȃ���
	if( inputDevice->joystickList_.size() < JOYSTIC_MAX ){
		// ���X�g�ɓo�^����
		inputDevice->joystickList_.push_back( device );
	}
	else{
		delete device;

		return DIENUM_CONTINUE;
	}

	// �f�[�^�t�H�[�}�b�g�̐ݒ�
    return DIENUM_CONTINUE;
}



/*========= EOF =============================================================*/