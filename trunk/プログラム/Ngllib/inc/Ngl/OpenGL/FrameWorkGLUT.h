/*******************************************************************************/
/**
 * @file FrameWorkGLUT.h.
 * 
 * @brief OpenGL GLUTフレームワーククラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_FRAMEWORKGLUT_H_
#define _NGL_OPENGL_FRAMEWORKGLUT_H_

#include	"Ngl/FrameTimer.h"
#include	"Ngl/IFrameWork.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class FrameWorkGLUT．
 * @brief OpenGL GLUTフレームワーククラス.
 */
class FrameWorkGLUT : public IFrameWork
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] desc フレームワーク記述子.
	 * @param[in] argc コマンドライン引数数.
	 * @param[in] argv コマンドライン引数.
	 */
	FrameWorkGLUT( const FrameWorkDesc& desc, int argc, char* argv[] );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~FrameWorkGLUT();


	/*=========================================================================*/
	/**
	 * @brief アプリケーションの実行
	 * 
	 * @param[in] なし.
	 * @return 終了コード.
	 */
	virtual int run();

	
	/*=========================================================================*/
	/**
	 * @brief アプリケーションの終了
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void exit();
	
	
	/*=========================================================================*/
	/**
	 * @brief フレームワーク記述子を取得
	 * 
	 * @param[in] なし.
	 * @return フレームワーク記述子.
	 */
	virtual const FrameWorkDesc& desc() const;


	/*=========================================================================*/
	/**
	 * @brief ウィンドウハンドルを取得する
	 * 
	 * @param[in] なし.
	 * @return ウィンドウハンドル.
	 */
	virtual void* getHWND();


	/*=========================================================================*/
	/**
	 * @brief 初期化処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void initialize() {}


	/*=========================================================================*/
	/**
	 * @brief デバイス作成時に呼ばれる
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void deviceCreate() {}

	
	/*=========================================================================*/
	/**
	 * @brief 更新処理
	 * 
	 * @param[in] deltaTime 処理の補正値.
	 * @return なし.
	 */
	virtual void update( float deltaTime ) {}


	/*=========================================================================*/
	/**
	 * @brief 描画処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void draw() {}


	/*=========================================================================*/
	/**
	 * @brief 終了処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void end() {}


	/*=========================================================================*/
	/**
	 * @brief アクティブになったときの処理
	 * 
	 * 1 アクティブになった
	 * 0 非アクティブになった
	 *
	 * @param[in] state 状態フラグ.
	 * @return なし.
	 */
	virtual void activate( int state ){}

private:

	/*=========================================================================*/
	/**
	 * @brief アクティブになったときに呼ばれる処理
	 * 
	 * 1 アクティブになった
	 * 0 非アクティブになった
	 *
	 * @param[in] state 状態フラグ.
	 * @return なし.
	 */
	static void onActivate( int state );


	/*=========================================================================*/
	/**
	 * @brief 描画されるときに呼ばれる処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	static void onDisplay();


	/*=========================================================================*/
	/**
	 * @brief アイドル処理時に呼ばれる処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	static void onIdle();


	/*=========================================================================*/
	/**
	 * @brief ウィンドウサイズが変更されたときに呼ばれる処理
	 * 
	 * @param[in] width 変更されたウィンドウ幅.
	 * @param[in] height 変更されたウィンドウ高さ.
	 * @return なし.
	 */
	static void onReshape( int width, int height );


	/*=========================================================================*/
	/**
	 * @brief 削除時に呼ばれる処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	static void onDestroy();


	/*=========================================================================*/
	/**
	 * @brief Vsyncを設定する
	 * 
	 * @param[in] interval 更新間隔.
	 * @return なし.
	 */
	void setSwapInterval( int interval );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止処理)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	FrameWorkGLUT( const FrameWorkGLUT& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード(コピー禁止処理)
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	FrameWorkGLUT& operator = ( const FrameWorkGLUT& other );

private:

	/** 自分のインスタンスポインタ( コールバック用 ) */
	static FrameWorkGLUT* instance_;

private:

	/** フレームワーク記述子 */
	FrameWorkDesc	desc_;

	/** フレームタイマー */
	FrameTimer		frameTimer_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/