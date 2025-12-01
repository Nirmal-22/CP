# include <iostream>
# include <vector>

# define int long long
using namespace std;

vector<int> a[200001];
	
int used[200001];
int c=0;

void dfs(int u,int par)
{
	for(int i:a[u])
	{
		if(i!=par)
			dfs(i,u);
	}

	if(!used[u] && !used[par] && par!=0)
	{
		used[u]=used[par]=1;
		c++;
	}
}


signed main()
{

	ios::sync_with_stdio();
	cin.tie(0);

	int n; cin>>n;

	for(int i=0;i<n-1;i++)
	{
		int x,y; cin>>x>>y;

		a[x].push_back(y);
		a[y].push_back(x);
	}

	dfs(1,0);

	cout<<c<<endl;
	return 0;
}