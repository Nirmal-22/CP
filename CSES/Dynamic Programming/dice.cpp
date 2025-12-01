// # include <iostream>
# include <bits/stdc++.h>
# define int long long
using namespace std;

const int m=1e9+7;
const int n=1e6+1;
int dp[n];

int dfs(int s)
{
		
	if(s==0)
		return 1;

	if(dp[s]!=-1)
		return dp[s];

	int c=0;

	for(int i=1;i<=6;i++)
	{
		if(s>=i)
		c= c+ dfs(s-i);
	}

	return dp[s] = c%m;
}

signed main()
{
	memset(dp,-1,sizeof(dp));

	int s; cin>>s;

	cout<<dfs(s);

	return 0;
}