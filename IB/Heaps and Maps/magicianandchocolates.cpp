#define MOD 1000000007

int Solution::nchoc(int A, vector<int> &B) {
    long long int totalChocolates = 0;
    priority_queue<int> bags;
    
    for (int i = 0; i < B.size(); i++) 
    {
        bags.push(B[i]);
    }
    
    while (A > 0) 
    {
        int currentBagChocolates = bags.top();
        bags.pop();
        
        totalChocolates = (totalChocolates + currentBagChocolates) % MOD;
        int newBagChocolates = currentBagChocolates / 2;
        bags.push(newBagChocolates);
        
        A--;
    }
    
    return totalChocolates;
}
