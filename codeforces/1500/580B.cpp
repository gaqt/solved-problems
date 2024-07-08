// https://codeforces.com/problemset/problem/580/B

#include <iostream>
#include <algorithm>
using namespace std;

typedef int64_t ll;

int main() {
    ll n, d;
    cin >> n >> d;

    pair<ll, ll> f[n];

    for (int i = 0; i < n; i++) {
        ll m, s;
        cin >> m >> s;

        f[i] = make_pair(m, s);
    }

    sort(f, f+n);

    ll l=0, r=1, sums=f[0].second;
    ll maxs = sums;

    while (l <= r && l != n) {
        if (r == n || (f[l].first + d <= f[r].first)) {
            sums -= f[l].second;
            l++;
            continue;
        }

        sums += f[r].second;
        maxs = max(maxs, sums);
        r++;
    }

    cout << maxs << endl;

    return 0;
}
