/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void diagonalTraversal(TreeNode* node, int diagonalLevel, unordered_map<int, vector<int>>& diagonalElements) 
{
    if (node == nullptr) 
    {
        return;
    }

    diagonalElements[diagonalLevel].push_back(node->val);

    diagonalTraversal(node->left, diagonalLevel + 1, diagonalElements);
    diagonalTraversal(node->right, diagonalLevel, diagonalElements);
}

vector<int> Solution::solve(TreeNode* A) {
    unordered_map<int, vector<int>> diagonalElements;
    diagonalTraversal(A, 0, diagonalElements);

    vector<int> ans;
    for (int i=0; i!=diagonalElements.size(); ++i) 
    {
        for (int val : diagonalElements[i]) 
        {
            ans.push_back(val);
        }
    }

    return ans;
}
