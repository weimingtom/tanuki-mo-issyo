/*******************************************************************************/
/**
 * @file VertexDeclarationGL.cpp.
 * 
 * @brief OpenGL ���_�錾�f�[�^�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/OpenGL/VertexDeclarationGL.h"
#include	"Ngl/OpenGL/BufferGL.h"

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc ���_�錾�f�[�^�L�q�q�̔z��.
 * @param[in] numDesc ���_�錾�f�[�^�L�q�q�z��̗v�f��.
 */
VertexDeclarationGL::VertexDeclarationGL( const VertexDeclarationDesc desc[], unsigned int numDesc ):
	desc_( &desc[0], &desc[numDesc] ),
	elements_( numDesc )
{
	for( unsigned int  i=0; i<numDesc; ++i ){
		elements_[i] = toElement( desc_[i] );
	}
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
VertexDeclarationGL::~VertexDeclarationGL()
{}



/*=========================================================================*/
/**
 * @brief ���_�錾�f�[�^�̌����擾
 * 
 * @param[in] �Ȃ�.
 * @return ��.
 */
unsigned int VertexDeclarationGL::size() const
{
	return (unsigned int)desc_.size();
}



/*=========================================================================*/
/**
 * @brief �L�q�q���擾
 * 
 * @param[in] index �擾����L�q�q�̃C���f�b�N�X�ԍ�.
 * @return �L�q�q.
 */
const VertexDeclarationDesc& VertexDeclarationGL::desc( unsigned int index ) const
{
	return desc_[index];
}



/*=========================================================================*/
/**
 * @brief ���_�o�b�t�@�X�g���[���̐ݒ�
 * 
 * @param[in] streams �ݒ肷�钸�_�X�g���[���L�q�q�z��.
 * @param[in] start �ݒ�J�n�z��ʒu.
 * @return �Ȃ�.
 */
void VertexDeclarationGL::setVertexStream( const VertexStreamDesc streams[], unsigned int start )
{
	// ���_�X�g���[���̃��Z�b�g
	resetVertexStream();

	// ���_�o�b�t�@��ݒ肷��
	for( VertexDeclarationArray::iterator i = elements_.begin(); i !=elements_.end(); ++i ){
		setVertexBuffer( *i, streams[ (*i).stream ], start );
	}
}



/*=========================================================================*/
/**
 * @brief ���_�o�b�t�@�X�g���[���̃��Z�b�g
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void VertexDeclarationGL::resetVertexStream()
{
	// ���_�z��𖳌��ɂ���
	for( GLuint attr=0; attr<VERTEX_DECLARATION_MAX; ++attr ){
		glDisableVertexAttribArray( attr );
	}
}



/*=========================================================================*/
/**
 * @brief ���_�o�b�t�@�̐ݒ�
 * 
 * @param[in] element ���_�錾�v�f�\����.
 * @param[in] stream ���_�X�g���[���L�q�q.
 * @param[in] start �J�n�ʒu.
 * @return �Ȃ�.
 */
void VertexDeclarationGL::setVertexBuffer( const VertexDeclarationGL::Element& element, const VertexStreamDesc& stream, unsigned int start )
{
	// ���_�o�b�t�@���o�C���h����
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, static_cast< BufferGL* >( stream.buffer )->buffer() );

	// ���_�f�[�^�z���L���ɂ���
	glEnableVertexAttribArrayARB( element.attrib );

	// ���_�o�b�t�@��ݒ肷��
	GLubyte* base = 0;
	glVertexAttribPointerARB(
		element.attrib,
		element.format.size,
		element.format.type,
		element.format.normalized,
		stream.stride,
		&base[ start * stream.stride + stream.offset + element.offset ]
		);

	// ���_�o�b�t�@�̃o�C���h������
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );
}



/*=========================================================================*/
/**
 * @brief ���_�錾�L�q�q��ϊ�
 * 
 * @param[in] desc �ϊ����钸�_�錾�L�q�q�\����.
 * @return �ϊ���̒��_�錾�v�f�\����.
 */
VertexDeclarationGL::Element VertexDeclarationGL::toElement( const VertexDeclarationDesc& desc )
{
	Element element;
	element.attrib	= toAttrib( desc.semantic ) + desc.index;
	element.format	= toVertexFormat( desc.type );
	element.offset	= desc.offset;
	element.stream	= desc.stream;
	return element;
}



/*=========================================================================*/
/**
 * @brief ���_�Z�}���e�B�b�N��ϊ�
 * 
 * @param[in] semantic �ϊ����钸�_�Z�}���e�B�b�N�t���O.
 * @return �ϊ����OpenGL���_�Z�}���e�B�b�N.
 */
