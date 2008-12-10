/*******************************************************************************/
/**
 * @file XMLText.cpp.
 * 
 * @brief XML�e�L�X�g�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/XML/XMLText.h"
#include	<sstream>

using namespace Ngl;
using namespace Ngl::XML;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
XMLText::XMLText()
{}

	
	
/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] text XML�̃e�L�X�g.
 */
XMLText::XMLText( const char* text ):
	text_( text )
{}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��ݒ肷��
 * 
 * @param[in] text XML�̃e�L�X�g.
 */
void XMLText::setText( const char* text )
{
	text_ = text;
}

	
	
/*=========================================================================*/
/**
 * @brief �e�L�X�g��ێ����Ă��邩
 * 
 * @param[in] �Ȃ�.
 * @retval true �ێ����Ă���.
 * @retval false �ێ����Ă��Ȃ�.
 */
bool XMLText::hasText() const
{
	return !text_.empty();
}
	
	
	
/*=========================================================================*/
/**
 * @brief �e�L�X�g�𕶎���Ŏ擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�L�X�g.
 */
const std::string& XMLText::getText() const
{
	return text_;
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�^�̐��l�Ŏ擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�L�X�g.
 */
int XMLText::getTextInt() const
{
	return std::atoi( text_.c_str() );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�^�̐��l�Ŏ擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�L�X�g.
 */
float XMLText::getTextFloat() const
{
	return (float)std::atof( text_.c_str() );
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g�𕶎���z��Ŏ擾����
 * 
 * @param[out] array XML������^�z��.
 * @return �Ȃ�.
 */
void XMLText::getArray( StringArray& array ) const
{
	std::stringstream ss( text_ );
	while ( ss.eof() == false ) {
		std::string value;
		ss >> value;
		array.push_back( value );
	}
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��int�^�z��Ŏ擾����
 * 
 * @param[out] array XMLint�^�z��.
 * @return �e�L�X�g.
 */
void XMLText::getArray( IntArray& array ) const
{
	std::stringstream ss( text_ );
	while( ss.eof() == false ){
		int value = 0;
		ss >> value;
		array.push_back( value );
	}
}



/*=========================================================================*/
/**
 * @brief �e�L�X�g��float�^�z��Ŏ擾����
 * 
 * @param[out] array XMLFloat�^�z��.
 * @return �e�L�X�g.
 */
void XMLText::getArray( FloatArray& array ) const
{
	std::stringstream ss( text_ );
	while( ss.eof() == false ){
		float value = 0;
		ss >> value;
		array.push_back( value );
	}
}


	
/*===== EOF ==================================================================*/