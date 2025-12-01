//not my code
string Solution::solve(string A, int B) {
    string res = "";
    string temp = "";
    int count = 1;
    for(int i = 0; i < A.size(); i++) {
        temp.push_back(A[i]);
        if(A[i] == A[i+1]) count++;
        else {
            if(count == B) count = 1;
            else res += temp;
            temp = "";
        }
    }
    return res;
}