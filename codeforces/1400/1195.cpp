#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int n;
    cin >> n;
    
    uint64_t h1[n+1], h2[n+1];
    h1[0]=0;
    h2[0]=0;
    
    for (int i = 1; i <= n; i++) cin >> h1[i];
    for (int i = 1; i <= n; i++) cin >> h2[i];
    
    uint64_t dp[n+1][3];
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = h1[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = h2[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    
    return 0;
}