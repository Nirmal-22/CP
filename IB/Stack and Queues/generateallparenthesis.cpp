int Solution::isValid(string A) {
     std::stack<char> stack;
    
    for (char c : A) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.empty()) {
                return 0;  
            } else {
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return 0;  
                    }
            }
        }
    }
    
    return stack.empty() ? 1 : 0;
}
