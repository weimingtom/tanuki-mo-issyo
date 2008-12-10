/*******************************************************************************/
/**
 * @file MshExFile.cpp.
 * 
 * @brief Msh MshEx���b�V���t�@�C���N���X�\�[�X�t�@�C��.
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
 * @brief �R���X�g���N�^
 * 
 * @param[in] renderer �����_���[.
 * @param[in] textureCreator �e�N�X�`���쐬�N���X.
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
 * @brief �R���X�g���N�^
 * 
 * @warning �ݒ肵���N���X�́AMshExFile���ō폜����܂�.
 *
 * @param[in] renderer �����_���[.
 * @param[in] msh msh,mshex�`�����b�V���t�@�C���쐬�N���X.
 * @param[in] skl skl�`���X�P���g���t�@�C���쐬�N���X.
 * @param[in] anm anm�`���A�j���[�V�����t�@�C���쐬�N���X.
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
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
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
 * @brief �t�@�C������쐬����
 *
 * @throw Ngl::InputStreamException& ���͗�O.
 *
 * @warning ���b�V���t�@�C���Ɠ�����skl�t�@�C���ƁAanm�t�@�C����ǂݍ��݂܂�<br>
 *
 * @param[in] filename �t�@�C����( ���b�V���t�@�C���̊g���q���� ).
 * @return �Ȃ�.
 */
void MshExFile::createFromFile( const std::string& filename )
{
	try{
		// �h���C�u���Ȃǂ��擾
		std::string drive = Ngl::Utility::getFilePathDrave( filename.c_str() );
		std::string path = Ngl::Utility::getFilePathDir( filename.c_str() );
		std::string fn = Ngl::Utility::getFileName( filename.c_str() );

		if( mshCreator_ != 0 ){
			// ���b�V���t�@�C����ǂݍ���
			mesh_ = mshCreator_->createFromFile( filename );
		}

		if( sklCreator_ != 0 ){
			// �X�P���g���t�@�C����ǂݍ���
			std::string sklfname = drive + path + fn + ".skl";
			skeleton_ = sklCreator_->createFromFile( sklfname );
		}

		if( anmCreator_ != 0 ){
			// �A�j���[�V�����t�@�C����ǂݍ���
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
 * @brief ���b�V���f�[�^���擾
 * 
 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
 *
 * @param[in] �Ȃ�.
 * @return ���b�V���f�[�^.
 */
IMesh* MshExFile::getMesh()
{
	return mesh_;
}



/*=========================================================================*/
/**
 * @brief �X�P���g���f�[�^���擾
 * 
 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
 *
 * @param[in] �Ȃ�.
 * @return �X�P���g���f�[�^.
 */
ISkeleton* MshExFile::getSkeleton()
{
	return skeleton_;
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V�����f�[�^���擾
 * 
 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
 *
 * @param[in] �Ȃ�.
 * @return ���b�V���f�[�^.
 */
IAnimation* MshExFile::getAnimation()
{
	return animation_;
}



/*===== EOF ==================================================================*/