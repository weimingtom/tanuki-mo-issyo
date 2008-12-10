/*******************************************************************************/
/**
 * @file InputDeviceManager.h.
 * 
 * @brief ���̓f�o�C�X�Ǘ��҃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUTDEVICEMANAGER_H_
#define _NGL_INPUTDEVICEMANAGER_H_

#include	"Ngl/Manager/ObjectManager.h"
#include	"Ngl/Manager/IEntityVisitor.h"
#include	"IInputDevice.h"
#include	<functional>
#include	<algorithm>
#include	<cassert>
#include	<string>
#include	<map>


namespace Ngl{


/**
 * @class InputDeviceManager�D
 * @brief ���̓f�o�C�X�Ǘ��҃N���X.
 *
 * ���̓f�o�C�X���܂Ƃ߂ĊǗ����邽�߂̃N���X�ł��B
 * �Ǘ��Ҏ��̂�1�̓��̓f�o�C�X�Ƃ��Ĉ������Ƃ��ł��܂��B
 */
class InputDeviceManager : public IInputDevice
{
private:

	/**
	 * @class LoadVisitor.
	 * @brief ���̓f�o�C�X�Ǘ��� �L�[���X�V�K��҃N���X.
	 *
	 * �S�Ă̊Ǘ��v�f�̃L�[���͏�Ԃ��X�V����B
	 *
	 */
	class LoadVisitor : public IEntityVisitor< IInputDevice* >
	{
	public:

		/**
		 * @brief �v�f��K�₷��.
		 *
		 * @param[in] entity �K�₵���v�f.
		 * @return �Ȃ�.
		 */
		void visit( IInputDevice* entity )
		{
			// �L�[����ǂݍ���
			entity->loadKeyState();
		}
	};

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] id �ŏ��ɃA�N�e�B�u�ɂ���ID��.
	 */
	InputDeviceManager( unsigned int id=0 );
	

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~InputDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X��o�^
	 * 
	 * @param[in] name �o�^�f�o�C�X��.
	 * @param[in] device �o�^����f�o�C�X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	void regist( unsigned int name, IInputDevice* device );
	

	/*=========================================================================*/
	/**
	 * @brief �o�^����Ă���f�o�C�X�����ׂč폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clear();
	

	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�f�o�C�X�̐ڑ��f�o�C�X��ύX����
	 *
	 * ���݃A�N�e�B�u�ɂȂ��Ă�����̓f�o�C�X�́A���͂�ǂݎ��f�o�C�X��ύX���܂��B
	 * 
	 * @param[in] connectID �ύX����ڑ��f�o�C�X�ԍ�.
	 * @return �Ȃ�.
	 */
	void changeActiveConnectDevice( unsigned int connectID=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�̓��̓f�o�C�X�̃A�N�e�B�u�Ȑڑ��f�o�C�X�ԍ�.
	 */
	unsigned int getActiveConnectDeviceNo();
	
	
	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�f�o�C�X�́A�ڑ��f�o�C�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ڑ��f�o�C�X��.
	 */
	unsigned int getConnectDeviceCount();
	
	
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
	 * @brief ���̓f�o�C�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual unsigned int getDeviceCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief �L�[����ǂݍ���
	 *
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

	/** ���̓f�o�C�X�R���e�i�^ */
	typedef ObjectManager< unsigned int, IInputDevice* >	InputDeviceContainer;

private:

	/** �A�N�e�B�u�ȃf�o�C�X��ID */
	unsigned int			activeDeviceID_;

	/** ���̓f�o�C�X�R���e�i */
	InputDeviceContainer	inputDeviceContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/