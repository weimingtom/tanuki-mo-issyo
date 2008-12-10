/*******************************************************************************/
/**
 * @file Collision.cpp.
 * 
 * @brief �Փ˔���N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/12.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Collision.h"
#include	"Ngl/MathUtility.h"
#include	"Ngl/Line3.h"
#include	<cfloat>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief ���̂Ƌ��̂̏Փ˔���
 * 
 * @param[in] center1 ����1��3D���_���W�z��.
 * @param[in] radius1 ����1�̔��a�l.	
 * @param[in] center2 ����2��3D���_���W�z��.
 * @param[in] radius2 ����2�̔��a�l.	
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�����.
 */
bool Collision::sphereAndSphere
( 
	const Ngl::Vector3&	center1, 
	float				radius1, 
	const Ngl::Vector3&	center2, 
	float				radius2
)
{
	// ���̊Ԃ̋��������߂�
	Vector3 v = center1 - center2;
	float distance = v.length();

	// 2�̋��̂̔��a�����Z�����l������������
	if( distance <= ( radius1 + radius2 ) ){
		return true;
	}
	
	return false;
}



/*===========================================================================*/
/**
 * @brief ���̂��Փ˂��Ȃ����W�֕␳����
 * 
 * @param[out] center ���̂�3D���S�ʒu���W.
 * @param[in] radius ���̂̔��a.
 * @param[in] intersect 3D��_���W. 
 * @return �Ȃ�.
 */
void Collision::sphereRevisePosition
( 
	Ngl::Vector3&		center, 
	float				radius,
	const Ngl::Vector3&	intersect
)
{
	// ��_���璆�S�܂ł̃x�N�g�������߂�
	Vector3 offset = center - intersect;
	offset.normalize();

	// �������Ă��镔����␳����
	offset *= ( radius - Ngl::sqrt( Ngl::sqr( center.distanceSq( intersect ) ) ) );

	Vector3 result = center;
	result += offset;

	center = result;
}



/*=========================================================================*/
/**
 * @brief ���̂Ɛ��̏Փ˔���
 * 
 * @param[in] center ���̂�3D���_���W�z��.
 * @param[in] radius ���̂̔��a�l.	
 * @param[in] rayPos ����3D�ʒu���W�z��.
 * @param[in] rayDir ���̕���3D�x�N�g���z��.	
 * @retval true �Փ˂��Ă���.
 * @retval false �Փ˂��Ă��Ȃ�����.
 */
bool Collision::sphereAndRay
(
	const Ngl::Vector3&	center, 
	float				radius, 
	const Ngl::Vector3&	rayPos, 
	const Ngl::Vector3&	rayDir
)
{
	// ���̂̒��S������ւ̃x�N�g�������߂�
	Vector3 v = rayPos - center;

	float a = rayDir.lengthSq();
	float b = v.dot( rayDir );
	float c = v.lengthSq() - Ngl::sqr( radius );

	float d = Ngl::sqr( b ) - a * c;
	if( d < 0.0f ){
		return false;
	}
	
	return true;
}


	
/*=========================================================================*/
/**
 * @brief �����Ɛ����̏Փ˔���
 * 
 * @param[in] a1 ���肷�����1�̎n�_3D���W.
 * @param[in] a2 ���肷�����1�̏I�_3D���W.
 * @param[in] b1 ���肷�����2�̎n�_3D���W.
 * @param[in] b2 ���肷�����2�̏I�_3D���W.
 * @param[in] isRay �����������ǂ���.
 * @param[in] epsilon 臒l.
 * @return �Փ˔��茋�ʍ\����.
 */
