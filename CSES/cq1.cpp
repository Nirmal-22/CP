#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;
const int logK = 18;

int N, Q, x, k, p[maxN][logK];

int main()
{
    scanf("%d %d", &N, &Q);

    for(int i = 2; i <= N; i++)
        scanf("%d", &p[i][0]);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j < logK; j++)
            {
                // cout<<p[i][j-1]<<" "<<p[p[i][j-1]][j-1]<<endl;

                p[i][j] = p [p[i][j-1]] [j-1];
            }  ///

    // for(int i = 0; i <= N; i++)
    // {
    //     for(int j = 0; j < logK; j++)
    //     {
    //         cout<<p[i][j]<<" ";   
    //     }
    //     cout<<endl;
    // }

    for(int q = 0; q < Q; q++)
    {
        scanf("%d %d", &x, &k);

        for(int i = 0; i < logK; i++)
            if(k & (1<<i))
            {                  ///
                // cout<<x<<" ";
                x = p[x][i];
            }

        printf("%d\n", x ? x : -1);
    }
}