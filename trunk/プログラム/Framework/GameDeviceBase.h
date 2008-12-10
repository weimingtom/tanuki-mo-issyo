/*******************************************************************************/
/**
 * @file GameDeviceBase.h.<br>
 * 
 * @brief ゲームデバイス基底クラス定義.<br>
 *
 * @date 2008/10/27.<br>
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _GAMEDEVICEBASE_H_
#define _GAMEDEVICEBASE_H_

#include	"IGameDevice.h"
#include	<Ngl/IFrameWork.h>


/**
 * @brief ゲームデバイス基底クラス
 * @tparam Graphic グラフィックデバイス.
 * @tparam Input 入力デバイス.
 * @tparam Sound サウンドデバイス.
 */
template
<
	class Graphic,
	class Input,
	class Sound
>
class GameDeviceBase : public IGameDevice
{
public:

	/**
	 * @brief コンストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	GameDeviceBase():
		frame_( 0 ),
		graphics_( 0 ),
		sound_( 0 ),
		input_( 0 )
	{}

	
	/**
	 * @brief デストラクタ<br>
	 * 
	 * @param[in] なし.
	 */
	virtual ~GameDeviceBase()
	{}
	
	
	/**
	 * @brief 作成処理<br>
	 * 
	 * @param[in] frame フレームワーク.
	 * @return なし.
	 */
	void Create( Ngl::IFrameWork& frame )
	{
		CreateDevice( frame );

		// ウィンドウハンドルを保存
		frame_ = &frame;
	}

	
	/**
	 * @brief 更新処理<br>
	 * 
	 * @param[in] frameTimer フレーム処理補正値.
	 * @return なし.
	 */
	virtual void Update( float frameTimer )
	{
		// キー入力を取得する
		input_->Reload();

		// サウンドデバイスを更新する
		sound_->Update( frameTimer );
	}

	
	/**
	 * @brief 終了処理<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	void End()
	{
		graphics_->End();

		delete graphics_;
		delete sound_;
		delete input_;
	}
	
	
	/**
	 * @brief グラフィックデバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return グラフィックデバイス.
	 */
	virtual IGraphicDevice& GetGraphicDevice()
	{
		return *graphics_;
	}

	
	/**
	 * @brief サウンドデバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return サウンドデバイス.
	 */
	virtual ISoundDevice& GetSoundDevice()
	{
		return *sound_;
	}
	
	
	/**
	 * @brief 入力デバイスを取得<br>
	 * 
	 * @param[in] なし.
	 * @return 入力デバイス.
	 */
	virtual IInputDevice& GetInputDevice()
	{
		return *input_;
	}

	
	/**
	 * @brief ウィンドウハンドルを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウハンドル.
	 */
	virtual void* GetHWND()
	{
		return frame_->getHWND();
	}

	
	/**
	 * @brief ウィンドウ幅を取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウ幅.
	 */
	virtual int GetWindowWidth()
	{
		return frame_->desc().windowWidth;
	}

	
	/**
	 * @brief ウィンドウの高さを取得<br>
	 * 
	 * @param[in] なし.
	 * @return ウィンドウの高さ.
	 */
	virtual int GetWindowHeight()
	{
		return frame_->desc().windowHeight;
	}


	/**
	 * @brief ゲームを終了する<br>
	 * 
	 * @param[in] なし.
	 * @return なし.
	 */
	virtual void Exit()
	{
		frame_->exit();
	}
	
protected:

	/**
	 * @brief デバイスの作成処理<br>
	 * 
	 * @param[in] frame フレームワーク.
	 * @return なし.
	 */
	virtual void CreateDevice( Ngl::IFrameWork& frame ) = 0;

private:

	/**
	 * @brief コピーコンストラクタ( コピー禁止 )<br>
	 * 
	 * @param[in] other コピーするオブジェクト.
	 */
	GameDeviceBase( const GameDeviceBase& other );


	/**
	 * @brief = 演算子オーバーロード( コピー禁止 )<br>
	 * 
	 * @param[in] other 代入するオブジェクト.
	 * @return 代入結果のオブジェクト
	 */
	GameDeviceBase& operator = ( const GameDeviceBase& other );

protected:

	/** フレームワーク */
	Ngl::IFrameWork*	frame_;

	/** グラフィックデバイス */
	Graphic*			graphics_;

	/** サウンドデバイス */
	Sound*				sound_;

	/** 入力デバイス */
	Input*				input_;

};

#endif

/*===== EOF ==================================================================*/