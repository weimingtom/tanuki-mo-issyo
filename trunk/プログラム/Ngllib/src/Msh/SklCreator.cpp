/*******************************************************************************/
/**
 * @file SklCreator.cpp.
 * 
 * @brief Msh skl�`���X�P���g���t�@�C���ǂݍ��݃N���X�\�[�X�t�@�C��.
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
 * @brief �t�@�C������쐬����
 * 
 * @param[in] fileName �t�@�C����.
 * @return �쐬�����X�P���g���N���X.
 */
ISkeleton* SklCreator::createFromFile( std::string fileName )
{
	// �X�P���g���t�@�C�����I�[�v������
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
 * @brief ���̓X�g���[������쐬����
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�����X�P���g���N���X.
 */
ISkeleton* SklCreator::createFromStream( IInputStream& stream )
{
	Skeleton* skl = 0;

	try{
		skl = new Skeleton();
		
		// �{�[���̐���ǂݍ���
		unsigned int numBones = 0;
		stream >> numBones;

		// �{�[�����̓ǂݍ���
		for( unsigned int i = 0; i<numBones; i++ ){
			// �{�[������ǂݍ���
			loadBone( stream, skl );
		}

		// �{�[���̊K�w�\����ݒ肷��
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
 * @brief �{�[����ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] skeleton �X�P���g��.
 * @return �Ȃ�.
 */
void SklCreator::loadBone( IInputStream& stream, Skeleton* skeleton )
{
	// �{�[�����쐬
	Bone* bone = new Bone();

	try{
		// �{�[��ID�̓ǂݍ���
		unsigned int boneID = 0;
		stream >> boneID;
	
		// �e�{�[��ID�̓ǂݍ���
		unsigned int parentBoneID = 0;
		stream >> parentBoneID;
	
		// �e����̑��΍��W�̓ǂݍ���
		Vector3 parentBoneOffset;
		stream >> Vector3Input( parentBoneOffset );
	
		// ���[�J�����W�ϊ��s��̓ǂݍ���
		Matrix4 matBoneOffset;
		stream >> Matrix4Input( matBoneOffset );

		// �{�[���ɏ���ݒ�
		bone->create( boneID, parentBoneID, parentBoneOffset, matBoneOffset );

		// �쐬�����{�[����ǉ�
		skeleton->addBone( bone );
	}
	catch( InputStreamException& e ){
		delete bone;
	
		e.add( "SklCreator", "loadBone" );
		throw e;
	}
}

	
	
/*===== EOF ==================================================================*/