/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (!A || B == 0) {
        return A; 
    }

    int length = 1;
    ListNode* tail = A;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    B = B % length;

    if (B == 0) {
        return A;     }

    int new_head_position = length - B;
    ListNode* new_tail = A;
    for (int i = 1; i < new_head_position; i++) {
        new_tail = new_tail->next;
    }

    ListNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    tail->next = A;

    return new_head;
}
