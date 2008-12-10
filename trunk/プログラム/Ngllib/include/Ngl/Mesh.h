/*******************************************************************************/
/**
 * @file Mesh.h.
 * 
 * @brief ���b�V���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/09.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MESH_H_
#define _NGL_MESH_H_

#include	"Ngl/MeshCollision.h"
#include	"Ngl/IMesh.h"
#include	"Ngl/ITextureCreator.h"
#include	<map>
#include	<vector>
#include	<string>

namespace Ngl{


/**
 * @class Mesh.
 * @brief ���b�V���N���X.
 */
class Mesh : public IMesh
{
public:

	/**
	 * @struct VertexFormat.
	 * @brief ���_�t�H�[�}�b�g�\����.
	 */
	struct VertexFormat
	{
		/** ���_�� */
		unsigned int	numVertices;

		/** ���_�C���f�b�N�X�� */
		unsigned int	numIndices;

		/** ���_�E�F�C�g�� */
		unsigned int	numWeights;

		/** �s��C���f�b�N�X�������Ă��邩 */
		bool			hasMatrixIndices;

		/** �e�N�X�`�����W�n�f�[�^�������Ă��邩 */
		bool			hasTextureSpace;
	};

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] renderer �����_���[.
	 */
	Mesh( IRenderer* renderer );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~Mesh();


	/*=========================================================================*/
	/**
	 * @brief ���_�t�H�[�}�b�g��ݒ�
	 * 
	 * @param[in] format ���_�t�H�[�}�b�g�\����.
	 * @return �Ȃ�.
	 */
	void setVertexFormat( const VertexFormat& format );
	
	
	/*=========================================================================*/
	/**
	 * @brief �o�b�t�@�f�[�^��ݒ�
	 * 
	 * @warning �ݒ肵���o�b�t�@��Mesh�N���X�ō폜����܂��B
	 *
	 * @param[in] buf �ݒ肷��o�b�t�@�̃|�C���^.
	 * @param[in] type �ݒ肷��o�b�t�@�̃X�g���[���^�C�v.
	 * @return �Ȃ�.
	 */
	void setBuffer( IBuffer* buf, StreamType type );
	
	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@�f�[�^��ݒ�
	 * 
	 * @warning �ݒ肵���o�b�t�@��Mesh�N���X�ō폜����܂��B
	 *
	 * @param[in] buf �ݒ肷��o�b�t�@�̃|�C���^.
	 * @return �Ȃ�.
	 */
	void setIndexBuffer( IBuffer* buf );
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�e���A���f�[�^��ݒ�
	 * 
	 * Mesh�N���X�ɐݒ肵�����ԂŁA�}�e���A���ԍ��������I�ɐݒ肳��܂��B
	 *
	 * @warning �ݒ肵���}�e���A����Mesh�N���X�ō폜����܂��B
	 * @warning �e�N�X�`�����ݒ肳��Ă����ꍇ�́A�Ƃ��ɍ폜����܂��B
	 *
	 * @param[in] material �ݒ肷��}�e���A���̃|�C���^.
	 * @return �Ȃ�.
	 */
	void setMaterial( MeshMaterial* material );
	
	
	/*=========================================================================*/
	/**
	 * @brief �ʃf�[�^�O���[�v��ݒ�
	 * 
	 * Mesh�N���X�ɐݒ肵�����ԂŁA�ʃf�[�^�O���[�v�ԍ��������I�ɐݒ肳��܂��B
	 *
	 * @warning �ݒ肵���ʃf�[�^�O���[�v��Mesh�N���X�ō폜����܂��B
	 *
	 * @param[in] face �ݒ肷��ʃf�[�^�O���[�v�̃|�C���^.
	 * @return �Ȃ�.
	 */
	void setFaceGroup( FaceGroup* face );
	
	
	/*=========================================================================*/
	/**
	 * @brief �Փ˔���f�[�^���쐬����
	 *
	 * �ݒ肳��Ă��钸�_�o�b�t�@�ƃC���f�b�N�X�o�b�t�@����Փ˔���f�[�^���쐬���܂��B<br>
	 * �ǂ��炩�̃o�b�t�@�����ݒ肳��Ă��Ȃ��ꍇ�́A�쐬����܂���B<br>
	 *
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void createCollisionData();
	
	
	/*=========================================================================*/
	/**
	 * @brief �������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release();

public:
	
	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] effect �G�t�F�N�g�̃|�C���^.
	 * @return �Ȃ�.
	 */
	virtual void draw( IEffect* effect );

	
	/*=========================================================================*/
	/**
	 * @brief �T�u�Z�b�g��`��
	 * 
	 * @param[in] faceNo �ʃf�[�^�ԍ�.
	 * @param[in] effect �G�t�F�N�g.
	 * @return �Ȃ�.
	 */
	virtual void drawSubset( unsigned int faceNo, IEffect* effect );

	
	/*=========================================================================*/
	/**
	 * @brief ���b�V�������擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return ���b�V�����\����.
	 */
	virtual const MeshInfo& info() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�o�͋L�q�q���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �G�t�F�N�g�o�͋L�q�q.
	 */
	virtual const EffectOutputDesc& effectOutputDesc() const;
	
	
	/*=========================================================================*/
	/**
	 * @brief �G�t�F�N�g�o�͋L�q�q��ݒ�
	 * 
	 * @param[in] desc �G�t�F�N�g�o�͋L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void effectOutputDesc( const EffectOutputDesc& desc );
	

	/*=========================================================================*/
	/**
	 * @brief �w��ʃf�[�^���擾����
	 *
	 * @param[in] faceNo �擾����ʃf�[�^�ԍ�.
	 * @return �ʃf�[�^�\����.
	 */
	virtual const FaceGroup& getFaceGroups( unsigned int faceNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief �w�胁�b�V���}�e���A���f�[�^���擾����
	 *
	 * @param[in] matNo �擾���郁�b�V���}�e���A���ԍ�.
	 * @return ���b�V���}�e���A���\����.
	 */
	virtual const MeshMaterial& getMaterial( unsigned int matNo );
	
	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�o�b�t�@���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �C���f�b�N�X�o�b�t�@�|�C���^.
	 */
	virtual IBuffer* getIndexBuffer();
	
	
	/*=========================================================================*/
	/**
	 * @brief ���_�o�b�t�@���擾
	 * 
	 * @param[in] stream �擾����o�b�t�@�̎��.
	 * @return ���_�o�b�t�@�|�C���^.
	 */
	virtual IBuffer* getVertexBuffer( StreamType stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief ���_�錾�f�[�^���쐬
	 * 
	 * @param[in] inputSignature ���̓V�O�l�`���L�q�q�̎Q��.
	 * @return �Ȃ�.
	 */
	virtual void setVertexDeclaration( const InputSignatureDesc& inputSignature );

	
	/*===========================================================================*/
	/**
	 * @brief �����Ƃ̏Փ˔���
	 * 
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionLine( const float* line0, const float* line1 );


	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v�Ɛ����Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] line0 �����̎n�_.
	 * @param[in] line1 �����̏I�_.
	 * @return �Փˌ��ʍ\���̂̎Q��.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndLine( int faceNo, const float* line0, const float* line1 );

	
	/*===========================================================================*/
	/**
	 * @brief 3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionRay( const float* rayPos, const float* rayDir );


	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v��3D���Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] rayPos 3D���̎n�_���W.
	 * @param[in] rayDir 3D���̕���.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndRay( int faceNo, const float* rayPos, const float* rayDir );

	
	/*===========================================================================*/
	/**
	 * @brief ���̂Ƃ̏Փ˔���
	 * 
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionSphere( const float* center, float radius );


	/*===========================================================================*/
	/**
	 * @brief �w��̖ʃf�[�^�O���[�v�Ƌ��̂Ƃ̏Փ˔���
	 * 
	 * @param[in] faceNo �ʃf�[�^�O���[�v�ԍ�.
	 * @param[in] center ���̂̒��S�ʒu.
	 * @param[in] radius ���̂̔��a.
	 * @return �ʃf�[�^�Փ˃p�����[�^�[.
	 */
	virtual const PlaneCollisionReport& collisionFaceAndSphere( int faceNo, const float* center, float radius );

private:
	
	/*=========================================================================*/
	/**
	 * @brief ���_�X�g���[���f�[�^��ݒ�
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void setVertexStream();


	/*=========================================================================*/
	/**
	 * @brief �X�g���[���^�C�v��ݒ肷��
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void setStreamType();

	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���^�C�v����Z�}���e�B�b�N���擾
	 * 
	 * @param[in] type �X�g���[���^�C�v.
	 * @return �Ȃ�.
	 */
	VertexSemantic getSemantic( StreamType type );

	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���^�C�v���璸�_�Z�}���e�B�b�N���擾
	 * 
	 * @param[in] type �X�g���[���^�C�v.
	 * @return �Ȃ�.
	 */
	VertexType getType( StreamType type );

	
	/*=========================================================================*/
	/**
	 * @brief �X�g���[���^�C�v����1�v�f�̗v�f�����擾
	 * 
	 * @param[in] type �X�g���[���^�C�v.
	 * @return �Ȃ�.
	 */
	unsigned int getStride( StreamType type );

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ (�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	Mesh( const Mesh& other );


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h (�R�s�[�֎~)
	 * 
	 * @param[in] other �R�s�[���̃I�u�W�F�N�g.
	 * @return �R�s�[���ʂ̃I�u�W�F�N�g.
	 */
	Mesh& operator = ( const Mesh& other );	

private:

	// �o�b�t�@�f�[�^���X�g�^
	typedef std::map< StreamType, IBuffer* >	BufferList;

	// �}�e���A���f�[�^�z��^
	typedef std::vector< MeshMaterial* >		MaterialArray;

	// �ʃf�[�^�z��^
	typedef std::vector< FaceGroup* >			FaceGroupArray;

	/** �X�g���[���^�C�v�z��^ */
	typedef std::vector< StreamType >			StreamTypeArray;

	/** �X�g���[���L�q�q�z��^ */
	typedef std::vector< VertexStreamDesc >		StreamDescArray;

private:

	/** �����_���[�N���X�̃|�C���^ */
	IRenderer*			renderer_;

	/** ���b�V�����t���O */
	unsigned int		meshInfo_;

	/** �C���f�b�N�X�o�b�t�@ */
	IBuffer*			indexBuffer_;

	/** �o�b�t�@���X�g */
	BufferList			bufferList_;

	/** �}�e���A���f�[�^�z�� */
	MaterialArray		materialArray_;

	/** �ʃf�[�^�O���[�v�z�� */
	FaceGroupArray		faceGroupArray_;

	/** ���_�錾�f�[�^ */
	IVertexDeclaration*	vertexDeclaration_;

	/** �X�g���[���z�� */
	StreamTypeArray		streamTypeArray_;

	/** �X�g���[���L�q�q�z�� */
	StreamDescArray		streamDescArray_;

	/** ���b�V�����\���� */
	MeshInfo			info_;

	/** �G�t�F�N�g�o�͋L�q�q�\���� */
	EffectOutputDesc	effectOutputDesc_;

	/** ���b�V���Փ˔���N���X */
	MeshCollision		collision_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/