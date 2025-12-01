int Solution::isPower(int A) 
{
    if(A==1) return 1;
    
    for(int i=2;i*i<=A;i++)
    {
        for(int j=2;j<=31;j++)
        if(pow(i,j)==A)
        return 1;
    }
    
    return 0;
}
