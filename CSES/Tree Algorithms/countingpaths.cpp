# include <bits/stdc++.h>
using namespace std;

const int maxn= 2e5+1;
const int logn= 20;

int n,m,a,b,sub[maxn],p[maxn][logn];
int timer, in[maxn], out[maxn];

vector<int> g[maxn];

void dfs1(int u=1,int par=1)
{
	in[u] = ++timer;

	p[u][0] = par;

	for(int i=1;i<logn;i++)
		p[u][i] = p[p[u][i-1]][i-1];

	for(int v: g[u])
		if(v!=par)
			dfs1(v,u);

	out[u]= ++timer;
}

void dfs2(int u=1)
{
	for(int v: g[u])
	{
		if(v!=p[u][0])
		{
			dfs2(v);
			sub[u]+=sub[v];
		}
	}
}

bool ancestor(int u,int v)
{
	return in[u]<=in[v] && out[u]>=out[v];
}

int lca(int u,int v)
{
	if(ancestor(u,v)) return u;
	if(ancestor(v,u)) return v;

	for(int i=logn-1; i>=0;i--)
		if(!ancestor(p[u][i],v))
			u=p[u][i];

	return p[u][0];
}

int main()
{
	int n,m; cin>>n>>m;

	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs1();

	for(int i=0;i<m;i++)
	{
		cin>>a>>b;

		int l=lca(a,b);

		sub[a]++; sub[b]++;
		sub[l]--;

		if(l!=1)
			sub[p[l][0]]--;
	}

	dfs2();

	for(int i=1;i<=n;i++)
		cout<<sub[i]<<" ";

	return 0;
}