/*******************************************************************************/
/**
 * @file IVertexDeclaration.h.
 * 
 * @brief 頂点宣言インターフェース定義.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IVERTEX_DECLARATION_H_
#define _NGL_IVERTEX_DECLARATION_H_

#include	"VertexDeclarationDesc.h"

namespace Ngl{


/**
 * @interface IVertexDeclaration.
 * @brief 頂点宣言インターフェース.
 */
class IVertexDeclaration
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IVertexDeclaration(){}

	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データの個数を取得
	 * 
	 * @param[in] なし.
	 * @return 個数.
	 */
	virtual unsigned int size() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief 記述子を取得
	 * 
	 * @param[in] index 取得する記述子のインデックス番号.
	 * @return 記述子.
	 */
	virtual const VertexDeclarationDesc& desc( unsigned int index ) const = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/