/*******************************************************************************/
/**
 * @file DefaultBMPPixel32Bit.h.
 * 
 * @brief BMP �f�t�H���g��32Bit�r�b�g�}�b�v�s�N�Z���N���X��`.
 *
 * @date 2008/07/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BMP_DEFAULTBMPPIXEL32BIT_H_
#define _NGL_BMP_DEFAULTBMPPIXEL32BIT_H_

#include	"IBMPPixel.h"
#include	"Ngl/Exception.h"

namespace Ngl{


namespace BMP{


/**
 * @class DefaultBMPPixel32Bit�D
 * @brief BMP �f�t�H���g��32Bit�r�b�g�}�b�v�s�N�Z���N���X.
 */
class DefaultBMPPixel32Bit : public IBMPPixel
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
			ifStream >> reinterpret_cast< char& >( texel[ 2 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 1 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 0 ] );
			ifStream >> reinterpret_cast< char& >( texel[ 3 ] );
		}
		catch( Ngl::InputStreamException& e ){
			e += "[DefaultBMPPixel32Bit] : [operator()]";
			throw e;
		}
	}

};

} // namespace BMP

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/