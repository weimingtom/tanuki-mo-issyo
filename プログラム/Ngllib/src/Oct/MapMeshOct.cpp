/*******************************************************************************/
/**
 * @file MapMeshOct.cpp.
 * 
 * @brief Oct Oct�`���}�b�v���b�V���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Oct/MapMeshOct.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Utility.h"
#include	"Ngl/MathUtility.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Oct;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 * @param[in] creator ���b�V���쐬��.
 */
MapMeshOct::MapMeshOct( IRenderer* renderer, IMeshCreator* creator ):
	renderer_( renderer ),
	meshCreator_( creator ),
	mesh_( NULL ),
	nodeCount_( 0 ),
	nodes_( 0 )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MapMeshOct::~MapMeshOct()
{
	release();
}



/*=========================================================================*/
/**
 * @brief �t�@�C������f�[�^��ǂݍ���
 * 
 * @param[in] fileName �t�@�C����.
 * @return �Ȃ�.
 */
void MapMeshOct::loadFromFile( std::string fileName )
{
	// �t�@�C�����J��
	FileInputC stream;
	try{
		stream.open( fileName.c_str() );
	}
	catch( FileOpenException& e ){
		ADDEXCEPTIONINFO_FILELINE( e );
		e.outputConsol();
	}

	// ���̓X�g���[������ǂݍ���
	loadFromStream( stream );
}



/*=========================================================================*/
/**
 * @brief ���̓X�g���[������f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �Ȃ�.
 */
