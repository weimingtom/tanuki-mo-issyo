/*******************************************************************************/
/**
 * @file EffectCgGL.cpp.
 * 
 * @brief OpenGL Cgfx�G�t�F�N�g�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"EffectCgGL.h"
#include	"TextureGL.h"
#include	<iostream>
#include	<cassert>

using namespace Ngl;
using namespace Ngl::OpenGL;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] fileName �t�@�C����.
 */
EffectCgGL::EffectCgGL( const char* fileName ):
	context_( 0 ),
	effect_( 0 ),
	technique_( 0 ),
	pass_( 0 )
{
	// �R���e�L�X�g���쐬
	context_ = cgCreateContext();
	assert( context_ != 0 );

	// �R���e�L�X�g��OpenGL�ɐݒ�
	cgGLRegisterStates( context_ );

	// �G�t�F�N�g��ǂݍ���
	effect_ = cgCreateEffectFromFile( context_, fileName, NULL );
	if( effect_ == 0 ){
		// �G���[���b�Z�[�W���o�͂���
		const char* listing = cgGetLastListing( context_ );
		if( listing != 0 ){
			std::cout << "Error" << fileName << " : " << listing;
		}
	}
	assert( effect_ != 0 );
}



/*=========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
EffectCgGL::~EffectCgGL()
{
	// �G�t�F�N�g���폜
	if( cgIsEffect( effect_ ) == CG_TRUE ){
		cgDestroyEffect( effect_ );
	}

	// �R���e�L�X�g���폜
	if( cgIsContext( context_ ) == CG_TRUE ){
		cgDestroyContext( context_ );
	}
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N���J�n
 * 
 * @param[in] techniqueName �e�N�j�b�N��.
 * @return �Ȃ�.
 */
void EffectCgGL::technique( const char* techniqueName )
{
	// �e�N�j�b�N���擾����
	technique_ = cgGetNamedTechnique( effect_, techniqueName );
}



/*=========================================================================*/
/**
 * @brief �p�X���J�n
 * 
 * @param[in] passNo �p�X�ԍ�.
 * @return �Ȃ�.
 */
void EffectCgGL::begin( int passNo )
{
	// �ŏ��̃p�X���擾����
	pass_ = cgGetFirstPass( technique_ );

	// �w��̃p�X������
	for( int n=0; n<passNo; ++n ){
		pass_ = cgGetNextPass( pass_ );
	}

	// �p�X��L���ɂ���
	cgSetPassState( pass_ );
}



/*=========================================================================*/
/**
 * @brief �p�X���I��
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void EffectCgGL::end()
{
	// ���݂̃p�X�����Z�b�g����
	cgResetPassState( pass_ );

	// �p�X�𖳌��ɂ���
	pass_ = 0;
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N�����擾
 * 
 * @param[in] techniqueNo �擾����e�N�j�b�N�ԍ�.
 * @return �e�N�j�b�N��.
 */
const char* EffectCgGL::getTechniqueName( int techniqueNo )
{
	CGtechnique t = cgGetFirstTechnique( effect_ );
	for( int n=0; n<techniqueNo; ++n ){
		t = cgGetNextTechnique( t );
	}

	return cgGetTechniqueName( t );
}



/*=========================================================================*/
/**
 * @brief �e�N�j�b�N�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�j�b�N��.
 */
int EffectCgGL::getNumTechnique()
{
	// �e�N�j�b�N�̑����𒲂ׂ�
	int numTechnique = 0;
	for( CGtechnique t=cgGetFirstTechnique( effect_ ); cgIsTechnique( t ); t=cgGetNextTechnique( t ) ){
		numTechnique++;
	}
	return numTechnique;
}



/*=========================================================================*/
/**
 * @brief ���݂̃e�N�j�b�N�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �e�N�j�b�N��.
 */
const char* EffectCgGL::getCurrentTechniqueName()
{
	assert( technique_ != 0 );
	return cgGetTechniqueName( technique_ );
}


	
/*=========================================================================*/
/**
 * @brief �p�����[�^�����擾
 * 
 * @param[in] paramNo �擾����p�����[�^�ԍ�.
 * @return �p�����[�^��.
 */
const char* EffectCgGL::getParameterName( int paramNo )
{
	int count = 0;
	CGparameter param = ::cgGetFirstEffectParameter( effect_ );
	while ( param != 0 ){
		if( paramNo == count ){
			const char* name = ::cgGetParameterName( param );
			assert( name != 0 );
			return name;
		}

		count++;

		param = ::cgGetNextParameter( param );
	};


	// �󕶎���Ԃ�
	return "";
}



/*=========================================================================*/
/**
 * @brief �p�����[�^�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �p�����[�^��.
 */
