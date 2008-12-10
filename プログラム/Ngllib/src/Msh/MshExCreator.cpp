/*******************************************************************************/
/**
 * @file MshExCreator.cpp.
 * 
 * @brief Msh msh,mshex�`�����b�V���t�@�C���쐬�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Msh/MshExCreator.h"
#include	"Ngl/Mesh.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"
#include	"Ngl/Utility.h"
#include	"Ngl/Vector4.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::Msh;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[.
 */
MshExCreator::MshExCreator( IRenderer* renderer ):
	renderer_( renderer ),
	textureCreator_( 0 ),
	hasMatrixIndices_( false ),
	hasTextureSpace_( false ),
	numMaterials_( 0 ),
	numFaceGroups_( 0 ),
	numVertices_( 0 ),
	numIndices_( 0 ),
	numWeights_( 0 )
{
	// ���b�V���������݃t���O��������
	std::memset( meshFlag, NOTWRITTEN, sizeof( unsigned int ) * MESHFLAG_MAX );
}

	
	
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MshExCreator::~MshExCreator()
{
	delete textureCreator_;
}

	
	
/*=========================================================================*/
/**
 * @brief �t�@�C������쐬����
 * 
 * @param[in] fileName �t�@�C����.
 * @return �쐬�������b�V���N���X.
 */
IMesh* MshExCreator::createFromFile( std::string fileName )
{
	// �t�@�C�����J��
	FileInputC stream;
	try{
		stream.open( fileName.c_str() );
	}
	catch( FileOpenException& e ){
		e += "[MshExCreator] : [createFromFile]";
		e.outputConsol();
	}

	// ���̓X�g���[������쐬
	return createFromStream( stream );
}



/*=========================================================================*/
/**
 * @brief ���̓X�g���[������쐬����
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�������b�V���N���X.
 */
