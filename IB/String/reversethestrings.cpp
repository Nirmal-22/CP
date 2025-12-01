string Solution::solve(string A) 
{
    int n=A.length();
    
    string w="";
    string ans="";
    int flag=0;
    for(int i=0;i<n;i++)
    {
        
        if(A[i]==' ')
        {
            if(w.length()>0)
            if(w[0]!=' ')
            {
                if(flag==1)
                ans=w+" "+ans;
                else
                {
                    ans=w+ans;
                    flag=1;
                }
            }
            w="";
        }
        else
        {
            w+=A[i];
        }
        
    }
    
    if(w.length()>0)
    if(w[0]!=' ')
    {
        if(flag==1)
        ans=w+" "+ans;
        else
        ans=w+ans;
    }
    return ans;
}
