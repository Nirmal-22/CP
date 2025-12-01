# include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;

	vector<int> g[100001];
	for(int i=0;i<m;i++)
	{
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<int> q;
	q.push(1);

	bool vis[100001];
	vis[1] = true;
	int dist[100001],p[100001];

	while(!q.empty())
	{
		int u=q.front(); q.pop();

		for(int v:g[u])
		{
			if(!vis[v])
			{
				dist[v]= dist[u]+1;
				vis[v]=true;
				p[v]=u;
				q.push(v);
			}
		}
	}

	if(!vis[n])
	{
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}

	int u=n;
	int k= dist[n];

	vector<int> ans(k+1);

	for(int i=k;i>=0;i--)
	{
		ans[i]=u;
		u=p[u];
	}

	cout<<k+1<<endl;

	for(int i=0;i<=k;i++)
	{
		cout<<ans[i]<<" ";
	}
}