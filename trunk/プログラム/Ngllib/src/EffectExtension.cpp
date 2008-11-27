/*******************************************************************************/
/**
 * @file EffectExtension.cpp.
 * 
 * @brief �g���G�t�F�N�g�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/EffectExtension.h"
#include	<cassert>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �t�@�C����.
 * @param[in] renderer �����_���[�N���X�̃|�C���^.
 */
EffectExtension::EffectExtension( const char* fileName, IRenderer* renderer ):
	effect_( 0 ),
	isDelete_( true )
{
	// �G�t�F�N�g���쐬
	effect_ = renderer->createEffect( fileName );
	assert( effect_ != 0 );

	// �쐬�������Ă�
	create();
}



/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] effect �G�t�F�N�g�N���X�̃|�C���^.
 * @param[in] isDelete �ݒ肵���G�t�F�N�g�N���X���폜���邩
 */
EffectExtension::EffectExtension( IEffect* effect, bool isDelete ):
	effect_( effect ),
	isDelete_( isDelete )
{
	assert( effect != 0 );

	// �쐬�������Ă�
	create();
}

	
	
/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
EffectExtension::~EffectExtension()
{
	// �p�����[�^�R���e�i�����
	ParameterContainer::iterator paramItor = parameterContainer_.begin();
	while( paramItor != parameterContainer_.end() ){
		delete *paramItor;
		paramItor = parameterContainer_.erase( paramItor );
	}

	// �e�N�j�b�N�R���e�i�����
	TechniqueContainer::iterator tecItor = techniqueContainer_.begin();
	while( tecItor != techniqueContainer_.end() ){
		delete *tecItor;
		tecItor = techniqueContainer_.erase( tecItor );
	}

	// �G�t�F�N�g���폜
	if( isDelete_ == true ){
		delete effect_;
	}
	else{
		effect_ = 0;
	}
}



/*=========================================================================*/
/**
 * @brief �C���f�b�N�X����e�N�j�b�N���擾����
 * 
 * @param[in] index �C���f�b�N�X.
 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectTechnique* EffectExtension::getTechniqueByIndex( unsigned int index )
{
	return techniqueContainer_[ index ];
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N������e�N�j�b�N���擾����
 * 
 * @param[in] name �e�N�j�b�N��.
 * @return �G�t�F�N�g�e�N�j�b�N�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectTechnique* EffectExtension::getTechniqueByName( const char* name )
{
	for( int i=0; i<effect_->getNumTechnique(); ++i ){
		if( techniqueContainer_[ i ]->name() == name ){
			return techniqueContainer_[ i ];
		}
	}
	assert( false );
	return 0;
}



/*=========================================================================*/
/**
 * @brief �p�����[�^������p�����[�^���擾����
 * 
 * @param[in] name �p�����[�^��.
 * @return �G�t�F�N�g�p�����[�^�C���^�[�t�F�[�X�̃|�C���^.
 */
IEffectParameter* EffectExtension::getParameterByName( const char* name )
{
	for( int i=0; i<effect_->getNumParameter(); ++i ){
		if( parameterContainer_[ i ]->name() == name ){
			return parameterContainer_[ i ];
		}
	}
	assert( false );
	return 0;
}



/*=========================================================================*/
/**
 * @brief �G�t�F�N�g�C���^�[�t�F�[�X���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
IEffect* EffectExtension::getEffect()
{
	return effect_;
}
	
	

/*=========================================================================*/
/**
 * @brief �쐬����
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void EffectExtension::create()
{
	// �e�N�j�b�N���쐬
	int tecCount = effect_->getNumTechnique();
	for( int i=0; i<tecCount; ++i ){
		EffectTechnique* tec = new EffectTechnique( effect_, i );
		techniqueContainer_.push_back( tec );
	}

	// �p�����[�^���쐬����
	int paramCount =effect_->getNumParameter(); 
	for( int i=0; i<paramCount; ++i ){
		EffectParameter* param = new EffectParameter( effect_, effect_->getParameterName( i ) );
		parameterContainer_.push_back( param );
	}
}
	
	
	
/*===== EOF ==================================================================*/