/*******************************************************************************/
/**
 * @file KeyframeData.h.
 * 
 * @brief �L�[�t���[���f�[�^�\���̒�`.
 *
 * @date 2008/07/01.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYFRAMEDATA_H_
#define _NGL_KEYFRAMEDATA_H_

#include	"Ngl/Vector3.h"
#include	"Ngl/Quaternion.h"

namespace Ngl{


/**
 * @struct KeyframeData�D
 * @brief �L�[�t���[���f�[�^�\����.
 */
struct KeyframeData
{
	/** �g��k���L�[ */
	Ngl::Vector3	scale;

	/** ��]�L�[ */
	Ngl::Quaternion	rotate;

	/** ���s�ړ��L�[ */
	Ngl::Vector3	position;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/