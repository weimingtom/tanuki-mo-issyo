/*******************************************************************************/
/*
 * @file Option.cpp.
 * 
 * @brief �Q�[���I�v�V�����N���X�̒�`.
 *
 * @date 2008/11/25.
 *
 * @version 1.00.
 *
 * @author Kenji Iwata.
 */
/*******************************************************************************/

/*===== �C���N���[�h ==========================================================*/
#include	"Manager/Scene/Option/Option.h"
#include	"Manager/Scene/Option/XMLLoader.h"


/*=============================================================================*/
/**
 * @brief �R���X�g���N�^.
 * 
 */
Option::Option()
{

}

/*=============================================================================*/
/**
 * @brief �f�X�g���N�^.
 */
Option::~Option()
{

}

/*=============================================================================*/
/**
 * @brief SE�{�����[���̐ݒ�.
 * 
 * @param[in] value ����.
 */
void Option::SetSEVolume(unsigned int value)
{
	m_seVolume = value;
}

/*=============================================================================*/
/**
 * @brief ���݂�SE�{�����[�����擾.
 * 
 * @return ����.
 */
unsigned int Option::GetSEVolume()
{
	return m_seVolume;
}

/*=============================================================================*/
/**
 * @brief BGM�{�����[���̐ݒ�.
 * 
 * @param[in] value ����.
 */
void Option::SetBGMVolume(unsigned int value)
{
	m_bgmVolume = value;
}

/*=============================================================================*/
/**
 * @brief ���݂�BGM�{�����[���̎擾.
 * 
 * @return ����.
 */
unsigned int Option::GetBGMVolume()
{
	return m_bgmVolume;
}

void Option::LoadSpriteInfo()
{
	XMLLoader loader;

	m_attackSpriteInfo			= loader.LoadSpriteInfo("attack");
	m_defenceSpriteInfo			= loader.LoadSpriteInfo("defence");
	m_fieldSpriteInfo			= loader.LoadSpriteInfo("field");
	m_avaterSpriteInfo			= loader.LoadSpriteInfo("avater");
	m_hitPointSpriteInfo		= loader.LoadSpriteInfo("hitpoint");
	m_nextBlockSpriteInfo		= loader.LoadSpriteInfo("nextblock");
	m_playerTimeSpriteInfo		= loader.LoadSpriteInfo("playertime");
	m_skillPoint1SpriteInfo		= loader.LoadSpriteInfo("skillpoint1");
	m_skillPoint2SpriteInfo		= loader.LoadSpriteInfo("skillpoint2");
	m_skillPoint3SpriteInfo		= loader.LoadSpriteInfo("skillpoint3");
	m_skillPoint4SpriteInfo		= loader.LoadSpriteInfo("skillpoint4");
	m_scoreSpriteInfo			= loader.LoadSpriteInfo("score");

}

/*===== EOF ===================================================================*/