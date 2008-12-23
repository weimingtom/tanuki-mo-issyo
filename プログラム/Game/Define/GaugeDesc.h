/*******************************************************************************/
/**
 * @file GaugeDesc.h.
 * 
 * @brief �Q�[�W�f�X�N�^��`.
 *
 * @date 2008/12/23.
 *
 * @version 1.00.
 *
 * @author Ryosuke Ogawa.
 */
/*******************************************************************************/
#ifndef _GAUGEDESC_H_
#define _GAUGEDESC_H_

/*===== �C���N���[�h ==========================================================*/
#include	"Define/Define.h"

/*--------------
   �\���̒�`
----------------*/
struct GaugeDesc
{
	/** �ő剡�� */
	float max;
	/** �Q�[�W�̈ʒu */
	float point;
	/** �T�C�Y */
	Vector2 size;

	Vector2 position;

	int texture1;
	int texture2;

	Rect textureRec1;
	Rect textureRec2;
};


#endif