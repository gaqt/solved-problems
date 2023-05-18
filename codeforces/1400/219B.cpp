#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
int main() {
    
    ll p, d;
    
    cin >> p >> d;
    
    ll k = p;
    ll res = p;
    
    ll cnt1=0, cnt2=0;
    bool b1=true, b2=true;
    
    for (ll i = 1; i <= p/10; i *= 10) {
        if (((p/i)%10) == 9) cnt2++;
        else break;
    }
    
    for (ll i = 1; i <= p/10; i *= 10) {
        k -= i*((k/i)%10);
        k -= 10*i;
        k += i*9;
    
    
        if (p - k <= d && b2) {
            ll j = 0;
            for (ll i = 1; i <= p/10; i *= 10) {
                if (((k/i)%10) == 9) j++;
                else break;
            }
            if (j > cnt1) {
                cnt1 = j;
                res = k;
            }
        }
        else b2 = false;
    }
    
    
    
    if (cnt2 >= cnt1) cout << p << endl;
    else cout << res << endl;
    
    return 0;
}