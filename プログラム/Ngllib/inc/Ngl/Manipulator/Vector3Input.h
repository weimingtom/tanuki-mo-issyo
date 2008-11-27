/*******************************************************************************/
/**
 * @file Vector3Input.h.
 * 
 * @brief 3�����x�N�g���\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR3INPUT_H_
#define _NGL_VECTOR3INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Vector3.h"

namespace Ngl{


/**
 * @class Vector3Input.
 * @brief 3�����x�N�g���\���̓��̓}�j�s�����[�^�N���X.
 */
class Vector3Input
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Vector3Input manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ���3�����\���� */
	Vector3& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ���3�����x�N�g���\����.
	 */
	Vector3Input( Vector3& value ):
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

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/