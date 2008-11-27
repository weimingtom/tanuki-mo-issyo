/*******************************************************************************/
/**
 * @file FrameWorkGLUT.h.
 * 
 * @brief OpenGL GLUT�t���[�����[�N�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_FRAMEWORKGLUT_H_
#define _NGL_OPENGL_FRAMEWORKGLUT_H_

#include	"Ngl/FrameTimer.h"
#include	"Ngl/IFrameWork.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class FrameWorkGLUT�D
 * @brief OpenGL GLUT�t���[�����[�N�N���X.
 */
class FrameWorkGLUT : public IFrameWork
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] desc �t���[�����[�N�L�q�q.
	 * @param[in] argc �R�}���h���C��������.
	 * @param[in] argv �R�}���h���C������.
	 */
	FrameWorkGLUT( const FrameWorkDesc& desc, int argc, char* argv[] );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~FrameWorkGLUT();


	/*=========================================================================*/
	/**
	 * @brief �A�v���P�[�V�����̎��s
	 * 
	 * @param[in] �Ȃ�.
	 * @return �I���R�[�h.
	 */
	virtual int run();

	
	/*=========================================================================*/
	/**
	 * @brief �A�v���P�[�V�����̏I��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void exit();
	
	
	/*=========================================================================*/
	/**
	 * @brief �t���[�����[�N�L�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �t���[�����[�N�L�q�q.
	 */
	virtual const FrameWorkDesc& desc() const;


	/*=========================================================================*/
	/**
	 * @brief �E�B���h�E�n���h�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �E�B���h�E�n���h��.
	 */
	virtual void* getHWND();


	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void initialize() {}


	/*=========================================================================*/
	/**
	 * @brief �f�o�C�X�쐬���ɌĂ΂��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void deviceCreate() {}

	
	/*=========================================================================*/
	/**
	 * @brief �X�V����
	 * 
	 * @param[in] deltaTime �����̕␳�l.
	 * @return �Ȃ�.
	 */
	virtual void update( float deltaTime ) {}


	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void draw() {}


	/*=========================================================================*/
	/**
	 * @brief �I������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void end() {}


	/*=========================================================================*/
	/**
	 * @brief �A�N�e�B�u�ɂȂ����Ƃ��̏���
	 * 
	 * 1 �A�N�e�B�u�ɂȂ���
	 * 0 ��A�N�e�B�u�ɂȂ���
	 *
	 * @param[in] state ��ԃt���O.
	 * @return �Ȃ�.
	 */
	virtual void activate( int state ){}

private:

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
	static void onActivate( int state );


	/*=========================================================================*/
	/**
	 * @brief �`�悳���Ƃ��ɌĂ΂�鏈��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	static void onDisplay();


	/*=========================================================================*/
	/**
	 * @brief �A�C�h���������ɌĂ΂�鏈��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	static void onIdle();


	/*=========================================================================*/
	/**
	 * @brief �E�B���h�E�T�C�Y���ύX���ꂽ�Ƃ��ɌĂ΂�鏈��
	 * 
	 * @param[in] width �ύX���ꂽ�E�B���h�E��.
	 * @param[in] height �ύX���ꂽ�E�B���h�E����.
	 * @return �Ȃ�.
	 */
	static void onReshape( int width, int height );


	/*=========================================================================*/
	/**
	 * @brief �폜���ɌĂ΂�鏈��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	static void onDestroy();


	/*=========================================================================*/
	/**
	 * @brief Vsync��ݒ肷��
	 * 
	 * @param[in] interval �X�V�Ԋu.
	 * @return �Ȃ�.
	 */
	void setSwapInterval( int interval );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	FrameWorkGLUT( const FrameWorkGLUT& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h(�R�s�[�֎~����)
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	FrameWorkGLUT& operator = ( const FrameWorkGLUT& other );

private:

	/** �����̃C���X�^���X�|�C���^( �R�[���o�b�N�p ) */
	static FrameWorkGLUT* instance_;

private:

	/** �t���[�����[�N�L�q�q */
	FrameWorkDesc	desc_;

	/** �t���[���^�C�}�[ */
	FrameTimer		frameTimer_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/