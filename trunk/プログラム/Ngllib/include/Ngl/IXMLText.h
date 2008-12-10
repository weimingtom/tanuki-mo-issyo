/*******************************************************************************/
/**
 * @file IXMLText.h.
 * 
 * @brief XML�e�L�X�g�C���^�[�t�F�[�X��`.
 *
 * @date 2008/11/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLTEXT_H_
#define _NGL_IXMLTEXT_H_

#include	<string>
#include	<vector>

namespace Ngl{


/**
 * @interface IXMLText�D
 * @brief XML�e�L�X�g�C���^�[�t�F�[�X.
 */
class IXMLText
{
public:

	/** XML String�l�z��^ */
	typedef std::vector< std::string >	StringArray;

	/** XML int�l�z��^ */
	typedef std::vector< int >			IntArray;

	/** XML float�l�z�� */
	typedef std::vector< float >		FloatArray;

public:
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IXMLText() {}

	
	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��ێ����Ă��邩
	 * 
	 * @param[in]�Ȃ�.
	 * @retval true �ێ����Ă���.
	 * @retval false �ێ����Ă��Ȃ�.
	 */
	virtual bool hasText() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g�𕶎���Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual const std::string& getText() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��int�^�̐��l�Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual int getTextInt() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��float�^�̐��l�Ŏ擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�L�X�g.
	 */
	virtual float getTextFloat() const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g�𕶎���z��Ŏ擾����
	 * 
	 * @param[out] array XML������^�z��.
	 * @return �Ȃ�.
	 */
	virtual void getArray( StringArray& array ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��int�^�z��Ŏ擾����
	 * 
	 * @param[out] array XMLint�^�z��.
	 * @return �e�L�X�g.
	 */
	virtual void getArray( IntArray& array ) const = 0;


	/*=========================================================================*/
	/**
	 * @brief �e�L�X�g��float�^�z��Ŏ擾����
	 * 
	 * @param[out] array XMLfloat�^�z��.
	 * @return �e�L�X�g.
	 */
	virtual void getArray( FloatArray& array ) const = 0;

};


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/