int Solution::canJump(vector<int> &A) 
{
    int n = A.size();
    int lastPos = n - 1; 

    for (int i = n - 2; i >= 0; --i) 
    {
        if (i + A[i] >= lastPos) 
        {
            lastPos = i;
        }
    }

    return (lastPos == 0)?1:0;
}
