/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
        if (A == nullptr) return nullptr;

    A->left = solve(A->left);
    A->right = solve(A->right);

    if (A->left == nullptr && A->right != nullptr) 
    {
        TreeNode* temp = A;
        A = A->right;
        delete temp;
    }
    else if (A->left != nullptr && A->right == nullptr) 
    {
        TreeNode* temp = A;
        A = A->left;
        delete temp;
    }

    return A;
}
