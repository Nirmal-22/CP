//not my code
void solve(vector<int> A, vector<vector<int>> &ans,int l,int r){
if(l==r){
ans.push_back(A);
return;
}
else{
for(int i=l;i<r;i++){
swap(A[i],A[l]);
solve(A,ans,l+1,r);
swap(A[i],A[l]);
}
}
}
vector<vector<int>> Solution::permute(vector<int> &A) {
vector<vector<int>> ans;
int n=A.size();
solve(A,ans,0,n);
return ans;
}