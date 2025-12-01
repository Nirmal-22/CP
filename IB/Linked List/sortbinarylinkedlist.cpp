/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) 
{
    ListNode* a=A;
    
    int c=0;
    while(a!=NULL)
    {
        if(a->val == 0)
        c++;   
        a = a->next;
    }
    
    a=A;
    while(a!=NULL)
    {
        if(c!=0)
        {
            a->val=0;
            c--;
        }
        else
        {
            a->val=1;
        }   
        a = a->next;
    }
    return A;
}
