#ifndef SINGLETON_H
#define SINGLETON_H
#include <stdio.h>
#include <stdlib.h>
#include <mutex>
//单例基类,注释掉的代码是原本打算利用静态变量自动释放内存，但是这种方法在模板基类里总是没有成功，
//如果不用模板基类的话可以。这点一直搞不明白怎么回事。所以就写了个接口需要主动调用，
//另外这是非线程安全的版本，线程安全加锁就可以了
template <typename T>
class Singleton
{
protected:
	Singleton()
	{
		printf("Singleton\n");
	}
	~Singleton()
	{
		printf("~Singleton\n");
	}
private:
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
/*	class Garbo
	{
	public:
		Garbo()
		{
			printf("Garbo\n");
		}
		~Garbo()
		{
			printf("~garbo\n");
			if(Singleton::m_pInstance)
			{
				delete Singleton::m_pInstance;
				Singleton::m_pInstance=NULL;
			}
		}
	};*/
private:
	static T* m_pInstance;
	std::mutex mutex_;
//	static Garbo m_garbo;
public:
	static T* GetInstance()
	{
		if(m_pInstance==NULL)
		{
			lock_guard<mutex> lock(mutex_);
			{
				if(m_pInstance==NULL)
					m_pInstance=new T();
			}
		}
		return m_pInstance;
	}
	static void destroy()
	{
		if(m_pInstance!=NULL)
			delete m_pInstance;
		m_pInstance=NULL;
	}
};

template <typename T>
T* Singleton<T>::m_pInstance=NULL;
//这里需要在前面加一个关键字typename显示说明它是一个类型，而非成员变量
//template <typename T> 
//typename Singleton<T>::Garbo Singleton<T>::m_garbo;
#endif