/*******************************************************************************/
/**
 * @file IInputDevice.h.
 * 
 * @brief ���̓f�o�C�X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IINPUTDEVIDCE_H_
#define _NGL_IINPUTDEVIDCE_H_

#include	"Ngl/Vector3.h"

namespace Ngl{


/**
 * @interface IInputDevice�D
 * @brief ���̓f�o�C�X�C���^�[�t�F�[�X.
 */
class IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IInputDevice() {}


	/*=========================================================================*/
	/**
	 * @brief �L�[����ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	virtual bool loadKeyState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���̏�Ԃ�ǂݍ���
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e���̏�ԃx�N�g��.
	 */
	virtual Vector3 readAxisState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �ڑ��f�o�C�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ڑ��f�o�C�X��.
	 */
	virtual unsigned int getConnectDeviceCount() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�ɂ���f�o�C�X��ύX����
	 * 
	 * @param[in] no �ύX����f�o�C�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void setActiveDevice( unsigned int no ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �A�N�f�B�u�ɂȂ��Ă���f�o�C�X�ԍ����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �A�N�e�B�u�f�o�C�X�ԍ�.
	 */
	virtual unsigned int getActiveDeviceNo() = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �L���L�[�����擾
	 *
	 * @retval true �擾����.
	 * @retval false �擾���s.
	 */
	virtual unsigned int getKeyCount() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual bool getKeyDown() = 0;


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[��������Ă��邩���ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true ������Ă���.
	 * @retval false ������Ă��Ȃ�����.
	 */
	virtual bool getKeyDown( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ������Ă���L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� ������Ă���L�[.
	 * @retval 0 ����������Ă��Ȃ�.
	 */
	virtual unsigned int getDownKey() = 0;


	/*=========================================================================*/
	/**
	 * @brief ��������̃L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool getKeyRelease() = 0;


	/*=========================================================================*/
	/**
	 * @brief �w�肵���L�[�������ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �����ꂽ.
	 * @retval false ������Ă��Ȃ�.
	 */
	virtual bool getKeyRelease( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �����ꂽ�L�[�𒲂ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �����ꂽ�L�[.
	 * @retval 0 ������Ă��Ȃ��B
	 */
	virtual unsigned int getReleaseKey() = 0;


	/*=========================================================================*/
	/**
	 * @brief �Ȃɂ�����̃L�[���^�C�v���ꂽ��
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �^�C�v���ꂽ.
	 : @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool getKeyTrigger() = 0;


	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[���^�C�v���ꂽ�����ׂ�
	 * 
	 * @param[in] key ���ׂ�L�[.
	 * @retval true �^�C�v���ꂽ.
	 * @retval false �^�C�v����Ă��Ȃ�.
	 */
	virtual bool getKeyTrigger( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �^�C�v���ꂽ�L�[���擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @retval 1�ȏ� �^�C�v���ꂽ�L�[.
	 * @retval 0 �^�C�v����Ă��Ȃ�.
	 */
	virtual unsigned int getTriggerKey() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/