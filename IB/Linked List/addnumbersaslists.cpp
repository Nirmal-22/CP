/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    ListNode* a=A;
    ListNode* b=B;
    
    int na=1,nb=1;
    while(a->next != NULL)
    {
        na++;
        a = a->next;
    }
    
    while(b->next != NULL)
    {
        nb++;
        b = b->next;
    }
    
    if(nb>na) addTwoNumbers(B,A);
    
    a=A,b=B;
    
    int carry=0;
    int sum=0;
    while(na--)
    {
        
        if(B == NULL)
        {
            sum=(A->val + B->val + carry);
            A->val = sum%10;
            carry = sum/10;
            
            sum=0;
            A = A->next;
            B = B->next;
        }
        
        sum=(A->val + carry);
        A->val= sum%10;
        carry= sum/10;
        sum=0;
        A = A->next;
    }
    
    if(carry!=0)
    {
        ListNode* node= new ListNode(carry); //syntax
        // node->val = carry;
        // node->next = NULL;
        
        A->next = node;
    }
    
    return a;
}
