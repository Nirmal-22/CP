bool check(const std::vector<int>& A, int B, int capacity) 
{
    int days = 1;
    int currentWeight = 0;
    
    for (int weight : A) 
    {
        if (currentWeight + weight > capacity) 
        {
            days++;
            currentWeight = 0;
        }
        currentWeight += weight;
    }
    
    return days <= B;
}

int Solution::solve(vector<int> &A, int B) {
    int maxWeight = 0;
    int totalWeight = 0;
    
    for (int weight : A) 
    {
        maxWeight = std::max(maxWeight, weight);
        totalWeight += weight;
    }
    
    int left = maxWeight;
    int right = totalWeight;
    
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        
        if (check(A, B, mid)) 
        {
            right = mid;
        } 
        else
        {
            left = mid + 1;
        }
    }
    
    return left;
}
