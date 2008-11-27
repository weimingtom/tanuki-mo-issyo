/*******************************************************************************/
/**
 * @file SoundDeviceDS.cpp.
 * 
 * @brief DirectSound サウンドデバイスクラスソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"SoundDeviceDS.h"
#include	"DirectSoundSocket.h"
#include	"Ngl/Utility.h"
#include	<cassert>

using namespace Ngl;
using namespace Ngl::DirectSound;


/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceDS::SoundDeviceDS():
	device_( 0 )	// DirectSoundオブジェクト
{}



/*===========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
SoundDeviceDS::~SoundDeviceDS()
{
	// デバイスを解放する
	release();
}



/*===========================================================================*/
/**
 * @brief デバイスを作成する
 * 
 * @param[in] hwnd ウィンドウハンドル.
 * @retval true 作成成功.
 * @retval false 作成失敗.
 */
bool SoundDeviceDS::create(HWND hwnd)
{
	HRESULT hr = DS_OK;	// 実行結果

	// デバイスを作成する
	hr = DirectSoundCreate8( 0, &device_, 0 );
	assert( hr == DS_OK );

	// 強調レベルを設定する
	hr = device_->SetCooperativeLevel( hwnd, DSSCL_EXCLUSIVE );
	assert( hr == DS_OK );

	// 作成成功
	return true;
}



/*=========================================================================*/
/**
 * @brief ソケット作成者を登録する
 * 
 * @param[in] name 登録名（"."を含まない再生ファイルの拡張子).
 * @param[in] creator 作成者のポインタ.
 * @return なし.
 */
void SoundDeviceDS::registCreator( std::string name, DSSocketCreator* creator )
{
	assert( creator != NULL );

	resourceFactory_[ name ] = creator;
}



/*=========================================================================*/
/**
 * @brief リソースを作成する
 *
 * @param[in] fileName ファイル名.
 * @return 作成したリソース.
 */
ISoundResource* SoundDeviceDS::create(const std::string& fileName )
{
	// 拡張子を取得する
	std::string fileExt = Utility::getFileExtension( fileName.c_str() );

	// リソースを作成する
	ISoundResource* res = resourceFactory_[ fileExt ]->create( fileName.c_str(), device_ );

	return res;
}



/*===========================================================================*/
/**
 * @brief デバイスを解放する
 * 
 * @param[in] なし.
 * @return なし.
 */
void SoundDeviceDS::release()
{
	// デバイスが作成されているか
	if( device_ == 0){
		// デバイスが作成されていないので終了
		return;
	}

	// バッファをすべて削除
	clearBuffer();

	// リソースファクトリの要素を全削除する
	ResourceFactory::iterator facItor = resourceFactory_.begin();
	while( facItor != resourceFactory_.end() ){
		delete facItor->second;
		facItor = resourceFactory_.erase( facItor );
	}

	// DirectInputデバイスを削除する
	device_->Release();
	device_ = 0;
}



/*========= EOF =============================================================*/