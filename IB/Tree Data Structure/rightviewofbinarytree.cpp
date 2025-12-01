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
    // static int dp=0;
    
    queue<pair<TreeNode*,int>> q;
    
    q.push({A,0});
    map<int,int> mp;
    
    vector<int> v;
    
    while(!q.empty())
    {
        mp[q.front().second]=q.front().first->val;
        if(q.front().first->left)
        {
            q.push({q.front().first->left,q.front().second+1});
        }
        
        if(q.front().first->right)
        {
            q.push({q.front().first->right,q.front().second+1});
        }
        
        q.pop();
    }
    
    for(auto i:mp)
    {
        v.push_back(i.second);
    }
    
    return v;    
}
