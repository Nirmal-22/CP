# include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+1;


int N,Q;
long long z[maxn];
int a,b;

vector<int> g[maxn];
int in[maxn],out[maxn];
int timer=0;

long long ds[2*maxn]={0};
long long negative[2*maxn]={0};

int t,s;
long long x;

void dfs(int u=1, int p=0)
{
	in[u]=++timer;

	for(int v:g[u])
		if(v!=p)
			dfs(v,u);

	out[u]=++timer;
}


void update(int idx, long long val)
{
	for(int i=idx; i<=timer;i += -i&i)
		if(val>ds[i])
			ds[i]=val;
}

long long query(int idx)
{
	long long max=0;
	for(int i=idx;i>0; i -= -i&i)
		if(ds[i]>max)
			max=ds[i];

	return max;
}

int main()
{
	cin>>N>>Q;

	for(int i=1;i<=N;i++)
		cin>>z[i];

	for(int i=1;i<=(N-1);i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs();

	for(int i=1;i<=N;i++)
	{
		update(out[i],-z[i]);
		update(in[i],z[i]);
	}

	for(int q=0;q<Q;q++)
	{
		cin>>t>>s;

		if(t==1)
		{
			cin>>x;
			update(in[s],-z[s]);
			update(out[s],z[s]);
			update(in[s],x);
			update(out[s],-x);
			z[s]=x;
		}
		else if(t==2)
		{
			cout<<query(in[s])<<endl;
		}
	}
}