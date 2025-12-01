int Solution::colorful(int A) 
{
    string s= to_string(A);
    int n=s.length();
    
    int i,j,k;
    unordered_map<int,int> mp;
    for(i=0;i<n;i++)
    {
        for(j=1;j<=(n-i);j++)
        {
            string str= s.substr(i,j);
            
            int p=1;
            for(k=0;k<str.length();k++)
                p=p* (str[k]-'0');
            
            if(mp.find(p)!=mp.end())
            return 0;
            
            mp[p]=1;
        }
    }
    
    return 1;
}
