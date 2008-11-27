/*******************************************************************************/
/**
 * @file IEffect.h.
 * 
 * @brief �G�t�F�N�g�C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/08.
 * 
 * @version 1.00.
 * 
 * @author ����Җ�.
 */
/******************************************************************************/
#ifndef _NGL_IEFFECT_H_
#define _NGL_IEFFECT_H_

#include	"InputSignatureDesc.h"

namespace Ngl{


// �e�N�X�`���C���^�[�t�F�[�X
class ITexture;

/**
 * @interface IEffect�D
 * @brief �G�t�F�N�g�C���^�[�t�F�[�X.
 */
class IEffect
{
public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IEffect(){}

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N���J�n
	 * 
	 * @param[in] techniqueName �e�N�j�b�N��.
	 * @return �Ȃ�.
	 */
	virtual void technique( const char* techniqueName ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �p�X���J�n
	 * 
	 * @param[in] passNo �p�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void begin( int passNo=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �p�X���I��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void end() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾
	 * 
	 * @param[in] techniqueNo �擾����e�N�j�b�N�ԍ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual const char* getTechniqueName( int techniqueNo ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�j�b�N�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual int getNumTechnique() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���݂̃e�N�j�b�N�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �e�N�j�b�N��.
	 */
	virtual const char* getCurrentTechniqueName() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] paramNo �擾����p�����[�^�ԍ�.
	 * @return �p�����[�^��.
	 */
	virtual const char* getParameterName( int paramNo ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�����[�^�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�����[�^��.
	 */
	virtual int getNumParameter() = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �p�X�����擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �p�X��.
	 */
	virtual int getNumPass() = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��X�J���[�l.
	 * @return �Ȃ�.
	 */
	virtual void setScalar( const char* name, float v ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��X�J���[�l.
	 * @return �Ȃ�.
	 */
	virtual void setScalar( const char* name, int v ) = 0;
	
	
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
	virtual void setVector( const char* name, float x=0, float y=0, float z=0, float w=0 ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �s��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] matrix �ݒ肷��s��p�����[�^
	 * @return �Ȃ�.
	 */
	virtual void setMatrix( const char* name, float* matrix ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setScalarArray( const char* name, float* v, unsigned int count ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�J���[�̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] v �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setScalarArray( const char* name, int* v, unsigned int count ) = 0;
	
	
	/*=========================================================================*/
	/**
	 * @brief �x�N�g���̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setVectorArray( const char* name, float* array, unsigned int count ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �s��̔z��p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] array �ݒ肷��z��p�����[�^�̐擪�|�C���^.
	 * @param[in] count �z��̗v�f��.
	 * @return �Ȃ�.
	 */
	virtual void setMatrixArray( const char* name, float* array, unsigned int count ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���̃p�����[�^��ݒ�
	 * 
	 * @param[in] name �p�����[�^��.
	 * @param[in] texture �e�N�X�`���C���^�[�t�F�[�X�N���X�̃|�C���^s.
	 * @return �Ȃ�.
	 */
	virtual void setTexture( const char* name, ITexture* texture ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief ���̓V�O�l�`���\���̂��擾
	 * 
	 * @param[in] techniqueName �e�N�j�b�N��.
	 * @param[in] passNo �p�X�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual const InputSignatureDesc inputSigneture( const char* techniqueName, int passNo=0 ) const = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/