int Solution::solve(int A, int B, int C, int D) 
{
    // set<int> s;
    
    // s.insert(A);
    // s.insert(B);
    // s.insert(C);
    // s.insert(D);
    
    // if(s.size()==2)
    // {
        if((A==B && C==D)||(A==C && B==D) || (A==D && B==C))
        {
            return 1;
        }
    // }
    return 0;
}
