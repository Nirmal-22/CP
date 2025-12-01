std::stack<int> dataStack;   
std::stack<int> minStack;   

MinStack::MinStack() 
{
    while (!dataStack.empty()) 
    {
        dataStack.pop();
    }
    while (!minStack.empty()) 
    {
        minStack.pop();
    }
}

void MinStack::push(int x) 
{
    dataStack.push(x);  

    if (minStack.empty() || x <= minStack.top()) 
    {
        minStack.push(x);  
    }
}

void MinStack::pop() 
{
    if (!dataStack.empty()) 
    {
        int top = dataStack.top();
        dataStack.pop();

        if (top == minStack.top()) 
        {
            minStack.pop();
        }
    }
}

int MinStack::top() 
{
    if (!dataStack.empty()) 
    {
        return dataStack.top();
    }
    return -1;  
}

int MinStack::getMin() 
{
    if (!minStack.empty()) 
    {
        return minStack.top();
    }
    return -1;  
}