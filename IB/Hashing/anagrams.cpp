vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
    unordered_map<string, vector<int>> anagramGroups;

    // for (const string& str : A) {
    for(int i=0;i<A.size();i++)
    {
        string sortedStr = A[i];
        sort(sortedStr.begin(), sortedStr.end());

        anagramGroups[sortedStr].push_back(i+1);
    }

    vector<vector<int>> result;
    for (const auto& group : anagramGroups) 
    {
        result.push_back(group.second);
    }
    
    sort(result.begin(),result.end());
    return result;
}
