/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if (!A)
        return nullptr;

    stack<TreeNode*> stk;
    TreeNode* prev = nullptr;

    stk.push(A);

    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();

        if (node->right)
            stk.push(node->right);
        if (node->left)
            stk.push(node->left);

        if (prev) {
            prev->left = nullptr;
            prev->right = node;
        }

        prev = node;
    }
    return A;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
