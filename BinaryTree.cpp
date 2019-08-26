// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

//Definition for binary tree
#include <cstdio>
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int length = pre.size();
		if (length == 0)
			return nullptr;
		return ConstructCore(pre, vin, 0, length - 1, 0, length - 1);
	}
	TreeNode* ConstructCore(vector<int> &pre, vector<int> &vin, int pre_begin, int pre_end, int vin_begin, int vin_end)
	{
		int root_val = pre[pre_begin];
		TreeNode *root = new TreeNode(root_val);
		if (pre_begin == pre_end)
		{
			if (vin_begin == vin_end&&pre[pre_begin] == vin[vin_begin])
				return root;
			else
				exit(0);
		}
		int vin_root = vin_begin;
		while (vin_root <= vin_end&&vin[vin_root] != root_val)
			vin_root++;
		if (vin_root>vin_end || vin[vin_root] != root_val)
		{
			exit(0);
		}
		int left_length = vin_root - vin_begin;
		int right_length = vin_end - vin_root;
		if (left_length>0)
			root->left = ConstructCore(pre, vin, pre_begin + 1, pre_begin + left_length, vin_begin, vin_root - 1);
		if (right_length>0)
			root->right = ConstructCore(pre, vin, pre_begin + left_length + 1, pre_end, vin_root + 1, vin_end);
		return root;
	}
};