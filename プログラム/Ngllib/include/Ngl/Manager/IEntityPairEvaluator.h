/*******************************************************************************/
/**
 * @file IEntityPairEvaluator.h.
 * 
 * @brief ペア評価者インターフェース.
 *
 * @date 2008/09/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IENTITYPAIREVALUATOR_H_
#define _NGL_IENTITYPAIREVALUATOR_H_


namespace Ngl{


/**
 * @class IEntityPairEvaluator．
 * @brief ペア評価者インタフェース.
 * @tparam Entity 要素.
 */
template
<
	class Entity
>
class IEntityPairEvaluator
{

protected:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IEntityPairEvaluator() {}

public:

	/*=========================================================================*/
	/**
	 * @brief 評価する
	 * 
	 * @param[in] entity1 評価する要素1.
	 * @param[in] entity2 評価する要素2.
	 * @retval true 真.
	 * @retval false 偽.
	 */
	virtual bool evaluate( Entity entity1, Entity entity2 ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/