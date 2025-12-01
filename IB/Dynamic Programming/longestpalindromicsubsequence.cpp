int Solution::solve(string A) 
{
    vector<vector<int>> v(1006,vector<int> (1006));
    string B=A;
    reverse(B.begin(),B.end());
    int m=A.length(),n= B.length();
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            v[i][j]=0;
            
    for(int i=1;i<=A.size();i++)
    {
        for(int j=1;j<=B.size();j++)
        {
            if(A[i-1]==B[j-1])
            v[i][j]=1+v[i-1][j-1];
            else
            v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    
    return v[A.size()][B.size()];
}
