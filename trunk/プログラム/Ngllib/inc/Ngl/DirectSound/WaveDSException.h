/*******************************************************************************/
/**
 * @file WaveDSException.h.
 * 
 * @brief DirectSound Wave���\�[�XDS��O�N���X��`.
 *
 * @date 2008/08/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTSOUND_WAVEDSEXCEPTION_H_
#define _NGL_DIRECTSOUND_WAVEDSEXCEPTION_H_

#include	"Ngl/Exception.h"

namespace Ngl{


namespace DirectSound{


/**
 * @class WaveDSException.
 * @brief Wave���\�[�XDS��O�N���X�D
 */
class WaveDSException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] msg �G���[���b�Z�[�W.
	 */
	WaveDSException( const std::string& msg ) :
	  InputStreamException( msg )	// �W����O�N���X
	{}


	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * "mes \n [file] : [line]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 * 
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] file ��O�̔��������t�@�C����.
	 * @param[in] line ��O�̔��������s��.
	 */
	WaveDSException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * "mes \n [className] : [methodName]"�̌`�̕�������Ƃ��ď���ݒ肵�܂��B
	 *
	 * @param[in] mes ��O��񕶎���.
	 * @param[in] className ��O�̔��������N���X��.
	 * @param[in] methodName ��O�̔��������֐���.
	 */
	WaveDSException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};

} // namespace DirectSound

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/