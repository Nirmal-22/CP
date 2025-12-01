int Solution::maxSubArray(const vector<int> &A) 
{
    int n=A.size();
    
    int s=0;
    int max=A[0];
    for(int i=0;i<n;i++)
    {
        if(s<0 && A[i]>s)
        s=0;
        
        s+=A[i];
        
        if(s>max)
        max=s;
        
    }
    
    return max;
}
