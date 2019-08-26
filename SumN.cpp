#include <vector>
#include <iostream>
//在数组中 找出和为给定值的组合数
using namespace std;
void SumN(vector<int>& nums,int start,int end,int sum,vector<vector<int> >& res,vector<int>& tmp)
{
	if(start==end&&sum==0)
	{
		res.push_back(tmp);
		return;
	}
	else if(start==end)
	{
		return;
	}
	else
	{
		if(nums[start]<=sum)
		{
			tmp.push_back(nums[start]);
			SumN(nums,start+1,end,sum-nums[start],res,tmp);
			tmp.pop_back();
		}
		SumN(nums,start+1,end,sum,res,tmp);
	}
}

int main()
{
	vector<int> nums{1,2,3,4,5,6,9,11,12};
	vector<vector<int>> res;
	vector<int> tmp;
	SumN(nums,0,nums.size()-1,6,res,tmp);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}