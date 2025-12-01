vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> v;

    function<void(int)> dfs = [&](int i)
    {
        if (B == 0) 
        {
            sort(v.begin(), v.end());
            if(find(ans.begin(), ans.end(), v) == ans.end())
                ans.push_back(v);
            return;
        }
        if (i == A.size() || A[i] > B) return;
        for(; i < A.size() && (B-A[i]) >= 0; i++) 
        {
            v.push_back(A[i]);
            B = B - A[i];
            dfs(i+1);
            B = B + A[i];
            v.pop_back();
        }
    };

    dfs(0);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
