/*******************************************************************************/
/**
 * @file MatrixStacker.h.
 * 
 * @brief �s��X�^�b�N�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATRIXSTACKER_H_
#define _NGL_MATRIXSTACKER_H_

#include	<Ngl/Matrix4.h>
#include	<stack>

namespace Ngl{


/**
 * @class MatrixStacker.
 * @brief �s��X�^�b�N�N���X�D
 */
class MatrixStacker
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	MatrixStacker();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~MatrixStacker();


	/*=========================================================================*/
	/**
	 * @brief ����������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void initialize();
	
	
	/*=========================================================================*/
	/**
	 * @brief �P�ʍs����v�b�V������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void push();


	/*=========================================================================*/
	/**
	 * @brief �擪�̍s����|�b�v����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void pop();
	
	
	/*=========================================================================*/
	/**
	 * @brief ���X�g�����ׂč폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clearList();


	/*=========================================================================*/
	/**
	 * @brief ���݂̍s��ɍs�����Z����
	 * 
	 * @param[in] matrix ��Z����s��.
	 * @return �Ȃ�.
	 */
	void multiply( const Ngl::Matrix4& matrix );


	/*=========================================================================*/
	/**
	 * @brief ���ʂ��擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return result.
	 */
	const Ngl::Matrix4& getResult() const;


	/*=========================================================================*/
	/**
	 * @brief �v�f���󂩒��ׂ�
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �v�f������.
	 * @retval false �v�f������.
	 */
	bool isEmpty();

private:

	/** �s��ۊǃN���X */
	std::stack< Ngl::Matrix4 >	stack_;	

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/