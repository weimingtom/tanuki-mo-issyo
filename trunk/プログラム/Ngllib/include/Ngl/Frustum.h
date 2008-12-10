/*******************************************************************************/
/**
 * @file Frustum.h.
 * 
 * @brief ������N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FRUSTUM_H_
#define _NGL_FRUSTUM_H_

#include	"Plane.h"

namespace Ngl{


// 3�����x�N�g���\���̂̑O���Q��
struct Vector3;

// �s��\���̂̑O���Q��
struct Matrix4;


/**
 * @class Frustum.
 * @brief ������N���X�D
 */
class Frustum
{

public:

	/*=========================================================================*/
	/**
	 * @brief ����ϊ��s��A�����ϊ��s�񂩂王������쐬����
	 * 
	 * @param[in] view ����ϊ��s��.
	 * @param[in] proj �����ϊ��s��.
	 * @return �Ȃ�.
	 */
	void createFromMatrices( const Matrix4& view, const Matrix4& proj );


	/*=========================================================================*/
	/**
	 * @brief �_����������ɑ��݂��邩���ׂ�
	 * 
	 * @param[in] point ���ׂ�_.
	 * @retval true ���݂��Ă���,
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isPointInside( const Vector3& point );


	/*=========================================================================*/
	/**
	 * @brief �{�b�N�X����������ɂ��邩���ׂ�
	 * 
	 * @param[in] p1 �{�b�N�X�̍��W1.
	 * @param[in] p2 �{�b�N�X�̍��W2.
	 * @retval true ���݂��Ă���.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isBoxInside( const Vector3& p1, const Vector3& p2 );


	/*=========================================================================*/
	/**
	 * @brief ���̂���������ɂ��邩���ׂ�
	 * 
	 * @param[in] center ���̂̒��S���W.
	 * @param[in] radius ���̂̔��a.
	 * @retval true ���݂��Ă���.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isSphereInside( const Vector3& center, float radius );

public:

	/**
	 * @enum Frustum::ClipingPlane.
	 * @brief �N���b�s���O�v���[���񋓌^.
	 */
	enum ClipingPlane
	{
		CLIP_PLANE_LEFT = 0,	/**< ������			*/
		CLIP_PLANE_RIGHT,		/**< �E����			*/
		CLIP_PLANE_TOP,			/**< �㑤��			*/
		CLIP_PLANE_BOTTOM,		/**< ������			*/
		CLIP_PLANE_NEAR,		/**< �߃N���b�v��	*/
		CLIP_PLANE_FAR			/**< ���N���b�v��	*/
	};

private:

	/** �����䕽�ʔz�� */
	Plane	mPlanes[6];

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/