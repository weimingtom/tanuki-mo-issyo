/*******************************************************************************/
/**
 * @file MshExFile.h.
 * 
 * @brief Msh MshEx���b�V���t�@�C���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/11/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_MSHEXFILE_H_
#define _NGL_MSH_MSHEXFILE_H_

#include	<Ngl/IMeshFile.h>
#include	<Ngl/IRenderer.h>
#include	<string>


namespace Ngl{


// �e�N�X�`���쐬�N���X
class ITextureCreator;


namespace Msh{


// msh,mshex�`�����b�V���t�@�C���쐬�N���X
class MshExCreator;

// skl�`���X�P���g���t�@�C���쐬�N���X
class SklCreator;

// anm�`���A�j���[�V�����t�@�C���쐬�N���X
class AnmCreator;


/**
 * @class MshExFile�D
 * @brief Msh MshEx���b�V���t�@�C���N���X.
 */
class MshExFile : public IMeshFile
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] renderer �����_���[.
	 * @param[in] textureCreator �e�N�X�`���쐬�N���X.
	 */
	MshExFile( IRenderer* renderer, ITextureCreator* creator );


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
	MshExFile( IRenderer* renderer, MshExCreator* msh, SklCreator* skl=0, AnmCreator* anm=0 );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	 ~MshExFile();

public:

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
	virtual void createFromFile( const std::string& filename );


	/*=========================================================================*/
	/**
	 * @brief ���b�V���f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return ���b�V���f�[�^.
	 */
	virtual IMesh* getMesh();


	/*=========================================================================*/
	/**
	 * @brief �X�P���g���f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return �X�P���g���f�[�^.
	 */
	virtual ISkeleton* getSkeleton();


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return ���b�V���f�[�^.
	 */
	virtual IAnimation* getAnimation();

protected:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ )
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	MshExFile( const MshExFile& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	MshExFile& operator = ( const MshExFile& other );

private:

	/** �����_���[ */
	IRenderer*		renderer_;
	
	/** ���b�V���쐬�N���X */
	MshExCreator*	mshCreator_;

	/** �X�P���g���쐬�N���X */
	SklCreator*		sklCreator_;

	/** �A�j���[�V�����쐬�N���X */
	AnmCreator*		anmCreator_;

	/** ���b�V���f�[�^ */
	IMesh*			mesh_;

	/** �X�P���g���f�[�^ */
	ISkeleton*		skeleton_;

	/** �A�j���[�V�����f�[�^ */
	IAnimation*		animation_;
	
};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/