/*******************************************************************************/
/**
 * @file VertexDeclarationDesc.h.
 * 
 * @brief ���_�錾�\���̒�`.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VERTEX_DECLARATION_DESC_H_
#define _NGL_VERTEX_DECLARATION_DESC_H_

namespace Ngl{


/**
 * @enum VertexSemantic.
 * @brief ���_�Z�}���e�B�b�N�񋓌^.
 */
enum VertexSemantic
{
	VERTEX_SEMANTIC_POSITION		= 0,	/**< ���_���W			*/
	VERTEX_SEMANTIC_BLENDWEIGHT		= 1,	/**< ���_�E�F�C�g		*/
	VERTEX_SEMANTIC_NORMAL			= 2,	/**< �@���x�N�g��		*/
	VERTEX_SEMANTIC_COLOR			= 3,	/**< ���_�J���[			*/
	VERTEX_SEMANTIC_DIFFUSE			= 4,	/**< �g�U���ˌ��J���[	*/
	VERTEX_SEMANTIC_SPECULAR		= 5,	/**< ���ʔ��ˌ��J���[	*/
	VERTEX_SEMANTIC_TESSFACTOR		= 6,	/**< �e�b�Z���[�V����	*/
	VERTEX_SEMANTIC_FOGCOORD		= 7,	/**< �t�H�O�ʒu			*/
	VERTEX_SEMANTIC_PSIZE			= 8,	/**< �|�C���g�T�C�Y		*/
	VERTEX_SEMANTIC_BLENDINDICES	= 9,	/**< �{�[���ԍ�			*/
	VERTEX_SEMANTIC_TEXCOORD		= 10,	/**< �e�N�X�`�����W0�`8	*/
	VERTEX_SEMANTIC_TANGENT			= 11,	/**< �ڃx�N�g��			*/
	VERTEX_SEMANTIC_BINORMAL		= 12	/**< �]�@���x�N�g��		*/
};


/**
 * @enum VertexType.
 * @brief ���_�^�C�v�񋓌^.
 */
enum VertexType
{
	VERTEX_TYPE_FLOAT1		= 0,	/**< float�^			�v�f��1			*/
	VERTEX_TYPE_FLOAT2		= 1,	/**< float�^			�v�f��2			*/
	VERTEX_TYPE_FLOAT3		= 2,	/**< float�^			�v�f��3			*/
	VERTEX_TYPE_FLOAT4		= 3,	/**< float�^			�v�f��4			*/
	VERTEX_TYPE_BYTE4		= 4,	/**< char�^				�v�f��4			*/
	VERTEX_TYPE_BYTE4N		= 5,	/**< char�^				�v�f��4 ���K��	*/
	VERTEX_TYPE_UBYTE4		= 6,	/**< unsigned char�^	�v�f��4			*/
	VERTEX_TYPE_UBYTE4N		= 7,	/**< unsigned chart�^	�v�f��4	���K��	*/
	VERTEX_TYPE_SHORT2		= 8,	/**< char�^				�v�f��2			*/
	VERTEX_TYPE_SHORT2N		= 9,	/**< char�^				�v�f��2	���K��	*/
	VERTEX_TYPE_USHORT2		= 10,	/**< unsigned char�^	�v�f��2			*/
	VERTEX_TYPE_USHORT2N	= 11,	/**< unsigned char�^	�v�f��2	���K��	*/
	VERTEX_TYPE_SHORT4		= 12,	/**< short�^			�v�f��4			*/
	VERTEX_TYPE_SHORT4N		= 13,	/**< short�^			�v�f��4	���K��	*/
	VERTEX_TYPE_USHORT4		= 14,	/**< unsigned short�^	�v�f��4			*/
	VERTEX_TYPE_USHORT4N	= 15,	/**< unsigned short�^	�v�f��4	���K��	*/
	VERTEX_TYPE_INT1		= 16,	/**< int�^				�v�f��1			*/
	VERTEX_TYPE_INT2		= 17,	/**< int�^				�v�f��2			*/
	VERTEX_TYPE_INT3		= 18,	/**< int�^				�v�f��3			*/
	VERTEX_TYPE_INT4		= 19,	/**< int�^				�v�f��4			*/
	VERTEX_TYPE_UINT1		= 20,	/**< unsigned int�^		�v�f��1			*/
	VERTEX_TYPE_UINT2		= 21,	/**< unsigned int�^		�v�f��2			*/
	VERTEX_TYPE_UINT3		= 22,	/**< unsigned int�^		�v�f��3			*/
	VERTEX_TYPE_UINT4		= 23	/**< unsigned int�^		�v�f��4			*/
};


/** ���_�錾�̍ő�l */
static const unsigned int VERTEX_DECLARATION_MAX	= 16;


/**
 * @struct VertexDeclarationDesc.
 * @brief ���_�錾�L�q�q�\����.
 */
struct VertexDeclarationDesc
{
	/** �Z�}���e�B�b�N */
	VertexSemantic	semantic;

	/** �Z�}���e�B�b�N�C���f�b�N�X */
	unsigned int	index;

	/** ���_�^�C�v */
	VertexType		type;

	/** �I�t�Z�b�g */
	unsigned int	offset;

	/** �X�g���[���ԍ� */
	unsigned int	stream;
};

} // namespace Ngl

#endif