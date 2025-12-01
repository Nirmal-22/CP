/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (!A) {
        return nullptr; // Empty list
    }

    ListNode* current = A;
    while (current->next) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; // Free memory for the duplicate node
        } else {
            current = current->next;
        }
    }

    return A;
}
