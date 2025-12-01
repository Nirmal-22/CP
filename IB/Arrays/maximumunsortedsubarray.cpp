vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int left = 0, right = n - 1;

    while (left < n - 1 && A[left] <= A[left + 1]) 
    {
        left++;
    }

    if (left == n - 1) 
    {
        return {-1};
    }

    while (right > 0 && A[right] >= A[right - 1]) 
    {
        right--;
    }

    int min_val = *min_element(A.begin() + left, A.begin() + right + 1);
    int max_val = *max_element(A.begin() + left, A.begin() + right + 1);
    
    // cout<<"min_val"<<" "<<min_val<<endl;
    // cout<<"max_val"<<" "<<max_val<<endl;
    // cout<<"left"<<" "<<A[left]<<endl;
    // cout<<"right"<<" "<<A[right]<<endl;
    
    while (left >= 0 && A[left] > min_val) 
    {
        left--;
    }

    while (right < n && A[right] < max_val) 
    {
        right++;
    }

    vector<int> v={left+1,right-1};
    return v;
}
