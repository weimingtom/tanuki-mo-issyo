/*******************************************************************************/
/**
 * @file SklCreator.h.
 * 
 * @brief Msh skl�`���X�P���g���t�@�C���ǂݍ��݃N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_SKLCREATOR_H_
#define _NGL_MSH_SKLCREATOR_H_

#include	"Ngl/ISkeleton.h"
#include	"Ngl/IInputStream.h"
#include	<string>

namespace Ngl{

// �X�P���g��
class Skeleton;

namespace Msh{


/**
 * @class SklCreator�D
 * @brief skl�`���X�P���g���t�@�C���ǂݍ��݃N���X.
 */
class SklCreator
{

public:
	
	/*=========================================================================*/
	/**
	 * @brief �t�@�C������쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�����X�P���g���N���X.
	 */
	ISkeleton* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������쐬����
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�����X�P���g���N���X.
	 */
	ISkeleton* createFromStream( IInputStream& stream );

private:

	/*=========================================================================*/
	/**
	 * @brief �{�[����ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] skeleton �X�P���g��.
	 * @return �Ȃ�.
	 */
	void loadBone( IInputStream& stream, Skeleton* skeleton );

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/