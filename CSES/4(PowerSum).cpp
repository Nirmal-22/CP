# include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n;
		int a[n];

		for(int i=0;i<n;i++)
			cin>>a[i];

		sort(a,a+n);

		int x=a[0],s[n]={0};
		s[0]=a[0];

		for(int i=1;i<n;i++)
		{
			s[i]=s[i-1]+a[i];

			if(s[i] && (!(s[i]&(s[i]-1))))
				z=i;

			if(x!=a[i])
			{
				if(z==i||z==(i-1))
				{
					
					x=a[i];
					continue;
				}

				int y;
				if( y= s[i-1]/((i-z-1)*x) )		//two possiblities
				{

				}
				else
				{
					//multiply individually
				}

				

				// int q=s[i-1];
				// if(q && (!(q&(q-1))))
				// {

				// }
			}
		}
	}

	return 0;
}