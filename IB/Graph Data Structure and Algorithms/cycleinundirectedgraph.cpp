bool dfs(int i,int parent,vector<vector<int>> & graph,vector<int> &visited)
{
	visited[i]=true;
	for(auto x:graph[i])
	{
        // if (!visited[neighbor] && neighbor!=parent) { //not altogether
		if(!visited[x])
		{
			if(dfs(x,i,graph,visited))              
			{
				return true;                //sending true to the calling function
			}
		}
		else if(x!=parent)
		{
			return true;
		}
	}
	return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> graph(A + 1);

    for (auto x : B) 
    {
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }

    vector<int> visited(A + 1, 0);

    // function<bool(int, int)> dfs = [&](int i, int parent) 
    // {
    //     visited[i] = 1;

    //     for (auto x : graph[i]) 
    //     {
    //         if (!visited[x]) 
    //         {
    //             if (dfs(x, i)) 
    //             {
    //                 return true;
    //             }
    //         } 
    //         else if (x != parent) 
    //         {
    //             return true;
    //         }
    //     }

    //     return false;
    // };

    for (int i = 1; i <= A; i++) 
    {
        if (!visited[i]) 
        {
            if (dfs(i,-1,graph,visited)) 
            {
                return 1;
            }
        }
    }

    return 0;
}

