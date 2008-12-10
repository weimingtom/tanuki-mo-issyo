/*******************************************************************************/
/**
 * @file EntityGroupManager.h.
 * 
 * @brief 汎用グループマネージャクラス定義.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYGROUPMANAGER_H_
#define _NGL_ENTITYGROUPMANAGER_H_

#include	"EntityManager.h"
#include	"PairManagerVisitor.h"
#include	<map>

namespace Ngl{


/**
 * @class EntityGroupManager.
 * @brief 汎用グループマネージャクラス．
 *
 * @tparam Entity 要素.
 * @tparam GroupID グループID.
 * @tparam Manager 管理者.
 * @tparam Map 管理者を管理する連想コンテナ.
 */
template<
	class Entity,
	class GroupID	= int,
	class Manager	= EntityManager< Entity >,
	class Map		= std::map<GroupID, Manager*>
>
class EntityGroupManager
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] なし.
	 */
	EntityGroupManager(){}

	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	~EntityGroupManager()
	{
		clear();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief グループを取得する
	 * 
	 * @param[in] id 参照するグループID.
	 * @return 指定のグループマネージャ.
	 */
	Manager& operator[] ( const GroupID& id )
	{
		// グループが存在しなければ新規に作成
		if( mGroup[id] == 0 ){
			mGroup[id] = new Manager();
		}
		return *mGroup[id];
	}

	
	/*=========================================================================*/
	/**
	 * @brief 要素数をカウントする
	 * 
	 * @param[in] なし.
	 * @return 要素数.
	 */
	unsigned int count() const
	{
		unsigned int result = 0;
		for( Map::const_iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			result += (*i).second->count();
		}
		return result;
	}

	
	/*=========================================================================*/
	/**
	 * @brief 全ての要素を削除
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void clear()
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			delete (*i).second;
		}
		mGroup.clear();
	}

	
	/*=========================================================================*/
	/**
	 * @brief 要素の削除
	 * 
	 * @param[in] evaluator 評価者.
	 * @return なし.
	 */
	// 要素の削除
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			(*i).second->remove( evaluator );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief 訪問者の受け入れ
	 * 
	 * @param[in] visitor 訪問者.
	 * @return なし.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			(*i).second->accept( visitor );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief ペア訪問者の受け入れ 指定のマネージャを訪問
	 * 
	 * @param[in] first 訪問するマネージャ.
	 * @param[in] second 訪問するマネージャ.
	 * @param[in] pair ペア訪問者.
	 * @return なし.
	 */
	template <class PairVisitor>
	void acceptPair( Manager& first, Manager& second, PairVisitor& pair )
	{
		PairManagerVisitor< Entity, Manager, PairVisitor > visitor( second, pair );
		first.accept( visitor );
	}

	
	/*=========================================================================*/
	/**
	 * @brief ペア訪問者の受け入れ 全てのマネージャを訪問
	 * 
	 * @param[in] pair ペア訪問者.
	 * @return なし.
	 */
	template< class PairVisitor >
	void acceptPair( PairVisitor& pair )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			// 同一グループをペアで訪問
			(*i).second->acceptPair( pair );
			// 他のグループをペアで訪問
			Map::iterator j( i );
			for( ++j; j!=mGroup.end(); ++j ){
				acceptPair( *(*i).second, *(*j).second, pair );
			}
		}
	}

private:
	
	
	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ コピー禁止
	 * 
	 * @param[in] other 代入するグループマネージャ.
	 */
	EntityGroupManager( const EntityGroupManager& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード コピー禁止
	 * 
	 * @param[in] other 代入するグループマネージャ.
	 * @return 代入結果のグループマネージャ.
	 */
	EntityGroupManager& operator = ( const EntityGroupManager& other );

private:

	/** マネージャーグループ */
	Map	mGroup;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/