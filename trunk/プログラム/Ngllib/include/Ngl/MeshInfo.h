/*******************************************************************************/
/**
 * @file MeshInfo.h.
 * 
 * @brief ���b�V�����\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESHINFO_H_
#define _NGL_MESHINFO_H_

namespace Ngl{


/**
 * @struct MeshInfo.
 * @brief ���b�V�����\����.
 */
struct MeshInfo
{
	/** ���_�� */
	unsigned int		numVertices;

	/** ���_�C���f�b�N�X�� */
	unsigned int		numIndices;

	/** �T�u�Z�b�g�� */
	unsigned int		numSubsets;

	/** �}�e���A���f�[�^�� */
	unsigned int		numMaterials;

	/** ���_�E�F�C�g�� */
	unsigned int		numWeights;

	/** �s��C���f�b�N�X�����邩 */
	bool				hasMatrixIndices;

	/** �e�N�X�`���f�[�^������}�e���A�������邩 */
	bool				hasTexture;

	/** �e�N�X�`�����W�n�f�[�^�����邩 */
	bool				hasTextureSpace;

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	MeshInfo():
		numVertices( 0 ),
		numIndices( 0 ),
		numSubsets( 0 ),
		numMaterials( 0 ),
		numWeights( 0 ),
		hasMatrixIndices( false ),
		hasTexture( false ),
		hasTextureSpace( false )
	{}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/