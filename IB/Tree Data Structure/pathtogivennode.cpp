/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool findPath(TreeNode* root, int target, std::vector<int>& path) 
{
    if (root == nullptr)
        return false;

    path.push_back(root->val);

    if (root->val == target)
        return true;

    if (findPath(root->left, target, path) || findPath(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) 
{
    std::vector<int> path;
    findPath(A, B, path);
    return path;
}
