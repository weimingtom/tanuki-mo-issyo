/*******************************************************************************/
/**
 * @file KeyFrame.cpp.
 * 
 * @brief �A�j���[�V�����L�[�t���[�����N���X�\�[�X�t�@�C��.
 *
 * @date 2007/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/KeyFrame.h"
#include	<cmath>
#include	<memory>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
KeyFrame::KeyFrame()
{}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
KeyFrame::~KeyFrame()
{
	// �L�[�t���[�������J������
	release();
}



/*=========================================================================*/
/**
 * @brief �g��k���L�[��ǉ�
 * 
 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
 *
 * @param[in] key �ݒ肷��L�[.
 * @return �Ȃ�.
 */
void KeyFrame::addKey( ScaleKey* key )
{
	scaleKeys_.push_back( key );
}



/*=========================================================================*/
/**
 * @brief ��]�L�[��ǉ�
 * 
 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
 *
 * @param[in] key �ݒ肷��L�[.
 * @return �Ȃ�.
 */
void KeyFrame::addKey( RotateKey* key )
{
	rotateKeys_.push_back( key );
}



/*=========================================================================*/
/**
 * @brief ���s�ړ��L�[��ǉ�
 * 
 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
 *
 * @param[in] key �ݒ肷��L�[.
 * @return �Ȃ�.
 */
void KeyFrame::addKey( PositionKey* key )
{
	positionKeys_.push_back( key );
}

	
	
/*===========================================================================*/
/**
 * @brief �L�[�t���[���f�[�^�̎擾
 * 
 * @param[in] globalTime �擾����L�[�̃^�C�}.
 * @param[out] data �L�[�t���[���f�[�^.
 * @return �L�[�t���[���f�[�^.
 */
KeyframeData& KeyFrame::getKey(float globalTime, KeyframeData& data)
{
	// �e�L�[�̒l������������
	data.scale.initialize( 1.0f, 1.0f, 1.0f );
	data.rotate.setIdentity();
	data.position.zero();

	// �g��k���L�[�������Ă��邩
	if( scaleKeys_.empty() == false ){
		// �g��k���L�[���擾����
		getScaleKeys( globalTime, data.scale );
	}

	// ��]�L�[�������Ă��邩
	if( rotateKeys_.empty() == false ){
		// ��]�L�[���擾����
		getRotateKeys( globalTime, data.rotate );

		// ��]�L�[�𐳋K������
		data.rotate.normalize();
	}

	// ���s�ړ��L�[�������Ă��邩
	if( positionKeys_.empty() == false ){
		// ���s�ړ��L�[���擾����
		getPositionKeys( globalTime, data.position );
	}

	return data;
}



/*===========================================================================*/
/**
 * @brief �w��̊g��k���L�[�̃t���[���^�C�����擾����
 * 
 * @param[in] no �g��k���L�[�ԍ�.
 * @return �t���[���^�C�}.
 */
unsigned int KeyFrame::getScaleKeyFrameTime( unsigned int no ) const
{
	// �ԍ����f�[�^�������傫����
	if( no > scaleKeys_.size() ){
		return 0;
	}

	// �t���[���^�C�}���擾���ĕԂ�
	return scaleKeys_[ no ]->frameTimer;
}



/*===========================================================================*/
/**
 * @brief �w��̉�]�L�[�̃t���[���^�C�����擾����
 * 
 * @param[in] no ��]�L�[�ԍ�.
 * @return �t���[���^�C�}.
 */
unsigned int KeyFrame::getRotateKeyFrameTime(unsigned int no) const
{
	// �ԍ����f�[�^�������傫����
	if( no > rotateKeys_.size() ){
		return 0;
	}

	// �t���[���^�C�}���擾���ĕԂ�
	return rotateKeys_[ no ]->frameTimer;
}



/*===========================================================================*/
/**
 * @brief �w��̕��s�ړ��L�[�̃t���[���^�C�����擾����
 * 
 * @param[in] no ���s�ړ��L�[�ԍ�.
 * @return �t���[���^�C�}.
 */
unsigned int KeyFrame::getPositionKeyFrameTime(unsigned int no) const
{
	// �ԍ����f�[�^�������傫����
	if( no > positionKeys_.size() ){
		return 0;
	}

	// �t���[���^�C�}���擾���ĕԂ�
	return positionKeys_[ no ]->frameTimer;
}



/*=========================================================================*/
/**
 * @brief �g��k���L�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �g��k���L�[��.
 */
unsigned int KeyFrame::getNumScaleKeys() const
{
	return static_cast< unsigned int >( scaleKeys_.size() );
}



