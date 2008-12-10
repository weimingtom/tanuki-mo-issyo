/*******************************************************************************/
/**
 * @file IClonable.h.
 * 
 * @brief クローン可能クラスインターフェース.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ICLONABLE_H_
#define _NGL_ICLONABLE_H_


namespace Ngl{


/**
 * @interface IClonable．
 * @brief クローン可能クラスインターフェース.
 *
 * @tparam CloneObject クローンとして生成する型.
 */
template
<
	typename CloneObject
>
class IClonable
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IClonable() {}


	/*=========================================================================*/
	/**
	 * @brief クローンを作成する
	 * 
	 * @param[in] なし.
	 * @return 作成したクローンのポインタ.
	 */
	virtual CloneObject* clone() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/