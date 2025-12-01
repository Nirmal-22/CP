int Solution::majorityElement(const vector<int> &A) 
{
    
    unordered_map<int,int> mp;
    
    int mx=0;
    int ans;
    for(int x:A)
    {
        mp[x]++;
        // mx=max(mx,mp[x]);
        if(mp[x]>mx)
        {
            mx=mp[x];
            ans=x;
        }
    }
    
    if(mx>(int)(A.size()/2))
    return ans;
}
