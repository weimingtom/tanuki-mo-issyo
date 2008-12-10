/*******************************************************************************/
/**
 * @file PolygonQuad.cpp.
 * 
 * @brief �l�p�`�|���S���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/08/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/PolygonQuad.h"
#include	"Ngl/Vector3.h"
#include	"Ngl/Matrix4.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
PolygonQuad::PolygonQuad():
	vertexBuffer_( 0 ),
	indexBuffer_( 0 ),
	texcoordBuffer_( 0 ),
	normalBuffer_( 0 ),
	isDeleted_( false )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
PolygonQuad::~PolygonQuad()
{
	end();
}



/*=========================================================================*/
/**
 * @brief �쐬����
 * 
 * @param[in] �����_���[.
 * @return �Ȃ�.
 */
void PolygonQuad::create( IRenderer* renderer )
{
	// ���_�o�b�t�@�̍쐬
	const static float vertices[][3] = {
		{ -0.5f,  0.5f, 0.0f },
		{ -0.5f, -0.5f, 0.0f },
		{  0.5f, -0.5f, 0.0f },
		{  0.5f,  0.5f, 0.0f }
	};
	Ngl::BufferDesc vertexBuffer;
	vertexBuffer.size	= sizeof( vertices );
	vertexBuffer.type	= BUFFER_TYPE_VERTEX;
	vertexBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	vertexBuffer_ = renderer->createBuffer( vertexBuffer, vertices );

	// �C���f�b�N�X�o�b�t�@���쐬
	const static unsigned short indices[] = {
		0, 1, 2,
		0, 2, 3
	};
	Ngl::BufferDesc indexBuffer;
	indexBuffer.size	= sizeof( indices );
	indexBuffer.type	= BUFFER_TYPE_INDEX;
	indexBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	indexBuffer_ = renderer->createBuffer( indexBuffer, indices );


	// �e�N�X�`�����W�o�b�t�@���쐬
	const static float texcoords[][2] = {
		{ 0.0f, 0.0f },
		{ 0.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 0.0f }
	};
	/*const static float texcoords[][2] = {
		{ 0.0f, 1.0f },
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f }
	};*/

	Ngl::BufferDesc texcoordBuffer;
	texcoordBuffer.size		= sizeof( texcoords );
	texcoordBuffer.type		= BUFFER_TYPE_VERTEX;
	texcoordBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	texcoordBuffer_ = renderer->createBuffer( texcoordBuffer, texcoords );

	// �@���x�N�g���o�b�t�@���쐬
	const static float normals[][3] = {
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f }
	};
	Ngl::BufferDesc normalBuffer;
	normalBuffer.size	= sizeof( normals );
	normalBuffer.type	= BUFFER_TYPE_VERTEX;
	normalBuffer.usage	= BUFFER_USAGE_DYNAMIC;
	normalBuffer_ = renderer->createBuffer( normalBuffer, normals );

	// ���_�X�g���[���z����쐬
	Ngl::VertexStreamDesc streams[] = {
		Ngl::VertexStreamDesc( vertexBuffer_, 0, sizeof(float)*3 ),
		Ngl::VertexStreamDesc( normalBuffer_, 0, sizeof(float)*3 ),
		Ngl::VertexStreamDesc( texcoordBuffer_, 0, sizeof(float)*2 )
	};
	for( int i=0; i<3; ++i ){
		streamArray_.push_back( streams[ i ] );
	}
}



/*=========================================================================*/
/**
 * @brief �`�揈��
 * 
 * @param[in] renderer �����_���[.
 * @param[in] effect �G�t�F�N�g.
 * @return �Ȃ�.
 */
