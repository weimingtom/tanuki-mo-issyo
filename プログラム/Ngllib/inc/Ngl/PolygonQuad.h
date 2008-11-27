/*******************************************************************************/
/**
 * @file PolygonQuad.h.
 * 
 * @brief �l�p�`�|���S���N���X�w�b�_�t�@�C��.
 *
 * @date 2008/08/06.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_POLYGONQUAD_H_
#define _NGL_POLYGONQUAD_H_

#include	"IRenderer.h"
#include	"Rect.h"
#include	<vector>

namespace Ngl{


/**
 * @class PolygonQuad�D
 * @brief �l�p�`�|���S���N���X.
 * @warning �C���f�b�N�X�̕��т͉E����W�n�ł��B
 */
class PolygonQuad
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	PolygonQuad();


	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~PolygonQuad();


	/*=========================================================================*/
	/**
	 * @brief �쐬����
	 * 
	 * @param[in] renderer �����_���[.
	 * @return �Ȃ�.
	 */
	void create( IRenderer* renderert );

	
	/*=========================================================================*/
	/**
	 * @brief �`�揈��
	 * 
	 * @param[in] renderer �����_���[.
	 * @param[in] effect �G�t�F�N�g.
	 * @return �Ȃ�.
	 */
	void draw( IRenderer* renderer, IEffect* effec );


	/*=========================================================================*/
	/**
	 * @brief �I������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void end();
	
	
	/*=========================================================================*/
	/**
	 * @brief �|���S���̋�`��ݒ�
	 * 
	 * @param[in] size ��`�l( ���[���h���W ).
	 * @return �Ȃ�.
	 */
	void setSize( const Rect& size );
	
	
	/*=========================================================================*/
	/**
	 * @brief �|���S���̋�`��ݒ�( 2D�X�v���C�g�p )
	 * 
	 * @param[in] size ��`�l( �X�N���[�����W ).
	 * @param[in] windowWidth �E�B���h�E�̕�.
	 * @param[in] windowHeight �E�B���h�E�̍���.
	 * @return �Ȃ�.
	 */
	void setSize2D( const Rect& size, int windowWidth, int windowHeight );


	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����W��ݒ肷��
	 *
	 * @param[in] srcRect ��`�l( ���[���h���W ).
	 * @return �Ȃ�.
	 */
	void setSrcRect( const Rect& srcRect );
	
	
	/*=========================================================================*/
	/**
	 * @brief �e�N�X�`�����W��ݒ肷��
	 *
	 * �X�N���[�����W���烏�[���h���W�֕ϊ����Đݒ肷��.
	 * 
	 * @param[in] srcRect ��`�l( �X�N���[�����W ).
	 * @param[in] width �e�N�X�`���̕�.
	 * @param[in] height �e�N�X�`���̍���.
	 * @return �Ȃ�.
	 */
	void setSrcRect( const Rect& srcRect, int width, int height );

private:

	/** ���_�X�g���[���z��^ */
	typedef std::vector< Ngl::VertexStreamDesc >	StreamArray;

private:

	/** ���_�o�b�t�@ */
	IBuffer*				vertexBuffer_;

	/** �C���f�b�N�X�o�b�t�@ */
	IBuffer*				indexBuffer_;

	/** �e�N�X�`�����W�o�b�t�@ */
	IBuffer*				texcoordBuffer_;

	/** �@���x�N�g���o�b�t�@ */
	IBuffer*				normalBuffer_;

	/** ���_�X�g���[���z�� */
	StreamArray				streamArray_;

	/** �폜�t���O */
	bool					isDeleted_;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/