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
    while (current != nullptr) 
    {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode* Solution::solve(ListNode* A) 
{
    if (A == nullptr || A->next == nullptr) {
        return A; 
    }

    ListNode* evenHead = nullptr;
    ListNode* evenTail = nullptr;
    ListNode* current = A;
    int index = 0;

    while (current != nullptr) 
    {
        if (index % 2 == 1) 
        { // Even position
            if (evenHead == nullptr)
            {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        current = current->next;
        index++;
    }

    evenHead = reverseList(evenHead);

    current = A;
    index = 0;

    while (current != nullptr) 
    {
        if (index % 2 == 1) // Even position
        { // Even position
            ListNode* temp = current->next;
            current->next = evenHead;
            evenHead = evenHead->next;
            current->next->next = temp;
        }
        current = current->next;
        index++;
    }

    return A;
}
