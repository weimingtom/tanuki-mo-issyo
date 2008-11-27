/*******************************************************************************/
/**
 * @file FrameWorkGLUT.cpp.
 * 
 * @brief OpenGL GLUT�t���[�����[�N�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"FrameWorkGLUT.h"
#include	"GL/glut.h"
#include	<windows.h>
#include	<sstream>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;


// �������g�̃C���X�^���X��������
FrameWorkGLUT* FrameWorkGLUT::instance_ = 0;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] desc �t���[�����[�N�L�q�q.
 * @param[in] argc �R�}���h���C��������.
 * @param[in] argv �R�}���h���C������.
 */
FrameWorkGLUT::FrameWorkGLUT( const FrameWorkDesc& desc, int argc, char* argv[] ):
	desc_( desc )	// �t���[�����[�N�L�q�q
{
	// �����̃C���X�^���X��ݒ�
	instance_ = this;

	// GULT��������
	glutInit( &argc, argv );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
FrameWorkGLUT::~FrameWorkGLUT()
{}



/*=========================================================================*/
/**
 * @brief �A�v���P�[�V�����̎��s
 * 
 * @param[in] �Ȃ�.
 * @return �I���R�[�h.
 */
int FrameWorkGLUT::run()
{
	// GLUT�E�B���h�E�̐ݒ�
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowPosition( desc().posX, desc().posY );
	glutInitWindowSize( desc().windowWidth, desc().windowHeight );

	// �t���X�N���[�����[�h���H
	if( desc().isFullScreenMode == true ){
		// �t���X�N���[�����[�h�ݒ蕶������쐬
		std::ostringstream mode;
		mode << desc().windowWidth << "x" << desc().windowHeight << "@60";

		// �t���X�N���[�����[�h�ɐݒ�
		glutGameModeString( mode.str().c_str() );
		glutEnterGameMode();

		// �}�E�X�J�[�\��������
		glutSetCursor( GLUT_CURSOR_NONE );
	}
	else{
		glutCreateWindow( desc().windowTitle.c_str() );
	}

	// Vsync��L���ɂ���
	setSwapInterval( 1 );

	// ���������������s
	initialize();

	// �R�[���o�b�N��o�^
	_glutDestroyFunc( onDestroy );
	glutReshapeFunc( onReshape );
	glutDisplayFunc( onDisplay );
	glutIdleFunc( onIdle );
	_glutActivateFunc( onActivate );

	// �t���[���^�C�}�[�����Z�b�g
	frameTimer_.reset();

	// ���C�����[�v�������s��
	glutMainLoop();

	// ���s�I��
	return 0;
}



/*=========================================================================*/
/**
 * @brief �A�v���P�[�V�����̏I��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::exit()
{
	// �t���X�N���[�����[�h��
	if( instance_->desc().isFullScreenMode == true ){
		// �A�v���P�[�V�������I������
		glutLeaveGameMode();
	}
	else{
		// �I���������Ă�
		instance_->end();
	}

	// �����I������
	std::exit( 0 );
}
	
	

/*=========================================================================*/
/**
 * @brief �t���[�����[�N�L�q�q���擾
 * 
 * @param[in] �Ȃ�.
 * @return �t���[�����[�N�L�q�q.
 */
const FrameWorkDesc& FrameWorkGLUT::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief �E�B���h�E�n���h�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �E�B���h�E�n���h��.
 */
void* FrameWorkGLUT::getHWND()
{
	return  _glutGetHWND();
}



/*=========================================================================*/
/**
 * @brief �A�N�e�B�u�ɂȂ����Ƃ��ɌĂ΂�鏈��
 * 
 * 1 �A�N�e�B�u�ɂȂ���
 * 0 ��A�N�e�B�u�ɂȂ���
 *
 * @param[in] state ��ԃt���O.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::onActivate( int state )
{
	// �A�N�e�B�u���̏������Ă�
	instance_->activate( state );
}



/*=========================================================================*/
/**
 * @brief �`�悳���Ƃ��ɌĂ΂�鏈��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::onDisplay()
{
	// �`�揈��
	instance_->draw();

	// �_�u���o�b�t�@�̐؂�ւ�
	glutSwapBuffers();

	// �^�C�}�[�E�F�C�g���s��
	instance_->frameTimer_.wait();
}



/*=========================================================================*/
/**
 * @brief �A�C�h���������ɌĂ΂�鏈��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::onIdle()
{
	// �t���[���^�C�}�[�̍X�V
	instance_->frameTimer_.update();

	do{
		// �X�V���������s
		instance_->update( instance_->frameTimer_.getTime() );

		// �G�X�P�[�v�L�[�������ꂽ��
		if( GetAsyncKeyState( VK_ESCAPE ) != 0 ){
			// �I������
			instance_->exit();
		}
	}while( instance_->frameTimer_.isSkipFrame() == true );

	// �`�揈�����Ă�
	glutPostRedisplay();
}



/*=========================================================================*/
/**
 * @brief �E�B���h�E�T�C�Y���ύX���ꂽ�Ƃ��ɌĂ΂�鏈��
 * 
 * @param[in] width �ύX���ꂽ�E�B���h�E��.
 * @param[in] height �ύX���ꂽ�E�B���h�E����.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::onReshape( int width, int height )
{
	// ������0�ɂȂ�Ȃ��悤�ɒ���
	height = ( height == 0 ) ? 1 : height;

	// �r���[�|�[�g�̐ݒ�
	glViewport( 0, 0, width, height );

	// ���ƍ������X�V
	instance_->desc_.windowWidth	= width;
	instance_->desc_.windowHeight	= height;
}



/*=========================================================================*/
/**
 * @brief �폜���ɌĂ΂�鏈��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::onDestroy()
{
	// �I�����������s
	instance_->end();
}



/*=========================================================================*/
/**
 * @brief Vsync��ݒ肷��
 * 
 * @param[in] interval �X�V�Ԋu.
 * @return �Ȃ�.
 */
void FrameWorkGLUT::setSwapInterval( int interval )
{
	// wglSwapIntervalEXT�g���֐��̃|�C���^�^
	typedef BOOL ( WINAPI * LPFNWGLSWAPINTERVALEXTPROC )( int interval );
	LPFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

	// �g���֐��̊֐��|�C���^���擾
	wglSwapIntervalEXT = ( LPFNWGLSWAPINTERVALEXTPROC )wglGetProcAddress( "wglSwapIntervalEXT" );

	// �擾�ł�����
	assert( wglSwapIntervalEXT != NULL );
	if( wglSwapIntervalEXT != NULL ){
		// �X���b�v�̃C���^�[�o����ݒ�
		wglSwapIntervalEXT( interval );
	}
}

	
	
/*===== EOF ==================================================================*/