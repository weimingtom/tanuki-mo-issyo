/*******************************************************************************/
/**
 * @file IDirectSoundResource.h.
 * 
 * @brief DirectSound オーディオリソースインターフェース定義.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_IDIRECTSOUNDRESOURCE_H_
#define _NGL_DIRECTSOUND_IDIRECTSOUNDRESOURCE_H_

#include	<dsound.h>

namespace Ngl{


namespace DirectSound{


/**
 * @interface IDirectSoundResource.
 * @brief DirectSound オーディオリソースインターフェース．
 */
class IDirectSoundResource
{

public:

	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~IDirectSoundResource() {}

	
	/*=========================================================================*/
	/**
	 * @brief 作成する
	 * 
	 * @param[in] fileName ファイル名.
	 * @param[in] ds ダイレクトサウンドオブジェクト.
	 * @param[in] enable3D 3Dサウンドを有効にするか.
	 * @return ダイレクトサウンドバッファ.
	 */
	virtual IDirectSoundBuffer* create( const char* fileName, IDirectSound8* ds, bool enable3D=false ) = 0;

};

}	// namespace DirectSound

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/