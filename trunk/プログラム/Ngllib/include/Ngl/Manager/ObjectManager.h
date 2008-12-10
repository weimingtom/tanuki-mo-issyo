/*******************************************************************************/
/**
 * @file ObjectManager.h.
 * 
 * @brief オブジェクト管理者クラステンプレート定義.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OBJECTMANAGER_H_
#define _NGL_OBJECTMANAGER_H_

#include	"DefaultDestroy.h"
#include	<map>

namespace Ngl{


/**
 * @class ObjectManager．
 * @brief オブジェクト管理者クラステンプレート.
 *
 * @tparam ID 管理要素ID.
 * @tparam Entity 管理要素.
 * @tparam Destroy 削除ポリシー.
 *
 * 汎用オブジェクト管理者クラス。<br>
 * EntityManagerと共通の部品を使って作成されています。<br>
 * IDで要素を管理できるのが、EntityManagerと違うところ。<br>
 */
template
<
	class ID,
	class Entity,
	class Destroy = DefaultDestroy,
	class Map = std::map< ID, Entity >
>
class ObjectManager
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	ObjectManager()
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~ObjectManager()
	{
		clear();
	}


	/*=========================================================================*/
	/**
	 * @brief 要素を追加
	 * 
	 * 指定IDのコンテナに要素を格納します。
	 * 同じIDの要素がすでに存在してた場合は、以前の要素を削除した後、新しい要素を設定します。
	 *
	 * @param[in] id 追加する要素ID.
	 * @param[in] entity 追加する要素.
	 * @return なし.
	 */
	void add( ID id, Entity entity )
	{
		remove( id );

		entityContainer_[ id ] = entity;
	}


	/*=========================================================================*/
	/**
	 * @brief 指定のIDが存在するか
	 * 
	 * @param[in] id 検索するID.
	 * @retval true 存在していた.
	 * @retval false 存在していない.
	 */
	bool isExist( ID id )
	{
		if( entityContainer_.find( id ) != entityContainer_.end() ){
			return true;
		}
		return false;
	}


	/*=========================================================================*/
	/**
	 * @brief 訪問者を受け入れる
	 * 
	 * 保持しているすべての要素を訪問します。
	 *
	 * @tparam Visitor 訪問者.
	 * @param[in] visitor 訪問者の参照.
	 * @return なし.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( Map::iterator i( entityContainer_.begin() ); i != entityContainer_.end(); ++i ){
			visitor.visit( i->second );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief ペア訪問者の受け入れ
	 * 
	 * 保持しているすべての要素をと要素を総当りで訪問します。
	 *
	 * @tparam PairVisitor ペア訪問者.
	 * @param[in] pair ペア訪問者の参照.
	 * @return なし.
	 */
	template<class PairVisitor>
	void acceptPair( PairVisitor& pair )
	{
		for( Map::iterator i(  entityContainer_.begin() ); i !=  entityContainer_.end(); ++i ){
			Map::iterator j( i );
			for( ++j; j !=  entityContainer_.end(); ++j ){
				pair.visit( i->second, j->second );
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief 指定のIDを削除
	 * 
	 * @param[in] id 削除するID.
	 * @return なし.
	 */
	void remove( ID id )
	{
		Map::iterator itor;
		itor = entityContainer_.find( id );
		if( itor != entityContainer_.end() ){
			Destroy::destroy( itor->second );
			entityContainer_.erase( itor );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief 要素の削除
	 * 
	 * すべての要素を評価者が評価します。<br>
	 * 評価が「真」の場合、その要素を削除します。
	 *
	 * @tparam Evaluator 評価者.
	 * @param[in] evaluator 評価者の参照.
	 * @return なし
	 */
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		Map::iterator i( entityContainer_..begin() );
		while( i != entityContainer_.end() ){
			if( evaluator.evaluate( i->second ) == true ){
				Destroy::destroy( i->second );
				i = mEntityList.erase( i );
			}
			else{
				++i;
			}
		}
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief 管理要素をすべて削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clear()
	{
		Map::iterator itor = entityContainer_.begin();
		while( itor != entityContainer_.end() ){
			Destroy::destroy( itor->second );
			itor = entityContainer_.erase( itor );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief 要素数を取得する
	 * 
	 * @param[in] なし.
	 * @return 要素数.
	 */
	unsigned int size()
	{
		return (unsigned int)entityContainer_.size();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief 要素が空か
	 * 
	 * @param[in] なし.
	 * @retval true 要素が存在している.
	 * @retval false 要素が存在していない.
	 */
	bool empty()
	{
		return entityContainer_.empty();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 * 
	 * idで指定した要素を取得する。
	 *
	 * @param[in] id 参照するID.
	 * @return idの要素.
	 */
	Entity& operator [] ( ID id )
	{
		return entityContainer_[ id ];
	}

private:

	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ(コピー禁止処理)
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	ObjectManager( const ObjectManager& other );


	/*=========================================================================*/
	/**
	 * @brief =演算子オーバーロード(コピー禁止処理)
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	ObjectManager& operator = ( const ObjectManager& other );

private:

	/** 要素コンテナ */
	Map		entityContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/