/*******************************************************************************/
/**
 * @file AnimationController.h.
 * 
 * @brief �A�j���[�V��������N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONCONTROLLER_H_
#define _NGL_ANIMATIONCONTROLLER_H_

#include	"Ngl/ISkeleton.h"
#include	"Ngl/IAnimation.h"
#include	"Ngl/Matrix4.h"
#include	<map>

namespace Ngl{


/**
 * @struct AnimationBindDesc�D
 * @brief �A�j���[�V�����f�[�^�o�C���h�L�q�q.
 */
struct AnimationBindDesc
{
	/** �o�C���h����A�j���[�V�����f�[�^ID */
	unsigned int	id;

	/** �A�j���[�V�����ԍ� */
	unsigned int	no;

	/** �A�j���[�V�����̕`��t���[���^�C�� */
	float			fTime;
};


/**
 * @class AnimationController.
 * @brief �A�j���[�V��������҃N���X�D
 */
class AnimationController
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] isDeleteInstance ���X�g����̍폜���ɃC���X�^���X��delete���邩.
	 */
	AnimationController( bool isDeleteInstance=true );


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~AnimationController();


	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ��s����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ϊ��s��z��.
	 */
	Matrix4* transform();
	
	
	/*=========================================================================*/
	/**
	 * @brief ���W�ϊ��s����擾����
	 * 
	 * @param[in] parentMatrix�@�e�̕ϊ��s��.
	 * @return �ϊ��s��z��.
	 */
	Matrix4* transform( const Matrix4& parentMatrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�P���g���f�[�^��ݒ肷��
	 * 
	 * @param[in] id �t�@�C��ID.
	 * @param[in] data �ݒ肷��X�P���g���f�[�^�N���X.
	 * @return �Ȃ�.
	 */
	void addSkeleton( unsigned int id, ISkeleton* data );


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����f�[�^��ݒ肷��
	 * 
	 * @param[in] id �t�@�C��ID.
	 * @param[in] data �ݒ肷��X�P���g���f�[�^�N���X.
	 * @return �Ȃ�.
	 */
	void addAnimation( unsigned int id, IAnimation* data );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�P���g���t�@�C�����o�C���h����
	 * 
	 * @param[in] id �t�@�C��ID.
	 * @retval true �o�C���h����.
	 * @retval false �o�C���h���s.
	 */
	bool bindSkeleton( unsigned int id );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w�肵��ID�̃X�P���g�����폜
	 * 
	 * @param[in] ID �X�P���g����ID.
	 * @return �Ȃ�.
	 */
	 void removeSkeleton( unsigned int ID );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief ���ׂĂ�ID�̃A�j���[�V�������폜
	 * 
	 * @param[in] ID �A�j���[�V������ID.
	 * @return �Ȃ�.
	 */
	 void removeAnimation( unsigned int ID );
	 
	 
	/*=========================================================================*/
	/**
	 * @brief ���ׂĂ�ID�̃X�P���g�����폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	 void clearSkeleton();
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �w�肵��ID�̃A�j���[�V�������폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	 void clearAnimation();
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����t�@�C�����o�C���h����
	 * 
	 * @param[in] id �t�@�C��ID.
	 * @param[in] no �A�j���[�V����NO.
	 * @param[in] fTime �A�j���[�V�����^�C�}.
	 * @retval true �o�C���h����.
	 * @retval false �o�C���h���s.
	 */
	bool bindAnimation( unsigned int id, unsigned int no, float fTime );
	
	
	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V�����t�@�C�����o�C���h����
	 * 
	 * @param[in] desc �A�j���[�V�����f�[�^�o�C���h�L�q�q.
	 * @retval true �o�C���h����.
	 * @retval false �o�C���h���s.
	 */
	bool bindAnimation( const AnimationBindDesc& desc );
		
	
	/*=========================================================================*/
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
	bool bindAnimation(
		unsigned int	id,
		unsigned int	no,
		float			fTime,
		unsigned int	otherId,
		unsigned int	otherNo,
		float			otherFTimer,
		float			fLerp
		);
	
	
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
	bool bindAnimation( unsigned int id, unsigned int no, float fTime, unsigned int beginBoneNo, unsigned int endBoneNo );

	
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
	bool bindAnimation( const AnimationBindDesc& desc, const AnimationBindDesc& otherDesc, float fLerp );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��A�j���[�V�����̏I���^�C�}���擾����
	 * 
	 * @param[in] id �t�@�C��ID.
	 * @param[in] no �A�j���[�V�����i���o�[.
	 * @return �I���^�C�}.
	 */
	unsigned int getEndAnimationTimer( unsigned int id, unsigned int no );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�L�����b�V���̎w��{�[���̈ʒu���W���擾����
	 * 
	 * @param[in] desc �擾����A�j���[�V�����f�[�^�o�C���h�L�q�q.
	 * @param[in] skeletonID �X�P���g���f�[�^�ԍ�.
	 * @param[in] boneNo �擾����{�[���ԍ�.
	 * @param[in] trans ���W�ϊ��s��.
	 * @return �ʒu���W.
	 */
	Vector3 getBoneCurrentPosition( const AnimationBindDesc& desc, unsigned int skeletonID, unsigned int boneNo, const Matrix4& trans );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�P���g���̎p���ϊ��s����擾����
	 * 
	 * @param[in] matrix �e�̕ϊ��s��.
	 * @return �ʒu���W.
	 */
	const Matrix4* getSkeletonOrientation( const Matrix4& matrix );

	
	/*=========================================================================*/
	/**
	 * @brief �X�P���g���̎p���ϊ��s����v�Z����
	 * 
	 * @param[in] desc �A�j���[�V�����f�[�^�o�C���h�L�q�q.
	 * @param[in] skeletonID �X�P���g���f�[�^�ԍ�.
	 * @param[in] parentMatrix �e�̕ϊ��s��.
	 * @param[out] matrix �v�Z���ʂ��i�[����s��z��
	 * @return �Ȃ�.
	 */
	void calculateOrientation( const AnimationBindDesc& desc, unsigned int skeletonID, const Matrix4& parentMatrix, Matrix4* matrix );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��X�P���g���̃{�[�������擾����
	 * 
	 * @param[in] id �X�P���g��ID.
	 * @return �{�[����.
	 */
	unsigned int getSkeletonNumBones( unsigned int id );
	
		
	/*=========================================================================*/
	/**
	 * @brief ����҂��������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �Ǘ��҂Ɏw���ID�����݂��邩��������
	 * 
	 * @param[in] id ID.
	 * @param[in] manager �Ǘ���.
	 * @retval true ���݂���.
	 * @retval false ���݂��Ȃ�.
	 */
	 template< typename Manager >
	 bool isIDExist( unsigned int id, Manager& manager ){
		 // ID�����łɐݒ肳��Ă��邩
		Manager::iterator i = manager.find( id );
		if( i != manager.end() ){
			// �h�c���ݒ肳��Ă���
			return true;
		}

		// ���݂��Ă��Ȃ�
		return false;
	 }
	 
	 
	/*=========================================================================*/
	/**
	 * @brief �Ǘ��҂���w��ID�̗v�f���폜����
	 * 
	 * @param[in] id ID.
	 * @param[in] manager �Ǘ���.
	 * @return �Ȃ�.
	 */
	 template< typename Manager >
	 void eraseElement( unsigned int id, Manager& manager )
	 {
		Manager::iterator itor;
		for( itor = manager.begin(); itor!=manager.end(); ++itor ){
			if( itor->first == id ){
				if( isDeleteInstance_ ){
					// ���X�g����폜
					delete (*itor).second;
				}
				manager.erase( itor );

				break;
			}
		}
	 }


	/*=========================================================================*/
	/**
	 * @brief �Ǘ��҂��炷�ׂĂ̗v�f���폜����
	 * 
	 * @param[in] manager �Ǘ���.
	 * @return �Ȃ�.
	 */
	 template< typename Manager >
	 void clearElement( Manager& manager )
	 {
		Manager::iterator itor = manager.begin();
		while( itor != manager.end() ){
			if( isDeleteInstance_ ){
				delete (*itor).second;
			}
			itor = manager.erase( itor );
		}
	 }

 private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^�i�R�s�[�֎~�j
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	AnimationController( const AnimationController& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h�i�R�s�[�֎~�j
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	AnimationController& operator = ( const AnimationController& other );

public:

	/** �s��̍ő吔 */
	static const unsigned int MATRIX_MAX = 1024;

private:

	/** �X�P���g���Ǘ��҂̌^ */
	typedef std::map< unsigned int, ISkeleton* >		SkeletonManager;

	/** �A�j���[�V�����Ǘ��Ҍ^ */
	typedef std::map< unsigned int, IAnimation* >		AnimationManager;

private:

	/** �C���X�^���X���폜���邩 */
	bool				isDeleteInstance_;

	/** �g�p����X�P���g��ID */
	unsigned int		bindSkeletonID_;

	/** �g�p����A�j���[�V����ID */
	unsigned int		bindAnimationID_;
	
	/** �X�P���g���Ǘ��� */
	SkeletonManager		skeletonManager_;
	
	/** �A�j���[�V�����Ǘ��� */
	AnimationManager	animationManager_;

	/** �A�j���[�V�����ϊ��s��z�� */
	Matrix4				animationMatrixArray_[ MATRIX_MAX ];

	/** �p���ϊ��s��z�� */
	Matrix4				orientMatrixArray_[ MATRIX_MAX ];

	/** ���W�ϊ��s��z�� */
	Matrix4				transformMatrixArray_[ MATRIX_MAX ];

};

}	// namespace Ngl

#endif

/*===== EOF ==================================================================*/