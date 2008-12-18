/*******************************************************************************/
/**
 * @file Gauge.h.
 * 
 * @brief �Q�[�W�N���X�w�b�_��`.
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
	 * @brief �R���X�g���N�^.
	 *
	 */
	Gauge(IGameDevice& device, int tex1, int tex2, Vector2 position, Vector2 size, float max, float point);

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^.
	 *
	 */
	~Gauge();

	/*=========================================================================*/
	/**
	 * @brief ����������.
	 * 
	 */
	void Initialize();

	/*=========================================================================*/
	/**
	 * @brief �I������.
	 * 
	 */
	void Terminate();

	/*=========================================================================*/
	/**
	 * @brief �I�����Ă��邩�ǂ���.
	 * 
	 * @return �I���t���O.
	 */
	bool IsTerminated();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̕`�揈��.
	 * 
	 */
	void RenderObject();

	/*=========================================================================*/
	/**
	 * @brief �I�u�W�F�N�g�̍X�V����.
	 * 
	 * @param[in] frameTimer �X�V�^�C�}.
	 */
	void UpdateObject(float frameTimer);

	void SetTexture(int tex1, int tex2 );

	void SetMax(float max);

	void SetPoint(float point);

	void SetPosition(Vector2 position);

	void SetSize(Vector2 size);


	private:
	/** �I���t���O */
	bool m_isTerminated;
	/** �Q�[���f�o�C�X */
	IGameDevice& m_device;

	/** y���W�@*/
	float m_y;
	/** x���W�@*/
	float m_x;
	/** �ő剡�� */
	float m_max;
	/** �Q�[�W�̈ʒu */
	float m_point;
	/** �T�C�Y */
	Vector2 m_size;

	Vector2 m_position;

	int m_texture1;
	int m_texture2;
};

#endif

/*===== EOF ===================================================================*/

