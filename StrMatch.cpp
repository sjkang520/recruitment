//字符串匹配，在字符串str1中匹配字符串str2
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//方法一，暴力法
int strmatch(string& str1,string str2)
{
	size_t length1=str1.size();
	size_t length2=str2.size();
	if(length2==0)
		return 0;
	if(length1<length2)
		return -1;
	int res=-1;
	for(int i=0;i<length1&&(length1-i)>=length2;++i)
	{
		int index1=i;
		int index2=0;
		if(str1[i]==str2[index2])
		{
			while(index2<length2&&index1<length1)
			{
				if(str1[index1]!=str2[index2])
					break;
				index1++;
				index2++;
			}
		}
		if(index2==length2)
		{
			res=i;
			break;
		}
	}
	return res;
}
//方法二
int main()
{
	string str1="afdasfsdff";
	string str2="sdf";
	cout<<strmatch(str1,str2)<<endl;
}