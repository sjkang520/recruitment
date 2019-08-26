//链表反转

struct ListNode{
	int item;
	ListNode* next;
}

ListNode* reverseList(ListNode* first)
{
	ListNode* cur=first;
	ListNode* pre=NULL;
	ListNode* pReversedHead=NULL;
	while(cur!=NULL)
	{
		ListNode* tmp=cur->next;
		if(tmp==NULL)
			pReversedHead=cur;
		cur->next=pre;
		pre=cur;
		cur=tmp;

	}
	return pReversedHead;
}