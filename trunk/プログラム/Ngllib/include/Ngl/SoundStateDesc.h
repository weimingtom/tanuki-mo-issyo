/*******************************************************************************/
/**
 * @file SoundStateDesc.h.
 * 
 * @brief �T�E���h��ԋL�q�q�\���̒�`.
 *
 * @date 2007/07/31.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SOUNDSTATEDESC_H_
#define _NGL_SOUNDSTATEDESC_H_

#include	<Ngl/Vector3.h>

namespace Ngl{


static const unsigned int SOUND_VOLUME_MIN	= 0;	/**< �{�����[���̍ŏ��l				*/
static const unsigned int SOUND_VOLUME_MAX	= 100;	/**< �{�����[���̍ő�l				*/

static const int SOUND_PAN_LEFTMAX	= -100;			/**< ���΃{�����[���ʒu�̍��ő�l	*/
static const int SOUND_PAN_MIDDLE	= 0;			/**< ���΃{�����[���ʒu�̒��Ԉʒu	*/
static const int SOUND_PAN_RIGHTMAX	= 100;			/**< ���΃{�����[���ʒu�̉E�ő�l	*/

/**
 * @enum SoundPlayType.
 * @brief �T�E���h�Đ��^�C�v�񋓌^.
 */
enum SoundPlayType
{
	SOUNDPLAYTYPE_NORMAL = 0,	/**< �ʏ�Đ�		*/
	SOUNDPLAYTYPE_LOOP,			/**< ���[�v�Đ�		*/
	SOUNDPLAYTYPE_WAIT			/**< �Đ��I���҂�	*/
};


/**
 * @struct SoundStateDesc�D
 * @brief �T�E���h��ԋL�q�q�\����.
 */
struct SoundStateDesc
{

	/** �Ȃ̍Đ��^�C�v */
	SoundPlayType	type;
	
	/** �{�����[�� */
	unsigned int	volume;

	/** �p���i���̍��E���ʁj*/
	long			pan;

	/** ���݂̍Đ��ʒu���� */
	float			currentTime;

	/** �Ȃ̍Đ��I���ʒu���� */
	float			endTime;

};


/** �f�t�H���g�̃T�E���h��ԋL�q�q */
static const SoundStateDesc SOUNDSTATEDESC_DEFAULT = { SOUNDPLAYTYPE_NORMAL, SOUND_VOLUME_MAX, 0, 0, 0 };


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/