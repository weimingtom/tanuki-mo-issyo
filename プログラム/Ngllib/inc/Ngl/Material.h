/*******************************************************************************/
/**
 * @file Material.h.
 * 
 * @brief �}�e���A���f�[�^�\���̒�`.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATERIAL_H_
#define _NGL_MATERIAL_H_

#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @struct Material�D
 * @brief �}�e���A���f�[�^�\����.
 */
struct Material
{

	/** �����J���[ */
	Color4		ambient;

	/** �g�U���ˌ��J���[ */
	Color4		diffuse;

	/** ���ʔ��ˌ��J���[ */
	Color4		specular;

	/** ���ˌ��J���[ */
	Color4		emissive;

	/* ���ʔ��ˎw�� */
	float		power;


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Material():
		power( 0.0f )
	{}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/