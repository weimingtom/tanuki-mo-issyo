/*******************************************************************************/
/*
 * @file ApplicationRunnerNglGL.cpp.<br>
 * 
 * @brief NglGL���C�u���� �A�v���P�[�V�������s�N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"ApplicationRunnerNglGL.h"

/*=========================================================================*/
/**
 * �R���X�g���N�^<br>
 * 
 * @param[in] desc �t���[�����[�N�L�q�q.
 * @param[in] argc �R�}���h���C��������.
 * @param[in] argv �R�}���h���C������.
 */
ApplicationRunnerNglGL::ApplicationRunnerNglGL( const Ngl::FrameWorkDesc& desc, int argc, char* argv[] ):
	Ngl::OpenGL::FrameWorkGLUT( desc, argc, argv )
{}



/*=========================================================================*/
/**
 * �f�X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
ApplicationRunnerNglGL::~ApplicationRunnerNglGL()
{}



/*=========================================================================*/
/**
 * �A�v���P�[�V�����̎��s<br>
 * 
 * @param[in] �Ȃ�.
 * @return �I���R�[�h.
 */
int ApplicationRunnerNglGL::runApp()
{
	return run();
}


	
/*=========================================================================*/
/**
 * ����������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void ApplicationRunnerNglGL::initialize()
{
	// �Q�[���f�o�C�X���쐬
	device_.Create( *this );

	// �r���[�|�[�g�̐ݒ�
	static const ViewportDesc viewportDesc = { 0, 0, desc().windowWidth, desc().windowHeight };
	device_.GetGraphicDevice().Viewport( viewportDesc );

	// �Q�[���̏���������
	game_.Initialize( device_ );
}



/*=========================================================================*/
/**
 * �X�V����<br>
 * 
 * @param[in] deltaTime �����̕␳�l.
 * @return �Ȃ�.
 */
void ApplicationRunnerNglGL::update( float deltaTime )
{
	// �Q�[���f�o�C�X�̍X�V����
	device_.Update( deltaTime );

	// �Q�[���̍X�V����
	game_.Update( device_, deltaTime );
}



/*=========================================================================*/
/**
 * �`�揈��<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void ApplicationRunnerNglGL::draw()
{
	// �Q�[���̕`�揈��
	game_.Draw( device_ );

	// �o�b�N�o�b�t�@�ɕ`��
	device_.GetGraphicDevice().Renderer().flush();
}



/*=========================================================================*/
/**
 * �I������<br>
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void ApplicationRunnerNglGL::end()
{
	// �Q�[���̏I������
	game_.Finish( device_ );

	// �f�o�C�X�̏I������
	device_.End();
}



/*===== EOF ==================================================================*/