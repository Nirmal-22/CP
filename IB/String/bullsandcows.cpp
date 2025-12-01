string Solution::solve(string A, string B) {
    int bulls = 0;
    int cows = 0;
    std::unordered_map<char, int> ACounts;
    std::unordered_map<char, int> BCounts;

    // Count bulls and initialize count maps
    for (int i = 0; i < A.length(); ++i) 
    {
        if (A[i] == B[i]) 
        {
            bulls++;
        } 
        else 
        {
            ACounts[A[i]]++;
            BCounts[B[i]]++;
        }
    }

    // Count cows
    for (auto it = BCounts.begin(); it != BCounts.end(); ++it) 
    {
        if (ACounts.find(it->first) != ACounts.end()) 
        {
            cows += std::min(it->second, ACounts[it->first]);
        }
    }

    // Format the hint
    std::string hint = std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    return hint;
}
