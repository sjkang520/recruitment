#ifndef __SORT_H__
#define __SORT_H__
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
template <class Type>
class sort
{
private:
	vector<Type> aux;
public:
	sort()=default;
	sort(vector<Type> &v);
	~sort();
	void Sort0(vector<Type> &v);//冒泡排序
	void Sort1(vector<Type> &v);//选择排序
	void Sort2(vector<Type> &v);//插入排序
	void Sort3(vector<Type> &v);//希尔排序
	void Sort4(vector<Type> &v,int lo,int hi);//自顶向下归并排序
	void Sort5(vector<Type> &v);//自底向上归并排序
	void Sort6(vector<Type> &v);//堆排序(数组v[1]到v[N]位置的元素排序)
	void Sort7(vector<Type> &v,int left,int right);//快速排序递归
	void Sort7(vector<Type> &v);//快速排序
	void sink(vector<Type> &v,int i,int N);
	bool less(Type a,Type b) const;
	bool less(vector<Type> &v,int i,int j);//堆排序用
	void exch(vector<Type> &v,int i,int j);//交换i和j位置的元素
	void exch2(vector<Type> &v,int i,int j);//对排序
	void show(vector<Type> &v) const;
	void merge(vector<Type> &v,int lo,int mid,int hi);//将两个有序数组v[lo..mid]和v[mid+1..hi]归并成一个有序数组
	int partition(vector<Type>& v,int left,int right);//快速排序的切分
	int min(int a,int b);
};

template <class Type>
sort<Type>::sort(vector<Type> &v)
{
	for(int i=0;i<v.size();i++)
		aux.push_back(v[i]);
}

template <class Type>
sort<Type>::~sort()
{
}

template <class Type>
void sort<Type>::Sort0(vector<Type> &v)
{
	int N=v.size();
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<N-i;j++)
			if(less(v[j],v[j-1]))
				exch(v,j,j-1);
	}
}

template <class Type>
void sort<Type>::Sort1(vector<Type> &v)
{
	int min;
	for(int i=0;i<v.size();i++)
	{
		min=i;
		for(int j=i+1;j<v.size();j++)
		{
			if(less(v[j],v[min]))
				min=j;
		}
		exch(v,i,min);
	}
}

template <class Type>
void sort<Type>::Sort2(vector<Type> &v)
{
	for(int i=1;i<v.size();i++)
	{
		for(int j=i;j>0&&less(v[j],v[j-1]);j--)
			exch(v,j,j-1);
	}
}

template <class Type>
void sort<Type>::Sort3(vector<Type> &v)
{
	int N=v.size();
	int h=1;
	while(h<N/3)
		h=3*h+1;
	while(h>=1)
	{
		for(int i=h;i<N;i++)
		{
			for(int j=i;j>=h&&less(v[j],v[j-h]);j-=h)
				exch(v,j,j-h);
		}
	h/=3;
	}
}

template <class Type>
void sort<Type>::Sort4(vector<Type> &v,int lo,int hi)
{
	if(hi<=lo) return;
	int mid=lo+(hi-lo)/2;
	Sort4(v,lo,mid);
	Sort4(v,mid+1,hi);
	merge(v,lo,mid,hi);
}

template <class Type>
void sort<Type>::Sort5(vector<Type> &v)
{
	int N=v.size();
	for(int sz=1;sz<N;sz+=sz)
	{
		for(int lo=0;lo<N-sz;lo+=sz+sz)
		{
			merge(v,lo,lo+sz-1,min(lo+sz+sz-1,N-1));
		}
	}
}

template <class Type>
void sort<Type>::Sort6(vector<Type> &v)
{
	int N=v.size();
	for(int k=N/2;k>=1;k--)
		sink(v,k,N);
	while(N>1)
	{
		exch(v,1,N--);
		sink(v,1,N);
	}
}
template <class Type>
void sort<Type>::Sort7(vector<Type>& v,int left,int right)
{
	if(right<=left)
		return;
	int mid=partition(v,left,right);
	Sort7(v,left,mid-1);
	Sort7(v,mid+1,right);
}

template <class Type>
void sort<Type>::Sort7(vector<Type>& v)
{
	Sort7(v,0,v.size()-1);
}

template <class Type>
void sort<Type>::sink(vector<Type> &v,int i,int N)
{
	while(2*i<=N)
	{
		int j=2*i;
		if(j<N&&less(v,j,j+1))
			j++;
		if(!less(v,i,j))
			break;
		exch2(v,i,j);
		i=j;
	}
}

template <class Type>
bool sort<Type>::less(Type a,Type b) const
{
	return a<b;
}

template <class Type>
bool sort<Type>::less(vector<Type> &v,int i,int j)
{
	return v[i-1]<v[j-1];
}

template <class Type>
void sort<Type>::exch(vector<Type> &v,int i,int j)
{
	Type temp;
	temp=v[j];
	v[j]=v[i];
	v[i]=temp;
}

template <class Type>
void sort<Type>::exch2(vector<Type> &v,int i,int j)
{
	Type temp;
	temp=v[j-1];
	v[j-1]=v[i-1];
	v[i-1]=temp;
}

template <class Type>
void sort<Type>::show(vector<Type> &v) const
{
	for(auto it : v)
		cout<<it<<" ";
	cout<<endl;
}

template <class Type>
void sort<Type>::merge(vector<Type> &v,int lo,int mid,int hi)
{
	//先将所有的元素复制到aux中，再归并到v中
	int i=lo;
	int j=mid+1;
	for(int k=lo;k<=hi;k++)
		aux[k]=v[k];
	for(int k=lo;k<=hi;k++)
	{
		if(i>mid) v[k]=aux[j++];
		else if(j>hi) v[k]=aux[i++];
		else if(less(aux[j],aux[i])) v[k]=aux[j++];
		else v[k]=aux[i++];
	}
}
template <class Type>
int sort<Type>::partition(vector<Type>& v,int left,int right)
{
	int i=left;
	int j=right+1;
	Type item=v[i];
	while(i<=j)
	{
		while(less(v[++i],item))
			if(i==right)
				break;
		while(less(item,v[--j]))
			if(j==left)
				break;
		if(i>=j)
			break;
		exch(v,i,j);
	}
	exch(v,j,left);
	return j;
}
template <class Type>
int sort<Type>::min(int a,int b)
{
	return a<b?a:b;
}
#endif