#include <bits/stdc++.h>
using namespace std;
    
#define MULTITEST true
    
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
    
struct vtx {
    vector<int> u;
};
    
void solve() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    ll dp[n+1][4][3][2];
    for (int i = 0; i <= n; i++) {
        for (int g = 0; g < 4; g++) {
            for (int b = 0; b < 3; b++) {
                dp[i][g][b][0] = 0;
                dp[i][g][b][1] = 0;
            }
        }
    }
    
    for (int g = 0; g <= 2; g++) {
        for (int b = 0; b <= 1; b++) {
            dp[0][g][b][0] = pow(2, 2-g)*pow(3, 1-b)*h;
        }
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int g = 2; g >= 0; g--) {
            for (int b = 1; b >= 0; b--) {
                dp[i][g][b][0] = max(dp[i-1][g][b][0], dp[i-1][g][b][1]);
                dp[i][g][b][0] = max(2*dp[i][g+1][b][0], dp[i][g][b][0]);
                dp[i][g][b][0] = max(3*dp[i][g][b+1][0], dp[i][g][b][0]);
                if (dp[i][g][b][0] > a[i]) {
                    dp[i][g][b][1] = dp[i][g][b][0] + a[i]/2;
                    cnt = max(cnt, i);
                } else {
                    dp[i][g][b][1] = 0;
                }
            }
        }
    }
    
    
    cout << cnt << endl;
}
    
int main() {
    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while(t--) solve();
    
    return 0;
}