#include <bits/stdc++.h>
using namespace std;

string s[50000];
int i=0;

void permute(string str)
{
	sort(str.begin(), str.end());

	do 
	{
	// cout << str << endl;
		s[i]=str;
		i++;
	} while (next_permutation(str.begin(), str.end()));
}

int main()
{		
	string str; cin>>str;
	permute(str);

	cout<<i<<endl;
	for(int j=0;j<i;j++)
		cout<<s[j]<<endl;

	return 0;
}
