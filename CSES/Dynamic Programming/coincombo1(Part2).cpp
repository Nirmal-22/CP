# include <iostream>
# include <algorithm>
# include <vector>
# define int long long
using namespace std;

const int N=1000007;
int dp[N];
int c=0;

void minimum(int s,vector<int> v,int x)
{   

    if(dp[s]!=0)
        return;
        //return dp[s];

    if(s==x)
    {
        //c++;
        //dp[s]=c;

        dp[s]++;
        return;
    }

    for(int i=0;i<v.size();i++)
    {
        s= s + v[i];

        if(s<=x)
        minimum(s,v,x);

        s= s- v[i];

        dp[s] =dp[s] + dp[s+v[i]];
    }
}
 

 
signed main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n,x;
    cin>>n>>x;
 
    vector<int> v;
 
    while(n--)
    {
        int a; cin>>a;
 
        v.push_back(a);
    }
 
    sort(v.begin(),v.end(),greater<int>());
 
    minimum(0,v,x);
 
    //cout<<c<<endl;

    cout<<dp[0]<<endl;

    return 0;
}