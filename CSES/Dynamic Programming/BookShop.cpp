#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000;
const int maxX = 1e5;

int N, X, h[maxN], s[maxN], dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)  scanf("%d", &h[i]);		//price
    for(int i = 0; i < N; i++)  scanf("%d", &s[i]);		//number of pages

    fill(dp+1, dp+X+1, -1);
    for(int i = 0; i < N; i++)
        for(int j = X-h[i]; j >= 0; j--)	
        // for(int j=0;j<=X-h[i];j++)		//Wrong
            if(dp[j] != -1)
                dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);

    for(int i = 1; i <= X; i++)
        dp[i] = max(dp[i], dp[i-1]);
    printf("%d\n", dp[X]);
}