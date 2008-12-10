/*******************************************************************************/
/**
 * @file EntityGroupManager.h.
 * 
 * @brief �ėp�O���[�v�}�l�[�W���N���X��`.
 *
 * @date 2008/08/05.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_ENTITYGROUPMANAGER_H_
#define _NGL_ENTITYGROUPMANAGER_H_

#include	"EntityManager.h"
#include	"PairManagerVisitor.h"
#include	<map>

namespace Ngl{


/**
 * @class EntityGroupManager.
 * @brief �ėp�O���[�v�}�l�[�W���N���X�D
 *
 * @tparam Entity �v�f.
 * @tparam GroupID �O���[�vID.
 * @tparam Manager �Ǘ���.
 * @tparam Map �Ǘ��҂��Ǘ�����A�z�R���e�i.
 */
template<
	class Entity,
	class GroupID	= int,
	class Manager	= EntityManager< Entity >,
	class Map		= std::map<GroupID, Manager*>
>
class EntityGroupManager
{
public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	EntityGroupManager(){}

	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	~EntityGroupManager()
	{
		clear();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief �O���[�v���擾����
	 * 
	 * @param[in] id �Q�Ƃ���O���[�vID.
	 * @return �w��̃O���[�v�}�l�[�W��.
	 */
	Manager& operator[] ( const GroupID& id )
	{
		// �O���[�v�����݂��Ȃ���ΐV�K�ɍ쐬
		if( mGroup[id] == 0 ){
			mGroup[id] = new Manager();
		}
		return *mGroup[id];
	}

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�����J�E���g����
	 * 
	 * @param[in] �Ȃ�.
	 * @return �v�f��.
	 */
	unsigned int count() const
	{
		unsigned int result = 0;
		for( Map::const_iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			result += (*i).second->count();
		}
		return result;
	}

	
	/*=========================================================================*/
	/**
	 * @brief �S�Ă̗v�f���폜
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void clear()
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			delete (*i).second;
		}
		mGroup.clear();
	}

	
	/*=========================================================================*/
	/**
	 * @brief �v�f�̍폜
	 * 
	 * @param[in] evaluator �]����.
	 * @return �Ȃ�.
	 */
	// �v�f�̍폜
	template<class Evaluator>
	void remove( Evaluator& evaluator )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			(*i).second->remove( evaluator );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief �K��҂̎󂯓���
	 * 
	 * @param[in] visitor �K���.
	 * @return �Ȃ�.
	 */
	template<class Visitor>
	void accept( Visitor& visitor )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			(*i).second->accept( visitor );
		}
	}

	
	/*=========================================================================*/
	/**
	 * @brief �y�A�K��҂̎󂯓��� �w��̃}�l�[�W����K��
	 * 
	 * @param[in] first �K�₷��}�l�[�W��.
	 * @param[in] second �K�₷��}�l�[�W��.
	 * @param[in] pair �y�A�K���.
	 * @return �Ȃ�.
	 */
	template <class PairVisitor>
	void acceptPair( Manager& first, Manager& second, PairVisitor& pair )
	{
		PairManagerVisitor< Entity, Manager, PairVisitor > visitor( second, pair );
		first.accept( visitor );
	}

	
	/*=========================================================================*/
	/**
	 * @brief �y�A�K��҂̎󂯓��� �S�Ẵ}�l�[�W����K��
	 * 
	 * @param[in] pair �y�A�K���.
	 * @return �Ȃ�.
	 */
	template< class PairVisitor >
	void acceptPair( PairVisitor& pair )
	{
		for( Map::iterator i( mGroup.begin() ); i != mGroup.end(); ++i ){
			// ����O���[�v���y�A�ŖK��
			(*i).second->acceptPair( pair );
			// ���̃O���[�v���y�A�ŖK��
			Map::iterator j( i );
			for( ++j; j!=mGroup.end(); ++j ){
				acceptPair( *(*i).second, *(*j).second, pair );
			}
		}
	}

private:
	
	
	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^ �R�s�[�֎~
	 * 
	 * @param[in] other �������O���[�v�}�l�[�W��.
	 */
	EntityGroupManager( const EntityGroupManager& other );
	
	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h �R�s�[�֎~
	 * 
	 * @param[in] other �������O���[�v�}�l�[�W��.
	 * @return ������ʂ̃O���[�v�}�l�[�W��.
	 */
	EntityGroupManager& operator = ( const EntityGroupManager& other );

private:

	/** �}�l�[�W���[�O���[�v */
	Map	mGroup;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/