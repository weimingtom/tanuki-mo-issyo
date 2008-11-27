/*******************************************************************************/
/**
 * @file Random.cpp.
 * 
 * @brief ���������N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Random.h"
#include	"SFMT/SFMT.h"
#include	"SFMT/SFMT.c" 
#include	<ctime>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �����̎��������( ���� )
 *
 * ���݂̎������痐�������������܂��B
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
void Random::srand()
{
	unsigned long t  = (unsigned long)time(NULL);
	::init_gen_rand( t );
}



/*=========================================================================*/
/**
 * @brief �����̎��������
 * 
 * @param[in] seed ����������l.
 * @return �Ȃ�.
 */
void Random::srand( unsigned int seed )
{
	::init_gen_rand( seed );
}



/*=========================================================================*/
/**
 * @brief 32bit�����^�̗������쐬
 * 
 * @param[in] �Ȃ�.
 * @return �Ȃ�.
 */
unsigned int Random::randi()
{
	return ::gen_rand32();
}



/*=========================================================================*/
/**
 * @brief min�`max�̊Ԃ�32bit�����^�̗������쐬
 * 
 * @param[in] min �����̍ŏ��l.
 * @param[in] max �����̍ő�l.
 * @return 32bit�����̗���.
 */
unsigned int Random::randi( unsigned int min, unsigned int max )
{
	return ( randi() % ( ( max + 1 ) - min ) ) + min;
}

	

/*=========================================================================*/
/**
 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
 * 
 * @param[in] type ���������͈�.
 * @return 32bit���������_�̗���.
 */
float Random::randf( RangeType type )
{
	return static_cast< float >( randd( type ) );
}



/*=========================================================================*/
/**
 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
 * 
 * @param[in] min �����̍ŏ��l.
 * @param[in] max �����̍ő�l.
 * @param[in] type ���������͈�.
 * @return 32bit���������_�̗���.
 */
float Random::randf( float min, float max, RangeType type )
{
	return static_cast< float >( randd( min, max, type ) );
}


	
/*=========================================================================*/
/**
 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
 * 
 * @param[in] type ���������͈�.
 * @return 32bit���������_�̗���.
 */
double Random::randd( Random::RangeType type )
{
	double result = 0.0;

	switch( type )
	{
	case RANGETYPE_REAL1:
		result = ::genrand_real1();
		break;
	case RANGETYPE_REAL2:
		result = ::genrand_real2();
		break;
	case RANGETYPE_REAL3:
		result = ::genrand_real3();
		break;
	case RANGETYPE_REAL53:
		result = ::genrand_res53();
		break;
	default:
		result = ::genrand_real1();
	}

	return result;
}

	
	
/*=========================================================================*/
/**
 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
 *
 * @param[in] min �����̍ŏ��l.
 * @param[in] max �����̍ő�l.
 * @param[in] type ���������͈�.
 * @return 32bit���������_�̗���.
 */
double Random::randd( double min, double max, RangeType type )
{
	return ( randd( type ) * ( max - min ) + min );
}

	
	
/*===== EOF ==================================================================*/