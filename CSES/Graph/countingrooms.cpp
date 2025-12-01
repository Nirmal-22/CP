# include <bits/stdc++.h>

using namespace std;

int cnt=0;
bool a[1000][1000];
int x[4]={0,0,1,-1}, y[4]={1,-1,0,0};
int m,n; 


void nullify(int i,int j)
{
	a[i][j] = true;
	for(int z=0;z<4;z++)
	{
		int g=i+x[z],h=j+y[z];

		if(g>=0 && g<m && h>=0 && h<n && !a[g][h])
			nullify(g,h);
	}
}

int main()
{
	cin>>m>>n;

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			char ch; cin>>ch;
			a[i][j] = (ch == '#');
		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!a[i][j])
			{
				nullify(i,j);
				cnt++;
			}
		}
	}


	cout<<cnt<<endl;

}
