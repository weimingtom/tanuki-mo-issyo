/*******************************************************************************/
/**
 * @file IMeshCreator.h.
 * 
 * @brief ���b�V���쐬�҃C���^�[�t�F�[�X��`.
 *
 * @date 2008/10/14.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMESHCREATOR_H_
#define _NGL_IMESHCREATOR_H_

#include	"Ngl/IMesh.h"
#include	"Ngl/ITextureCreator.h"

namespace Ngl{


/**
 * @class IMeshCreator�D
 * @brief ���b�V���쐬�҃C���^�[�t�F�[�X.
 */
class IMeshCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IMeshCreator() {}


	/*=========================================================================*/
	/**
	 * @brief �t�@�C������쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�������b�V���N���X.
	 */
	virtual IMesh* createFromFile( std::string fileName ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������쐬����
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�������b�V���N���X.
	 */
	virtual IMesh* createFromStream( IInputStream& stream ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/