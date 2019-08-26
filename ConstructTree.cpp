//根据前序遍历和中序遍历构建二叉树
#include <stdlib.h>
#include <stdio.h>
class TreeNode
{
public:
	TreeNode* left;
	TreeNode* rigth;
	int m_value;
	TreeNode(int value):m_value(value)
	{
		left=rigth=nullptr;
	}
	
};

TreeNode* contructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
	int value=startPreorder[0];
	TreeNode* node=new TreeNode(value);
	if(startPreorder==endPreorder)
	{
		if(startInorder==endInorder&&startPreorder[0]==startInorder[0])
			return node;
		else
		{
			printf("invalid input\n");
			return nullptr;
		}
	}
	int* rootInorder=startInorder;
	while(rootInorder<=endInorder&&*rootInorder!=value)
		++rootInorder;
	int leftlength=rootInorder-startInorder;
	int* leftPreorderEnd=startPreorder+leftlength;
	int rightlength=endInorder-rootInorder;
	if(leftlength>0)
		node->left=contructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
	if(rightlength>0)
		node->rigth=contructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
	return node;
}
TreeNode* construct(int* preorder,int* inorder,int length)
{
	if(preorder==nullptr||inorder==nullptr||length<=0)
		return nullptr;
	return contructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}
int main()
{
	int preorder[]={1,2,4,7,3,5,6,8};
	int inorder[]={4,7,2,15,3,8,6};
	TreeNode* root=construct(preorder,inorder,8);
}