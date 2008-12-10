/*******************************************************************************/
/**
 * @file ObjectManager.h.
 * 
 * @brief �I�u�W�F�N�g�Ǘ��҃N���X�e���v���[�g��`.
 *
 * @date 2008/07/16.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_OBJECTMANAGER_H_
#define _NGL_OBJECTMANAGER_H_

#include	"DefaultDestroy.h"
#include	<map>

namespace Ngl{


/**
 * @class ObjectManager�D
 * @brief �I�u�W�F�N�g�Ǘ��҃N���X�e���v���[�g.
 *
 * @tparam ID �Ǘ��v�fID.
 * @tparam Entity �Ǘ��v�f.
 * @tparam Destroy �폜�|���V�[.
 *
 * �ėp�I�u�W�F�N�g�Ǘ��҃N���X�B<br>
 * EntityManager�Ƌ��ʂ̕��i���g���č쐬����Ă��܂��B<br>
 * ID�ŗv�f���Ǘ��ł���̂��AEntityManager�ƈႤ�Ƃ���B<br>
 */
template
<
	class ID,
	class Entity,
	class Destroy = DefaultDestroy,
	class Map = std::map< ID, Entity >
>
class ObjectManager
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	ObjectManager()
	{}
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~ObjectManager()
	{
		clear();
	}


	/*=========================================================================*/
	/**
	 * @brief �v�f��ǉ�
	 * 
	 * �w��ID�̃R���e�i�ɗv�f���i�[���܂��B
	 * ����ID�̗v�f�����łɑ��݂��Ă��ꍇ�́A�ȑO�̗v�f���폜������A�V�����v�f��ݒ肵�܂��B
	 *
	 * @param[in] id �ǉ�����v�fID.
	 * @param[in] entity �ǉ�����v�f.
	 * @return �Ȃ�.
	 */
	void add( ID id, Entity entity )
	{
		remove( id );

		entityContainer_[ id ] = entity;
	}


	/*=========================================================================*/
	/**
	 * @brief �w���ID�����݂��邩
	 * 
	 * @param[in] id ��������ID.
	 * @retval true ���݂��Ă���.
	 * @retval false ���݂��Ă��Ȃ�.
	 */
	bool isExist( ID id )
	{
		if( entityContainer_.find( id ) != entityContainer_.end() ){
			return true;
		}
		return false;
	}


	/*=========================================================================*/
	/**
	 * @brief �K��҂��󂯓����
	 * 
	 * �ێ����Ă��邷�ׂĂ̗v�f��K�₵�܂��B
	 *
	 * @tparam Visitor �K���.
	 * @param[in] visitor �K��҂̎Q��.
	 * @return �Ȃ�.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( Map::iterator i( entityContainer_.begin() ); i != entityContainer_.end(); ++i ){
			visitor.visit( i->second );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief �y�A�K��҂̎󂯓���
	 * 
	 * �ێ����Ă��邷�ׂĂ̗v�f���Ɨv�f�𑍓���ŖK�₵�܂��B
	 *
	 * @tparam PairVisitor �y�A�K���.
	 * @param[in] pair �y�A�K��҂̎Q��.
	 * @return �Ȃ�.
	 */
	template<class PairVisitor>
	void acceptPair( PairVisitor& pair )
	{
		for( Map::iterator i(  entityContainer_.begin() ); i !=  entityContainer_.end(); ++i ){
			Map::iterator j( i );
			for( ++j; j !=  entityContainer_.end(); ++j ){
				pair.visit( i->second, j->second );
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief �w���ID���폜
	 * 
	 * @param[in] id �폜����ID.
	 * @return �Ȃ�.
	 */
	void remove( ID id )
	{
		Map::iterator itor;
		itor = entityContainer_.find( id );
		if( itor != entityContainer_.end() ){
			Destroy::destroy( itor->second );
			entityContainer_.erase( itor );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief �v�f�̍폜
	 * 
	 * ���ׂĂ̗v�f��]���҂��]�����܂��B<br>
	 * �]�����u�^�v�̏ꍇ�A���̗v�f���폜���܂��B
	 *
	 * @tparam Evaluator �]����.
	 * @param[in] evaluator �]���҂̎Q��.
	 * @return �Ȃ�
	 */
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		Map::iterator i( entityContainer_..begin() );
		while( i != entityContainer_.end() ){
			if( evaluator.evaluate( i->second ) == true ){
				Destroy::destroy( i->second );
				i = mEntityList.erase( i );
			}
			else{
				++i;
			}
		}
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief �Ǘ��v�f�����ׂč폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clear()
	{
		Map::iterator itor = entityContainer_.begin();
		while( itor != entityContainer_.end() ){
			Destroy::destroy( itor->second );
			itor = entityContainer_.erase( itor );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief �v�f�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �v�f��.
	 */
	unsigned int size()
	{
		return (unsigned int)entityContainer_.size();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief �v�f����
	 * 
	 * @param[in] �Ȃ�.
	 * @retval true �v�f�����݂��Ă���.
	 * @retval false �v�f�����݂��Ă��Ȃ�.
	 */
	bool empty()
	{
		return entityContainer_.empty();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 * 
	 * id�Ŏw�肵���v�f���擾����B
	 *
	 * @param[in] id �Q�Ƃ���ID.
	 * @return id�̗v�f.
	 */
	Entity& operator [] ( ID id )
	{
		return entityContainer_[ id ];
	}

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	ObjectManager( const ObjectManager& other );


	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h(�R�s�[�֎~����)
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	ObjectManager& operator = ( const ObjectManager& other );

private:

	/** �v�f�R���e�i */
	Map		entityContainer_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/