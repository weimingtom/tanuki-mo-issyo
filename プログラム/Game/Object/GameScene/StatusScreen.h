#ifndef _STATUSSCREEN_H_
#define _STATUSSCREEN_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		Player;

class StatusScreen : public ObjectBase
{
public:
	StatusScreen(IGameDevice &device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);
	~StatusScreen();
	void Initialize();

	void Terminate();

	bool IsTerminated();

	void RenderObject();

	void UpdateObject( float frameTimer );

private:
	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManager& m_objectManager;
	/** ゲームオプション */
	Option& m_option;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;
	/** プレーヤ */
	Player& m_player;

};

#endif