/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) 
{
    struct ListNode* node = A;
    
    int c=1;
    while(node->next!=NULL)
    {
        c++;
        node = node->next;
    }
    
    node=A;
    
    int n=(c/2+1)-B;
    c=1;
    
    if(n<=0)
    return -1;
    else
    while(node->next!=NULL)
    {
        if(c==n)
        return node->val;
        
        c++;
        node = node->next;
    }
}