//找出数组中出现次数超过一半的数字
//
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

bool CheckMoreThanHalf(vector<int>& v,int res)
{
	int times=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==res)
			times++;
	}
	if(2*times<=v.size())
		return false;
	return true;
}

int moreThanHalfOfNum(vector<int>& v)
{
	int length=v.size();
	if(length==0)
		return 0;
	int mid=length>>1;
	int start=0;
	int end=length-1;
	int index=partition(v,0,length-1);
	while(index!=mid)
	{
		if(index>mid)
		{
			end=index-1;
			index=partition(v,start,end);
		}
		else
		{
			start=index+1;
			index=partition(v,start,end);
		}
	}
	int result=v[index];
	if(!CheckMoreThanHalf(v,result))
		return 0;
	return result;
}


int main()
{
	vector<int> v{1,4,3,4,4,4,5,4,2};
	int result=moreThanHalfOfNum(v);
	cout<<result<<endl;
}