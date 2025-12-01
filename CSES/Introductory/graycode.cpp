# include <iostream>
# include <vector>
using namespace std;

int main()
{
	int n; cin>>n;

	int x=1<<n;			// better way to get 2 power n


	// for(int i=1;i<=n;i++)		/////////
	// {
	// 	x=x<<1;
	// }
	// x=x>>1;

	vector<int>current;
		/*
		0 1 2 3 4 5 6 7 -- in range(0,2^n-1) 
		0 1 3 2 6 7 5 4 - required answer order(now observe difference with xor
		--------------------------------------------------
		0 0 1 1 2 2 3 3  - thats y we are dividing with 2^i
		*/
        for(int i=0;i<(1<<n);i++)
        {
            current.push_back(i ^ i>>1);
        }
        
        for(int z:current)
        {
        	// cout<<x<<endl;
        	for(int i=x;i>0;i=i>>1)
        	{	
        		cout<<1:0?z/i;			/////////
        		z=z-i;
        	}

        	cout<<endl;
        }

        return 0;
}