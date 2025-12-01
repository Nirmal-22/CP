vector<vector<int> > Solution::solve(int A) {
    std::vector<std::vector<int>> triangle;
    
    for (int i = 0; i < A; ++i) 
    {
        std::vector<int> row(i + 1, 1); // Start each row with 1
        for (int j = 1; j < i; ++j) 
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Calculate middle elements
        }
        triangle.push_back(row);
    }
    
    return triangle;
}
