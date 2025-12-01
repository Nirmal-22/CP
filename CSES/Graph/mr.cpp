# include <iostream>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	q.push(1);

	vis[1] = true;

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
	k= dist[n];

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