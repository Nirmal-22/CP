#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> v[N];

int dep[N],ans[N];

/*  
    The maximum distance of a node to any other node always occur at one of the endpoints of the diameter.

    Here , our approach would be to find two endpoints of diameter and record the maximum of the two distances
    from then for every node in the graph.

    There is a general algorithm for finding the diameter of the tree using only two depth first searches 
    
    For more details refer to : 
        https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
*/


void dfs(int s,int p)
{
    for(int &j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
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
    // dfs(1,0);

                                // for(int i=1;i<=n;++i)
                                // {
                                //     cout<<dep[i]<<" ";
                                // }
                                // cout<<endl;

    // finding the first endpoint

    for(int z=1;z<=n;z++)
    {
        dep[z]=0;
        dfs(z,0);

        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(i!=z)
                s=s+dep[i];
        }

        cout<<s<<" ";

    }
    int u = -1, dis = -1;
    for(int i=1;i<=n;++i)
    {
        if(dep[i]>dis)
            dis = dep[i] , u = i;
    }

    // call dfs on one endpoint
    dep[u] = 0;
    dfs(u,0);

    int v = -1; // second endpoint
    dis = -1;
    // for distances from one endpoint of diameter
    for(int i=1;i<=n;++i)
    {
        if(dep[i] > dis)
            dis = dep[i] , v = i;

        ans[i] = max(ans[i] , dep[i]);
    }

    for(int i=1;i<=n;++i)
    {
        ans[i] = max(ans[i] , dep[i]);

                                // cout << ans[i]<<"--"<<dep[i]<<"  ";
    }
    // cout<<endl;

    dep[v] = 0;
    dfs(v,0);

    // record for second endpoint
    // 
    for(int i=1;i<=n;++i)
    {
        ans[i] = max(ans[i] , dep[i]);

                                // cout << ans[i]<<"--"<<dep[i]<<"  ";
        cout<<ans[i]<<" ";
    }
}   