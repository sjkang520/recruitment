#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int maximumSwap(int num) {
	string str = to_string(num);
	vector<int> maxNum(str.size(), 0);
	int maxIndex;
	int maxValue = INT_MIN;
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] - '0'>maxValue)
		{
			maxValue = str[i] - '0';
			maxIndex = i;
		}
		maxNum[i] = maxIndex;
	}
	for (int j = 0; j<str.size(); ++j)
	{
		if (str[j]!=str[maxNum[j]]&&maxNum[j] != j)
		{
			char tmp = str[j];
			str[j] = str[maxNum[j]];
			str[maxNum[j]] = tmp;
			break;
		}
	}
	
	return atoi(str.c_str());
}
int main()
{
	int m;
	cin >> m;
	string str1;
	string str2;
	vector<bool> res(m, false);
	for (int i = 0; i < m; i++)
	{
		cin >> str1 >> str2;
		string num1;
		string num2;
		auto pos1 = str1.find(".");
		while (pos1 != str1.npos)
		{
			num1 += str1.substr(0, pos1);
			str1 = str1.substr(pos1 + 1);
			pos1 = str1.find(".");
		}
		num1 += str1;
		auto pos2 = str2.find(".");
		while (pos2 != str2.npos)
		{
			num2 += str2.substr(0, pos2);
			str2 = str2.substr(pos2 + 1);
			pos2 = str2.find(".");
		}
		num2 += str2;
		int index1 = 0;
		int index2 = 0;
		while (index1 < num1.size() && index2 < num2.size())
		{
			if (num2[index2]>num1[index2])
				res[i] = true;
			index1++;
			index2++;
		}
		while (index2 < num2.size())
		{
			if (num2[index2] != '0')
				res[i] = true;
		}
	}
	for (auto it : res)
	{
		if (it == false)
			cout << "false" << endl;
		else
			cout << "true" << endl;
	}
	system("pause");
	
}