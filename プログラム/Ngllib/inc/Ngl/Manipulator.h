/*******************************************************************************/
/**
 * @file Manipulator.h.
 * 
 * @brief マニピュレータ定義ヘッダファイル.
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
 * @brief 8進数読み込みマニピュレータ.
 */
IInputStream& oct( IInputStream& stream );


/**
 * @name dec
 * @brief 10進数読み込みマニピュレータ.
 */
IInputStream& dec( IInputStream& stream );


/**
 * @name hex
 * @brief 16進数読み込みマニピュレータ.
 */
IInputStream& hex( IInputStream& stream );


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/