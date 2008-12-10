/*******************************************************************************/
/**
 * @file Factory.h.
 * 
 * @brief �H��e���v���[�g�N���X��`.
 *
 * @date 2008/11/02.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_FACTORY_H_
#define _NGL_FACTORY_H_

#include <map>
#include <string>


namespace Ngl{


/**
 * @class Factory.
 * @brief �H��e���v���[�g�N���X.
 *
 * @tparam T ���i.
 * @tparam ID ���i�h�c.
 *
 * @warning ���i�Ƃ��Ēǉ�����N���X�ɂ́A"T* clone( void )"�֐������N���[���@�\���K�v�ł�
 *
 * Ngl::IClonable�N���X���g�p����ƁA�N���[���֐��ɑΉ������֐������������邱�Ƃ��ł��܂��B<br>
 * Ngl/IClonable.h���C���N���[�h���Ă�������<br>
 */
template
<
	class T,
	class ID = std::string
>
class Factory
{

private:

	//���i�R���e�i�N���X
	typedef std::map< ID, T* >	ProductContainer;

public:

	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~Factory()
	{
		// �ێ����Ă��鐻�i��S�č폜
		ProductContainer::iterator itor=productContainer_.begin();
		while( itor != productContainer_.end() ){
			delete itor->second;
			itor = productContainer_.erase( itor );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief ���i�̌��^��ǉ�
	 * 
	 * @param[in] id �ǉ����鐻�i�̂h�c.
	 * @param[in] product �ǉ����鐻�i.
	 * @return �Ȃ�.
	 */
	void add( const ID& id, T* product )
	{
		productContainer_[ id ] = product;
	}

	
	/*=========================================================================*/
	/**
	 * @brief ���i���쐬
	 * 
	 * @param[in] id �쐬���鐻�i�̂h�c.
	 * @return �쐬�������i.
	 */
	T* create( const ID& id )
	{
		//�w�肳�ꂽ���i�̃N���[�����쐬
		return productContainer_[ id ]->clone();
	}

private:

	/** ���i�R���e�i */
	ProductContainer productContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/