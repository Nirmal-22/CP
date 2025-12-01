//not my code
int Solution::solve(vector<string> &A) {

    vector<int> vect(26);
    for(auto x: A){
        for(auto ax: x){
            vect[ax - 'a']++;
        }
    }
    for(auto x: vect){
        if(x == 0) return 0;
    }
    return 1;
}
