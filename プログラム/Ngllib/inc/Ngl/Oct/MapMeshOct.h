/*******************************************************************************/
/**
 * @file MapMeshOct.h.
 * 
 * @brief Oct Oct�`���}�b�v���b�V���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OCT_MAPMESHOCT_H_
#define _NGL_OCT_MAPMESHOCT_H_

#include	"Ngl/Frustum.h"
#include	"Ngl/Collision.h"
#include	"Ngl/IMapMesh.h"
#include	"Ngl/IMesh.h"
#include	"Ngl/IMeshCreator.h"
#include	"Ngl/IInputStream.h"
#include	"Ngl/IRenderer.h"

namespace Ngl{


namespace Oct{


/**
 * @class MapMeshOct�D
 * @brief Oct Oct�`���}�b�v���b�V���N���X.
 */
class MapMeshOct : public IMapMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * @warning ���b�V���쐬�҂�MapMeshOct�N���X�ō폜����܂�.
	 * 
	 * @param[in] renderer �����_���[�N���X�̃|�C���^.
	 * @param[in] creator ���b�V���쐬��.
	 */
	MapMeshOct( IRenderer* renderer, IMeshCreator* creator );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~MapMeshOct();


	/*=========================================================================*/
	/**
	 * @brief �t�@�C������f�[�^��ǂݍ���
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �Ȃ�.
	 */
	void loadFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �Ȃ�.
	 */
	virtual void loadFromStream( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^���쐬
	 * 
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature );

	
	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] effect �G�t�F�N�g�̃|�C���^.
	 * @param[in] matProj 4x4�����ϊ��s��\���̂̎Q��.
	 * @param[in] matView 4x4����ϊ��s��\���̂̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView );


	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] rayPos ���C�̎n�_.
	 * @param[in] rayDir ���C�̕���.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& MapMeshOct::collisionRay( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius );

private:

	/** ���[�t�m�[�h�t���O */
	static const int LEAFNODE_FLAG = 1;

private:

	/**
	 * @struct NodeInfo.
	 * @brief Oct �m�[�h���\����
	 */
	struct NodeInfo
	{
		/** �ʃf�[�^���ԍ� */
		int	faceGroupIndex;

		/** �ʃf�[�^�O���[�v�� */
		int faceGroupCount;
	};

	/**
	 * @struct Node.
	 * @brief Oct �I�N�c���[�m�[�h�\����.
	 */
	struct Node
	{
		/** ���[�t�m�[�h�t���O */
		bool					leafNodeFlag;

		/** �m�[�h�̕� */
		Vector3			posMin;

		/** �m�[�h�̒��S�_ */
		Vector3			posMax;

		/** �m�[�h�̃��b�V���f�[�^ */
		IMesh*			mesh;

		/** �q�m�[�h�ւ̃|�C���^ */
		Node*			nodes[8];

		/** �m�[�h��� */
		NodeInfo		info;
	};

private:

	/*=========================================================================*/
	/**
	 * @brief �m�[�h�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] node �f�[�^��ݒ肷��I�N�c���[�m�[�h�̃|�C���^.
	 * @return �Ȃ�.
	 */
	void loadNodeData( IInputStream& stream, Node* node );
	
	
	/*=========================================================================*/
	/**
	 * @brief �m�[�h��`��
	 * 
	 * @param[in] effect �G�t�F�N�g�̃|�C���^.
	 * @param[in] node �`�悷��m�[�h�\���̂̎Q��.
	 * @return �Ȃ�.
	 */
	void drawNode( IEffect* effect, Node& node );
	
	
	/*=========================================================================*/
	/**
	 * @brief �������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*===========================================================================*/
	/**
	 * @brief �m�[�h�Ɛ����̏Փ˔���
	 * 
	 * @param[in] node �I�N�c���[�m�[�h�̎Q��.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	const PlaneCollisionReport& collisionNodeAndLine( Node& node, const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief �m�[�h�ƃ��C�̏Փ˔���
	 * 
	 * @param[in] node �m�[�h.
	 * @param[in] rayPos ���C�̈ʒu.
	 * @param[in] rayDir ���C�̕���.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	const PlaneCollisionReport& collisionNodeAndRay( Node& node, const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief �m�[�h�Ƌ��̂̏Փ˔���
	 * 
	 * @param[in] node �m�[�h.
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	const PlaneCollisionReport& collisionNodeAndSphere( MapMeshOct::Node& node, const float* center, float radius );

private:

	/** �����_���[�N���X�̃|�C���^ */
	IRenderer*				renderer_;

	/** ���b�V���쐬�� */
	IMeshCreator*			meshCreator_;

	/** ���b�V���f�[�^ */
	IMesh*					mesh_;

	/** �m�[�h�� */
	unsigned int			nodeCount_;

	/** �m�[�h */
	Node*					nodes_;

	/** ������ */
	Frustum					frustum_;

	/** �Փ˔��� */
	Collision				collision_;

};

} // namespace Oct

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/