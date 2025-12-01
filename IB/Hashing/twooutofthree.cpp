vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_set<int> setA, setB, setC;
    set<int> result;

    for (int num : A) 
        setA.insert(num);
    

    for (int num : B) 
        setB.insert(num);
    

    for (int num : C) 
        setC.insert(num);
    

    for (int num : setA) 
        if (setB.count(num) || setC.count(num)) 
            result.insert(num);
        

    for (int num : setB) 
        if (setA.count(num) || setC.count(num)) 
            result.insert(num);
        

    for (int num : setC) 
        if (setA.count(num) || setB.count(num)) 
            result.insert(num);
        

    vector<int> sortedResult(result.begin(), result.end());

    return sortedResult;
}
