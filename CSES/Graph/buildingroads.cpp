# include <iostream>
# include <vector>
using namespace std;

bool vis[100001]={0};
vector<int> edge[100001];

void dfs(int node)
{
	vis[node]=1;

	for(auto i:edge[node])
		if(!vis[i])
			dfs(i);
}
int main()
{
	int n,m; cin>>n>>m;

	vector<int> v;
	for(int i=0;i<=m;i++)
	{
		int a,b; cin>>a>>b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for(int i=1;i<n+1;i++)
	{
		if(!vis[i])
		{
			v.push_back(i);
			dfs(i);
		}
	}

	cout<<v.size()-1<<endl;

	for(int i=1;i<v.size();i++)
	{
		cout<<v[0]<<" "<<v[i]<<endl;
	}

	return 0;
}