/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode* reverseList(ListNode* A) 
{
    ListNode* prev = nullptr;
    ListNode* current = A;
    while (current) 
    {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    if (!A || !A->next || !A->next->next) 
    {
        return A;
    }

    ListNode* slow = A;
    ListNode* fast = A;

    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr; 

    secondHalf = reverseList(secondHalf);

    ListNode* firstHalf = A;
    while (firstHalf && secondHalf) 
    {
        ListNode* temp1 = firstHalf->next;
        ListNode* temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }

    return A;   
}
