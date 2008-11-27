/*******************************************************************************/
/**
 * @file NoDestroy.h.
 * 
 * @brief 非削除ポリシークラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_NODESTROY_H_
#define _NGL_NODESTROY_H_

namespace Ngl{


/**
 * @class NoDestroy.
 * @brief 非削除ポリシークラス.
 */
class NoDestroy
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief 削除しない
	 * 
	 * @tparam Entity 削除する要素を持つクラス.( *演算子オーバーロードを持つ )
	 * @param[in] instance 削除しない要素.
	 * @return なし.
	 */
	template<class Entity>
	static void destroy( Entity instance ){}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/