void MapMeshOct::loadFromStream( IInputStream& stream )
{
	try{
		// �I�N�c���[�t�@�C�����̓ǂݍ���
		unsigned int octree_mshInfo = 0;
		stream >> octree_mshInfo;

		// ���b�V���t�@�C�����̓ǂݍ���
		std::string meshFileName;
		stream >> meshFileName;

		// �t�@�C���p�X�𕪉�����
		std::string Drive;
		std::string Dir;
		Drive = Utility::getFilePathDrave( stream.streamName().c_str() );
		Dir = Utility::getFilePathDir( stream.streamName().c_str() );

		// �t���p�X�̃t�@�C�������쐬
		std::string meshFileNamePass;
		meshFileNamePass = Drive + Dir;
		meshFileName = meshFileNamePass + meshFileName;

		// ���b�V���f�[�^�𐶐�
		IMesh* mesh = meshCreator_->createFromFile( meshFileName );
		
		// �I�N�c���[���N���[���A�b�v����
		release();

		// �V�������b�V����ݒ肷��
		mesh_ = mesh;
		
		// �m�[�h���̓ǂݍ���
		stream >> nodeCount_;

		// �m�[�h�̔z��𐶐�����
		nodes_ = new MapMeshOct::Node[ nodeCount_ ];

		// �m�[�h�̔z���ǂݍ���
		for( unsigned int i=0; i<nodeCount_; i++ ){
			loadNodeData( stream, &nodes_[ i ] );
		}
	}
	catch( InputStreamException& e ){
		ADDEXCEPTIONINFO_FILELINE( e );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief ���_�錾�f�[�^���쐬
 * 
 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
 * @return �Ȃ�.
 */
void MapMeshOct::setVertexDeclaration( const InputSignatureDesc& inputSignature )
{
	mesh_->setVertexDeclaration( inputSignature );
}


	
/*=========================================================================*/
/**
 * @brief �`�揈��
 * 
 * @param[in] effect �G�t�F�N�g�̃|�C���^.
 * @param[in] matProj 4x4�����ϊ��s��\���̂̎Q��.
 * @param[in] matView 4x4����ϊ��s��\���̂̎Q��.
 * @return �Ȃ�.
 */
void MapMeshOct::draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView )
{
	// ��������쐬
	frustum_.createFromMatrices( matView, matProj );

	// �m�[�h��`�悷��
	drawNode( effect, nodes_[ 0 ] );
}



/*===========================================================================*/
/**
 * @brief �����Ƃ̏Փ˔���
 * 
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionLine( const float* line0, const float* line1 )
{
	// �m�[�h�Ɛ����Ƃ̏Փ˔��������
	return collisionNodeAndLine( nodes_[0], line0, line1 );
}



/*===========================================================================*/
/**
 * @brief 3D���Ƃ̏Փ˔���
 * 
 * @param[in] rayPos ���C�̎n�_.
 * @param[in] rayDir ���C�̕���.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionRay( const float* rayPos, const float* rayDir )
{
	// �m�[�h�ƃ��C�̏Փ˔��������
	return collisionNodeAndRay( nodes_[0], rayPos, rayDir );
}



/*===========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] center ���̂̒��S���W.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionSphere( const float* center, float radius )
{
	// �m�[�h�Ƌ��̂Ƃ̏Փ˔��������
	return collisionNodeAndSphere( nodes_[0], center, radius );
}



/*=========================================================================*/
/**
 * @brief �m�[�h�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[���̎Q��.
 * @param[in] node �f�[�^��ݒ肷��I�N�c���[�m�[�h�̃|�C���^.
 * @return �Ȃ�.
 */
void MapMeshOct::loadNodeData( IInputStream& stream, MapMeshOct::Node* node )
{
	// �m�[�h�̃f�[�^��ǂݍ���
	unsigned int leafNodeFlag;
	stream >> leafNodeFlag;

	// ���[�t�m�[�h������
	if( leafNodeFlag == LEAFNODE_FLAG ){
		node->leafNodeFlag = true;
	}
	else{
		node->leafNodeFlag = false;
	}

	// �m�[�h�̕��ƒ��S�_��ǂݍ���
	stream >> Vector3Input( node->posMin );
	stream >> Vector3Input( node->posMax );

	// �ʃf�[�^�O���[�v�̐���ǂݍ���
	stream >> node->info.faceGroupCount;

	// �ʃf�[�^�O���[�v�ԍ���ǂݍ���
	stream >> node->info.faceGroupIndex;

	// �q�m�[�h��ǂݍ���
	for( int j=0; j<8; ++j ){
		unsigned int nodeID = 0;
		stream >> nodeID;

		// �q�m�[�h��ݒ�
		if( static_cast<int>( nodeID ) != -1 ){
			node->nodes[ j ] = &nodes_[ nodeID ];
		}
		else{
			node->nodes[ j ] = 0;
		}
	}

	// ���[�t�m�[�h�̏ꍇ�̓m�[�h�p�̃��b�V���f�[�^��ݒ肷��
	node->mesh = NULL;
	if( node->leafNodeFlag == LEAFNODE_FLAG ){
		node->mesh = mesh_;
	}
}

	
	

/*=========================================================================*/
/**
 * @brief �m�[�h��`��
 * 
 * @param[in] effect �G�t�F�N�g�̃|�C���^.
 * @param[in] node �`�悷��m�[�h�\���̂̎Q��.
 * @return �Ȃ�.
 */
void MapMeshOct::drawNode( IEffect* effect, MapMeshOct::Node& node )
{
	// �m�[�h��������ɓ����Ă��邩
	if( frustum_.isBoxInside( node.posMin, node.posMax ) == false ){
		return;
	}

	// ���[�t�m�[�h��
	if( node.leafNodeFlag == true ){
		// ���b�V����`�悷��
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			node.mesh->drawSubset( node.info.faceGroupIndex+i, effect );
		}
	}

	// �q�m�[�h�����ׂĕ`�悷��
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			drawNode( effect, *node.nodes[i] );
		}
	}
}
	
	

