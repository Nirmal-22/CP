//DIY
//My code tho
vector<vector<int> > Solution::prettyPrint(int A) 
{
    int n=A;
    
    vector<int> v(2*n-1);
    
    vector<vector<int>> ans(2*n-1);
    
    for(int i=n;i>=1;i--)
    {
        int x=0;
        for(int j=n;j>=i;j--,x++) //Check greater than/less than in pyramid
        {
            v[x]=j;
            v[2*n-2 -x]=j;    
            // cout<<x<<" "<<(2*n-2 -x)<<" "<<j<<endl;
        }
        for(int j=x;j<=((2*n-2)-x);j++,x++)
        {
            v[x]=i;
            v[2*n-2 -x]=i;
        }
        
        
        ans[n-i]= v;
        ans[2*n-2 - (n-i)] = v;
    }
    
    return ans;
}
