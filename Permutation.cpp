//输入一个字符串，按字典序打印出该字符串的所有排列,剑指offer
//
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;
//方法1 递归算法，采用set去重
void PermutationCore(set<string>& res,string str,int start)
{
	if(start==str.size()-1)
	{
		res.insert(str);
		return;
	}
	for(int n=start;n<str.size();++n)
	{
		swap(str[start],str[n]);
		PermutationCore(res,str,start+1);
	}
}
//方法二，递归算法
//去重方法,当交换n位置的元素和后面位置元素时，判断后面的元素是否被交换过，若没有，则交换，若交换过则不用交换
void PermutationCore2(vector<string>& res,string str,int start)
{
    if(start==str.size()-1)
    {
        res.push_back(str);
        return;
    }
    unordered_set<char> swaped;
    for(int n=start;n<str.size();++n)
    {
        if(n==start||swaped.find(str[n])==swaped.end())
        {
            swaped.insert(str[n]);
            swap(str[start],str[n]);
            PermutationCore2(res,str,start+1);
        }
    }
}
//方法三，字典序列排序算法
//先对初始字符串str排序
//然后执行以下过程
/*
 如何得到346987521的下一个
     *1，从尾部往前找第一个P(i-1) < P(i)的位置
     * 3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1
     * 最终找到6是第一个变小的数字，记录下6的位置i-1
     *
     * 2，从i位置往后找到最后一个大于6的数
     * 3 4 6 -> 9 -> 8 -> 7 5 2 1
     * 最终找到7的位置，记录位置为m
     *
     * 3，交换位置i-1和m的值
     * 3 4 7 9 8 6 5 2 1
     * 4，倒序i位置后的所有数据
     * 3 4 7 1 2 5 6 8 9
     * 则347125689为346987521的下一个排列
  */
 //方法三代码暂时略
 
 //扩展，若不是求字符串所有排列，而是求字符串所有组合（ab和ba属于同一个组合）
 //对于长度为n的字符串，组合长度有1 2 3...m(1=<m<=n)
 //思想，对于n个字符串分成两部分，第一个字符串和后面的字符串，若组合里包含第一个字符串，那么从后面
 //n-1个字符里选出m-1个字符，如果组合里不包含第一个字符串，那么从后面n-1个字符中选出m个字符串
 void combination(string& str,int start,int n,int m,vector<string>& res,string com)
 {
 	if(m==0||m>n)
 	{
 		if(m==0)
 			res.push_back(com);
 		return;
 	}
 	com+=str[start];
 	combination(str,start+1,n-1,m-1,res,com);
 	com.pop_back();
 	combination(str,start+1,n-1,m,res,com);
 }
 
vector<string> Permutation(string str)
{
	set<string> res;//用set是为了去重
	PermutationCore(res,str,0);
	vector<string> result(res.begin(),res.end());
	sort(result.begin(),result.end());//按照字典序排序
	return result;
}

int main()
{
	string str="adf";
	vector<string> result;
	vector<string> res=Permutation(str);
	for(int i=1;i<=str.size();i++)
		combination(str,0,str.size(),i,result,"");
	for(auto it:res)
		cout<<it<<" ";
	cout<<endl;
	for(auto it:result)
		cout<<it<<" ";
	cout<<endl;
}