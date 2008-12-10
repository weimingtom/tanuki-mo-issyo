/*******************************************************************************/
/*
 * @file ApplicationRunnerNglGL.h.<br>
 * 
 * @brief NglGL���C�u���� �A�v���P�[�V�������s�N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _APPLICATIONRUNNERNGLGL_H_
#define _APPLICATIONRUNNERNGLGL_H_

#include	"GameFrame.h"
#include	"GameDeviceNglGL.h"
#include	"IApplicationRunner.h"
#include	<Ngl/OpenGL/FrameWorkGLUT.h>

/**
 * @class ApplicationRunner�D
 * @brief�A�v���P�[�V�������s�N���X.
 */
class ApplicationRunnerNglGL : public Ngl::OpenGL::FrameWorkGLUT, public IApplicationRunner
{

public:

	/*=========================================================================*/
	/**
	 * �R���X�g���N�^<br>
	 * 
	 * @param[in] desc �t���[�����[�N�L�q�q.
	 * @param[in] argc �R�}���h���C��������.
	 * @param[in] argv �R�}���h���C������.
	 */
	ApplicationRunnerNglGL( const Ngl::FrameWorkDesc& desc, int argc, char* argv[] );


	/*=========================================================================*/
	/**
	 * �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ApplicationRunnerNglGL();


	/*=========================================================================*/
	/**
	 * �A�v���P�[�V�����̎��s<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �I���R�[�h.
	 */
	virtual int runApp();
	
private:
	
	/*=========================================================================*/
	/**
	 * ����������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void initialize();


	/*=========================================================================*/
	/**
	 * �X�V����<br>
	 * 
	 * @param[in] deltaTime �����̕␳�l.
	 * @return �Ȃ�.
	 */
	virtual void update( float deltaTime );


	/*=========================================================================*/
	/**
	 * �`�揈��<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void draw();


	/*=========================================================================*/
	/**
	 * �I������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void end();

private:

	/** �Q�[���f�o�C�X */
	GameDeviceNglGL		device_;

	/** �Q�[�� */
	GameFrame			game_;

};

#endif

/*===== EOF ==================================================================*/