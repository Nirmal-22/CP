# include <iostream>
using namespace std;

int main()
{
	string s; cin>>s;

	string sstr; cin>>sstr;

	int l=sstr.length();

	int c=0;

	

	for(int i=0;i< (s.length()-l+1);i++)
	{
		if(sstr==s.substr(i,l))
			c++;

		i=i+l-1;	
	}

	cout<<c<<endl;

	return 0;
}