IMesh* MshExCreator::createFromStream( IInputStream& stream )
{
	// ���b�V���f�[�^���쐬
	Mesh* mesh = new Mesh( renderer_ );

	try{
		// ���b�V���f�[�^��ǂݍ���
		loadMeshData( stream );
		
		// �}�e���A���f�[�^��ǂݍ���
		loadMaterial( stream, mesh );

		// �ʃf�[�^��ǂݍ���
		loadFaceGroup( stream, mesh );

		// �C���f�b�N�X�f�[�^��ǂݍ���
		IBuffer* index = loadIndices( stream );
		mesh->setIndexBuffer( index );

		// ���_�f�[�^��ǂݍ���
		if( meshFlag[ MESHFLAGTYPE_VERTEX ] == WRITTEN ){
			IBuffer* vertex = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( vertex, STREAM_TYPE_VERTEX );
		}

		// �@���x�N�g���f�[�^��ǂݍ���
		if( meshFlag[ MESHFLAGTYPE_NORMAL ] == WRITTEN ){
			IBuffer* normal = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( normal, STREAM_TYPE_NORMAL );
		}

		// �g�U���ˌ��J���[�z��̓ǂݍ���
		if( meshFlag[ MESHFLAGTYPE_DIFFUSECOLORS ] == WRITTEN ){
			IBuffer* diffuse = loadVertexBuffer( stream, 4 );
			mesh->setBuffer( diffuse, STREAM_TYPE_DIFFUSE );
		}

		// ���ʔ��ˌ��J���[�z��̓ǂݍ���
		if( meshFlag[ MESHFLAGTYPE_SPECULARCOLORS ] == WRITTEN ){
			IBuffer* specular = loadVertexBuffer( stream, 4 );
			mesh->setBuffer( specular, STREAM_TYPE_SPECULAR );
		}
		
		// �e�N�X�`�����W�f�[�^��ǂݍ���
		if( meshFlag[ MESHFLAGTYPE_NUMTEXCOORDS ] != 0 ){
			IBuffer* texcoord = loadVertexBuffer( stream, 2 );
			mesh->setBuffer( texcoord, STREAM_TYPE_TEXCOORD );
		}

		// ���_�E�F�C�g�f�[�^�����邩
		if( hasMatrixIndices_ == true ){
			// ���_�E�F�C�g�f�[�^��ǂݍ���
			IBuffer* blendWeights = loadVertexWeight( stream );
			mesh->setBuffer( blendWeights, STREAM_TYPE_BLENDWEIGHT );
		}

		// �X�L����񂪂��邩
		if( meshFlag[ MESHFLAGTYPE_MATRIXINDICES ] == WRITTEN ){
			// �}�g���N�X�C���f�b�N�X�f�[�^��ǂݍ���
			IBuffer* matrixIndices = loadMatrixIndex( stream );
			mesh->setBuffer( matrixIndices, STREAM_TYPE_MATRIXINDEX );
		}

		// �e�N�X�`�����W�n��񂪂��邩
		if( hasTextureSpace_ == true ){
			// �ڃx�N�g���f�[�^��ǂݍ���
			IBuffer* tangent = loadVertexBuffer( stream, 3 );
			mesh->setBuffer( tangent, STREAM_TYPE_TANGENT );

			// �]�@���x�N�g���f�[�^��ǂݍ���
			IBuffer* binormal = loadVertexBuffer( stream,  3 );
			mesh->setBuffer( binormal, STREAM_TYPE_BINORMAL );
		}

		// ���_�t�H�[�}�b�g��ݒ�
		setVertexFormat( mesh );

		// �Փ˔���f�[�^���쐬
		mesh->createCollisionData();
	}
	catch( InputStreamException& e ){
		delete mesh;
		mesh = 0;

		e.add( "MshExCreator", "createFormStream" );
		e.outputConsol();
	}

	return mesh;
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���쐬�N���X��ݒ�
 * 
 * @warning �ݒ肵���N���X��MshExCreator�N���X�ō폜����܂�.
 *
 * @param[in] creator �e�N�X�`���쐬�N���X�̃|�C���^.
 * @return �Ȃ�.
 */
void MshExCreator::setTextureCreator( ITextureCreator* creator )
{
	delete textureCreator_;

	textureCreator_ = creator;
}

	
	
/*=========================================================================*/
/**
 * @brief ���b�V���f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �Ȃ�.
 */
void MshExCreator::loadMeshData( IInputStream& stream )
{
	try{
		// ���b�V�����t���O��ǂݍ���
		unsigned int meshInfo = 0;
		stream >> meshInfo;

		// ���b�V���t���O���̓ǂݍ���
		unsigned int meshFlagCount = 0;
		stream >> meshFlagCount;

		// ���b�V���t���O�̓ǂݍ���
		for( unsigned int i=0; i<meshFlagCount; ++i ){
			stream >> meshFlag[ i ];
		}

		// ���_�E�F�C�g���𔲂��o��
		numWeights_ = meshFlag[ MESHFLAGTYPE_NUMWEIGHTS ];

		// �e�N�X�`�����W�n�f�[�^�����݂��Ă��邩
		if( meshFlag[ MESHFLAGTYPE_TEXTURESPACE ] == WRITTEN ){
			hasTextureSpace_ = true;
		}
		
		// �s��C���f�b�N�X�f�[�^�����邩
		if( meshFlag[ MESHFLAGTYPE_MATRIXINDICES ] == WRITTEN ){
			hasMatrixIndices_ = true;
		}

		// �}�e���A���f�[�^���̓ǂݍ���
		stream >> numMaterials_;

		// �ʃf�[�^�O���[�v���̓ǂݍ���
		stream >> numFaceGroups_;

		// ���_�C���f�b�N�X�f�[�^���̓ǂݍ���
		stream >> numIndices_;

		// ���_���W�f�[�^���̓ǂݍ���
		stream >> numVertices_;
	}
	catch( InputStreamException& e ){
		throw e;
	}
}

	
	
/*=========================================================================*/
/**
 * @brief �}�e���A���f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] mesh ���b�V��.
 * @return �Ȃ�.
 */
