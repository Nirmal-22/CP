unsigned int Solution::reverse(unsigned int A) 
{
    // uint32_t result = 0;
    unsigned int result=0;
    int bitCount = sizeof(A) * 8;  // Total number of bits in A

    while (bitCount--) {
        result <<= 1;  // Left shift result by 1 bit
        result |= A & 1;  // Set the rightmost bit of result with the rightmost bit of A
        A >>= 1;  // Right shift A by 1 bit
    }

    return result;
}
