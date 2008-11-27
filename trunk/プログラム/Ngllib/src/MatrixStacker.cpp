/*******************************************************************************/
/**
 * @file MatrixStacker.cpp.
 * 
 * @brief �s��X�^�b�N�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/10/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/MatrixStacker.h>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MatrixStacker::MatrixStacker()
{}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
MatrixStacker::~MatrixStacker()
{
	clearList();
}
	
	
	
/*===========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MatrixStacker::initialize()
{
	// ���X�g���폜
	clearList();

	// �P�ʍs����ЂƂv�b�V��
	push();
}



/*=========================================================================*/
/**
 * @brief �P�ʍs����v�b�V������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MatrixStacker::push()
{
	stack_.push( Ngl::MATRIX4_IDENTITY );
}



/*=========================================================================*/
/**
 * @brief �擪�̍s����|�b�v����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MatrixStacker::pop()
{
	if( isEmpty() == true ){
		return;
	}

	// �v�f��1�Ȃ�|�b�v���Ȃ�
	if( stack_.size() == 1 ){
		return;
	}
	
	stack_.pop();
}



/*===========================================================================*/
/**
 * @brief ���X�g�����ׂč폜
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MatrixStacker::clearList()
{
	while( stack_.empty() == false ){
		stack_.pop();
	}
}



/*===========================================================================*/
/**
 * @brief ���݂̍s��ɍs�����Z����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void MatrixStacker::multiply( const Ngl::Matrix4& matrix )
{
	// �v�f�����邩
	if( stack_.empty() == true ){
		return;
	}
		
	// �擪�̗v�f�ɏ�Z
	stack_.top() *= matrix;
}



/*=========================================================================*/
/**
 * @brief ���ʂ��擾����
 * 
 * @param[in] �Ȃ�.
 * @return result.
 */
const Ngl::Matrix4& MatrixStacker::getResult() const
{
	return stack_.top();
}


/*=========================================================================*/
/**
 * @brief �v�f���󂩒��ׂ�
 * 
 * @param[in] �Ȃ�.
 * @retval true �v�f������.
 * @retval false �v�f������.
 */
bool MatrixStacker::isEmpty()
{
	return stack_.empty();
}



/*========= EOF =============================================================*/