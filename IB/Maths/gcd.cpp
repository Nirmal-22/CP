int Solution::gcd(int A, int B) 
{
    
    if(A==0) return B;
    if(B==0) return A;
    if(A>B) swap(A,B);
    return gcd(B%A,A);
}
