/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void inOrderTraversal(TreeNode* node, int B, int& count, int& result) 
    {
        if (!node) return;

        inOrderTraversal(node->left, B, count, result);

        count++;
        if (count == B) 
        {
            result = node->val;
            return; 
        }

        inOrderTraversal(node->right, B, count, result);
    }
    
int Solution::kthsmallest(TreeNode* A, int B) {
    int count = 0;
        int result = -1; 

        inOrderTraversal(A, B, count, result);
        return result;
}
