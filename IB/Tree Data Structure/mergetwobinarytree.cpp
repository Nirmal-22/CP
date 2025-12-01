/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if (A == nullptr) return B;
        if (B == nullptr) return A;

        TreeNode* newNode = new TreeNode(A->val + B->val);
        newNode->left = solve(A->left, B->left);
        newNode->right = solve(A->right, B->right);

        return newNode;
}
