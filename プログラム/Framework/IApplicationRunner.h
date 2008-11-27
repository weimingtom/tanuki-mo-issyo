/*******************************************************************************/
/**
 * @file IApplicationRunner.h.<br>
 * 
 * @brief アプリケーション実行インターフェース定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IAPPLICATIONRUNNER_H_
#define _IAPPLICATIONRUNNER_H_

#include	"Define/Define.h"

/**
 * @brief アプリケーション実行インターフェース
 */
class IApplicationRunner
{
public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~IApplicationRunner() {}


	/*=========================================================================*/
	/**
	 * @brief アプリケーションの実行<br>
	 * 
	 * @param[in] なし.
	 * @return 終了コード.
	 */
	virtual int runApp() = 0;

};

#endif

/*===== EOF ==================================================================*/