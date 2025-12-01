vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int>> ans;
    vector<int> v;

    function<void(int)> dfs = [&](int i)
    {
        if (B == 0) ans.push_back(v);   //first 
        if (i == A.size()) return;      //second
        while (i < A.size() && B - A[i] >= 0) 
        {
            v.push_back(A[i]);
            B=B-A[i];
            dfs(i);
            B=B+A[i];
            i++;
            v.pop_back();
        }
    };
    dfs(0);
    return ans;
}