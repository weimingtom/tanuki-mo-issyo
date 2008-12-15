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
	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManager& m_objectManager;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState& m_gameSceneState;
	/** �v���[�� */
	Player& m_player;

};

#endif