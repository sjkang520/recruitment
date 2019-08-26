#include <vector>
#include <iostream>
using namespace std;
//堆排序，最大堆
//时间复杂度O(N*LogN),空间复杂度O(1)
class heapSort
{
public:
	heapSort()
	{}
	~heapSort()
	{}
	void sort(vector<int>& v)
	{
		//建堆
		int N=v.size();
		for(int i=N/2;i>=1;i--)
			sink(i,N,v);
	    //排序
		while(N>1)
		{
			exch(v,1,N--);
			sink(1,N,v);
		}
	}
	//堆下沉
	void sink(int k,int N,vector<int>& v)
	{
		while(2*k<=N)
		{
			int j=2*k;
			if(j<N&&less(v,j,j+1))
				j++;
			if(!less(v,k,j))
				break;
			exch(v,k,j);
			k=j;
		}
	}
	//堆上浮
	void swim(int k,int N,vector<int>& v)
	{
		while(k>1&&less(v,k/2,k))
		{
			exch(v,k/2,k);
			k=k/2;
		}
	}
	bool less(vector<int>& v,int i,int j)
	{
		return v[i-1]<v[j-1];
	}
	void exch(vector<int>& v,int i,int j)
	{
		int tmp=v[i-1];
		v[i-1]=v[j-1];
		v[j-1]=tmp;
	}
};

int main()
{
	vector<int> v{5,6,2,5,6,9};
	heapSort heapsort;
	heapsort.sort(v);
	for(auto &it : v)
		cout<<it<<" ";
	cout<<endl;
}