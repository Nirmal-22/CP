int Solution::findMinXor(vector<int> &v) 
{
    sort(v.begin(),v.end());
    int n=v.size();
    int x=v[0]^v[1];
    for(int i=1;i<(n-1);i++)
    {
        // if(v[i]^v[i+1]<x)
        //     x=v[i]^v[i+1];
        
        x= min(x,v[i]^v[i+1]);
    }
    return x;
}