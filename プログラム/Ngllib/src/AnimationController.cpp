/*******************************************************************************/
/**
 * @file AnimationController.cpp.
 * 
 * @brief �A�j���[�V��������҃N���X�\�[�X�t�@�C��.
 *
 * @date 2007/09/10.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationController.h"
#include	<cassert>

using namespace Ngl;


/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
  * @param[in] isDeleteInstance ���X�g����̍폜���ɃC���X�^���X��delete���邩.
 */
AnimationController::AnimationController( bool isDeleteInstance ):
	bindSkeletonID_( 0 ),					// �g�p����X�P���g��ID
	bindAnimationID_( 0 ),					// �g�p����A�j���[�V����ID
	isDeleteInstance_( isDeleteInstance )	// �C���X�^���X���폜���邩
{
	// �S�Ă̍s���P�ʍs��ɐݒ�
	for( int i=0; i<MATRIX_MAX; ++i ){
		transformMatrixArray_[ i ].setIdentitiy();
	}
}



/*===========================================================================*/
/**
 * @brief �f�X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
AnimationController::~AnimationController()
{
	// �������
	release();
}



/*===========================================================================*/
/**
 * @brief ���W�ϊ��s����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �ϊ��s��.
 */
Matrix4* AnimationController::transform()
{
	// �X�P���g���f�[�^���ݒ肳��Ă��邩
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true );

	// �X�P���g���̎p���ϊ��s������߂�
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		0,
		animationMatrixArray_
	);

	//�ŏI�I�ȍ��W�ϊ��s����쐬����
	skeletonManager_[ bindSkeletonID_ ]->calculateTransform(
		transformMatrixArray_,
		orientMatrixArray_
		);

	return transformMatrixArray_;
}



/*=========================================================================*/
/**
 * @brief ���W�ϊ��s����擾����
 * 
 * @param[in] parentMatrix �e�̕ϊ��s��.
 * @return �ϊ��s��z��.
 */
Matrix4* AnimationController::transform( const Matrix4& parentMatrix )
{
	// �X�P���g���f�[�^���ݒ肳��Ă��邩
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true );

	// �X�P���g���̎p���ϊ��s������߂�
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		&parentMatrix,
		animationMatrixArray_
	);

	//�ŏI�I�ȍ��W�ϊ��s����쐬����
	skeletonManager_[ bindSkeletonID_ ]->calculateTransform(
		transformMatrixArray_,
		orientMatrixArray_
		);

	return transformMatrixArray_;
}



/*=========================================================================*/
/**
 * @brief �X�P���g���f�[�^��ݒ肷��
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] data �ݒ肷��X�P���g���f�[�^�N���X.
 * @return �Ȃ�.
 */
