/*******************************************************************************/
/**
 * @file FrameTimer.cpp.
 * 
 * @brief �t���[���^�C�������N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/FrameTimer.h"
#include	<windows.h>

using namespace Ngl;

/*==== �萔�錾 =============================================================*/
const int	FrameTimer::FRAME_SKIP_MAX	= 8;		// �t���[���X�L�b�v�̍ő�\��
const float	FrameTimer::FPS_ERROR		= 0.1f;		// �^�C�}�덷
const float	FrameTimer::FPS				= 60.0f;	// �t���[���^�C��


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
FrameTimer::FrameTimer() :
	fps_( FPS ),						// FPS
	startTime_( 0.0f ),					// 1�t���[���J�n����
	prevTime_( 0.0f ),					// �O��̃t���[���J�n����
	frameTime_( 0.0f ),					// 1�t���[���̌o�ߎ���
	overTime_( 0.0f ),					// �����I�[�o�[����
	waitTime_( 0.25f ),					// �E�F�C�g����
	frameSkipCount_( 0 ),				// �t���[���X�L�b�v�J�E���^
	frameSkipCountMax_( FRAME_SKIP_MAX )// �t���[���X�L�b�v�̍ő吔
{}



/*===========================================================================*/
/**
 * @brief �t���[���^�C�}�[�̃��Z�b�gbr>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameTimer::reset()
{
	startTime_			= 0.0f;		// �t���[���J�n����
	frameTime_			= 0.0f;		// 1�t���[���̏�������
	overTime_			= 0.0f;		// �����I�[�o�[����
	waitTime_			= 0.25f;	// �E�F�C�g����
	frameSkipCount_		= 0;		// �t���[���X�L�b�v��

	// �O��̃t���[���J�n���Ԃ�ۑ�����
	prevTime_			= timeGetTime();
}



/*===========================================================================*/
/**
 * @brief �t���[���^�C�}�[���X�V����br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameTimer::update()
{
	// 1�t���[���̊J�n���Ԃ��v��
	startTime_ = timeGetTime();

	// 1�t���[��������̏������Ԃ����߂�
	frameTime_ = ( startTime_ - prevTime_ ) * fps_;

	// �O��̃^�C�}�[�l�Ƃ��ĕۑ�����
	prevTime_ = startTime_;

	// FPS�^�C�}�[�ȏ�Ɏ��Ԃ��o�߂��Ă��܂��Ă��邩
	overTime_ = 0.0f;
	if( frameTime_ > 1.0f ){
		// �I�[�o�[�������Ԃ��v�Z����
		overTime_ = frameTime_ - 1.0f;

		// �I�[�o�[����␳����
		frameTime_ = 1.0f;

		// �덷�͈͓̔������肷��
		if( overTime_ <= FPS_ERROR ){
			overTime_ = 0.0f;
		}
	}
}



/*===========================================================================*/
/**
 * @brief �b�^�C�}�|���擾����br>
 * 
 * @param[in] �Ȃ�.
 * @return �o�ߎ���(�b). �@
 */
float FrameTimer::timeGetTime()
{
	// �^�C�}���擾����
	LARGE_INTEGER Time;
	QueryPerformanceCounter( &Time );

	// �^�C�}�̕���\���擾����
	LARGE_INTEGER Freq;
	QueryPerformanceFrequency( &Freq );

	// �b�P�ʂɕϊ����ĕԂ�
	return	(float)( (double)Time.QuadPart / (double)Freq.QuadPart );
}



/*===========================================================================*/
/**
 * @brief ���������ɂ��`��X�L�b�v�̕K�v�����邩���ׂ�br>
 * 
 * @param[in] �Ȃ�.
 * @retval true �X�L�b�v���K�v.
 * @retval false �s�v.
 */
bool FrameTimer::isSkipFrame()
{
	// �ő�X�L�b�v���ȏ�̓X�L�b�v�����Ȃ��悤�ɂ���
	if( frameSkipCount_ >= FRAME_SKIP_MAX ){
		/* �X�L�b�v�������������� */
		frameSkipCount_ = 0;

		/* �I�[�o�[�������Ԃ����������� */
		overTime_ = 0.0f;

		return	false;
	}

	// ���ԃI�[�o�[���Ă��邩
	if ( overTime_ > 0 ){
		// �e�o�r�^�C�}�����I�[�o�[���Ă��邩�H
		if ( overTime_ > 1.0f ){
			// �I�[�o�[�������Ԃ𒲐�����
			overTime_ -= 1.0f;

			// �^�C�}�𒲐�����
			frameTime_ = 1.0f;
		}
		else{
			// �^�C�}�𒲐�����
			frameTime_ = overTime_;

			// �I�[�o�[�������ԕ��͏������������ɂ���
			overTime_ = 0.0f;
		}

		// �X�L�b�v�J�E���^�𑝉�������
		frameSkipCount_++;

		// �`����X�L�b�v����K�v������
		return	true;
	}

	// �X�L�b�v�J�E���^������������
	frameSkipCount_ = 0;

	// �I�[�o�[�������Ԃ�����������
	overTime_ = 0.0f;

	return	false;
}



/*===========================================================================*/
/**
 * @brief �E�F�C�g������br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameTimer::wait()
{
	// �P�t���[��������̎��Ԃ����߂�
	float		frameTime;
	frameTime = ( timeGetTime() - startTime_ ) * fps_;

	// �Œ�E�F�C�g���Ԃ������Ԃ��Z����
	if ( frameTime < waitTime_ ){
		// �E�F�C�g���鎞�Ԃ����߂�
		float		waitTime;
		waitTime = waitTime_ - frameTime;

		// �Œ�E�F�C�g�^�C�}���E�F�C�g����
		float		startTime;
		startTime = timeGetTime() * fps_;
		while ( ( ( ( timeGetTime() * fps_ ) - startTime )  ) < waitTime );
	}
}



/*========= EOF =============================================================*/