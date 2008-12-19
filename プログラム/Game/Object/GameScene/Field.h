/*******************************************************************************/
/**
 * @file Field.h.
 * 
 * @brief ファイル説明.
 *
 * @date 2008/12/08.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/
#ifndef _FIELD_H_
#define _FIELD_H_

/*===== インクルード ==========================================================*/
#include	"IGameDevice.h"
#include	"Manager/Object/ObjectManager.h"
#include	"Object/ObjectBase.h"
#include	"Scene/GameSceneState.h"
#include	"Manager/Scene/Option/Option.h"
#include	"Define/GameDefine.h"

class		Player;
class		IGameDevice;

/**
 * @brief クラス名．
 */
class Field : public ObjectBase
{

public:

	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 * 
	 * @param[in] device ゲームデバイス.
	 * @param[in] objectManager オブジェクトマネージャ.
	 * @param[in] option ゲームオプション.
	 * @param[in] gameSceneState ゲームシーンステート.
	 */
	Field(IGameDevice& device, ObjectManager& objectManager, Option& option, GameSceneState& gameSceneState, Player& player);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Field();

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
	 * @brief 関数説明.
	 * 
	 * @param[in] 引数名 引数説明.
	 * @return 戻り値説明.
	 */
	void GetFieldBlockMatrix(FieldMatrix* fieldMatrix);
	
	/*=========================================================================*/
	/**
	 * @brief 関数説明.
	 * 
	 * @param[in] 引数名 引数説明.
	 * @return 戻り値説明.
	 */
	void GetFieldStateMatrix(FieldMatrix* fieldMatrix);
	Vector2 GetPosition();

	void SetBlock(int x, int y, int id);

	/*=========================================================================*/
	/**
	 * @brief 関数説明.
	 * 
	 * @param[in] 引数名 引数説明.
	 * @return 戻り値説明.
	 */
	void CheckBlock( void );

	/*=========================================================================*/
	/**
	 * @brief 関数説明.
	 * 
	 * @param[in] 引数名 引数説明.
	 * @return 戻り値説明.
	 */
	void BlockCount( int x, int y, int id, int &num, CheckMatrix & checkMatrix);
	void BlockDelete( int x, int y);
	void ChangeToFallBlock();


private:

	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;
	/** オブジェクトマネージャメディエータ */
	ObjectManager& m_objectManager;
	/** ゲームオプション */
	Option& m_option;
	/** ゲームシーンステート */
	GameSceneState& m_gameSceneState;
	/** プレーヤ */
	Player& m_player;

	/** X位置 */
	float m_x;
	/** Y位置 */
	float m_y;
	/** ブロックのサイズ */

	int m_fieldBlock[FIELD_WIDTH][FIELD_HEIGHT];
	int m_fieldState[FIELD_WIDTH][FIELD_HEIGHT];

};

#endif

/*===== EOF ===================================================================*/