string Solution::serialize(vector<string> &A) {
    string ans="";
    for(auto x:A)
    {
        ans+= x + to_string(x.length()) + "~";
    }
    
    return ans;
}

