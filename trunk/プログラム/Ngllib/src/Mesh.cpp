/*******************************************************************************/
/**
 * @file Mesh.cpp.
 * 
 * @brief ���b�V���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/09.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Mesh.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/Utility.h"
#include	"Ngl/Vector4.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[.
 */
Mesh::Mesh( IRenderer* renderer ):
	renderer_( renderer ),
	meshInfo_( 0 ),
	indexBuffer_( 0 ),
	vertexDeclaration_( 0 )
{
	// �����l���쐬
	bufferList_[ STREAM_TYPE_VERTEX	]		= 0;
	bufferList_[ STREAM_TYPE_NORMAL	]		= 0;
	bufferList_[ STREAM_TYPE_DIFFUSE ]		= 0;
	bufferList_[ STREAM_TYPE_SPECULAR ]		= 0;
	bufferList_[ STREAM_TYPE_TEXCOORD ]		= 0;
	bufferList_[ STREAM_TYPE_BLENDWEIGHT ]	= 0;
	bufferList_[ STREAM_TYPE_MATRIXINDEX ]	= 0;
	bufferList_[ STREAM_TYPE_TANGENT ]		= 0;
	bufferList_[ STREAM_TYPE_BINORMAL ]		= 0;
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Mesh::~Mesh()
{
	release();
}



/*=========================================================================*/
/**
 * @brief ���_�t�H�[�}�b�g��ݒ�
 * 
 * @param[in] format ���_�t�H�[�}�b�g�\����.
 * @return �Ȃ�.
 */
void Mesh::setVertexFormat( const VertexFormat& format )
{
	info_.numVertices		= format.numVertices;
	info_.numIndices		= format.numIndices;
	info_.numWeights		= format.numWeights;
	info_.hasTextureSpace	= format.hasTextureSpace;
	info_.hasMatrixIndices	= format.hasMatrixIndices;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �o�b�t�@�f�[�^��ݒ�
 * 
 * @warning �ݒ肵���o�b�t�@��Mesh�N���X�ō폜����܂��B
 *
 * @param[in] buf �ݒ肷��o�b�t�@�̃|�C���^.
 * @param[in] type �ݒ肷��o�b�t�@�̃X�g���[���^�C�v.
 * @return �Ȃ�.
 */
void Mesh::setBuffer( IBuffer* buf, StreamType type )
{
	assert( buf != 0 );

	if( bufferList_[ type ] != 0 ){
		delete bufferList_[ type ];
	}

	bufferList_[ type ] = buf;
}

	
	
/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�o�b�t�@�f�[�^��ݒ�
 * 
 * @warning �ݒ肵���o�b�t�@��Mesh�N���X�ō폜����܂��B
 *
 * @param[in] buf �ݒ肷��o�b�t�@�̃|�C���^.
 * @return �Ȃ�.
 */
void Mesh::setIndexBuffer( IBuffer* buf )
{
	assert( buf != 0 );

	if( indexBuffer_ != 0 ){
		delete indexBuffer_;
	}

	indexBuffer_ = buf;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �}�e���A���f�[�^��ݒ�
 * 
 * Mesh�N���X�ɐݒ肵�����ԂŁA�}�e���A���ԍ��������I�ɐݒ肳��܂��B
 *
 * @warning �ݒ肵���}�e���A����Mesh�N���X�ō폜����܂��B
 * @warning �e�N�X�`�����ݒ肳��Ă����ꍇ�́A�Ƃ��ɍ폜����܂��B
 *
 * @param[in] material �ݒ肷��}�e���A���̃|�C���^.
 * @return �Ȃ�.
 */
void Mesh::setMaterial( MeshMaterial* material )
{
	materialArray_.push_back( material );

	// �e�N�X�`���������Ă��邩
	if( material->hasTexture == true ){
		info_.hasTexture = true;
	}

	// �}�e���A�������J�E���g
	++info_.numMaterials;
}



/*=========================================================================*/
/**
 * @brief �ʃf�[�^�O���[�v��ݒ�
 * 
 * Mesh�N���X�ɐݒ肵�����ԂŁA�ʃf�[�^�O���[�v�ԍ��������I�ɐݒ肳��܂��B
 *
 * @warning �ݒ肵���ʃf�[�^�O���[�v��Mesh�N���X�ō폜����܂��B
 *
 * @param[in] face �ݒ肷��ʃf�[�^�O���[�v�̃|�C���^.
 * @return �Ȃ�.
 */
void Mesh::setFaceGroup( FaceGroup* face )
{
	faceGroupArray_.push_back( face );

	// �ʃf�[�^�O���[�v�����J�E���g
	++info_.numSubsets;
}

	
	
/*=========================================================================*/
/**
 * @brief �Փ˔���f�[�^���쐬����
 *
 * �ݒ肳��Ă��钸�_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@����Փ˔���f�[�^���쐬���܂��B
 * �ǂ��炩�̃o�b�t�@���ݒ肳��Ă��Ȃ��ꍇ�́A�쐬����܂���B
 *
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Mesh::createCollisionData()
{
	assert( bufferList_[ STREAM_TYPE_VERTEX ] != 0 && indexBuffer_ != 0 );

	// ���b�V���Փ˔���f�[�^���쐬
	collision_.create( info_, bufferList_[ STREAM_TYPE_VERTEX ], indexBuffer_ );
}
	
	
	
/*=========================================================================*/
/**
 * @brief �������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Mesh::release()
{
	// ���_�錾�f�[�^���폜
	delete vertexDeclaration_;

	// �ʃf�[�^��z����폜
	FaceGroupArray::iterator itor = faceGroupArray_.begin();
	while( itor != faceGroupArray_.end() ){
		delete *itor;
		itor = faceGroupArray_.erase( itor );
	}

	// �}�e���A���f�[�^��z����폜
	MaterialArray::iterator matItor = materialArray_.begin();
	while( matItor != materialArray_.end() ){
		// �e�N�X�`���������Ă��邩
		if( (*matItor)->hasTexture == true ){
			// �e�N�X�`�����폜
			delete (*matItor)->texture;
		}
		delete *matItor;
		matItor = materialArray_.erase( matItor );
	}

	// �o�b�t�@���X�g���폜
	BufferList::iterator bufItor = bufferList_.begin();
	while( bufItor != bufferList_.end() )
	{
		delete bufItor->second;
		bufItor = bufferList_.erase( bufItor );
	}

	// �C���f�b�N�X�o�b�t�@���폜
	delete indexBuffer_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �`�揈��
 * 
 * @param[in] effect �G�t�F�N�g�̃|�C���^.
 * @return �Ȃ�.
 */
void Mesh::draw( IEffect* effect )
{	
	// �ʃf�[�^��`�悷��
	for( unsigned int face=0; face<info_.numSubsets; ++face ){
		// �T�u�Z�b�g��`�悷��
		drawSubset( face, effect );
	}
}



/*=========================================================================*/
/**
 * @brief �T�u�Z�b�g��`��
 * 
 * @param[in] faceNo �ʃf�[�^�ԍ�.
 * @param[in] effect �G�t�F�N�g.
 * @return �Ȃ�.
 */
void Mesh::drawSubset( unsigned int faceNo, IEffect* effect )
{
	assert( effect != 0 );
	
	// ���_�X�g���[����ݒ�
	renderer_->setVertexBuffer( &streamDescArray_[ 0 ], (unsigned int)streamDescArray_.size() );
	
	// ���_�錾�f�[�^��ݒ�
	renderer_->setVertexDeclaration( vertexDeclaration_ );

	// �C���f�b�N�X�o�b�t�@�̐ݒ�
	renderer_->setIndexBuffer( indexBuffer_, INDEX_TYPE_USHORT );

	// �}�e���A���ԍ����擾
	int matNo = faceGroupArray_[ faceNo ]->materialNo;

	// �}�e���A���f�[�^���G�t�F�N�g�ɏo�͂���
	if( effectOutputDesc().isOutMaterial == true ){
		effect->setVector( effectOutputDesc_.matAmbientName.c_str(), materialArray_[ matNo ]->material.ambient.r, materialArray_[ matNo ]->material.ambient.g, materialArray_[ matNo ]->material.ambient.b, materialArray_[ matNo ]->material.ambient.a );
		effect->setVector( effectOutputDesc_.matDiffuseName.c_str(), materialArray_[ matNo ]->material.diffuse.r, materialArray_[ matNo ]->material.diffuse.g, materialArray_[ matNo ]->material.diffuse.b, materialArray_[ matNo ]->material.diffuse.a );
		effect->setVector( effectOutputDesc_.matSpecularName.c_str(), materialArray_[ matNo ]->material.specular.r, materialArray_[ matNo ]->material.specular.g, materialArray_[ matNo ]->material.specular.b, materialArray_[ matNo ]->material.specular.a );
		effect->setVector( effectOutputDesc_.matEmissiveName.c_str(), materialArray_[ matNo ]->material.emissive.r, materialArray_[ matNo ]->material.emissive.g, materialArray_[ matNo ]->material.emissive.b, materialArray_[ matNo ]->material.emissive.a );
		effect->setScalar( effectOutputDesc_.matShininessName.c_str(), materialArray_[ matNo ]->material.power );
	}

	// �e�N�X�`�����G�t�F�N�g�ɏo�͂���
	if( materialArray_[ matNo ]->hasTexture == true && effectOutputDesc().isOutTexture == true ){
		effect->setTexture( effectOutputDesc_.textureName.c_str(), materialArray_[ matNo ]->texture );
	}

	// �p�X�̉񐔕������_�����O
	for( int pass=0; pass<effect->getNumPass(); ++pass ){
		// �G�t�F�N�g���J�n����
		effect->begin( pass );

		// ���_�C���f�b�N�X�𗘗p���ĕ`��
		renderer_->setPrimitive( PRIMITIVE_TYPE_TRIANGLE_LIST );
		renderer_->drawIndexed( faceGroupArray_[ faceNo ]->numIndices, faceGroupArray_[ faceNo ]->startIndices );

		// �G�t�F�N�g�̏I��
		effect->end();
	}
}

	

/*=========================================================================*/
/**
 * @brief ���b�V�������擾
 * 
 * @param[in] �Ȃ�.
 * @return ���b�V�����\����.
 */
const MeshInfo& Mesh::info() const
{
	return info_;
}



/*=========================================================================*/
/**
 * @brief �G�t�F�N�g�o�͋L�q�q���擾
 * 
 * @param[in] �Ȃ�.
 * @return �G�t�F�N�g�o�͋L�q�q.
 */
const EffectOutputDesc& Mesh::effectOutputDesc() const
{
	return effectOutputDesc_;
}



/*=========================================================================*/
/**
 * @brief �G�t�F�N�g�o�͋L�q�q��ݒ�
 * 
 * @param[in] desc �G�t�F�N�g�o�͋L�q�q.
 * @return �Ȃ�.
 */
void Mesh::effectOutputDesc( const EffectOutputDesc& desc )
{
	effectOutputDesc_ = desc;
}

	
	
/*=========================================================================*/
/**
 * @brief �w��ʃf�[�^���擾����
 *
 * @param[in] faceNo �擾����ʃf�[�^�ԍ�.
 * @return �ʃf�[�^�\����.
 */
const FaceGroup& Mesh::getFaceGroups( unsigned int faceNo )
{
	return *faceGroupArray_[ faceNo ];
}



/*=========================================================================*/
/**
 * @brief �w�胁�b�V���}�e���A���f�[�^���擾����
 *
 * @param[in] matNo �擾���郁�b�V���}�e���A���ԍ�.
 * @return ���b�V���}�e���A���\����.
 */
const MeshMaterial& Mesh::getMaterial( unsigned int matNo )
{
	return *materialArray_[ matNo ];
}
	
	
	
/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�o�b�t�@���擾
 * 
 * @param[in] �Ȃ�.
 * @return �C���f�b�N�X�o�b�t�@�|�C���^.
 */
IBuffer* Mesh::getIndexBuffer()
{
	return indexBuffer_;
}



/*=========================================================================*/
/**
 * @brief ���_�o�b�t�@���擾
 * 
 * @param[in] stream �擾����o�b�t�@�̎��.
 * @return ���_�o�b�t�@�|�C���^.
 */
IBuffer* Mesh::getVertexBuffer( StreamType stream )
{
	return bufferList_[ stream ];
}

	
	
/*=========================================================================*/
/**
 * @brief ���_�錾�f�[�^���쐬
 * 
 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
 * @return �Ȃ�.
 */
void Mesh::setVertexDeclaration( const InputSignatureDesc& inputSignature )
{
	// ���_�錾�f�[�^�����łɑ��݂��邩
	if( vertexDeclaration_ != 0 ){
		delete vertexDeclaration_;
	}

	// �X�g���[���^�C�v�z���ݒ�
	setStreamType();

	// ���C�A�E�g�f�[�^���쐬����
	std::vector< VertexDeclarationDesc > layout;	// ���_���C�A�E�g
	for( unsigned int streamNo=0; streamNo<streamTypeArray_.size(); ++streamNo ){
		StreamType type = streamTypeArray_[ streamNo ];
		VertexDeclarationDesc decl = { getSemantic( type ), 0, getType( type ), 0, streamNo };
		
		// �f�[�^��ݒ�
		layout.push_back( decl );
	}

	// ���_�錾�f�[�^���쐬����
	vertexDeclaration_ = renderer_->createVertexDeclaration( &layout[ 0 ], (unsigned int)layout.size(), inputSignature );
	assert( vertexDeclaration_ != 0 );

	// ���_�X�g���[����ݒ�
	setVertexStream();
}



/*===========================================================================*/
/**
 * @brief �����Ƃ̏Փ˔���
 * 
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& Mesh::collisionLine( const float* line0, const float* line1 )
{
	return collision_.line( line0, line1 );
}

	
	
/*===========================================================================*/
/**
 * @brief �w��̖ʃf�[�^�O���[�v�Ɛ����Ƃ̏Փ˔���
 * 
 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndLine( int faceNo, const float* line0, const float* line1 )
{
	// �J�n�|���S���f�[�^�ԍ������߂�
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// �|���S���Ɛ����̏Փ˔���
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndLine( planeNo, line0, line1 );
		if( report.isCollision == true ){
			return report;
		}

		// �|���S���f�[�^�ԍ����X�V
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief 3D���Ƃ̏Փ˔���
 * 
 * @param[in] rayPos 3D���̎n�_���W.
 * @param[in] rayDir 3D���̕���.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Mesh::collisionRay( const float* rayPos, const float* rayDir )
{
	return collision_.ray( rayPos, rayDir );
}



/*===========================================================================*/
/**
 * @brief �w��̖ʃf�[�^�O���[�v��3D���Ƃ̏Փ˔���
 * 
 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
 * @param[in] rayPos 3D���̎n�_���W.
 * @param[in] rayDir 3D���̕���.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir )
{
	// �J�n�|���S���f�[�^�ԍ������߂�
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// �|���S���Ɛ����̏Փ˔���
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndRay( planeNo, rayPos, rayDir );
		if( report.isCollision == true ){
			return report;
		}

		// �|���S���f�[�^�ԍ����X�V
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*===========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Mesh::collisionSphere( const float* center, float radius )
{
	return collision_.sphere( center, radius );
}



/*===========================================================================*/
/**
 * @brief �w��̖ʃf�[�^�O���[�v�Ƌ��̂Ƃ̏Փ˔���
 * 
 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Mesh::collisionFaceAndSphere( int faceNo, const float* center, float radius )
{
	// �J�n�|���S���f�[�^�ԍ������߂�
	int planeNo = faceGroupArray_[ faceNo ]->startIndices / 3; 

	// �|���S���Ɛ����̏Փ˔���
	for( unsigned int i=0; i<faceGroupArray_[ faceNo ]->numIndices/3; ++i ){
		const PlaneCollisionReport& report = collision_.polygonAndSphere( planeNo, center, radius );
		if( report.isCollision == true ){
			return report;
		}

		// �|���S���f�[�^�ԍ����X�V
		planeNo++;
	}

	return PLANECOLLISIONREPORT_NOT_COLLISION;
}

	

/*=========================================================================*/
/**
 * @brief ���_�X�g���[���f�[�^��ݒ�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Mesh::setVertexStream()
{
	// �ȑO�̃f�[�^���폜
	streamDescArray_.clear();

	IBuffer* buffers[] = {		// �o�b�t�@�̃|�C���^�z��
		bufferList_[ STREAM_TYPE_VERTEX	],			// STREAM_TYPE_VERTEX		= 0,
		bufferList_[ STREAM_TYPE_NORMAL	],			// STREAM_TYPE_NORMAL		= 1,
		bufferList_[ STREAM_TYPE_DIFFUSE ],			// STREAM_TYPE_DIFFUSE		= 2,
		bufferList_[ STREAM_TYPE_SPECULAR ],		// STREAM_TYPE_SPECULAR		= 3,
		bufferList_[ STREAM_TYPE_TEXCOORD ],		// STREAM_TYPE_TEXCOORD		= 4,
		bufferList_[ STREAM_TYPE_BLENDWEIGHT ],		// STREAM_TYPE_BLENDWEIGHT	= 5,
		bufferList_[ STREAM_TYPE_MATRIXINDEX ],		// STREAM_TYPE_MATRIXINDEX	= 6,
		bufferList_[ STREAM_TYPE_TANGENT ],			// STREAM_TYPE_TANGENT		= 7,
		bufferList_[ STREAM_TYPE_BINORMAL ]			// STREAM_TYPE_BINORMAL		= 8
	};

	// �X�g���[����ݒ�
	VertexStreamDesc streamDesc;
	for( unsigned int streamNo=0; streamNo<streamTypeArray_.size(); ++streamNo ){
		streamDesc.buffer	= buffers[ streamTypeArray_[ streamNo ] ];
		streamDesc.offset	= 0;
		streamDesc.stride	= getStride( streamTypeArray_[ streamNo ] );
		streamDescArray_.push_back( streamDesc );
	}
}

	
	
/*=========================================================================*/
/**
 * @brief �X�g���[���^�C�v��ݒ肷��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Mesh::setStreamType()
{
	// �ȑO�̃f�[�^���N���A
	streamTypeArray_.clear();

	// �ʒu���W���C�A�E�g�̐ݒ�
	streamTypeArray_.push_back( STREAM_TYPE_VERTEX );

	// �@���x�N�g�����C�A�E�g�̐ݒ�
	streamTypeArray_.push_back( STREAM_TYPE_NORMAL );

	// �g�U���ˌ��J���[���������邩
	if( bufferList_[ STREAM_TYPE_DIFFUSE ] != 0 ){
		streamTypeArray_.push_back( STREAM_TYPE_DIFFUSE );
	}

	// ���ʔ��ˌ��J���[���������邩
	if( bufferList_[ STREAM_TYPE_SPECULAR ] != 0 ){
		streamTypeArray_.push_back( STREAM_TYPE_SPECULAR );
	}

	// �e�N�X�`�����W���ݒ肳��Ă��邩
	if( bufferList_[ STREAM_TYPE_TEXCOORD ] != 0 ){
		// �e�N�X�`�����W���C�A�E�g�̐ݒ�
		streamTypeArray_.push_back( STREAM_TYPE_TEXCOORD );
	}

	// �X�L���f�[�^�����邩
	if( info_.numWeights != 0 ){
		// �X�L���E�F�C�g���C�A�E�g�̐ݒ�
		streamTypeArray_.push_back( STREAM_TYPE_BLENDWEIGHT );
	}

	// �s��C���f�b�N�X�f�[�^�����邩
	if( info_.hasMatrixIndices == true ){
		// �}�g���N�X�C���f�b�N�X���C�A�E�g�̐ݒ�
		streamTypeArray_.push_back( STREAM_TYPE_MATRIXINDEX );
	}

	// �e�N�X�`�����W�n�f�[�^�����邩
	if( info_.hasTextureSpace == true ){
		// �ڃx�N�g�����C�A�E�g�̐ݒ�
		streamTypeArray_.push_back( STREAM_TYPE_TANGENT );

		// �]�@���x�N�g�����C�A�E�g�̐ݒ�
		streamTypeArray_.push_back( STREAM_TYPE_BINORMAL );
	}
}


	
/*=========================================================================*/
/**
 * @brief �X�g���[���^�C�v����Z�}���e�B�b�N���擾
 * 
 * @param[in] type �X�g���[���^�C�v.
 * @return �Ȃ�.
 */
VertexSemantic Mesh::getSemantic( StreamType type )
{
	static const VertexSemantic semantics[] = {
		VERTEX_SEMANTIC_POSITION,			// STREAM_TYPE_VERTEX		= 0,
		VERTEX_SEMANTIC_NORMAL,				// STREAM_TYPE_NORMAL		= 1,
		VERTEX_SEMANTIC_DIFFUSE,			// STREAM_TYPE_DIFFUSE		= 2,
		VERTEX_SEMANTIC_SPECULAR,			// STREAM_TYPE_SPECULAR		= 3,
		VERTEX_SEMANTIC_TEXCOORD,			// STREAM_TYPE_TEXCOORD		= 4,
		VERTEX_SEMANTIC_BLENDWEIGHT,		// STREAM_TYPE_BLENDWEIGHT	= 5,
		VERTEX_SEMANTIC_BLENDINDICES,		// STREAM_TYPE_MATRIXINDEX	= 6,
		VERTEX_SEMANTIC_TANGENT,			// STREAM_TYPE_TANGENT		= 7,
		VERTEX_SEMANTIC_BINORMAL			// STREAM_TYPE_BINORMAL		= 8

	};

	return semantics[ type ];
}



/*=========================================================================*/
/**
 * @brief �X�g���[���^�C�v���璸�_�Z�}���e�B�b�N���擾
 * 
 * @param[in] type �X�g���[���^�C�v.
 * @return �Ȃ�.
 */
VertexType Mesh::getType( StreamType type )
{
	static const VertexType types[] = {
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_VERTEX		= 0,
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_NORMAL		= 1,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_DIFFUSE		= 2,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_SPECULAR		= 3,
		VERTEX_TYPE_FLOAT2,		// STREAM_TYPE_TEXCOORD		= 4,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_BLENDWEIGHT	= 5,
		VERTEX_TYPE_FLOAT4,		// STREAM_TYPE_MATRIXINDEX	= 6,
		VERTEX_TYPE_FLOAT3,		// STREAM_TYPE_TANGENT		= 7,
		VERTEX_TYPE_FLOAT3		// STREAM_TYPE_BINORMAL		= 8

	};

	return types[ type ];
}

	

/*=========================================================================*/
/**
 * @brief �X�g���[���^�C�v����1�v�f�̗v�f�����擾
 * 
 * @param[in] type �X�g���[���^�C�v.
 * @return �Ȃ�.
 */
unsigned int Mesh::getStride( StreamType type )
{
	static const unsigned int strides[] = {
		sizeof( float ) * 3,	// STREAM_TYPE_VERTEX		= 0,
		sizeof( float ) * 3,	// STREAM_TYPE_NORMAL		= 1,
		sizeof( float ) * 4,	// STREAM_TYPE_DIFFUSE		= 2,
		sizeof( float ) * 4,	// STREAM_TYPE_SPECULAR		= 3,
		sizeof( float ) * 2,	// STREAM_TYPE_TEXCOORD		= 4,
		sizeof( float ) * 4,	// STREAM_TYPE_BLENDWEIGHT	= 5,
		sizeof( float ) * 4,	// STREAM_TYPE_MATRIXINDEX	= 6,
		sizeof( float ) * 3,	// STREAM_TYPE_TANGENT		= 7,
		sizeof( float ) * 3		// STREAM_TYPE_BINORMAL		= 8

	};

	return strides[ type ];
}



/*===== EOF ==================================================================*/