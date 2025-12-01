int Solution::solve(vector<int> &v) 
{
    int n=v.size();
    int x;
    for(int i=0;i<n;i++)
    {
        if((i+1)*(n-i)%2!=0)
        x=x^v[i];
    }

    return x;
}
