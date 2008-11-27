#ifndef _BLOCK_H_
#define _BLOCK_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManagerMediator.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;

class  Block : public ObjectBase
{
public:
	Block(IGameDevice& device, ObjectManagerMediator& objectManagerMediator, Option& option, GameSceneState& gameSceneState);
	~Block();

	void Initialize();
	void Terminate();
	bool IsTerminated();
	void RenderObject();
	void UpdateObject(float frameTimer);

private:

	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManagerMediator& m_objectManagerMediator;
	/** ゲームオプション */
	Option& m_option;
	/** ゲームシーンステート */
	GameSceneState m_gameSceneState;

	float x;
	float y;
	float size;
	float time;
};

#endif