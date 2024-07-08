// https://codeforces.com/problemset/problem/1338/A

#include <iostream>
#include <math.h>
using namespace std;

typedef int64_t ll;

inline void solve() {
    ll n;
    cin >> n;
    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll x = 0, maxprev = a[0];

    for (int i = 1; i < n; i++) {
        ll diff = maxprev - a[i];
        maxprev = max(maxprev, a[i]);
        if (diff <= 0) continue;

        x = max(x, 1+(ll)log2l(diff));
    }

    cout << x << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
