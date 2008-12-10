/*******************************************************************************/
/**
 * @file Color4Input.h.
 * 
 * @brief RGBA�J���[�\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COLOR4INPUT_H_
#define _NGL_COLOR4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Color4.h"

namespace Ngl{


/**
 * @class Color4Input.
 * @brief RGBA�J���[�\���̓��̓}�j�s�����[�^�N���X.
 */
class Color4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Color4Input manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ���RGBA�J���[�\���� */
	Color4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ���RGBA�J���[�\����.
	 */
	Color4Input( Color4& value ):
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
		stream >> value_.r;
		stream >> value_.g;
		stream >> value_.b;
		stream >> value_.a;

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/