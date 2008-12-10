/*******************************************************************************/
/**
 * @file MathUtility.h.
 * 
 * @brief ���w���[�e�B���e�B�[�֐��S��`�w�b�_�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_MATHUTILITY_H_
#define _NGL_MATHUTILITY_H_

#include	<cmath>

namespace Ngl{


/** �~���� */
static const float PI = 3.14159265358979323846264f;


/*=========================================================================*/
/**
 * @brief �����l�����߂�
 * 
 * @param[in] degree �p�x.
 * @return �����l.
 */
float sin( float degree );


/*=========================================================================*/
/**
 * @brief �]���l�����߂�
 * 
 * @param[in] degree �p�x.
 * @return �]���l.
 */
float cos( float degree );


/*=========================================================================*/
/**
 * @brief ���ڒl�����߂�
 * 
 * @param[in] degree �p�x.
 * @return ���ڒl.
 */
float tan( float degree );


/*=========================================================================*/
/**
 * @brief �t�����l�����߂�
 * 
 * @param[in] y ���߂�l.
 * @return �t�����l.
 */
float asin( float y );


/*=========================================================================*/
/**
 * @brief �t�]���l�����߂�
 * 
 * @param[in] x ���߂�l.
 * @return �t�]���l.
 */
float acos( float x );


/*=========================================================================*/
/**
 * @brief �t���ڒl�����߂�
 * 
 * @param[in] x x����.
 * @param[in] y y����.
 * @return �t���ڒl.
 */
float atan( float degX, float degY );


/*=========================================================================*/
/**
 * @brief �p�x�����W�A���ɕϊ�����
 * 
 * @param[in] degree �p�x.
 * @return �ϊ��������W�A���l.
 */
float toRadian( float degree );


/*=========================================================================*/
/**
 * @brief ���W�A�����p�x�ɕϊ�����
 * 
 * @param[in] radian ���W�A��.
 * @return �ϊ������p�x.
 */
float toDegree( float radian );


/*=========================================================================*/
/**
 * @brief �p�x�𐳋K������
 * 
 * @param[in] degree ���K������p�x.
 * @return ���K�������p�x.
 */
float degreeNormalize( float degree );


/*=========================================================================*/
/**
 * @brief ��Βl�����߂�
 * 
 * @param[in] v ��Βl�����߂�l.
 * @return ��Βl.
 */
template< typename Type >
Type abs( Type v )
{
	Type result = 0;
	( v < 0 ) ? result = -v : result = v;
	return result;
}


/*=========================================================================*/
/**
 * @brief �ő�l�����߂�
 * 
 * @param[in] a �v�f�P.
 * @param[in] b �v�f�Q.
 * @return �ő�l.
 */
template< typename Type >
Type max_ngl( Type a, Type b )
{
	Type result = 0;
	( a > b ) ? result = a : result = b;
	return result;
}


/*=========================================================================*/
/**
 * @brief �ŏ��l�����߂�
 * 
 * @param[in] a �v�f�P.
 * @param[in] b �v�f�Q.
 * @return �ŏ��l.
 */
template< typename Type >
Type min_ngl( Type a, Type b )
{
	Type result = 0;
	( a < b ) ? result = a : result = b;
	return result;
}


/*=========================================================================*/
/**
 * @brief �w��̒l���Q�悷��
 * 
 * @param[in] a �Q�悷��l
 * @return �Q�悵���l.
 */
template< typename Type >
Type sqr( Type a )
{
	return a * a;
}


/*=========================================================================*/
/**
 * @brief �����������߂�
 * 
 * @param[in] a �����������߂�l
 * @return �Q�悵���l.
 */
template< typename Type >
Type sqrt( Type a )
{
	return std::sqrt( a );
}



/*=========================================================================*/
/**
 * @brief v��l����h�̊ԂɎ��߂�
 * 
 * @param[in] v �N�����v����l.
 * @param[in] l �ŏ��l.
 * @param[in] h �ő�l.
 * @return �N�����v�����l.
 */
template< typename Type >
Type clamp( Type v, Type l, Type h )
{
	return max_ngl( l, min_ngl( v, h ) );
}


/*=========================================================================*/
/**
 * @brief l����h�܂ł���`��Ԃ���(a��0.0f����1.0f)
 * 
 * @param[in] a ��Ԃ������l.
 * @param[in] l �ŏ��l.
 * @param[in] h �ő�l.
 * @return ��Ԃ����l.
 */
template< typename Type >
Type lerp( float a, Type l, Type h )
{
	return l + ( h - l ) * a;
}


/*=========================================================================*/
/**
 * @brief v1, v2, v3��񎟕⊮����(a��0.0f����1.0f)
 * 
 * @param[in] a ��Ԃ������l.
 * @param[in] v1 ��Ԓl�P.
 * @param[in] v2 ��Ԓl�Q.
 * @param[in] v3 ��Ԓl�R.
 * @return ��Ԃ����l.
 */
template< typename Type >
Type quadratic( float a, Type v1, Type v2, Type v3 )
{
	return v1 * ( 1.0f - a ) * ( 1.0f - a ) + 2 * v2 * a * ( 1.0f - a ) + v3 * a * a; 
}


/*=========================================================================*/
/**
 * @brief a �̒l��min, max�͈̔͊O�̒l�����ׂ�
 * 
 * @param[in] a ���ׂ�l.
 * @param[in] minV �͈͂̍ŏ��l.
 * @param[in] maxV �͈͂̍ő�l.
 * @retval true �͈͊O�̒l.
 * @retval false �͈͓��̒l.
 */
template< typename Type >
bool outOfRange( Type a, Type minV, Type maxV )
{
	return ( ( ( a < minV ) || ( a > maxV ) ) ? true : false );
}


} // namespace Ngl

#endif

/*===== EOF ==================================================================*/