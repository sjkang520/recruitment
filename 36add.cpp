#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
string table = "0123456789abcdefghijklmnopqrstuvwxyz";
int getInt(char c)
{
	int res;
	if (c >= '0'&&c <= '9')
		res = c - '0';
	else
		res = c - 'a' + 10;
	return res;
}
//我的版本
string add(string& s1, string& s2)
{
	vector<int> res;
	string result;
	int carry = 0;
	int index1 = s1.size()-1;
	int index2 = s2.size()-1;
	while (index1 >= 0 || index2 >= 0)
	{
		if (index1 >= 0 && index2 >= 0)
		{
			int tmp = getInt(s1[index1]) + getInt(s2[index2]) + carry;
			carry = tmp / 36;
			res.push_back(tmp % 36);
			--index1;
			--index2;
		}
		else if (index1 >= 0)
		{
			int tmp = getInt(s1[index1])+carry;
			carry = tmp / 36;
			res.push_back(tmp % 36);
			--index1;
		}
		else
		{
			int tmp = getInt(s2[index2]) + carry;
			carry = tmp / 36;
			res.push_back(tmp % 36);
			--index2;
		}
	}
	if (carry)
		res.push_back(carry);
	for (int n = res.size() - 1; n >= 0; --n)
	{
		result += table[res[n]];
	}
	return result;
}
//徐鹏程版本
string add2(string str1, string str2)
{
	map<char, int> nums;
	for (int i = 0; i < 36; ++i)
	{
		if (i < 10) nums['0' + i] = i;
		else nums['a' + i - 10] = i;
	}
	vector<char> renums = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
		'w', 'x', 'y', 'z' };

	int len1 = str1.size() - 1;
	int len2 = str2.size() - 1;
	string res;
	int carrier = 0;
	int temp = 0;
	while (len1 >= 0 && len2 >= 0)
	{
		temp = nums[str1[len1]] + nums[str2[len2]] + carrier;
		carrier = 0;
		if (temp > 35) { temp -= 36; carrier = 1; }
		res = renums[temp] + res;
		--len1;
		--len2;
	}
	while (len1 >= 0)
	{
		temp = nums[str1[len1]] + carrier;
		carrier = 0;
		if (temp > 35) { temp -= 36; carrier = 1; }
		res = renums[temp] + res;
		--len1;
	}
	while (len2 >= 0)
	{
		temp = nums[str2[len2]] + carrier;
		carrier = 0;
		if (temp > 35) { temp -= 36; carrier = 1; }
		res = renums[temp] + res;
		--len2;
	}
	if (carrier == 1) res = '1' + res;
	return res;
}

int _36toTen(string& s)
{
	int res=0;
	int length = s.size();
	for (int i = 0; i < s.size(); ++i)
	{
		res += getInt(s[i])*pow(36, length-1-i);
	}
	return res;
}
string Tento36(int n)
{
	string res;
	if (n == 0)
		return "0";
	while (n > 0)
	{
		res += table[n % 36];
		n /= 36;
	}
	reverse(res.begin(), res.end());
	return res;
}
string add3(string& s1, string s2)
{
	int n1 = _36toTen(s1);
	int n2 = _36toTen(s2);
	int res = n1 + n2;
	return Tento36(res);
}
int main()
{
	string s1 = "uv";
	string s2 = "xyz";
	cout << add(s1,s2) << endl;
	cout << add2(s1, s2) << endl;
	cout << add3(s1, s2) << endl;
	system("pause");
}