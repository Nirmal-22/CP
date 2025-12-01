vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int N=A.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < A.size(); i++) 
    {
        for (int j = 0; j < B.size(); j++) 
        {
            int sum = A[i] + B[j];
            if (pq.size() < N) 
            {
                pq.push(sum);
            } 
            else 
            {
                if (sum > pq.top()) 
                {
                    pq.pop();
                    pq.push(sum);
                } 
                else 
                {
                    break;
                }
            }
        }
    }
    vector<int> result;
    while (!pq.empty()) 
    {
        result.push_back(pq.top());
        pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
