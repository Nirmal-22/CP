# include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin>>t;

	while(t--)
	{
		double x1,y1,x2,y2,x3,y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;

		double m;
        
        int x=0;
        
		if(x1!=x2)
		m= (y2-y1)/(x2-x1);

		else if(x1==x2)
		x=x1;

		double c=y1 - m*x1;
        
        if(x1!=x2)
        {
    	if(y3- m*x3 - c >0 )
    		cout<<"LEFT"<<endl;
    	else if (y3 - m*x3 -c <0)
    		cout<<"RIGHT"<<endl;
    	else
    		cout<<"TOUCH"<<endl;
        }
        
        else
        {
            if(x3>x)
            cout<<"RIGHT"<<endl;
            else if(x3<x)
            cout<<"LEFT"<<endl;
            else
            cout<<"TOUCH"<<endl;
        }
		
	}

	return 0;
}