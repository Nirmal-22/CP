/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
if (A == NULL)
        return NULL;

    if (A->next == NULL) 
    {
        TreeNode* root = new TreeNode(A->val);
        return root;
    }

    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    TreeNode* root = new TreeNode(slow->val);

    root->left = sortedListToBST(A);
    root->right = sortedListToBST(slow->next);

    return root;
}
