/*******************************************************************************/
/**
 * @file InputDeviceManager.cpp.
 * 
 * @brief ���̓f�o�C�X�Ǘ��҃N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/InputDeviceManager.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] id �ŏ��ɃA�N�e�B�u�ɂ���ID��.
 */
InputDeviceManager::InputDeviceManager( unsigned int id ):
	activeDeviceID_( id )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
InputDeviceManager::~InputDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief �f�o�C�X��o�^
 * 
 * @param[in] name �o�^�f�o�C�X��.
 * @param[in] device �o�^����f�o�C�X�̃|�C���^.
 * @return �Ȃ�.
 */
void InputDeviceManager::regist( unsigned int name, IInputDevice* device )
{
	assert( device != NULL );

	inputDeviceContainer_.add( name, device );
}



/*=========================================================================*/
/**
 * @brief �o�^����Ă���f�o�C�X�����ׂč폜
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void InputDeviceManager::clear()
{
	inputDeviceContainer_.clear();
}



/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�f�o�C�X�̐ڑ��f�o�C�X��ύX����
 * 
 * ���݃A�N�e�B�u�ɂȂ��Ă�����̓f�o�C�X�́A���͂�ǂݎ��f�o�C�X��ύX���܂��B
 *
 * @param[in] connectID �ύX����ڑ��f�o�C�X�ԍ�.
 * @return �Ȃ�.
 */
void InputDeviceManager::changeActiveConnectDevice( unsigned int connectID )
{
	// ���̓f�o�C�X�ɐڑ�����Ă���f�o�C�X��ύX
	inputDeviceContainer_[ activeDeviceID_ ]->setActiveDevice( connectID );
}

	
	
/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ����擾
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ�.
 */
unsigned int InputDeviceManager::getActiveConnectDeviceNo()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getActiveDeviceNo();
}
	
	
	
/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�f�o�C�X�́A�ڑ��f�o�C�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �ڑ��f�o�C�X��.
 */
unsigned int InputDeviceManager::getConnectDeviceCount()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getConnectDeviceCount();
}

	
	
/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�ɂ���f�o�C�X��ύX����
 * 
 * @param[in] no �ύX����f�o�C�X�ԍ�.
 * @return �Ȃ�.
 */
void InputDeviceManager::setActiveDevice( unsigned int no )
{
	// ���̓f�o�C�X��ύX
	activeDeviceID_ = no;
}



/*=========================================================================*/
/**
 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
 */
unsigned int InputDeviceManager::getActiveDeviceNo()
{
	return activeDeviceID_;
}

	
	
/*=========================================================================*/
/**
 * @brief �L���L�[�����擾
 *
 * @retval true �擾����.
 * @retval false �擾���s.
 */
unsigned int InputDeviceManager::getKeyCount()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyCount();
}
	
	
	
/*=========================================================================*/
/**
 * @brief ���̓f�o�C�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
unsigned int InputDeviceManager::getDeviceCount()
{
	return inputDeviceContainer_.size();
}



/*=========================================================================*/
/**
 * @brief �L�[����ǂݍ���
 *
 * @retval true �擾����.
 * @retval false �擾���s.
 */
bool InputDeviceManager::loadKeyState()
{
	// �v�f����
	if( inputDeviceContainer_.empty() == true ){
		return false;
	}

	// �f�o�C�X����ǂݍ���
	LoadVisitor loadVisitor;
	inputDeviceContainer_.accept( loadVisitor );

	return true;
}



/*=========================================================================*/
/**
 * @brief ���̏�Ԃ�ǂݍ���
 * 
 * @param[in] �Ȃ�.
 * @return �e���̏�ԃx�N�g��.
 */
Vector3 InputDeviceManager::readAxisState()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->readAxisState();
}



/*=========================================================================*/
/**
 * @brief ��������̃L�[��������Ă��邩���ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���.
 * @retval 0 ����������Ă��Ȃ�.
 */
bool InputDeviceManager::getKeyDown()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyDown();
}



/*=========================================================================*/
/**
 * @brief �w�肵���L�[��������Ă��邩���ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true ������Ă���.
 * @retval false ������Ă��Ȃ�����.
 */
bool InputDeviceManager::getKeyDown( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyDown( key );
}



/*=========================================================================*/
/**
 * @brief ������Ă���L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� ������Ă���L�[.
 * @retval 0 ����������Ă��Ȃ�.
 */
unsigned int InputDeviceManager::getDownKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getDownKey();
}



/*=========================================================================*/
/**
 * @brief ��������̃L�[�������ꂽ�����ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool InputDeviceManager::getKeyRelease()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyRelease();
}



/*=========================================================================*/
/**
 * @brief �w�肵���L�[�������ꂽ�����ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �����ꂽ.
 * @retval false ������Ă��Ȃ�.
 */
bool InputDeviceManager::getKeyRelease( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyRelease( key );
}



/*=========================================================================*/
/**
 * @brief �����ꂽ�L�[�𒲂ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �����ꂽ�L�[.
 * @retval 0 ������Ă��Ȃ��B
 */
unsigned int InputDeviceManager::getReleaseKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getReleaseKey();
}



/*=========================================================================*/
/**
 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
 * 
 * @param[in] �Ȃ�.
 * @retval true �^�C�v���ꂽ.
 : @retval false �^�C�v����Ă��Ȃ�.
 */
bool InputDeviceManager::getKeyTrigger()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyTrigger();
}



/*=========================================================================*/
/**
 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
 * 
 * @param[in] key ���ׂ�L�[.
 * @retval true �^�C�v���ꂽ.
 * @retval false �^�C�v����Ă��Ȃ�.
 */
bool InputDeviceManager::getKeyTrigger( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyTrigger( key );
}



/*=========================================================================*/
/**
 * @brief �^�C�v���ꂽ�L�[���擾����
 * 
 * @param[in] �Ȃ�.
 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
 * @retval 0 �^�C�v����Ă��Ȃ�.
 */
unsigned int InputDeviceManager::getTriggerKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getTriggerKey();
}



/*===== EOF ==================================================================*/