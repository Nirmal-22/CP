# include <bits/stdc++.h>

using namespace std;

int mn=1000000;

int dp[1000001];

int dfs(int s,int c)
{
	if(s==0)
	{
		if(c<mn)
			mn=c;
		return mn;
	}

	if(dp[s]!=1000000)
		return dp[s];
	// string str=to_string(s);
	// sort(str.begin(),str.end(),greater<int>());
	// int x=stoi(str);
	int x=s;
	int cnt=0;

	while(x>0)
	{
		int d=x%10;

		if(d!=0)
		{
			dp[s]=min(dp[s],cnt=dfs(s-d,c+1));
		}

		x=x/10;
	}

	if(dp[s]!=1000000)
		dp[s]=cnt;

	return dp[s];
}

int main()
{
	memset(dp,1000000,sizeof(dp));

	int n; cin>>n;
	
	cout<<dfs(n,0)<<endl;
	
	cout<<mn<<endl;

	return 0;
}