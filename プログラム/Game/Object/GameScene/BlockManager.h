#ifndef _BLOCKMANAGER_H_
#define _BLOCKMANAGER_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Object/GameScene/Block.h"
#include	"Object/GameScene/FallBlock.h"
#include	"Object/GameScene/Field.h"
class		Player;
class		IGameDevice;

class BlockManager : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] objectManager オブジェクトマネージャ.
	 * @param[in] option ゲームオプション.
	 * @param[in] gameSceneState ゲームシーンステート.
	 */
	BlockManager(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~BlockManager();
	/*=========================================================================*/
	/**
	 * @brief 初期化処理.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief 終了処理.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief 終了しているかどうか.
	 * 
	 * @return 終了フラグ.
	 */
	bool IsTerminated();
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの描画処理.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの更新処理.
	 * 
	 * @param[in] frameTimer 更新タイマ.
	 */
	void UpdateObject(float frameTimer);

	Field&			GetField();

private:
	bool			m_isTerminated;
	IGameDevice&	m_device;
	ObjectManager&	m_objectManager;
	Option&			m_option;
	GameSceneState&	m_gameSceneState;
	Player& m_player;

	Block			*m_block;
	Field			m_field;
	FallBlock		*m_fallBlock;
};


#endif

/*===== EOF ===================================================================*/