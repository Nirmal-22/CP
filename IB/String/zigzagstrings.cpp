string Solution::convert(string A, int B) {
    if (B <= 1 || B >= A.size()) 
    {
        return A;
    }
    
    vector<string> rows(B);
    int currentRow = 0;
    bool goingDown = false;
    
    for (char c : A) 
    {
        rows[currentRow] += c;
        if (currentRow == 0 || currentRow == B - 1) 
        {
            goingDown = !goingDown;
        }
        currentRow += goingDown ? 1 : -1;
    }
    
    string result;
    for (string row : rows) 
    {
        result += row;
    }
    
    return result;
}
