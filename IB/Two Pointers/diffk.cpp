//not my code
int Solution::diffPossible(vector<int> &A, int B) {

    for(int i=0;i<A.size();i++){

        if(find(A.begin()+i+1,A.end(),A[i]+B)!=A.end())return 1;

        if (A[i]+B>A[A.size()-1])return 0;}

    return 0;}