void MshExCreator::loadMaterial( IInputStream& stream, Mesh* mesh )
{
	for( unsigned int i=0; i<numMaterials_; ++i ){
		MeshMaterial* mat = new MeshMaterial;
		
		// �ʏ��t���O��ǂݍ���
		unsigned int bMaterial = 0;
		stream >> bMaterial;

		// �����J���[��ǂݍ���
		stream >> Color4Input( mat->material.ambient );

		// �g�U���ˌ��J���[��ǂݍ���
		stream >> Color4Input( mat->material.diffuse );

		// ���ʔ��ˌ��J���[��ǂݍ���
		stream >> Color4Input( mat->material.specular );

		// ���ˌ��J���[��ǂݍ���
		stream >> Color4Input( mat->material.emissive );

		// ���ʔ��˗��̓ǂݍ���
		stream >> mat->material.power;

		// �e�N�X�`���������Ă��邩
		if( ( bMaterial & TEXTUREMAPPED ) != 0 ){
			// �e�N�X�`���t�@�C����ǂݍ���
			std::string fileName;
			stream >> fileName;

			// �t�@�C���p�X�𕪉�����
			std::string texFileNamePass;
			std::string drive	= Utility::getFilePathDrave( stream.streamName().c_str() );
			std::string dir		= Utility::getFilePathDir( stream.streamName().c_str() );

			// �t�@�C���p�X�ɘA��
			texFileNamePass = drive + dir;

			// �t�@�C�����ɘA��
			fileName = texFileNamePass + fileName;

			// �e�N�X�`���𐶐�
			assert( textureCreator_ != NULL );
			textureCreator_->setRenderer( renderer_ );
			mat->texture = textureCreator_->create( fileName );
			assert( mat->texture != NULL );

			// �~�b�v�}�b�v���쐬
			renderer_->generateMipmap( mat->texture );
	
			mat->hasTexture = true;
		}

		// �쐬�����}�e���A����ݒ�
		mesh->setMaterial( mat );
	}
}



/*=========================================================================*/
/**
 * @brief �ʃf�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] mesh ���b�V��.
 * @return �Ȃ�.
 */
