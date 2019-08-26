#include <vector>
#include <iostream>
using namespace std;
//快速排序的切分
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
int partition(vector<int>& v,int left,int right)
{
	int i=left;
	int j=right+1;
	int item=v[left];
	while(i<=j)
	{
		while(lessd(v[++i],item))
			if(i==right)
				break;
		while(lessd(item,v[--j]))
			if(j==left)
				break;
		if(j<=i)
			break;
		exch(v,i,j);
	}
	exch(v,j,left);
	return j;
}
//快速排序
//时间复杂度O(N*LogN),不稳定,空间复杂度O(logN),空间的消耗主要在递归上,每递归一次就要保持一些数据
void sort(vector<int>& v,int left,int right)
{
	if(right<=left)
		return;
	int mid=partition(v,left,right);
	sort(v,left,mid-1);
	sort(v,mid+1,right);
}
void sort(vector<int>& v)
{
	sort(v,0,v.size()-1);
}
int main()
{
	vector<int> v{1,4,2,4,30,2,34,34,5,3,3,5,6};
	sort(v);
	for(auto &it :v)
		cout<<it<<" ";
	cout<<endl;
}