/*******************************************************************************/
/**
 * @file MeshSkinDesc.h.<br>
 * 
 * @brief �X�L�����b�V���L�q�q�\���̒�`.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _MESH_SKIN_DESC_H_
#define _MESH_SKIN_DESC_H_

#include	"MeshDesc.h"
#include	"Define/Define.h"

/**
 * @brief �X�L�j���O���b�V���L�q�q�\���́D
 */
struct MeshSkinDesc
{
	/** ���b�V���L�q�q */
	MeshDesc		meshDesc;

	/** �X�P���g���t�@�C���ԍ� */
	MeshID			skeletonID;

	/** �A�j���[�V�����t�@�C���ԍ� */
	MeshID			animationID;

	/** �A�j���[�V�����ԍ� */
	unsigned int	animationNo;

	/** �A�j���[�V�����^�C�}�[�̍X�V�l */
	float			animationTimer;

	/** �A�j���[�V�������`���m��⊮���邩 */
	bool			isLerp;

	/** ��ԗv�f�̃A�j���[�V�����t�@�C���ԍ� */
	unsigned int	lerpAnimationID;

	/** ��ԗv�f�̃A�j���[�V�����ԍ� */
	unsigned int	lerpAnimationNo;

	/** ��ԗv�f�̃A�j���[�V�����X�V�l */
	float			lerpAnimationTimer;

	/** ��Ԓl(0.0f�`1.0f) */
	float			lerpValue;

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	MeshSkinDesc():
		skeletonID( MESHID_NONE ),
		animationID( MESHID_NONE ),
		animationNo( 0 ),
		animationTimer( 0.0f ),
		isLerp( false ),
		lerpAnimationID( 0 ),
		lerpAnimationNo( 0 ),
		lerpAnimationTimer( 0.0f ),
		lerpValue( 0.0f )
	{
		meshDesc.techniqueName	=	"Skin";
		meshDesc.effectID		=	EFFECTID_COM_SKIN;
	}
};

#endif

/*===== EOF ==================================================================*/