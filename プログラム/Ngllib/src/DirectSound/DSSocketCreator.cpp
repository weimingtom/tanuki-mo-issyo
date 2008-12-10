/*******************************************************************************/
/**
 * @file DSSocketCreator.cpp.
 * 
 * @brief DirectSound ソケット作成クラスソースファイル.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/DirectSound/DSSocketCreator.h"
#include	"Ngl/DirectSound/DirectSoundSocket.h"

using namespace Ngl;
using namespace Ngl::DirectSound;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] resource ダイレクトサウンドリソース.
 */
DSSocketCreator::DSSocketCreator( IDirectSoundResource* resource ):
	resource_( resource )
{
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
DSSocketCreator::~DSSocketCreator()
{
	delete resource_;
}



/*=========================================================================*/
/**
 * @brief 
 * 
 * @param[in] fileName ファイル名.
 * @param[in] ds DirectSoundデバイスのポインタ.
 * @return 作成したサウンドリソース.
 */
ISoundResource* DSSocketCreator::create( const char* fileName, IDirectSound8* ds )
{
	DirectSoundSocket* socket = new DirectSoundSocket();
	socket->create( fileName, ds, resource_ );

	return socket;
}



/*===== EOF ==================================================================*/