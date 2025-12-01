# include <iostream>
# define int long long
using namespace std;

signed main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin>>s;

	for(int i=1;i<s.length();i++)
	{
		if(s.substr(0,i) == s.substr(s.length()-i,i))
		{
			cout<<i<<" ";
		}
	}

	return 0;
}