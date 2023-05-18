#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 72
    
#define INF (INT_MAX/4)
    
int n, m, k;
    
int dp[MAXN][MAXN][MAXN/2][MAXN];
    
int modulo(int a, int mod) {
    a = a%mod;
    if (a < 0) a += mod;
    return a;
}
    
int main() {
    
    cin >> n >> m >> k;
    
    int v[n+1][m+1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= m/2; p++) {
                for (int d = 0; d < k; d++) {
                    dp[i][j][p][d] = -INF;
                }
            }
        }
    }
    
    for (int j = 0; j <= m; j++) {
        for (int p = 0; p <= m/2; p++) {
            dp[0][j][p][0] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= m/2 && p <= j; p++) {
                for (int d = 0; d < k; d++) {
                    if (j == 0) {
                        for (int _p = 0; _p <= m/2; _p++) {
                            dp[i][j][p][d] = max(dp[i][j][p][d], dp[i-1][m][_p][d]);
                        }
                    } else {
                        dp[i][j][p][d] = dp[i][j-1][p][d];
                        if (p > 0) {
                            dp[i][j][p][d] = max(dp[i][j][p][d], dp[i][j-1][p-1][modulo(d-v[i][j],k)] + v[i][j]);
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    
    for (int p = 0; p <= m/2; p++) {
        ans = max(ans, dp[n][m][p][0]);
    }
    
    cout << ans << endl << endl;
    
    return 0;
}