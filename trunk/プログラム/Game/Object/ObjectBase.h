/*******************************************************************************/
/**
 * @file ObjectBase.h.
 * 
 * @brief オブジェクト基底クラス定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_BASE_H_
#define _OBJECT_BASE_H_


/**
 * @brief ObjectBase．
 */
class ObjectBase
{
public:

	/*=========================================================================*/
	/**
	 * @brief 仮想デストラクタ.
	 *
	 */
	virtual ~ObjectBase(){}

	/*=========================================================================*/
	/**
	 * @brief 初期化処理.
	 * 
	 */
	virtual void Initialize() = 0;
	/*=========================================================================*/
	/**
	 * @brief 終了処理.
	 * 
	 */
	virtual void Terminate() = 0;
	/*=========================================================================*/
	/**
	 * @brief 終了しているかどうか.
	 * 
	 * @return 終了フラグ.
	 */
	virtual bool IsTerminated() = 0;

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの描画処理.
	 * 
	 */
	virtual void RenderObject() = 0;
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの更新処理.
	 * 
	 * @param[in] frameTimer 更新タイマ.
	 */
	virtual void UpdateObject(float frameTimer) = 0;
};

#endif

/*===== EOF ===================================================================*/
