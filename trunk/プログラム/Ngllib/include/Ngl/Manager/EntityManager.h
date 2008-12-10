/*******************************************************************************/
/**
 * @file EntityManager.h.
 * 
 * @brief �ėp�}�l�[�W���[�N���X��`.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYMANAGER_H_
#define _NGL_ENTITYMANAGER_H_

#include	"DefaultDestroy.h"
#include	<list>
#include	<algorithm>

namespace Ngl{


/**
 * @class EntityManager.
 * @brief �ėp�}�l�[�W���[�N���X.
 *
 * @tparam Entity �v�f
 * @tparam Destroy �폜���@�������|���V�[�N���X.
 * @tparam List �R���e�i�̎�ނ�����킷�|���V�[�N���X.
 */
template
<
	class Entity,						
	class Destroy	= DefaultDestroy,	
	class List		= std::list<Entity>	
>
class EntityManager
{
public:
	
	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	EntityManager(){}

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] ������ ��������.
	 */
	~EntityManager()
	{
		clear();
	}

	
	/*=========================================================================*/
	/**
	 * @brief �v�f��ǉ�����
	 * 
	 * @param[in] entity �ǉ�����v�f.
	 * @return �Ȃ�.
	 */
	void add( Entity entity )
	{
		mEntityList.push_back( entity );
	}


	/*=========================================================================*/
	/**
	 * @brief �v�f�����擾����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �v�f��.
	 */
	unsigned int count() const
	{
		return static_cast< unsigned int >( mEntityList.size() );
	}


	/*=========================================================================*/
	/**
	 * @brief �K��҂��󂯓����
	 * 
	 * @tparam Visitor �K���.
	 * @param[in] visitor �K���.
	 * @return �Ȃ�.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			visitor.visit( *i );
		}
	}


	/*=========================================================================*/
	/**
	 * @brief �y�A�K��҂̎󂯓���
	 * 
	 * @tparam PairVisitor �y�A�K���.
	 * @param[in] pair �y�A�K���.
	 * @return �Ȃ�.
	 */
	template<class PairVisitor>
	void acceptPair( PairVisitor& pair )
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			List::iterator j( i );
			for( ++j; j != mEntityList.end(); ++j ){
				pair.visit( *i, *j );
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�̍폜
	 * 
	 * @tparam Evaluator �]����.
	 * @param[in] evaluator �]����.
	 * @return �Ȃ�
	 */
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		List::iterator i( mEntityList.begin() );
		while( i != mEntityList.end() ){
			if( evaluator.evaluate( *i ) == true ){
				Destroy::destroy( *i );
				i = mEntityList.erase( i );
			}
			else{
				++i;
			}
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�̕��ёւ�
	 * 
	 * @param[in] sorter ������.
	 * @return �Ȃ�
	 */
	template<class Sorter>
	void sort( Sorter& sorter )
	{
		sorter.sort(
			mEntityList.begin(),
			mEntityList.end()
			);
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief �v�f�̑S�폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clear()
	{
		for( List::iterator i( mEntityList.begin() ); i != mEntityList.end(); ++i ){
			Destroy::destroy( *i );
		}
		mEntityList.clear();
	}

private:

	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^(�R�s�[�֎~����)
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	EntityManager( const EntityManager& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief =���Z�q�I�[�o�[���[�h(�R�s�[�֎~����)
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	EntityManager& operator = ( const EntityManager& other );

private:

	/** �v�f���X�g */
	List		mEntityList;
};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/