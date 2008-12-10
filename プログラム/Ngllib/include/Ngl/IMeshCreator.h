/*******************************************************************************/
/**
 * @file IMeshCreator.h.
 * 
 * @brief メッシュ作成者インターフェース定義.
 *
 * @date 2008/10/14.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMESHCREATOR_H_
#define _NGL_IMESHCREATOR_H_

#include	"Ngl/IMesh.h"
#include	"Ngl/ITextureCreator.h"

namespace Ngl{


/**
 * @class IMeshCreator．
 * @brief メッシュ作成者インターフェース.
 */
class IMeshCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IMeshCreator() {}


	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したメッシュクラス.
	 */
	virtual IMesh* createFromFile( std::string fileName ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームから作成する
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したメッシュクラス.
	 */
	virtual IMesh* createFromStream( IInputStream& stream ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/