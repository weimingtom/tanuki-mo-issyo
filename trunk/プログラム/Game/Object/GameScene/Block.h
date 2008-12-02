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

	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;
	/** �I�u�W�F�N�g�}�l�[�W�����f�B�G�[�^ */
	ObjectManager& m_objectManager;
	/** �Q�[���I�v�V���� */
	Option& m_option;
	/** �Q�[���V�[���X�e�[�g */
	GameSceneState m_gameSceneState;
	/** �u���b�N�̔z�� */
	int blockMatrix[3][3];
	/** �u���b�N��ID */
	int blockID[2];
	/** �X�s�[�h */
	float speed;

	float x;
	float y;
	float size;
	float time;
};

#endif