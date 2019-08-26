#include "Singleton.h"
#include <stdlib.h>
#include <stdio.h>
//这里注释的就是利用静态变量自动释放内存，但是这种方法在模板基类里行不通，我不知道为什么
/*
class Singleton
{
private:
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

	class Garbo
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
	};
private:
	static Singleton* m_pInstance;
	static Garbo m_garbo;
public:
	static Singleton* GetInstance()
	{
		if(m_pInstance==NULL)
			m_pInstance=new Singleton();
		return m_pInstance;
	}
};
Singleton* Singleton::m_pInstance=NULL;
Singleton::Garbo Singleton::m_garbo;*/
class test:public Singleton<test>
{
	friend class Singleton<test>;
	public:
		void function()
		{
			printf("hello\n");
		}
		
	private:
		
		test()
		{
			printf("test\n");
		}
		~test()
		{
			printf("~test\n");
		}
		test(const test&);
		test& operator=(const test&);
};
int main()
{
	test* t=test::GetInstance();
	t->function();
	t->destroy();
	//delete t;
}