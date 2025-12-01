/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* head) 
{
    if(!head || !head->next) return true;

	ListNode *slow=head, *fast=head;
	while(fast->next!=NULL && fast->next->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}

	ListNode* prev=NULL, *curr = slow->next, *next=NULL;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	ListNode *p1=head,*p2=prev;
	while(p2)
	{
		if(p1->val != p2->val) return 0;
		p1=p1->next;
		p2=p2->next;
	}

	return 1;
}
