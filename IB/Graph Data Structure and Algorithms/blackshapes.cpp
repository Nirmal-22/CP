void dfs(vector<string> &A,vector<vector<bool>> &visited,int row,int col)
{
	if(row<0 || col<0 || row>=A.size() || col>=A[0].size() || visited[row][col] || A[row][col]!='X')
	{
		return;
	}

	visited[row][col]=true;

	dfs(A,visited,row-1,col);
	dfs(A,visited,row+1,col);
	dfs(A,visited,row,col-1);
	dfs(A,visited,row,col+1);
}


int Solution::black(vector<string> &A) {
    if(A.empty())
	{
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	vector<vector<bool>> visited(rows,vector<bool>(cols,false));

	int count=0;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(!visited[i][j] && A[i][j]=='X')
			{
				count++;
				dfs(A,visited,i,j);
			}
		}
	}

	return count;
}
