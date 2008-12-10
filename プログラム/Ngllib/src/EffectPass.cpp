/*******************************************************************************/
/**
 * @file EffectPass.cpp.
 * 
 * @brief �G�t�F�N�g�p�X�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectPass.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
 * @param[in] techniqueName �e�N�j�b�N��.
 * @param[in] passNo �p�X�ԍ�.
 */
EffectPass::EffectPass( IEffect* effect, const std::string& techniqueName, unsigned int passNo ):
	effect_( effect ),
	techniqueName_( techniqueName ),
	passNo_( passNo )
{
	assert( effect_ != NULL );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
EffectPass::~EffectPass()
{
	effect_ = 0;
}



/*=========================================================================*/
/**
 * @brief �p�X���J�n����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void EffectPass::begin()
{
	// �e�N�j�b�N��ݒ�
	effect_->technique( techniqueName_.c_str() );

	//�@�p�X���J�n����
	effect_->begin( passNo_ );
}



/*=========================================================================*/
/**
 * @brief �p�X���I������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void EffectPass::end()
{
	effect_->end();
}



/*=========================================================================*/
/**
 * @brief ���̓V�O�l�`���L�q�q���擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���̓V�O�l�`���L�q�q.
 */
const InputSignatureDesc EffectPass::inputSignature()
{
	return effect_->inputSigneture( techniqueName_.c_str(), passNo_ );
}



/*===== EOF ==================================================================*/