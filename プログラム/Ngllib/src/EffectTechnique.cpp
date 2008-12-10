/*******************************************************************************/
/**
 * @file EffectTechnique.cpp.
 * 
 * @brief �G�t�F�N�g�e�N�j�b�N�N���X�\�[�X�t�@�C��.
 *
 * @date 2007/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectTechnique.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
 * @param[in] techniqueNo �e�N�j�b�N�ԍ�.
 */
EffectTechnique::EffectTechnique( IEffect* effect, unsigned int techniqueNo ):
	effect_( effect ),
	techniqueNo_( techniqueNo )
{
	assert( effect_ != NULL );

	// �e�N�j�b�N����ݒ�
	techniqueName_ = effect_->getTechniqueName( techniqueNo_ );

	// �e�N�j�b�N��ݒ�
	effect_->technique( techniqueName_.c_str() );

	// �G�t�F�N�g�p�X���쐬
	for( int pass=0; pass<effect_->getNumPass(); ++pass ){
		EffectPass* tPass = new EffectPass( effect_, techniqueName_.c_str(), pass );
		passContainer_.push_back( tPass );
	}
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
EffectTechnique::~EffectTechnique()
{
	// �p�X��S�폜
	EffectPassContainer::iterator itor = passContainer_.begin();
	while( itor != passContainer_.end() ){
		delete *itor;
		itor = passContainer_.erase( itor );
	}
}



/*=========================================================================*/
/**
 * @brief �p�X�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �p�X��.
 */
unsigned int EffectTechnique::numPass()
{
	return effect_->getNumPass();
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X����p�X���擾����
 * 
 * @param[in] index �p�X�C���f�b�N�X�ԍ�.
 * @return �p�X�N���X�̃|�C���^.
 */
IEffectPass* EffectTechnique::getPassByIndex( unsigned int index )
{
	return passContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N�����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�j�b�N��.
 */
const std::string& EffectTechnique::name() const
{
	return techniqueName_;
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N��ݒ�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void EffectTechnique::setTechnique()
{
	effect_->technique( name().c_str() );
}


	
/*===== EOF ==================================================================*/