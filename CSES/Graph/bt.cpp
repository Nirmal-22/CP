# include <bits/stdc++.h>
using namespace std;

const int max=100001;

int n,m;
bool possible,vis[max],team[max];
vector<int> g[max];

void dfs(int u,int p=0)
{
	for(int v:g[u])
	{
		if(v!=p)
		{
			team[v]= !team[u];
			vis[v]=true;
			dfs(v,u);
		}
		else
			if(team[v]==team[u])
				possible=false;
	}
}

int main()
{
	cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	possible = true;

	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(i);
		}
	}

	if(!possible)
		cout<<"IMPOSSIBLE"<<endl;
	else
		for(int i=1;i<=n;i++)
		{
			cout<<team[i]?1:2;
		}

		return 0;
}