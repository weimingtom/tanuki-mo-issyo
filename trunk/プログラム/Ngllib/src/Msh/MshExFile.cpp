/*******************************************************************************/
/**
 * @file MshExFile.cpp.
 * 
 * @brief Msh MshExメッシュファイルクラスソースファイル.
 *
 * @date 2008/11/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Msh/MshExFile.h"
#include	"Ngl/Msh/MshExCreator.h"
#include	"Ngl/Msh/SklCreator.h"
#include	"Ngl/Msh/AnmCreator.h"
#include	<Ngl/Exception.h>
#include	<Ngl/Utility.h>

using namespace Ngl;
using namespace Ngl::Msh;


/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] renderer レンダラー.
 * @param[in] textureCreator テクスチャ作成クラス.
 */
MshExFile::MshExFile( IRenderer* renderer, ITextureCreator* creator ):
	renderer_( renderer ),
	mshCreator_( 0 ),
	sklCreator_( 0 ),
	anmCreator_( 0 ),
	mesh_( 0 ),
	skeleton_( 0 ),
	animation_( 0 )
{
	mshCreator_ = new MshExCreator( renderer );
	mshCreator_->setTextureCreator( creator );

	sklCreator_ = new SklCreator();
	anmCreator_ = new AnmCreator();
}



/*=========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @warning 設定したクラスは、MshExFile内で削除されます.
 *
 * @param[in] renderer レンダラー.
 * @param[in] msh msh,mshex形式メッシュファイル作成クラス.
 * @param[in] skl skl形式スケルトンファイル作成クラス.
 * @param[in] anm anm形式アニメーションファイル作成クラス.
 */
MshExFile::MshExFile( IRenderer* renderer, MshExCreator* msh, SklCreator* skl, AnmCreator* anm ):
	renderer_( renderer ),
	mshCreator_( msh ),
	sklCreator_( skl ),
	anmCreator_( anm ),
	mesh_( 0 ),
	skeleton_( 0 ),
	animation_( 0 )
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
MshExFile::~MshExFile()
{
	delete mshCreator_;
	delete sklCreator_;
	delete anmCreator_;

	delete mesh_;
	delete skeleton_;
	delete animation_;
}



/*=========================================================================*/
/**
 * @brief ファイルから作成する
 *
 * @throw Ngl::InputStreamException& 入力例外.
 *
 * @warning メッシュファイルと同名のsklファイルと、anmファイルを読み込みます<br>
 *
 * @param[in] filename ファイル名( メッシュファイルの拡張子込み ).
 * @return なし.
 */
void MshExFile::createFromFile( const std::string& filename )
{
	try{
		// ドライブ名などを取得
		std::string drive = Ngl::Utility::getFilePathDrave( filename.c_str() );
		std::string path = Ngl::Utility::getFilePathDir( filename.c_str() );
		std::string fn = Ngl::Utility::getFileName( filename.c_str() );

		if( mshCreator_ != 0 ){
			// メッシュファイルを読み込む
			mesh_ = mshCreator_->createFromFile( filename );
		}

		if( sklCreator_ != 0 ){
			// スケルトンファイルを読み込む
			std::string sklfname = drive + path + fn + ".skl";
			skeleton_ = sklCreator_->createFromFile( sklfname );
		}

		if( anmCreator_ != 0 ){
			// アニメーションファイルを読み込む
			std::string anmfname = drive + path + fn + ".anm";
			animation_ = anmCreator_->createFromFile( anmfname );
		}
	}
	catch( InputStreamException& e ){
		throw e;
	}
}



/*=========================================================================*/
/**
 * @brief メッシュデータを取得
 * 
 * @warning 作成されていない場合は、0が返ります.
 *
 * @param[in] なし.
 * @return メッシュデータ.
 */
IMesh* MshExFile::getMesh()
{
	return mesh_;
}



/*=========================================================================*/
/**
 * @brief スケルトンデータを取得
 * 
 * @warning 作成されていない場合は、0が返ります.
 *
 * @param[in] なし.
 * @return スケルトンデータ.
 */
ISkeleton* MshExFile::getSkeleton()
{
	return skeleton_;
}



/*=========================================================================*/
/**
 * @brief アニメーションデータを取得
 * 
 * @warning 作成されていない場合は、0が返ります.
 *
 * @param[in] なし.
 * @return メッシュデータ.
 */
IAnimation* MshExFile::getAnimation()
{
	return animation_;
}



/*===== EOF ==================================================================*/