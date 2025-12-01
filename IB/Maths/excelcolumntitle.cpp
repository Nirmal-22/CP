string Solution::convertToTitle(int A) {
    string result = "";
    while (A > 0) 
    {
        A--;
        result = char(A % 26 + 'A') + result;
        A /= 26;
    }
    return result;
}
