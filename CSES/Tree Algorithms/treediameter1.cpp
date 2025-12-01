# include <iostream>
using namespace std;

int main()
{
	int n; cin>>n;

	for(int i=0;i<n-1;i++)
	{
		int x,y; cin>>x>>y;

		a[x].push_back(y);
		a[y].push_back(x);
	}

	
}