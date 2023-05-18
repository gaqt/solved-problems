#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    long long sum[n+1];
    sum[0] = 0;
 
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
 
 
    deque<vector<vector<long long> > > dp;
 
    vector<vector<long long> > defV;
    vector<long long> defD;
 
    defV.push_back(defD);
    defV.push_back(defD);
 
    int add = 0;
 
    for (int i = 0; i <= n; i++) {
        dp.push_back(defV);
        for (int j = 0; j <= k; j++) {
            dp[i+add][0].push_back(0);
            dp[i+add][1].push_back(0);
            if (i < m || j == 0) {
                dp[i+add][0][j] = 0;
                dp[i+add][1][j] = 0;
            } else {
                dp[i+add][0][j] = max(dp[i+add-1][0][j], dp[i+add-1][1][j]);
                if (j == 1 || dp[i+add-m+1][0][j-1] > 0)
                    dp[i+add][1][j] = (sum[i] - sum[i-m]) + dp[i+add-m+1][0][j-1];
                else dp[i+add][1][j] = 0;
            }
 
        }
        if (i >= m+15) {
            dp.pop_front();
            add--;
        }
    }
 
    cout << max(dp[n+add][0][k], dp[n+add][1][k]) << endl;

    return 0;
}