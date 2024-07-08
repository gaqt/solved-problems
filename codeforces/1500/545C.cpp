// https://codeforces.com/problemset/problem/545/C

#include <iostream>
using namespace std;

typedef int64_t ll;
#define INF LONG_MAX

int main() {

    int n;
    cin >> n;

    ll x[n+1], h[n+1], dp[n][3];

    x[n] = INF;
    h[n] = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 1;

    for (int i = 1; i < n; i++) {

        // 0
        dp[i][0] = -INF;
        if (x[i-1] < x[i] - h[i]) {
            dp[i][0] = 1 + max(dp[i-1][0],
                               dp[i-1][1]);
        }
        if (x[i-1] + h[i-1] < x[i] - h[i]) {
            dp[i][0] = max(dp[i][0], 1+dp[i-1][2]);
        }

        // 1
        dp[i][1] = max(dp[i-1][0],
                       dp[i-1][1]);
        if (x[i-1] + h[i-1] < x[i]) {
            dp[i][1] = max(dp[i][1], dp[i-1][2]);
        }

        // 2
        dp[i][2] = 1 + dp[i][1];

    }

    ll res = max(dp[n-1][0], max(
                 dp[n-1][1],
                 dp[n-1][2]));

    cout << res << endl;

    return 0;
}

/*
x[i] = pos of ith tree
h[i] = height of ith tree

f(i, h) = max falls at ith tree where
    h = 0 -> tree falls to the left
    h = 1 -> tree stays in place
    h = 2 -> tree falls to the right

f(i, h) = -INFINITY if not possible

f(i, 0) = 1 + max( f(i-1, 0)  if x[i-1] < x[i] - h[i],
                   f(i-1, 1)  if x[i-1] < x[i] - h[i],
                   f(i-1, 2)  if x[i-1] + h[i-1] < x[i] - h[i] )

f(i, 1) = max( f(i-1, 0),
               f(i-1, 1),
               f(i-1, 2)  if x[i-1] + h[i-1] < x[i] )

f(i, 2) = 1 + f(i, 1)

*/
