/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    for (int i = 0; i <= B; i++) 
    {
        if (fast == NULL) 
        {
            return A->next;
        }
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}
