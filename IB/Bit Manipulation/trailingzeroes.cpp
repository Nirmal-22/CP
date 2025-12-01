int Solution::solve(int A) 
{
    int c=0;
    while((A&1) == 0)
    {
        c++;
        A=A>>1;
    }
    
    return c;
}
