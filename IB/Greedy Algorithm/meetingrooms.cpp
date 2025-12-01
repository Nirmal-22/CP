

bool comp(pair<int,char> x, pair<int,char> y)
{
    if(x.first==y.first)
    return x.second>y.second;
    
    return x.first<y.first;
}

int Solution::solve(vector<vector<int> > &A) 
{
    vector<pair<int,char>> v;
    
    for(vector<int> x:A)
    {
        v.push_back({x[0],'x'});
        v.push_back({x[1],'y'});
    }
    
    sort(v.begin(),v.end(),comp);
    // sort(v.begin(),v.end());
    int mx=0;
    int c=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second=='x')
        c++;
        else
        c--;
        
        mx=max(mx,c);
    }
    
    return mx;
}