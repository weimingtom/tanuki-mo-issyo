/*******************************************************************************/
/**
 * @file IInputDevice.h.
 * 
 * @brief 入力デバイスインターフェース定義.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IINPUTDEVIDCE_H_
#define _NGL_IINPUTDEVIDCE_H_

#include	"Ngl/Vector3.h"

namespace Ngl{


/**
 * @interface IInputDevice．
 * @brief 入力デバイスインターフェース.
 */
class IInputDevice
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IInputDevice() {}


	/*=========================================================================*/
	/**
	 * @brief キー情報を読み込む
	 * 
	 * @param[in] なし.
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual bool loadKeyState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 軸の状態を読み込む
	 * 
	 * @param[in] なし.
	 * @return 各軸の状態ベクトル.
	 */
	virtual Vector3 readAxisState() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 接続デバイス数を取得
	 * 
	 * @param[in] なし.
	 * @return 接続デバイス数.
	 */
	virtual unsigned int getConnectDeviceCount() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief アクティブにするデバイスを変更する
	 * 
	 * @param[in] no 変更するデバイス番号.
	 * @return なし.
	 */
	virtual void setActiveDevice( unsigned int no ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief アクディブになっているデバイス番号を取得する
	 * 
	 * @param[in] なし.
	 * @return アクティブデバイス番号.
	 */
	virtual unsigned int getActiveDeviceNo() = 0;
	 
	 
	/*=========================================================================*/
	/**
	 * @brief 有効キー数を取得
	 *
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual unsigned int getKeyCount() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが押されているか調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	virtual bool getKeyDown() = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが押されているか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	virtual bool getKeyDown( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 押されているキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	virtual unsigned int getDownKey() = 0;


	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが離されたか調べる
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease() = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが離されたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief 離されたキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	virtual unsigned int getReleaseKey() = 0;


	/*=========================================================================*/
	/**
	 * @brief なにかしらのキーがタイプされたか
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger() = 0;


	/*=========================================================================*/
	/**
	 * @brief 指定のキーがタイプされたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger( unsigned int key ) = 0;


	/*=========================================================================*/
	/**
	 * @brief タイプされたキーを取得する
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	virtual unsigned int getTriggerKey() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/