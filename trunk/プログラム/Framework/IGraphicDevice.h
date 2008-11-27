/*******************************************************************************/
/**
 * @file IGraphicDevice.h.<br>
 * 
 * @brief �O���t�B�b�N�f�o�C�X�C���^�[�t�F�[�X��`.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _IGRAPHICDEVICE_H_
#define _IGRAPHICDEVICE_H_

#include	"IEffectParameter.h"
#include	"QuadDesc.h"
#include	"SpriteDesc.h"
#include	"MeshDesc.h"
#include	"MeshSkinDesc.h"
#include	"LightDesc.h"
#include	"Define/Define.h"
#include	<Ngl/IRenderer.h>
#include	<string>

/**
 * @brief ���W�ϊ��s��^�C�v�񋓌^
 */
enum TransformType
{
	MAT_VIEW = 0,	/**< ����ϊ��s�� */
	MAT_PROJECTION	/**< �����ϊ��s�� */
};


/**
 * @brief �J���[�L�[�t���O
 */
enum ColorkeyFlag
{
	COLORKEYFLAG_NONE,	/**< �J���[�L�[�Ȃ�			*/
	COLORKEYFLAG_AUTO,	/**< �J���[�L�[�������Őݒ�	*/
	COLORKEYFLAG_USER	/**< �J���[�L�[�����[�U�ݒ�	*/
};


/**
 * @brief �O���t�B�b�N�f�o�C�X�C���^�[�t�F�[�X.
 */
class IGraphicDevice
{

protected:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~IGraphicDevice(){}

public:

