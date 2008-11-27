/*******************************************************************************/
/**
 * @file DSSocketCreator.h.
 * 
 * @brief DirectSound ソケット作成クラスヘッダファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_DSSOCKETCREATOR_H_
#define _NGL_DIRECTSOUND_DSSOCKETCREATOR_H_

#include	"DirectSound.h"
#include	"IDirectSoundResource.h"
#include	"Ngl/ISoundResource.h"

namespace Ngl{


namespace DirectSound{


/**
 * @class DSSocketCreator．
 * @brief DirectSound ソケット作成クラス.
 */
class DSSocketCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] resource ダイレクトサウンドリソース.
	 */
	DSSocketCreator( IDirectSoundResource* resource );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~DSSocketCreator();


	/*=========================================================================*/
	/**
	 * @brief 
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] ds DirectSoundデバイスのポインタ.
	 * @return 作成したサウンドリソース.
	 */
	ISoundResource* create( const char* fileName, IDirectSound8* ds );

private:

	/** ダイレクトサウンドリソース */
	IDirectSoundResource*	resource_;

};

} // namespace DirectSound

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/