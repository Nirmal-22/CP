int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n <= 1) return 0; 

    int jumps = 1; 
    int currMaxReach = A[0]; 
    int nextMaxReach = A[0]; 

    for (int i = 1; i < n; i++) 
    {
        if (i > currMaxReach) 
        {
            // cout<<"i currMaxReach "<<i<<" "<<currMaxReach<<endl;
            if (currMaxReach == nextMaxReach) 
                return -1;

            currMaxReach = nextMaxReach;
            jumps++;
        }
        
        // cout<<"nextMaxReach i A[i] "<<nextMaxReach<<" "<<i<<" "<<A[i]<<endl;
        nextMaxReach = std::max(nextMaxReach, i + A[i]);
        
        // if(nextMaxReach >= (n-1))  //manual 
        // return jumps+1;
    }
    
    return jumps;
}
