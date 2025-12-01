# include <bits/stdc++.h>
using namespace std;

const int N=2e5+1;

bool vis1[N];
bool vis2[N];

vector<int> g1[N],g2[N];

void dfs1(int u=1,int parent=0)
{
	vis1[u]=true;

	for(auto x:g1[u])
	{
		if(x!=parent && !vis1[x])
			dfs1(x,u);
	}
}

void dfs2(int u=1,int parent=0)
{
	vis2[u]=true;

	for(auto x:g2[u])
	{
		if(x!=parent && !vis2[x])
			dfs2(x,u);
	}
}

int main()
{
	int n,m; cin>>n>>m;

	while(m--)
	{
		int u,v; cin>>u>>v;

		g1[u].push_back(v);
		g2[v].push_back(u);
	}

	dfs1();
	dfs2();

	for(int i=1;i<=n;i++)
	{
		if(!vis1[i] || !vis2[i])
		// if(!(vis1[i] && vis2[i]))
		{
			cout<<"NO"<<endl;

			if(!vis1[i]) cout<<"1 "<<i<<endl;
			else cout<<i<<" 1"<<endl;

			return 0;
		}
	}

	cout<<"YES"<<endl;

	return 0;
}