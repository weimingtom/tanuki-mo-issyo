/*******************************************************************************/
/**
 * @file XMLElement.cpp.
 * 
 * @brief XML�v�f�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLElement.h"

using namespace Ngl;
using namespace Ngl::XML;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] name �G�������g��.
 */
XMLElement::XMLElement( const char* name ):
	elementName_( name )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLElement::~XMLElement()
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
 * @brief �q�G�������g��ǉ�
 * 
 * @param[in] child �ǉ�����q�G�������g.
 * @return �Ȃ�.
 */
void XMLElement::addChild( XMLElement* child )
{
	elementContainer_.push_back( child );
}



/*=========================================================================*/
/**
 * @brief ������ǉ�
 * 
 * @param[in] name �ǉ����鑮����.
 * @param[in] attrib �ǉ����鑮���e�L�X�g.
 * @return �Ȃ�.
 */
void XMLElement::addAttribute( const char* name, const char* attrib )
{
	attribContainer_[ name ] = XMLText( attrib );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��ݒ�
 * 
 * @param[in] text �ݒ肷��e�L�X�g.
 * @return �Ȃ�.
 */
void XMLElement::setText( const char* text )
{
	value_.setText( text );
}


	
/*=========================================================================*/
/**
 * @brief �v�f�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �v�f��.
 */
const std::string& XMLElement::getElementName() const
{
	return elementName_;
}
	
	
	
/*=========================================================================*/
/**
 * @brief ���O����v�f���擾
 * 
 * @param[in] name �l���擾����v�f��.
 * @return �擾�����v�f.
 */
IXMLElement* XMLElement::getElementByName( const std::string& name )
{
	ElementContainer::iterator itor;
	for( itor=elementContainer_.begin(); itor!=elementContainer_.end(); ++itor ){
		if( (*itor)->getElementName() == name ){
			return *itor;
		}
	}
	return 0;
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X�ԍ�����v�f���擾
 * 
 * @param[in] index �l���擾����v�f��.
 * @return �擾�����v�f(�͈͊O�̏ꍇ��0���Ԃ�܂�).
 */
IXMLElement* XMLElement::getElementByIndex( int index )
{
	return elementContainer_[ index ];
}
	
	
	
/*=========================================================================*/
/**
 * @brief ���������瑮���̒l���擾
 * 
 * @param[in] name �l���擾���鑮����.
 * @return �擾�����l ���݂��Ȃ��ꍇ�͋󕶎����Ԃ�.
 */
const IXMLText& XMLElement::getAttribByName( const std::string& name )
{
	return attribContainer_[ name ];
}



/*=========================================================================*/
/**
 * @brief �l���擾
 *
 * @param[in] �Ȃ�.
 * @return �擾�����l.
 */
const IXMLText& XMLElement::getValue() const
{
	return value_;
}



/*=========================================================================*/
/**
 * @brief �q�v�f�������Ă��邩
 * 
 * @param[in] �Ȃ�.
 * @retval true �q�v�f�����݂���.
 * @retval false �q�v�f�����݂��Ȃ�.
 */
bool XMLElement::isExistChildElement() const
{
	return elementContainer_.empty();
}



/*=========================================================================*/
/**
 * @brief �����������Ă��邩
 * 
 * @param[in] �Ȃ�.
 * @retval true �����������Ă���.
 * @retval false �����������Ă��Ȃ�.
 */
bool XMLElement::isExistAttrib() const
{
	return attribContainer_.empty();
}



/*=========================================================================*/
/**
 * @brief �l�������Ă��邩
 * 
 * @param[in] �Ȃ�.
 * @retval true �l�������Ă���.
 * @retval false �l�������Ă��Ȃ�.
 */
bool XMLElement::isExistValue() const
{
	return value_.hasText();
}



/*=========================================================================*/
/**
 * @brief �q�v�f�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �q�v�f��.
 */
unsigned int XMLElement::childElementCount() const
{
	return static_cast< unsigned int >( elementContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief ���������擾
 * 
 * @param[in] �Ȃ�.
 * @return ������.
 */
unsigned int XMLElement::attribCount() const
{
	return static_cast< unsigned int >( attribContainer_.size() );
}



/*=========================================================================*/
/**
 * @brief [] ���Z�q�I�[�o�[���[�h
 * 
 * name�Ŏw�肵���q�v�f���擾����.
 * 
 * @param[in] name �擾����q�v�f��.
 * @return �擾�����q�v�f�N���X.
 */
IXMLElement* XMLElement::operator [] ( const std::string& name )
{
	return getElementByName( name );
}



/*=========================================================================*/
/**
 * @brief [] ���Z�q�I�[�o�[���[�h
 * 
 * name�Ŏw�肵���q�v�f���擾����.
 * 
 * @param[in] index �擾����v�f�C���f�b�N�X�ԍ�.
 * @return �擾�����q�v�f�N���X( �͈͊O�̏ꍇ��0���Ԃ�܂�).
 */
IXMLElement* XMLElement::operator [] ( int index )
{
	return getElementByIndex( index );
}


	
/*===== EOF ==================================================================*/