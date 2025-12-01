vector<int> Solution::dNums(vector<int> &A, int B) 
{
    vector<int> v;
    map<int,int> mp;
    set<int> s;
    int N=A.size();
    if(B>N) return v;
    
    for(int i=0;i<B;i++)
    {
        mp[A[i]]++;
        s.insert(A[i]);
    }
    
    v.push_back(s.size());
    
    
    for(int i=B;i<N;i++)
    {
        if(--mp[A[i-B]] == 0)
        s.erase(s.find(A[i-B]));
        
        if(++mp[A[i]] == 1)
        s.insert(A[i]);
        
        v.push_back(s.size());
    }
    
    return v;
}
