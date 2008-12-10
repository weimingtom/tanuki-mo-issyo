/*******************************************************************************/
/**
 * @file EntityManager.h.
 * 
 * @brief 汎用マネージャークラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYMANAGER_H_
#define _NGL_ENTITYMANAGER_H_

#include	"DefaultDestroy.h"
#include	<list>
#include	<algorithm>

namespace Ngl{


/**
 * @class EntityManager.
 * @brief 汎用マネージャークラス.
 *
 * @tparam Entity 要素
 * @tparam Destroy 削除方法を示すポリシークラス.
 * @tparam List コンテナの種類をあらわすポリシークラス.
 */
template
<
	class Entity,						
	class Destroy	= DefaultDestroy,	
	class List		= std::list<Entity>	
>
class EntityManager
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	EntityManager(){}

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] 引数名 引数説明.
	 */
	~EntityManager()
	{
		clear();
	}

	
	/*=========================================================================*/
	/**
	 * @brief 要素を追加する
	 * 
	 * @param[in] entity 追加する要素.
	 * @return なし.
	 */
	void add( Entity entity )
	{
		mEntityList.push_back( entity );
	}


	/*=========================================================================*/
	/**
	 * @brief 要素数を取得する
	 * 
	 * @param[in] なし.
	 * @return 要素数.
	 */
	unsigned int count() const
	{
		return static_cast< unsigned int >( mEntityList.size() );
	}


	/*=========================================================================*/
	/**
	 * @brief 訪問者を受け入れる
	 * 
	 * @tparam Visitor 訪問者.
	 * @param[in] visitor 訪問者.
	 * @return なし.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			visitor.visit( *i );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief ペア訪問者の受け入れ
	 * 
	 * @tparam PairVisitor ペア訪問者.
	 * @param[in] pair ペア訪問者.
	 * @return なし.
	 */
	template<class PairVisitor>
	void acceptPair( PairVisitor& pair )
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			List::iterator j( i );
			for( ++j; j != mEntityList.end(); ++j ){
				pair.visit( *i, *j );
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief 要素の削除
	 * 
	 * @tparam Evaluator 評価者.
	 * @param[in] evaluator 評価者.
	 * @return なし
	 */
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		List::iterator i( mEntityList.begin() );
		while( i != mEntityList.end() ){
			if( evaluator.evaluate( *i ) == true ){
				Destroy::destroy( *i );
				i = mEntityList.erase( i );
			}
			else{
				++i;
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief 要素の並び替え
	 * 
	 * @param[in] sorter 交換者.
	 * @return なし
	 */
	template<class Sorter>
	void sort( Sorter& sorter )
	{
		sorter.sort(
			mEntityList.begin(),
			mEntityList.end()
			);
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief 要素の全削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clear()
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			Destroy::destroy( *i );
		}
		mEntityList.clear();
	}

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止処理)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	EntityManager( const EntityManager& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード(コピー禁止処理)
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	EntityManager& operator = ( const EntityManager& other );

private:

	/** 要素リスト */
	List		mEntityList;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/