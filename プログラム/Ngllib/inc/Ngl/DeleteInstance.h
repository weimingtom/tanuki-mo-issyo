/*******************************************************************************/
/**
 * @file DeleteInstance.h.
 * 
 * @brief 削除関数オブジェクトクラス定義.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DELETE_INSTANCE_H_
#define _NGL_DELETE_INSTANCE_H_

namespace Ngl{


/**
 * @class DeleteInstance.
 * @brief 汎用削除関数オブジェクトクラス.
 */
class DeleteInstance
{

public:

	/*=========================================================================*/
	/**
	 * @brief  関数呼び出し ()演算子オーバーロード
	 * 
	 * @param[in] instance 削除するインスタンス.
	 * @return true 削除完了.
	 */
	template <class T>						
	bool operator () ( const T* instance )
	{
		delete instance;

		return true;
	}
};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/