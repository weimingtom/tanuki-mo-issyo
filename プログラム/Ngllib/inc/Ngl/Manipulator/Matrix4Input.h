/*******************************************************************************/
/**
 * @file Matrix4Input.h.
 * 
 * @brief 4x4�s��\���̓��̓}�j�s�����[�^�N���X��`.
 *
 * @date 2008/07/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATRIX4INPUT_H_
#define _NGL_MATRIX4INPUT_H_

#include	"IInputStream.h"
#include	"Ngl/Matrix4.h"

namespace Ngl{


/**
 * @class Matrix4Input.
 * @brief 4x4�s��\���̓��̓}�j�s�����[�^�N���X.
 */
class Matrix4Input
{
	/*=========================================================================*/
	/**
	 * @brief >> ���Z�q�I�[�o�[���[�h ( �}�j�s�����[�^���� )
	 * 
	 * @param[in] stream ���̓X�g���[���̎Q��.
	 * @param[in] manip �}�j�s�����[�^.
	 * @return ���̓X�g���[���̎Q��.
	 */
	friend IInputStream& operator >> ( IInputStream& stream, Matrix4Input manip )
	{
		return manip( stream );
	}

private:

	/** �f�[�^��ǂݍ���4x4�s��\���� */
	Matrix4& value_;

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] value �f�[�^��ǂݍ���4x4�s��\����.
	 */
	Matrix4Input( Matrix4& value ):
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
		for( int i=0; i<4; ++i ){
			for( int j=0; j<4; j++ ){
				stream >> value_.m[ i ][ j ];
			}
		}

		return stream;
	}
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/