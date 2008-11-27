/*******************************************************************************/
/**
 * @file SceneManagerMediator.h.
 * 
 * @brief �V�[���}�l�[�W������N���X��`.
 *
 * @date 2008/11/27.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _SCENE_MANAGER_MEDIATOR_H_
#define _SCENE_MANAGER_MEDIATOR_H_

/*===== �C���N���[�h ==========================================================*/
class	SceneFactoryBase;


/**
 * @brief �N���X���D
 */
class SceneManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief ���z�f�X�g���N�^.
	 *
	 */
	virtual ~SceneManagerMediator(){}
	
	/*=========================================================================*/
	/**
	 * @brief �V�[���̕ύX.
	 * 
	 * @param[in] sceneID �ύX����V�[��.
	 */
	virtual void ChangeScene(int sceneID) = 0;
	/*=========================================================================*/
	/**
	 * @brief �V�[���̌Ăяo��.
	 * 
	 * @param[in] sceneID �Ăяo���V�[��.
	 */
	virtual void CallScene(int sceneID) = 0;

};

#endif