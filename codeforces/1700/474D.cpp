#include <bits/stdc++.h>
using namespace std;
    
long MOD = pow(10, 9) + 7;
    
    
int main() {
    
    int t, k;
    cin >> t >> k;
    
    int a[t];
    int b[t];
    
    int maxB = 0;
    
    for (int i = 0; i < t; i++) {
        cin >> a[i] >> b[i];
        maxB = max(maxB, b[i]);
    }
    
    int dp[maxB+1];
    dp[0] = 1;
    
    int sum[maxB+1];
    sum[0] = 1;
    
    for (int i = 1; i <= maxB; i++) {
        dp[i] = dp[i-1];
        dp[i] = dp[i] % MOD;
        if (k <= i) {
            dp[i] += dp[i-k];
            dp[i] = dp[i] % MOD;
        }
    
        sum[i] = sum[i-1] + dp[i];
        sum[i] = sum[i] % MOD;
    }
    
    for (int i = 0; i < t; i++) {
        int ans = sum[b[i]] - sum[a[i]-1];
        if (ans < 0) ans += MOD;
        cout << ans << endl;
    }
    
    return 0;
}