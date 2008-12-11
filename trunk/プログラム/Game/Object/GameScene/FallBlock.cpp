/*******************************************************************************/
/**
 * @file FallBlock.h.
 * 
 * @brief �t�H�[���u���b�N�N���X�\�[�X��`.
 *
 * @date 2008/12/8.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/

#include "FallBlock.h"


/*=========================================================================*/
/**
* @brief �R���X�g���N�^
*/
FallBlock::FallBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_player(player), m_isTerminated(false)
{
	m_x		= 400.0f;
	m_y		= 0.0f; 
	m_speed	= 1.0f;
}
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^.
 * 
 */
FallBlock::~FallBlock()
{

}

/*=========================================================================*/
/**
 * @brief ����������.
 * 
 */
void FallBlock::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief �I������.
 * 
 */
void FallBlock::Terminate()
{

}

/*=========================================================================*/
/**
 * @brief �I�����Ă��邩�ǂ���.
 * 
 * @return �I���t���O.
 */
bool FallBlock::IsTerminated()
{
	return 0;
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̕`�揈��.
 * 
 */
void FallBlock::RenderObject()
{
	Matrix4 rotate;
	rotate.setTranslate(1.0f,0.5f,0.5f);
	SpriteDesc sd;
	sd.textureID = TEXTUREID_TEST;
	
	sd.rect = Rect(m_x,m_y,m_x+(BLOCK_SIZE),m_y+(BLOCK_SIZE));
	m_device.GetGraphicDevice().Render( sd );
}

/*=========================================================================*/
/**
 * @brief �I�u�W�F�N�g�̍X�V����.
 * 
 * @param[in] frameTimer �X�V�^�C�}.
 */
void FallBlock::UpdateObject(float frameTimer)
{

	m_y += m_speed;
}
