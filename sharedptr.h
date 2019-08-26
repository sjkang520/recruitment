template<typename T>
class sharedptr
{
private:
	T* ptr_;
	int* counts;
public:
	sharedptr();
	explicit sharedptr(T* ptr);
	explicit sharedptr(const sharedptr& other);
	sharedptr& operator=(const sharedptr& other);
	~sharedptr();
	T* operator->()
	{
		return ptr_;
	}
	T& operator*()
	{
		return *ptr_;
	}
	
};

template <typename T>
sharedptr<T>::sharedptr():ptr_(nullptr),counts(nullptr)
{

}
template <typename T>
sharedptr<T>::sharedptr(T* ptr):ptr_(ptr),counts(new int(1))
{

}
template <typename T>
sharedptr<T>::sharedptr(const sharedptr& other)
{

	*(other.counts)++;
	ptr_=other.ptr_;
	counts=other.counts;
}

template <typename T>
sharedptr& sharedptr<T>::operator=(const sharedptr& other)
{
	if(ptr_==other.ptr_)
		return *this;
	if(ptr_&&--*counts==0)
	{
		delete ptr_;
		delete counts;
		ptr_=nullptr;
		counts=nullptr;
	}
	*(other.counts)++;
	ptr_=other.ptr_;
	counts=other.counts;
	return *this;
}

template <typename T>
sharedptr<T>::~sharedptr()
{
	if(ptr_&&--*counts==0)
	{
		delete ptr_;
		delete counts;
		ptr_=nullptr;
		counts=nullptr;
	}
}