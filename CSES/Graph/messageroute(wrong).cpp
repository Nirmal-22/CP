// # include <iostream>
// # include <vector>

# include <bits/stdc++.h>

using namespace std;

bool vis[100001]={0};
vector<int> edge[100001];
int c=0;
queue<int> q;
int flag=0;
int min;

void dfs(int node,int n)
{
	vis[node]=1;
	
	if(node==n)
	{	
		if(q.size()<min)
		min=q.size();
		return;
	}

	for(auto i:edge[node])
		if(!vis[i])
		{
			q.push(i);
			dfs(i,n);
			if(flag==1)
				return;
			q.pop();
		}


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

	min=n;

	dfs(1,n);

	// cout<<v.size()-1<<endl;

	// for(int i=1;i<v.size();i++)
	// {
	// 	cout<<v[0]<<" "<<v[i]<<endl;
	// }

	if(!q.empty())
	{
		cout<<q.size()+1<<endl;
		cout<<1<<" ";
		while(!q.empty())
		{
			cout<<q.front()<<" ";
			q.pop();
		}
	}
	else
	{
		cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}