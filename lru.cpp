//LRU的实现
#include <unordered_map>
using namespace std;
class Node
{
public:
	int m_key;
	int m_value;
	Node* pre;
	Node* next;
	Node(int key,int value):m_key(key),m_value(value)
	{
		pre=nullptr;
		next=nullptr;
	}
};

class LRUCache
{
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void set(int key,int value);
	void moveTolast(Node* node);
private:
	int capacity_;
	Node* first;//最少使用的item
	Node* last;
	unordered_map<int,Node*> CacheMap_;
};

LRUCache::LRUCache(int capacity):capacity_(capacity)
{
	first=new Node(-1,-1);
	last=new Node(-1,-1);
	first->next=last;
	last->pre=first;
}


LRUCache::~LRUCache()
{
	
}


int LRUCache::get(int key)
{
	if(CacheMap_.find(key)==CacheMap_.end())
		return -1;
	Node* cur=CacheMap_[key];
	cur->pre->next=cur->next;
	cur->next->pre=cur->pre;;
	moveTolast(cur);
	return cur->m_value;
}


void LRUCache::set(int key,int value)
{
	if(get(key)!=-1)
	{
		CacheMap_[key]->m_value=value;
		return;
	}
	if(CacheMap_.size()==capacity_)
	{
		Node* tmp=first->next;
		CacheMap_.erase(tmp->m_key);
		first->next=tmp->next;
		tmp->next->pre=first;
		delete tmp;
	}
	Node* newNode=new Node(key,value);
	CacheMap_[key]=newNode;
	moveTolast(newNode);
}


void LRUCache::moveTolast(Node* node)
{
	last->pre->next=node;
	node->pre=last->pre;
	node->next=last;
	last->pre=node;
}

int main()
{
	LRUCache lru(10);
}
