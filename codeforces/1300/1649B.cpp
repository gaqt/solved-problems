#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll v[n];
        for (int i = 0; i < n; i++) cin >> v[i];
    
        sort(v, v+n);
        ll sum = 0;
        for (int i = 0; i < n-1; i++) sum += v[i];
    
        if (v[n-1] == 0) cout << 0 << endl;
        else cout << max((ll)1, v[n-1] - sum) << endl;
    }
    
    
    
    return 0;
}