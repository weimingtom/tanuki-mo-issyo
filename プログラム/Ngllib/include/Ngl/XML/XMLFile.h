/*******************************************************************************/
/**
 * @file XMLFile.h.
 * 
 * @brief XML�t�@�C���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XML_XMLFILE_H_
#define _NGL_XML_XMLFILE_H_

#include	"Ngl/IXMLFile.h"
#include	<vector>

namespace Ngl{


namespace XML{


// XML�v�f�N���X
class XMLElement;

/**
 * @class XMLFile�D
 * @brief XML�t�@�C���N���X.
 */
class XMLFile : public IXMLFile
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	XMLFile();

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~XMLFile();


	/*=========================================================================*/
	/**
	 * @brief �擪�̃G�������g��ǉ�
	 * 
	 * @param[in] elm �ǉ�����G�������g.
	 * @return �Ȃ�.
	 */
	void addElement( XMLElement* elm );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���O����v�f���擾
	 * 
	 * @param[in] name �擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByName( const std::string name );

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�ԍ�����v�f���擾
	 * 
	 * @param[in] index �擾����v�f�̃C���f�b�N�X�ԍ�.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByIndex( unsigned int index );

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �擾�����v�f��.
	 */
	virtual unsigned int elementCount();

	
	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 *
	 * name�Ŏw�肵���v�f���擾����.
	 * 
	 * @param[in] name �擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* operator [] ( const std::string name );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	XMLFile( const XMLFile& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	XMLFile& operator = ( const XMLFile& other );

private:

	/** �v�f�R���e�i�^ */
	typedef std::vector< XMLElement* >	ElementContainer;

private:

	/** �G�������g�R���e�i */
	ElementContainer	elementContainer_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/