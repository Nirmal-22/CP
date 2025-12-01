// 1

// 1+1
// 2+0

// 1+2
// 2+1
// 3+0

// 1+3
// 2+2
// 3+1
// 4+0

// 1+4
// 2+3
// 3+2
// 4+1
// 5+0

// 1+5
// 2+4
// 3+3
// 4+2
// 5+1
// 6+0

// 1+6
// 2+5
// 3+4
// 4+3
// 5+2
// 6+1

// 1+7
// 2+6
// 3+5
// 4+4
// 5+3
// 6+2

#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;
const int MOD = 1e9+7;

int N, dp[maxN+1];

int main(){
    scanf("%d", &N);

    dp[0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= 6 && i-j >= 0; j++)
            dp[i] = (dp[i] + dp[i-j]) % MOD;

    printf("%d\n", dp[N]);
}