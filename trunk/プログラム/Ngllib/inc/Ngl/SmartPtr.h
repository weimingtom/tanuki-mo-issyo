/*******************************************************************************/
/**
 * @file SmartPtr.h.
 * 
 * @brief スマートポインタクラス定義.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SMARTPTR_H_
#define _NGL_SMARTPTR_H_

#include	<cassert>

namespace Ngl{


/**
 * @class SmartPtr．
 * @brief スマートポインタクラス.
 * @tparam Ptr 保持する型.
 *
 * 参照カウンタを持つスマートポインタクラスです。<br>
 * 参照カウンタが0になると、自動的に保持しているポインタを削除します。<br>
 */
template< typename Ptr >
class SmartPtr
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ
	 * 
	 * @param[in] ptr 保持するポインタ.
	 */
	explicit SmartPtr( Ptr* ptr=0 ):
			ptr_( ptr ),
			refCount_( 0 )
	{
		// 参照カウンタ用を作成
		refCount_ = new unsigned int;
		*refCount_ = 0;

		// 参照カウンタを増やす
		addRef();
	}


	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	SmartPtr( const SmartPtr< Ptr >& other )
	{
		// ポインタをそのままコピー
		ptr_ = other.ptr_;
		refCount_ = other.refCount_;

		// 参照カウンタを増やす
		addRef();
	}


	/*=========================================================================*/
	/**
	 * @brief コピーコンストラクタ
	 *
	 * 暗黙的アップキャスト用コピーコンストラクタ.
	 * 
	 * @tparam Ptr2 相手クラスの保持ポインタ型.
	 * @param[in] ptr コピーするオブジェクト.
	 */
	template < class Ptr2 >
	SmartPtr( SmartPtr< Ptr2 >& ptr )
	{
		refCount_ = ptr.refCount_;
		ptr_ = ptr.ptr_;

		// 自分自身の参照カウンタを増やす
		addRef();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief デストラクタ
	 * 
	 * @param[in] なし.
	 */
	virtual ~SmartPtr()
	{
		release();
	}


	/*=========================================================================*/
	/**
	 * @brief ポインタを設定する
	 * 
	 * @param[in] ptr 設定するポインタ.
	 * @return なし.
	 */
	void setPtr( Ptr* ptr=0 )
	{
		// 参照カウンタを減らす( すでにポインタを持っている場合の削除処理 )
		release();

		// 再初期化
		refCount_ = new unsigned int;
		*refCount_ = 0;
		ptr_ = ptr;
		addRef();
	}
	

	/*=========================================================================*/
	/**
	 * @brief 保持しているポインタを取得
	 * 
	 * @param[in] なし.
	 * @return 保持しているポインタ.
	 */
	Ptr* get()
	{
		return ptr_;
	}

	
	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	SmartPtr& operator = ( const SmartPtr< Ptr >& other )
	{
		// 自分自身へのコピーか
		if( ptr_ == other.ptr_ ){
			// 代入しない
			return *this;
		}

		// 自分の参照カウンタを減らす( 自分が他人になるため )
		release();

		// ポインタをコピー
		ptr_ = other.ptr_;
		refCount_ = other.refCount_;

		// 参照カウンタを増やす
		addRef();

		return *this;
	}


	/*=========================================================================*/
	/**
	 * @brief = 演算子オーバーロード
	 * 
	 * 明示的アップキャスト用.
	 *
	 * @tparam Ptr2 相手クラスの保持ポインタ型.
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト.
	 */
	template< class Ptr2 >
	SmartPtr< Ptr >& operator == ( const SmartPtr< Ptr2 >& other )
	{
		// 自分自身へのコピーか
		if( ptr_ == other.ptr_ ){
			// 代入しない
			return *this;
		}

		// 自分の参照カウンタを減らす( 自分が他人になるため )
		release();

		// 保持ポインタをコピー
		ptr_ = other.ptr_;

		// 参照カウンタを増やす
		addRef();

		return *this;
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief == 演算子オーバーロード
	 *
	 * 保持しているポインタとポインタが等しいか比較する.
	 * 
	 * @param[in] ptr 比較するポインタ.
	 * @retval true 同じポインタを保持.
	 * @retval false 違うポインタを保持. 
	 */
	bool operator == ( Ptr* ptr )
	{
		if( ptr_ == ptr ){
			return true;
		}
		return false;
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief != 演算子オーバーロード
	 *
	 * 保持しているポインタとポインタが等しくないか比較する.
	 * 
	 * @param[in] ptr 比較するポインタ.
	 * @retval true 違うポインタを保持.
	 * @retval false 同じポインタを保持. 
	 */
	bool operator != ( Ptr* ptr )
	{
		return !( *this == ptr );
	}


	/*=========================================================================*/
	/**
	 * @brief -> 演算子オーバーロード
	 *
	 * 保持しているポインタにアクセスする.
	 * 
	 * @param[in] なし.
	 * @return 保持しているポインタ.
	 */
	Ptr* operator -> ()
	{
		return ptr_;
	}


	/*=========================================================================*/
	/**
	 * @brief * 演算子オーバーロード
	 *
	 * 保持しているポインタを間接参照する.
	 * 
	 * @param[in] なし.
	 * @return 保持しているポインタ.
	 */
	Ptr& operator * ()
	{
		return *ptr_;
	}


	/*=========================================================================*/
	/**
	 * @brief [] 演算子オーバーロード
	 *
	 * 保持しているポインタ配列の要素を返す
	 * ( ポインタ配列を保持している場合のみ有効 ).
	 * 
	 * @param[in] index 取得する要素番号.
	 * @return 保持しているポインタ.
	 */
	Ptr& operator [] ( int index )
	{
		return ptr_[ index ];
	}

private:

	/*=========================================================================*/
	/**
	 * @brief 参照カウンタを増やす
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void addRef()
	{
		(*refCount_)++;
	}


	/*=========================================================================*/
	/**
	 * @brief 解放処理
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void release()
	{
		--(*refCount_);

		// 参照カウンタが0か
		if( *refCount_ <= 0 ){
			// ポインタと参照カウンタを削除
			delete[] ptr_;
			delete refCount_;
			refCount_ = 0;
		}
	}

private:

	/** 保持しているポインタ */
	Ptr*			ptr_;

	/** 参照カウンタ */
	unsigned int*	refCount_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/