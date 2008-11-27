/*******************************************************************************/
/**
 * @file FrameTimer.h.
 * 
 * @brief �t���[���^�C�������N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRAMETIMER_H_
#define _NGL_FRAMETIMER_H_

namespace Ngl{


/**
 * @class FrameTimer.
 * @brief �t���[���������Ԍv���N���X�D
 */
class FrameTimer
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	FrameTimer();
	
	
	/*=========================================================================*/
	/**
	 * @brief �t���[���^�C�}�[�̃��Z�b�gbr>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void reset();


	/*=========================================================================*/
	/**
	 * @brief �t���[���^�C�}�[���X�V����br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void update();


	/*=========================================================================*/
	/**
	 * @brief �b�^�C�}�|���擾����br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �o�ߎ���(�b).
	 */
	float timeGetTime();


	/*=========================================================================*/
	/**
	 * @brief ���������ɂ��`��X�L�b�v�̕K�v�����邩���ׂ�br>
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �X�L�b�v���K�v.
	 * @retval false �s�v.
	 */
	bool isSkipFrame();

	
	/*=========================================================================*/
	/**
	 * @brief �E�F�C�g������br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void wait();
	
	
	/*=========================================================================*/
	/**
	 * @brief �t���[���������Ԃ��擾����br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t���[����������.
	 */
	inline float getTime() const
	{
		return frameTime_;
	}


	/*=========================================================================*/
	/**
	 * @brief �E�F�C�g���Ԃ�ݒ肷��br>
	 * 
	 * @param[in] wait �ݒ肷��҂�����.
	 * @return �Ȃ�.
	 */
	inline void setWaitTime( float wait )
	{
		waitTime_ = wait;
	}


	/*=========================================================================*/
	/**
	 * @brief FPS��ݒ肷��br>
	 * 
	 * @param[in] fps �ݒ肷��FPS�l.
	 * @return �Ȃ�.
	 */
	inline void setFPS( float fps )
	{
		fps_ = fps;
	}

public:

	/** �t���[���^�C�� */
	static const float	FPS;

	/** �X�L�b�v�ő吔 */
	static const int	FRAME_SKIP_MAX;

	/** �^�C�}�̌덷 */
	static const float	FPS_ERROR;

private:

	/** FPS */
	float	fps_;

	/** 1�t���[���̊J�n���� */
	float	startTime_;

	/** �O��̃t���[���J�n���� */
	float	prevTime_;

	/** 1�t���[���̌o�ߎ��� */
	float	frameTime_;

	/** �����I�[�o�[���� */
	float	overTime_;

	/** �E�F�C�g���� */
	float	waitTime_;

	/** �t���[���X�L�b�v�J�E���^ */
	int		frameSkipCount_;

	/** �t���[���X�L�b�v�̍ő吔 */
	int		frameSkipCountMax_;

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/