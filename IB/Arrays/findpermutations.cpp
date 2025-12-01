vector<int> Solution::findPerm(const string A, int B) 
{
    std::vector<int> result;
    int low = 1;
    int high = B;

    for (char c : A) 
    {
        if (c == 'D') 
        {
            result.push_back(high);
            high--;
        } 
        else if (c == 'I') 
        {
            result.push_back(low);
            low++;
        }
    }

    result.push_back(low);

    return result;
}
