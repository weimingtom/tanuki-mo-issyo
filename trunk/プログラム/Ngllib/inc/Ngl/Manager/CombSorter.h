/*******************************************************************************/
/**
 * @file CombSorter.h.
 * 
 * @brief �R���\�[�g�N���X��`.
 *
 * @date 2008/09/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_COMSORTER_H_
#define _NGL_COMSORTER_H_


namespace Ngl{


/**
 * @class CombSorter�D
 * @brief �R���\�[�g�N���X.
 * @tparam Entity �v�f.
 * @tparam PairEvaluator �y�A�]����.
 */
template
<
	typename Entity,
	typename PairEvaluator
>
class CombSorter
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] evaluator �����Ɏg�p����y�A�]����.
	 */
	CombSorter( PairEvaluator evaluator ):
	  mEvaluator( evaluator )
	{}


	/*=========================================================================*/
	/**
	 * @brief �v�f�̕��ёւ�
	 * 
	 * @tparam Itor �C�e���[�^.
	 *
	 * @param[in] first ���ёւ����郊�X�g�̊J�n�ʒu�����q.
	 * @param[in] last ���ёւ����郊�X�g�̏I���ʒu�����q.
	 * @return �Ȃ�.
	 */
	template< class Itor >
	void sort( Itor first, Itor last )
	{
		// �擪�Ɩ����̋��������߂�
		int gap = static_cast<int>( std::distance( first, last ) );
		if ( gap < 1 ) {
			return;
		}

		Itor first2 = last;
		bool swapped = false;	// ����ւ��t���O
		
		do{
			int newgap = (gap*10+3)/13;
			if ( newgap < 1 ){
				newgap = 1;
			}

			std::advance(first2, newgap - gap);
			gap = newgap;
			swapped = false;
		 
			for( Itor target1 = first, target2 = first2; target2 != last; ++target1, ++target2 ){
				// ���ёւ����K�v��
				if( mEvaluator.evaluate( *target2, *target1 ) ){
					// �v�f�����ւ���
					std::iter_swap(target1, target2);
					swapped = true;
				}
			}
		}while( (gap > 1) || swapped );
	}

private:

	/** �y�A�]���� */
	PairEvaluator	mEvaluator;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/