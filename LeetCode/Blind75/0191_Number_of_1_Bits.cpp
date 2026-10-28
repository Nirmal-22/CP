// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t A) {
        int c=0;
    while(A>0)
    {
        if(A & 1)
        c++;
        
        A=A>>1;
    }
    
    return c;
    }
};
