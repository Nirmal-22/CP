int dfs(int u,int parent, vector<int> adj[], vector<bool>& visited, int& result) 
{
  visited[u] = true;
  int count = 1;
  for (int v : adj[u]) 
  {
    if (!visited[v] && v!=parent) 
    {
      int subtree_size = dfs(v,u, adj, visited, result);
      if (subtree_size % 2 == 0) 
      {
        result++;
      } 
      else 
      {
        count += subtree_size;
      }
    }
  }
  return count;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<int> adj[A];
    for (auto& edge : B) 
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(A, false);
    int result = 0;
    dfs(0,-1, adj, visited, result);
    return result;
}
