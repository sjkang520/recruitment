#include <iostream>
#include <queue>
using namespace std;
//�ҳ�����n��7���ֵĴ���
int FindNum7(int n)
{
	int counts = 0;
	for (int i = 1; i <= n; i*=10)
	{
		int a = n / i;
		int b = n%i;
		counts = counts + (a + 2) / 10 * i + (a % 10 == 7)*(b + 1);
	}
	return counts;
}
//���������
struct Node
{
	Node* left;
	Node* right;
	int value;
};
int widthOfBiTree(Node* root)
{
	if (root == NULL)
		return NULL;
	queue<Node*> q;
	q.push(root);
	int maxWidth = 0;
	while (true)
	{
		int len = q.size();
		if (len == 0)
			break;
		while (len>0)
		{
			Node* node = q.front();
			q.pop();
			--len;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		maxWidth = maxWidth > q.size() ? maxWidth : q.size();
	}
}
int main()
{
	cout << FindNum7(1000) << endl;
	system("pause");
}