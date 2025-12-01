// # include <iostream>
# include <bits/stdc++.h>
using namespace std;

const int maxn= 2e5+1;
const int logn=20;i

int n,m,a,b,sub[maxn],p[maxn][logn];
int timer,in[maxn],out[maxn];

vector<int> g[maxn];



int main()
{
	scanf("%d %d",&n,&m);

	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs1();

	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);

		int l= lca(a,b);
		sub[a]++; sub[b]++;
		sub[l]--;

		if(l!=1)
			sub[p[l][0]]--;
	}

	dfs2();

	for(int i=1;i<=n;i++)
		printf("%d%c",sub[i],("\n")[i==n]);
}