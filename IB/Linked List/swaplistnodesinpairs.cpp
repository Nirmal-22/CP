/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) 
{
    if (!A || !A->next) 
    {
        return A;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = A;
    ListNode* prev = dummy;
    ListNode* curr = A;
    ListNode* next = A->next;

    while (curr && next) 
    {
        curr->next = next->next;
        next->next = curr;
        prev->next = next;

        prev = curr;
        curr = curr->next;
        if (curr) {
            next = curr->next;
        }
    }

    return dummy->next;
}
