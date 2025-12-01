# include <bits/stdc++.h>
using namespace std;

bool vis[100001];
// int dist[100001],p[100001];
int a[100001];
int x=1;
	queue<int> q;
	vector<int> g[100001];

void dfs()
{
	while(!q.empty())
	{
		int u=q.front(); q.pop();

		x= (x==1)?2:1; // this is where I went wrong .. queue

		for(int v:g[u])
		{
			if(vis[v])
			{
				if(a[v]==a[u])
				{
					cout<<"IMPOSSIBLE"<<endl;
					exit(0);

					//return 0; it wont work here .. The return type of the function is void.
				}
			}
			if(!vis[v])
			{
				// dist[v]= dist[u]+1;
				vis[v]=true;
				// p[v]=u;
				a[v]=x;

				q.push(v);
			}
		}
	}

}
int main()
{
	int n,m; cin>>n>>m;

	for(int i=0;i<m;i++)
	{
		int a,b; cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}


	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			q.push(i);
			a[i]=1;
			x=1;
			vis[i] = true;
			dfs();
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}