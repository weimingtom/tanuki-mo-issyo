/*******************************************************************************/
/**
 * @file AnimationRect.cpp.
 * 
 * @brief �A�j���[�V������`�N���X�\�[�X�t�@�C��.
 *
 * @date 2008/08/11.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/AnimationRect.h"

using namespace Ngl;


/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @oaram[in] �Ȃ�
 */
AnimationRect::AnimationRect(  ):
	isPlay_( false )
{
}



/*=========================================================================*/
/**
 * @brief �J�n����
 * 
 * @param[in] desc �A�j���[�V������`�L�q�q.
 * @return �Ȃ�.
 */
void AnimationRect::begin( const AnimationRectDesc& desc )
{
	// �ݒ�L�q�q����p�����[�^���R�s�[
	param_.totalWidth			= desc.totalWidth;
	param_.totalHeight			= desc.totalHeight;
	param_.imageWidth			= desc.imageWidth;
	param_.imageHeight			= desc.imageHeight;
	param_.timer				= desc.timer;
	param_.loop					= desc.loop;
	param_.imageCountColumns	= desc.imageCountColumns;
	param_.imageCountRows		= desc.imageCountRows;

	// �ݒ�����Z�b�g
	reset();

	// �X�V�C���^�[�o�������߂�
	param_.interval = (float)param_.timer / (float)param_.imageCountColumns / (float)param_.imageCountRows;

	// �Đ��J�n
	isPlay_ = true;
}



/*=========================================================================*/
/**
 * @brief �X�V����
 * 
 * @param[in] frameTimer �t���[�������␳�l.
 * @return �Ȃ�.
 */
void AnimationRect::update( float frameTimer )
{
	// �Đ����ł͂Ȃ���
	if( isPlay_ == false ){
		return;
	}

	// �A�j���[�V�����^�C�}�[�����Z����
	param_.currentTimer += frameTimer;

	// �C���^�[�o���ɓ��B���Ă��邩
	if( param_.currentTimer >= param_.interval ){
		// ��`�l���X�V
		updateRect();

		// �A�j���[�V�����^�C�}�[���N���A
		param_.currentTimer = 0.0f;
	}
}



/*=========================================================================*/
/**
 * @brief ��`�l���擾
 *
 * @warning ��`�̒l�̓X�N���[�����W�ł��B
 *
 * @param[in] �Ȃ�.
 * @return ���݂̋�`�l.
 */
const Rect& AnimationRect::getRect() const
{
	return rect_;
}



/*=========================================================================*/
/**
 * @brief �A�j���[�V���������Z�b�g
 *
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationRect::reset()
{
	// �ŗL�p�����[�^��������
	param_.currentTimer				= 0.0f;
	param_.currentImageIndexColumn	= 0;
	param_.currentImageIndexRow		= 0;

	// 1���ڂ̃C���[�W�̋�`�l��ݒ�
	rect_.initialize( 
		0,							// ��
		0,							// ��
		(float)param_.imageWidth,	// �E
		(float)param_.imageHeight	// ��
		);
}
	
	

/*=========================================================================*/
/**
 * @brief �p�����[�^���擾
 *
 * @param[in] �Ȃ�.
 * @return �p�����[�^�\����.
 */
const AnimationRect::AnimationRectParameter& AnimationRect::parameter()
{
	return param_;
}



/*=========================================================================*/
/**
 * @brief ��`�l���X�V����
 *
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void AnimationRect::updateRect()
{
	// ���݂�X�ʒu���v�Z
	int curX = param_.imageWidth * param_.currentImageIndexColumn;
	int curY = param_.imageHeight * param_.currentImageIndexRow;
	
	// �e�N�X�`�����W��ύX
	rect_.initialize(
		(float)curX,							// ��
		(float)curY,							// ����				
		(float)( curX + param_.imageWidth  ),	// �E
		(float)( curY + param_.imageHeight )	// �E��
	);

	// ���̃C���[�W�ԍ����X�V
	param_.currentImageIndexColumn++;

	// �������𒴂��Ă��Ȃ���
	if( param_.currentImageIndexColumn <= param_.imageCountColumns ){
		return;
	}

	// ���̃C���[�W�ԍ���������
	param_.currentImageIndexColumn = 0;

	// �c�̃C���[�W�ԍ����X�V
	param_.currentImageIndexRow++;

	// �c�����𒴂��Ă��Ȃ���
	if( param_.currentImageIndexRow < param_.imageCountRows ){
		return;
	}

	// ���[�v�w�肩
	if( param_.loop == true ){
		// ����������
		reset();
	}
	else{
		// ��~����
		isPlay_ = false;

		// �Ō�̃C���[�W�ɐݒ�
		param_.currentImageIndexColumn	= param_.imageCountColumns-1;
		param_.currentImageIndexRow		= param_.imageCountRows-1;
	}
}

	
	
/*===== EOF ==================================================================*/