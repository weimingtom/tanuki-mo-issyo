/*******************************************************************************/
/**
 * @file MeshCollision.h.
 * 
 * @brief ���b�V���f�[�^�Փ˔���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/18.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESHCOLLISION_H_
#define _NGL_MESHCOLLISION_H_

#include	"IMeshCollision.h"
#include	"IBuffer.h"
#include	"MeshInfo.h"
#include	"Collision.h"
#include	"Plane.h"
#include	"Vector3.h"
#include	<vector>

namespace Ngl{


/**
 * @class MeshCollision�D
 * @brief ���b�V���f�[�^�Փ˔���N���X.
 */
class MeshCollision : public IMeshCollision
{

public:

	/*===========================================================================*/
	/**
	 * @brief �Փ˔���f�[�^���쐬����
	 * 
	 * @param[in] info ���b�V�����\���̂̎Q��.
	 * @param[in] vertices ���_�o�b�t�@�f�[�^�̃|�C���^.
	 * @param[in] indices �C���f�b�N�X�o�b�t�@�f�[�^�̃|�C���^
	 * @return �Ȃ�.
	 */
	void create( const MeshInfo& info, IBuffer* vertices, IBuffer* indices );
	
	
	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& line( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S���Ɛ����Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& polygonAndLine( int polygonNo, const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���<b�w���r>
	 * 
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& ray( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S����3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& sphere( const float* center, float radius );


	/*===========================================================================*/
	/**
	 * @brief �w��̃|���S���Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& polygonAndSphere( int polygonNo, const float* center, float radius );

private:

	/** ��Փ� */
	static const PlaneCollisionReport NOT_COLLISION;

private:

	/** ���_�f�[�^�z��^ */
	typedef std::vector< Vector3 >			VertexArray;

	/** �C���f�b�N�X�f�[�^�z��^ */
	typedef std::vector< unsigned short >	IndexArray;

	/** ���ʏ��z��^ */
	typedef std::vector< Plane >			PlaneArray;

private:

	/** ���b�V����� */
	MeshInfo			info_;

	/** ���_�f�[�^�z�� */
	VertexArray			vertices_;

	/** �C���f�b�N�X�f�[�^�z�� */
	IndexArray			indices_;

	/** ���ʏ��z�� */
	PlaneArray			planeArray_;

	/** �Փ˔���N���X */
	Collision			collision_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/