bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int Solution::braces(string A) 
{
    stack<char> st;
    int n = A.length();
    
    for (int i = 0; i < n; i++) 
    {
        char curr = A[i];
        
        if (curr == '(' || isOperator(curr)) 
        {
            st.push(curr);
        }
        else if (curr == ')') 
        {
            if (st.empty() || st.top() == '(') 
            {
                return 1;  
            }
            
            while (!st.empty() && st.top() != '(') 
            {
                st.pop();
            }
            
            st.pop(); 
        }
    }
    
    return 0; 
}
