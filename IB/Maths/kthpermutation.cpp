long long fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

vector<int> Solution::findPerm(int A, long B) 
{
    vector<int> ans;
    vector<int> nums;
    for (int i = 1; i <= A; i++) {
        nums.push_back(i);
    }

    B--; // To convert to 0-based indexing

    for (int i = A - 1; i >= 0; i--) {
        int index = B / fact(i);
        ans.push_back(nums[index]);
        nums.erase(nums.begin() + index);
        B %= fact(i);
    }
    return ans;
}
