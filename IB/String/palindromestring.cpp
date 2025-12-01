int Solution::isPalindrome(string A) 
{
    int n=A.length();
    
    string ans="";
    
    for(int i=0;i<n;i++)
    {
        if((A[i]>='A'&&A[i]<='Z')|| (A[i]>='a'&&A[i]<='z'))
        ans+=tolower(A[i]);
        
        if(A[i]>='0'&&A[i]<='9')
        ans+=A[i];
    }
    
    n=ans.length();

    for(int i=0;i<n/2;i++)
    {
        if(ans[i]!=ans[n-1-i])
        return 0;
    }
    
    return 1;
}
