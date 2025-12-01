int Solution::isInterleave(string s1, string s2, string s) 
{
    int m=s1.size();
    int n=s2.size();
   
    // if(m+n != s.size())
    // {
    //     return 0;
    // }
   
    vector<vector<bool>> dp(m+1 , vector<bool>(n+1 , false ));
      
     dp[0][0]=true;
     
     for(int i=1;i<=n;i++)
     {
         if(s2[i-1]==s[i-1] && dp[0][i-1]==true)
         {
             dp[0][i]=true;
         }
     }
     
    for(int i=1;i<=m;i++)
     {
         if(s1[i-1]==s[i-1] && dp[i-1][0]==true)
         {
             dp[i][0]=true;
         }
     }
     
     for(int i=1;i<=m;i++)
     {
         for(int j=1;j<=n;j++)
         {
             int k = i+j-1;
             
             if(s1[i-1]==s[k] && dp[i-1][j]==true)
             {
                 dp[i][j]=true;
             }
             
             if(s2[j-1]==s[k] && dp[i][j-1]==true)
             {
                 dp[i][j]=true;
             }
         }
     }
     
     return dp[m][n];
}