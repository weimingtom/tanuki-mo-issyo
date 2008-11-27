/*******************************************************************************/
/**
 * @file MathUtility.cpp.
 * 
 * @brief ���w���[�e�B���e�B�[�֐��S��`�\�[�X�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/MathUtility.h>


/*=========================================================================*/
/**
 * @brief �����l�����߂�
 * 
 * @param[in] degree �p�x.
 * @return �����l.
 */
float Ngl::sin( float degree )
{
	float temp;

	// ���W�A���ɕϊ�
	temp = (float)Ngl::toRadian(degree);

	return std::sin(temp);
}



/*=========================================================================*/
/**
 * @brief �]���l�����߂�
 * 
 * @param[in] degree �p�x.
 * @return �]���l.
 */
float Ngl::cos( float degree )
{
	float temp;

	// ���W�A���ɕϊ�
	temp = (float)Ngl::toRadian(degree);

	return std::cos(temp);
}



/*=========================================================================*/
/**
 * @brief ���ڒl�����߂�
 * 
 * @param[in] degree �p�x.
 * @return ���ڒl.
 */
float Ngl::tan( float degree )
{
	float temp;

	// ���W�A���ɕϊ�
	temp = (float)Ngl::toRadian(degree);

	return std::tan(temp);
}



/*=========================================================================*/
/**
 * @brief �t�����l�����߂�
 * 
 * @param[in] y ���߂�l.
 * @return �t�����l.
 */
float Ngl::asin( float y )
{
	return Ngl::toDegree( std::asin( y ) );
}



/*=========================================================================*/
/**
 * @brief �t�]���l�����߂�
 * 
 * @param[in] x ���߂�l.
 * @return �t�]���l.
 */
float Ngl::acos( float x )
{
	return Ngl::toDegree( std::acos( x ) );
}



/*=========================================================================*/
/**
 * @brief �t���ڒl�����߂�
 * 
 * @param[in] x x����.
 * @param[in] y y����.
 * @return �t���ڒl.
 */
float Ngl::atan( float x, float y )
{
	return degreeNormalize( Ngl::toDegree( std::atan2( x, y ) ) );
}



/*=========================================================================*/
/**
 * @brief �p�x�����W�A���ɕϊ�����
 * 
 * @param[in] degree �p�x.
 * @return �ϊ��������W�A���l.
 */
float Ngl::toRadian( float degree )
{
	return degree * ( 1.0f / 180.0f * Ngl::PI );
}



/*=========================================================================*/
/**
 * @brief ���W�A�����p�x�ɕϊ�����
 * 
 * @param[in] radian ���W�A��.
 * @return �ϊ������p�x.
 */
float Ngl::toDegree( float radian )
{
	return radian * ( 1.0f / Ngl::PI * 180.0f );
}



/*=========================================================================*/
/**
 * @brief �p�x�𐳋K������
 * 
 * @param[in] degree ���K������p�x.
 * @return ���K�������p�x.
 */
float Ngl::degreeNormalize( float degree )
{
	return ( ( degree >= 0.0f ) ? (float)std::fmod( degree, 360.0f ) : (float)std::fmod( degree, 360.0f ) + 360.0f );
}



/*===== EOF ==================================================================*/