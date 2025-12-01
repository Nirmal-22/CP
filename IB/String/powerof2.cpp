//not my code

int Solution::power(string A) 
{
    while((atoi(A))>9)
    {
        (atoi(A))>>1;
    }
    
    if((atoi(A))==8)
    return 1;
    else
    return 0;
}