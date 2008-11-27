/*******************************************************************************/
/**
 * @file Animation.h.
 * 
 * @brief �A�j���[�V�����f�[�^�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_ANIMATIONANM_H_
#define _NGL_MSH_ANIMATIONANM_H_

#include	"Ngl/IAnimation.h"
#include	"Ngl/IBoneframe.h"
#include	<vector>

namespace Ngl{


/**
 * @class Animation
 * @brief �A�j���[�V�����N���X�D
 */
class Animation : public IAnimation
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	Animation();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~Animation();


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����e�C�N�f�[�^��ǉ�����
	 * 
	 * @warning �ǉ������A�j���[�V�����e�C�N�f�[�^��Animation�N���X�ō폜����܂�.
	 *
	 * @param[in] animationTake �ǉ�����f�[�^.
	 * @return �I���^�C�}.
	 */
	void addAnimationTake( IBoneframe* animationTake );

public:
	
	/*=========================================================================*/
	/**
	 * @brief �w��̃L�[�t���[���f�[�^���擾����
	 * 
	 * @param[in] no �擾����f�[�^�ԍ�.
	 * @param[in] boneNo �擾����{�[���ԍ�.
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[���f�[�^.
	 * @return �L�[�t���[���f�[�^.
	 */
	KeyframeData& getKeyFrame( unsigned int no, unsigned int boneNo, float globalTime, KeyframeData& data );


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����̏I���^�C�}�𒲂ׂ�
	 * 
	 * @param[in] no �A�j���[�V�����i���o�[.
	 * @return �I���^�C�}.
	 */
	unsigned int getEndTimer( unsigned int no );


	/*=========================================================================*/
	/**
	 * @brief �w��̃A�j���[�V�����̃{�[�����𒲂ׂ�
	 * 
	 * @param[in] no �f�[�^�ԍ�.
	 * @return �{�[����.
	 */
	unsigned int getNumBones( unsigned int no );
	
private:
	
	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����f�[�^�̉��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();

	
	/*=========================================================================*/
	/**
	 * @brief �w��i���o�[���{�[���t���[���f�[�^�������傫����
	 * 
	 * @param[in] boneframeNo �{�[���t���[���ԍ�.
	 * @retval true �傫��.
	 * @retval false ������.
	 */
	bool isOutOfRange( unsigned int boneframeNo );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^( �R�s�[�֎~ �j
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 * @return �Ȃ�.
	 */
	Animation( const Animation& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h�i �R�s�[�֎~ �j
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	Animation& operator = ( const Animation& other );

private:

	/** �A�j���[�V�����e�C�N�z��^ */
	typedef std::vector< IBoneframe* >	AnimationTakeArray;

private:

	/** �A�j���[�V�����e�C�N�z�� */
	AnimationTakeArray	animationTakeArray_;

};

} // namesapce Msh

#endif

/*===== EOF ==================================================================*/