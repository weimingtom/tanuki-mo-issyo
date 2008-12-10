/*******************************************************************************/
/**
 * @file MshExFile.h.
 * 
 * @brief Msh MshExメッシュファイルクラスヘッダファイル.
 *
 * @date 2008/11/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_MSHEXFILE_H_
#define _NGL_MSH_MSHEXFILE_H_

#include	<Ngl/IMeshFile.h>
#include	<Ngl/IRenderer.h>
#include	<string>


namespace Ngl{


// テクスチャ作成クラス
class ITextureCreator;


namespace Msh{


// msh,mshex形式メッシュファイル作成クラス
class MshExCreator;

// skl形式スケルトンファイル作成クラス
class SklCreator;

// anm形式アニメーションファイル作成クラス
class AnmCreator;


/**
 * @class MshExFile．
 * @brief Msh MshExメッシュファイルクラス.
 */
class MshExFile : public IMeshFile
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] renderer レンダラー.
	 * @param[in] textureCreator テクスチャ作成クラス.
	 */
	MshExFile( IRenderer* renderer, ITextureCreator* creator );


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @warning 設定したクラスは、MshExFile内で削除されます.
	 *
	 * @param[in] renderer レンダラー.
	 * @param[in] msh msh,mshex形式メッシュファイル作成クラス.
	 * @param[in] skl skl形式スケルトンファイル作成クラス.
	 * @param[in] anm anm形式アニメーションファイル作成クラス.
	 */
	MshExFile( IRenderer* renderer, MshExCreator* msh, SklCreator* skl=0, AnmCreator* anm=0 );
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	 ~MshExFile();

public:

	/*=========================================================================*/
	/**
	 * @brief ファイルから作成する
	 *
	 * @throw Ngl::InputStreamException& 入力例外.
	 *
	 * @warning メッシュファイルと同名のsklファイルと、anmファイルを読み込みます<br>
	 *
	 * @param[in] filename ファイル名( メッシュファイルの拡張子込み ).
	 * @return なし.
	 */
	virtual void createFromFile( const std::string& filename );


	/*=========================================================================*/
	/**
	 * @brief メッシュデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return メッシュデータ.
	 */
	virtual IMesh* getMesh();


	/*=========================================================================*/
	/**
	 * @brief スケルトンデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return スケルトンデータ.
	 */
	virtual ISkeleton* getSkeleton();


	/*=========================================================================*/
	/**
	 * @brief アニメーションデータを取得
	 * 
	 * @warning 作成されていない場合は、0が返ります.
	 *
	 * @param[in] なし.
	 * @return メッシュデータ.
	 */
	virtual IAnimation* getAnimation();

protected:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 )
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	MshExFile( const MshExFile& other );


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	MshExFile& operator = ( const MshExFile& other );

private:

	/** レンダラー */
	IRenderer*		renderer_;
	
	/** メッシュ作成クラス */
	MshExCreator*	mshCreator_;

	/** スケルトン作成クラス */
	SklCreator*		sklCreator_;

	/** アニメーション作成クラス */
	AnmCreator*		anmCreator_;

	/** メッシュデータ */
	IMesh*			mesh_;

	/** スケルトンデータ */
	ISkeleton*		skeleton_;

	/** アニメーションデータ */
	IAnimation*		animation_;
	
};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/