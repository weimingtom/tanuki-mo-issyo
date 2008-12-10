/*******************************************************************************/
/**
 * @file BubbleSorter.h.
 * 
 * @brief �o�u���\�[�g�N���X��`.
 *
 * @date 2008/09/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_BUBBLESORTER_H_
#define _NGL_BUBBLESORTER_H_


namespace Ngl{


/**
 * @class BubbleSorter�D
 * @brief �o�u���\�[�g�N���X.
 * @tparam Entity �v�f.
 * @tparam PairEvaluator �y�A�]����.
 */
template
<
	typename Entity,
	typename PairEvaluator
>
class BubbleSorter
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] evaluator �����Ɏg�p����y�A�]����.
	 */
	BubbleSorter( PairEvaluator evaluator ):
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
		bool swapped = false;
		
		do{
			Itor curr = first;
			Itor next = curr;
			++next;
			swapped = false;
			while( next != last ){
				if( mEvaluator.evaluate( *next, *curr ) ){
					std::iter_swap(curr, next);
					swapped = true;
				}
				++curr; ++next;
			}
			
			--last;
		}while( swapped );
	}

private:

	/** �y�A�]���� */
	PairEvaluator	mEvaluator;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/