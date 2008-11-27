/*******************************************************************************/
/**
 * @file IXMLFile.h.
 * 
 * @brief XML�t�@�C���C���^�[�t�F�[�X.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLFILE_H_
#define _NGL_IXMLFILE_H_

#include	"IXMLElement.h"
#include	<string>

namespace Ngl{


/**
 * @class IXMLFile�D
 * @brief XML�t�@�C���C���^�[�t�F�[�X.
 */
class IXMLFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IXMLFile() {}


	/*=========================================================================*/
	/**
	 * @brief ���O����v�f���擾
	 * 
	 * @param[in] name �擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByName( const std::string name ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�ԍ�����v�f���擾
	 * 
	 * @param[in] index �擾����v�f�̃C���f�b�N�X�ԍ�.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByIndex( unsigned int index ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �擾�����v�f��.
	 */
	virtual unsigned int elementCount() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 *
	 * name�Ŏw�肵���v�f���擾����.
	 * 
	 * @param[in] name �擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* operator [] ( const std::string name ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/