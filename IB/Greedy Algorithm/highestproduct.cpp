int Solution::maxp3(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int n=A.size();
    if(A[0]>=0)
    return A[n-1]*A[n-2]*A[n-3];
    
    if(A[n-1]<=0)
    return A[n-1]*A[n-2]*A[n-3];
    // return A[0]*A[1]*A[2]; wrong
    
    if(A[0]*A[1]<A[n-2]*A[n-3])
    return A[n-1]*A[n-2]*A[n-3];
    else 
    return A[0]*A[1]*A[n-1];
}
