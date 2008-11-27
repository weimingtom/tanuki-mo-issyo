/*******************************************************************************/
/**
 * @file AnimationRect.h.
 * 
 * @brief �A�j���[�V������`�N���X�w�b�_�t�@�C��.
 *
 * @date 2008/08/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ANIMATIONRECT_H_
#define _NGL_ANIMATIONRECT_H_

#include	"Rect.h"

namespace Ngl{


/**
 * @struct AnimationRectDesc.
 * @brief �A�j���[�V������`�L�q�q�\����.
 *
 * �p�����[�^�̐ݒ�Ɏg�p����L�q�q�ł�.
 */
struct AnimationRectDesc
{
	/** �S�̂̕�( �X�N���[�����W ) */
	int			totalWidth;

	/** �S�̂̍���( �X�N���[�����W ) */
	int			totalHeight;

	/** �C���[�W1���̕�( �X�N���[�����W ) */
	int			imageWidth;

	/** �C���[�W1���̍���( �X�N���[�����W ) */
	int			imageHeight;

	/** �C���[�W�̉����� */
	int			imageCountColumns;

	/** �C���[�W�̏c���� */
	int			imageCountRows;

	/** ���ׂẴC���[�W��`�悷��̂ɂ����鎞�� */
	int			timer;

	/** ���[�v���邩 */
	bool		loop;


	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�
	 */
	AnimationRectDesc():
		totalWidth( 1 ),
		totalHeight( 1 ),
		imageWidth( 1 ),
		imageHeight( 1 ),
		imageCountColumns( 1 ),
		imageCountRows( 1  ),
		timer( 1 ),
		loop( true )
	{}
};


/**
 * @class AnimationRect�D
 * @brief �A�j���[�V������`�N���X.
 *
 * �A�j���[�V�����p�̋�`�l�𐶐�����N���X�ł��B
 * �r�f�I�e�N�X�`���Ȃǂ��A�j���[�V���������邽�߂̃e�N�X�`�����W�Ƃ��ė��p�ł��܂��B
 */
class AnimationRect
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @oaram[in] �Ȃ�
	 */
	AnimationRect();


	/*=========================================================================*/
	/**
	 * @brief �J�n����
	 *
	 * @param[in] desc �A�j���[�V������`�L�q�q.
	 * @return �Ȃ�.
	 */
	void begin( const AnimationRectDesc& desc );
	
	
	/*=========================================================================*/
	/**
	 * @brief �X�V����
	 * 
	 * @param[in] frameTimer �t���[�������␳�l.
	 * @return �Ȃ�.
	 */
	void update( float frameTimer );


	/*=========================================================================*/
	/**
	 * @brief ��`�l���擾
	 *
	 * @warning ��`�̒l�̓X�N���[�����W�ł��B
	 *
	 * @param[in] �Ȃ�.
	 * @return ���݂̋�`�l.
	 */
	const Rect& getRect() const;


	/*=========================================================================*/
	/**
	 * @brief �A�j���[�V���������Z�b�g
	 *
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void reset();

public:

	/**
	 * @struct AnimationRectParameter.
	 * @brief �A�j���[�V������`�p�����[�^�\����.
	 */
	struct AnimationRectParameter
	{
		/** ���[�v���邩 */
		bool		loop;
		
		/** ���݂̕`�悵�Ă���C���[�W���ԍ�( �C���[�W1���ڂ�0�� ) */
		int			currentImageIndexColumn;

		/** ���݂̕`�悵�Ă���C���[�W�c�ԍ�( �C���[�W1���ڂ�0�� ) */
		int			currentImageIndexRow;

		/** �S�̂̕�( �X�N���[�����W ) */
		int			totalWidth;

		/** �S�̂̍���( �X�N���[�����W ) */
		int			totalHeight;

		/** �C���[�W1���̕�( �X�N���[�����W ) */
		int			imageWidth;

		/** �C���[�W1���̍���( �X�N���[�����W ) */
		int			imageHeight;

		/** �C���[�W�̉����� */
		int			imageCountColumns;

		/** �C���[�W�̏c���� */
		int			imageCountRows;

		/** �`��^�C�}�[ */
		int			timer;

		/** ���݂̕`��^�C�}�[ */
		float		currentTimer;

		// �؂�ւ��Ԋu
		float		interval;
	};


	/*=========================================================================*/
	/**
	 * @brief �p�����[�^���擾
	 *
	 * @param[in] �Ȃ�.
	 * @return �p�����[�^�\����.
	 */
	const AnimationRectParameter& parameter();

private:

	/*=========================================================================*/
	/**
	 * @brief ��`�l���X�V����
	 *
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void updateRect();

private:

	/** ��`�l */
	Rect					rect_;
	
	/** �p�����[�^ */
	AnimationRectParameter	param_;

	/** �Đ����� */
	bool					isPlay_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/