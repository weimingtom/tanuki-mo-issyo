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
SpriteInfo LoadSpriteInfo( std::string name )
{
	SpriteInfo			info;
	Ngl::XML::XMLFile	file;
	Ngl::IXMLElement*	spriteInfo;
	Ngl::IXMLElement*	element;

	Ngl::TinyXML::XMLDomParserTinyXML xml;
	xml.load("Resource/Data/sprite.xml", file);
	spriteInfo = file.getElementByName("spriteInfo");
	for(unsigned int i=0; i<spriteInfo->childElementCount(); i++)
	{
		if(spriteInfo->getElementByIndex(i)->getAttribByName("sprite").getText() == name)
		{
			element = spriteInfo->getElementByIndex(i);
			break;
		}
	}
	if(!element) return info;

	info.srcPosition.x << element->getElementByName("srcPositionX")->getValue();
	info.srcPosition.y << element->getElementByName("srcPositionY")->getValue();
	info.srcSize.x << element->getElementByName("srcSize.x")->getValue();
	info.srcSize.y << element->getElementByName("srcSize.y")->getValue();
	info.position.x << element->getElementByName("position.x")->getValue();
	info.position.y << element->getElementByName("position.y")->getValue();
	info.size.x << element->getElementByName("size.x")->getValue();
	info.size.y << element->getElementByName("size.y")->getValue();

	return info;
}

/*=============================================================================*/
/**
 * @brief デストラクタ.
 *
 */

/*=============================================================================*/
/**
 * @brief 関数説明.
 * 
 * @param[in] 引数名 引数説明.
 * @return 戻り値説明.
 */

/*=============================================================================*/

/*===== EOF ===================================================================*/