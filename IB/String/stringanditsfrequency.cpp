string Solution::solve(string A) 
{
    unordered_map<char,int> mp;
    
    for(int i=0;i<A.length();i++)
    {
        mp[A[i]]++;
    }
    
    string ans="";
    for(int i=0;i<A.length();i++)
    {
        if(mp[A[i]]!=0) 
        {
            ans+= A[i] + to_string(mp[A[i]]);
            mp[A[i]]=0;
        }
    }
    
    return ans;
}

