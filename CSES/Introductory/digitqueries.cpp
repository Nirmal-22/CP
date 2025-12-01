# include <iostream>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n;

		int a=9;
		int i;
		for(i=0;i<=17;i++)
		{
			if(n>a*(i+1))
			{
				n=n-a*(i+1);
				a=a*10;
			}
			else
			{
				break;
			}
		}

		int x=n/(i+1);
		int y=n%(i+1);

		int z;

		if(y==0)
		z=a/9+x-1;
		else
		z=a/9+x;

		string s= to_string(z);

		if(y!=0)
		cout<<s[y-1]<<endl;
		else
		cout<<x%10<<endl;
	}
	return 0;
}