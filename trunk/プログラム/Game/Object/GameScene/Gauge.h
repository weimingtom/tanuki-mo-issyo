/*******************************************************************************/
/**
 * @file Gauge.h.
 * 
 * @brief ゲージクラスヘッダ定義.
 *
 * @date 2008/12/18.
 *
 * @version 1.00.
 *
 * @author Ryouma Kawasue.
 */
/*******************************************************************************/
#ifndef _GAUGE_H_
#define _GAUGE_H_

#include	"IGameDevice.h"
#include	"Object/ObjectBase.h"

class Gauge : public ObjectBase
{
public:
	/*=========================================================================*/
	/**
	 * @brief コンストラクタ.
	 *
	 */
	Gauge(IGameDevice& device, int tex1, int tex2, Vector2 position, Vector2 size, float max, float point);

	/*=========================================================================*/
	/**
	 * @brief デストラクタ.
	 *
	 */
	~Gauge();

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

	void SetTexture(int tex1, int tex2 );

	void SetMax(float max);

	void SetPoint(float point);

	void SetPosition(Vector2 position);

	void SetSize(Vector2 size);


	private:
	/** 終了フラグ */
	bool m_isTerminated;
	/** ゲームデバイス */
	IGameDevice& m_device;

	/** y座標　*/
	float m_y;
	/** x座標　*/
	float m_x;
	/** 最大横幅 */
	float m_max;
	/** ゲージの位置 */
	float m_point;
	/** サイズ */
	Vector2 m_size;

	Vector2 m_position;

	int m_texture1;
	int m_texture2;
};

#endif

/*===== EOF ===================================================================*/

