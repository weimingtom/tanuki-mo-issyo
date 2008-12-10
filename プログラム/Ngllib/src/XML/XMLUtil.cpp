/*******************************************************************************/
/**
 * @file XMLUtil.cpp.
 * 
 * @brief XML���[�e�B���e�B�[�֐��S�\�[�X�t�@�C��.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLUtil.h"

/*=========================================================================*/
/**
 * @brief �e�L�X�g��char�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( char& value, const Ngl::IXMLText& text )
{
	value = (char)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned char�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( unsigned char& value, const Ngl::IXMLText& text )
{
	value = (unsigned char)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��short�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( short& value, const Ngl::IXMLText& text )
{
	value = (short)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned short�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( unsigned short& value, const Ngl::IXMLText& text )
{
	value = (unsigned short)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( int& value, const Ngl::IXMLText& text )
{
	value = text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned int�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( unsigned int& value, const Ngl::IXMLText& text )
{
	value = (unsigned int)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��long�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( long& value, const Ngl::IXMLText& text )
{
	value = (long)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned long�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( unsigned long& value, const Ngl::IXMLText& text )
{
	value = (unsigned long)text.getTextInt();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( float& value, const Ngl::IXMLText& text )
{
	value = text.getTextFloat();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��double�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( double& value, const Ngl::IXMLText& text )
{
	value = (double)text.getTextFloat();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��string�^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( std::string& value, const Ngl::IXMLText& text )
{
	value = text.getText();
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��string�z��^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( Ngl::IXMLText::StringArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�z��^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( Ngl::IXMLText::IntArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�z��^�Ŏ擾����
 * 
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @param[in] text XML�e�L�X�g.
 * @return �Ȃ�.
 */
void operator << ( Ngl::IXMLText::FloatArray& value, const Ngl::IXMLText& text )
{
	text.getArray( value );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��char�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, char& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned char�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned char& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��short�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, short& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned short�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned short& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, int& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned int�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned int& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��long�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, long& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��unsigned long�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, unsigned long& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, float& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��double�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, double& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��string�^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, std::string& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��string�z��^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::StringArray& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�z��^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::IntArray& value )
{
	value << text;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�z��^�Ŏ擾����
 * 
 * @param[in] text XML�e�L�X�g.
 * @param[in] value �擾�����l���i�[����ϐ�.
 * @return �Ȃ�.
 */
void operator >> ( const Ngl::IXMLText& text, Ngl::IXMLText::FloatArray& value )
{
	value << text;
}



/*===== EOF ==================================================================*/