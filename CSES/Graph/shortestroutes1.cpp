// # include <iostream>
# include <bits/stdc++.h>
using namespace std;

vector<pair<int>> v[200001];
int s[100001]={0};

int dfs(int u,int par=0,int sum)
{
	if(u==1 && par!=0)
		return 0;

	for(int z:a[u])
	{
		int v=z.first;
		if(v!=par)
		{
			sum= sum+ a[u].second;
			s[u] = min(s[u],sum + dfs());


		}
	}
}

int main()
{
	int n,m; cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		int a,b,c; cin>>a>>b>>c;

		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}

	dfs(1);
}