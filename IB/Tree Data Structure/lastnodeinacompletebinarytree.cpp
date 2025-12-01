/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lastNode(TreeNode* A) {
    if (A == NULL) 
    {
        return -1;
    }

    std::queue<TreeNode*> q;
    q.push(A);

    int rightmost = -1;

    while (!q.empty()) 
    {
        TreeNode* curr = q.front();
        q.pop();
        rightmost = curr->val;

        if (curr->left) 
        {
            q.push(curr->left);
        }

        if (curr->right) 
        {
            q.push(curr->right);
        }
    }

    return rightmost;
}