void PolygonQuad::draw( IRenderer* renderer, IEffect* effect )
{
	static const VertexDeclarationDesc layout[] = {
		{ VERTEX_SEMANTIC_POSITION, 0, VERTEX_TYPE_FLOAT3, sizeof(float)*0, 0 },
		{ VERTEX_SEMANTIC_NORMAL,   0, VERTEX_TYPE_FLOAT3, sizeof(float)*0, 1 },
		{ VERTEX_SEMANTIC_TEXCOORD, 0, VERTEX_TYPE_FLOAT2, sizeof(float)*0, 2 }
	};

	// �C���f�b�N�X�o�b�t�@��ݒ�
	renderer->setIndexBuffer( indexBuffer_, INDEX_TYPE_USHORT );

	// ���_�o�b�t�@��ݒ�
	renderer->setVertexBuffer( &streamArray_[0], 3 );

	// �G�t�F�N�g�̃p�X���������_�����O
	for( int passNo=0; passNo<effect->getNumPass(); ++passNo ){
		// �G�t�F�N�g���J�n
		effect->begin( passNo );
		
		// ���_�錾�f�[�^���쐬
		IVertexDeclaration* vertexDeclaration = renderer->createVertexDeclaration( 
			layout,																	// ���_���C�A�E�g�L�q�q�z��
			3,																		// �v�f��
			effect->inputSigneture( effect->getCurrentTechniqueName(), passNo ) );	// ���̓V�O�l�`��
		renderer->setVertexDeclaration( vertexDeclaration );

		// �v���~�e�B�u��ݒ�
		renderer->setPrimitive( PRIMITIVE_TYPE_TRIANGLE_LIST );
	
		// �`��
		renderer->drawIndexed( 6 );

		// �G�t�F�N�g���I��
		effect->end();

		// �쐬�������_�錾�f�[�^���폜
		delete vertexDeclaration;
	}
}



/*=========================================================================*/
/**
 * @brief �I������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void PolygonQuad::end()
{
	// ���łɍ폜����Ă��邩
	if( isDeleted_ == true ){
		return;
	}

	delete vertexBuffer_;
	delete indexBuffer_;
	delete texcoordBuffer_;
	delete normalBuffer_;

	isDeleted_ = true;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �|���S���̋�`��ݒ�
 * 
 * @param[in] size ��`�l( ���[���h���W ).
 * @return �Ȃ�.
 */
void PolygonQuad::setSize( const Rect& size )
{
	Vector3 vertices[] = {
		Vector3( size.left,  size.top,    0.0f ),
		Vector3( size.left,  size.bottom, 0.0f ),
		Vector3( size.right, size.bottom, 0.0f ),
		Vector3( size.right, size.top,    0.0f )
	};
	vertexBuffer_->setData( vertices );
}


	
/*=========================================================================*/
/**
 * @brief �|���S���̋�`��ݒ�( 2D�X�v���C�g�p )
 * 
 * @param[in] size ��`�l( �X�N���[�����W ).
 * @param[in] windowWidth �E�B���h�E�̕�.
 * @param[in] windowHeight �E�B���h�E�̍���.
 * @return �Ȃ�.
 */
void PolygonQuad::setSize2D( const Rect& size, int windowWidth, int windowHeight )
{
	Vector3 vertices[] = {
		Vector3( size.left,  size.top,    0.0f ),
		Vector3( size.left,  size.bottom, 0.0f ),
		Vector3( size.right, size.bottom, 0.0f ),
		Vector3( size.right, size.top,    0.0f )
	};

	// ���[���h���W����X�N���[�����W�ւ̕ϊ��s����쐬
	Matrix4 model;
	model.setIdentitiy();
	model.m[0][0] = 1.0f / windowWidth;
	model.m[1][1] = 1.0f / windowHeight;

	// ���ׂĂ̒��_�����W�ϊ�����
	for( int i=0; i<4; ++i ){
		vertices[ i ].transform( model );

		vertices[ i ].x -= 0.5f;
		vertices[ i ].y -= 0.5f;
	}
	
	vertexBuffer_->setData( vertices );
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`�����W��ݒ肷��
 *
 * @param[in] srcRect ��`�l( ���[���h���W ).
 * @return �Ȃ�.
 */
void PolygonQuad::setSrcRect( const Rect& srcRect )
{
	float texcoords[][2] = {
		{ srcRect.left,  srcRect.top },
		{ srcRect.left,  srcRect.bottom },
		{ srcRect.right, srcRect.bottom },
		{ srcRect.right, srcRect.top }
	};

	texcoordBuffer_->setData( texcoords );
}
	
	
	
/*=========================================================================*/
/**
 * @brief �e�N�X�`�����W��ݒ肷��
 *
 * �X�N���[�����W���烏�[���h���W�֕ϊ����Đݒ肷��.
 * 
 * @param[in] srcRect ��`�l( �X�N���[�����W ).
 * @param[in] width �e�N�X�`���̕�.
 * @param[in] height �e�N�X�`���̍���.
 * @return �Ȃ�.
 */
void PolygonQuad::setSrcRect( const Rect& srcRect, int width, int height )
{
	// �e�N�X�`�����W�̌v�Z���s��
	Rect rc( 
		srcRect.left   / width,
		srcRect.top    / height,
		srcRect.right  / width,
		srcRect.bottom / height
	);

	setSrcRect( rc );
}



/*===== EOF ==================================================================*/