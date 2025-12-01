//not my code

void tree2graph(TreeNode* root,unordered_map<int,vector<int>> &adj,int parent)
{
    if(root==NULL) return ;
    if(parent!=-1)
    {
        adj[parent].push_back(root->val);
        adj[root->val].push_back(parent);
    }
    tree2graph(root->left,adj,root->val);
    tree2graph(root->right,adj,root->val);
    return ;
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) 
{
    unordered_map<int,vector<int> > adj;
    tree2graph(A,adj,-1);

    vector<int> ans;
    unordered_map<int,int>vis;
    queue<int> q;
    q.push(B);
    while(q.size()>0)
    {
        int s=q.size();
        if(C==0)
        {   
            while(q.size()>0)
            {
                ans.push_back(q.front());
                q.pop();
                
            }
            return ans;
        }
        while(s--)
        {
        int node=q.front();
        int par = q.front();
        q.pop();
        vis[node]=1;
        for(auto it:adj[node])
            {  if(!vis[it])
                { vis[it]=1;
                q.push(it);
                }
            }
                
        }
        C--;
        
    }
   
}