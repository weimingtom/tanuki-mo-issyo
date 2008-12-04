/*******************************************************************************/
/**
 * @file ObjectParam.h.
 * 
 * @brief �I�u�W�F�N�g�p�����[�^�N���X��`.
 *
 * @date 2008/12/04.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_PARAM_H_
#define _OBJECT_PARAM_H_

#include "IGameDevice.h"

/**
 * @brief ObjectParam�D
 */

class ObjectParam
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^.
	 *
	 */
	ObjectParam();
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~ObjectParam();

	/*=========================================================================*/
	/**
	 * @brief �ʒu�̐ݒ�.
	 * 
	 * @param[in] x x�ʒu.
	 * @param[in] y y�ʒu.
	 */
	void SetPosition(float x, float y);
	/*=========================================================================*/
	/**
	 * @brief �ʒu�̐ݒ�.
	 * 
	 * @param[in] position �ʒu.
	 */
	void SetPosition(Vector2 position);
	/*=========================================================================*/
	/**
	 * @brief �ʒu�̎擾.
	 * 
	 * @return �ʒu.
	 */
	Vector2 GetPosition();

	/*=========================================================================*/
	/**
	 * @brief �T�C�Y�̐ݒ�.
	 * 
	 * @param[in] sx x�T�C�Y.
	 * @param[in] sy y�T�C�Y.
	 */
	void SetSize(float sx, float sy);
	/*=========================================================================*/
	/**
	 * @brief �T�C�Y�̐ݒ�.
	 * 
	 * @param[in] size �T�C�Y.
	 */
	void SetSize(Vector2 size);
	/*=========================================================================*/
	/**
	 * @brief �T�C�Y�̎擾.
	 * 
	 * @return �T�C�Y.
	 */
	Vector2 GetSize();

	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`��ID�̐ݒ�.
	 * 
	 * @param[in] texture �e�N�X�`��ID.
	 */
	void SetTextureID(int texture);
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`��ID�̎擾.
	 * 
	 * @return �e�N�X�`��ID.
	 */
	int GetTextureID();

private:

	/** �ʒu */
	Vector2 m_position;
	/** �T�C�Y */
	Vector2 m_size;
	/** �e�N�X�`��ID */
	int m_textureID;

};

#endif

/*===== EOF ===================================================================*/