/*******************************************************************************/
/**
 * @file IEntityPairEvaluator.h.
 * 
 * @brief yA]ฟาC^[tF[X.
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
 * @class IEntityPairEvaluatorD
 * @brief yA]ฟาC^tF[X.
 * @tparam Entity vf.
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
	 * @brief fXgN^
	 * 
	 * @param[in] ศต.
	 */
	virtual ~IEntityPairEvaluator() {}

public:

	/*=========================================================================*/
	/**
	 * @brief ]ฟท้
	 * 
	 * @param[in] entity1 ]ฟท้vf1.
	 * @param[in] entity2 ]ฟท้vf2.
	 * @retval true ^.
	 * @retval false U.
	 */
	virtual bool evaluate( Entity entity1, Entity entity2 ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/