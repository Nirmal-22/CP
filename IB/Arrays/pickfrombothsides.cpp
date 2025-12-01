int Solution::solve(vector<int> &A, int B) 
{
    int n=A.size();
    int s=0;
    for(int i=0;i<B;i++)
    {
        s+=A[i];
    }
    
    int max=s,j=n-1;
    for(int i=B-1;i>=0;i--,j--)
    {
        s-=A[i];
        s+=A[j];
        
        if(s>max)
        max=s;
    }
    
    return max;
}
