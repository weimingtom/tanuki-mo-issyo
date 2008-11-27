/*******************************************************************************/
/**
 * @file MatrixStacker.cpp.
 * 
 * @brief 行列スタッククラスソースファイル.
 *
 * @date 2008/10/19.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	<Ngl/MatrixStacker.h>

using namespace Ngl;

/*===========================================================================*/
/**
 * @brief コンストラクタ
 * 
 * @param[in] なし.
 */
MatrixStacker::MatrixStacker()
{}



/*=========================================================================*/
/**
 * @brief デストラクタ
 * 
 * @param[in] なし.
 */
MatrixStacker::~MatrixStacker()
{
	clearList();
}
	
	
	
/*===========================================================================*/
/**
 * @brief 初期化処理
 * 
 * @param[in] なし.
 * @return なし.
 */
void MatrixStacker::initialize()
{
	// リストを削除
	clearList();

	// 単位行列をひとつプッシュ
	push();
}



/*=========================================================================*/
/**
 * @brief 単位行列をプッシュする
 * 
 * @param[in] なし.
 * @return なし.
 */
void MatrixStacker::push()
{
	stack_.push( Ngl::MATRIX4_IDENTITY );
}



/*=========================================================================*/
/**
 * @brief 先頭の行列をポップする
 * 
 * @param[in] なし.
 * @return なし.
 */
void MatrixStacker::pop()
{
	if( isEmpty() == true ){
		return;
	}

	// 要素が1つならポップしない
	if( stack_.size() == 1 ){
		return;
	}
	
	stack_.pop();
}



/*===========================================================================*/
/**
 * @brief リストをすべて削除
 * 
 * @param[in] なし.
 * @return なし.
 */
void MatrixStacker::clearList()
{
	while( stack_.empty() == false ){
		stack_.pop();
	}
}



/*===========================================================================*/
/**
 * @brief 現在の行列に行列を乗算する
 * 
 * @param[in] なし.
 * @return なし.
 */
void MatrixStacker::multiply( const Ngl::Matrix4& matrix )
{
	// 要素があるか
	if( stack_.empty() == true ){
		return;
	}
		
	// 先頭の要素に乗算
	stack_.top() *= matrix;
}



/*=========================================================================*/
/**
 * @brief 結果を取得する
 * 
 * @param[in] なし.
 * @return result.
 */
const Ngl::Matrix4& MatrixStacker::getResult() const
{
	return stack_.top();
}


/*=========================================================================*/
/**
 * @brief 要素が空か調べる
 * 
 * @param[in] なし.
 * @retval true 要素がある.
 * @retval false 要素が無い.
 */
bool MatrixStacker::isEmpty()
{
	return stack_.empty();
}



/*========= EOF =============================================================*/