bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current_node, int& A) 
{
    visited[current_node] = true;

    if (current_node == A) 
        return true;

    for (int x : graph[current_node]) 
        if (!visited[x]) 
            if (dfs(graph, visited, x, A)) 
                return true;

    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<vector<int>> graph(A + 1);
    
    for (auto edge : B) 
        graph[edge[0]].push_back(edge[1]);
    
    vector<bool> visited(A + 1, false);
    
    if (dfs(graph, visited, 1, A)) 
        return 1;
    
    return 0;
}
