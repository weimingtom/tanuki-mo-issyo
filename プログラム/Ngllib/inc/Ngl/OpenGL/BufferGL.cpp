/*******************************************************************************/
/**
 * @file BufferGL.cpp.
 * 
 * @brief OpenGL バッファクラスソースファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"BufferGL.h"
#include	<memory>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] desc バッファ作成記述子.
 * @param[in] data バッファデータ.
 */
BufferGL::BufferGL( const BufferDesc& desc, const void* data ):
	desc_( desc ),
	target_( toTarget( desc.type ) ),
	usage_( toUsage( desc.usage ) )
{
	// バッファの作成
	glGenBuffersARB( 1, &buffer_ );
	glBindBufferARB( target_, buffer_ );
	glBufferDataARB( target_, desc_.size, data, usage_ );
	glBindBufferARB( target_, 0 );
}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
BufferGL::~BufferGL()
{
	// バッファを削除
	glDeleteBuffersARB( 1, &buffer_ );
}



/*=========================================================================*/
/**
 * @brief 記述子を取得する
 * 
 * @param[in] なし.
 * @return バッファ記述子.
 */
const BufferDesc& BufferGL::desc() const
{
	return desc_;
}



/*=========================================================================*/
/**
 * @brief バッファデータの設定
 * 
 * @param[in] data 設定するデータ.
 * @return なし.
 */
void BufferGL::setData( const void* data )
{
	glBindBufferARB( target_, buffer_ );
	void* buf = glMapBufferARB( target_, GL_WRITE_ONLY_ARB );
	std::memcpy( buf, data, desc_.size );
	glUnmapBufferARB( target_ );
	glBindBufferARB( target_, 0 );
}



/*=========================================================================*/
/**
 * @brief バッファデータの取得
 * 
 * @param[out] data バッファデータを格納するデータ.
 * @return なし.
 */
void BufferGL::getData( void* data ) const
{
	glBindBufferARB( target_, buffer_ );
	void* buf = glMapBufferARB( target_, GL_READ_ONLY_ARB );
	std::memcpy( data, buf, desc_.size );
	glUnmapBufferARB( target_ );
	glBindBufferARB( target_ , 0 );
}



/*=========================================================================*/
/**
 * @brief OepnGLバッファインデックスの取得
 * 
 * @param[in] なし.
 * @return OpenGLバッファインデックス.
 */
GLuint BufferGL::buffer() const
{
	return buffer_;
}



/*=========================================================================*/
/**
 * @brief バッファタイプを変換
 * 
 * @param[in] 変換するバッファタイプ.
 * @return 変換したOpenGLバッファタイプ.
 */
GLenum BufferGL::toTarget( BufferType type )
{
	static const GLenum targets[] = {
		GL_ARRAY_BUFFER_ARB,		// BUFFER_TYPE_VERTEX	= 0
		GL_ELEMENT_ARRAY_BUFFER_ARB	// BUFFER_TYPE_INDEX	= 1
	};

	return targets[ type ];
}



/*=========================================================================*/
/**
 * @brief バッファの使用方法を変換
 * 
 * @param[out] usage 変換するバッファの使用方法フラグ.
 * @return 変換したOpenGLバッファ使用方法フラグ.
 */
GLenum BufferGL::toUsage( BufferUsage usage )
{
	static const GLenum usages[] = {
		GL_STREAM_DRAW,		// BUFFER_USAGE_DEFAULT		= 0
		GL_STATIC_DRAW,		// BUFFER_USAGE_IMMUTABLE	= 1
		GL_DYNAMIC_DRAW		// BUFFER_USAGE_DYNAMIC		= 2
	};

	return usages[ usage ];
}



/*===== EOF ==================================================================*/