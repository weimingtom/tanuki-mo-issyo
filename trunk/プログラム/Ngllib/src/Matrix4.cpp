/*******************************************************************************/
/**
 * @file Matrix4.cpp.
 * 
 * @brief 4x4�s��\���̃\�[�X�t�@�C��.
 *
 * @date 2008/06/28.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Matrix4.h"
#include	"Ngl/Quaternion.h"
#include	"Ngl/MathUtility.h"

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] �Ȃ�.
 */
Matrix4::Matrix4()
{
	// �P�ʍs����쐬
	setIdentitiy();
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] m11�`m44 �s�񐬕�.
 */
Matrix4::Matrix4
(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44
)
{
	// �����̒l����
	m[0][0] = m11; m[0][1] = m12; m[0][2] = m13; m[0][3] = m14;
	m[1][0] = m21; m[1][1] = m22; m[1][2] = m23; m[1][3] = m24;
	m[2][0] = m31; m[2][1] = m32; m[2][2] = m33; m[2][3] = m34;
	m[3][0] = m41; m[3][1] = m42; m[3][2] = m43; m[3][3] = m44;
}



/*===========================================================================*/
/**
 * @brief �R���X�g���N�^
 * 
 * @param[in] other �������s��l.
 */
Matrix4::Matrix4( const float *other )
{
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			m[i][j] = other[ ( i * 4 ) + j ];
		}
	}
}



/*===========================================================================*/
/**
 * @brief �P�ʍs��̐ݒ�
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
Matrix4& Matrix4::setIdentitiy()
{
	// �P�ʍs��̒l����
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief �]�u�s������߂�
 * 
 * @param[in] �Ȃ�.
 * @return ���߂��]�u�s��.
 */
Matrix4& Matrix4::transpose()
{
	Matrix4 tmp;

	// �s��̍s�Ɨ����������
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			tmp.m[i][j] = m[j][i];
		}
	}

	*this = tmp;

	return *this;
}



/*=========================================================================*/
/**
 * @brief �t�s����擾����
 * 
 * @param[in] �Ȃ�.
 * @return ���߂��t�s��.
 */
Matrix4 Matrix4::getInverse() const
{
	Matrix4 tmp;

	tmp.m[0][0] = m[0][0];
	tmp.m[1][0] = m[0][1];
	tmp.m[2][0] = m[0][2];

	tmp.m[0][1] = m[1][0];
	tmp.m[1][1] = m[1][1];
	tmp.m[2][1] = m[1][2];

	tmp.m[0][2] = m[2][0];
	tmp.m[1][2] = m[2][1];
	tmp.m[2][2] = m[2][2];

	tmp.m[3][0] = -( m[3][0] * tmp.m[0][0]
	             + m[3][1] * tmp.m[1][0]
	             + m[3][2] * tmp.m[2][0] );
	tmp.m[3][1] = -( m[3][0] * tmp.m[0][1] 
	             + m[3][1] * tmp.m[1][1]
	             + m[3][2] * tmp.m[2][1] );
	tmp.m[3][2] = -( m[3][0] * tmp.m[0][2]
	             + m[3][1] * tmp.m[1][2]
	             + m[3][2] * tmp.m[2][2] );

	tmp.m[0][3] = m[0][3];
	tmp.m[1][3] = m[1][3];
	tmp.m[2][3] = m[2][3];
	tmp.m[3][3] = m[3][3];

	return tmp;
}
	

	
/*===========================================================================*/
/**
 * @brief �t�s������߂�
 * 
 * @param[in] �Ȃ�.
 * @return ���߂��t�s��.
 */
Matrix4& Matrix4::inverse()
{
	*this = getInverse();

	return *this;
}



/*===========================================================================*/
/**
 * @brief �g��k���s��̐ݒ�
 * 
 * @param[in] x x�����̊g��䗦.
 * @param[in] y y�����̊g��䗦.
 * @param[in] z z�����̊g��䗦.
 * @return �ݒ肵���s��.
 */
Matrix4& Matrix4::setScale( float x, float y, float z )
{
	// �P�ʍs��̒l����
	m[0][0] = x;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = y;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = z;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}

	
	
/*===========================================================================*/
/**
 * @brief �g��k���s��̐ݒ�
 * 
 * @param[in] v �g��k�����x�N�g��.
 * @return �ݒ肵���s��.
 */
Matrix4& Matrix4::setScale(const Vector3& v)
{
	return setScale( v.x, v.y, v.z );
}



/*===========================================================================*/
/**
 * @brief x������̉�]�s���ݒ�
 * 
 * @param[in] aNgle �p�x.
 * @return �ݒ肵����]�s��.
 */
Matrix4& Matrix4::setRotateX(float aNgle)
{
	// Sin�l��Cos�l��ݒ�
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// �P�ʍs��̒l����
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = Cos;	m[1][2] = Sin;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = -Sin;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief y������̉�]�s���ݒ�
 * 
 * @param[in] aNgle �p�x.
 * @return �ݒ肵����]�s��.
 */
Matrix4& Matrix4::setRotateY(float aNgle)
{
	// Sin�l��Cos�l��ݒ�
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// �P�ʍs��̒l����
	m[0][0] = Cos;	m[0][1] = 0.0f;	m[0][2] = -Sin;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = Sin;	m[2][1] = 0.0f;	m[2][2] = Cos;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief z������̉�]�s���ݒ�
 * 
 * @param[in] aNgle �p�x.
 * @return �ݒ肵����]�s��.
 */
Matrix4& Matrix4::setRotateZ(float aNgle)
{
	// Sin�l��Cos�l��ݒ�
	float Sin = Ngl::sin(aNgle);
	float Cos = Ngl::cos(aNgle);

	// �P�ʍs��̒l����
	m[0][0] = Cos;	m[0][1] = Sin;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = -Sin;	m[1][1] = Cos;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = 0.0f;	m[3][1] = 0.0f;	m[3][2] = 0.0f;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���[�E�s�b�`�E���[�������]�s������߂�
 * 
 * @param[in] yaw ���[.
 * @param[in] pitch �s�b�`.
 * @param[in] role ���[��.
 * @return �ݒ肵�����W.
 */
Matrix4& Matrix4::setRotateFromYawPitchRole(float yaw, float pitch, float role)
{
	// ���[�p�̕ϊ��s������߂�
	Matrix4 matYaw;
	matYaw.setRotateY( yaw );

	// �s�b�`�p�̕ϊ��s������߂�
	Matrix4 matPitch;
	matPitch.setRotateX( pitch );

	// ���[���p�̕ϊ��s������߂�
	Matrix4 matRoll;
	matRoll.setRotateZ( role );

	// �ϊ��s�����������
	*this = matRoll * matPitch * matYaw;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���s�ړ��s���ݒ�
 * 
 * @param[in] x x�����̈ړ���.
 * @param[in] y y�����̈ړ���.
 * @param[in] z z�����̈ړ���.
 * @return �ݒ肵�����s�ړ��s��.
 */
Matrix4& Matrix4::setTranslate(float x, float y, float z)
{
	// �P�ʍs��̒l����
	m[0][0] = 1.0f;	m[0][1] = 0.0f;	m[0][2] = 0.0f;	m[0][3] = 0.0f;
	m[1][0] = 0.0f;	m[1][1] = 1.0f;	m[1][2] = 0.0f;	m[1][3] = 0.0f;
	m[2][0] = 0.0f;	m[2][1] = 0.0f;	m[2][2] = 1.0f;	m[2][3] = 0.0f;
	m[3][0] = x;	m[3][1] = y;	m[3][2] = z;	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���s�ړ��s���ݒ�
 * 
 * @param[in] v ���s�ړ�����.
 * @return �ݒ肵�����s�ړ��s��.
 */
Matrix4& Matrix4::setTranslate(const Vector3& v)
{
	return setTranslate( v.x, v.y, v.z );
}



/*===========================================================================*/
/**
 * @brief �����ϊ��s��̐ݒ�(�E����W�n)
 * 
 * @param[in] fov ����p.
 * @param[in] aspect �A�X�y�N�g��.
 * @param[in] zNear �߃N���b�v��.
 * @param[in] zFar ���N���b�v��.
 * @return �ݒ肵�������ϊ��s��.
 */
Matrix4& Matrix4::setPerspectiveRH(float fov, float aspect, float zNear, float zFar)
{
	float f = 1.0f / Ngl::tan(fov / 2.0f);

	// �s��̒l�ɑ��
	m[0][0] = f / aspect;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;
	
	m[1][0] = 0.0f;
	m[1][1] = f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;
	
	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = (zFar + zNear) / (zNear - zFar);
	m[2][3] = -1.0f;
	
	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = (2 * zFar * zNear) / (zNear - zFar);
	m[3][3] = 0.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief �����ϊ��s��̐ݒ�(������W�n)
 * 
 * @param[in] fov ����p.
 * @param[in] aspect �A�X�y�N�g��.
 * @param[in] zNear �߃N���b�v��.
 * @param[in] zFar ���N���b�v��.
 * @return �ݒ肵�������ϊ��s��.
 */
Matrix4& Matrix4::setPerspectiveLH(float fov, float aspect, float zNear, float zFar)
{
	float f = Ngl::cos( fov / 2.0f ) / Ngl::sin( fov / 2.0f );

	m[0][0] = f / aspect;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;

	m[1][0] = 0;
	m[1][1] = f;
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = ( zFar + zNear ) / ( zNear - zFar );
	m[2][3] = 1.0f;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = ( 2.0f * zFar * zNear ) / ( zNear - zFar );
	m[3][3] = 0.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ����ϊ��s���ݒ�(�E����W�n)
 * 
 * @param[in] eye ���_�̈ʒu.
 * @param[in] at �����_.
 * @param[in] up ������̃x�N�g��.
 * @return �ݒ肵������ϊ��s��.
 */
Matrix4& Matrix4::setLookAtRH(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	// z�����̃x�N�g�������߂�
	Vector3 e(eye - at);
	e.normalize();

	// x�����̃x�N�g�������߂�
	Vector3 v(up.cross(e));
	v.normalize();

	// y�����̃x�N�g�������߂�
	Vector3 u(e.cross(v));

	// �s��̒l�ɑ��
	m[0][0] = v.x;
	m[0][1] = u.x;
	m[0][2] = e.x;
	m[0][3] = 0.0f;
	
	m[1][0] = v.y;
	m[1][1] = u.y;
	m[1][2] = e.y;
	m[1][3] = 0.0f;
	
	m[2][0] = v.z;
	m[2][1] = u.z;
	m[2][2] = e.z;
	m[2][3] = 0.0f;
	
	m[3][0] = -eye.dot(v);
	m[3][1] = -eye.dot(u);
	m[3][2] = -eye.dot(e);
	m[3][3] = 1.0f;

	return *this;
}


/*===========================================================================*/
/**
 * @brief ����ϊ��s���ݒ�(������W�n)
 * 
 * @param[in] eye ���_�̈ʒu.
 * @param[in] at �����_.
 * @param[in] up ������̃x�N�g��.
 * @return �ݒ肵������ϊ��s��.
 */
Matrix4& Matrix4::setLookAtLH(const Vector3& eye, const Vector3& at, const Vector3& up)
{
	// z�����̃x�N�g�������߂�
	Vector3 e( at - eye );
	e.normalize();

	// x�����̃x�N�g�������߂�
	Vector3 v( up.cross( e ) );
	v.normalize();

	// y�����̃x�N�g�������߂�
	Vector3 u( e.cross( v ) );

	// ��]�s��Ɋe�x�N�g����ݒ肷��
	m[0][0] = v.x;
	m[0][1] = u.x;
	m[0][2] = e.x;
	m[0][3] = 0.0f;

	m[1][0] = v.y;
	m[1][1] = u.y;
	m[1][2] = e.y;
	m[1][3] = 0.0f;

	m[2][0] = v.z;
	m[2][1] = u.z;
	m[2][2] = e.z;
	m[2][3] = 0.0f;

	// ���_�̈ʒu��ݒ肷��
	m[3][0] = -eye.dot( v );
	m[3][1] = -eye.dot( u );
	m[3][2] = -eye.dot( e );
	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief ���ˉe�ϊ��s���ݒ�(�E����W�n)
 * 
 * @param[in] left �N���b�v�ʂ̍����̍��W.
 * @param[in] right �N���b�v�ʂ̉E���̍��W.
 * @param[in] bottom �N���b�v�ʂ̉����̍��W.
 * @param[in] top �N���b�v�ʂ̏㑤�̍��W.
 * @param[in] zNear �߃N���b�v�ʂ̍��W.
 * @param[in] zFar ���N���b�v�ʂ̍��W.
 * @return �ݒ肵���ϊ��s��.
 */
Matrix4& Matrix4::setOrthoRH( float left, float right, float top, float bottom, float zNear, float zFar )
{
	m[0][0] = 2.0f / ( right - left );
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0; 

	m[1][0] = 0;
	m[1][1] = 2.0f / (  top - bottom );
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = -2.0f / ( zFar - zNear );
	m[2][3] = 0; 

	m[3][0] = -( right + left   ) / ( right - left   );
	m[3][1] = -( top   + bottom ) / ( top   - bottom );
	m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	m[3][3] = 1;

	return *this;
}
	
	
	
/*===========================================================================*/
/**
 * @brief ���ˉe�ϊ��s���ݒ�(������W�n)
 * 
 * @param[in] left �N���b�v�ʂ̍����̍��W.
 * @param[in] right �N���b�v�ʂ̉E���̍��W.
 * @param[in] bottom �N���b�v�ʂ̉����̍��W.
 * @param[in] top �N���b�v�ʂ̏㑤�̍��W.
 * @param[in] zNear �߃N���b�v�ʂ̍��W.
 * @param[in] zFar ���N���b�v�ʂ̍��W.
 * @return �ݒ肵���ϊ��s��.
 */
Matrix4& Matrix4::setOrthoLH( float left, float right, float top, float bottom, float zNear, float zFar )
{
	m[0][0] = 2.0f / ( right - left );
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0; 

	m[1][0] = 0;
	m[1][1] = 2.0f / (  top - bottom );
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 2.0f / ( zFar - zNear );
	m[2][3] = 0; 

	m[3][0] = -( right + left   ) / ( right - left   );
	m[3][1] = -( top   + bottom ) / ( top   - bottom );
	m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	m[3][3] = 1;


	return *this;
}

	
	
/*=========================================================================*/
/**
 * @brief ���W�ϊ�
 *
 * �x�N�g���ƍs��s��̊|���Z������.
 * 
 * @param[in] v ��Z����3�����x�N�g��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
Vector3 Matrix4::transform(const Vector3& v) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
	float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + m[3][3];

	return Vector3(x/w, y/w, z/w);
}



/*=========================================================================*/
/**
 * @brief ���W�ϊ�.
 *
 * �x�N�g���ƍs��s��̊|���Z������ ���̌��ʂ� w = 1 �Ɏˉe����.
 * 
 * @param[in] v ��Z����3�����x�N�g��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
Vector3 Matrix4::transformCoord( const Vector3& v ) const
{
	float x = v.x * m[0][0]
			+ v.y * m[1][0]
			+ v.z * m[2][0]
			+ m[3][0];
	float y = v.x * m[0][1]
			+ v.y * m[1][1]
			+ v.z * m[2][1]
			+ m[3][1];
	float z = v.x * m[0][2]
			+ v.y * m[1][2]
			+ v.z * m[2][2]
			+ m[3][2];
	float w = v.x * m[0][3]
			+ v.y * m[1][3]
			+ v.z * m[2][3]
			+ m[3][3];

	Vector3 result( x, y, z );
	result = result * ( 1.0f / w );

	return result;
}

	
	
/*=========================================================================*/
/**
 * @brief ���W�ϊ�
 *
 * �@���x�N�g���p�ŉ�]�݂̂ŕ��s�ړ��͂����Ȃ�.
 * 
 * @param[in] v ��Z����3�����x�N�g��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
Vector3 Matrix4::transformNormal(const Vector3& v) const
{
	float x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0];
	float y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1];
	float z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2];

	return Vector3(x, y, x);
}



/*===========================================================================*/
/**
 * @brief ���[���p�����߂�
 * 
 * @param[in] �Ȃ�.
 * @return ���[���p.
 */
float Matrix4::getRole() const
{
	return Ngl::atan( m[0][1], m[1][1] );
}



/*===========================================================================*/
/**
 * @brief �s�b�`�p�����߂�
 * 
 * @param[in] �Ȃ�.
 * @return �s�b�`�p.
 */
float Matrix4::getPitch() const
{
	return Ngl::degreeNormalize( Ngl::asin( -m[2][1] ) );
}



/*===========================================================================*/
/**
 * @brief ���[�p�����߂�
 * 
 * @param[in] �Ȃ�.
 * @return ���[�p.
 */
float Matrix4::getYaw() const
{
	return Ngl::atan( m[2][0], m[2][2] );
}



/*===========================================================================*/
/**
 * @brief x���ʒu��ݒ肷��
 * 
 * @param[in] axisX �����̈ʒu���W.
 * @return �Ȃ�.
 */
Matrix4& Matrix4::setAxisX(const Vector3 &axisX)
{
	m[0][1] = axisX.x;
	m[0][2] = axisX.y;
	m[0][3] = axisX.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief y���ʒu��ݒ肷��
 * 
 * @param[in] axisY y���̈ʒu���W.
 * @return �Ȃ�.
 */
Matrix4& Matrix4::setAxisY(const Vector3 &axisY)
{
	m[1][0] = axisY.x;
	m[1][1] = axisY.y;
	m[1][2] = axisY.z;

	return *this;
}


/*===========================================================================*/
/**
 * @brief z���ʒu��ݒ肷��
 * 
 * @param[in] axisZ z���̈ʒu���W.
 * @return �Ȃ�.
 */
Matrix4& Matrix4::setAxisZ(const Vector3 &axisZ)
{
	m[2][0] = axisZ.x;
	m[2][1] = axisZ.y;
	m[2][2] = axisZ.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief �ʒu���W��ݒ肷��
 * 
 * @param[in] position �ʒu���W.
 * @return �Ȃ�.
 */
Matrix4& Matrix4::setPosition(const Vector3 &position)
{
	m[3][0] = position.x;
	m[3][1] = position.y;
	m[3][2] = position.z;

	return *this;
}



/*===========================================================================*/
/**
 * @brief x���ʒu���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �����̈ʒu���W.
 */
Vector3 Matrix4::getAxisX() const
{
	return Vector3( m[0][0], m[0][1], m[0][2] );
}



/*===========================================================================*/
/**
 * @brief y���ʒu���擾����
 * 
 * @param[in] �Ȃ�.
 * @return y���̈ʒu���W.
 */
Vector3 Matrix4::getAxisY() const
{
	return Vector3( m[1][0], m[1][1], m[1][2] );
}



/*===========================================================================*/
/**
 * @brief z���ʒu���擾����
 * 
 * @param[in] �Ȃ�.
 * @return z���̈ʒu���W.
 */
Vector3 Matrix4::getAxisZ() const
{
	return Vector3( m[2][0], m[2][1], m[2][2] );
}



/*===========================================================================*/
/**
 * @brief �ʒu���W���擾����
 * 
 * @param[in] �Ȃ�.
 * @return �ʒu���W.
 */
Vector3 Matrix4::getPosition() const
{
	return Vector3( m[3][0], m[3][1], m[3][2] );
}



/*===========================================================================*/
/**
 * @brief �N�H�[�^�j�I������s������߂�
 * 
 * @param[in] q �N�H�[�^�j�I��.
 * @return �s��.
 */
Matrix4& Matrix4::fromQuaternion(const Quaternion &q)
{
	float		xx, yy, zz;
	float		xy, xz, yz;
	float		wx, wy, wz;

	xx = q.x * q.x * 2.0f;
	yy = q.y * q.y * 2.0f;
	zz = q.z * q.z * 2.0f;
	xy = q.x * q.y * 2.0f;
	xz = q.x * q.z * 2.0f;
	yz = q.y * q.z * 2.0f;
	wx = q.w * q.x * 2.0f;
	wy = q.w * q.y * 2.0f;
	wz = q.w * q.z * 2.0f;

	m[0][0] = 1.0f - ( yy + zz );
	m[0][1] = xy + wz;
	m[0][2] = xz - wy;
	m[0][3] = 0.0f;

	m[1][0] = xy - wz;
	m[1][1] = 1.0f - ( xx + zz );
	m[1][2] = yz + wx;
	m[1][3] = 0.0f;

	m[2][0] = xz + wy;
	m[2][1] = yz - wx;
	m[2][2] = 1.0f - ( xx + yy );
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;

	return *this;
}



/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return ���Z���ʂ�Matrix4.
 */
Matrix4 Matrix4::operator + () const
{
	return *this;
}



/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return ���Z���ʂ�Matrix4.
 */
Matrix4 Matrix4::operator - () const
{
	// ���ׂĂ̗v�f�̕����𔽓]�������s���Ԃ�
	return Matrix4(
		-m[0][0], -m[0][1], -m[0][2], -m[0][3],
		-m[1][0], -m[1][1], -m[1][2], -m[1][3],
		-m[2][0], -m[2][1], -m[2][2], -m[2][3],
		-m[3][0], -m[3][1], -m[3][2], -m[3][3]
		);
}



/*===========================================================================*/
/**
 * @brief =���Z�q�I�[�o�[���[�h
 * 
 * @param[in] m2 ������邷��s��.
 * @return ����������ʂ̍s��.
 */
Matrix4& Matrix4::operator =(const Matrix4 &m2)
{
	// �����ւ̑���ł͂Ȃ���
	if( this != &m2 ){
		// �e�������R�s�[
		for( int i=0; i<4; i++ ){
			for( int j=0; j<4; j++ ){
				m[i][j] = m2.m[i][j];
			}
		}
	}

	return *this;
}



/*===========================================================================*/
/**
 * @brief *=���Z�q�I�[�o�[���[�h
 * 
 * @param[in] m2 ��Z����s��.
 * @return ���Z���ʂ̍s��.
 */
Matrix4& Matrix4::operator *= (const Matrix4& m2)
{
	Matrix4 tmp;

	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ){
			tmp.m[i][j] = m[i][0] * m2.m[0][j]
					    + m[i][1] * m2.m[1][j]
					    + m[i][2] * m2.m[2][j]
					    + m[i][3] * m2.m[3][j];
		}
	}

	*this = tmp;

	return *this;
}



/*===========================================================================*/
/**
 * @brief float* ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Matrix4::operator float *() const
{
	return ( float* )m;
}



/*===========================================================================*/
/**
 * @brief float* ���Z�q�I�[�o�[���[�h
 * 
 * @param[in] �Ȃ�.
 * @return �L���X�g�����l.
 */
Matrix4::operator const float *() const
{
	return ( const float* )m;
}



/*===========================================================================*/
/**
 * @brief ==���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ��r����s��.
 * @param[in] m2 ��r����s��.
 * @return ��r���ʂ̍s��.
 */
bool operator == ( const Matrix4& m1, const Matrix4& m2 )
{
	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			if( m1.m[i][j] != m2.m[i][j] ){
				return false;
			}
		}
	}
	return true;
}



/*===========================================================================*/
/**
 * @brief !=���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ��r����s��.
 * @param[in] m2 ��r����s��.
 * @return ��r���ʂ̍s��.
 */
bool operator != ( const Matrix4& m1, const Matrix4& m2 )
{
	return !( m1 == m2 );
}



/*===========================================================================*/
/**
 * @brief +���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Matrix4 operator + ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 result;	// ���Z���ʍs��

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
		}
	}
	
	// ���ʂ�Ԃ�
	return result;
}



/*===========================================================================*/
/**
 * @brief -���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Matrix4 operator - ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 result;	// ���Z���ʍs��

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
		}
	}
	
	// ���ʂ�Ԃ�
	return result;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m1 ���Z����s��.
 * @param[in] m2 ���Z����s��.
 * @return ���Z���ʂ̍s��.
 */
const Matrix4 operator * ( const Matrix4& m1, const Matrix4& m2 )
{
	Matrix4 tmp(m1);
	return tmp *= m2;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] v ���Z����3�����x�N�g��.
 * @param[in] m ���Z����s��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Vector3 operator * ( const Vector3& v, const Matrix4& m )
{
	return m.transform(v);
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m ���Z����s��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Matrix4 operator * ( const Matrix4& m, float s )
{
	Matrix4 result; // ���Z����

	for( int i=0; i<4; i++ ){
		for( int j=0; j<4; j++ ){
			result.m[i][j] = m.m[i][j] * s;
		}
	}

	return result;
}



/*===========================================================================*/
/**
 * @brief *���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] s ���Z����X�J���[.
 * @param[in] m ���Z����s��.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Matrix4 operator * ( float s, const Matrix4& m )
{
	return m * s;
}



/*===========================================================================*/
/**
 * @brief /���Z�q�I�[�o�[���[�h �񃁃��o�֐�
 * 
 * @param[in] m ���Z����s��.
 * @param[in] s ���Z����X�J���[.
 * @return ���Z���ʂ�3�����x�N�g��.
 */
const Matrix4 operator / ( const Matrix4& m, float s )
{
	return m * ( 1.0f / s );
}



/*========= EOF =============================================================*/