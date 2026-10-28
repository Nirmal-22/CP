// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int A, int B) {
        while (B != 0) {
        int carry = A & B;  
        A = A ^ B;          
        B = carry << 1;     
    }
        return A;
    }
};