/*=========================================================================*/
/**
 * @brief ��]�L�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ��]�L�[��.
 */
unsigned int KeyFrame::getNumRotateKeys() const
{
	return static_cast< unsigned int >( rotateKeys_.size() );
}



/*=========================================================================*/
/**
 * @brief ���s�ړ��L�[�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���s�ړ��L�[��.
 */
unsigned int KeyFrame::getNumPositionKeys() const
{
	return static_cast< unsigned int >( positionKeys_.size() );
}


	
/*===========================================================================*/
/**
 * @brief �L�[�t���[�������J������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void KeyFrame::release()
{
	// �g��k���L�[�z������
	ScaleKeyArray::iterator scaleitor=scaleKeys_.begin();
	while( scaleitor != scaleKeys_.end() ){
		delete *scaleitor;
		scaleitor = scaleKeys_.erase( scaleitor );
	}

	// ��]�L�[�z������
	RotateKeyArray::iterator rotateitor=rotateKeys_.begin();
	while( rotateitor != rotateKeys_.end() ){
		delete *rotateitor;
		rotateitor = rotateKeys_.erase( rotateitor );
	}

	// ���s�ړ��L�[�z������
	PositionKeyArray::iterator positionitor=positionKeys_.begin();
	while( positionitor != positionKeys_.end() ){
		delete *positionitor;
		positionitor = positionKeys_.erase( positionitor );
	}
}



/*===========================================================================*/
/**
 * @brief �g��k���L�[���擾����
 * 
 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
 * @param[out] ret �擾�����L�[.
 * @return ���s�ړ��L�[��.
 */
void KeyFrame::getScaleKeys( float globalTime, Vector3 &ret )
{
	unsigned int numKeys = (unsigned int)scaleKeys_.size();	// �L�[��

	// ��]�����߂�
	float fTime = (float)fmod( globalTime, static_cast<float>(scaleKeys_[ numKeys-1 ]->frameTimer) );

	// �L�[�l��������
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)scaleKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)scaleKeys_[iKey1]->frameTimer;
	float fTime2 = (float)scaleKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// �L�[�̕�Ԃ��s��
	ret.lerp( scaleKeys_[iKey1]->value, scaleKeys_[iKey2]->value, fLerpTime );
}



/*===========================================================================*/
/**
 * @brief ��]�L�[���擾����
 * 
 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
 * @param[out] ret �擾�����L�[.
 * @return ���s�ړ��L�[��.
 */
void KeyFrame::getRotateKeys( float globalTime, Quaternion &ret )
{
	unsigned int numKeys = (unsigned int)rotateKeys_.size();	// �L�[��

	// ��]�����߂�
	float fTime = (float)fmod( globalTime, static_cast<float>(rotateKeys_[numKeys-1]->frameTimer) );

	// �L�[�l��������
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)rotateKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)rotateKeys_[iKey1]->frameTimer;
	float fTime2 = (float)rotateKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// �L�[�̕�Ԃ��s��
	ret.slerp( rotateKeys_[iKey1]->value, rotateKeys_[iKey2]->value, fLerpTime );
}



/*===========================================================================*/
/**
 * @brief ���s�ړ��L�[���擾����
 * 
 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
 * @param[out] ret �擾�����L�[.
 * @return ���s�ړ��L�[��.
 */
void KeyFrame::getPositionKeys( float globalTime, Vector3 &ret )
{
	unsigned int numKeys = (unsigned int)positionKeys_.size();	// �L�[��

	// ��]�����߂�
	float fTime = (float)fmod( globalTime, static_cast<float>(positionKeys_[numKeys-1]->frameTimer) );

	// �L�[�l��������
	unsigned int iKey1 = 0;
	unsigned int iKey2 = 0;

	for( unsigned int iKey=0; iKey<numKeys; iKey++ ){
		if( (float)positionKeys_[iKey]->frameTimer > fTime ){
			iKey2 = iKey;

			if( iKey > 0 ){
				iKey1 = iKey - 1;
			}
			else{
				iKey1 = iKey;
			}
			break;
		}
	}

	float fTime1 = (float)positionKeys_[iKey1]->frameTimer;
	float fTime2 = (float)positionKeys_[iKey2]->frameTimer;

	float fLerpTime = 0.0f;
	if( ( fTime2 - fTime1 ) == 0 ){
		fLerpTime = 0.0f;
	}
	else{
		fLerpTime = ( fTime - fTime1 ) / ( fTime2 - fTime1 );
	}

	// �L�[�̕�Ԃ��s��
	ret.lerp( positionKeys_[iKey1]->value, positionKeys_[iKey2]->value, fLerpTime );
}



/*========= EOF =============================================================*/