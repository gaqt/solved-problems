//https://codeforces.com/problemset/problem/607/B

#include <bits/stdc++.h>
using namespace std;

#define MAXN 512

int n;

int dp[MAXN][MAXN];
int a[MAXN];

int get_min_steps(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i > j) {
        dp[i][j] = 0;
        return 0;
    }

    if (i == j) {
        dp[i][j] = 1;
        return 1;
    }

    int result = INT_MAX;
    result = min(result, 1 + get_min_steps(i+1, j));
    for (int k = j; k > i+1; k--) {
        if (a[i] != a[k]) continue;
        result = min(result, get_min_steps(i+1, k-1) + get_min_steps(k+1, j));
    }
    if (a[i] == a[i+1]) result = min(result, 1 + get_min_steps(i+2, j));

    dp[i][j] = result;

    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dp[i][j] = -1;

    cout << get_min_steps(0, n-1);

    return 0;
}