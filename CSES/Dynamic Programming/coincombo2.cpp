//# include <iostream>
# include <bits/stdc++.h>

using namespace std;

# define int long long

int dp[1000001];
int mod=1e9+7;

//int dfs(int s,int (&a)[n])
int dfs(int j,int s,int n,int *a)
{
	if(s==0)
	return 1;

	if(dp[s]!=-1)
	return dp[s];

	int c=0;

	//for(int i:a)
	for(int i=j;i<n;i++)
	{
		if(s>=a[i])
		c= c + dfs(i,s-a[i],n,a);
	}

	return dp[s]=c%mod;
}

signed main()
{
	memset(dp,-1,sizeof(dp));

	int n,s; cin>>n>>s;

	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	cout<<dfs(0,s,n,a);

	return 0;
}