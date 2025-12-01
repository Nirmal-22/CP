/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void dfs(TreeNode* node, vector<int>& path, int currSum, int targetSum, vector<vector<int>>& result) 
{
    if (node == NULL) 
    {
        return;
    }
    
    path.push_back(node->val);
    currSum += node->val;
    
    if (node->left == NULL && node->right == NULL && currSum == targetSum) 
    {
        result.push_back(path);
    }
    
    dfs(node->left, path, currSum, targetSum, result);
    dfs(node->right, path, currSum, targetSum, result);
    
    path.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> result;
    vector<int> path;
    
    dfs(A, path, 0, B, result);
    
    return result;
}
