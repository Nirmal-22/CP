int Solution::titleToNumber(string A) 
{
    int l=A.length();
    
    int sum=0;
    for(int i=0;i<l;i++)
    {
        sum+=pow(26,l-i-1)*(A[i]-'A'+1);
    }
    
    return sum;
}
