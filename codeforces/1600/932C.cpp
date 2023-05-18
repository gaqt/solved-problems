#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N, A, B;
    
    cin >> N >> A >> B;
    
    int dp[N+1][2];
    
    for (int i = 1; i <= N; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for (int i = 1; i <= N; i++) {
        if (i >= A && (dp[i-A][0] != -1 || dp[i-A][1] != -1)) {
            dp[i][0] = dp[i-A][0] + 1;
            dp[i][1] = dp[i-A][1];
        } else if (i >= B && (dp[i-B][0] != -1 || dp[i-B][1] != -1)) {
            dp[i][0] = dp[i-B][0];
            dp[i][1] = dp[i-B][1] + 1;
        }
    }
    
    if (dp[N][0] == -1) {
        cout << -1;
        return 0;
    }
    
    int x = 1;
    
    while (dp[N][0] + dp[N][1] > 0) {
        if (dp[N][0] > 0) {
            int xi = x;
            
            while (x - xi < A-1) {
                x++;
                cout << x << " ";
            }
            x++;
            cout << xi << " ";
            
            dp[N][0]--;
        }
    
        if (dp[N][1] > 0) {
            int xi = x;
            
            while (x - xi < B-1) {
                x++;
                cout << x << " ";
            }
            x++;
            cout << xi << " ";
    
            dp[N][1]--;
        }
    }
    
    return 0;
}