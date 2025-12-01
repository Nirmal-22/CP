/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    ListNode* ogless= new ListNode(0);
	ListNode* ogmore= new ListNode(0);
	ListNode* less= ogless;
	ListNode* more= ogmore;

	while(A)
	{
		if(A->val < B)
		{
			less->next = A;
			less = less->next;
		}
		else 
		{
			more->next = A;
			more = more->next;
		}

		A=A->next;
	}

	more->next = nullptr;
	less->next = ogmore->next;

	return ogless->next;
}
