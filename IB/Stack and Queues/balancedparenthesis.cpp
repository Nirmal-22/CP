int Solution::solve(string A) 
{
    stack<int> st;
    
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='(')
        {
            st.push(1);
            continue;
        }
        else
        {
            if(!st.empty())
            st.pop();
            else
            return 0;
        }
        
    }
    
    if(st.empty()) return 1;
    else return 0;
}   