void AnimationController::addSkeleton( unsigned int id, ISkeleton* data )
{
	assert( data != NULL );

	// ID�����łɑ��݂��Ă��邩
	if( isIDExist( id, skeletonManager_ ) == true ){
		// ID���폜
		eraseElement( id, skeletonManager_ );
	}

	// �w��ID�ɓo�^
	skeletonManager_[ id ] = data;
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V�����f�[�^��ݒ肷��
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] data �ݒ肷��X�P���g���f�[�^�N���X.
 * @return �Ȃ�.
 */
void AnimationController::addAnimation( unsigned int id, IAnimation* data )
{
	assert( data != NULL );

	// ID�����łɑ��݂��Ă��邩
	if( isIDExist( id, animationManager_ ) == true ){
		// ID���폜
		eraseElement( id, animationManager_ );
	}

	// �w��ID�ɓo�^
	animationManager_[ id ] = data;
}


	
/*===========================================================================*/
/**
 * @brief �X�P���g���t�@�C�����o�C���h����
 * 
 * @param[in] id �t�@�C��ID.
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */
bool AnimationController::bindSkeleton(unsigned int id)
{
	// ID�����݂��Ă��邩
	if( isIDExist( id, skeletonManager_ ) == true){
		// ID��ݒ肷��
		bindSkeletonID_ = id;

		return true;
	}

	return false;
}



/*===========================================================================*/
/**
 * @brief �A�j���[�V�����t�@�C�����o�C���h����
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] no �A�j���[�V����NO.
 * @param[in] fTime �A�j���[�V�����^�C�}.
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */	
bool AnimationController::bindAnimation(unsigned int id, unsigned int no, float fTime)
{
	// �A�j���[�V�����f�[�^�����݂��邩
	if( isIDExist( id, animationManager_ ) == false ){
		// �S�Ă�P�ʍs��ɐݒ肷��
		for( unsigned int boneNo=0; boneNo<MATRIX_MAX; boneNo++ ){
			animationMatrixArray_[boneNo].setIdentitiy();
		}
		return false;
	}

	// �A�j���[�V�����I�u�W�F�N�g���擾����
	IAnimation* tmpAnm = animationManager_[id];

	// �{�[���f�[�^�����擾����
	unsigned int numBones = tmpAnm->getNumBones( no );

	// �A�j���[�V�������o�C���h
	bindAnimation( id, no, fTime, 0, numBones-1 );

	return true;
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V�����t�@�C�����o�C���h����
 * 
 * @param[in] desc �A�j���[�V�����f�[�^�o�C���h�L�q�q.
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */
bool AnimationController::bindAnimation( const AnimationBindDesc& desc )
{
	return bindAnimation( desc.id, desc.no, desc.fTime );
}


	
/*===========================================================================*/
/**
 * @brief �A�j���[�V�����t�@�C�����o�C���h����(���`���)
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] no �A�j���[�V����NO.
 * @param[in] fTime �A�j���[�V�����^�C�}.
 * @param[in] otherId �⊮����v�f�̃t�@�C��ID.
 * @param[in] otherNo �⊮����v�f�̃A�j���[�V����NO
 * @param[in] otherFTimer �⊮����v�f�̃A�j���[�V�����^�C�}
 * @param[in] fLerp ��Ԓl
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */
bool AnimationController::bindAnimation
(
	unsigned int	id,
	unsigned int	no,
	float			fTime,
	unsigned int	otherId,
	unsigned int	otherNo,
	float			otherFTimer,
	float			fLerp
)
{
	// 1�̃A�j���[�V�����f�[�^�����݂��Ă��Ȃ���
	if( isIDExist( id, animationManager_ ) == false ){
		return false;
	}

	// 2�̃A�j���[�V�����f�[�^�����݂��Ă��Ȃ���
	if( isIDExist( id, animationManager_ ) == false ){
		// �A�j���[�V����1�̂݃o�C���h
		bindAnimation( id, no, fTime );
		return false;
	}

	// �{�[���f�[�^�����擾����
	unsigned int numBones = animationManager_[id]->getNumBones( no );

	// �A�j���[�V�����ϊ��s��ɐݒ肷��
	for( unsigned int BoneNo=0; BoneNo<numBones; BoneNo++ ){
		// �A�j���[�V����1�̃L�[�t���[���f�[�^���擾����
		KeyframeData data1;
		animationManager_[id]->getKeyFrame( no, BoneNo, fTime, data1 );

		// �A�j���[�V����2�̃L�[�t���[���f�[�^���擾����
		KeyframeData data2;
		animationManager_[id]->getKeyFrame( otherNo, BoneNo, otherFTimer, data2 );

		// �e�L�[����`�⊮����
		KeyframeData uni;
		uni.position.lerp( data1.position, data2.position, fLerp );
		uni.rotate.slerp( data1.rotate, data2.rotate, fLerp );
		uni.scale.lerp( data1.scale, data2.scale, fLerp );

		// �e�L�[���s��ɕϊ�����
		Matrix4 matScale;
		matScale.setScale( uni.scale );
		Matrix4 matRotate;
		matRotate.fromQuaternion( uni.rotate );
		animationMatrixArray_[ BoneNo ] = matScale * matRotate;
		animationMatrixArray_[ BoneNo ].setPosition( uni.position );
	}

	return true;
}


	
/*=========================================================================*/
/**
 * @brief �w��{�[���͈͂̃A�j���[�V�����f�[�^���o�C���h����
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] no �A�j���[�V����NO.
 * @param[in] fTime �A�j���[�V�����^�C�}.
 * @param[in] beginBoneNo �o�C���h�J�n�{�[���ԍ�.
 * @param[in] endBoneNo �o�C���h�I���{�[���ԍ�.
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */
bool AnimationController::bindAnimation( unsigned int id, unsigned int no, float fTime, unsigned int beginBoneNo, unsigned int endBoneNo )
{
	// �A�j���[�V�����I�u�W�F�N�g���擾����
	IAnimation* tmpAnm = animationManager_[id];

	// �A�j���[�V�����ϊ��s��ɐݒ肷��
	for( unsigned int boneNo=beginBoneNo; boneNo<=endBoneNo; boneNo++ ){
		// �L�[�t���[���f�[�^���擾����
		KeyframeData data;
		tmpAnm->getKeyFrame( no, boneNo, fTime, data );

		// �e�L�[���s��ɕϊ�����
		Matrix4 matScale;
		matScale.setScale( data.scale );
		Matrix4 matRotate;
		matRotate.fromQuaternion( data.rotate );

		// ���ʂ̍s����쐬
		Matrix4 tmp;

		// �e�L�[����Z����
		tmp = matScale * matRotate;

		// ���s�ړ��L�[��ݒ�
		tmp.setPosition( data.position );

		// �z��ɐݒ�
		animationMatrixArray_[ boneNo ] = tmp;
	}

	return true;
}
	
	
	
/*=========================================================================*/
/**
 * @brief �A�j���[�V�����t�@�C�����o�C���h����(���`���)
 * 
 * @param[in] desc �A�j���[�V�����f�[�^�o�C���h�L�q�q.
 * @param[in] otherDesc ��ԗv�f�̃A�j���[�V�����f�[�^�o�C���h�L�q�q.
 * @param[in] fLerp ��Ԓl
 * @retval true �o�C���h����.
 * @retval false �o�C���h���s.
 */
bool AnimationController::bindAnimation( const AnimationBindDesc& desc, const AnimationBindDesc& otherDesc, float fLerp )
{
	return bindAnimation(
		desc.id, desc.no, desc.fTime,
		otherDesc.id, otherDesc.no, otherDesc.fTime,
		fLerp
		);
}

	
	
/*===========================================================================*/
/**
 * @brief �w�肵��ID�̃X�P���g�����폜
 * 
 * @param[in] ID �X�P���g����ID.
 * @return �Ȃ�.
 */
void AnimationController::removeSkeleton(unsigned int ID)
{
	eraseElement( ID, skeletonManager_ );
}



/*===========================================================================*/
/**
 * @brief �w�肵��ID�̃A�j���[�V�������폜
 * 
 * @param[in] ID �A�j���[�V������ID.
 * @return �Ȃ�.
 */
void AnimationController::removeAnimation(unsigned int ID)
{
	eraseElement( ID, animationManager_ );
}



/*===========================================================================*/
/**
 * @brief ���ׂĂ�ID�̃X�P���g�����폜
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationController::clearSkeleton()
{
	clearElement( skeletonManager_ );
}
 

 
/*===========================================================================*/
/**
 * @brief ���ׂĂ�ID�̃A�j���[�V�������폜
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationController::clearAnimation()
{
	clearElement( animationManager_ );
}
	 
	 
	 
/*===========================================================================*/
/**
 * @brief �w��A�j���[�V�����̏I���^�C�}���擾����
 * 
 * @param[in] id �t�@�C��ID.
 * @param[in] no �A�j���[�V�����i���o�[.
 * @return �I���^�C�}.
 */
unsigned int AnimationController::getEndAnimationTimer(unsigned int id, unsigned int no)
{
	// ID�����݂��Ă��邩
	bool result = isIDExist( id, animationManager_ );
	assert( result == true );

	// �w��i���o�[�̏I���^�C�}�[���擾����
	return animationManager_[id]->getEndTimer( no );
}

	

/*===========================================================================*/
/**
 * @brief �X�L�����b�V���̎w��{�[���̈ʒu���W���擾����
 * 
 * @param[in] desc �擾����A�j���[�V�����f�[�^�o�C���h�L�q�q.
 * @param[in] skeletonID �X�P���g���f�[�^�ԍ�.
 * @param[in] boneNo �擾����{�[���ԍ�.
 * @param[in] trans ���W�ϊ��s��.
 * @return �ʒu���W.
 */
Vector3 AnimationController::getBoneCurrentPosition(const AnimationBindDesc& desc, unsigned int skeletonID, unsigned int boneNo, const Matrix4& trans)
{
	// �ʒu���W���쐬����
	Vector3 position;

	// �X�P���g�����o�C���h����
	bindSkeleton( skeletonID );

	// �A�j���[�V�������o�C���h����
	bindAnimation( desc.id, desc.no, desc.fTime );

	// �X�P���g���̎p���ϊ��s������߂�
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
			orientMatrixArray_,
			0,
			animationMatrixArray_
	);

	position.transform( orientMatrixArray_[ boneNo ] );

	// ���f�����O�ϊ�����
	position.transform( trans );

	return position;
}



/*===========================================================================*/
/**
 * @brief �X�P���g���̎p���ϊ��s����擾����
 * 
 * @param[in] �Ȃ�.
 * @return �ʒu���W.
 */
const Matrix4* AnimationController::getSkeletonOrientation(const Matrix4 &matrix)
{
	// �X�P���g���f�[�^��ݒ�
	bool result = isIDExist( bindSkeletonID_, skeletonManager_ );
	assert( result == true ); 	

	// �X�P���g���̎p���ϊ��s������߂�
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		orientMatrixArray_,
		&matrix,
		animationMatrixArray_
	);

	return orientMatrixArray_;
}



/*===========================================================================*/
/**
 * @brief �X�P���g���̎p���ϊ��s����v�Z����
 * 
 * @param[in] desc �A�j���[�V�����f�[�^�o�C���h�L�q�q.
 * @param[in] skeletonID �X�P���g���f�[�^�ԍ�.
 * @param[in] parentMatrix �e�̕ϊ��s��.
 * @param[out] matrix �v�Z���ʂ��i�[����s��z��
 * @return �Ȃ�.
 */
void AnimationController::calculateOrientation(const AnimationBindDesc &desc, unsigned int skeletonID, const Matrix4 &parentMatrix, Ngl::Matrix4 *matrix)
{
	bool result = true;	// ����

	// �X�P���g�����o�C���h����
	result = bindSkeleton( skeletonID );
	assert( result == true );

	// �A�j���[�V�������o�C���h����
	result = bindAnimation( desc.id, desc.no, desc.fTime );
	assert( result == true );
	
	// �p���ϊ��s����v�Z����
	skeletonManager_[ bindSkeletonID_ ]->calculateOrientation(
		matrix,
		&parentMatrix,
		animationMatrixArray_
	);
}



/*===========================================================================*/
/**
 * @brief �w��X�P���g���̃{�[�������擾����
 * 
 * @param[in] id �X�P���g��ID.
 * @return �{�[����.
 */
unsigned int AnimationController::getSkeletonNumBones(unsigned int id)
{
	// ID�����݂��Ă��邩
	if( isIDExist( id, skeletonManager_ ) == true ){
		return skeletonManager_[id]->getNumBones();
	}

	return 0;
}



/*===========================================================================*/
/**
 * @brief ����҂��������
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationController::release()
{
	// �S�ẴX�P���g���v�f���폜
	clearSkeleton();

	// �S�ẴA�j���[�V�����v�f���폜
	clearAnimation();
}



/*========= EOF =============================================================*/