/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int PathSum(TreeNode* root, int currentSum,int& B) 
{
    if (root == nullptr)
        return 0;

    currentSum += root->val;

    if (root->left == nullptr && root->right == nullptr)
        return (B==currentSum)?1:0;

    int leftSum = PathSum(root->left, currentSum,B);
    int rightSum = PathSum(root->right, currentSum,B);

    return (leftSum | rightSum);
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return PathSum(A, 0, B);
}
