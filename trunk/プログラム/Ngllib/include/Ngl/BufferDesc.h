/*******************************************************************************/
/**
 * @file BufferDesc.h.
 * 
 * @brief �o�b�t�@�쐬�L�q�q�\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BUFFER_DESC_H_
#define _NGL_BUFFER_DESC_H_

namespace Ngl{


/**
 * @enum BufferUsage
 * @brief �o�b�t�@�̎g�p���@�񋓌^.
 */
enum BufferUsage
{
	BUFFER_USAGE_DEFAULT	= 0,	/**< �f�t�H���g					*/
	BUFFER_USAGE_IMMUTABLE	= 1,	/**< �쐬���݈̂�x������������	*/
	BUFFER_USAGE_DYNAMIC	= 2		/**< �p�ɂɏ�������				*/
};


/**
 * @enum BufferType�D
 * @brief �o�b�t�@�^�C�v�񋓌^.
 */
enum BufferType
{
	BUFFER_TYPE_VERTEX	= 0,	/**< ���_�o�b�t�@			*/
	BUFFER_TYPE_INDEX	= 1		/**< �C���f�b�N�X�o�b�t�@	*/
};


/**
 * @struct BufferDesc�D
 * @brief �o�b�t�@�쐬�L�q�q�\����.
 */
struct BufferDesc
{
	/** �o�b�t�@�^�C�v */
	BufferType	type;

	/** �o�b�t�@�̎g�p���@ */
	BufferUsage	usage;

	/** �f�[�^�̃o�C�g�� */
	unsigned int	size;


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	BufferDesc():
		type( BUFFER_TYPE_VERTEX),
		usage( BUFFER_USAGE_DEFAULT ),
		size( 0 )
	{}
};

}	// namesapce Ngl

#endif

/*===== EOF ==================================================================*/