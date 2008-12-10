/*******************************************************************************/
/**
 * @file IXMLElement.h.
 * 
 * @brief XML�v�f�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IXMLELEMENT_H_
#define _NGL_IXMLELEMENT_H_

#include	"IXMLText.h"
#include	<string>

namespace Ngl{


/**
 * @interface IXMLElement�D
 * @brief XML�v�f�C���^�[�t�F�[�X.
 */
class IXMLElement
{
protected:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IXMLElement() {}

public:

	/*=========================================================================*/
	/**
	 * @brief ���O����q�v�f���擾
	 * 
	 * @param[in] name �l���擾����v�f��.
	 * @return �擾�����v�f.
	 */
	virtual IXMLElement* getElementByName( const std::string& name ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�ԍ�����v�f���擾
	 * 
	 * @param[in] index �l���擾����v�f��.
	 * @return �擾�����v�f(�͈͊O�̏ꍇ��0���Ԃ�܂�).
	 */
	virtual IXMLElement* getElementByIndex( int index ) = 0;
	

	/*=========================================================================*/
	/**
	 * @brief ���������瑮���̒l���擾
	 * 
	 * @param[in] name �l���擾���鑮����.
	 * @return �擾�����l ���݂��Ȃ��ꍇ�͋󕶎����Ԃ�.
	 */
	virtual const IXMLText& getAttribByName( const std::string& name ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �l���擾
	 *
	 * @param[in] �Ȃ�.
	 * @return �擾�����l.
	 */
	virtual const IXMLText& getValue() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �q�v�f�������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �q�v�f�����݂���.
	 * @retval false �q�v�f�����݂��Ȃ�.
	 */
	virtual bool isExistChildElement() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �����������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �����������Ă���.
	 * @retval false �����������Ă��Ȃ�.
	 */
	virtual bool isExistAttrib() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �l�������Ă��邩
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �l�������Ă���.
	 * @retval false �l�������Ă��Ȃ�.
	 */
	virtual bool isExistValue() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �q�v�f�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �q�v�f��.
	 */
	virtual unsigned int childElementCount() const = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief ���������擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ������.
	 */
	virtual unsigned int attribCount() const = 0;

	
	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 * 
	 * name�Ŏw�肵���q�v�f���擾����.
	 * 
	 * @param[in] name �擾����q�v�f��.
	 * @return �擾�����q�v�f�N���X.
	 */
	virtual IXMLElement* operator [] ( const std::string& name ) = 0;


	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 * 
	 * name�Ŏw�肵���q�v�f���擾����.
	 * 
	 * @param[in] index �擾����v�f�C���f�b�N�X�ԍ�.
	 * @return �擾�����q�v�f�N���X( �͈͊O�̏ꍇ��0���Ԃ�܂�).
	 */
	virtual IXMLElement* operator [] ( int index ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/