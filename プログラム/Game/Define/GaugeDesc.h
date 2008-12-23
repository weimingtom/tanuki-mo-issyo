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

#include	"Define.h"
#include	<Ngl/Vector2.h>
#include	<Ngl/Rect.h>

/*--------------
   �\���̒�`
----------------*/
typedef struct{
	/** �ő剡�� */
	float Max;
	/** �Q�[�W�̈ʒu */
	float Point;
	/** �T�C�Y */
	Vector2 Size;

	Vector2 Position;

	int Texture1;
	int Texture2;

	Rect TextureRec1;
	Rect TextureRec2;
}GaugeDesc;


#endif