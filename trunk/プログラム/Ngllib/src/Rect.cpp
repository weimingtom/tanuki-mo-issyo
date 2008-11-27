/*******************************************************************************/
/**
 * @file Rect.cpp.
 * 
 * @brief ��`�\���̃\�[�X�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Rect.h"

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Rect::Rect():
	left( 0.0f ),	// ���[�ʒu
	top( 0.0f ),	// ��[�ʒu
	right( 0.0f ),	// �E�[�ʒu
	bottom( 0.0f )	// ���[�ʒu
{
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] L ���[�ʒu, T ��[�ʒu, R �E�[�ʒu, B ���[�ʒu.
 */
Rect::Rect(float L, float T, float R, float B):
	left( L ),	// ���[�ʒu
	top( T ),	// ��[�ʒu
	right( R ),	// �E�[�ʒu
	bottom( B )	// ���[�ʒu
{
}



/*===========================================================================*/
/**
 * @brief ����������
 * 
 * @param[in] L ���[�ʒu.
 * @param[in] T ��[�ʒu.
 * @param[in] R �E�[�ʒu.
 * @param[in] B ���[�ʒu.
 * @return �Ȃ�.
 */
void Rect::initialize( float L, float T, float R, float B )
{
	left = L;
	top = T;
	right = R;
	bottom = B;
}

	
	
/*=========================================================================*/
/**
 * @brief �ʒu���W, ���ƍ��������`�����߂�
 * 
 * @param[in] L ����ʒux���W.
 * @param[in] T ����ʒuy���W.
 * @param[in] Width �E�[�ʒu.
 * @param[in] Height ���[�ʒu.
 * @return �Ȃ�.
 */
void Rect::fromSize( float L, float T, float Width, float Height )
{
	left	= L;
	top		= T;
	right	= left + Width;
	bottom	= top + Height; 
}
	
	
	
/*=========================================================================*/
/**
 * @brief == ���Z�q�I�[�o�[���[�h
 *
 * �����l�̋�`����r����B
 * 
 * @param[in] r1 ��r�����`1.
 * @param[in] r2 ��r�����`2.
 * @retval true �����l.
 * @retval false �Ⴄ�l.
 */
bool operator == ( const Ngl::Rect& r1, const Ngl::Rect& r2 )
{
	return ( r1.left == r2.left && r1.top == r2.top && r1.right == r2.right && r1.bottom == r2.bottom );
}



/*=========================================================================*/
/**
 * @brief != ���Z�q�I�[�o�[���[�h
 *
 * �Ⴄ�l�̋�`����r����B
 * 
 * @param[in] r1 ��r�����`1.
 * @param[in] r2 ��r�����`2.
 * @retval true �Ⴄ�l.
 * @retval false �����l.
 */
bool operator != ( const Ngl::Rect& r1, const Ngl::Rect& r2 )
{
	return !( r1 == r2 );
}
	
	
	
/*========= EOF =============================================================*/