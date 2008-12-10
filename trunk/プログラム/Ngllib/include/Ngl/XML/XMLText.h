/*******************************************************************************/
/**
 * @file XMLText.h.
 * 
 * @brief XML�e�L�X�g�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_XMLTEXT_H_
#define _NGL_XMLTEXT_H_

#include	"Ngl/IXMLText.h"
#include	<string>

namespace Ngl{


namespace XML{


/**
 * @class XMLText�D
 * @brief XML�e�L�X�g�N���X.
 */
class XMLText : public IXMLText
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in]�Ȃ�.
	 */
	XMLText();

	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] text XML�̃e�L�X�g.
	 */
	XMLText( const char* text );


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��ݒ肷��
	 * 
	 * @param[in] text XML�̃e�L�X�g.
	 */
	void setText( const char* text );
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��ێ����Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �ێ����Ă���.
	 * @retval false �ێ����Ă��Ȃ�.
	 */
	virtual bool hasText() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g�𕶎���Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual const std::string& getText() const;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��int�^�̐��l�Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual int getTextInt() const;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��float�^�̐��l�Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual float getTextFloat() const;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g�𕶎���z��Ŏ擾����
	 * 
	 * @param[out] array XML������^�z��.
	 * @return �Ȃ�.
	 */
	virtual void getArray( StringArray& array ) const;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��int�^�z��Ŏ擾����
	 * 
	 * @param[out] array XMLint�^�z��.
	 * @return �e�L�X�g.
	 */
	virtual void getArray( IntArray& array ) const;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��float�^�z��Ŏ擾����
	 * 
	 * @param[out] array XMLfloat�^�z��.
	 * @return �e�L�X�g.
	 */
	virtual void getArray( FloatArray& array ) const;

private:

	/** XML�̃e�L�X�g */
	std::string	text_;

};

} // namespace XML

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/