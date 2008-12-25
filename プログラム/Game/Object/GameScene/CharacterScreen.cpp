/*******************************************************************************/
/**
 * @file CharacterScreen.cpp.
 * 
 * @brief �L�����N�^�[�X�N���[���\�[�X.
 *
 * @date 2008/12/11.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include	"CharacterScreen.h"

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^.
 */ 
CharacterScreen::CharacterScreen(IGameDevice &device, ObjectManager &objectManager, Option &option, GameSceneState &gameSceneState, Player &player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false),
		m_avatar(device, objectManager, option, gameSceneState, player)
{

}

/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 *
 */
CharacterScreen::~CharacterScreen()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void CharacterScreen::Initialize()
{
	m_avatar.Initialize();
}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void CharacterScreen::Terminate()
{
	m_avatar.Terminate();
	m_isTerminated = true;
}


/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool CharacterScreen::IsTerminated()
{
	return m_isTerminated;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void CharacterScreen::RenderObject()
{
	m_avatar.RenderObject();
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void CharacterScreen::UpdateObject(float frameTimer)
{
	m_avatar.UpdateObject(frameTimer);
}

Avatar& CharacterScreen::GetAvatar()
{
	return m_avatar;
}


/*===== EOF ===================================================================*/
