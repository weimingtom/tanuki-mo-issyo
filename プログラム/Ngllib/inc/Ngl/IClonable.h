/*******************************************************************************/
/**
 * @file IClonable.h.
 * 
 * @brief �N���[���\�N���X�C���^�[�t�F�[�X.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ICLONABLE_H_
#define _NGL_ICLONABLE_H_


namespace Ngl{


/**
 * @interface IClonable�D
 * @brief �N���[���\�N���X�C���^�[�t�F�[�X.
 *
 * @tparam CloneObject �N���[���Ƃ��Đ�������^.
 */
template
<
	typename CloneObject
>
class IClonable
{

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~IClonable() {}


	/*=========================================================================*/
	/**
	 * @brief �N���[�����쐬����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �쐬�����N���[���̃|�C���^.
	 */
	virtual CloneObject* clone() = 0;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/