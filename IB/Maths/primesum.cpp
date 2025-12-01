vector<int> Solution::primesum(int A) 
{
    int n=A;
    vector<int> v;   
    
    bool prime[A];
    memset(prime,true,sizeof(prime));
    
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            prime[j]=false;
        }
    }
    
    for(int i=2;i<=(n/2);i++)
    {
        if(prime[i]&&prime[A-i])
        {
            v.push_back(i);
            v.push_back(A-i);
            break;
        }
    }
    
    return v;
}
