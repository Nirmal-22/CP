int Solution::seats(string s) 
{
    int mod=10000003;
    int n=s.length();
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='x')
			v.push_back(i);
	}
    
    if(v.size()==0)
    return 0;
    
	int mi=v[(int)(v.size()/2)];

	int c=0,sum=0;
	for(int i=mi+1;i<s.length();i++)
	{
		if(s[i]=='.')
			c=(c+1)%mod;
		else 
			sum=(sum%mod+c%mod)%mod;
	}

	c=0;

	for(int i=mi-1;i>=0;i--)
	{
		if(s[i]=='.')
			c=(c+1)%mod;
		else 
			sum=(sum%mod+c%mod)%mod;
	}

	return sum;
}
