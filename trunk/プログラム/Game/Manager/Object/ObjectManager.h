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

#include	"Manager/Object/ObjectFactory.h"
#include	"Manager/Object/EffectFactory.h"

/**
 * @brief ObjectManager．
 */
class ObjectManager
{
public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	ObjectManager(IGameDevice &device, Option &option);
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
	void AddObject(ObjectBase* object);
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

	ObjectFactory& GetObjectFactory();
	EffectFactory& GetEffectFactory();

	void AddEffect(ObjectBase* object);
	void DelEffect(ObjectBase* object);
	void RenderEffect();
	void UpdateEffect(float frameTimer);

private:

	/** オブジェクトファクトリ */
	ObjectFactory* m_objectFactory;
	EffectFactory* m_effectFactory;
	/** オブジェクトリスト */
	std::vector<ObjectBase*> m_object;
	/** エフェクトリスト */
	std::vector<ObjectBase*> m_effect;
	/** 終了フラグ */
	bool m_isTerminated;
	
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** ゲームオプション */
	Option& m_option;
	

};

#endif

/*===== EOF ===================================================================*/