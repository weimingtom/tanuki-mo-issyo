/*******************************************************************************/
/**
 * @file InputDeviceManager.cpp.
 * 
 * @brief 入力デバイス管理者クラスソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/InputDeviceManager.h"

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] id 最初にアクティブにするID名.
 */
InputDeviceManager::InputDeviceManager( unsigned int id ):
	activeDeviceID_( id )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
InputDeviceManager::~InputDeviceManager()
{}



/*=========================================================================*/
/**
 * @brief デバイスを登録
 * 
 * @param[in] name 登録デバイス名.
 * @param[in] device 登録するデバイスのポインタ.
 * @return なし.
 */
void InputDeviceManager::regist( unsigned int name, IInputDevice* device )
{
	assert( device != NULL );

	inputDeviceContainer_.add( name, device );
}



/*=========================================================================*/
/**
 * @brief 登録されているデバイスをすべて削除
 * 
 * @param[in] なし.
 * @return なし.
 */
void InputDeviceManager::clear()
{
	inputDeviceContainer_.clear();
}



/*=========================================================================*/
/**
 * @brief アクティブデバイスの接続デバイスを変更する
 * 
 * 現在アクティブになっている入力デバイスの、入力を読み取るデバイスを変更します。
 *
 * @param[in] connectID 変更する接続デバイス番号.
 * @return なし.
 */
void InputDeviceManager::changeActiveConnectDevice( unsigned int connectID )
{
	// 入力デバイスに接続されているデバイスを変更
	inputDeviceContainer_[ activeDeviceID_ ]->setActiveDevice( connectID );
}

	
	
/*=========================================================================*/
/**
 * @brief アクティブの入力デバイスのアクティブな接続デバイス番号を取得
 * 
 * @param[in] なし.
 * @return アクティブの入力デバイスのアクティブな接続デバイス番号.
 */
unsigned int InputDeviceManager::getActiveConnectDeviceNo()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getActiveDeviceNo();
}
	
	
	
/*=========================================================================*/
/**
 * @brief アクティブデバイスの、接続デバイス数を取得
 * 
 * @param[in] なし.
 * @return 接続デバイス数.
 */
unsigned int InputDeviceManager::getConnectDeviceCount()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getConnectDeviceCount();
}

	
	
/*=========================================================================*/
/**
 * @brief アクティブにするデバイスを変更する
 * 
 * @param[in] no 変更するデバイス番号.
 * @return なし.
 */
void InputDeviceManager::setActiveDevice( unsigned int no )
{
	// 入力デバイスを変更
	activeDeviceID_ = no;
}



/*=========================================================================*/
/**
 * @brief アクディブになっているデバイス番号を取得する
 * 
 * @param[in] なし.
 * @return アクティブデバイス番号.
 */
unsigned int InputDeviceManager::getActiveDeviceNo()
{
	return activeDeviceID_;
}

	
	
/*=========================================================================*/
/**
 * @brief 有効キー数を取得
 *
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
unsigned int InputDeviceManager::getKeyCount()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyCount();
}
	
	
	
/*=========================================================================*/
/**
 * @brief 入力デバイス数を取得
 * 
 * @param[in] なし.
 * @return なし.
 */
unsigned int InputDeviceManager::getDeviceCount()
{
	return inputDeviceContainer_.size();
}



/*=========================================================================*/
/**
 * @brief キー情報を読み込む
 *
 * @retval true 取得成功.
 * @retval false 取得失敗.
 */
bool InputDeviceManager::loadKeyState()
{
	// 要素が空か
	if( inputDeviceContainer_.empty() == true ){
		return false;
	}

	// デバイス情報を読み込む
	LoadVisitor loadVisitor;
	inputDeviceContainer_.accept( loadVisitor );

	return true;
}



/*=========================================================================*/
/**
 * @brief 軸の状態を読み込む
 * 
 * @param[in] なし.
 * @return 各軸の状態ベクトル.
 */
Vector3 InputDeviceManager::readAxisState()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->readAxisState();
}



/*=========================================================================*/
/**
 * @brief 何かしらのキーが押されているか調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されている.
 * @retval 0 何も押されていない.
 */
bool InputDeviceManager::getKeyDown()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyDown();
}



/*=========================================================================*/
/**
 * @brief 指定したキーが押されているか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true 押されていた.
 * @retval false 押されていなかった.
 */
bool InputDeviceManager::getKeyDown( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyDown( key );
}



/*=========================================================================*/
/**
 * @brief 押されているキーを調べる
 * 
 * @param[in] なし.
 * @retval 1以上 押されているキー.
 * @retval 0 何も押されていない.
 */
unsigned int InputDeviceManager::getDownKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getDownKey();
}



/*=========================================================================*/
/**
 * @brief 何かしらのキーが離されたか調べる
 * 
 * @param[in] なし.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool InputDeviceManager::getKeyRelease()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyRelease();
}



/*=========================================================================*/
/**
 * @brief 指定したキーが離されたか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true 離された.
 * @retval false 離されていない.
 */
bool InputDeviceManager::getKeyRelease( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyRelease( key );
}



/*=========================================================================*/
/**
 * @brief 離されたキーを調べる
 * 
 * @param[in] なし.
 * @retval 1以上 離されたキー.
 * @retval 0 離されていない。
 */
unsigned int InputDeviceManager::getReleaseKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getReleaseKey();
}



/*=========================================================================*/
/**
 * @brief なにかしらのキーがタイプされたか
 * 
 * @param[in] なし.
 * @retval true タイプされた.
 : @retval false タイプされていない.
 */
bool InputDeviceManager::getKeyTrigger()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyTrigger();
}



/*=========================================================================*/
/**
 * @brief 指定のキーがタイプされたか調べる
 * 
 * @param[in] key 調べるキー.
 * @retval true タイプされた.
 * @retval false タイプされていない.
 */
bool InputDeviceManager::getKeyTrigger( unsigned int key )
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getKeyTrigger( key );
}



/*=========================================================================*/
/**
 * @brief タイプされたキーを取得する
 * 
 * @param[in] なし.
 * @retval 1以上 タイプされたキー.
 * @retval 0 タイプされていない.
 */
unsigned int InputDeviceManager::getTriggerKey()
{
	return inputDeviceContainer_[ activeDeviceID_ ]->getTriggerKey();
}



/*===== EOF ==================================================================*/