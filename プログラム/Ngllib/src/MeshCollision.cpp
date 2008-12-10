/*******************************************************************************/
/**
 * @file MeshCollision.cpp.
 * 
 * @brief ���b�V���f�[�^�Փ˔���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/18.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/MeshCollision.h"
#include	<cassert>

using namespace Ngl;


/** ��Փ� */
const PlaneCollisionReport MeshCollision::NOT_COLLISION = PLANECOLLISIONREPORT_NOT_COLLISION;


/*===========================================================================*/
/**
 * @brief �Փ˔���f�[�^���쐬����
 *
 * @param[in] info ���b�V�����\���̂̎Q��.
 * @param[in] vertices ���_�o�b�t�@�f�[�^�̃|�C���^.
 * @param[in] indices �C���f�b�N�X�o�b�t�@�f�[�^�̃|�C���^
 * @return �Ȃ�.
 */
void MeshCollision::create( const MeshInfo& info, IBuffer* vertices, IBuffer* indices )
{
	assert( vertices != NULL );
	assert( indices != NULL );

	// �ʃf�[�^����ݒ�
	info_ = info;

	// ���łɕ��ʂ���������Ă���ꍇ�̓N���A����
	if( planeArray_.empty() == false ){
		planeArray_.clear();
	}

	// �z��̃T�C�Y��ݒ�
	planeArray_.resize( sizeof( Plane ) * ( info_.numIndices/ 3 ) );

	// ���_�f�[�^���擾
	vertices_.resize( sizeof( Vector3 ) * info_.numVertices );
	vertices->getData( (void*)&vertices_[ 0 ] );

	// �C���f�b�N�X�f�[�^���擾
	indices_.resize( sizeof( unsigned short ) * info_.numIndices );
	indices->getData( (void*)&indices_[ 0 ] );

	// �|���S�����쐬����
	for( unsigned int i=0; i<( info_.numIndices/3 ); i++ ){
		// �|���S����3���_���擾����
		planeArray_[i].createFromPoints(
			vertices_[ indices_[ i*3+0 ] ],
			vertices_[ indices_[ i*3+1 ] ],
			vertices_[ indices_[ i*3+2 ] ]
		);
	}
}



/*===========================================================================*/
/**
 * @brief �����Ƃ̏Փ˔���
 * 
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MeshCollision::line( const float* line0, const float* line1 )
{
	// ���ׂẴ|���S���Ɛ����Ƃ̏Փ˔�����s��
	for( unsigned int i=0; i<info_.numIndices/3; ++i ){
		const PlaneCollisionReport& param = polygonAndLine( i, line0, line1 );
		
		// �Փ˂��Ă�����
		if( param.isCollision == true ){
			return param;
		}
	}

	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief �w��̃|���S���Ɛ����Ƃ̏Փ˔���
 * 
 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @return �Փˌ��ʍ\���̂̎Q��.
 */
const PlaneCollisionReport& MeshCollision::polygonAndLine( int polygonNo, const float* line0, const float* line1 )
{
	// ���ʂ̃|���S���Ƃ͏Փ˔��肵�Ȃ�
	if( planeArray_[ polygonNo ].getClassifyPoint( line0 ) == Plane::BEHIND_PLANE ){
		return NOT_COLLISION;
	}

	// �|���S����3���_���擾����
	Vector3 vert[3];
	vert[0] = vertices_[ indices_[ polygonNo*3+0 ] ];
	vert[1] = vertices_[ indices_[ polygonNo*3+1 ] ];
	vert[2] = vertices_[ indices_[ polygonNo*3+2 ] ];

	// �|���S���Ɛ����̏Փ˔�����s��
	return collision_.polygonAndLine( vert, 3, planeArray_[polygonNo], line0, line1 );
}

	
	
/*===========================================================================*/
/**
 * @brief 3D���Ƃ̏Փ˔���
 * 
 * @param[in] rayPos 3D���̎n�_���W.
 * @param[in] rayDir 3D���̕���.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& MeshCollision::ray( const float* rayPos, const float* rayDir )
{
	// �S�|���S���ƃ��C�̏Փ˔��������
	for( unsigned int i=0; i<info_.numIndices/3; i++ ){
		const PlaneCollisionReport& param = polygonAndRay( i, rayPos, rayDir );
		
		// �Փ˂��Ă���
		if( param.isCollision == true ){
			return param;
		}
	}

	// �Փ˂��Ă��Ȃ�����
	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief �w��̃|���S����3D���Ƃ̏Փ˔���
 * 
 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
 * @param[in] rayPos 3D���̎n�_���W.
 * @param[in] rayDir 3D���̕���.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& MeshCollision::polygonAndRay( int polygonNo, const float* rayPos, const float* rayDir )
{
	// ���ʂ̃|���S���Ƃ͏Փ˔�������Ȃ�
	if( planeArray_[ polygonNo ].getClassifyPoint( rayPos ) == Plane::BEHIND_PLANE ){
		return NOT_COLLISION;
	}

	// �|���S����3���_���擾����
	Vector3 vert[3];
	vert[0] = vertices_[ indices_[ polygonNo*3+0 ] ];
	vert[1] = vertices_[ indices_[ polygonNo*3+1 ] ];
	vert[2] = vertices_[ indices_[ polygonNo*3+2 ] ];

	// �|���S���ƃ��C�̏Փ˔�����s��
	return collision_.polygonAndRay( vert, 3, planeArray_[ polygonNo ], rayPos, rayDir );
}

	
	
/*===========================================================================*/
/**
 * @brief ���̂Ƃ̏Փ˔���
 * 
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& MeshCollision::sphere( const float* center, float radius )
{
	// �S�|���S���Ƌ��̂Ƃ̏Փ˔�����s��
	for( unsigned int i = 0; i<info_.numIndices/3; i++ ){
		const PlaneCollisionReport& param = polygonAndSphere( i, center, radius );
		
		// �Փ˂��Ă�����
		if( param.isCollision == true ){
			return param;
		}
	}

	// �Փ˂��Ă��Ȃ�����
	return NOT_COLLISION;
}



/*===========================================================================*/
/**
 * @brief �w��̃|���S���Ƌ��̂Ƃ̏Փ˔���
 * 
 * @param[in] polygonNo �|���S���f�[�^�ԍ�.
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return �ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& MeshCollision::polygonAndSphere( int polygonNo, const float* center, float radius )
{
	// ���̂��|���S���ƌ������Ȃ������ׂ�
	if( planeArray_[ polygonNo ].getClassifySphere( center, radius ) != Plane::INTERSECTS_PLANE ){
		return NOT_COLLISION;
	}

	// �|���S����3���_���擾����
	Vector3 vert[3] = {
		vertices_[ indices_[ polygonNo*3+0 ] ],
		vertices_[ indices_[ polygonNo*3+1 ] ],
		vertices_[ indices_[ polygonNo*3+2 ] ]
	};

	// �|���S���Ƌ��̂��Փ˂��Ă��邩
	const PlaneCollisionReport& param = collision_.polygonAndSphere( vert, 3, planeArray_[ polygonNo ], center, radius );

	// �Փ˂��Ă��邩
	if( param.isCollision == true ){
		// �Փ˂��Ă���
		return param;
	}

	// �|���S���̃G�b�W�Ƌ��̂��Փ˂��Ă��邩
	return collision_.polygonEdgeAndSphere( vert, 3, center, radius );
}


	
/*===== EOF ==================================================================*/