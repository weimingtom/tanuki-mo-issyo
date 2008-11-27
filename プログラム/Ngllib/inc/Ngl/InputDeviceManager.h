/*******************************************************************************/
/**
 * @file InputDeviceManager.h.
 * 
 * @brief 入力デバイス管理者クラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_INPUTDEVICEMANAGER_H_
#define _NGL_INPUTDEVICEMANAGER_H_

#include	"Ngl/Manager/ObjectManager.h"
#include	"Ngl/Manager/IEntityVisitor.h"
#include	"IInputDevice.h"
#include	<functional>
#include	<algorithm>
#include	<cassert>
#include	<string>
#include	<map>


namespace Ngl{


/**
 * @class InputDeviceManager．
 * @brief 入力デバイス管理者クラス.
 *
 * 入力デバイスをまとめて管理するためのクラスです。
 * 管理者自体も1つの入力デバイスとして扱うことができます。
 */
class InputDeviceManager : public IInputDevice
{
private:

	/**
	 * @class LoadVisitor.
	 * @brief 入力デバイス管理者 キー情報更新訪問者クラス.
	 *
	 * 全ての管理要素のキー入力状態を更新する。
	 *
	 */
	class LoadVisitor : public IEntityVisitor< IInputDevice* >
	{
	public:

		/**
		 * @brief 要素を訪問する.
		 *
		 * @param[in] entity 訪問した要素.
		 * @return なし.
		 */
		void visit( IInputDevice* entity )
		{
			// キー情報を読み込む
			entity->loadKeyState();
		}
	};

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] id 最初にアクティブにするID名.
	 */
	InputDeviceManager( unsigned int id=0 );
	

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~InputDeviceManager();


	/*=========================================================================*/
	/**
	 * @brief デバイスを登録
	 * 
	 * @param[in] name 登録デバイス名.
	 * @param[in] device 登録するデバイスのポインタ.
	 * @return なし.
	 */
	void regist( unsigned int name, IInputDevice* device );
	

	/*=========================================================================*/
	/**
	 * @brief 登録されているデバイスをすべて削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clear();
	

	/*=========================================================================*/
	/**
	 * @brief アクティブデバイスの接続デバイスを変更する
	 *
	 * 現在アクティブになっている入力デバイスの、入力を読み取るデバイスを変更します。
	 * 
	 * @param[in] connectID 変更する接続デバイス番号.
	 * @return なし.
	 */
	void changeActiveConnectDevice( unsigned int connectID=0 );

	
	/*=========================================================================*/
	/**
	 * @brief アクティブの入力デバイスのアクティブな接続デバイス番号を取得
	 * 
	 * @param[in] なし.
	 * @return アクティブの入力デバイスのアクティブな接続デバイス番号.
	 */
	unsigned int getActiveConnectDeviceNo();
	
	
	/*=========================================================================*/
	/**
	 * @brief アクティブデバイスの、接続デバイス数を取得
	 * 
	 * @param[in] なし.
	 * @return 接続デバイス数.
	 */
	unsigned int getConnectDeviceCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief アクティブにするデバイスを変更する
	 * 
	 * @param[in] no 変更するデバイス番号.
	 * @return なし.
	 */
	virtual void setActiveDevice( unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief アクディブになっているデバイス番号を取得する
	 * 
	 * @param[in] なし.
	 * @return アクティブデバイス番号.
	 */
	virtual unsigned int getActiveDeviceNo();
	
	
	/*=========================================================================*/
	/**
	 * @brief 有効キー数を取得
	 *
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual unsigned int getKeyCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief 入力デバイス数を取得
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual unsigned int getDeviceCount();
	
	
	/*=========================================================================*/
	/**
	 * @brief キー情報を読み込む
	 *
	 * @retval true 取得成功.
	 * @retval false 取得失敗.
	 */
	virtual bool loadKeyState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 軸の状態を読み込む
	 * 
	 * @param[in] なし.
	 * @return 各軸の状態ベクトル.
	 */
	virtual Vector3 readAxisState();
	
	
	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが押されているか調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されている.
	 * @retval 0 何も押されていない.
	 */
	virtual bool getKeyDown();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが押されているか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 押されていた.
	 * @retval false 押されていなかった.
	 */
	virtual bool getKeyDown( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief 押されているキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 押されているキー.
	 * @retval 0 何も押されていない.
	 */
	virtual unsigned int getDownKey();


	/*=========================================================================*/
	/**
	 * @brief 何かしらのキーが離されたか調べる
	 * 
	 * @param[in] なし.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease();


	/*=========================================================================*/
	/**
	 * @brief 指定したキーが離されたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true 離された.
	 * @retval false 離されていない.
	 */
	virtual bool getKeyRelease( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief 離されたキーを調べる
	 * 
	 * @param[in] なし.
	 * @retval 1以上 離されたキー.
	 * @retval 0 離されていない。
	 */
	virtual unsigned int getReleaseKey();


	/*=========================================================================*/
	/**
	 * @brief なにかしらのキーがタイプされたか
	 * 
	 * @param[in] なし.
	 * @retval true タイプされた.
	 : @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger();


	/*=========================================================================*/
	/**
	 * @brief 指定のキーがタイプされたか調べる
	 * 
	 * @param[in] key 調べるキー.
	 * @retval true タイプされた.
	 * @retval false タイプされていない.
	 */
	virtual bool getKeyTrigger( unsigned int key );


	/*=========================================================================*/
	/**
	 * @brief タイプされたキーを取得する
	 * 
	 * @param[in] なし.
	 * @retval 1以上 タイプされたキー.
	 * @retval 0 タイプされていない.
	 */
	virtual unsigned int getTriggerKey();

private:

	/** 入力デバイスコンテナ型 */
	typedef ObjectManager< unsigned int, IInputDevice* >	InputDeviceContainer;

private:

	/** アクティブなデバイスのID */
	unsigned int			activeDeviceID_;

	/** 入力デバイスコンテナ */
	InputDeviceContainer	inputDeviceContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/