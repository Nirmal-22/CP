int Solution::divisibleBy60(vector<int> &A) 
{
    if(A.size()==1 && A[0]==0) 
        return 1;
        
    int sum = 0;
    bool hasEven = false;
    bool hasZero = false;
    for (int digit : A) 
    {
        sum += digit;
        if (digit == 0) 
        {
            hasZero = true;
        }
        else if (digit % 2 == 0) 
        {
            hasEven = true;
        }
    }
    return (sum % 3 == 0 && hasZero && hasEven)?1:0;
}
