vector<vector<int> > Solution::subsets(vector<int> &A) 
{
    sort(A.begin(),A.end());
	vector<vector<int>> result;
    vector<int> temp;
      
    function<void(int)> dfs = [&](int x)
    {
      result.push_back(temp);
      for (int i = x; i < A.size(); i++) 
      {
        temp.push_back(A[i]);
        dfs(i + 1);
        temp.pop_back();
      }
    };

  dfs(0);
  return result;
}
  