/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Create a dummy node to simplify code.
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (A != nullptr && B != nullptr) 
    {
        if (A->val < B->val) {
            current->next = A;
            A = A->next;
        } else {
            current->next = B;
            B = B->next;
        }
        current = current->next;
    }

    if (A != nullptr) {
        current->next = A;
    } else {
        current->next = B;
    }

    ListNode* mergedList = dummy->next;

    // Clean up the dummy node.
    delete dummy;

    return mergedList;
}
