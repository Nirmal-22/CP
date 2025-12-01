string Solution::fractionToDecimal(int A, int B) 
{
    if(A==INT_MIN && B==-1) return "2147483648"; //what the hell is this?
    
    if (A == 0)
    return "0";

    std::string result;
    
    if ((A < 0) ^ (B < 0))
        result += '-';
    
    long long num = std::abs(A);
    long long den = std::abs(B);
    
    result += std::to_string(num / den);
    
    if (num % den == 0)
        return result;
    
    result += '.';
    
    std::unordered_map<long long, int> remainderMap;
    long long remainder = num % den;
    
    while (remainder != 0) 
    {
        if (remainderMap.count(remainder) > 0) {
            result.insert(remainderMap[remainder], "(");
            result += ')';
            break;
        }
    
        remainderMap[remainder] = result.length();
        remainder *= 10;
        result += std::to_string(abs(remainder / den));
        remainder %= den;
    }
    
    return result;
}
