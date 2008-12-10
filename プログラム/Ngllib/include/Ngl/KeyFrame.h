/*******************************************************************************/
/**
 * @file KeyFrame.h.
 * 
 * @brief �A�j���[�V�����L�[�t���[�����N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/16.
 * 
 * @version 1.00.
 * 
 * @author Kentaru Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_KEYFRAME_H_
#define _NGL_KEYFRAME_H_

#include	"Ngl/IKeyframe.h"
#include	<vector>

namespace Ngl{


/**
 * @struct ScaleKey.
 * @brief �g��k���L�[�\����.
 */
struct ScaleKey
{
	/** �t���[���^�C�} */
	unsigned int	frameTimer;

	/** �L�[�l */
	Vector3			value;
};


/**
 * @struct RotateKey.
 * @brief ��]�L�[�\����.
 */
struct RotateKey
{
	/** �t���[���^�C�} */
	unsigned int	frameTimer;

	/** �L�[�l */
	Quaternion		value;
};


/** 
 * @struct PositionKey.
 * @brief ���s�ړ��L�[�\����.
 */
struct PositionKey
{
	/** �t���[���^�C�} */
	unsigned int	frameTimer;

	/** �L�[�l */
	Vector3			value;
};


/**
 * @class KeyFrame
 * @brief �A�j���[�V�����L�[�t���[���N���X�D
 */
class KeyFrame : public IKeyframe
{	

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	KeyFrame();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~KeyFrame();


	/*=========================================================================*/
	/**
	 * @brief �g��k���L�[��ǉ�
	 * 
	 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
	 *
	 * @param[in] key �ݒ肷��L�[.
	 * @return �Ȃ�.
	 */
	void addKey( ScaleKey* key );


	/*=========================================================================*/
	/**
	 * @brief ��]�L�[��ǉ�
	 * 
	 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
	 *
	 * @param[in] key �ݒ肷��L�[.
	 * @return �Ȃ�.
	 */
	void addKey( RotateKey* key );


	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��L�[��ǉ�
	 * 
	 * @warning �ݒ肳�ꂽ�L�[��KeyFrame�N���X�ō폜����܂�.
	 *
	 * @param[in] key �ݒ肷��L�[.
	 * @return �Ȃ�.
	 */
	void addKey( PositionKey* key );
	
public:

	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[���f�[�^�̎擾
	 * 
	 * @param[in] globalTime �擾����L�[�̃^�C�}.
	 * @param[out] data �L�[�t���[���f�[�^.
	 * @return �L�[�t���[���f�[�^.
	 */
	virtual KeyframeData& getKey( float globalTime, KeyframeData& data );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w��̊g��k���L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no �g��k���L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getScaleKeyFrameTime( unsigned int no ) const;


	/*=========================================================================*/
	/**
	 * @brief �w��̉�]�L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no ��]�L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getRotateKeyFrameTime( unsigned int no ) const;


	/*=========================================================================*/
	/**
	 * @brief �w��̕��s�ړ��L�[�̃t���[���^�C�����擾����
	 * 
	 * @param[in] no ���s�ړ��L�[�ԍ�.
	 * @return �t���[���^�C�}.
	 */
	virtual unsigned int getPositionKeyFrameTime( unsigned int no ) const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �g��k���L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �g��k���L�[��.
	 */
	virtual unsigned int getNumScaleKeys() const;


	/*=========================================================================*/
	/**
	 * @brief ��]�L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ��]�L�[��.
	 */
	virtual unsigned int getNumRotateKeys() const;
	

	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��L�[�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���s�ړ��L�[��.
	 */
	virtual unsigned int getNumPositionKeys() const;

private:

	/*=========================================================================*/
	/**
	 * @brief �L�[�t���[�������J������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();


	/*=========================================================================*/
	/**
	 * @brief �g��k���L�[���擾����
	 * 
	 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
	 * @param[out] ret �擾�����L�[.
	 * @return ���s�ړ��L�[��.
	 */
	void getScaleKeys( float globalTime, Vector3& ret );
	
	
	/*=========================================================================*/
	/**
	 * @brief ��]�L�[���擾����
	 * 
	 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
	 * @param[out] ret �擾�����L�[.
	 * @return ���s�ړ��L�[��.
	 */
	void getRotateKeys( float globalTime, Quaternion& ret );

	
	/*=========================================================================*/
	/**
	 * @brief ���s�ړ��L�[���擾����
	 * 
	 * @param[in] globalTime �擾����L�[�̃t���[���^�C��.
	 * @param[out] ret �擾�����L�[.
	 * @return ���s�ړ��L�[��.
	 */
	void getPositionKeys( float globalTime, Vector3& ret );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 * @return �Ȃ�.
	 */
	KeyFrame( const KeyFrame& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h(�R�s�[�֎~)
	 * 
	 * @param[in] other ������邷��I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	KeyFrame& operator = ( const KeyFrame& other );

private:

	/** �g��k���L�[�z��^ */
	typedef std::vector< ScaleKey* >	ScaleKeyArray;

	/** ��]�L�[�z��^ */
	typedef std::vector< RotateKey* >	RotateKeyArray;

	/** ���s�ړ��L�[�z��^ */
	typedef std::vector< PositionKey* >	PositionKeyArray;

private:

	/** �g��k���L�[�z��ւ̃|�C���^ */
	ScaleKeyArray		scaleKeys_;

	/** ��]�L�[�z��ւ̃|�C���^ */
	RotateKeyArray		rotateKeys_;

	/** ���s�ړ��L�[�z��ւ̃|�C���^ */
	PositionKeyArray	positionKeys_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/