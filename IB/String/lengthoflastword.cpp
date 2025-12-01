int Solution::lengthOfLastWord(const string A) 
{
    int n=A.length();
    
    string w="";
    string ans="";
    for(int i=0;i<n;i++)
    {
        
        if(A[i]!=' ')
        {
            w+=A[i];
        }
        else
        {
            if(w.length()>0)
            if(w[0]!=' ')
            ans=w;
            w="";
            
        }
    }
    if(w.length()>0)
    if(w[0]!=' ')
    ans=w;
    
    return ans.length();
}
