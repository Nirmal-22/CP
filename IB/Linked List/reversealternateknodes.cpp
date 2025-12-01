/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) 
{
    ListNode* current=A;
    ListNode* prev=NULL;
    ListNode* next;
    
    int count=0;
    while(current!=NULL && count<B)
    {
        next= current->next;
        current->next= prev;
        prev= current;
        current= next;
        count++;
    }
    
    if(A!=NULL)
    A->next = current;
    
    count=0;
    while(count<B-1 && current!=NULL)
    {
        current = current->next;
        count++;
    }
    
    if(current!=NULL)
    current->next = solve(current->next,B);
    
    return prev;
}
