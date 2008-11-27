/*******************************************************************************/
/**
 * @file ITextureFilter.h.
 * 
 * @brief �e�N�X�`���t�B���^�C���^�[�t�F�[�X��`.
 *
 * @date 2008/08/22.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ITEXTUREFILTER_H_
#define _NGL_ITEXTUREFILTER_H_


namespace Ngl{


/**
 * @interface ITextureFilter�D
 * @brief �e�N�X�`���t�B���^�C���^�[�t�F�[�X.
 */
class ITextureFilter
{

protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~ITextureFilter() {}

public:

	/*=========================================================================*/
	/**
	 * @brief () ���Z�q�I�[�o�[���[�h
	 * 
	 * �s�N�Z�������H����.
	 *
	 * @param[in] texel ���H����s�N�Z���l.
	 * @return �Ȃ�.
	 */
	virtual void operator () ( unsigned char* texel ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/