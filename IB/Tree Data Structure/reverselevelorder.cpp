/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) 
{
    stack<int> s;
    queue<TreeNode*> q;
    
    q.push(A);
    
    while(!q.empty())
    {
        TreeNode* a=q.front();
        q.pop();
        s.push(a->val);
        
        if(a->right)        //traverse right first to make it reverse level order 
                            //or else it will become fully reversed regular traversal
        q.push(a->right);
        
        if(a->left)
        q.push(a->left);
    }
    
    vector<int> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    
    return v;
}