	/**
	 * @brief �r���[�|�[�g�̐ݒ�<br>
	 * 
	 * @param[in] desc �r���[�|�[�g�L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void Viewport(const ViewportDesc& desc) = 0;

	
	/**
	 * @brief �r���[�|�[�g���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �r���[�|�[�g�L�q�q.
	 */
	virtual const ViewportDesc& Viewport() = 0;
	
	
	/**
	 * @brief ��ʂ�����<br>
	 * 
	 * @param[in] color ��������J���[.
	 * @return �Ȃ�.
	 */
	virtual void Clear( const Color4& color ) = 0;

	
	/**
	 * @brief �����ϊ��s���ݒ�<br>
	 * 
	 * @param[in] fov ����p.
	 * @param[in] aspect ��ʂ̃A�X�y�N�g��.
	 * @param[in] znear �߃N���b�v��.
	 * @param[in] zfar ���N���b�v��.
	 * @return �Ȃ�.
	 */
	virtual void Perspective(float fov, float aspect, float znear, float zfar) = 0;
	
	
	/**
	 * @brief ����ϊ��s���ݒ�<br>
	 * 
	 * @param[in] eye �n�_�ʒu.
	 * @param[in] at �����_�ʒu.
	 * @param[in] up ������̃x�N�g��
	 * @return �Ȃ�.
	 */
	virtual void LookAt(const Vector3& eye, const Vector3& at, const Vector3& up) = 0;

	
	/**
	 * @brief �w��̍��W�ϊ��s����擾<br>
	 * 
	 * @param[in] flag �擾������W�ϊ��s��̃t���O.
	 * @return �Ȃ�.
	 */
	virtual Matrix4 GetTransformMatrix(TransformType flag) = 0;

	
	/**
	 * @brief �l�p�`�|���S����`��<br>
	 * 
	 * @param[in] desc �l�p�`�|���S���L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void Render( const QuadDesc& desc ) = 0;
	
	
	/**
	 * @brief 2D�X�v���C�g��`��<br>
	 * 
	 * @param[in] desc �X�v���C�g�L�q�q.
	 * @return �Ȃ�.
	 */virtual void Render( const SpriteDesc& desc ) = 0;
	
	
	/**
	 * @brief ���b�V����ǂݍ���<br>
	 * 
	 * @param[in] id ���蓖�Ă郁�b�V�����\�[�XID.
	 * @param[in] filename ���b�V���t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void LoadMesh(unsigned int id, std::string filename) = 0;
	
	
	/**
	 * @brief ���b�V����`��<br>
	 * 
	 * @param[in] desc ���b�V���L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void Render(const MeshDesc& desc) = 0;
 
	
	/**
	 * @brief �w��ID�̃��b�V��������<br>
	 * 
	 * @param[in] id �������郁�b�V�����\�[�XID.
	 * @return �Ȃ�.
	 */
	virtual void RemoveMesh(unsigned int id) = 0;

	
	/**
	 * @brief ���ׂẴ��b�V��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearMesh() = 0;
	
	
	/**
	 * @brief �X�L�����b�V����`��<br>
	 * 
	 * @param[in] desc �X�L�����b�V���L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void Render(const MeshSkinDesc& desc) = 0;

	
	/**
	 * @brief �X�P���g���f�[�^��ǂݍ���<br>
	 * 
	 * @param[in] id ���蓖�Ă郊�\�[�XID.
	 * @param[in] filename �X�P���g���f�[�^�t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void LoadSkeleton(unsigned int id, std::string filename) = 0;

	
	/**
	 * @brief �w��ID�̃X�P���g��������<br>
	 * 
	 * @param[in] id ��������X�P���g��ID.
	 * @return �Ȃ�.
	 */
	virtual void RemoveSkeleton(unsigned int id) = 0;
	
	
	/**
	 * @brief �X�P���g����S��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearSkeleton() = 0;
	
	
	/**
	 * @brief �A�j���[�V�����f�[�^��ǂݍ���<br>
	 * 
	 * @param[in] if ���蓖�Ă郊�\�[�XID.
	 * @param[in] filename �A�j���[�V�����f�[�^�t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void LoadAnimation(unsigned int id, std::string filename) = 0;

	
	/**
	 * @brief �w��ID�̃A�j���[�V�����f�[�^������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void RemoveAnimation(unsigned int id) = 0;

	
	/**
	 * @brief �A�j���[�V�����f�[�^��S����<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearAnimation() = 0;

	
	/**
	 * @brief �X�P���g���f�[�^�ƃA�j���[�V�����f�[�^�̍����s����擾<br>
	 * 
	 * @param[in] sklID �X�P���g��ID.
	 * @param[in] anmID �A�j���[�V����ID.
	 * @param[in] anmNo �A�j���[�V�����ԍ�.
	 * @param[in] anmTimer �A�j���[�V�����^�C�}�[.
	 * @return ���������s��z��.
	 */
	virtual Matrix4* CalculateBoneMatrices( unsigned int sklID, unsigned int anmID, unsigned int anmNo, float anmTimer ) = 0;
	
	
	/**
	 * @brief �e�N�X�`����ǂݍ���<br>
	 * 
	 * @param[in] id ���蓖�Ă郊�\�[�XID.
	 * @param[in] filename �e�N�X�`���t�@�C����.
	 * @param[in] colorkeyFlag �J���[�L�[�t���O.
	 * @param[in] colorkey �J���[�L�[.
	 * @return �Ȃ�.
	 */
	virtual void LoadTexture( unsigned int id, std::string filename, ColorkeyFlag colorkeyFlag=COLORKEYFLAG_NONE, Color4 colorkey=Color4( 0.0f, 0.0f, 0.0f, 1.0f ) ) = 0;
	
	
	/**
	 * @brief �e�N�X�`�����쐬<br>
	 * 
	 * @param[in] id ���蓖�Ă�e�N�X�`��ID.
	 * @param[in] desc �e�N�X�`���쐬�L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void CreateTexture( unsigned int id, const TextureDesc& desc ) = 0;

	
	/**
	 * @brief �w��ID�̃e�N�X�`��������<br>
	 * 
	 * @param[in] id ��������e�N�X�`��ID.
	 * @return �Ȃ�.
	 */
	virtual void RemoveTexture( unsigned int id ) = 0;

	
	/**
	 * @brief �e�N�X�`����S��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearTexture() = 0;
	
	
	/**
	 * @brief �e�N�X�`���L�q�q���擾<br>
	 * 
	 * @param[in] id �L�q�q���擾����e�N�X�`����ID.
	 * @return �e�N�X�`���L�q�q.
	 */
	virtual const TextureDesc& GetTextureDesc( unsigned int id ) = 0;
	
	
	/**
	 * @brief �e�N�X�`���������_�[�^�[�Q�b�g�ɐݒ�<br>
	 * 
	 * @param[in] renderTexID �����_�[�^�[�Q�b�g�Ƃ��Ďg�p����e�N�X�`��ID.
	 * @param[in] depthTexID �f�v�X�X�e���V���o�b�t�@�Ƃ��Ďg�p����e�N�X�`��ID.
	 * @return �Ȃ�.
	 */
	virtual void SetRenderTarget( unsigned int renderTexID, unsigned int depthTexID ) = 0;

	
	/**
	 * @brief �����_�[�^�[�Q�b�g�����ɖ߂�<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ResetRenderTarget() = 0;

	
	/**
	 * @brief �G�t�F�N�g�f�[�^��ǂݍ���<br>
	 * 
	 * @param[in] id ���蓖�Ă郊�\�[�XID.
	 * @param[in] filename �G�t�F�N�g�t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void LoadEffect(unsigned int id, std::string filename) = 0;
	
	
	/**
	 * @brief �w��ID�̃G�t�F�N�g����������<br>
	 * 
	 * @param[in] id ��������G�t�F�N�gID.
	 * @return �Ȃ�.
	 */
	virtual void RemoveEffect(unsigned int id) = 0;		
	
	
	/**
	 * @brief �G�t�F�N�g��S��������<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearEffect() = 0;
	
	
	/**
	 * @brief �G�t�F�N�g�p�����[�^���擾<br>
	 * 
	 * @param[in] id �p�����[�^���擾����G�t�F�N�gID.
	 * @return �G�t�F�N�g�p�����[�^.
	 */
	virtual IEffectParameter& GetEffectVariable( unsigned int id ) = 0;

	
	/**
	 * @brief �G�t�F�N�g�Ƀe�N�X�`����ݒ�<br>
	 * 
	 * @param[in] effectID �e�N�X�`����ݒ肷��G�t�F�N�gID.
	 * @param[in] texID �ݒ肷��e�N�X�`��ID.
	 * @return �Ȃ�.
	 */
	virtual void SetTextureToEffect( unsigned int effectID, unsigned int texID, std::string paramName ) = 0;

	
	/**
	 * @brief �I�N�c���[�f�[�^��ǂݍ���<br>
	 * 
	 * @param[in] id ���蓖�Ă郊�\�[�XID.
	 * @param[in] filename �I�N�c���[�t�@�C����.
	 * @return �Ȃ�.
	 */
	virtual void LoadOctree( unsigned int id, const std::string& filename ) = 0;
	
	
	/**
	 * @brief �I�N�c���[�f�[�^��`�悷��<br>
	 * 
	 * @param[in] desc �I�N�c���[�L�q�q.
	 * @return �Ȃ�.
	 */
	virtual void RenderOctree( const MeshDesc& desc ) = 0;
	
	
	/**
	 * @brief �w��̃I�N�c���[�f�[�^���폜<br>
	 * 
	 * @param[in] id �폜���郊�\�[�XID.
	 * @return �Ȃ�.
	 */
	virtual void RemoveOctree( unsigned int id ) = 0;


