/*******************************************************************************/
/**
 * @file EffectCgGL.h.
 * 
 * @brief OpenGL Cgfx�G�t�F�N�g�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/20.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OPENGL_EFFECT_H_
#define _NGL_OPENGL_EFFECT_H_

#include	"Ngl/IEffect.h"
#include	"OpenGL.h"
#include	<Cg/cg.h>
#include	<Cg/cgGL.h>

namespace Ngl{


// �e�N�X�`���N���X
class ITexture;


namespace OpenGL{


/**
 * @class EffectCgGL.
 * @brief OpenGL Cgfx�G�t�F�N�g�N���X.
 *
 * cgfx�`���G�t�F�N�g�t�@�C�����������邽�߂̃N���X�ł��B
 */
class EffectCgGL : public IEffect
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] fileName �t�@�C����.
	 */
	EffectCgGL( const char* fileName );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~EffectCgGL();

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N���J�n
	 * 
	 * @param[in] techniqueName �e�N�j�b�N��.
	 * @return �Ȃ�.
	 */
	void technique( const char* techniqueName );

	
	/*=========================================================================*/
	/**
	 * @brief �p�X���J�n
	 * 
	 * @param[in] passNo �p�X�ԍ�.
	 * @return �Ȃ�.
	 */
	void begin( int passNo=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �p�X���I��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void end();

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾
	 * 
	 * @param[in] techniqueNo �擾����e�N�j�b�N�ԍ�.
	 * @return �e�N�j�b�N��.
	 */
	const char* getTechniqueName( int techniqueNo );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	int getNumTechnique();

	
	/*=========================================================================*/
	/**
	 * @brief ���݂̃e�N�j�b�N�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual const char* getCurrentTechniqueName();
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] paramNo �擾����p�����[�^�ԍ�.
	 * @return �p�����[�^��.
	 */
	virtual const char* getParameterName( int paramNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�����[�^��.
	 */
	virtual int getNumParameter();
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�X��.
	 */
	int getNumPass();

	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��X�J���[�l.
	 * @return �Ȃ�.
	 */
	virtual void setScalar( const char* name, float v );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��X�J���[�l.
	 * @return �Ȃ�.
	 */
	virtual void setScalar( const char* name, int v );
	
	
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
	void setVector( const char* name, float x=0, float y=0, float z=0, float w=0 );

	
	/*=========================================================================*/
	/**
	 * @brief �s��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] matrix �ݒ肷��s��p�����[�^
	 * @return �Ȃ�.
	 */
	void setMatrix( const char* name, float* matrix );

	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setScalarArray( const char* name, float* v, unsigned int count );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setScalarArray( const char* name, int* v, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g���̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	void setVectorArray( const char* name, float* array, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief �s��̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	void setMatrixArray( const char* name, float* array, unsigned int count );

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���̃p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] texture �e�N�X�`���C���^�[�t�F�[�X�N���X�̃|�C���^s.
	 * @return �Ȃ�.
	 */
	void setTexture( const char* name, ITexture* texture );

	
	/*=========================================================================*/
	/**
	 * @brief ���̓V�O�l�`���\���̂��擾
	 * 
	 * @param[in] techeniqueName �e�N�j�b�N��.
	 * @param[in] passNo �p�X�ԍ�.
	 * @return �Ȃ�.
	 */
	const InputSignatureDesc inputSigneture( const char* techeniqueName, int passNo=0 ) const;

private:

	/** �b�f�R���e�L�X�g */
	CGcontext	context_;

	/** �G�t�F�N�g */
	CGeffect	effect_;

	/** �e�N�j�b�N */
	CGtechnique	technique_;

	/** �p�X */
	CGpass		pass_;

};

} // namespace OpenGL

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/