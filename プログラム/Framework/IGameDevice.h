/*******************************************************************************/
/**
 * @file IGameDevice.h.<br>
 * 
 * @brief �Q�[���f�o�C�X�C���^�[�t�F�[�X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IGAMEDEVICE_H_
#define _IGAMEDEVICE_H_

#include	"IGraphicDevice.h"
#include	"IInputDevice.h"
#include	"ISoundDevice.h"
#include	"Define/Define.h"
#include	<string>

class IMovieScene;

/**
 * @brief �Q�[���f�o�C�X�C���^�[�t�F�[�X
 */
class IGameDevice
{
protected:

	/**
	 * @brief �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IGameDevice() {}

public:
	
	/**
	 * @brief �O���t�B�b�N�f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �O���t�B�b�N�f�o�C�X.
	 */
	virtual IGraphicDevice& GetGraphicDevice() = 0;

	
	/**
	 * @brief �T�E���h�f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �T�E���h�f�o�C�X.
	 */
	virtual ISoundDevice& GetSoundDevice() = 0;

	
	/**
	 * @brief ���̓f�o�C�X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���̓f�o�C�X.
	 */
	virtual IInputDevice& GetInputDevice() = 0;

	
	/**
	 * @brief �E�B���h�E�n���h�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�n���h��.
	 */
	virtual void* GetHWND() = 0;

	
	/**
	 * @brief �E�B���h�E�����擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E��.
	 */
	virtual int GetWindowWidth() = 0;

	
	/**
	 * @brief �E�B���h�E�̍������擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�̍���.
	 */
	virtual int GetWindowHeight() = 0;


	/**
	 * @brief �Q�[�����I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void Exit() = 0;

};

#endif

/*===== EOF ==================================================================*/