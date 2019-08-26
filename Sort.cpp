#include <vector>
#include <iostream>
using namespace std;
bool lessd(int a,int b)
{
	return a<b;
}
void exch(vector<int>& v,int i,int j)
{
	int tmp=v[i];
	v[i]=v[j];
	v[j]=tmp;
}
//冒泡排序
//时间复杂度O(N^2),稳定排序算法,空间复杂度O(1)
void sort(vector<int>& v)
{
	for(int i=0;i<v.size();i++)
	{
		bool flag=false;
		for(int j=1;j<v.size()-i;j++)
		{
			if(lessd(v[j],v[j-1]))
			{
				exch(v,j,j-1);
				flag=true;
			}
		}
		if(!flag)
			break;
	}
}

//选择排序
//时间复杂度O(N^2),不稳定,空间复杂度O(1)
void sort1(vector<int>& v)
{
	for(int i=0;i<v.size();++i)
	{
		int min=i;
		for(int j=i+1;j<v.size();++j)
		{
			if(lessd(v[j],v[min]))
				min=j;
		}
		exch(v,min,i);
	}
}

//插入排序
//时间复杂度O(N^2) ，稳定,空间复杂度O(1)
void sort2(vector<int>& v)
{
	for(int i=1;i<v.size();++i)
	{
		for(int j=i;j>0&&lessd(v[j],v[j-1]);--j)
			exch(v,j,j-1);
	}
}

int main()
{
	vector<int> v{2,3,9,2,34,49,12,34,4,53,230,5,430,436,5,7};
	sort(v);
	for(auto &it : v)
		cout<<it<<" ";
	cout<<endl;
}