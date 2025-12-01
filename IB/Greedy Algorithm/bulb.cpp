int Solution::bulbs(vector<int> &A) 
{
    int n=A.size();
    
    int c=0;
    // int ans=0;
    for(int i=0;i<n;i++)
    {
        if( (A[i]+c)%2==0)
        {
            // ans++;
            c++;
        }
    }        
    
    // return ans;
    return c;
}
