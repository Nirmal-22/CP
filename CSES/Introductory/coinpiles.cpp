# include <iostream>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int x,y; cin>>x>>y;

		if(x!=y)
		{
			int dif=abs(x-y);

			if(x>y)
			{
				x=x-dif*2;
				y=y-dif;
			}
			else
			{
				y=y-dif*2;
				x=x-dif;
			}
		}

		if(x%3==0 && x>=0 && y>=0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

	return 0;
}