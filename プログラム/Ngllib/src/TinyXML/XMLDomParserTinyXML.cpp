/*******************************************************************************/
/**
 * @file XMLDomParserTinyXML.cpp.
 * 
 * @brief TinyXML DOM����XML�p�[�T�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/12/03.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/TinyXML/XMLDomParserTinyXML.h"
#include	<TinyXML/tinyxml.h>

using namespace Ngl;
using namespace Ngl::TinyXML;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLDomParserTinyXML::XMLDomParserTinyXML():
	xmlDocument_( new TiXmlDocument() )
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLDomParserTinyXML::~XMLDomParserTinyXML()
{
	delete xmlDocument_;
}



/*=========================================================================*/
/**
 * @brief �t�@�C������f�[�^��ǂݍ���
 * 
 * @param[in] name �t�@�C����.
 * @param[out] file �f�[�^��ǂݍ���XMLFile�N���X.
 * @return �Ȃ�.
 */
void XMLDomParserTinyXML::load( const std::string& name, Ngl::XML::XMLFile& file )
{
	// XML�t�@�C������͂���
	xmlDocument_->LoadFile( name.c_str() );

	// �Z��v�f���擾
	TiXmlElement* element = xmlDocument_->FirstChildElement();
	while( element != 0 ){
		// �v�f���쐬����
		Ngl::XML::XMLElement* elm = new Ngl::XML::XMLElement( element->Value() );
		createElement( elm, element );

		// �쐬�����v�f��ǉ�
		file.addElement( elm );

		// ���̗v�f��
		element = xmlDocument_->NextSiblingElement();
	}
}



/*=========================================================================*/
/**
 * @brief �v�f���쐬
 * 
 * @param[in] elm �쐬�����v�f��ǉ�����v�f( �e�v�f ).
 * @param[out] source �f�[�^��ǂݍ���TinyXML�v�f�N���X.
 * @return �Ȃ�.
 */
void XMLDomParserTinyXML::createElement( Ngl::XML::XMLElement* elm, TiXmlElement* source )
{
	// �I�[�̃m�[�h�ɒB����
	if( source == 0 ){
		return;
	}

	// �������쐬
	createAttribute( elm, source );

	// �l�����݂��Ă���ΐݒ�
	const char* txt = source->GetText();
	if( txt != 0 ){
		elm->setText( txt );
	}

	// �q�m�[�h���쐬
	TiXmlElement* childElm = source->FirstChildElement();
	while( childElm != 0 ){
		Ngl::XML::XMLElement* tElm = new Ngl::XML::XMLElement( childElm->Value() );
	
		// �v�f���쐬����
		createElement( tElm, childElm );

		// �쐬�����v�f��ǉ�
		elm->addChild( tElm );

		// ���̗v�f��
		childElm = childElm->NextSiblingElement();
	}
}

	
	
/*=========================================================================*/
/**
 * @brief �������쐬
 * 
 * @param[in] elm �쐬����������ǉ�����v�f.
 * @param[out] source �f�[�^��ǂݍ���TinyXML�v�f�N���X.
 * @return �Ȃ�.
 */
void XMLDomParserTinyXML::createAttribute( Ngl::XML::XMLElement* elm, TiXmlElement* source )
{
	// ���������݂��Ă��邩
	TiXmlAttribute* attb = source->FirstAttribute();
	while( attb != 0 ){
		// ������ǉ�
		elm->addAttribute( attb->Name(), attb->Value() );

		// ���̑�����
		attb = attb->Next();
	}
}

	
	
/*===== EOF ==================================================================*/