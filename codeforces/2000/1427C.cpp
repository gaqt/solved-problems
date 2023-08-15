//https://codeforces.com/problemset/problem/1427/C

#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) + abs(y1-y2);
}

int main() {
  int r, n;
  cin >> r >> n;

  int t[n+1], x[n+1], y[n+1];
  t[0] = 0;
  x[0] = 1;
  y[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  int dp[n+1];
  int max_dp[n+1];
  dp[0] = 0;
  max_dp[0] = 0;

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    max_dp[i] = max_dp[i-1];

    if (t[i] >= dist(x[i],y[i], x[0],y[0])) dp[i] = 1;
    else {
      dp[i] = INT_MIN;
      continue;
    }
    int k;
    for (k = i-1; k >= 0 && t[i]-t[k] <= 2*r-2; k--) {
      if (t[i]-t[k] >= dist(x[i],y[i], x[k],y[k])) {
        dp[i] = max(dp[i], dp[k]+1);
      }
    }
    if (k >= 0) dp[i] = max(dp[i], max_dp[k]+1);
    max_dp[i] = max(max_dp[i], dp[i]);

    ans = max(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}