const LineCollisionReport& Collision::lineAndLine
(
	const Ngl::Vector3& a1, 
	const Ngl::Vector3& a2, 
	const Ngl::Vector3& b1, 
	const Ngl::Vector3& b2,
	bool				isRay,
	float				epsilon
)
{
	// ���ʃ��|�[�g��������
	lineReport_ = LINECOLLISIONREPORT_NOT_COLLISION;

	// ����a, b�̃x�N�g�������߂�
	Vector3 VA = a2 - a1;
	Vector3 VB = b2 - b1;

	// ����a, b�̂Q��a�����߂�
	float l11 = VA.lengthSq();
	float l22 = VB.lengthSq();

	// a�̒�����臒l������( �_�Ɛ����̔��� )
	if( l11 < FLT_EPSILON ){
		// ����a�̎n�_���W�ɍł��߂�����b��̍��W�����߂�
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, VB, a1, isRay, lineReport_.intersectPosB, dammy );
	}
	// b�̒�����臒l������( �_�Ɛ����̔��� )
	else if( l22 < FLT_EPSILON ){
		// ����b�̎n�_���W�ɍł��߂�����a��̍��W�����߂�
		float dammy = 0.0f;
		findNearestPointOnLineSegment( a1, VA, b1, isRay, lineReport_.intersectPosA, dammy );
	}
	// ����a�ƁA����b��臒l�����傫��
	else{
		Vector3 AB = b1 - a1;
		float l12 = -VA.dot( VB );
		float detL = l11 * l22 - Ngl::sqr( l12 );

		if( Ngl::abs( detL ) < FLT_EPSILON ){
			// ����b�̎��_���W�ɍł��߂�����a��̍��W�����߂�
			findNearestPointOfParallelLineSegments(
				a1, a2, VA,
				b1, b1, VB,
				isRay,
				lineReport_.intersectPosA,
				lineReport_.intersectPosB
				);
		}
		else{
			float ra = VA.dot( AB );
			float rb = -VB.dot( AB );
			float t = ( l11 * rb - ra * l12 ) / detL;
			float s = ( ra - l12 * t ) / l11;
			lineReport_.intersectPosA.linearEquation( a1, VA, s );
			lineReport_.intersectPosB.linearEquation( a2, VB, t );

			// �L�������ŁA�ǂ��炩�̐�������������Ă��邩
			if( ( isRay == false ) && 
				( Ngl::outOfRange( s, 0.0f, 1.0f ) == true || Ngl::outOfRange( t, 0.0f, 1.0f ) == true )
				){
				// �L���������m�̍ł��߂��_�̒���������
				adjustNearestPoint(
					a1, VA,
					b1, VB,
					s, t,
					lineReport_.intersectPosA,
					lineReport_.intersectPosB
					);
			}
		}
	}

	// �ł��߂��_���m�̋�������臒l�����Z���ꍇ�͏Փ˂��Ă���
	if( lineReport_.intersectPosA.distanceSq( lineReport_.intersectPosB ) <= Ngl::sqr( epsilon ) ){
		return lineReport_;
	}

	// �Փ˂��Ă��Ȃ�����
	return LINECOLLISIONREPORT_NOT_COLLISION;
}

	
	
/*=========================================================================*/
/**
 * @brief �����ƁA�w����W�̍ł��אڂ��������̍��W�����߂�
 * 
 * @param[in] linePos �����̍��W.
 * @param[in] lineVec �����̕���.
 * @param[in] point ���ׂ������W.
 * @param[in] isRay ����������.
 * @param[out] np ������̗אڂ�����W.
 * @param[out] parameter �����̕������p�����[�^.
 * @return �Ȃ�.
 */
void Collision::findNearestPointOnLineSegment
(
	const Ngl::Vector3& linePos,
	const Ngl::Vector3& lineVec,
	const Ngl::Vector3& point,
	bool				isRay,
	Ngl::Vector3&		np,
	float&				parameter
)
{
	// �����̃x�N�g���̒��������߂�
	float distance = lineVec.lengthSq();

	// �����̃x�N�g���̒�����肪臒l������������
	if( distance < FLT_EPSILON ){
		// �����̎��_���ł��߂��_( ������_�Ƃ��Ĉ��� )
		np = linePos;
		parameter = 0.0f;
	}

	// �����̎��_����A�_�ւ̃x�N�g�������߂�
	Vector3 vLP = point - linePos;

	// ������̒��ׂ������W�ɍł��߂����W�̃p�����[�^�����߂�
	float t = lineVec.dot( vLP ) / distance;

	// �L��������
	if( isRay == false ){
		t = Ngl::clamp( t, 0.0f, 1.0f );
	}

	// ���߂��p�����[�^����ł��߂����W�����߂�
	np.linearEquation( linePos, lineVec, t );
	parameter = t;
}

	

