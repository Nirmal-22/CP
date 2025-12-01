/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (!A || B == C) 
    {
        return A;
    }

    ListNode dummy(0);
    dummy.next = A;
    ListNode* prev = &dummy;
    ListNode* curr = A;

    for (int i = 1; i < B; i++) 
    {
        prev = curr;
        curr = curr->next;
    }

    ListNode* prev_B = prev;
    ListNode* tail = curr;
    ListNode* next_node = nullptr;
    
    for (int i = B; i <= C; i++) 
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    prev_B->next = prev;
    tail->next = curr;

    return dummy.next;
}
