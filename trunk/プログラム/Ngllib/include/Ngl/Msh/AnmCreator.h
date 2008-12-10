/*******************************************************************************/
/**
 * @file AnmCreator.h.
 * 
 * @brief Msh anm�`���A�j���[�V�����t�@�C���ǂݍ��݃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_ANMCREATOR_H_
#define _NGL_MSH_ANMCREATOR_H_

#include	"Ngl/IAnimation.h"
#include	"Ngl/IInputStream.h"
#include	<string>

namespace Ngl{

// �A�j���[�V����
class Animation;

// �A�j���[�V�����e�C�N
class AnimationTake;


namespace Msh{


/**
 * @class AnmCreator�D
 * @brief Msh anm�`���A�j���[�V�����t�@�C���ǂݍ��݃N���X.
 */
class AnmCreator
{

public:
	
	/*=========================================================================*/
	/**
	 * @brief �t�@�C������쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�����A�j���[�V�����N���X.
	 */
	IAnimation* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������쐬����
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�����A�j���[�V�����N���X.
	 */
	IAnimation* createFromStream( IInputStream& stream );

private:

	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����e�C�N��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] animation �A�j���[�V����.
	 * @return �Ȃ�.
	 */
	void loadAnimationTake( IInputStream& stream, Animation* animation );


	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[����ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] animationTake �A�j���[�V�����e�C�N.
	 * @return �Ȃ�.
	 */
	void loadKeyFrame( IInputStream& stream, AnimationTake* animationTake );

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/