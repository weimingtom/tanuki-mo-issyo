/*******************************************************************************/
/**
 * @file BubbleSorter.h.
 * 
 * @brief バブルソートクラス定義.
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
 * @class BubbleSorter．
 * @brief バブルソートクラス.
 * @tparam Entity 要素.
 * @tparam PairEvaluator ペア評価者.
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
	 * @brief コンストラクタ
	 * 
	 * @param[in] evaluator 交換に使用するペア評価者.
	 */
	BubbleSorter( PairEvaluator evaluator ):
	  mEvaluator( evaluator )
	{}


	/*=========================================================================*/
	/**
	 * @brief 要素の並び替え
	 * 
	 * @tparam Itor イテレータ.
	 *
	 * @param[in] first 並び替えするリストの開始位置反復子.
	 * @param[in] last 並び替えするリストの終了位置反復子.
	 * @return なし.
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

	/** ペア評価者 */
	PairEvaluator	mEvaluator;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/