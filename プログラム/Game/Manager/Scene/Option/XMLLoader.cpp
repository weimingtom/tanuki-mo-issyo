/*******************************************************************************/
/*
 * @file XMLLoader.cpp.
 * 
 * @brief XML読み込み補助クラス.
 *
 * @date 2009/01/13.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== インクルード ==========================================================*/
#include	<Ngl/TinyXML/XMLDomParserTinyXML.h>
#include	<Ngl/XML/XMLUtil.h>
#include	"XMLLoader.h"
/*===== 定数宣言 ==============================================================*/


/*=============================================================================*/
/**
 * @brief コンストラクタ.
 * 
 * @param[in] 引数名 引数説明.
 */
XMLLoader::XMLLoader()
{
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */
XMLLoader::~XMLLoader()
{
}

/*=============================================================================*/
/**
 * @brief 関数説明.
 * 
 * @param[in] 引数名 引数説明.
 * @return 戻り値説明.
 */
SpriteInfo XMLLoader::LoadSpriteInfo( std::string name )
{
	SpriteInfo			info;
	Ngl::XML::XMLFile	file;
	Ngl::IXMLElement*	spriteInfo;
	Ngl::IXMLElement*	element = NULL;

	Ngl::TinyXML::XMLDomParserTinyXML xml;
	xml.load("Resource/Data/sprite.xml", file);
	spriteInfo = file.getElementByName("spriteInfo");
	for(unsigned int i=0; i<spriteInfo->childElementCount(); i++)
	{
		if(spriteInfo->getElementByIndex(i)->getAttribByName("name").getText() == name)
		{
			element = spriteInfo->getElementByIndex(i);
			break;
		}
	}
	if(!element) return info;

	if(element->getElementByName("srcPositionX"))
		info.srcPosition.x << element->getElementByName("srcPositionX")->getValue();
	if(element->getElementByName("srcPositionY"))
		info.srcPosition.y << element->getElementByName("srcPositionY")->getValue();
	if(element->getElementByName("srcSizeX"))
		info.srcSize.x << element->getElementByName("srcSizeX")->getValue();
	if(element->getElementByName("srcSizeY"))
		info.srcSize.y << element->getElementByName("srcSizeY")->getValue();
	if(element->getElementByName("positionX"))
		info.position.x << element->getElementByName("positionX")->getValue();
	if(element->getElementByName("positionY"))
		info.position.y << element->getElementByName("positionY")->getValue();
	if(element->getElementByName("sizeX"))
		info.size.x << element->getElementByName("sizeX")->getValue();
	if(element->getElementByName("sizeY"))
		info.size.y << element->getElementByName("sizeY")->getValue();
	if(element->getElementByName("textureName"))
		info.spriteName << element->getElementByName("textureName")->getValue();


	return info;
}

/*=============================================================================*/

/*===== EOF ===================================================================*/