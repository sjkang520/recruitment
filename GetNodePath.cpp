//树中两个结点的最低公共祖先
#include <vector>
#include <list>
using namespace std;
struct TreeNode
{
	vector<TreeNode*> Children_;
};
//找出从pRoot到pNode的路径
bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
	if(pRoot==pNode)
		return true;
	path.push_back(pNode);
	bool found=false;
	auto it=pRoot->Children_.begin();
	while(!found&&it!=pRoot->Children_.end())
	{
		found=GetNodePath(*it,pNode,path);
		++it;
	}
	if(!found)
		path.pop_back();
	return found;
}