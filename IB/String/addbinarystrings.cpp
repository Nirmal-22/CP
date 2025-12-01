//my code (needed help)
string Solution::addBinary(string A, string B) 
{
    if(A.length()<B.length()) return addBinary(B,A);
    
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    for(int i=0;i<B.length();i++) A[i]=A[i]+B[i]-'0';
    
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='2' || A[i]=='3')
        {
            if(i== (A.length()-1) )
            {
                A[i]=A[i]-2;
                A+="1";
            }
            else
            {
                A[i]=A[i]-2;
                A[i+1]++;
            }
        }
    }    
    
    reverse(A.begin(),A.end());
    return A;
}
