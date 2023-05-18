#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return max(a, b);
    else return gcd(b%a, a);
}
    
ll get(ll bin, int i) {
    return (bin>>i)&1;
}
    
    
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
    
        int v[n];
        int h[31];
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < 31; i++) h[i] = 0;
    
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 31; j++) {
                h[j] += get(v[i], j);
            }
        }
    
        int k = gcd(h[0], h[1]);
    
        for (int i = 2; i < 31; i++) k = gcd(k, h[i]);
    
        if (k == 0) {
            for (int i = 1; i <= n; i++) cout << i << " ";
        } else {
            for (int i = 1; i <= k/2; i++) if (k%i == 0) cout << i << " ";
            cout << k;
            cout << endl;
        }
    }
    
    return 0;
}