/*=========================================================================*/
/**
 * @brief �������m���������Ȃ��ꍇ�́A�������m�ōł��߂��_�����߂�
 * 
 * @param[in] a1 ���肷�����a�̎n�_3D���W.
 * @param[in] a2 ���肷�����a�̏I�_3D���W.
 * @param[in] va ����a�̎n�_����I�_�ւ̃x�N�g��.
 * @param[in] b1 ���肷�����b�̎n�_3D���W.
 * @param[in] b2 ���肷�����b�̏I�_3D���W.
 * @param[in] vb ����b�̎n�_����I�_�ւ̃x�N�g��.
 * @param[in] isRay �����������ǂ���.
 * @param[out] pa ����a��́A����b�ɍł��߂�3D���W.
 * @param[out] pb ����b��́A����a�ɍł��߂�3D���W.
 * @return �Ȃ�.
 */
void Collision::findNearestPointOfParallelLineSegments
(
	const Ngl::Vector3& a1, 
	const Ngl::Vector3& a2,
	const Ngl::Vector3& va,
	const Ngl::Vector3& b1, 
	const Ngl::Vector3& b2,
	const Ngl::Vector3& vb,
	bool				isRay,
	Ngl::Vector3&		pa,
	Ngl::Vector3&		pb
)
{
	// ����a��̍��W�ŁA�ł�����b�̎n�_�ɋ߂����W�����߂�
	float s1 = 0.0f;
	findNearestPointOnLineSegment( a1, va, b1, true, pa, s1 );

	// ����������
	if( isRay == true ){
		// ���������̏ꍇ�́A����b�̎n�_���ł��߂����W
		pb = b1;

		return;
	}

	// ����a��̍��W�ŁA�ł�����b�̏I�_�ɋ߂����W�����߂�
	float s2 = 0.0f;
	Vector3 tmpPoint;
	findNearestPointOnLineSegment( a1, va, b2, true, tmpPoint, s2 );

	if( ( s1 < 0.0f ) && ( s2 < 0.0f ) ){
		pa = a1;
		pb = ( s1 < s2 ) ? b2 : b1;
	}
	else if( ( s1 > 1.0f ) && ( s2 > 1.0f ) ){
		pa = a2;
		pb = ( s1 < s2 ) ? b1 : b2;
	}
	else{
		float t = 0.5f * ( Ngl::clamp( s1, 0.0f, 1.0f ) + Ngl::clamp( s2, 0.0f, 1.0f ) );
		pa.linearEquation( a1, va, t );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, vb, pa, true, pb, dammy );
	}
}
	
	

/*=========================================================================*/
/**
 * @brief �������m�́A�ł��߂����W�̒���������
 * 
 * @param[in] a1 ���肷�����a�̎n�_3D���W.
 * @param[in] va ����a�̎n�_����I�_�ւ̃x�N�g��.
 * @param[in] b1 ���肷�����b�̎n�_3D���W.
 * @param[in] vb ����b�̎n�_����I�_�ւ̃x�N�g��.
 * @param[in] s ����a�̒����������p�����[�^.
 * @param[in] t ����b�̒����������p�����[�^.
 * @param[out] pa ����a��́A����b�ɍł��߂�3D���W.
 * @param[out] pb ����b��́A����a�ɍł��߂�3D���W.
 * @return �Ȃ�.
 */
