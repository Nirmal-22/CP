int Solution::isPalindrome(int A) 
{
    
    if(A<0) return 0;
    int p=1,B=A,n=0;
    
    while(B>0)
    {
        n++;
        p*=10;
        B/=10;
    }
    p/=10;
    
    B=A;
    
    // cout<<n<<endl;
    // cout<<p<<endl;
    
    for(int i=1;i<=(n/2);i++)
    {
        int f=A/p;
        A=A%(p);
        p=p/10;
        
        int l=B%10;
        B=B/10;
        
        if(f!=l)
        return 0;
        // cout<<f<<" "<<l<<endl;
    }   
    
    return 1;
}