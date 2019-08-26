//两个线程，两个数组，线程各自编写，交叉输出
//有缺陷，只能打印连个数组元素个数相同的
//而且有点疑问，为什么信号不会丢失
#include <vector>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <unistd.h>
using namespace std;
condition_variable cond;
mutex mute;
bool falg=true;


void print1(vector<int>& a)
{
	int n=0;
	while(n<a.size())
	{
		unique_lock<mutex> lock(mute);
		cond.wait(lock,[]{return falg;});
		cout<<a[n++]<<" ";
		falg=false;
		cond.notify_one();
	}
}
void print2(vector<int>& b)
{
	int m=0;
	while(m<b.size())
	{
		sleep(2);
		unique_lock<mutex> lock(mute);
		cond.wait(lock,[]{return !falg;});
		cout<<b[m++]<<" ";
		falg=true;
		cond.notify_one();
	}
}
int main()
{
	vector<int> a{1,3,4,5};
	vector<int> b{6,8,9,0};
	thread t1(std::bind(print1,a));
	thread t2(std::bind(print2,b));
	//thread t1(print1,a);
	//thread t2(print2,b);
	t1.join();
	t2.join();
	
}