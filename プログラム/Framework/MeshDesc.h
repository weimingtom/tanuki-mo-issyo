/*******************************************************************************/
/**
 * @file MeshDesc.h.<br>
 * 
 * @brief ���b�V���L�q�q�\���̒�`.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _MESH_DESC_H_
#define _MESH_DESC_H_

#include	"Define/Define.h"
#include	<string>


/**
 * @brief ���b�V���L�q�q�\���́D
 */
struct MeshDesc
{
	/** ���b�V���h�c */
	MeshID			meshID;

	/** �g�p����G�t�F�N�g�ԍ� */
	EffectID		effectID;

	/** �G�t�F�N�g�e�N�j�b�N�� */
	std::string		techniqueName;

	/** �}�e���A���J���[���o�͂��邩 */
	bool			isSetMaterial;

	/** �e�N�X�`�����o�͂��邩 */
	bool			isSetTexture;

	/** ���C�g�ԍ� */
	unsigned int	lightNo;

	/** ���W�ϊ��s�� */
	Matrix4			matrix;

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	MeshDesc() :
		meshID( MESHID_NONE ),
		effectID( EFFECTID_COM_PIXELLIGHTING ),
		lightNo( 0 ),
		techniqueName( "PixelLighting" ),
		isSetMaterial( true ),
		isSetTexture( true )
	{}
};

#endif

/*===== EOF ==================================================================*/