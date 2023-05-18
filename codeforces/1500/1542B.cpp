#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, a, b;
        cin >> n >> a >> b;
    
        if (b == 1) cout << "Yes" << endl;
        else if (a == 1) {
            if (n%b == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else {
            ll h = 1;
            bool g = false;
            while (h <= n) {
                if (h%b == n%b) {g = true; break;}
                h *= a;
            }
            if (g) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    
    
    return 0;
}