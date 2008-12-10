/*******************************************************************************/
/**
 * @file RandomSFMT.h.
 * 
 * @brief �����Z���k�c�C�X�^�[���������N���X�w�b�_�t�@�C��.
 *
 * @date 2008/07/23.
 * 
 * @version 2.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_RANDOMSFMT_H_
#define _NGL_RANDOMSFMT_H_

namespace Ngl{


/**
 * @class RandomSFMT�D
 * @brief �����Z���k�c�C�X�^�[���������N���X.
 */
class RandomSFMT
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 *
	 * @param[in] �Ȃ�.
	 */
	RandomSFMT();
	
	
	/*=========================================================================*/
	/**
	 * @brief �����̎��������( ���� )
	 *
	 * ���݂̎������痐�������������܂��B
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void srand();
	
	
	/*=========================================================================*/
	/**
	 * @brief �����̎��������
	 * 
	 * @param[in] seed ����������l.
	 * @return �Ȃ�.
	 */
	void srand( unsigned int seed );


	/*=========================================================================*/
	/**
	 * @brief 32bit�����^�̗������쐬
	 * 
	 * @param[in] �Ȃ�.
	 * @return 32bit�����̗���.
	 */
	unsigned int randi();


	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] min �����̍ŏ��l.
	 * @param[in] max �����̍ő�l.
	 * @return 32bit�����̗���.
	 */
	unsigned int randi( unsigned int min, unsigned int max );

public:

	/**
	 * @enum RangeType.
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
	float randf( RangeType type=RANGETYPE_REAL1 );
	
	
	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	float randf( float min, float max, RangeType type=RANGETYPE_REAL1 );

	
	/*=========================================================================*/
	/**
	 * @brief 32bit���������_�^�̗���( 0.0�`1.0 )���쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	double randd( RangeType type=RANGETYPE_REAL1 );


	/*=========================================================================*/
	/**
	 * @brief min�ȏ�max�ȉ��̊Ԃ�32bit�����^�̗������쐬
	 * 
	 * @param[in] type ���������͈�.
	 * @return 32bit���������_�̗���.
	 */
	double randd( double min, double max, RangeType type=RANGETYPE_REAL1 );
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/