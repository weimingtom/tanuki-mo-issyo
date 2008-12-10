/*******************************************************************************/
/**
 * @file XMLDomParserTinyXML.h.
 * 
 * @brief TinyXML DOM����XML�p�[�T�N���X�w�b�_�t�@�C��.
 *
 * @date 2007/12/03.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_TINYXML_XMLDOMPARSERTINYXML_H_
#define _NGL_TINYXML_XMLDOMPARSERTINYXML_H_

#include	"Ngl/XML/XMLFile.h"
#include	"Ngl/XML/XMLElement.h"

// TinyXML �h�L�������g�N���X
class TiXmlDocument;

// TinyXML �G�������g�N���X
class TiXmlElement;


namespace Ngl{


namespace TinyXML{


/**
 * @class XMLDomParserTinyXML�D
 * @brief TinyXML DOM����XML�p�[�T�N���X.
 */
class XMLDomParserTinyXML
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	XMLDomParserTinyXML();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~XMLDomParserTinyXML();


	/*=========================================================================*/
	/**
	 * @brief �t�@�C������f�[�^��ǂݍ���
	 * 
	 * @param[in] name �t�@�C����.
	 * @param[out] file �f�[�^��ǂݍ���XMLFile�N���X.
	 * @return �Ȃ�.
	 */
	void load( const std::string& name, Ngl::XML::XMLFile& file );

private:

	/*=========================================================================*/
	/**
	 * @brief �v�f���쐬
	 * 
	 * @param[in] elm �쐬�����v�f��ǉ�����v�f( �e�v�f ).
	 * @param[out] source �f�[�^��ǂݍ���TinyXML�v�f�N���X.
	 * @return �Ȃ�.
	 */
	void createElement( Ngl::XML::XMLElement* elm, TiXmlElement* source );

	
	/*=========================================================================*/
	/**
	 * @brief �������쐬
	 * 
	 * @param[in] elm �쐬����������ǉ�����v�f.
	 * @param[out] source �f�[�^��ǂݍ���TinyXML�v�f�N���X.
	 * @return �Ȃ�.
	 */
	void createAttribute( Ngl::XML::XMLElement* elm, TiXmlElement* source );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	XMLDomParserTinyXML( const XMLDomParserTinyXML& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h ( �R�s�[�֎~ )
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	XMLDomParserTinyXML& operator = ( const XMLDomParserTinyXML& other );

private:

	/** XML���� */
	TiXmlDocument*	xmlDocument_;

};

} // namespace TinyXML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/