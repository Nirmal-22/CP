vector<int> Solution::findOccurences(vector<int> &A) {
    std::map<int, int> occurrenceMap;

    for (int num : A) 
    {
        occurrenceMap[num]++;
    }

    std::vector<int> result;

    for (const auto& pair : occurrenceMap) 
    {
            result.push_back(pair.second);
    }

    return result;
}
