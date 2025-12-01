int Solution::solve(string A, string B) 
{
    vector <vector<int>> v(1006 , vector <int> (1006));
    long long int i,j;

    for(i=0;i<A.size();i++)
    {
        for(j=0;j<B.size();j++)
        {
            v[i][j]=0;
        }
    }
    
    for(i=1;i<=A.size();i++)
    {
        for(j=1;j<=B.size();j++)
        {
            if(A[i-1]==B[j-1])
            v[i][j]=1+v[i-1][j-1];
            else
            v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    return v[A.size()][B.size()];
}