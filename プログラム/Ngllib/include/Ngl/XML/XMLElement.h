/*******************************************************************************/
/**
 * @file XMLElement.h.
 * 
 * @brief XML�v�f�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/11/30.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XML_XMLELEMENT_H_
#define _NGL_XML_XMLELEMENT_H_

#include	"XMLText.h"
#include	"Ngl/IXMLElement.h"
#include	<string>
#include	<map>
#include	<vector>

namespace Ngl{


namespace XML{


/**
 * @class XMLElement�D
 * @brief XML�v�f�N���X.
 */
class XMLElement : public IXMLElement
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] name �G�������g��.
	 */
	XMLElement( const char* name );
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~XMLElement();


	/*=========================================================================*/
	/**
	 * @brief �q�G�������g��ǉ�
	 * 
	 * @param[in] child �ǉ�����q�G�������g.
	 * @return �Ȃ�.
	 */
	void addChild( XMLElement* child );
	
	
	/*=========================================================================*/
	/**
	 * @brief ������ǉ�
	 * 
	 * @param[in] name �ǉ����鑮����.
	 * @param[in] attrib �ǉ����鑮���e�L�X�g.
	 * @return �Ȃ�.
	 */
	void addAttribute( const char* name, const char* attrib );
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��ݒ�
	 * 
	 * @param[in] text �ݒ肷��e�L�X�g.
	 * @return �Ȃ�.
	 */
	void setText( const char* text );
	
	
	/*=========================================================================*/
	/**
	 * @brief �v�f�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �v�f��.
	 */
	virtual const std::string& getElementName() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���O����v�f���擾
	 * 
	 * @param[in] name �l���擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByName( const std::string& name );
	
	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�ԍ�����v�f���擾
	 * 
	 * @param[in] index �l���擾����v�f��.
	 * @return �擾�����v�f(�͈͊O�̏ꍇ��0���Ԃ�܂�).
	 */
	virtual IXMLElement* getElementByIndex( int index );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���������瑮���̒l���擾
	 * 
	 * @param[in] name �l���擾���鑮����.
	 * @return �擾�����l ���݂��Ȃ��ꍇ�͋󕶎����Ԃ�.
	 */
	virtual const IXMLText& getAttribByName( const std::string& name );

	
	/*=========================================================================*/
	/**
	 * @brief �l���擾
	 *
	 * @param[in] �Ȃ�.
	 * @return �擾�����l.
	 */
	virtual const IXMLText& getValue() const;

	
	/*=========================================================================*/
	/**
	 * @brief �q�v�f�������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �q�v�f�����݂���.
	 * @retval false �q�v�f�����݂��Ȃ�.
	 */
	virtual bool isExistChildElement() const;

	
	/*=========================================================================*/
	/**
	 * @brief �����������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����������Ă���.
	 * @retval false �����������Ă��Ȃ�.
	 */
	virtual bool isExistAttrib() const;

	
	/*=========================================================================*/
	/**
	 * @brief �l�������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �l�������Ă���.
	 * @retval false �l�������Ă��Ȃ�.
	 */
	virtual bool isExistValue() const;

	
	/*=========================================================================*/
	/**
	 * @brief �q�v�f�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �q�v�f��.
	 */
	virtual unsigned int childElementCount() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���������擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ������.
	 */
	virtual unsigned int attribCount() const;

	
	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 * 
	 * name�Ŏw�肵���q�v�f���擾����.
	 * 
	 * @param[in] name �擾����q�v�f��.
	 * @return �擾�����q�v�f�N���X.
	 */
	virtual IXMLElement* operator [] ( const std::string& name );


	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 * 
	 * name�Ŏw�肵���q�v�f���擾����.
	 * 
	 * @param[in] index �擾����v�f�C���f�b�N�X�ԍ�.
	 * @return �擾�����q�v�f�N���X( �͈͊O�̏ꍇ��0���Ԃ�܂�).
	 */
	virtual IXMLElement* operator [] ( int index );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	XMLElement( const XMLElement& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	XMLElement& operator = ( const XMLElement& other );

private:

	/** �v�f�R���e�i�^ */
	typedef std::vector< XMLElement* >			ElementContainer;

	/** �����R���e�i�^ */
	typedef std::map< std::string, XMLText >	AttribContainer;

private:

	/** �v�f�R���e�i */
	ElementContainer	elementContainer_;

	/** �����R���e�i */
	AttribContainer		attribContainer_;

	/** �v�f�� */
	std::string			elementName_;

	/** �l */
	Ngl::XML::XMLText	value_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/