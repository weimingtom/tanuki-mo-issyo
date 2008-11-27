/*******************************************************************************/
/**
 * @file CombSorter.h.
 * 
 * @brief コムソートクラス定義.
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
 * @class CombSorter．
 * @brief コムソートクラス.
 * @tparam Entity 要素.
 * @tparam PairEvaluator ペア評価者.
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
	 * @brief コンストラクタ
	 * 
	 * @param[in] evaluator 交換に使用するペア評価者.
	 */
	CombSorter( PairEvaluator evaluator ):
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
		// 先頭と末尾の距離を求める
		int gap = static_cast<int>( std::distance( first, last ) );
		if ( gap < 1 ) {
			return;
		}

		Itor first2 = last;
		bool swapped = false;	// 入れ替えフラグ
		
		do{
			int newgap = (gap*10+3)/13;
			if ( newgap < 1 ){
				newgap = 1;
			}

			std::advance(first2, newgap - gap);
			gap = newgap;
			swapped = false;
		 
			for( Itor target1 = first, target2 = first2; target2 != last; ++target1, ++target2 ){
				// 並び替えが必要か
				if( mEvaluator.evaluate( *target2, *target1 ) ){
					// 要素を入れ替える
					std::iter_swap(target1, target2);
					swapped = true;
				}
			}
		}while( (gap > 1) || swapped );
	}

private:

	/** ペア評価者 */
	PairEvaluator	mEvaluator;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/