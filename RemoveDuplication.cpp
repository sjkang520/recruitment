#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//数组去重
void removeDuplication(vector<int>& arr)
{
	sort(arr.begin(),arr.end());
	int first=0;
	int end=1;
	while(end<arr.size())
	{
		if(arr[first]!=arr[end])
			arr[++first]=arr[end];
		end++;
	}
	arr.erase(arr.begin()+first+1,arr.end());
}
int main()
{
	vector<int> arr{3,3,4,3,3,4,5,34,32,5,34,352,45,345,34,4};
	removeDuplication(arr);
	for(auto it:arr)
		cout<<it<<" ";
	cout<<endl;
}