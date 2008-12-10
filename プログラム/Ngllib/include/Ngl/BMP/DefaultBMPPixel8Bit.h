/*******************************************************************************/
/**
 * @file DefaultBMPPixel8Bit.h.
 * 
 * @brief BMP �f�t�H���g��8Bit�r�b�g�}�b�v�s�N�Z���N���X��`.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_DEFAULTBMPPIXEL8BIT_H_
#define _NGL_BMP_DEFAULTBMPPIXEL8BIT_H_

#include	"IBMPPixel.h"
#include	"Ngl/Exception.h"

namespace Ngl{


namespace BMP{


/**
 * @class DefaultBMPPixel8Bit�D
 * @brief BMP �f�t�H���g��8Bit�r�b�g�}�b�v�s�N�Z���N���X.
 */
class DefaultBMPPixel8Bit : public IBMPPixel
{

public:

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
	 * @throw Ngl::InputStreamException �ǂݍ��݃G���[.
	 */
	virtual void operator () ( BYTE* texel, IInputStream& ifStream, const BitMap& bmp, int x, int y )
	{
		try{
			// �s�N�Z���̐F�f�[�^���擾
			BYTE pixel = 0;
			ifStream.read( reinterpret_cast< char* >( &pixel ), sizeof( BYTE ) );

			texel[0] = bmp.rgbQuad[ pixel ].rgbRed;		// Red
			texel[1] = bmp.rgbQuad[ pixel ].rgbGreen;	// Green
			texel[2] = bmp.rgbQuad[ pixel ].rgbBlue;	// Blue
			texel[3] = 0xff;							// Alpha
		}
		catch( Ngl::InputStreamException& e ){
			e += "[DefaultBMPPixel8Bit] : [operator()]";
			throw e;
		}
	}

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/