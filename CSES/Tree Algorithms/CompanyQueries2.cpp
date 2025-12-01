# include <bits/stdc++.h>
using namespace std;

const int maxn= 2e5 +1;

int n,Q,e,a,b,p[maxn][20];
int timer,in[maxn],out[maxn];

vector<int> g[maxn];

void dfs(int u=1,int par=1)
{
	in[u] = ++timer;
	p[u][0] =par;

	for(int i=1;i< 20/*log(n)*/;i++)
		p[u][i] = p[p[u][i-1]][i-1];   /////

	for(int v:g[u])
		if(v!=par)
			dfs(v,u);

	out[u] = ++timer;
}

bool ancestor(int u,int v)
{
	return in[u]<=in[v] && out[u]>=out[v];
}

int lca(int u,int v)
{
	if(ancestor(u,v))
		return u;

	if(ancestor(v,u))
		return v;

	for(int i=20-1;i>=0;i--)
	{
		if(!ancestor(p[u][i],v))
			u=p[u][i];
	}

	return p[u][0];
}


int main()
{
	scanf("%d,%d",&n,&Q);

	for(int i=2;i<=n;i++)
	{
		scanf("%d",&e);
		g[e].push_back(i);
		g[i].push_back(e);
	}

	dfs();

	for(int q=0;q<Q;q++)
	{
		scanf("%d,%d",&a,&b);
		printf("%d\n",lca(a,b));
	}

	return 0;
}