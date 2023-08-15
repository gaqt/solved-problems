#include <iostream>
#include <limits.h>
using namespace std;

const int MAXN = 5123;
int n;
int c[MAXN];
int dp[MAXN][MAXN][2];

int solve(int i, int j, int d) {
  if (dp[i][j][d] != -1) return dp[i][j][d];
  if (i >= j) {
    dp[i][j][d] = 0;
    return dp[i][j][d];
  }

  int arg_min = INT_MAX;

  if (d == 0) {
    if (c[i] == c[i+1]) arg_min = min(arg_min, solve(i+1, j, 0));
    else                arg_min = min(arg_min, solve(i+1, j, 0)+1);

    if (c[i] == c[j]) arg_min = min(arg_min, solve(i+1, j, 1));
    else                arg_min = min(arg_min, solve(i+1, j, 1)+1);
  } else {
    if (c[j] == c[j-1]) arg_min = min(arg_min, solve(i, j-1, 1));
    else                arg_min = min(arg_min, solve(i, j-1, 1)+1);

    if (c[j] == c[i]) arg_min = min(arg_min, solve(i, j-1, 0));
    else                arg_min = min(arg_min, solve(i, j-1, 0)+1);
  }

  dp[i][j][d] = arg_min;
  return dp[i][j][d];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j][0] = -1;
      dp[i][j][1] = -1;
    }
  }

  cout << min(solve(1,n,0), solve(1,n,1)) << endl;

  return 0;
}