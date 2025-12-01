int Solution::evalRPN(vector<string> &A) 
{
    std::stack<int> stack;

    for (const auto& token : A) 
    {
        if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(operand1 + operand2);
            else if (token == "-")
                stack.push(operand1 - operand2);
            else if (token == "*")
                stack.push(operand1 * operand2);
            else if (token == "/")
                stack.push(operand1 / operand2);
        } 
        else 
        {
            int number = std::stod(token);
            stack.push(number);
        }
    }

    return stack.top();
}
