# include <bits/stdc++.h>
using namespace std;

int n,m;
char a[1000][1000];										///
int x[4]={0,0,1,-1},y[4]={1,-1,0,0};
string store="";

void search(int i,int j,string str)						///String incorrect string correct
{
	
	string s=str;
	for(int z=0;z<4;z++)
	{
		int g=i+ x[z], h=j+ y[z];

		if(z==0)
			s= s+ "R";					/// matrix positioning row and column
		else if(z==1)
			s= s+ "L";
		else if(z==2)
			s= s+ "D";
		else
			s= s+ "U";

		if(g>=0 && g<n && h>=0 && h<m)
			if(a[g][h]=='B')
			{
				store=s;
				return;
			}

		if(g>=0 && g<n && h>=0 && h<m)
			if(a[g][h]=='.')
				search(g,h,s);

		if(store!="")
			return;
	}
}


int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char x;cin>>x;
			a[i][j] = x;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!(a[i][j]=='#') && a[i][j]=='A')
				search(i,j,"");
		}
	}

	if(store!="")
	{
		cout<<"YES"<<endl;
		cout<<store.length()<<endl;
		cout<<store<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

}