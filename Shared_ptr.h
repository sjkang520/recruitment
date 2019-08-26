#ifndef SHARED_PTR_H
#define SHARED_PTR_H
//智能指针
template <typename T> 
class SharedPtr
{
public:
	SharedPtr();
	explicit SharedPtr(T* ptr);
	explicit SharedPtr(const SharedPtr& other);
	~SharedPtr();
	SharedPtr& operator=(const SharedPtr& other);
	T* operator->()
	{
		return ptr_;
	}
	T& operator*()
	{
		return *ptr_;
	}
private:
	T* ptr_;
	int* refCount_;
};

template <typename T>
SharedPtr<T>::SharedPtr():ptr_(nullptr),refCount_(nullptr)
{

}
template <typename T>
SharedPtr<T>::SharedPtr(T* ptr):ptr_(ptr),refCount_(new int(1))
{

}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
{
	*(other.refCount_)++;
	ptr_=other.ptr_;
	refCount_=other.refCount;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
	if(ptr_&&--*refCount_==0)
	{
		delete ptr_;
		delete refCount_;
		ptr_=nullptr;
		refCount_=nullptr;
	}
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
{
	if(ptr_==other.ptr_)
		return *this;
	if(ptr_&&--*refCount_==0)
	{
		delete ptr_;
		delete refCount_;
		ptr_=nullptr;
		refCount_=nullptr;
	}
	++*(other.refCount_);
	ptr_=other.ptr_;
	refCount_=other.refCount_;
	return *this;
}
#endif