void MshExCreator::loadFaceGroup( IInputStream& stream, Mesh* mesh )
{
	for( unsigned int i=0; i<numFaceGroups_; ++i ){
		FaceGroup* facegroup = new FaceGroup;

		// �ʏ��t���O�̓ǂݍ���
		stream >> facegroup->faceInfo;

		// �}�e���A���C���f�b�N�X�̓ǂݍ���
		stream >> facegroup->materialNo;

		// ���_�C���f�b�N�X�̊J�n�ʒu�̓ǂݍ���
		stream >> facegroup->startIndices;

		// ���_�C���f�b�N�X���̓ǂݍ���
		stream >> facegroup->numIndices;

		// �ʃf�[�^��o�^
		mesh->setFaceGroup( facegroup );
	}
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�����o�b�t�@.
 */
IBuffer* MshExCreator::loadIndices( IInputStream& stream )
{
	std::vector< unsigned short > indices;

	// �C���f�b�N�X�f�[�^��ǂݍ���
	for( unsigned int i=0; i<numIndices_; ++i ){
		unsigned short ent = 0;
		stream >> ent;
		indices.push_back( ent );
	}

	// �C���f�b�N�X�o�b�t�@�̍쐬
	BufferDesc indexBufferDesc;
	indexBufferDesc.type		= BUFFER_TYPE_INDEX;
	indexBufferDesc.size		= sizeof( unsigned short ) * (unsigned int)indices.size();
	indexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;

	IBuffer* tmp = renderer_->createBuffer( indexBufferDesc, &indices[ 0 ] );
	assert( tmp != NULL );

	return tmp;
}



/*=========================================================================*/
/**
 * @brief ���_�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] numElements 1�v�f�̗v�f��.
 * @return �쐬�����o�b�t�@.
 */
IBuffer* MshExCreator::loadVertexBuffer( IInputStream& stream, unsigned int numElements )
{
	std::vector< float > vertices;
	
	// ���_�f�[�^��ǂݍ���
	for( unsigned int i=0; i<numVertices_ * numElements; i++ ){
		float ent = 0.0f;
		stream >> ent;
		vertices.push_back( ent );
	}

	// ���_�o�b�t�@���쐬
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( float ) * (unsigned int)vertices.size();
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;

	IBuffer* tmp  = renderer_->createBuffer( vertexBufferDesc, &vertices[ 0 ] ); 
	assert( tmp != NULL );

	return tmp;
}



/*=========================================================================*/
/**
 * @brief ���_�E�F�C�g�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�����o�b�t�@.
 */
IBuffer* MshExCreator::loadVertexWeight( IInputStream& stream )
{
	// �����p�E�F�C�g�z����쐬
	float* fWeights = new float[ numVertices_ ];
	std::memset( fWeights, 1, sizeof( float ) * numVertices_ );

	// �t�@�C������f�[�^��ǂݍ���
	Vector4* blendWeights = new Vector4[ numVertices_ ];
	for( unsigned int i=0; i<numWeights_; ++i ){
		for( unsigned int j=0; j<numVertices_; ++j ){
			float* tmp = (float*)blendWeights[ j ];
			float weight = 0.0f;
			stream >> weight;

			tmp[ i ] = weight;
			fWeights[ j ] += weight;
		}
	}

	// �����̃E�F�C�g�l��ݒ�
	for( unsigned int i=0; i<numVertices_; ++i ){
		float* tmp = (float*)blendWeights[ i ];
		tmp[ numWeights_ ] = 1.0f - fWeights[ i ];
	}

	// �o�b�t�@�f�[�^���쐬����
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( Vector4 ) * numVertices_;
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;
	IBuffer* tmp = renderer_->createBuffer( vertexBufferDesc, blendWeights );

	// �쐬�������_�E�F�C�g�z��̏���
	delete[] blendWeights;

	// �����p�E�F�C�g�z����폜
	delete[] fWeights;

	assert( tmp != NULL );
	return tmp;
}



/*=========================================================================*/
/**
 * @brief �}�g���N�X�C���f�b�N�X�f�[�^��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�����o�b�t�@.
 */
IBuffer* MshExCreator::loadMatrixIndex( IInputStream& stream )
{
	// �t�@�C������f�[�^��ǂݍ���
	Vector4* indexData = new Vector4[ numVertices_ ];
	for( unsigned int i=0; i<numVertices_; ++i ){
		float* tmp = (float*)indexData[ i ];
		unsigned int j=0;

		// �f�[�^��ǂݍ���
		unsigned int index=0;
		stream >> Ngl::hex >> index;
		stream.readType( STREAM_READ_TYPE_10 );
		
		// �}�g���N�X�C���f�b�N�X�����o��
		for( j=0; j<numWeights_; ++j ){
			tmp[ j ] = static_cast< float >( ( index >> ( j*8 ) ) & 0xff );
		}
		tmp[ numWeights_ ] = static_cast< float >( ( index >> ( j*8 ) ) & 0xff );
	}

	// �o�b�t�@�f�[�^���쐬����
	BufferDesc vertexBufferDesc;
	vertexBufferDesc.type		= BUFFER_TYPE_VERTEX;
	vertexBufferDesc.size		= sizeof( Vector4 ) * numVertices_;
	vertexBufferDesc.usage		= BUFFER_USAGE_DEFAULT;
	IBuffer* tmp = renderer_->createBuffer( vertexBufferDesc, indexData );
	
	// �W�J�f�[�^���폜
	delete[] indexData;

	assert( tmp != NULL );
	return tmp;
}



/*=========================================================================*/
/**
 * @brief ���_�t�H�[�}�b�g��ݒ�
 * 
 * @param[in] mesh ���b�V��.
 * @return �Ȃ�.
 */
void MshExCreator::setVertexFormat( Mesh* mesh )
{
	// ���_�t�H�[�}�b�g
	Mesh::VertexFormat vertexFormat = {
		numVertices_,		// ���_�f�[�^��
		numIndices_,		// �C���f�b�N�X�f�[�^��
		numWeights_,		// ���_�E�F�C�g��
		hasMatrixIndices_,	// �s��C���f�b�N�X�f�[�^�������Ă��邩
		hasTextureSpace_	// �e�N�X�`�����W�n�f�[�^�������Ă��邩
	};

	mesh->setVertexFormat( vertexFormat );
}

	
	
/*===== EOF ==================================================================*/