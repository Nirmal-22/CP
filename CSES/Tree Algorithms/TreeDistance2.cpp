#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> v[N];

int dep[N],ans[N];
int sum=0;


void dfs(int s,int p)
{
    for(int &j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            sum=sum+dep[j];
            dfs(j,s);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    
    for(int z=1;z<=n;z++)
    {
        dep[z]=0;
        dfs(z,0);

        cout<<sum<<" ";
        sum=0;
        // int s=0;
        // for(int i=1;i<=n;i++)
        // {
        //     if(i!=z)
        //         s=s+dep[i];
        // }

        // cout<<s<<" ";

    }
}   