int Solution::reverse(int A) 
{
    int flag=0;
    
    if(A<0)
    {
        // cout<<"-"<<endl;
        A*=-1;
        flag=1;
    }
    
    int a=A;
    long long l=0;
    
    while(a>0)
    {
        int d=a%10;
        l=l*10+d;
        a/=10;
    }
    
    // cout<<l<<endl;
    int r=(int)l;
    
    if(r==l)
    return r* ( (flag==0)?1:-1);
    else
    return 0;
}