int EffectCgGL::getNumParameter()
{
	int count = 0;
	CGparameter param = ::cgGetFirstEffectParameter( effect_ );
	while ( param != 0 ) {
		param = ::cgGetNextParameter( param );
		count ++;
	}
	return count;
}

	
	
/*=========================================================================*/
/**
 * @brief �p�X�����擾
 * 
 * @param[in] �Ȃ�.
 * @return �p�X��.
 */
int EffectCgGL::getNumPass()
{
	// �p�X�̑����𒲂ׂ�
	int numPass = 0;
	for( CGpass p=cgGetFirstPass( technique_ ); cgIsPass( p ); p=cgGetNextPass( p ) ){
		numPass++;
	}
	return numPass;
}



/*=========================================================================*/
/**
 * @brief �X�J���[�p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] v �ݒ肷��X�J���[�l.
 * @return �Ȃ�.
 */
void EffectCgGL::setScalar( const char* name, float v )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameter1f( param, v );
}



/*=========================================================================*/
/**
 * @brief �X�J���[�p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] v �ݒ肷��X�J���[�l.
 * @return �Ȃ�.
 */
void EffectCgGL::setScalar( const char* name, int v )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameter1i( param, v );
}

	
	

/*=========================================================================*/
/**
 * @brief �x�N�g���p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] x �ݒ肷��x�N�g����x����.
 * @param[in] y �ݒ肷��x�N�g����y����.
 * @param[in] z �ݒ肷��x�N�g����z����.
 + @param[in] w �ݒ肷��x�N�g����w����.
 * @return �Ȃ�.
 */
void EffectCgGL::setVector( const char* name, float x, float y, float z, float w )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	float v[4] = { x, y, z, w };
	cgSetParameterValuefc( param,cgGetParameterColumns( param ), v );
}



/*=========================================================================*/
/**
 * @brief �s��p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] matrix �ݒ肷��s��p�����[�^
 * @return �Ȃ�.
 */
void EffectCgGL::setMatrix( const char* name, float* matrix )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetMatrixParameterfr( param, matrix );
}



/*=========================================================================*/
/**
 * @brief �X�J���[�̔z��p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �z��̗v�f��.
 * @return �Ȃ�.
 */
void EffectCgGL::setScalarArray( const char* name, float* v, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgSetParameterValuefc( param, count, v );
}



/*=========================================================================*/
/**
 * @brief �X�J���[�̔z��p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �z��̗v�f��.
 * @return �Ȃ�.
 */
void EffectCgGL::setScalarArray( const char* name, int* v, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( elements, (int)count );
	cgSetParameterValueic( param, size, v );
}

	
	
/*=========================================================================*/
/**
 * @brief �x�N�g���̔z��p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �z��̗v�f��.
 * @return �Ȃ�.
 */
void EffectCgGL::setVectorArray( const char* name, float* array, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int columns		= cgGetParameterColumns( param );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( columns * elements, columns * (int)count );
	cgSetParameterValuefc( param, size, array );
}



/*=========================================================================*/
/**
 * @brief �s��̔z��p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
 * @param[in] count �z��̗v�f��.
 * @return �Ȃ�.
 */
void EffectCgGL::setMatrixArray( const char* name, float* array, unsigned int count )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	int columns		= cgGetParameterColumns( param );
	int rows		= cgGetParameterRows( param );
	int elements	= cgGetArrayTotalSize( param );
	int size		= min( columns * rows * elements, columns * rows * (int)count );
	cgSetParameterValuefr( param, size, array );
}



/*=========================================================================*/
/**
 * @brief �e�N�X�`���̃p�����[�^��ݒ�
 * 
 * @param[in] name �p�����[�^��.
 * @param[in] texture �e�N�X�`���C���^�[�t�F�[�X�N���X�̃|�C���^s.
 * @return �Ȃ�.
 */
void EffectCgGL::setTexture( const char* name, ITexture* texture )
{
	CGparameter param = cgGetNamedEffectParameter( effect_, name );
	cgGLSetupSampler( param, static_cast< TextureGL* >( texture )->texture() );
}



/*=========================================================================*/
/**
 * @brief ���̓V�O�l�`���\���̂��擾
 * 
 * @param[in] techeniqueName �e�N�j�b�N��.
 * @param[in] passNo �p�X�ԍ�.
 * @return �Ȃ�.
 */
const InputSignatureDesc EffectCgGL::inputSigneture( const char* techeniqueName, int passNo ) const
{
	(void)techeniqueName;
	(void)passNo;

	// DirectX10�Ƃ̌݊����������邽�߂̃_�~�[
	InputSignatureDesc descSignature = { 0, 0 };
	return descSignature;
}



/*===== EOF ==================================================================*/