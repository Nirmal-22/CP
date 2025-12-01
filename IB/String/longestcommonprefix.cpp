string Solution::longestCommonPrefix(vector<string> &A) 
{
    //n=sizeof(A)/sizeof(A[0])
    int n=A.size();
    
    int mn=A[0].length();
    
    for(auto &x:A)
    // mn=min(mn,x.length());
    mn = (x.length()<=mn)?x.length():mn;
    
    string str="";
    for(int i=0;i<mn;i++)
    {
        int j;
        for(j=1;j<n;j++)
        {
            if(A[j][i] != A[j-1][i])
            {
                return str;
            }         
        }
        if(j==n)
        str+=A[0][i];
    }
    
    return str;
}
