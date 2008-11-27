/*******************************************************************************/
/**
 * @file ViewportDesc.h.
 * 
 * @brief �r���[�|�[�g�L�q�q�\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VIEWPORT_DESC_H_
#define _NGL_VIEWPORT_DESC_H_

namespace Ngl{


/**
 * @struct ViewportDesc.
 * @brief �r���[�|�[�g�L�q�q�\����.
 */
struct ViewportDesc
{
	/** x���W */
	int x;

	/** y���W */
	int y;

	/** �� */
	int width;

	/** ���� */
	int height;
};

} // namesapce Ngl

#endif

/*===== EOF ==================================================================*/