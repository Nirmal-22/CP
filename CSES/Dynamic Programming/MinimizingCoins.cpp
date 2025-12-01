#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;
const int INF = 0x3f3f3f3f;

int N, X, c, dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    fill(dp+1, dp+X+1, INF);
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X-c; j++)
            if(dp[j] != INF)
                dp[j+c] = min(dp[j+c], dp[j]+1);
    }
    printf("%d\n", dp[X] == INF ? -1 : dp[X]);
}





// 1   1
// 2   1+1
// 3   1+1+1
// 4   1+1+1+1
// 5   5
// 6   5+1
// 7   7
// 8   7+1+1
// 9   7+1+1
// 10  5+5
// 11  5+5+1