GLuint VertexDeclarationGL::toAttrib( VertexSemantic semantic )
{
	static const unsigned int attribs[] = {
		0,	// VERTEX_FORMAT_POSITION		= 0
		1,	// VERTEX_FORMAT_BLENDWEIGHT	= 1
		2,	// VERTEX_FORMAT_NORMAL			= 2
		3,	// VERTEX_FORMAT_COLOR			= 3
		3,	// VERTEX_FORMAT_DIFFUSE		= 4
		4,	// VERTEX_FORMAT_SPECULAR		= 5
		5,	// VERTEX_FORMAT_TESSFACTOR		= 6
		5,	// VERTEX_FORMAT_FOGCOORD		= 7
		6,	// VERTEX_FORMAT_PSIE			= 8
		7,	// VERTEX_FORMAT_BLENDINDICES	= 9
		8,	// VERTEX_FORMAT_TEXCOORD		= 10
		14,	// VERTEX_FORMAT_TANGENT		= 11
		15	// VERTEX_FORMAT_BINORMAL		= 12
	};

	return attribs[ semantic ];
}



/*=========================================================================*/
/**
 * @brief ���_�^�C�v��ϊ�
 * 
 * @param[in] type �ϊ����钸�_�^�C�v�t���O.
 * @return �ϊ���̒��_�t�H�[�}�b�g�\����.
 */
const VertexDeclarationGL::VertexFormat& VertexDeclarationGL::toVertexFormat( VertexType type )
{
	static const VertexFormat vertexFormats[] = {
		{ GL_FLOAT,				1,	GL_FALSE },		// VERTEX_TYPE_FLOAT1	= 0
		{ GL_FLOAT,				2,	GL_FALSE },		// VERTEX_TYPE_FLOAT2	= 1
		{ GL_FLOAT,				3,	GL_FALSE },		// VERTEX_TYPE_FLOAT3	= 2
		{ GL_FLOAT,				4,	GL_FALSE },		// VERTEX_TYPE_FLOAT4	= 3
		{ GL_BYTE,				4,	GL_FALSE },		// VERTEX_TYPE_BYTE4	= 4
		{ GL_BYTE,				4,	GL_TRUE	 },		// VERTEX_TYPE_BYTE4N	= 5
		{ GL_UNSIGNED_BYTE,		4,	GL_FALSE },		// VERTEX_TYPE_UBYTE4	= 6
		{ GL_UNSIGNED_BYTE,		4,	GL_TRUE	 },		// VERTEX_TYPE_UBYTE4N	= 7
		{ GL_SHORT,				2,	GL_FALSE },		// VERTEX_TYPE_SHORT2	= 8
		{ GL_SHORT,				2,	GL_TRUE  },		// VERTEX_TYPE_SHORT2N	= 9
		{ GL_UNSIGNED_SHORT,	2,	GL_FALSE },		// VERTEX_TYPE_USHORT2	= 10
		{ GL_UNSIGNED_SHORT,	2,	GL_TRUE	 },		// VERTEX_TYPE_USHORT2N	= 11
		{ GL_SHORT,				4,	GL_FALSE },		// VERTEX_TYPE_SHORT4	= 12
		{ GL_SHORT,				4,	GL_TRUE	 },		// VERTEX_TYPE_SHORT4N	= 13
		{ GL_UNSIGNED_SHORT,	4,	GL_FALSE },		// VERTEX_TYPE_USHORT4	= 14
		{ GL_UNSIGNED_SHORT,	4,	GL_TRUE  },		// VERTEX_TYPE_USHORT4N	= 15
		{ GL_INT,				1,	GL_FALSE },		// VERTEX_TYPE_INT1		= 16
		{ GL_INT,				2,	GL_FALSE },		// VERTEX_TYPE_INT2		= 17
		{ GL_INT,				3,	GL_FALSE },		// VERTEX_TYPE_INT3		= 18
		{ GL_INT,				4,	GL_FALSE },		// VERTEX_TYPE_INT4		= 19
		{ GL_UNSIGNED_INT,		1,	GL_FALSE },		// VERTEX_TYPE_UINT1	= 20
		{ GL_UNSIGNED_INT,		2,	GL_FALSE },		// VERTEX_TYPE_UINT2	= 21
		{ GL_UNSIGNED_INT,		3,	GL_FALSE },		// VERTEX_TYPE_UINT3	= 22
		{ GL_UNSIGNED_INT,		4,	GL_FALSE }		// VERTEX_TYPE_UINT4	= 23
	};

	return vertexFormats[ type ];
}



/*===== EOF ==================================================================*/