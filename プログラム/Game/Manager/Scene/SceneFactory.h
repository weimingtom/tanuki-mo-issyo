/*******************************************************************************/
/**
 * @file SceneFactory.h.
 * 
 * @brief �V�[���t�@�N�g���N���X.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_FACTORY_H_
#define _SCENE_FACTORY_H_

/*===== �C���N���[�h ==========================================================*/
#include	"IGameDevice.h"
class		SceneManagerMediator;
class		SceneBase;
class		Option;

/**
 * @brief SceneFactory�D
 */
class SceneFactory
{
public:
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 * 
	 * @param[in] device �Q�[���f�o�C�X.
	 * @param[in] SceneManagerMediator �V�[���}�l�[�W�����f�B�G�[�^.
	 * @param[in] Option �I�v�V����.
	 */
	SceneFactory(IGameDevice& device, SceneManagerMediator& sceneManagerMediator, Option& option);
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~SceneFactory();

	/*=========================================================================*/
	/**
	 * @brief �V�[���̐���.
	 * 
	 * @param[in] sceneID ��������V�[��.
	 * @return ���������V�[��.
	 */
	SceneBase* CreateScene(int sceneID);

private:
	
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �V�[���}�l�[�W�����f�B�G�[�^ */
	SceneManagerMediator& m_sceneManagerMediator;
	/** �Q�[���I�v�V���� */
	Option& m_option;
};

#endif

/*===== EOF ===================================================================*/