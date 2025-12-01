int Solution::solve(vector<int> &A, int B) 
{
    // int n = A.size();
    // sort(A.begin(), A.end());
    // int minElement = A[0];
    
    // for (int i = 1; i < n; i++) 
    // {
    //     if ((A[i] - minElement) % B != 0) 
    //     {
    //         return false;
    //     }
    // }
    // return true;
    
    sort(A.begin(), A.end());
    
    for(int i=1; i<A.size(); i++) 
    {
        if(A[i]-A[i-1] != x && A[i]-A[i-1] != 0) 
        {
            return 0;
        }
    }
    
    return 1;
}
