int Solution::solve(int A) 
{
    int c1=__builtin_popcount(A);
    int x=A;
    int pb=0;
    int sum=0;
    while(x)
    {
        if(x&1==1)
        {
            sum = sum + (((int)pow(2,pb-1))*pb)%1000000007;
            sum = sum + ((int)pow(2,pb-1)*(--c1)%1000000007);
        }
        pb++;
        x>>1;
    }
    
    return sum;
}
