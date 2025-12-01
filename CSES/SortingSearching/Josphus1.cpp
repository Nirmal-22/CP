# include <iostream>
# include <vector>
using namespace std;

int c=1,flag=0;

int remove(vector<int> v,int j)
{

	if(v.size()==1)
		return v[0];

	for(unsigned int i=j;i<v.size();i++)
	{
		if(c%2==0)
		{
			if(flag == 1) cout<<v[i]<<" ";
			// v.pop_back(v[i]);    wrong syntax
			v.erase(v.begin() + i);

		}
		c++;
	}

	return remove(v,0);
}


int main()
{
	int n; cin>>n;

	vector<int> v;

	for(int i=0;i<n;i++)
		v[i]=i+1;

		vector<int> z=v;
	int a = remove(v,0);

	int dif = n-a;
	flag=1,c=1;

	cout<<remove(z,dif)<<endl;

	return 0;
}