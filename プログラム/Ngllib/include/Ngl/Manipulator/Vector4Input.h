/*******************************************************************************/
/**
 * @file Vector4Input.h.
 * 
 * @brief 4�����x�N�g���\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/08/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_VECTOR4INPUT_H_
#define _NGL_VECTOR4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Vector4.h"

namespace Ngl{


/**
 * @class Vector4Input.
 * @brief 4�����x�N�g���\���̓��̓}�j�s�����[�^�N���X.
 */
class Vector4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Vector4Input manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ���4�����\���� */
	Vector4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ���3�����x�N�g���\����.
	 */
	Vector4Input( Vector4& value ):
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