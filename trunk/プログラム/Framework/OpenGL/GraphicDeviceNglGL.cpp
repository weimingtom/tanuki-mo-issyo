/*******************************************************************************/
/**
 * @file GraphicDeviceNglGL.cpp.<br>
 * 
 * @brief NGL���C�u����OpenGL�O���t�B�b�N�f�o�C�X�N���X�\�[�X�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"GraphicDeviceNglGL.h"
#include	<Ngl/OpenGL/RendererGL.h>
#include	<cassert>


/*=========================================================================*/
/**
 * �R���X�g���N�^<br>
 * 
 * @param[in] frame �t���[�����[�N.
 */
GraphicDeviceNglGL::GraphicDeviceNglGL( Ngl::OpenGL::FrameWorkGLUT& frame ):
GraphicDeviceBase( frame )
{}



/*=========================================================================*/
/**
 * �f�X�g���N�^<br>
 * 
 * @param[in] �Ȃ�.
 */
GraphicDeviceNglGL::~GraphicDeviceNglGL()
{}



/*=========================================================================*/
/**
 * �쐬����<br>
 * 
 * @param[in] frame �t���[�����[�N.
 * @return �Ȃ�.
 */
void GraphicDeviceNglGL::Create( Ngl::IFrameWork* frame )
{
	// �����_���[���쐬
	renderer_ = new Ngl::OpenGL::RendererGL;
	assert( renderer_ != NULL );
	renderer_->initialize();

	// �r���[�|�[�g��������
	Ngl::ViewportDesc viewport = { 0, 0, frame->desc().windowWidth, frame->desc().windowHeight };
	renderer_->setViewport( viewport );

	// �G�t�F�N�g�̊g���q��ݒ�
	effectExtName_ = ".cgfx";

	// �l�p�`�|���S�����쐬
	quad_.create( renderer_  );
}
	
	

/*===== EOF ==================================================================*/