/*******************************************************************************/
/**
 * @file BufferGL.h.
 * 
 * @brief OpenGL バッファクラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_BUFFERGL_H_
#define _NGL_OPENGL_BUFFERGL_H_

#include	"Ngl/IBuffer.h"
#include	"OpenGL.h"

namespace Ngl{


namespace OpenGL{


/**
 * @class BufferGL．
 * @brief OpenGL バッファクラス.
 */
class BufferGL : public IBuffer
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] desc バッファ作成記述子.
	 * @param[in] data バッファデータ.
	 */
	BufferGL( const BufferDesc& desc, const void* data=0 );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~BufferGL();

	
	/*=========================================================================*/
	/**
	 * @brief 記述子を取得する
	 * 
	 * @param[in] なし.
	 * @return バッファ記述子.
	 */
	const BufferDesc& desc() const;

	
	/*=========================================================================*/
	/**
	 * @brief バッファデータの設定
	 * 
	 * @param[in] data 設定するデータ.
	 * @return なし.
	 */
	void setData( const void* data );

	
	/*=========================================================================*/
	/**
	 * @brief バッファデータの取得
	 * 
	 * @param[out] data バッファデータを格納するデータ.
	 * @return なし.
	 */
	void getData( void* data ) const;

	
	/*=========================================================================*/
	/**
	 * @brief OepnGLバッファインデックスの取得
	 * 
	 * @param[out] なし.
	 * @return OpenGLバッファインデックス.
	 */
	GLuint buffer() const;

private:

	/*=========================================================================*/
	/**
	 * @brief バッファタイプを変換
	 * 
	 * @param[in] type 変換するバッファタイプ.
	 * @return 変換したOpenGLバッファタイプ.
	 */
	static GLenum toTarget( BufferType type );

	
	/*=========================================================================*/
	/**
	 * @brief バッファの使用方法を変換
	 * 
	 * @param[in] usage 変換するバッファの使用方法フラグ.
	 * @return 変換したOpenGLバッファ使用方法フラグ.
	 */
	static GLenum toUsage( BufferUsage usage );

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 */
	BufferGL( const BufferGL& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	BufferGL& operator = ( const BufferGL& other );

private:

	/** 記述子 */
	BufferDesc	desc_;

	/** バッファオブジェクト */
	GLuint		buffer_;

	/** ターゲット */
	GLenum		target_;

	/** 使用方法 */
	GLenum		usage_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/