/*******************************************************************************/
/**
 * @file InputSignatureDesc.h.
 * 
 * @brief ���̓V�O�l�`���\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUT_SIGNATURE_DESC_H_
#define _NGL_INPUT_SIGNATURE_DESC_H_

namespace Ngl{


/**
 * @struct InputSignatureDesc.
 * @brief ���̓V�O�l�`���L�q�q.
 */
struct InputSignatureDesc
{
	/** �V�O�l�`�� */
	void*			signature;

	/** �V�O�l�`���T�C�Y */
	unsigned int	size;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/