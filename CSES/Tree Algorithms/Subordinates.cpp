# include <iostream>
# include <vector>

# define int long long
using namespace std;

vector<int> a[200001];
int s[200001];


	
void dfs(int u,int v)
{
	s[u]=1;

	for(int x:a[u])
	{
		if(x!=v)
		{
			dfs(x,u);
			s[u]+=s[x];
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin>>n;

	for(int i=2;i<=n;i++)
	{	
		int x; cin>>x;

		a[i].push_back(x);
		a[x].push_back(i);
	}


	dfs(1,0);

	for(int i=1;i<=n;i++)
	{
		cout<<s[i] - 1<<" ";
	}

	return 0;
}