void Collision::adjustNearestPoint
(
	const Ngl::Vector3& a1,
	const Ngl::Vector3& va,
	const Ngl::Vector3& b1,
	const Ngl::Vector3& vb,
	float				s,
	float				t,
	Ngl::Vector3&		pa,
	Ngl::Vector3&		pb
)
{
	if( Ngl::outOfRange( s, 0.0f, 1.0f ) == true && Ngl::outOfRange( t, 0.0f, 1.0f ) == true ){
		s = Ngl::clamp( s, 0.0f, 1.0f );
		pa.linearEquation( a1, va, s );
		findNearestPointOnLineSegment( b1, vb, pa, true, pb, t );

		if( Ngl::outOfRange( t, 0.0f, 1.0f ) == true ){
			t = Ngl::clamp( t, 0.0f, 1.0f );
			pb.linearEquation( b1, vb, t );
			float dammy = 0.0f;
			findNearestPointOnLineSegment( a1, va, pb, false, pa, dammy );
			findNearestPointOnLineSegment( b1, vb, pa, false, pb, dammy );
		}
	}
	else if( Ngl::outOfRange( s, 0.0f, 1.0f ) == true ){
		s = Ngl::clamp( s, 0.0f, 1.0f );
		pa.linearEquation( a1, va, s );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( b1, vb, pa, false, pb, dammy );
	}
	else{
		t = Ngl::clamp( t, 0.0f, 1.0f );
		pb.linearEquation( b1, vb, t );
		float dammy = 0.0f;
		findNearestPointOnLineSegment( a1, va, pb, false, pa, dammy );
	}
}

	
	
/*===========================================================================*/
/**
 * @brief �������{�b�N�X���ɑ��݂��邩�`�F�b�N����
 * 
 * @param[in] min �{�b�N�X�̍ŏ����W.
 * @param[in] max �{�b�N�X�̍ő���W.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @retval true ���݂���.
 * @retval false ���݂��Ȃ�.
 */
bool Collision::lineIsInsideBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& line0,
	const Vector3& line1
)
{
	// �{�b�N�X�����S�ɊO���ɑ��݂��Ă��邩
	if( lineIsOutsideBox( min, max, line0, line1 ) == true ){
		return false;
	}

	// �n�_���{�b�N�X���ɑ��݂��邩
	if( ( line0.x >= min.x && line0.x <= max.x ) &&
		( line0.y >= min.y && line0.y <= max.y ) &&
		( line0.z >= min.z && line0.z <= max.z )
		){
		return true;
	}

	// �I�_���{�b�N�X���ɑ��݂��邩
	if( ( line1.x >= min.x && line1.x <= max.x ) &&
		( line1.y >= min.y && line1.y <= max.y ) &&
		( line1.z >= min.z && line1.z <= max.z )
		){
		return true;
	}

	// �����̕��������߂�
	Vector3 dir = line1 - line0;
	dir.normalize();

	// �������{�b�N�X�ƌ������邩
	return rayIsIntersectBox( min, max, line0, dir );
}



/*===========================================================================*/
/**
 * @brief �������{�b�N�X�̊O�ɂ��邩�`�F�b�N����
 * 
 * @param[in] min �{�b�N�X�̍ŏ����W.
 * @param[in] max �{�b�N�X�̍ő���W.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_.
 * @retval true ���݂���.
 * @retval false ���݂��Ȃ�.
 */
bool Collision::lineIsOutsideBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& line0,
	const Vector3& line1
)
{
	// ���S�Ƀ{�b�N�X�����O�ɂ��邩
	if( ( line0.x < min.x && line1.x < min.x ) ||
		( line0.y < min.y && line1.y < min.y ) ||
		( line0.z < min.z && line1.z < min.z ) ||
		( line0.x > max.x && line1.x > max.x ) ||
		( line0.y > max.y && line1.y > max.y ) ||
		( line0.z > max.z && line1.z > max.z )
		){
		return true;
	}

	// �{�b�N�X�̓����ɑ��݂��Ă���
	return false;
}
	
	

/*===========================================================================*/
/**
 * @brief ���C�ƃ{�b�N�X���������邩�`�F�b�N����
 * 
 * @param[in] min �{�b�N�X�̍ŏ����W.
 * @param[in] max �{�b�N�X�̍ő���W.
 * @param[in] rayPos ���C�̈ʒu.
 * @param[in] rayDir ���C�̕���.
 * @retval true ��������.
 * @retval false �������Ȃ�.
 */
