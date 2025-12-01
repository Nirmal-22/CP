#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int N,k, a, b,p[maxN],sz[maxN];
vector<int> G[maxN];

void dfs(int u = 1){
    sz[u] = 1;
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

int main()
{
    scanf("%d%d", &N,&k);
    for(int i = 0; i < N-1; i++)
    {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    int c=0;
    for(int i=1;i<=(n-1);i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(abs(sz[i]-sz[j])==k)
                c++;
        }
    }

    cout<<c<<endl;

    return 0;
}