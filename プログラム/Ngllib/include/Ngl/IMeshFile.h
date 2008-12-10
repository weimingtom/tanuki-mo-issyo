/*******************************************************************************/
/**
 * @file IMeshFile.h.
 * 
 * @brief ���b�V���t�@�C���C���^�[�t�F�[�X��`.
 *
 * @date 2008/11/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMESHFILE_H_
#define _NGL_IMESHFILE_H_

#include	<Ngl/IMesh.h>
#include	<Ngl/ISkeleton.h>
#include	<Ngl/IAnimation.h>


namespace Ngl{


/**
 * @interface IMeshFile�D
 * @brief ���b�V���t�@�C���C���^�[�t�F�[�X.
 */
class IMeshFile
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IMeshFile() {}


	/*=========================================================================*/
	/**
	 * @brief �t�@�C������쐬����
	 *
	 * @param[in] filename �t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void createFromFile( const std::string& filename ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ���b�V���f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return ���b�V���f�[�^.
	 */
	virtual IMesh* getMesh() = 0;


	/*=========================================================================*/
	/**
	 * @brief �X�P���g���f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return �X�P���g���f�[�^.
	 */
	virtual ISkeleton* getSkeleton() = 0;


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����f�[�^���擾
	 * 
	 * @warning �쐬����Ă��Ȃ��ꍇ�́A0���Ԃ�܂�.
	 *
	 * @param[in] �Ȃ�.
	 * @return ���b�V���f�[�^.
	 */
	virtual IAnimation* getAnimation() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/