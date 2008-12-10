/*******************************************************************************/
/**
 * @file XMLFile.cpp.
 * 
 * @brief XML�t�@�C���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLFile.h"
#include	"Ngl/XML/XMLElement.h"

using namespace Ngl;
using namespace Ngl::XML;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLFile::XMLFile()
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLFile::~XMLFile()
{
	// �v�f��S�폜
	ElementContainer::iterator itor = elementContainer_.begin();
	while( itor != elementContainer_.end() ){
		delete *itor;
		itor = elementContainer_.erase( itor );
	}
}



/*=========================================================================*/
/**
 * @brief �擪�̃G�������g��ǉ�
 * 
 * @param[in] elm �ǉ�����G�������g.
 * @return �Ȃ�.
 */
void XMLFile::addElement( XMLElement* elm )
{
	elementContainer_.push_back( elm );
}



/*=========================================================================*/
/**
 * @brief ���O����v�f���擾
 * 
 * @param[in] name �擾����v�f��.
 * @return �擾�����v�f.
 */
IXMLElement* XMLFile::getElementByName( const std::string name )
{
	ElementContainer::iterator itor;
	for( itor=elementContainer_.begin(); itor!=elementContainer_.end(); ++itor ){
		if( (*itor)->getElementName() == name ){
			return *itor;
		}
	}

	// ������Ȃ�����
	return 0;
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�ԍ�����v�f���擾
 * 
 * @param[in] index �擾����v�f�̃C���f�b�N�X�ԍ�.
 * @return �擾�����v�f.
 */
IXMLElement* XMLFile::getElementByIndex( unsigned int index )
{
	return elementContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief �v�f�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �擾�����v�f��.
 */
unsigned int XMLFile::elementCount()
{
	return static_cast<unsigned int>( elementContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief [] ���Z�q�I�[�o�[���[�h
 *
 * name�Ŏw�肵���v�f���擾����.
 * 
 * @param[in] name �擾����v�f��.
 * @return �擾�����v�f.
 */
IXMLElement* XMLFile::operator [] ( const std::string name )
{
	return getElementByName( name );
}



/*===== EOF ==================================================================*/