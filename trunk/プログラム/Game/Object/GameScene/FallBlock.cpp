/*******************************************************************************/
/**
 * @file FallBlock.h.
 * 
 * @brief フォールブロッククラスソース定義.
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
* @brief コンストラクタ
*/
FallBlock::FallBlock(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState) :
	m_device(device), m_objectManager(objectManager), m_option(option), m_gameSceneState(gameSceneState), m_isTerminated(false)
{
	m_x		= 400.0f;
	m_y		= 0.0f; 
	m_speed	= 1.0f;
}
/*=========================================================================*/
/**
 * @brief デストラクタ.
 * 
 */
FallBlock::~FallBlock()
{

}

/*=========================================================================*/
/**
 * @brief 初期化処理.
 * 
 */
void FallBlock::Initialize()
{

}

/*=========================================================================*/
/**
 * @brief 終了処理.
 * 
 */
void FallBlock::Terminate()
{

}

/*=========================================================================*/
/**
 * @brief 終了しているかどうか.
 * 
 * @return 終了フラグ.
 */
bool FallBlock::IsTerminated()
{
	return 0;
}

/*=========================================================================*/
/**
 * @brief オブジェクトの描画処理.
 * 
 */
void FallBlock::RenderObject()
{
	Matrix4 rotate;
	rotate.setTranslate(1.0f,0.5f,0.5f);
	SpriteDesc sd;
	sd.textureID = TEXTUREID_TEST;
	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < 3; j++ ){
			sd.rect = Rect(m_x-(m_size*j),m_y+(m_size*i),m_x+(m_size*(j+1)),m_y+(m_size*(i+1)));
			m_device.GetGraphicDevice().Render( sd );
		}
	}

}

/*=========================================================================*/
/**
 * @brief オブジェクトの更新処理.
 * 
 * @param[in] frameTimer 更新タイマ.
 */
void FallBlock::UpdateObject(float frameTimer)
{

	m_y += m_speed;
}
