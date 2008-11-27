/*******************************************************************************/
/**
 * @file IMapMesh.h.
 * 
 * @brief �}�b�v���b�V���C���^�[�t�F�[�X��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_IMAPMESH_H_
#define _NGL_IMAPMESH_H_

#include	"IInputStream.h"
#include	"IEffect.h"
#include	"Ngl/CollisionReport.h"
#include	"Matrix4.h"

namespace Ngl{


/**
 * @interface IMapMesh�D
 * @brief �}�b�v���b�V���C���^�[�t�F�[�X.
 */
class IMapMesh
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IMapMesh() {}


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �Ȃ�.
	 */
	virtual void loadFromStream( IInputStream& stream ) = 0;


	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^���쐬
	 * 
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature ) = 0;

	
	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] effect �G�t�F�N�g�̃|�C���^.
	 * @param[in] matProj 4x4�����ϊ��s��\���̂̎Q��.
	 * @param[in] matView 4x4����ϊ��s��\���̂̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void draw( IEffect* effect, const Matrix4& matProj, const Matrix4& matView ) = 0;

	
	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 ) = 0;


	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] rayPos ���C�̎n�_.
	 * @param[in] rayDir ���C�̕���.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir ) = 0;


	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius ) = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/