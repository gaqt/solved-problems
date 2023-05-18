#include <bits/stdc++.h>
using namespace std;
    
#define INF (INT_MAX/4)
    
int n, m, k;
string a, b;
    
int main() {
    
    cin >> n >> m >> k;
    cin >> a >> b;
    
    int dp[n+1][m+1][k+1][2];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int h = 1; h <= k; h++) {
                dp[i][j][h][0] = -INF;
                dp[i][j][h][1] = -INF;
            }
            dp[i][j][0][0] = 0;
            dp[i][j][0][1] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int h = 0; h <= k; h++) {
                dp[i][j][h][0] = max(dp[i-1][j][h][0], dp[i][j-1][h][0]);
                dp[i][j][h][0] = max(dp[i][j][h][0], dp[i-1][j][h][1]);
                dp[i][j][h][0] = max(dp[i][j][h][0], dp[i][j-1][h][1]);
    
                if (a[i-1] == b[j-1] && h > 0) {
                    dp[i][j][h][1] = max(dp[i][j][h][1], dp[i-1][j-1][h][1] +1);
                    dp[i][j][h][1] = max(dp[i][j][h][1], dp[i-1][j-1][h-1][0] +1);
                    dp[i][j][h][1] = max(dp[i][j][h][1], dp[i-1][j-1][h-1][1] +1);
                }
            }
        }
    }
    
    cout << max(dp[n][m][k][0], dp[n][m][k][1]) << endl;
    
    return 0;
}