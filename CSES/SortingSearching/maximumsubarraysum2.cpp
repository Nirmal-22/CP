# include <iostream>
using namespace std;

int main()
{
	int n,a,b; cin>>n>>a>>b;

	int arr[n]; 
	for(int i=0;i<n;i++)	cin>>arr[i];

	int max=0,s=0;
	for(int i=a;i<b;i++)
	{
		s = s + arr[i];
		c++;

		if((s>max) && (c>=a && c<=b))
		max=s;

		if(s<0)
			s=0;
	}

	cout<<max<<endl;

	return 0;
}