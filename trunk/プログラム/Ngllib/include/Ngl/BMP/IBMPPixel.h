/*******************************************************************************/
/**
 * @file IBMPPixel.h.
 * 
 * @brief BMP �s�N�Z���f�[�^�N���X�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/*******************************************************************************/
#ifndef _NGL_BMP_IBMPPIXEL_H_
#define _NGL_BMP_IBMPPIXEL_H_

#include	"BitMap.h"
#include	"Ngl/IInputStream.h"
#include	<fstream>

namespace Ngl{


namespace BMP{

/**
 * @interface IBMPPixel�D
 * @brief BMP �s�N�Z���f�[�^�N���X�C���^�[�t�F�[�X.
 */
class IBMPPixel
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IBMPPixel() {}


	/*=========================================================================*/
	/**
	 * @brief () ���Z�q�I�[�o�[���[�h
	 *
	 * �s�N�Z���f�[�^��ǂݍ���.
	 * 
	 * @param[out] texel �f�[�^��ݒ肷��e�N�Z���f�[�^.
	 * @param[in] ifStream ���̓X�g���[��.
	 * @param[in] bmp �r�b�g�}�b�v�\����.
	 * @param[in] x �ǂݍ��ރs�N�Z���̐����ʒu.
	 * @param[in] y �ǂݍ��ރs�N�Z���̐����ʒu.
	 * @retval �Ȃ�.
	 * @throw std::ios::failure �ǂݍ��݃G���[.
	 */
	virtual void operator () ( BYTE* texel, IInputStream& ifStream, const BitMap& bmp, int x, int y ) = 0;

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/