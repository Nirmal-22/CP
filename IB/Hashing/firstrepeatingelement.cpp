//my code
int Solution::solve(vector<int> &A) 
{
    int n=A.size();
    
    unordered_map<int,int> mp;
    int x=n,ans;
    for(int i=0;i<n;i++)
    {
        if(mp.count(A[i])>0)
        {
            if(mp[A[i]]<x)
            {
                ans=A[i];
                x=mp[A[i]];
            }
        }
        else
        {
            mp[A[i]]=i;
        }
    }
    
    if(x!=n)
    return ans;
    else 
    return -1;
}
    