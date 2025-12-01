vector<int> Solution::solve(vector<int> &A, int B) 
{
    vector<int> ans;
    priority_queue<int> pq;
    
    for(int i=0;i<B;i++)
    {
        pq.push(-A[i]);
    }
    
    for(int i=B;i<A.size();i++)
    {
        if(A[i] > -pq.top())
        {
            pq.pop();
            pq.push(-A[i]);
        }
    }
    
    while(!pq.empty())
    {
        ans.push_back(-pq.top());
        pq.pop();
    }
    
    return ans;
}