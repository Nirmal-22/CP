int Solution::solve(string A) 
{
    int n=A.length();
    
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
        c++;
    }
    
    return (c*(n-c))%(int)(1e9+7);
}
