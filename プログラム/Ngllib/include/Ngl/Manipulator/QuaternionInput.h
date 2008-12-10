/*******************************************************************************/
/**
 * @file QuaternionInput.h.
 * 
 * @brief �N�H�[�^�j�I���\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_QUATERNIONINPUT_H_
#define _NGL_QUATERNIONINPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Quaternion.h"

namespace Ngl{


/**
 * @class QuaternionInput
 * @brief �N�H�[�^�j�I���\���̓��̓}�j�s�����[�^�N���X.
 */
class QuaternionInput
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, QuaternionInput manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ��ރN�H�[�^�j�I���\���� */
	Quaternion& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ��ރN�H�[�^�j�I���\����.
	 */
	QuaternionInput( Quaternion& value ):
	  value_( value )
	{}

private:

	/*=========================================================================*/
	/**
	 * @brief () ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @return ���̓X�g���[���̎Q��.
	 */
	IInputStream& operator ()( IInputStream& stream )
	{
		stream >> value_.x;
		stream >> value_.y;
		stream >> value_.z;
		stream >> value_.w;

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/