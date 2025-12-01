int Solution::solve(int A, int B, int C) 
{
    C=C%B;   
    int rem=A%B;
    
    return (C+rem-1)%B;
}
