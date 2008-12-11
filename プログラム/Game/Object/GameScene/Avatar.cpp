/*******************************************************************************/
/**
 * @file Avatar.cpp.
 * 
 * @brief �A�o�^�[�N���X�\�[�X.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"Avatar.h"


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Avatar::Avatar(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
Avatar::~Avatar()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void Avatar::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void Avatar::Terminate()
{
	m_isTerminated = true;
}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool Avatar::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void Avatar::RenderObject()
{

}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void Avatar::UpdateObject(float frameTimer)
{

}


/*===== EOF ===================================================================*/
