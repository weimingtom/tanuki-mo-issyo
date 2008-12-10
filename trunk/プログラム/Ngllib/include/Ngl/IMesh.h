/*******************************************************************************/
/**
 * @file IMesh.h.
 * 
 * @brief ���b�V���C���^�[�t�F�[�X��`.
 *
 * @date 2008/06/27.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_I_MESH_SKIN_H_
#define _NGL_I_MESH_SKIN_H_

#include	"IMeshCollision.h"
#include	"Material.h"
#include	"IInputStream.h"
#include	"IRenderer.h"
#include	"MeshInfo.h"
#include	"EffectOutputDesc.h"

namespace Ngl{


/**
 * @enum StreamType.
 * @brief �X�g���[���񋓌^.
 */
enum StreamType
{
	STREAM_TYPE_VERTEX		= 0,	/**< ���_�f�[�^						*/
	STREAM_TYPE_NORMAL		= 1,	/**< �@���f�[�^						*/
	STREAM_TYPE_DIFFUSE		= 2,	/**< �g�U���ˌ��J���[�f�[�^			*/
	STREAM_TYPE_SPECULAR	= 3,	/**< ���ʔ��ˌ��J���[�f�[�^			*/
	STREAM_TYPE_TEXCOORD	= 4,	/**< �e�N�X�`�����W�f�[�^			*/
	STREAM_TYPE_BLENDWEIGHT	= 5,	/**< ���_�E�F�C�g�f�[�^				*/
	STREAM_TYPE_MATRIXINDEX	= 6,	/**< �}�g���N�X�C���f�b�N�X�f�[�^	*/
	STREAM_TYPE_TANGENT		= 7,	/**< �ڃx�N�g���f�[�^				*/
	STREAM_TYPE_BINORMAL	= 8,	/**< �]�@���x�N�g���f�[�^			*/

	STREAM_TYPE_COUNT				/**< �X�g���[����					*/
};


/**
 * @struct MeshMaterial.
 * @brief ���b�V���p�}�e���A���f�[�^�\����.
 */
struct MeshMaterial
{
	/** �e�N�X�`���f�[�^�������Ă��邩 */
	bool			hasTexture;

	/** �}�e���A���f�[�^ */
	Material		material;

	/** �e�N�X�`���f�[�^ */
	ITexture*		texture;

	MeshMaterial():
		hasTexture( false ),
		texture( 0 )
	{}
};


/**
 * @struct FaceGroup.
 * @brief Msh �ʃf�[�^�O���[�v�\����.
 */
struct FaceGroup
{
	/** �ʏ��t���O */
	unsigned int	faceInfo;

	/** �}�e���A���i���o�[ */
	unsigned int	materialNo;

	/** ���_�C���f�b�N�X�� */
	unsigned int	numIndices;

	/** ���_�C���f�b�N�X�J�n�ʒu */
	unsigned int	startIndices;
};


/**
 * @interface IMesh�D
 * @brief �X�L�����b�V���C���^�[�t�F�[�X.
 */
class IMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IMesh(){}
	
	
	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] effect �G�t�F�N�g�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void draw( IEffect* effect ) = 0;


	/*=========================================================================*/
	/**
	 * @brief �T�u�Z�b�g��`��
	 * 
	 * @param[in] faceNo �ʃf�[�^�ԍ�.
	 * @param[in] effect �G�t�F�N�g.
	 * @return �Ȃ�.
	 */
	virtual void drawSubset( unsigned int faceNo, IEffect* effect ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���b�V�������擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���b�V�����\����.
	 */
	virtual const MeshInfo& info() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�o�͋L�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �G�t�F�N�g�o�͋L�q�q.
	 */
	virtual const EffectOutputDesc& effectOutputDesc() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�o�͋L�q�q��ݒ�
	 * 
	 * @param[in] desc �G�t�F�N�g�o�͋L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void effectOutputDesc( const EffectOutputDesc& desc ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��ʃf�[�^���擾����
	 *
	 * @param[in] faceNo �擾����ʃf�[�^�ԍ�.
	 * @return �ʃf�[�^�\����.
	 */
	virtual const FaceGroup& getFaceGroups( unsigned int faceNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �w�胁�b�V���}�e���A���f�[�^���擾����
	 *
	 * @param[in] matNo �擾���郁�b�V���}�e���A���ԍ�.
	 * @return ���b�V���}�e���A���\����.
	 */
	virtual const MeshMaterial& getMaterial( unsigned int matNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �C���f�b�N�X�o�b�t�@�|�C���^.
	 */
	virtual IBuffer* getIndexBuffer() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@���擾
	 * 
	 * @param[in] stream �擾����o�b�t�@�̎��.
	 * @return ���_�o�b�t�@�|�C���^.
	 */
	virtual IBuffer* getVertexBuffer( StreamType stream ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^���쐬
	 * 
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v�Ɛ����Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndLine( int faceNo, const float* line0, const float* line1 ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v��3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius ) = 0;


	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v�Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndSphere( int faceNo, const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/