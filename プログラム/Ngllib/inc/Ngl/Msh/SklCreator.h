/*******************************************************************************/
/**
 * @file SklCreator.h.
 * 
 * @brief Msh skl形式スケルトンファイル読み込みクラスヘッダファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_SKLCREATOR_H_
#define _NGL_MSH_SKLCREATOR_H_

#include	"Ngl/ISkeleton.h"
#include	"Ngl/IInputStream.h"
#include	<string>

namespace Ngl{

// スケルトン
class Skeleton;

namespace Msh{


/**
 * @class SklCreator．
 * @brief skl形式スケルトンファイル読み込みクラス.
 */
class SklCreator
{

public:
	
	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したスケルトンクラス.
	 */
	ISkeleton* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief 入力ストリームから作成する
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @return 作成したスケルトンクラス.
	 */
	ISkeleton* createFromStream( IInputStream& stream );

private:

	/*=========================================================================*/
	/**
	 * @brief ボーンを読み込む
	 * 
	 * @param[in] stream 入力ストリーム.
	 * @param[in] skeleton スケルトン.
	 * @return なし.
	 */
	void loadBone( IInputStream& stream, Skeleton* skeleton );

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/