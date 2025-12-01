int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    for(auto &i:A)
        m[i]++;
    for(auto &i:m)
    {
        i.second--;
        if(m[B-i.first]>0 || m[i.first-B]>0)
            return 1;
        i.second++;    
    }
    return 0;
}
