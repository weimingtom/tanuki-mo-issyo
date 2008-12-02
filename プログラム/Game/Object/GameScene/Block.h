#ifndef _BLOCK_H_
#define _BLOCK_H_

#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
class		IGameDevice;

class  Block : public ObjectBase
{
public:
	Block(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, int blockCID, int blockMID);
	~Block();

	void Initialize();
	void Terminate();
	bool IsTerminated();
	void RenderObject();
	void UpdateObject(float frameTimer);
	void InitializeMatrix();

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
	GameSceneState m_gameSceneState;
	/** ブロックの配列 */
	int blockMatrix[3][3];
	/** ブロックのID */
	int blockID[2];
	/** スピード */
	float speed;

	float x;
	float y;
	float size;
	float time;
};

#endif