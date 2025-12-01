/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* reverseGroup(ListNode* A, int B) 
{
    ListNode* prev = nullptr;
    ListNode* curr = A;
    ListNode* next = nullptr;
    
    while (B > 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        B--;
    }
    
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) 
{
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prev = dummy;
    ListNode* node = A;
    
    int count = 0;
    ListNode* curr = A;
    while (curr) 
    {
        curr = curr->next;
        count++;
        if (count == B) 
        {
            ListNode* group_end = prev->next;
            ListNode* nextnode = curr;
            // cout<<((prev)?prev->val:NULL)<<" "<<((curr)?curr->val:NULL)<<endl;
            
            prev->next = reverseGroup(node, B);
            // cout<<"node "<<node->val<<endl;
            node->next = nextnode;
            prev = group_end;
            node = nextnode;
            count = 0;
        }
    }
    
    return dummy->next;
}
