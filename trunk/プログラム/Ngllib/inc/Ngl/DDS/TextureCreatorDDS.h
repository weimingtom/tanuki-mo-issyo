/*******************************************************************************/
/**
 * @file TextureCreatorDDS.h.
 * 
 * @brief DDS テクスチャ作成クラスヘッダファイル.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DDS_TEXTURECREATORDDS_H_
#define _NGL_DDS_TEXTURECREATORDDS_H_

#include	"Ngl/ITextureCreator.h"
#include	"DDSFile.h"
#include	<string>

namespace Ngl{


namespace DDS{


/**
 * @class TextureCreatorDDS．
 * @brief DDS テクスチャ作成クラス.
 */
class TextureCreatorDDS : public ITextureCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 */
	TextureCreatorDDS( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~TextureCreatorDDS();


	/*=========================================================================*/
	/**
	 * @brief テクスチャを作成
	 * 
	 * @param[in] fileName ファイル名.
	 * @return 作成したテクスチャのポインタ.
	 */
	virtual ITexture* create( const std::string& fileName );


	/*=========================================================================*/
	/**
	 * @brief レンダラーを設定
	 * 
	 * @param[in] renderer レンダラークラスのポインタ.
	 * @return なし.
	 */
	virtual void setRenderer( IRenderer* renderer );


	/*=========================================================================*/
	/**
	 * @brief 作成できるファイル拡張子名を取得
	 * 
	 * @warning "."を含まず、全てアルファベット小文字の拡張子名を返す.
	 *
	 * @param[in] なし.
	 * @return 拡張子名( "dds" ).
	 */
	virtual std::string extension();


	/*=========================================================================*/
	/**
	 * @brief テクスチャフィルタを設定する
	 * 
	 * @warning 設定したインスタンスの削除は行いません.
	 *
	 * @param[in] filter 設定するフィルタ.
	 * @return なし.
	 */
	virtual void setFilter( ITextureFilter* filter );

private:

	/*=========================================================================*/
	/**
	 * @brief テクスチャフォーマットに変換
	 * 
	 * @param[in] ddpf DDSピクセルフォーマット構造体の参照.
	 * @return 変換したテクスチャフォーマット.
	 */
	TextureFormat toTextureFormat( const DDSFile::PixelFormat& ddpf );

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャタイプに変換
	 * 
	 * @param[in] caps DDS補助フラグ構造体の参照.
	 * @return 変換したテクスチャタイプ.
	 */
	TextureType toTextureType( const DDSFile::Caps2& caps );

	
	/*=========================================================================*/
	/**
	 * @brief テクスチャ記述子に変換
	 * 
	 * @param[in] descDDS DDSサーフェース記述子の参照.
	 * @return 変換したテクスチャ記述子.
	 */
	TextureDesc toTextureDesc( const DDSFile::SurfaceDesc& descDDS );

private:

	/** レンダラークラス */
	IRenderer*		renderer_;

	/** DDSファイルクラスのポインタ */
	DDSFile*		dds_;

	/** テクスチャフィルタ */
	ITextureFilter*	filter_;

	/** テクスチャファイル名 */
	std::string		fileName_;

};

} // namespace DDS

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/