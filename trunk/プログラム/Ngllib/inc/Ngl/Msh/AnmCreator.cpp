/*******************************************************************************/
/**
 * @file AnmCreator.cpp.
 * 
 * @brief Msh anm�`���A�j���[�V�����t�@�C���쐬�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"AnmCreator.h"
#include	"Ngl/Animation.h"
#include	"Ngl/AnimationTake.h"
#include	"Ngl/KeyFrame.h"
#include	"Ngl/FileInputC.h"
#include	"Ngl/Manipulator.h"

using namespace Ngl;
using namespace Ngl::Msh;

/*=========================================================================*/
/**
 * @brief �t�@�C������쐬����
 * 
 * @param[in] fileName �t�@�C����.
 * @return �쐬�����A�j���[�V�����N���X.
 */
IAnimation* AnmCreator::createFromFile( std::string fileName )
{
	// �X�P���g���t�@�C�����I�[�v������
	FileInputC ifStream;
	try{
		ifStream.open( fileName );
	}
	catch( FileOpenException& e ){
		e.add( "AnmCreator", "createFormFile" );
		e.outputConsol();
	}
	
	return createFromStream( ifStream );
}



/*=========================================================================*/
/**
 * @brief ���̓X�g���[������쐬����
 * 
 * @param[in] stream ���̓X�g���[��.
 * @return �쐬�����A�j���[�V�����N���X.
 */
IAnimation* AnmCreator::createFromStream( IInputStream& stream )
{
	Animation* anm = 0;

	try{
		anm = new Animation;
		
		// �A�j���[�V�����e�C�N����ǂݍ���
		unsigned int animationTakeCount;
		stream >> animationTakeCount;

		// �A�j���[�V�����e�C�N���̓ǂݍ���
		for( unsigned int i = 0; i<animationTakeCount; i++ ){
			loadAnimationTake( stream, anm );
		}
	}
	catch( Ngl::InputStreamException& e ){
		delete anm;
		anm = 0;

		e.add( "AnmCreator", "createFromStream" );
		e.outputConsol();
	}

	return anm;
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V�����e�C�N��ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] animation �A�j���[�V����.
 * @return �Ȃ�.
 */
void AnmCreator::loadAnimationTake( IInputStream& stream, Animation* animation )
{
	AnimationTake* animationTake = new AnimationTake;

	try{
		// �L�[�t���[�����̓ǂݍ���
		unsigned int numKeyframes = 0;
		stream >> numKeyframes;
	
		// �L�[�t���[���z���ǂݍ���
		for( unsigned int i=0; i<numKeyframes; ++i ){
			loadKeyFrame( stream, animationTake );
		}

		// �쐬�����A�j���[�V�����e�C�N�f�[�^��ǉ�����
		animation->addAnimationTake( animationTake );
	}
	catch( InputStreamException& e ){
		delete animationTake;

		e.add( "AnmCreator", "loadAnimationTake" );
		e.outputConsol();
	}
}



/*=========================================================================*/
/**
 * @brief �L�[�t���[����ǂݍ���
 * 
 * @param[in] stream ���̓X�g���[��.
 * @param[in] animationTake �A�j���[�V�����e�C�N.
 * @return �Ȃ�.
 */
void AnmCreator::loadKeyFrame( IInputStream& stream, AnimationTake* animationTake )
{
	KeyFrame* keyframe = new KeyFrame;

	try{
		// �L�[�t���[������ǂݎ��
		unsigned int keyframeInfo = 0;
		stream >> hex >> keyframeInfo;

		// �g��k���L�[����ǂݎ��
		unsigned int numScaleKeys = 0;
		stream >> numScaleKeys;

		// ��]�L�[����ǂݎ��
		unsigned int numRotateKeys = 0;
		stream >> numRotateKeys;

		// ���s�ړ��L�[����ǂݎ��
		unsigned int numPositionKeys = 0;
		stream >> numPositionKeys;

		// �}�g���N�X�L�[����ǂݎ��
		unsigned int numMatrixKeys = 0;
		stream >> numMatrixKeys;

		// �g��k���L�[�̓ǂݍ���
		for( unsigned int i=0; i<numScaleKeys; i++ ){
			ScaleKey* key = new ScaleKey;
			stream >> key->frameTimer;
			stream >> Vector3Input( key->value );
			keyframe->addKey( key );
		}

		// ��]�L�[�̓ǂݍ���
		for( unsigned int i=0; i<numRotateKeys; i++ ){
			RotateKey* key = new RotateKey;
			stream >> key->frameTimer;
			stream >> QuaternionInput( key->value );
			keyframe->addKey( key );
		}

		// ���s�ړ��L�[�̓ǂݍ���
		for( unsigned int i=0; i<numPositionKeys; i++ ){
			PositionKey* key = new PositionKey;
			stream >> key->frameTimer;
			stream >> Vector3Input( key->value );
			keyframe->addKey( key );
		}

		// �쐬�����L�[�t���[����ǉ�
		animationTake->addKeyFrame( keyframe );
	}
	catch( InputStreamException& e ){
		delete keyframe;

		e += "[AnmCreator] : [loadKeyFrame]";
		e.outputConsol();
	}
}

	
	
/*===== EOF ==================================================================*/