#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5;

struct Edge {int v; ll w; };

struct Node {
    int id; ll dist;
    friend bool operator<(const Node &a, const Node &b){
        return a.dist > b.dist;
    }
};

int N, M, a, b;
ll dist[maxN+1], c;
vector<Edge> G[maxN+1];
priority_queue<Node> Q;
// vector<pair<int,ll>> G[maxN+1];      // not working 0 largenumber largenumber
// queue<pair<int,ll>> Q;
int main(){
  
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %lld", &a, &b, &c);
        G[a].push_back({b, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    Q.push({1, 0});
    while(!Q.empty()){
//         ll d= Q.front().first;
//      int u=Q.front().second;

        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();

        if(d > dist[u]) continue;
        
//      for(pair<int,ll> e : G[u])
        for(Edge e : G[u])
        {
//             if(dist[e.first] > (d+e.second))
//          {
//              dist[e.first] = d+e.second;
//              Q.push({e.first,dist[e.first]});
//          }
            if(dist[e.v] > d+e.w){
                dist[e.v] = d+e.w;
                Q.push({e.v, d+e.w});
            }
        }
    }

    for(int i = 1; i <= N; i++)
        printf("%lld%c", dist[i], (" \n")[i==N]);
}