/*=========================================================================*/
/**
 * @brief �������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MapMeshOct::release()
{
	// �I�N�c���[�̃m�[�h���폜
	if( nodes_ != NULL ){
		for( unsigned int i=0; i<nodeCount_; i++ ){
			// ���[�t�m�[�h��
			if( nodes_[i].leafNodeFlag == true ){
				// �m�[�h�̃��b�V�����N���A
				nodes_[i].mesh = NULL;
			}
		}
		// �m�[�h���폜
		delete[] nodes_;
		nodes_ = NULL;
	}

	// �m�[�h����������
	nodeCount_ = 0;

	// ���b�V�����폜
	if( mesh_ != NULL ){
		delete mesh_;
		mesh_ = NULL;
	}
}

	
	
/*===========================================================================*/
/**
 * @brief �m�[�h�Ɛ����̏Փ˔���
 * 
 * @param[in] node �I�N�c���[�m�[�h�̎Q��.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndLine( MapMeshOct::Node& node, const float* line0, const float* line1 )
{		
	// �m�[�h�̒��ɐ��������݂��邩�`�F�b�N����
	if( collision_.lineIsInsideBox( node.posMin, node.posMax, line0, line1 ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// ���[�t�m�[�h�̏ꍇ�̓��b�V���Ƃ̏Փ˔�����s��
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndLine( node.info.faceGroupIndex+i, line0, line1 );
			// �Փ˂��Ă��邩
			if( param.isCollision == true ){
				return param;
			}
			return param;
		}
	}

	// �S�Ă̎q�m�[�h�Ƃ̏Փ˔�����s��
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndLine( *node.nodes[i], line0, line1 );
			if( param.isCollision == true ){
				return param;
			}
		}
	}
	// ��Փ�
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief �m�[�h�ƃ��C�̏Փ˔���
 * 
 * @param[in] node �m�[�h.
 * @param[in] rayPos ���C�̈ʒu.
 * @param[in] rayDir ���C�̕���.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndRay( MapMeshOct::Node& node, const float* rayPos, const float* rayDir )
{
	// �m�[�h�̒��Ƀ��C�����݂��邩���ׂ�
	if( collision_.rayIsIntersectBox( node.posMin, node.posMax, rayPos, rayDir ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// ���[�t�m�[�h�̏ꍇ�̓��b�V���Ƃ̏Փ˔��������
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){ 
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndRay( node.info.faceGroupIndex+i, rayPos, rayDir );
			
			// �Փ˂��Ă�����
			if( param.isCollision == true ){
				return param;
			}

			return param;
		}
	}

	// ���ׂĂ̎q�m�[�h�Ƃ̏Փ˔��������
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndRay( *node.nodes[i], rayPos, rayDir );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// ��Փ�
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief �m�[�h�Ƌ��̂̏Փ˔���
 * 
 * @param[in] node �m�[�h.
 * @param[in] center ���̂̒��S���W.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MapMeshOct::collisionNodeAndSphere( MapMeshOct::Node& node, const float* center, float radius )
{
	// �m�[�h�̒��ɋ��̂����݂��Ȃ����`�F�b�N����
	if( collision_.sphereIsInsideBox( node.posMin, node.posMax, center, radius ) == false ){
		return PLANECOLLISIONREPORT_NOT_COLLISION;
	}

	// ���[�t�m�[�h��
	if( node.leafNodeFlag == true ){
		for( int i=0; i<node.info.faceGroupCount; ++i ){
			// ���b�V���Ƌ��̂̏Փ˔�����s��
			const PlaneCollisionReport& param = node.mesh->collisionFaceAndSphere( node.info.faceGroupIndex+i, center, radius );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// �S�Ă̎q�m�[�h�Ƃ̏Փ˔�����s��
	for( int i=0; i<8; i++ ){
		if( node.nodes[i] != 0 ){
			const PlaneCollisionReport& param = collisionNodeAndSphere( *node.nodes[i], center, radius );
			if( param.isCollision == true ){
				return param;
			}
		}
	}

	// ��Փ�
	return PLANECOLLISIONREPORT_NOT_COLLISION;
}



/*===== EOF ==================================================================*/