/*******************************************************************************/
/**
 * @file VertexStreamDesc.h.
 * 
 * @brief ���_�X�g���[���L�q�q�\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VERTEX_STREAM_DESC_H_
#define _NGL_VERTEX_STREAM_DESC_H_

namespace Ngl{

// �o�b�t�@�C���^�[�t�F�[�X
class IBuffer;

/**
 * @struct VertexStreamDesc.
 * @brief ���_�X�g���[���L�q�q�\����.
 */
struct VertexStreamDesc
{
	/** ���_�o�b�t�@ */
	IBuffer*		buffer;

	/** �o�b�t�@�܂ł̃I�t�Z�b�g�l */
	unsigned int	offset;

	/** �X�g���C�h�l */
	unsigned int	stride;


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	VertexStreamDesc():
		buffer( 0 ),
		stride( 0 ),
		offset( 0 )
	{}


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] Buffer ���_�o�b�t�@.
	 * @param[in] Offset �o�b�t�@�܂ł̃I�t�Z�b�g�l.
	 * @param[in] Stride �X�g���C�h�l.
	 */
	VertexStreamDesc( IBuffer* Buffer, unsigned int Offset=0, unsigned int Stride=0 ):
		buffer( Buffer ),
		offset( Offset ),
		stride( Stride )
	{}

};

} // namesapce Ngl

#endif

/*===== EOF ==================================================================*/