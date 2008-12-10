/*******************************************************************************/
/**
 * @file IMeshFile.h.
 * 
 * @brief メッシュファイルインターフェース定義.
 *
 * @date 2008/11/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMESHFILE_H_
#define _NGL_IMESHFILE_H_

#include	<Ngl/IMesh.h>
#include	<Ngl/ISkeleton.h>
#include	<Ngl/IAnimation.h>


namespace Ngl{


/**
 * @interface IMeshFile．
 * @brief メッシュファイルインターフェース.
 */
class IMeshFile
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IMeshFile() {}


	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 *
	 * @param[in] filename ファイル名.
	 * @return なし.
	 */
	virtual void createFromFile( const std::string& filename ) = 0;


	/*=========================================================================*/
	/**
	 * @brief メッシュデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return メッシュデータ.
	 */
	virtual IMesh* getMesh() = 0;


	/*=========================================================================*/
	/**
	 * @brief スケルトンデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return スケルトンデータ.
	 */
	virtual ISkeleton* getSkeleton() = 0;


	/*=========================================================================*/
	/**
	 * @brief アニメーションデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return メッシュデータ.
	 */
	virtual IAnimation* getAnimation() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/