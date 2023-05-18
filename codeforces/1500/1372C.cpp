#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
ll maxn = 1e5;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll v[n];
        for (int i = 0; i < n; i++) cin >> v[i];
    
        int l = 0, r = n-1;
        while (l < r) {
            if (v[l] == l+1) l++;
            else if (v[r] == r+1) r--;
            else break;
        }
    
        int cnt = 0;
        for (int i = l; i <= r; i++) if (v[i] == i+1) cnt++;
    
        if (cnt == r-l+1) cout << 0 << endl;
        else if (cnt == 0) cout << 1 << endl;
        else cout << 2 << endl;
    }
    
    
    
    return 0;
}