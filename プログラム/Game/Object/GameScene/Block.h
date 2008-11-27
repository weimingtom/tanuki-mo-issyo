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

	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManagerMediator& m_objectManagerMediator;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState m_gameSceneState;

	float x;
	float y;
	float size;
	float time;
};

#endif