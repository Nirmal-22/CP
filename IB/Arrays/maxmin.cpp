int Solution::solve(vector<int> &A) 
{
    int mn=A[0],mx=A[0];
    for(int i=0;i<A.size();i++)
    {
        mn=min(A[i],mn);
        mx=max(A[i],mx);
    }
    
    return mx+mn;
}
