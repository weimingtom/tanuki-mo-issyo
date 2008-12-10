/*******************************************************************************/
/**
 * @file Manipulator.h.
 * 
 * @brief �}�j�s�����[�^��`�w�b�_�t�@�C��.
 *
 * @date 2008/07/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MANIPULATOR_H_
#define _NGL_MANIPULATOR_H_

#include	"IInputStream.h"
#include	"Manipulator/Vector2Input.h"
#include	"Manipulator/Vector3Input.h"
#include	"Manipulator/Vector4Input.h"
#include	"Manipulator/Matrix4Input.h"
#include	"Manipulator/Color4Input.h"
#include	"Manipulator/QuaternionInput.h"

namespace Ngl{

/**
 * @name oct
 * @brief 8�i���ǂݍ��݃}�j�s�����[�^.
 */
IInputStream& oct( IInputStream& stream );


/**
 * @name dec
 * @brief 10�i���ǂݍ��݃}�j�s�����[�^.
 */
IInputStream& dec( IInputStream& stream );


/**
 * @name hex
 * @brief 16�i���ǂݍ��݃}�j�s�����[�^.
 */
IInputStream& hex( IInputStream& stream );


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/