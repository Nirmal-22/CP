# include <iostream>
# define int long long
using namespace std;

signed main()
{
	int n; cin>>n;

	int a[10001];

	//int a[10001]; shows wrong answer 

	a[1]=0;
	a[2]=6;
	a[3]=28;
	a[4]=96;

	for(int i=5;i<=n;i++)
	{   
		
	    int x=i*i;
		int tot= (x*(x-1))/2;

		int sub= 8*4 + (i-4)*4*4 + 4*4 + (i-4)*6*4 + (i-4)*(i-4)*8;

		a[i]=(tot - (sub/2));
	}

	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
	return 0;
}








