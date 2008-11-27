/*******************************************************************************/
/**
 * @file MshExCreator.h.
 * 
 * @brief Msh msh,mshex�`�����b�V���t�@�C���쐬�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/10/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MSH_MSHEXCREATOR_H_
#define _NGL_MSH_MSHEXCREATOR_H_

#include	"Ngl/IMeshCreator.h"


namespace Ngl{

// ���b�V���N���X
class Mesh;


namespace Msh{


/**
 * @class MshExCreator�D
 * @brief Msh msh,mshex�`�����b�V���t�@�C���ǂݍ��݃N���X.
 */
class MshExCreator : public IMeshCreator
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] renderer �����_���[.
	 */
	MshExCreator( IRenderer* renderer );

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~MshExCreator();

	
	/*=========================================================================*/
	/**
	 * @brief �t�@�C������쐬����
	 * 
	 * @param[in] fileName �t�@�C����.
	 * @return �쐬�������b�V���N���X.
	 */
	IMesh* createFromFile( std::string fileName );


	/*=========================================================================*/
	/**
	 * @brief ���̓X�g���[������쐬����
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�������b�V���N���X.
	 */
	IMesh* createFromStream( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`���쐬�N���X��ݒ�
	 * 
	 * @warning �ݒ肵���N���X��MshExCreator�N���X�ō폜����܂�.
	 *
	 * @param[in] creator �e�N�X�`���쐬�N���X�̃|�C���^.
	 * @return �Ȃ�.
	 */
	void setTextureCreator( ITextureCreator* creator );

private:

	/*=========================================================================*/
	/**
	 * @brief ���b�V���f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �Ȃ�.
	 */
	void loadMeshData( IInputStream& stream );
	
	
	/*=========================================================================*/
	/**
	 * @brief �}�e���A���f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] mesh ���b�V��.
	 * @return �Ȃ�.
	 */
	void loadMaterial( IInputStream& stream, Mesh* mesh );

	
	/*=========================================================================*/
	/**
	 * @brief �ʃf�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] mesh ���b�V��.
	 * @return �Ȃ�.
	 */
	void loadFaceGroup( IInputStream& stream, Mesh* mesh );

	
	/*=========================================================================*/
	/**
	 * @brief �C���f�b�N�X�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�����o�b�t�@.
	 */
	IBuffer* loadIndices( IInputStream& stream );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @param[in] numElements 1�v�f�̗v�f��.
	 * @return �쐬�����o�b�t�@.
	 */
	IBuffer* loadVertexBuffer( IInputStream& stream, unsigned int numElements );

	
	/*=========================================================================*/
	/**
	 * @brief ���_�E�F�C�g�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�����o�b�t�@.
	 */
	IBuffer* loadVertexWeight( IInputStream& stream );

	
	/*=========================================================================*/
	/**
	 * @brief �}�g���N�X�C���f�b�N�X�f�[�^��ǂݍ���
	 * 
	 * @param[in] stream ���̓X�g���[��.
	 * @return �쐬�����o�b�t�@.
	 */
	IBuffer* loadMatrixIndex( IInputStream& stream );


	/*=========================================================================*/
	/**
	 * @brief ���_�t�H�[�}�b�g��ݒ�
	 * 
	 * @param[in] mesh ���b�V��.
	 * @return �Ȃ�.
	 */
	void setVertexFormat( Mesh* mesh );

private:

	/** �f�[�^���������܂�Ă��Ȃ� */
	static const int NOTWRITTEN		= 0;

	/** �f�[�^���������܂�Ă��� */
	static const int WRITTEN		= 1;

	/** �e�N�X�`���f�[�^�����݂��邩 */
	static const int TEXTUREMAPPED	= 1 << 0;

	/** ���b�V���t���O�ő吔 */
	static const int MESHFLAG_MAX	= 8;

private:

	/**
	 * @enum MeshFlagType
	 * @brief ���b�V���t���O�^�C�v�񋓌^.
	 */
	enum MeshFlagType
	{
		MESHFLAGTYPE_VERTEX				= 0,	/**< ���_�f�[�^�����邩				*/
		MESHFLAGTYPE_NORMAL				= 1,	/**< �@���f�[�^�����邩				*/
		MESHFLAGTYPE_DIFFUSECOLORS		= 2,	/**< �g�U���ˌ��J���[�f�[�^�����邩	*/
		MESHFLAGTYPE_SPECULARCOLORS		= 3,	/**< ���ʔ��ˌ��J���[�f�[�^�����邩	*/
		MESHFLAGTYPE_NUMTEXCOORDS		= 4,	/**< �e�N�X�`�����W�f�[�^��			*/
		MESHFLAGTYPE_NUMWEIGHTS			= 5,	/**< ���_�E�F�C�g��					*/
		MESHFLAGTYPE_MATRIXINDICES		= 6,	/**< �s��C���f�b�N�X�f�[�^�����邩	*/
		MESHFLAGTYPE_TEXTURESPACE		= 7		/**< �e�N�X�`�����W�n�f�[�^�����邩	*/
	};

private:

	/** �����_���[ */
	IRenderer*			renderer_;

	/** �e�N�X�`���쐬�� */
	ITextureCreator*	textureCreator_;

	/** �e�N�X�`�����W�n�f�[�^�����邩	*/
	bool				hasTextureSpace_;

	/** �}�e���A���� */
	unsigned int		numMaterials_;

	/** �ʃf�[�^�� */
	unsigned int		numFaceGroups_;

	/** ���_�f�[�^�� */
	unsigned int		numVertices_;

	/** �C���f�b�N�X�f�[�^�� */
	unsigned int		numIndices_;

	/** ���_�E�F�C�g�� */
	unsigned int		numWeights_;

	/** ���b�V���t���O�z�� */
	unsigned int		meshFlag[ MESHFLAG_MAX ];

};

} // namespace Msh

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/