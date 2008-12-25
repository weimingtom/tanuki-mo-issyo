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
	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState& m_gameSceneState;


};

#endif