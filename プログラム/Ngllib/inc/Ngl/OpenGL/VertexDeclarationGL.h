/*******************************************************************************/
/**
 * @file VertexDeclarationGL.h.
 * 
 * @brief OpenGL 頂点宣言データクラスヘッダファイル.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_VERTEXDECLARATIONGL_H_
#define _NGL_OPENGL_VERTEXDECLARATIONGL_H_

#include	"Ngl/IVertexDeclaration.h"
#include	"Ngl/VertexStreamDesc.h"
#include	"OpenGL.h"
#include	<vector>

namespace Ngl{


namespace OpenGL{


/**
 * @class VertexDeclarationGL.
 * @brief OpenGL 頂点宣言データクラス.
 */
class VertexDeclarationGL : public IVertexDeclaration
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] desc 頂点宣言データ記述子の配列.
	 * @param[in] numDesc 頂点宣言データ記述子配列の要素数.
	 */
	VertexDeclarationGL( const VertexDeclarationDesc desc[], unsigned int numDesc );

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~VertexDeclarationGL();


	/*=========================================================================*/
	/**
	 * @brief 頂点宣言データの個数を取得
	 * 
	 * @param[in] なし.
	 * @return 個数.
	 */
	virtual unsigned int size() const;

	
	/*=========================================================================*/
	/**
	 * @brief 記述子を取得
	 * 
	 * @param[in] index 取得する記述子のインデックス番号.
	 * @return 記述子.
	 */
	virtual const VertexDeclarationDesc& desc( unsigned int index ) const;

	
	/*=========================================================================*/
	/**
	 * @brief 頂点バッファストリームの設定
	 * 
	 * @param[in] streams 設定する頂点ストリーム記述子配列.
	 * @param[in] start 設定開始配列位置.
	 * @return なし.
	 */
	void setVertexStream( const VertexStreamDesc streams[], unsigned int start=0 );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点バッファストリームのリセット
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void resetVertexStream();

private:

	/**
	 * @struct VertexFormat.
	 * @brief OpenGL 頂点フォーマット構造体.
	 */
	struct VertexFormat
	{
		GLuint		type;		/**< 頂点タイプ			*/
		GLint		size;		/**< 頂点データサイズ	*/
		GLboolean	normalized;	/**< 正規化データか		*/
	};

	/**
	 * @struct Element.
	 * @brief OpenGL 頂点宣言要素構造体.
	 */
	struct Element
	{
		GLuint			attrib;	/**< 属性			*/
		VertexFormat	format;	/**< フォーマット	*/
		GLuint			offset;	/**< オフセット値	*/
		unsigned int	stream;	/**< ストリーム番号	*/
	};

private:

	/*=========================================================================*/
	/**
	 * @brief 頂点バッファの設定
	 * 
	 * @param[in] element 頂点宣言要素構造体.
	 * @param[in] stream 頂点ストリーム記述子.
	 * @param[in] start 開始位置.
	 * @return なし.
	 */
	void setVertexBuffer( const Element& element, const VertexStreamDesc& stream, unsigned int start );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点宣言記述子を変換
	 * 
	 * @param[in] desc 変換する頂点宣言記述子構造体.
	 * @return 変換後の頂点宣言要素構造体.
	 */
	static Element toElement( const VertexDeclarationDesc& desc );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点セマンティックを変換
	 * 
	 * @param[in] semantic 変換する頂点セマンティックフラグ.
	 * @return 変換後のOpenGL頂点セマンティック.
	 */
	static GLuint toAttrib( VertexSemantic semantic );

	
	/*=========================================================================*/
	/**
	 * @brief 頂点タイプを変換
	 * 
	 * @param[in] type 変換する頂点タイプフラグ.
	 * @return 変換後の頂点フォーマット構造体.
	 */
	static const VertexFormat& toVertexFormat( VertexType type );

private:

	/** 記述子配列型 */
	typedef std::vector< VertexDeclarationDesc >	VertexDeclarationDescArray;

	/** 頂点レイアウト配列型 */
	typedef std::vector< Element >					VertexDeclarationArray;

private:

	/** 記述子配列 */
	VertexDeclarationDescArray	desc_;

	/** 頂点レイアウト配列 */
	VertexDeclarationArray		elements_;
};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/