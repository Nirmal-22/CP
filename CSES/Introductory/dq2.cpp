// # include <iostream>
# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n;

		int x=9;
		if(x<n)
		{
			n-=x;
			x*=10;
		}

		x/=9;

		int p=0;
		int z=x;

		while(z>0)
		{
			z/=10;
			p++;
		}

		p++;

		if(n%p==0)
		{
			cout<<((n/p)-1)%10<<endl;
		}
		else
		{  
		    // string s=to_string(x+(n/p));
			cout<<to_string(x+(n/p))[n%p]<<endl;
		}

	}

	return 0;
}