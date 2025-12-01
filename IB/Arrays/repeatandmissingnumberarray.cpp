vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int xor1 = 0, xor2 = 0;

    //[3 1 2 5 3] 
    // Calculate xor1 and xor2
    for (int i = 0; i < n; i++) 
    {
        xor1 ^= A[i] ^ (i + 1);  //1 to n and {  } 4^3
        xor2 ^= (i + 1);            //1 to n
    }

    // Find the rightmost set bit
    int rightmostSetBit = 1;
    while ((xor1 & rightmostSetBit) == 0) 
    {
        rightmostSetBit <<= 1;
    }

    int result1 = 0, result2 = 0;

    // Calculate result1 and result2
    for (int i = 0; i < n; i++) 
    {
        if (A[i] & rightmostSetBit) 
        {
            result1 ^= A[i];
            // cout<<"r1 "<<nums[i]<<endl;
        } 
        else 
        {
            result2 ^= A[i];
            // cout<<"r2 "<<nums[i]<<endl;
        }

        if ((i + 1) & rightmostSetBit) 
        {
            result1 ^= (i + 1);
            // cout<<"r1 "<<(i+1)<<endl;
        } 
        else 
        {
            result2 ^= (i + 1);
            // cout<<"r2 "<<(i+1)<<endl;
        }
    }

    // Find duplicate and missing elements
    for (int i = 0; i < n; i++) {
        if (A[i] == result1) {
            return {result1, result2};
        }
    }

    return {result2, result1};
}
