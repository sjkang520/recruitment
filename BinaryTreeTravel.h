#include <stack>
using namespace std;
struct node
{
	node* left;
	node* right;
	int value;
};
//前序遍历
//首先将根结点加入栈中，然后开始判断栈是否为空，若不为空，从栈中
//弹出一个结点并打印，同时判断右结点不为空，则将右结点加入栈中，再
//判断若左结点不为空，则将左结点加入栈中
void preorder(node* head)
{
	if(head!=NULL)
	{
		stack<node*> s;
		s.push(head);
		while(!s.empty())
		{
			int tops=s.top();
			s.pop();
			cout<<tops->value<<" ";
			if(head->right!=NULL)
				s.push(head->right);
			if(head->left!=NULL)
				s.push(head->left);
		}
	}
}

//中序遍历
//判断当前结点是否为空，若不为空将当前结点加入栈中，然后将该结点指向其左子结点
//若当前结点为空，则从栈中弹出一个元素打印，并将当前结点指向弹出元素的右子树
void inorder(node* head)
{
	if(head!=NULL)
	{
		stack<node*> s;
		while(!s.empty()||head!=NULL)
		{
			if(head!=NULL)
			{
				s.push(head);
				head=head->next;
			}
			else(head==NULL)
			{
				head=s.top();
				s.pop();
				cout<<head->value<<endl;
				head=head->right;
			}
		}
	}
}

//后序遍历，左子树-右子树-根结点
//反过来就是：根结点-右子树-左子树
//利用先序遍历，反向遍历，然后用栈保存
void postorder(node* head)
{
	if(head!=NULL)
	{
		stack<node*> s1;
		stack<node*> s2;
		s1.push(head);
		while(s1.empty())
		{
			node* tops=s1.top();
			s1.pop();
			s2.push(tops);
			if(tops->left)
				s1.push(tops->left);
			if(tops->right)
				s1.push(tops->right);
		}
		while(!s2.empty())
		{
			cout<<s2.top()->value<<" ";
			s2.pop();
		}
	}
}