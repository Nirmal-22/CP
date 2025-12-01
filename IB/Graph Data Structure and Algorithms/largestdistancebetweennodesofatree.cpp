//not my code

int ans;
int dfs(int node,unordered_map<int,vector<int>> &adj)
{
    if(adj.find(node)==adj.end()) return 1;
    int n=adj[node].size();
    for(int i=0;i<n;i++)
    adj[node][i] = dfs(adj[node][i],adj);

    sort(adj[node].begin(),adj[node].end(),greater<int>());

    if(n>1)
    {
        ans = max(ans,adj[node][0]+adj[node][1]);
    }
    else ans=max(ans,adj[node][0]);
    return 1 + adj[node][0];
}

int Solution::solve(vector<int> &A)
{
    int root;
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==-1)
        root=i;
        else
        adj[A[i]].push_back(i);
    }
    if(A.size()==1) return 0;
    ans=1;
    dfs(root,adj);
    return ans;
}