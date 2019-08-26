#include <stdlib.h>
#include <stdio.h>
class Singleleton
{
private:
	Singleleton()
	{
		printf("Singleleton\n");
	}
	~Singleleton()
	{
		printf("~Singleleton\n");
	}
	Singleleton(const Singleleton&);
	Singleleton& operator=(const Singleleton&);
private:
	static Singleleton* m_instance;
public:
	static Singleleton* GetInstance()
	{
		return m_instance;
	}
	static void destroy()
	{
		delete m_instance;
		m_instance=NULL;
	}
};
Singleleton* Singleleton::m_instance=new Singleleton();
int main()
{
	Singleleton* s=Singleleton::GetInstance();
	s->destroy();
}