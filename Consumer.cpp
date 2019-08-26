//生产者消费者模型
#include <functional>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
#include <memory>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
class Consumer
{
public:
	typedef function<void()> functor;
	Consumer():running_(false)
	{

	}
	~Consumer()
	{
		if(running_)
			stop();
	}
	void start(int workThread)
	{
		running_=true;
		threads_.resize(workThread);
		for(int n=0;n<workThread;++n)
			threads_[n].reset(new std::thread(bind(&Consumer::threadFun,this)));
	}
	void stop()
	{
		running_=false;
		
		cond_.notify_all();
		for(int n=0;n<threads_.size();++n)
			threads_[n]->join();
	}
	void addTask(const functor& cb)
	{
		unique_lock<mutex> lock(mutex_);
		task_.push(move(cb));
		cond_.notify_one();
	}
	functor takeTask()
	{

	}
	void threadFun()
	{
		while(true)
		{
			{
				functor task;
				{
					unique_lock<mutex> lock(mutex_);
					while(task_.empty()&&running_)
						cond_.wait(lock);
					if(!running_)
						break;
					task=task_.front();
					task_.pop();
				}
				if(task)
					task();
			}
			
		}
	}
private:
	queue<functor> task_;
	mutex mutex_;
	condition_variable cond_;
	vector<shared_ptr<std::thread>> threads_;
	bool running_;
};

void print(int a)
{
	printf("hello word %d\n",a);
}
void func(const string& str)
{
	printf("%s\n",str.c_str());
}
void print2()
{
	printf("hello world 2\n");
}
int main()
{
	Consumer consumer;
	consumer.start(4);
	consumer.addTask(bind(print,1));	
	consumer.addTask(bind(func,"fangjiale"));
//	sleep(2);
	consumer.stop();
//	
//	
//	consumer.addTask(print2);
//	consumer.stop();
}