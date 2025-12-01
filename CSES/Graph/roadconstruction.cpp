# include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;

int parent[N];
int sz[N];

void make(int v)
{
	parent[v]=v;
	sz[v]=1;
}

int find(int v)
{
	if(v==parent[v]) return v;
	
	return parent[v]=find(parent[v]);
}

bool Union(int &u,int &v)
// void Union(int u,int v)
{
	u=find(u); v=find(v);

	if(u==v) return false;
    // if(u==v) return;

	if(sz[u]<sz[v]) swap(u,v);

	sz[u]+=sz[v];
	parent[v]=u;
	
	return true;
}

int main()
{
	int n,m; cin>>n>>m;
	int cp=n;

	for(int i=1;i<=n;i++)
		make(i);
	   
	int mx=1;
	
	while(m--)
	{
		int u,v; cin>>u>>v;
		
		// Union(u,v);
		if(Union(u,v))
			cp--;
		
		cout<<cp<<" "<<(mx=max(mx,max(sz[u],sz[v])))<<endl;

	}

	return 0;
}