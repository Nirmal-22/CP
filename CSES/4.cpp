# include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin>>t;

	while(t--)
	{
		int a,b; cin>>a>>b;

		int x1,y1; cin>>x1>>y1;
		int x2,y2; cin>>x2>>y2;

		if(a==1 && b==1)
		{
			if(x1==2)
			{
				if(y1!=y2)
				{
					x2=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==2)
			{
				if(y1!=y2)
				{
					x1=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y1==2)
			{
				if(x1!=x2)
				{
					y2=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==2)
			{
				if(x1!=x2)
				{
					y1=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}

		}



		else if(a==8 && b==8)
		{
			if(x1==7)
			{
				if(y1!=y2)
				{
					x2=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==7)
			{
				if(y1!=y2)
				{
					x1=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y1==7)
			{
				if(x1!=x2)
				{
					y2=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==7)
			{
				if(x1!=x2)
				{
					y1=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}



		else if(a==1 && b==8)
		{
			if(x1==2)
			{
				if(y1!=y2)
				{
					x2=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==2)
			{
				if(y1!=y2)
				{
					x1=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y1==7)
			{
				if(x1!=x2)
				{
					y2=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==7)
			{
				if(x1!=x2)
				{
					y1=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}
	
																		/////////////////////////////////////
		else if(a==8 && b==1)
		{
			if(x1==7)
			{
				if(y1!=y2)
				{
					x2=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==7)
			{
				if(y1!=y2)
				{
					x1=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y1==2)
			{
				if(x1!=x2)
				{
					y2=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==2)
			{
				if(x1!=x2)
				{
					y1=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}



		else if(a==1)
		{
			if(x1==2)
			{
				if(y1!=y2)
				{
					x2=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==2)
			{
				if(y1!=y2)
				{
					x1=1;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}



		else if(b==1)
		{
			if(y1==2)
			{
				if(x1!=x2)
				{
					y2=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==2)
			{
				if(x1!=x2)
				{
					y1=1;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}




		else if(a==8)
		{
			if(x1==7)
			{
				if(y1!=y2)
				{
					x2=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(x2==7)
			{
				if(y1!=y2)
				{
					x1=8;
					if(abs(b-y1)>=2 && abs(b-y2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}




		else if(b==8)
		{
			if(y1==7)
			{
				if(x1!=x2)
				{
					y2=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else if(y2==7)
			{
				if(x1!=x2)
				{
					y1=8;
					if(abs(a-x1)>=2 && abs(a-x2)>=2)
						cout<<"YES\n";
					else
						cout<<"NO\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}



		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}