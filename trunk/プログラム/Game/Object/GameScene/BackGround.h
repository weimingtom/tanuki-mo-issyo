#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_


#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"

class BackGround : public ObjectBase
{
public:
	BackGround(IGameDevice& device, GameSceneState& gameSceneState);

	~BackGround();

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
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;


};

#endif