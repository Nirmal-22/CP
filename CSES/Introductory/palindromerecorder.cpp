# include <iostream>
# define int long long
using namespace std;

int count[26]={0};

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	string s; cin>>s;

	for(int i=0;i<s.length();i++)
	{
		count[s[i]-65]++;
	}

	// for(int i=0;i<26;i++)
	// 	cout<<count[i]<<endl;
 
	int c=0;
	int p=-1;

	for(int i=0;i<26;i++)
	{
		if(count[i]%2!=0)
		{
			c++;
			p=i;
		}
	}


	// cout<<c<<endl;
	// cout<<p<<endl;

	if(c>1)
	cout<<"NO SOLUTION"<<endl;
	else
	{
		for(int i=0;i<26;i++)
		{	
			if(i!=p)
			// for(int j=1;j<=count[s[i]]/2;j++)
			for(int j=1;j<=count[i]/2;j++)
			{
				cout<<char('A'+i);
			}
		}

	
		if(p!=-1)
		for(int i=1;i<=count[p];i++)
			cout<<char('A'+p);

		for(int i=0;i<26;i++)
		{	
			if((25-i)!=p)
			for(int j=1;j<=count[25-i]/2;j++)
			{
				cout<<char('Z'-i);
			}
		}
		
		// for(int i=25;i>=0;i++)			
		// {
		// 	if(i!=p)
		// 	for(int j=1;j<=count[i]/2;j++)
		// 	{
		// 		cout<<char('A'+i);
		// 	}
		// }
	}

	return 0;
}