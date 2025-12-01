#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
const int N=1e6+5;
int dp[N];
vector<int> dice={1,2,3,4,5,6};
int solve(int n){
	if(n==0){
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int ways=0;
	for(auto x:dice){
		if(n>=x){
			ways+=solve(n-x);
		}
	}
	return dp[n]=ways%M;
}
 
signed main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}