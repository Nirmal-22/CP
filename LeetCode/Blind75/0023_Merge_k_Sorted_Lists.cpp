// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        struct Cmp { bool operator()(ListNode* a, ListNode* b) const {return a->val > b->val;}};
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for(auto n: lists) if(n) pq.push(n);

        ListNode dummy, *tail = &dummy;
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            tail->next = node; tail=node;
            if(node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