bool Collision::rayIsIntersectBox
(
	const Vector3& min,
	const Vector3& max,
	const Vector3& rayPos,
	const Vector3& rayDir
)
{
	// �{�b�N�X�̉��炩�̖ʂ����C�ƌ������邩���ׂ�
	if( isIntersect( min, max, rayPos, rayDir, -rayPos.y + max.y,  rayDir.y ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.y - min.y, -rayDir.y ) == true ||
		isIntersect( min, max, rayPos, rayDir, -rayPos.x + max.x,  rayDir.x ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.x - min.x, -rayDir.x ) == true ||
		isIntersect( min, max, rayPos, rayDir, -rayPos.z + max.z,  rayDir.z ) == true ||
		isIntersect( min, max, rayPos, rayDir,  rayPos.z - min.z, -rayDir.z ) == true
		){
		// �������Ă���
		return true;
	}

	// �������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief ���C�ƃ{�b�N�X�̉��炩�̖ʂ��������邩�`�F�b�N����
 * 
 * @param[in] min �{�b�N�X�̍ŏ����W.
 * @param[in] max �{�b�N�X�̍ő���W.
 * @param[in] rayPos ���C�̈ʒu.
 * @param[in] rayDir ���C�̕���.
 * @param[in] numerator ���q.
 * @param[in] denominator ����.
 * @retval true ��������.
 * @retval false �������Ȃ�.
 */
bool Collision::isIntersect
(
	const Vector3&	min,
	const Vector3&	max,
	const Vector3&	rayPos,
	const Vector3&	rayDir,
	float			numerator,
	float			denominator
)
{
	// �����Ɩʂ����s��
	if( denominator == 0.0f ){
		return false;
	}

	// ��_�����߂�
	Vector3 v;
	v.linearEquation( rayPos, rayDir, numerator / denominator );

	const float MACH_FACTOR = 0.0001f;

	// ��_���{�b�N�X���ɑ��݂��邩
	if( v.x >= ( min.x - MACH_FACTOR ) && v.x <= ( max.x + MACH_FACTOR ) &&
		v.y >= ( min.y - MACH_FACTOR ) && v.y <= ( max.y + MACH_FACTOR ) &&
		v.z >= ( min.z - MACH_FACTOR ) && v.z <= ( max.z + MACH_FACTOR )
		){
		return true;
	}

	// �ǂ̖ʂƂ��������Ă��Ȃ�����
	return false;
}



/*===========================================================================*/
/**
 * @brief ���̂��{�b�N�X���ɑ��݂��邩�`�F�b�N����
 * 
 * @param[in] min �{�b�N�X�̍ŏ����W.
 * @param[in] max �{�b�N�X�̍ő���W.
 * @param[in] center ���̂̒��S���W.
 * @param[in] radius ���̂̔��a.
 * @retval true ���݂���.
 * @retval false ���݂��Ȃ�.
 */
bool Collision::sphereIsInsideBox
(
	const Vector3&	min,
	const Vector3&	max,
	const Vector3&	center,
	float			radius
)
{
	float distanceSq = 0.0f;

	// x���W�𒲂ׂ�
	if( center.x > max.x ){
		distanceSq += Ngl::sqr( center.x - max.x );
	}
	else if( center.x < min.x ){
		distanceSq += Ngl::sqr( min.x - center.x );
	}

	// y���W�𒲂ׂ�
	if( center.y > max.y ){
		distanceSq += Ngl::sqr( center.y - max.y );
	}
	else if( center.y < min.y ){
		distanceSq += Ngl::sqr( min.y - center.y );
	}

	// z���W�𒲂ׂ�
	if( center.z > max.z ){
		distanceSq += Ngl::sqr( center.z - max.z );
	}
	else if( center.z < min.z ){
		distanceSq += Ngl::sqr( min.z - center.z );
	}

	// ���������a�����������Z����
	if( distanceSq <= Ngl::sqr( radius ) ){
		// �{�b�N�X�̒��ɋ��̂����݂���
		return true;
	}
	// �{�b�N�X�̊O�ɋ��̂����݂���
	return false;
}



/*===========================================================================*/
/**
 * @brief �|���S���Ɛ����Ƃ̏Փ˔���
 * 
 * @param[in] vert ���_�z��ւ̃|�C���^.
 * @param[in] numVertices ���_��.
 * @param[in] planeParam ���ʕ������p�����[�^�[.
 * @param[in] line0 �����̎n�_.
 * @param[in] line1 �����̏I�_
 * return param �Փ˃p�����[�^�[
 */
const PlaneCollisionReport& Collision::polygonAndLine
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	line0,
	const Vector3&	line1
)
{
	// �Փ˃��|�[�g��������
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// ���ʂƃ��C�����Փ˂��Ă��Ȃ���
	if( planeParam.intersectLine( line0, line1 ) == false ){
		// �p�����[�^�[�����̂܂ܕԂ�
		return planeReport_;
	}

	// ��_���W�����߂�
	Vector3 tmpIntersect = planeParam.intersectLinePosition( line0, line1, tmpIntersect );

	// ��_���|���S�����ɑ��݂��邩
	if( isInsidePolygon( vert, numVertices, tmpIntersect ) == true ){
		// �Փ˃p�����[�^�[��ݒ肷��
		planeReport_.isCollision	= true;
		planeReport_.intersect		= tmpIntersect;
		planeReport_.distanceSq		= tmpIntersect.distance( line0 );
		planeReport_.planeParam		= planeParam;
	}

	// �p�����[�^�[��Ԃ�
	return planeReport_;
}
	
	
	
/*===========================================================================*/
/**
 * @brief �|���S����3D���Ƃ̏Փ˔���
 * 
 * @param[in] vert ���_�z��ւ̃|�C���^.
 * @param[in] numVertices ���_��.
 * @param[in] planeParam ���ʕ������p�����[�^�[.
 * @param[in] rayPos ���C�̎n�_.
 * @param[in] rayDir ���C�̕���.
 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Collision::polygonAndRay
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	rayPos,
	const Vector3&	rayDir
)
{
	// �Փ˃��|�[�g��������
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// ���ʂƃ��C���Փ˂��Ă��Ȃ���
	if( planeParam.intersectRay( rayPos, rayDir ) == false ){
		// �p�����[�^�[�����̂܂ܕԂ�
		return planeReport_;
	}

	// ��_���擾����
	Vector3 tmpIntersect = planeParam.intersectRayPositon( rayPos, rayDir, tmpIntersect );

	// ��_���|���S�����ɑ��݂��邩
	if( isInsidePolygon( vert, numVertices, tmpIntersect ) == true ){
		// �Փ˃p�����[�^�[��ݒ肷��
		planeReport_.isCollision	= true;
		planeReport_.intersect		= tmpIntersect;
		planeReport_.distanceSq		= tmpIntersect.distanceSq( tmpIntersect );
		planeReport_.planeParam		= planeParam;
	}
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief �|���S���Ƌ��̂Ƃ̏Փ˔���
 * 
 * @param[in] vert ���_�z��ւ̃|�C���^.
 * @param[in] numVertices ���_��.
 * @param[in] planeParam ���ʕ������p�����[�^�[.
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Collision::polygonAndSphere
(
	const Vector3*	vert,
	unsigned int	numVertices,
	Plane&			planeParam,
	const Vector3&	center,
	float			radius
)
{
	// �Փ˃��|�[�g��������
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;

	// ���̂��|���S�����ʂƌ������邩���ׂ�
	if( planeParam.getClassifySphere( center, radius ) != Plane::INTERSECTS_PLANE ){
		// �������Ȃ��ꍇ�͏Փ˂��Ȃ�
		return planeReport_;
	}

	// �|���S�����ʂƋ��̂̒��S���W�܂ł̑��΍��W�����Ƃ߂�
	float disCenter = planeParam.distance( center );

	// �I�t�Z�b�g�̃x�N�g�������߂�
	Vector3 offset;
	offset.x = planeParam.x * disCenter;
	offset.y = planeParam.y * disCenter;
	offset.z = planeParam.z * disCenter;

	// �|���S�����ʏ�ɋ��̂̒��S�ʒu��␳����
	Vector3 spherePos = center - offset;

	// �|���S���̕��ʏ�ɋ��̂̒��S���W�����݂��邩
	if( isInsidePolygon( vert, numVertices, spherePos ) == true ){
		// �Փ˃p�����[�^�[��ݒ肷��
		planeReport_.isCollision	= true;
		planeReport_.intersect		= spherePos;
		planeReport_.distanceSq		= disCenter;
		planeReport_.planeParam		= planeParam;

		return planeReport_;
	}

	// �|���S���G�b�W�Ƌ��̂̏Փ˔���
	const PlaneCollisionReport& param = polygonEdgeAndSphere( vert, numVertices, center, radius );

	// �|���S���Ƌ��̂̃G�b�W���Փ˂��Ă��邩
	if( param.isCollision == true ){
		// �p�����[�^�[��Ԃ�
		return param;
	}

	// �Փ˂��Ă��Ȃ�����
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief �|���S���̃G�b�W�Ƌ��̂Ƃ̏Փ˔���
 * 
 * @param[in] vert ���_�z��ւ̃|�C���^.
 * @param[in] numVertices ���_��.
 * @param[in] center ���̂̒��S�ʒu.
 * @param[in] radius ���̂̔��a.
 * @return ���ʃf�[�^�Փ˃p�����[�^�[.
 */
const PlaneCollisionReport& Collision::polygonEdgeAndSphere
(
	const Vector3*	vert,
	unsigned int	numVertices,
	const Vector3&	center,
	float			radius
)
{
	// �S���_�Ɣ��肷��
	for( unsigned int i=0; i<numVertices; i++ ){
		// ���̂̒��S���W�ƃ|���S�������Ԑ��������߂�
		Line3 li( vert[i], vert[ (i+1) % numVertices ] );

		// �����ɍł��߂����W�����߂�
		Vector3 point = li.findNearestPoint( center.x, center.y, center.z );

		// ������̍��W�Ƌ��̂̒��S�Ƃ̋��������߂�
		float distanceSq = point.distanceSq( center );

		// ���������a�����Z����
		if( distanceSq < Ngl::sqr( radius ) ){
			planeReport_.isCollision = true;
			planeReport_.distanceSq = distanceSq;
			planeReport_.intersect = point;
			planeReport_.planeParam.createFromPoints( vert[0], vert[1], vert[2] );

			return planeReport_;
		}
	}

	// �Փ˂��Ă��Ȃ�
	planeReport_ = PLANECOLLISIONREPORT_NOT_COLLISION;
	return planeReport_;
}



/*===========================================================================*/
/**
 * @brief �|���S�������Ɍ�_�����݂��邩
 * 
 * @param[in] vert ���_�z��ւ̃|�C���^.
 * @param[in] numVertices ���_��.
 * @param[out] point ��_���W. 
 * @retval true ���݂���.
 * @retval false ���݂��Ȃ�.
 */
bool Collision::isInsidePolygon
(
	const Vector3*	vert,
	unsigned int	numVertices,
	const Vector3&	point
)
{
	// �|���S���̊e���_�ƌ�_�����Ԑ����̊p�x�̍��v�����߂�
	float angle = 0.0f;
	for( unsigned int i=0; i<numVertices; i++ ){
		Vector3 v1 = vert[ i ] - point;
		Vector3 v2 = vert[ (i+1) % numVertices ] - point;

		// ���_�ƌ�_�Ƃ̋��������߂�
		float lenV1 = v1.length();
		float lenV2 = v2.length();

		// �ǂ��炩�̋������덷���e�͈͖�����
		float much_factor = 0.0001f;
		if( lenV1 < much_factor || lenV2 < much_factor ){
			// �Փ˂��Ă���
			return true;
		}

		// ��̃x�N�g���̂Ȃ��p�x�����߂�
		float cosTheta = v1.dot( v2 ) / ( lenV1 * lenV2 );

		// �p�x�̍��v�����߂�
		angle += Ngl::acos( Ngl::clamp( cosTheta, -1.0f, 1.0f ) );
	}

	// ���v�����p�x��360�x�ȏォ
	float much_factor = 0.99f;
	if( angle >= ( 360.0f * much_factor ) ){
		// �Փ˂��Ă���
		return true;
	}
	// �Փ˂��Ă��Ȃ�����
	return false;
}



/*===== EOF ==================================================================*/