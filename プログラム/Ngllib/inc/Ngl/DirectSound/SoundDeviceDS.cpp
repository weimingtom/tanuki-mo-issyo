/*******************************************************************************/
/**
 * @file SoundDeviceDS.cpp.
 * 
 * @brief DirectSound �T�E���h�f�o�C�X�N���X�\�[�X�t�@�C��.
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
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceDS::SoundDeviceDS():
	device_( 0 )	// DirectSound�I�u�W�F�N�g
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
SoundDeviceDS::~SoundDeviceDS()
{
	// �f�o�C�X���������
	release();
}



/*===========================================================================*/
/**
 * @brief �f�o�C�X���쐬����
 * 
 * @param[in] hwnd �E�B���h�E�n���h��.
 * @retval true �쐬����.
 * @retval false �쐬���s.
 */
bool SoundDeviceDS::create(HWND hwnd)
{
	HRESULT hr = DS_OK;	// ���s����

	// �f�o�C�X���쐬����
	hr = DirectSoundCreate8( 0, &device_, 0 );
	assert( hr == DS_OK );

	// �������x����ݒ肷��
	hr = device_->SetCooperativeLevel( hwnd, DSSCL_EXCLUSIVE );
	assert( hr == DS_OK );

	// �쐬����
	return true;
}



/*=========================================================================*/
/**
 * @brief �\�P�b�g�쐬�҂�o�^����
 * 
 * @param[in] name �o�^���i"."���܂܂Ȃ��Đ��t�@�C���̊g���q).
 * @param[in] creator �쐬�҂̃|�C���^.
 * @return �Ȃ�.
 */
void SoundDeviceDS::registCreator( std::string name, DSSocketCreator* creator )
{
	assert( creator != NULL );

	resourceFactory_[ name ] = creator;
}



/*=========================================================================*/
/**
 * @brief ���\�[�X���쐬����
 *
 * @param[in] fileName �t�@�C����.
 * @return �쐬�������\�[�X.
 */
ISoundResource* SoundDeviceDS::create(const std::string& fileName )
{
	// �g���q���擾����
	std::string fileExt = Utility::getFileExtension( fileName.c_str() );

	// ���\�[�X���쐬����
	ISoundResource* res = resourceFactory_[ fileExt ]->create( fileName.c_str(), device_ );

	return res;
}



/*===========================================================================*/
/**
 * @brief �f�o�C�X���������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void SoundDeviceDS::release()
{
	// �f�o�C�X���쐬����Ă��邩
	if( device_ == 0){
		// �f�o�C�X���쐬����Ă��Ȃ��̂ŏI��
		return;
	}

	// �o�b�t�@�����ׂč폜
	clearBuffer();

	// ���\�[�X�t�@�N�g���̗v�f��S�폜����
	ResourceFactory::iterator facItor = resourceFactory_.begin();
	while( facItor != resourceFactory_.end() ){
		delete facItor->second;
		facItor = resourceFactory_.erase( facItor );
	}

	// DirectInput�f�o�C�X���폜����
	device_->Release();
	device_ = 0;
}



/*========= EOF =============================================================*/