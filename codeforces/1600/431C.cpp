#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 112
long long MOD = pow(10,9)+7;
    
int main() {
    int n, k, d;
    
    cin >> n >> k >> d;
    
    long long dp[MAXN][2];
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int h = 1; h < d && h <= i; h++) {
            dp[i][0] += dp[i-h][0];
            while(dp[i][0] >= MOD) dp[i][0] -= MOD;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 0;
        for (int h = 1; h <= k && h <= i; h++) {
            dp[i][1] += dp[i-h][1];
            while(dp[i][1] >= MOD) dp[i][1] -= MOD;
            if (i >= d && h >= d) dp[i][1] += dp[i-h][0];
            while(dp[i][1] >= MOD) dp[i][1] -= MOD;
        }
    }
    
    cout << dp[n][1];
    
    return 0;
}