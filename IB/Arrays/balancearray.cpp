//not my code
int Solution::solve(vector<int> &A)
{
    int n=A.size(),count=0;
    long long oddsum[n],evensum[n];
    oddsum[0]=A[0];
    if(n==1)
    return 1;
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        oddsum[i]=oddsum[i-1]+A[i];
        else
        oddsum[i]=oddsum[i-1];
    }
    evensum[0]=0;
    evensum[1]=A[1];
    for(int i=2;i<n;i++)
    {
        //cout<<"hi";
        if(i%2!=0)
        evensum[i]=evensum[i-1]+A[i];
        else
        evensum[i]=evensum[i-1];
    }
    //for(int i=0;i<n;i++)
    //cout<<evensum[i]<<" ";
    long long a=oddsum[n-1];
    long long b=evensum[n-1];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            int t=a-A[0];
            if(t==b)
            count++;
        }
        if(i==n-1)
        {
            if(n%2!=0)
            {
                int t=a-A[n-1];
                if(t==b)
                count++;
            }
            else
            {
                int t=b-A[n-1];
                if(a==t)
                count++;
            }
        }
        else
        {
            int x= evensum[i-1];
            int y= oddsum[i-1];
            int even=x+oddsum[n-1]-oddsum[i];
            int odd=y+evensum[n-1]-evensum[i];
            if(even==odd)
            count++;
        }
    }
    return count;
}