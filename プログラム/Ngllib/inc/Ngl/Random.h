/*******************************************************************************/
/**
 * @file Random.h.
 * 
 * @brief ���������N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/23.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RANDOM_H_
#define _NGL_RANDOM_H_

namespace Ngl{


/**
 * @class Random�D
 * @brief ���������N���X.
 *
 * SFMT�i�����Z���k�c�C�X�^�[�j�ɂ�闐���𐶐����郆�[�e�B���e�B�N���X�ł��B
 */
class Random
{

public:

	/*=========================================================================*/
	/**
	 * @brief �����̎��������( ���� )
	 *
	 * ���݂̎������痐�������������܂��B
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	static void srand();
	
	
	/*=========================================================================*/
	/**
	 * @brief �����̎��������
	 * 
	 * @param[in] seed ����������l.
	 * @return �Ȃ�.
	 */
	static void srand( unsigned int seed );


	/*=========================================================================*/
	/**
	 * @brief 32bit�����^�̗������쐬
	 * 
	 * @param[in] �Ȃ�.
	 * @return 32bit�����̗���.
	 */
	static unsigned int randi();


	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] min �����̍ŏ��l.
	 * @param[in] max �����̍ő�l.
	 * @return 32bit�����̗���.
	 */
	static unsigned int randi( unsigned int min, unsigned int max );

public:

	/**
	 * @enum Random::RangeType.
	 * @brief �����������񋓌^.
	 */
	enum RangeType
	{
		RANGETYPE_REAL1	= 0,	/**< [0,1] (0��1���܂�) (32�r�b�g���x)				*/
		RANGETYPE_REAL2,		/**< [0,1) (0�͊܂ނ��A1�͊܂܂Ȃ�) (32�r�b�g���x)	*/
		RANGETYPE_REAL3,		/**< (0,1) (0��1���܂܂Ȃ�) (32�r�b�g���x)			*/
		RANGETYPE_REAL53		/**< [0,1) (0�͊܂ނ��A1�͊܂܂Ȃ�) (53�r�b�g���x)	*/
	};

public:

	/*=========================================================================*/
	/**
	 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	static float randf( RangeType type=RANGETYPE_REAL1 );
	
	
	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	static float randf( float min, float max, RangeType type=RANGETYPE_REAL1 );

	
	/*=========================================================================*/
	/**
	 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	static double randd( RangeType type=RANGETYPE_REAL1 );


	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	static double randd( double min, double max, RangeType type=RANGETYPE_REAL1 );
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/