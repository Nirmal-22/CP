int Solution::maximalRectangle(vector<vector<int> > &A) {
    if (A.empty()) return 0;
    int m = A.size();
    int n = A[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;
    for (int i = 0; i < m; i++) 
    {
        stack<int> s;
        for (int j = 0; j < n; j++) 
        {
            if (A[i][j] == 1) heights[j]++;
            else heights[j] = 0;
        }

    //     for (int j = 0; j < n; j++) 
    //     {
    //         while (!s.empty() && height[s.top()] >= height[j]) 
    //         {
    //             int tp = s.top();
    //             s.pop();
    //             int width = s.empty() ? j : j - s.top() - 1;
    //             maxArea = max(maxArea, height[tp] * width);
    //         }
    //         s.push(j);
    //     }

    //     while (!s.empty()) 
    //     {
    //         int tp = s.top();
    //         s.pop();
    //         int width = s.empty() ? n : n - s.top() - 1;
    //         maxArea = max(maxArea, height[tp] * width); 
    //     }
    // }
    // return maxArea;

        for (int i = 0; i <= heights.size(); ++i) 
        {
            while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()])) 
            {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
        s.push(i);
        }
    }

    return maxArea;
}
