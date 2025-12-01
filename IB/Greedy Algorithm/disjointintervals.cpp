bool comp(vector<int> a,vector< int> b)
{
    return a[1]<b[1];           //bruh why a[1]<b[1] why.... why not a[0]<b[0]
}

int Solution::solve(vector<vector<int>> &A) 
{
    sort(A.begin(),A.end(),comp);
    
    // for()
     int n=A.size();
    
    // vector<vector<int>> ans;
    int c=1;
    vector< int> v=A[0];
    for( int i=1;i<n;i++)
    {
        if(v[1]<A[i][0])
        {
            c++;
            // ans.push_back(v);
            v=A[i];
        }

    }

    // return ans.size();
    return c;
}