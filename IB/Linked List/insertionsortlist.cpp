/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    
    if(A == nullptr || A->next == nullptr)
    {
        return A;
    }

    function<void(ListNode*&, ListNode*)> dfs =[&](ListNode* &sorted,ListNode* node)
    {
        if(sorted == nullptr || node->val <sorted->val)
        {
            node->next = sorted;
            sorted = node;
        }
        else
        {
            ListNode* temp= sorted;

            while(temp->next!=nullptr && node->val > temp->next->val)
            {
                temp=temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    };

    ListNode* sorted = nullptr;
    ListNode* current = A;
    while(current!=nullptr)
    {
        ListNode* next= current->next;
        dfs(sorted, current);
        current = next;
    }

    return sorted;

}
