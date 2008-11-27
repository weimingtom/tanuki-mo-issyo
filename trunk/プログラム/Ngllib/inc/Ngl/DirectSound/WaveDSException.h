/*******************************************************************************/
/**
 * @file WaveDSException.h.
 * 
 * @brief DirectSound WaveリソースDS例外クラス定義.
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
 * @brief WaveリソースDS例外クラス．
 */
class WaveDSException : public InputStreamException
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] msg エラーメッセージ.
	 */
	WaveDSException( const std::string& msg ) :
	  InputStreamException( msg )	// 標準例外クラス
	{}


	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 *
	 * "mes \n [file] : [line]"の形の文字列情報として情報を設定します。
	 * 
	 * @param[in] mes 例外情報文字列.
	 * @param[in] file 例外の発生したファイル名.
	 * @param[in] line 例外の発生した行数.
	 */
	WaveDSException( const std::string& mes, std::string file, int line ):
	  InputStreamException( mes, file, line )
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * "mes \n [className] : [methodName]"の形の文字列情報として情報を設定します。
	 *
	 * @param[in] mes 例外情報文字列.
	 * @param[in] className 例外の発生したクラス名.
	 * @param[in] methodName 例外の発生した関数名.
	 */
	WaveDSException( const std::string& mes, const std::string& className, const std::string& methodName ):
	 InputStreamException( mes, className, methodName )
	{}

};

} // namespace DirectSound

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/