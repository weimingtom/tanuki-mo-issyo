/*******************************************************************************/
/**
 * @file Random.cpp.
 * 
 * @brief ���������N���X�\�[�X�t�@�C��.
 *
 * @date 2008/07/23.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Random/Random.h"
#include	<ctime>
#include	<cstdlib>

using namespace Ngl;

/*=========================================================================*/
/**
 * @brief �R���X�g���N�^
 *
 * @param[in] �Ȃ�.
 */
Random::Random()
{
	srand();
}



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
	srand( (unsigned int)time( 0 ) );
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
	::srand( seed );
}



/*=========================================================================*/
/**
 * @brief 32bit�����^�̗������쐬
 * 
 * @param[in] �Ȃ�.
 * @return 32bit�����̗���.
 */
unsigned int Random::randi()
{
	return rand();
}



/*=========================================================================*/
/**
 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
 * 
 * @param[in] min �����̍ŏ��l.
 * @param[in] max �����̍ő�l.
 * @return 32bit�����̗���.
 */
unsigned int Random::randi( unsigned int min, unsigned int max )
{
	return ( rand() / RAND_MAX ) * ( max - min ) + min;
}



/*=========================================================================*/
/**
 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
 * 
 * @param[in] �Ȃ�.
 * @return 32bit���������_�̗���.
 */
float Random::randf()
{
	return ( (float)rand() / RAND_MAX );
}



/*=========================================================================*/
/**
 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
 * 
 * @param[in] �Ȃ�.
 * @return 32bit���������_�̗���.
 */
float Random::randf( float min, float max )
{
	return ( (float)rand() / RAND_MAX ) * ( max - min ) + min;
}



/*=========================================================================*/
/**
 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
 * 
 * @param[in] �Ȃ�.
 * @return 32bit���������_�̗���.
 */
double Random::randd()
{
	return ( (double)rand() / RAND_MAX );
}



/*=========================================================================*/
/**
 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
 * 
 * @param[in] �Ȃ�.
 * @return 32bit���������_�̗���.
 */
double Random::randd( double min, double max )
{
	return ( (double)rand() / RAND_MAX ) * ( max - min ) + min;
}



/*===== EOF ==================================================================*/