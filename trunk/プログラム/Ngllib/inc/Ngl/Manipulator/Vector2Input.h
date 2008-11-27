/*******************************************************************************/
/**
 * @file Vector2Input.h.
 * 
 * @brief 2�����x�N�g���\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR2INPUT_H_
#define _NGL_VECTOR2INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Vector2.h"

namespace Ngl{


/**
 * @class Vector2Input
 * @brief 2�����x�N�g���\���̓��̓}�j�s�����[�^�N���X.
 */
class Vector2Input
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Vector2Input manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ���2�����\���� */
	Vector2& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ���3�����x�N�g���\����.
	 */
	Vector2Input( Vector2& value ):
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

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/