/*******************************************************************************/
/**
 * @file Manipulator.cpp.
 * 
 * @brief マニピュレータ定義ソースファイル.
 *
 * @date 2008/07/13.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#include	"Ngl/Manipulator.h"

/**
 * @name oct
 * @brief 8進数読み込みマニピュレータ.
 */
Ngl::IInputStream& Ngl::oct( Ngl::IInputStream& stream )
{
	stream.readType( Ngl::STREAM_READ_TYPE_8 );
	return stream;
}



/**
 * @name dec
 * @brief 10進数読み込みマニピュレータ.
 */
Ngl::IInputStream& Ngl::dec( Ngl::IInputStream& stream )
{
	stream.readType( STREAM_READ_TYPE_10 );
	return stream;
}



/**
 * @name hex
 * @brief 16進数読み込みマニピュレータ.
 */
Ngl::IInputStream& Ngl::hex( Ngl::IInputStream& stream )
{
	stream.readType( Ngl::STREAM_READ_TYPE_16 );
	return stream;
}



/*===== EOF ==================================================================*/