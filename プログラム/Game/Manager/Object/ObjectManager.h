/*******************************************************************************/
/**
 * @file ObjectManager.h.
 * 
 * @brief オブジェクト管理クラスの定義.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _OBJECT_MANAGER_H_
#define _OBJECT_MANAGER_H_

/*===== インクルード ==========================================================*/
#include	<vector>
#include	"Manager/Object/ObjectManagerMediator.h"
#include	"Manager/Object/ObjectFactoryBase.h"


/**
 * @brief ObjectManager．
 */
class ObjectManager : public ObjectManagerMediator
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	ObjectManager();
	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~ObjectManager();

	/*=========================================================================*/
	/**
	 * @brief 初期化処理.
	 * 
	 */
	void Initialize();
	/*=========================================================================*/
	/**
	 * @brief 終了処理.
	 * 
	 */
	void Terminate();
	/*=========================================================================*/
	/**
	 * @brief 終了しているかどうか.
	 * 
	 * @return 終了フラグ.
	 */
	bool IsTerminated();

	/*=========================================================================*/
	/**
	 * @brief オブジェクトの追加.
	 * 
	 * @param[in] objectID 追加するオブジェクト.
	 */
	void AddObject(int objectID);
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの削除.
	 * 
	 * @param[in] object 削除するオブジェクト.
	 */
	void DelObject(ObjectBase* object);
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの描画処理.
	 * 
	 */
	void RenderObject();
	/*=========================================================================*/
	/**
	 * @brief オブジェクトの更新処理.
	 * 
	 * @param[in] frameTimer 更新タイマ.
	 */
	void UpdateObject(float frameTimer);

	/*=========================================================================*/
	/**
	 * @brief オブジェクトファクトリの設定.
	 * 
	 * @param[in] objectFactory 設定するファクトリ.
	 */
	void SetFactory(ObjectFactoryBase* objectFactory);

private:

	/** オブジェクトファクトリ */
	ObjectFactoryBase* m_objectFactory;
	/** オブジェクトリスト */
	std::vector<ObjectBase*> m_object;
	/** 終了フラグ */
	bool m_isTerminated;

};

#endif

/*===== EOF ===================================================================*/