/*******************************************************************************/
/**
 * @file SoundDeviceDS.h.
 * 
 * @brief DirectSound サウンドデバイスクラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_SOUNDDEVIDEDS_H_
#define _NGL_DIRECTINPUT_SOUNDDEVIDEDS_H_

#include	"DirectSound.h"
#include	"DSSocketCreator.h"
#include	"IDirectSoundResource.h"
#include	"Ngl/SoundDeviceBase.h"
#include	<map>


namespace Ngl{


namespace DirectSound{


/**
 * @class SoundDeviceDS.
 * @brief DirectSound サウンドデバイスクラス．
 */
class SoundDeviceDS : public SoundDeviceBase
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	SoundDeviceDS();


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~SoundDeviceDS();

	
	/*=========================================================================*/
	/**
	 * @brief デバイスを作成する
	 * 
	 * @param[in] hwnd ウィンドウハンドル.
	 * @retval true 作成成功.
	 * @retval false 作成失敗.
	 */
	bool create( HWND hwnd );


	/*=========================================================================*/
	/**
	 * @brief ソケット作成者を登録する
	 * 
	 * @param[in] name 登録名（"."を含まない再生ファイルの拡張子).
	 * @param[in] creator 作成者のポインタ.
	 * @return なし.
	 */
	void registCreator( std::string name, DSSocketCreator* creator );
	

	/*=========================================================================*/
	/**
	 * @brief デバイスを解放する
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release();

private:

	/*=========================================================================*/
	/**
	 * @brief リソースを作成する
	 *
	 * @param[in] fileName ファイル名.
	 * @return 作成したリソース.
	 */
	virtual ISoundResource* create( const std::string& fileName );

private:

	/** リソース工場型 */
	typedef std::map< std::string, DSSocketCreator* >	ResourceFactory;

private:

	/** ダイレクトサウンドデバイス */
	LPDIRECTSOUND8		device_;

	/** リソース工場 */
	ResourceFactory		resourceFactory_;

};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/