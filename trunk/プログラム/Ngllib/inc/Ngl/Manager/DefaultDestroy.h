/*******************************************************************************/
/**
 * @file DefaultDestroy.h.
 * 
 * @brief 削除ポリシークラス定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DEFAULTDESTROY_H_
#define _NGL_DEFAULTDESTROY_H_

namespace Ngl{


/**
 * @class DefaultDestroy.
 * @brief 削除ポリシークラス
 */
class DefaultDestroy
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief 削除する
	 * 
	 * @tparam Entity 削除する要素を持つクラス.( *演算子オーバーロードを持つ )
	 * @param[in] instance 削除する要素.
	 * @return なし.
	 */
	template <class Entity>
	static void destroy( Entity instance )
	{
		delete instance;
	}

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/