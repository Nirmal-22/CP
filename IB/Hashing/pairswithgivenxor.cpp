int Solution::solve(vector<int> &A, int B) 
{
    unordered_set<int> seen;
    int count = 0;

    for (int num : A) 
    {
        int complement = B ^ num;
        if (seen.count(complement)) 
            count++;
        seen.insert(num);
    }

    return count;
}
