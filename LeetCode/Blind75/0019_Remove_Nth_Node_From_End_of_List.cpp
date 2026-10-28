// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode * fast=&dummy, *slow=&dummy;

        for(int i=0;i<=n;i++) fast=fast->next;

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* to_rem = slow->next;
        slow->next = to_rem->next;
        delete to_rem;

        return dummy.next;
    }
};
