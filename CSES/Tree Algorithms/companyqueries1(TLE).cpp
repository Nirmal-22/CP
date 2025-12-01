# include <iostream>
// # define int long long
# define endl "\n"
using namespace std;

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	
	int n,q; cin>>n>>q;

	int a[n+1];

	a[1]=0;

	for(int i=2;i<=n;i++)
		cin>>a[i];

	while(q--)
	{
		int e,c; cin>>e>>c;

		while(c--)
		{
			int x=a[e];

			if(x==0)
			{
				cout<<-1<<endl;
				break;
			}
			if(c==0)
				cout<<x<<endl;

			e=x;
		}
			
	}

	return 0;
}