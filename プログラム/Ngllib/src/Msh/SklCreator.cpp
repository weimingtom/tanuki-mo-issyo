/*******************************************************************************/
/**
 * @file SklCreator.cpp.
 * 
 * @brief Msh skl形式スケルトンファイル読み込みクラスソースファイル.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Msh/SklCreator.h"
#include	"Ngl/Skeleton.h"
#include	"Ngl/Bone.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"

using namespace Ngl;
using namespace Ngl::Msh;

/*=========================================================================*/
/**
 * @brief ファイルから作成する
 * 
 * @param[in] fileName ファイル名.
 * @return 作成したスケルトンクラス.
 */
ISkeleton* SklCreator::createFromFile( std::string fileName )
{
	// スケルトンファイルをオープンする
	FileInputC ifStream;
	try{
		ifStream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "SklCreator", "createFormFile" );
		e.outputConsol();
	}
	
	return createFromStream( ifStream );
}



/*=========================================================================*/
/**
 * @brief 入力ストリームから作成する
 * 
 * @param[in] stream 入力ストリーム.
 * @return 作成したスケルトンクラス.
 */
ISkeleton* SklCreator::createFromStream( IInputStream& stream )
{
	Skeleton* skl = 0;

	try{
		skl = new Skeleton();
		
		// ボーンの数を読み込む
		unsigned int numBones = 0;
		stream >> numBones;

		// ボーン情報の読み込み
		for( unsigned int i = 0; i<numBones; i++ ){
			// ボーン情報を読み込む
			loadBone( stream, skl );
		}

		// ボーンの階層構造を設定する
		skl->linkBone();
	}
	catch( Ngl::InputStreamException& e ){
		delete skl;
		skl = 0;

		e.add( "SklCreator", "createFromStream" );
		e.outputConsol();
	}

	return skl;
}



/*=========================================================================*/
/**
 * @brief ボーンを読み込む
 * 
 * @param[in] stream 入力ストリーム.
 * @param[in] skeleton スケルトン.
 * @return なし.
 */
void SklCreator::loadBone( IInputStream& stream, Skeleton* skeleton )
{
	// ボーンを作成
	Bone* bone = new Bone();

	try{
		// ボーンIDの読み込み
		unsigned int boneID = 0;
		stream >> boneID;
	
		// 親ボーンIDの読み込み
		unsigned int parentBoneID = 0;
		stream >> parentBoneID;
	
		// 親からの相対座標の読み込み
		Vector3 parentBoneOffset;
		stream >> Vector3Input( parentBoneOffset );
	
		// ローカル座標変換行列の読み込み
		Matrix4 matBoneOffset;
		stream >> Matrix4Input( matBoneOffset );

		// ボーンに情報を設定
		bone->create( boneID, parentBoneID, parentBoneOffset, matBoneOffset );

		// 作成したボーンを追加
		skeleton->addBone( bone );
	}
	catch( InputStreamException& e ){
		delete bone;
	
		e.add( "SklCreator", "loadBone" );
		throw e;
	}
}

	
	
/*===== EOF ==================================================================*/