//not my code
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

    vector<int> res;

    if(B== 0)   return res;

    map<int, int> m;

    int n = A.size();

    int maxi = INT_MIN;

    for(int i =0;i<B;i++){

        m[A[i]]++;

        maxi = max(maxi, A[i]);

    }

    res.push_back(maxi);

    for(int i=1;i<=n-B;i++){

        m[A[i-1]]--;

        if(m[A[i-1]] == 0){

            m.erase(A[i-1]);

        }

        m[A[B+i-1]]++;

        auto it = m.rbegin();

        res.push_back(it->first);

    }

    return res;

}