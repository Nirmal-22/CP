vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> v;

    function<void(int,int)> dfs = [&](int i,int c)
    {
        if (c == 0) ans.push_back(v);   //first 

        for (;i<=A;i++) 
        {
            v.push_back(i);
            dfs(i+1,c-1);
            v.pop_back();
        }
    };
    dfs(1,B);
    return ans;
}
