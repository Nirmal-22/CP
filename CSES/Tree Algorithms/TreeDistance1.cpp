# include <iostream>
# include <vector>

# define int long long
using namespace std;

vector<int> a[200001];

int z[200001]={0};

// vector<int> max;
int maxa=0;

void dfs(int u,int l,int p)
{

	if(z[u]==0)
	for(int x:a[u])
	{
		if(x!=p)
			dfs(x,l+1,u);
	}

	else
		l=l+z[u];

	if(l>maxa)
		maxa=l;
}

signed main()
{
	int n; cin>>n;

	// int l[n+1]={0};

	for(int i=1;i<n;i++)
	{
		int x,y; cin>>x>>y;

		a[x].push_back(y);
		a[y].push_back(x);
	}

	for(int i=1;i<=n;i++)
	{
		for(int x:a[i])
		{
			dfs(x,1,i);
		}

		z[i]=maxa;
		maxa=0;
	}

	for(int i=1;i<=n;i++)
	{
		cout<<z[i]<<" ";
	}

	return 0;
}