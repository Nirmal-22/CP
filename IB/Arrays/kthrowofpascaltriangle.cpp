vector<int> Solution::getRow(int A) {
    std::vector<int> row(A + 1, 1);

    for (int i = 1; i <= A; ++i) 
    {
        for (int j = i - 1; j > 0; --j) 
        {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}
