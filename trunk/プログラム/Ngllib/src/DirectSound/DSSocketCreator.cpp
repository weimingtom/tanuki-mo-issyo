/*******************************************************************************/
/**
 * @file DSSocketCreator.cpp.
 * 
 * @brief DirectSound �\�P�b�g�쐬�N���X�\�[�X�t�@�C��.
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
 * @brief �R���X�g���N�^
 * 
 * @param[in] resource �_�C���N�g�T�E���h���\�[�X.
 */
DSSocketCreator::DSSocketCreator( IDirectSoundResource* resource ):
	resource_( resource )
{
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
DSSocketCreator::~DSSocketCreator()
{
	delete resource_;
}



/*=========================================================================*/
/**
 * @brief 
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] ds DirectSound�f�o�C�X�̃|�C���^.
 * @return �쐬�����T�E���h���\�[�X.
 */
ISoundResource* DSSocketCreator::create( const char* fileName, IDirectSound8* ds )
{
	DirectSoundSocket* socket = new DirectSoundSocket();
	socket->create( fileName, ds, resource_ );

	return socket;
}



/*===== EOF ==================================================================*/