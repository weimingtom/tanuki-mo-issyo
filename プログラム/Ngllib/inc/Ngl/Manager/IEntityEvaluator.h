/*******************************************************************************/
/**
 * @file IEntityEvaluator.h.
 * 
 * @brief 評価インターフェース定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYEVALUATOR_H_
#define _NGL_IENTITYEVALUATOR_H_

namespace Ngl{


/**
 * @interface IEntityEvaluator.
 * @brief 評価者インターフェース．
 * @tparam Entity 評価する要素.
 */
template <class Entity>
class IEntityEvaluator
{
public:
	

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEntityEvaluator(){}
	
	
	/*=========================================================================*/
	/**
	 * @brief 評価する
	 * 
	 * @param[in] entity 評価する要素.
	 * @return なし.
	 */
	virtual bool evaluate( Entity entity ) = 0;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/