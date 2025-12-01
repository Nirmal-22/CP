# include <bits/stdc++.h>
using namespace std;

# define int long long
const int maxn = 1e5;

struct edge{int v; int w;};

struct node{int id; int dist;
friend bool operator<(const node &a, const node &b){
        return a.dist > b.dist;
    }};

int N,M,a,b;
int dist[maxn+1],c;
// vector<pair<int,int>> g[maxn+1];
// queue<pair<int,int>> q;
vector<edge> g[maxn+1];
priority_queue<node> q;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// #ifdef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif

	cin>>N>>M;

	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}

	memset(dist,0x3f, sizeof(dist));

	dist[1]=0;

	q.push({1,0});

	while(!q.empty())
	{
		// int  d= q.front().first;
		// int u=q.front().second;

		int d= q.top().dist;
		int u=q.top().id;

		q.pop();

		if(d>dist[u]) continue;

		// for(pair<int,int> e : g[u])
		for(edge e : g[u])
		{
			// if(dist[e.first] > d+e.second)
			// {
			// 	dist[e.first] = d+e.second;
			// 	q.push({e.first,dist[e.first]});
			// }

			if(dist[e.v] > d+e.w)
			{
				dist[e.v] = d+e.w;
				q.push({e.v,dist[e.v]});
			}
		}

		for(int i=1;i<=N;i++)
		{
			cout<<dist[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}