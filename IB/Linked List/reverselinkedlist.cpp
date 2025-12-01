/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev = NULL;
    ListNode* n;
    while(A){
        n = A->next;
        A->next = prev;
        prev = A;
        A = n;
    }
    return prev;
}