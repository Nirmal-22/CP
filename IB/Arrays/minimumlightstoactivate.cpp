//not my code
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int i=0;
    int cnt=0;
    while(i<n)
    {
        int lo=max(0,i-(B-1));
        int hi=min(n-1,i+(B-1));
        int c=0;
        for(int k=hi;k>=lo;k--)
        {
            if(A[k]==1)
            {
                cnt++;
                i=k+(B);
                c++;
                break;
            }
        }

        if(c==0)
            return -1;
    }

    return cnt;
}