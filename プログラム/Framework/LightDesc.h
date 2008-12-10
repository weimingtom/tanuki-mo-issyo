/*******************************************************************************/
/**
 * @file LightDesc.h.<br>
 * 
 * @brief ���C�g�ݒ�L�q�q�\���̒�`.<br>
 *
 * @date 2008/10/26.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _LIGHT_DESC_H_
#define _LIGHT_DESC_H_

#include	"Define/Define.h"


/**
 * @brief ���C�g�L�q�q�\���́D
 */
struct LightDesc
{
	/** �����̐F */
	Color4				ambientColor;

	/** �g�U���ˌ��̐F */
	Color4				diffuseColor;

	/** ���ʔ��ˌ��̐F */
	Color4				specularColor;

	/** ���C�g�ʒu */
	Vector3				position;
};


/** �f�t�H���g�̃��C�g�L�q�q */
static const LightDesc LIGHTDESC_DEFAULT = { 
	Color4( 0.3f, 0.3f, 0.3f, 1.0f ), 
	Color4( 1.0f, 1.0f, 1.0f, 1.0f ), 
	Color4( 0.0f, 0.0f, 0.0f, 1.0f ),
	Vector3( 0.0f, 0.0f, 0.0f )
	};


#endif

/*===== EOF ==================================================================*/