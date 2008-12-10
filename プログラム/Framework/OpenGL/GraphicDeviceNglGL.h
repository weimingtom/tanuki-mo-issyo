/*******************************************************************************/
/**
 * @file GraphicDeviceNglGL.h.<br>
 * 
 * @brief NGL���C�u����OpenGL�O���t�B�b�N�f�o�C�X�N���X�w�b�_�t�@�C��.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GRAPHICDEVICENGLGL_H_
#define _GRAPHICDEVICENGLGL_H_

#include	"GraphicDeviceBase.h"
#include	<Ngl/OpenGL/FrameWorkGLUT.h>

/**
 * @brief NGL���C�u����OpenGL�O���t�B�b�N�f�o�C�X�N���X.
 */
class GraphicDeviceNglGL : public GraphicDeviceBase
{
public:

	/*=========================================================================*/
	/**
	 * �R���X�g���N�^<br>
	 * 
	 * @param[in] frame �t���[�����[�N.
	 */
	GraphicDeviceNglGL( Ngl::OpenGL::FrameWorkGLUT& frame );

	
	/*=========================================================================*/
	/**
	 * �f�X�g���N�^<br>
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~GraphicDeviceNglGL();

	
	/*=========================================================================*/
	/**
	 * �쐬����<br>
	 * 
	 * @param[in] frame �t���[�����[�N.
	 * @return �Ȃ�.
	 */
	void Create( Ngl::IFrameWork* frame );

};


#endif

/*===== EOF ==================================================================*/