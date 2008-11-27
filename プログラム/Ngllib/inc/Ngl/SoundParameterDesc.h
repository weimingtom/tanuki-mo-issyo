/*******************************************************************************/
/**
 * @file SoundParameterDesc.h.<br>
 * 
 * @brief �T�E���h�Đ��p�����[�^�L�q�q�\���̒�`.<br>
 *
 * @date 2007/07/05.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDPARAMETERDESC_H_
#define _NGL_SOUNDPARAMETERDESC_H_

#include	<Ngl/Vector3.h>

namespace Ngl{


/**
 * @struct SoundParameterDesc�D
 * @brief �T�E���h�Đ��p�����[�^�L�q�q�\����.
 */
struct SoundParameterDesc
{

public:

	/** �{�����[�� */
	int				volume;

	/** �p���i���̍��E���ʁj*/
	int				pan;

	/** ���݂̍Đ��ʒu */
	int				currentPosition;

	/** �Ȃ̍Đ��I���ʒu */
	int				endPosition;

	/** �Đ��ʒu3D���W */
	Vector3			soundPosition;

	/** �������ʒu3D���W */
	Vector3			listenerPosition;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/