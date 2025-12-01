# include <iostream>
using namespace std;

const int n=8;
const int h[]={-2,-1,1,2,2,1,-1,-2};
const int v[]={1,2,2,1,-1,-2,-2,-1};

bool vis[n][n];
int ans[n][n], deg[n][n];

bool inbounds(int x,int y)
{
	return x>=0 && x<n && y>=0 && y<n;
}

void init()
{
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			for(int i=0;i<n;i++)
			{
				int dx= x + h[i];
				int dy= y + v[i];
				if(inbounds(dx,dy))
					deg[x][y]++;			//deg - no of possibilities for every place
			}
		}
	}
}

void mark(int id, int x, int y)
{
	ans[x][y] = id;
	vis[x][y] = true;

	for(int i=0;i<n;i++)
	{
		int dx= x+ h[i];
		int dy= y+ v[i];
		if(inbounds(dx,dy) && !vis[dx][dy])
			deg[dx][dy]--;			// no of possiblities of dx&dy(decreased by 1)after x&y are chosen...
	}
}

void unmark(int x,int y)
{
	ans[x][y] = -1;
	vis[x][y]= false;

	for(int i=0;i<n;i++)
	{
		int dx= x + h[i];
		int dy= y + v[i];

		if(inbounds(dx,dy) && !vis[dx][dy])
			deg[dx][dy]++;	//no of possibilities of dx&dy(increased by 1)after x&y are backtracked...
	}
}

bool solve(int id, int x,int y)
{
	mark(id,x,y);

	if(id>=64) return true;

	vector<array<int,3>> options;

	for(int i=0;i<n;i++)
	{
		int dx= x + h[i];
		int dy= y + v[i];

		if(inbounds(dx,dy) && !vis[dx][dy])
			options.push_back({deg[dx][dy],dx,dy});		//storing possible next steps...
	}

	sort(options.begin(),options.end());

	for(triple T: options)
		if(solve(id+1,T[1],T[2]))
			return true;

	unmark(x,y);

	return false;
}

int main()
{
	init();
	int x,y;

	scanf("%d %d",&x,&y);

	assert(solve(1,y-1,x-1));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d%c",ans[i][j], ("\n")[j==N-1]);
	}
}