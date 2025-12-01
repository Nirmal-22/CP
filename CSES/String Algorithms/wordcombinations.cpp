# include <iostream>
# define int long long
# define mod 1000000007
using namespace std;

string x[100001];
int n;
string s;
int c=0;

void count(int a)
{
	if(a==s.length())
	{
		c=(c%mod+1)%mod;
		return;
	}

	if(a>s.length())
		return;

	for(int i=0;i<n;i++)
	{	
		if(a+x[i].length()-1 <= s.length()-1)
		if(x[i]==s.substr(a,x[i].length()))
		{
			count(a+x[i].length());
		}
	}
}


signed main()
// int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>s;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}

	count(0);

	cout<<c<<endl;

	return 0;
}