# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn= 2e5+1;

int n,a,b,sz[maxn];
ll down[maxn],up[maxn];
vector<int> g[maxn];


void dfs1(int u=1,int p=0)
{
	sz[u] =1;

	for(int v:g[u])
	{
		if(v!=p)
		{
			dfs1(v,u);
			sz[u] +=sz[v];
			down[u]+=down[v]+sz[v];
		}
	}
}

void dfs2(int u=1,int p=0)
{
	if(p!=0)
		up[u] = (up[p]+down[p]) + n - (2*sz[u]+down[u]);

	for(int v:g[u])
		if(v!=p)
			dfs2(v,u);
}

int main()
{
	cin>>n;

	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs1();
	// dfs2();

	// for(int i=1;i<=n;i++)
	// 	cout<<down[i]+up[i]<<" ";

	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<sz[i]<<" "<<down[i]<<endl;
	}
	return 0;
}