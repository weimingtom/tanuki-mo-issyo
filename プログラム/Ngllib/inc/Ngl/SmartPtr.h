/*******************************************************************************/
/**
 * @file SmartPtr.h.
 * 
 * @brief �X�}�[�g�|�C���^�N���X��`.
 *
 * @date 2008/07/29.
 * 
 * @version 1.00.
 * 
 * @author Kentarou Nishimura.
 */
/******************************************************************************/
#ifndef _NGL_SMARTPTR_H_
#define _NGL_SMARTPTR_H_

#include	<cassert>

namespace Ngl{


/**
 * @class SmartPtr�D
 * @brief �X�}�[�g�|�C���^�N���X.
 * @tparam Ptr �ێ�����^.
 *
 * �Q�ƃJ�E���^�����X�}�[�g�|�C���^�N���X�ł��B<br>
 * �Q�ƃJ�E���^��0�ɂȂ�ƁA�����I�ɕێ����Ă���|�C���^���폜���܂��B<br>
 */
template< typename Ptr >
class SmartPtr
{

public:

	/*=========================================================================*/
	/**
	 * @brief �R���X�g���N�^
	 * 
	 * @param[in] ptr �ێ�����|�C���^.
	 */
	explicit SmartPtr( Ptr* ptr=0 ):
			ptr_( ptr ),
			refCount_( 0 )
	{
		// �Q�ƃJ�E���^�p���쐬
		refCount_ = new unsigned int;
		*refCount_ = 0;

		// �Q�ƃJ�E���^�𑝂₷
		addRef();
	}


	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^
	 * 
	 * @param[in] other �R�s�[����I�u�W�F�N�g.
	 */
	SmartPtr( const SmartPtr< Ptr >& other )
	{
		// �|�C���^�����̂܂܃R�s�[
		ptr_ = other.ptr_;
		refCount_ = other.refCount_;

		// �Q�ƃJ�E���^�𑝂₷
		addRef();
	}


	/*=========================================================================*/
	/**
	 * @brief �R�s�[�R���X�g���N�^
	 *
	 * �ÖٓI�A�b�v�L���X�g�p�R�s�[�R���X�g���N�^.
	 * 
	 * @tparam Ptr2 ����N���X�̕ێ��|�C���^�^.
	 * @param[in] ptr �R�s�[����I�u�W�F�N�g.
	 */
	template < class Ptr2 >
	SmartPtr( SmartPtr< Ptr2 >& ptr )
	{
		refCount_ = ptr.refCount_;
		ptr_ = ptr.ptr_;

		// �������g�̎Q�ƃJ�E���^�𑝂₷
		addRef();
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief �f�X�g���N�^
	 * 
	 * @param[in] �Ȃ�.
	 */
	virtual ~SmartPtr()
	{
		release();
	}


	/*=========================================================================*/
	/**
	 * @brief �|�C���^��ݒ肷��
	 * 
	 * @param[in] ptr �ݒ肷��|�C���^.
	 * @return �Ȃ�.
	 */
	void setPtr( Ptr* ptr=0 )
	{
		// �Q�ƃJ�E���^�����炷( ���łɃ|�C���^�������Ă���ꍇ�̍폜���� )
		release();

		// �ď�����
		refCount_ = new unsigned int;
		*refCount_ = 0;
		ptr_ = ptr;
		addRef();
	}
	

	/*=========================================================================*/
	/**
	 * @brief �ێ����Ă���|�C���^���擾
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ێ����Ă���|�C���^.
	 */
	Ptr* get()
	{
		return ptr_;
	}

	
	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h
	 * 
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	SmartPtr& operator = ( const SmartPtr< Ptr >& other )
	{
		// �������g�ւ̃R�s�[��
		if( ptr_ == other.ptr_ ){
			// ������Ȃ�
			return *this;
		}

		// �����̎Q�ƃJ�E���^�����炷( ���������l�ɂȂ邽�� )
		release();

		// �|�C���^���R�s�[
		ptr_ = other.ptr_;
		refCount_ = other.refCount_;

		// �Q�ƃJ�E���^�𑝂₷
		addRef();

		return *this;
	}


	/*=========================================================================*/
	/**
	 * @brief = ���Z�q�I�[�o�[���[�h
	 * 
	 * �����I�A�b�v�L���X�g�p.
	 *
	 * @tparam Ptr2 ����N���X�̕ێ��|�C���^�^.
	 * @param[in] other �������I�u�W�F�N�g.
	 * @return ������ʂ̃I�u�W�F�N�g.
	 */
	template< class Ptr2 >
	SmartPtr< Ptr >& operator == ( const SmartPtr< Ptr2 >& other )
	{
		// �������g�ւ̃R�s�[��
		if( ptr_ == other.ptr_ ){
			// ������Ȃ�
			return *this;
		}

		// �����̎Q�ƃJ�E���^�����炷( ���������l�ɂȂ邽�� )
		release();

		// �ێ��|�C���^���R�s�[
		ptr_ = other.ptr_;

		// �Q�ƃJ�E���^�𑝂₷
		addRef();

		return *this;
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief == ���Z�q�I�[�o�[���[�h
	 *
	 * �ێ����Ă���|�C���^�ƃ|�C���^������������r����.
	 * 
	 * @param[in] ptr ��r����|�C���^.
	 * @retval true �����|�C���^��ێ�.
	 * @retval false �Ⴄ�|�C���^��ێ�. 
	 */
	bool operator == ( Ptr* ptr )
	{
		if( ptr_ == ptr ){
			return true;
		}
		return false;
	}
	
	
	/*=========================================================================*/
	/**
	 * @brief != ���Z�q�I�[�o�[���[�h
	 *
	 * �ێ����Ă���|�C���^�ƃ|�C���^���������Ȃ�����r����.
	 * 
	 * @param[in] ptr ��r����|�C���^.
	 * @retval true �Ⴄ�|�C���^��ێ�.
	 * @retval false �����|�C���^��ێ�. 
	 */
	bool operator != ( Ptr* ptr )
	{
		return !( *this == ptr );
	}


	/*=========================================================================*/
	/**
	 * @brief -> ���Z�q�I�[�o�[���[�h
	 *
	 * �ێ����Ă���|�C���^�ɃA�N�Z�X����.
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ێ����Ă���|�C���^.
	 */
	Ptr* operator -> ()
	{
		return ptr_;
	}


	/*=========================================================================*/
	/**
	 * @brief * ���Z�q�I�[�o�[���[�h
	 *
	 * �ێ����Ă���|�C���^���ԐڎQ�Ƃ���.
	 * 
	 * @param[in] �Ȃ�.
	 * @return �ێ����Ă���|�C���^.
	 */
	Ptr& operator * ()
	{
		return *ptr_;
	}


	/*=========================================================================*/
	/**
	 * @brief [] ���Z�q�I�[�o�[���[�h
	 *
	 * �ێ����Ă���|�C���^�z��̗v�f��Ԃ�
	 * ( �|�C���^�z���ێ����Ă���ꍇ�̂ݗL�� ).
	 * 
	 * @param[in] index �擾����v�f�ԍ�.
	 * @return �ێ����Ă���|�C���^.
	 */
	Ptr& operator [] ( int index )
	{
		return ptr_[ index ];
	}

private:

	/*=========================================================================*/
	/**
	 * @brief �Q�ƃJ�E���^�𑝂₷
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void addRef()
	{
		(*refCount_)++;
	}


	/*=========================================================================*/
	/**
	 * @brief �������
	 * 
	 * @param[in] �Ȃ�.
	 * @return �Ȃ�.
	 */
	void release()
	{
		--(*refCount_);

		// �Q�ƃJ�E���^��0��
		if( *refCount_ <= 0 ){
			// �|�C���^�ƎQ�ƃJ�E���^���폜
			delete[] ptr_;
			delete refCount_;
			refCount_ = 0;
		}
	}

private:

	/** �ێ����Ă���|�C���^ */
	Ptr*			ptr_;

	/** �Q�ƃJ�E���^ */
	unsigned int*	refCount_;

};

} // namespace Ngl

#endif

/*===== EOF ==================================================================*/