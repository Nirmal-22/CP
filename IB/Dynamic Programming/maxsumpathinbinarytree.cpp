/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int calculateMaxPathSum(TreeNode* node, int& max_sum) 
    {
        if (node == nullptr) 
        {
            return 0;
        }

        int left_sum = max(0, calculateMaxPathSum(node->left, max_sum));
        int right_sum = max(0, calculateMaxPathSum(node->right, max_sum));

        max_sum = max(max_sum, node->val + left_sum + right_sum);

        return node->val + max(left_sum, right_sum);
    }
    
int Solution::maxPathSum(TreeNode* A) {
    int max_sum = INT_MIN; 
        calculateMaxPathSum(A, max_sum);
        return max_sum;
}
