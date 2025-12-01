# include <iostream>
using namespace std;

# define int long long

# define mod 1000000007
signed main()
{
	int n; cin>>n;

	int ans=1;
	while(n--)
	{
		ans = (ans*2)%mod;
	}

	cout<<ans<<endl;

	return 0;
}