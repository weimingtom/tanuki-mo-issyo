/*******************************************************************************/
/**
 * @file DirectInput.h.
 * 
 * @brief DirectInput DirectInput�֌W�f�[�^��`�t�@�C��.
 *
 * @date 2008/07/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_DIRECTINPUT_H_
#define _NGL_DIRECTINPUT_H_

/** DirectInput�̃o�[�W������` */
#ifndef		DIRECTINPUT_VERSION
#define		DIRECTINPUT_VERSION 0x0800
#endif

#include	"KeyboardKeyDI8.h"
#include	"MouseKeyDI8.h"
#include	"JoystickKeyDI8.h"
#include	<d3dx9.h>
#include	<dinput.h>
#include	<windows.h>

// �K�v�ȃ��C�u�����t�@�C���̃��[�h
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")

#endif

/*===== EOF ==================================================================*/