	/**
	 * @brief �I�N�c���[�f�[�^�����ׂč폜<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual void ClearOctree() = 0;
	
	
	/**
	 * @brief ���\�[�X�����ׂč폜����
	 *
	 * @param[in] �Ȃ�
	 * @return	�Ȃ�
	 */
	virtual void ClearResource() = 0;

	
	/**
	 * @brief �����_���[�N���X���擾<br>
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	virtual Ngl::IRenderer& Renderer() = 0;


	/**
	 * @brief �X�P���g���̎p���ϊ��s����v�Z����
	 *
	 * @param[in] desc �X�L�����b�V���L�q�q
	 * @param[in] parentMatrix �e�̕ϊ��s��
	 * @param[in] matrices �v�Z���ʂ��i�[����s��z��ւ̃|�C���^
	 * @return	�Ȃ�
	 */
	virtual void CalculateOrientation( const MeshSkinDesc& desc, const Matrix4& parentMatrix, Matrix4* matrices ) = 0;


	/**
	 * @brief �w��A�j���[�V�����̏I���^�C�����擾����
	 *
	 * @param[in] id �A�j���[�V����ID
	 * @param[in] no �A�j���[�V�����ԍ�
	 * @return	�I���^�C��
	 */
	virtual unsigned int GetAnimationEndTime( unsigned int id, unsigned int no ) = 0;

	
	/**
	 * @brief ���C�g���擾����<br>
	 * 
	 * @param[in] index ���C�g�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual const LightDesc& GetLight( unsigned int index ) = 0;


	/**
	 * @brief ���C�g���擾����<br>
	 * 
	 * @param[in] index ���C�g�ԍ�.
	 * @return �Ȃ�.
	 */
	virtual void SetLight( unsigned int index, const LightDesc& desc ) = 0;

};

#endif

/*========= End of File =====================================================*/