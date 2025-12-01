// coin combination

//# include <iostream>
# include <bits/stdc++.h>

using namespace std;
# define int long long

const int m=1e9 + 7;
const int N=1e6 + 5;

int dp[N];

set<set<int>> s;

int solve(int s,vector<int> &v)  //pass by reference
								 // if done by value, it will copy the vector multiple times hence tle.
{
	if(s==0)
		return 1;

	if(dp[s]!=-1)
		return dp[s];

	int c=0;
	for(int i:v)
	{
		
		if(s>=i)						//very important
			c= c + solve(s-i,v);
	}

	return dp[s]=c%m;
}


signed main()
{   
    memset(dp,-1,sizeof(dp));
	int n; cin>>n;
	int s; cin>>s;

	vector<int> v;

	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		
		v.push_back(x);
	}

	cout<<solve(s,v);
	return 0;
}