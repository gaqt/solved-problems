#include <bits/stdc++.h>
using namespace std;
    
long n, m;
    
int main() {
    
    cin >> n >> m;
    
    long dp[n+2];
    long sum[n+2];
    
    dp[n] = 1;
    dp[n+1] = 0;
    sum[n] = 1;
    sum[n+1] = 0;
    
    for (int i = n-1; i >= 1; i--) {
        dp[i] = sum[i+1];
        for (long j = 2; i*j <= n; j++) {
            dp[i] += (sum[i*j] - sum[min(i*j + j, n+1)]) % m;
            dp[i] = dp[i] % m;
        }
        sum[i] = (sum[i+1] + dp[i]) % m;
    }
    
    cout << dp[1] << endl;
    
    return 0;
}