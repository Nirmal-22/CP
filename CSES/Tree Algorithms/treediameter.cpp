#include <iostream>
#include <vector>
# include <algorithm>
using namespace std;

vector<int> a[200005];      //2e5 double

// int a[200000];
int maxa[200005]={0};

int maxm=0;

void dfs(int u,int l,int par)
{
    for(int x:a[u])
    {
        if(x!=par)
            dfs(x,l+1,u);
            
    }
    

    maxa[u]=l;
    
    if(maxa[u]>maxm)
        maxm=maxa[u];
    
}

int main() 
{
    int n; cin>>n;
    
    for(int i=1;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    vector<int> v;

    for(int x:a[1])
    {
        dfs(x,1,1);

        // cout<<maxm<<endl;

        v.push_back(maxm);
        maxm = 0;
    }

    
    sort(v.begin(),v.begin()+v.size());

    cout<<v[v.size()-1] + v[v.size()-2]<<endl;

    // dfs(1,0,0);

    
    // int p=0,q=0; 
    // for(int i=1;i<=n;i++)
    // {
    //     if(maxa[i]>p)
    //     {
    //         p=maxa[i];
    //         q=i;
    //     }        
    // }
    
    // // cout<<q<<endl; //4
    // // cout<<p<<endl; //2

    // maxa[q]=0;
    // q=0;
    
    // for(int i=1;i<=n;i++)
    // {
    //     if(maxa[i]>q)
    //     {
    //         q=maxa[i];
    //         p=i;
    //     }        
    // }
    
    // cout<<p<<endl; //5
    // cout<<q<<endl; //2

    // cout<<p+q<<endl;
    return 0;
}