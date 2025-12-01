int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    vector<int> v;
    
    for(int i=0;i<A.size();i++)
    {
        v.push_back(A[i]-B[i]);
    }
    
    vector<int> a;
    
    int sum=0;
    int x=0;
    for(int i=0;i<A.size();i++)
    {
        sum=sum+v[i];
        
        if(sum<0)
        {
            a.push_back(sum);
            sum=0;
            x=i+1;
        }
    }
    
    if(x==A.size())
        return -1;
    else
    {
        for(int b:a)
        {
            sum=sum+b;
        }
        
        if(sum>=0) return x;
        else return -1;
    }
}
