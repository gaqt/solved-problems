#include <bits/stdc++.h>
using namespace std;
    
#define ll long long
    
int main() {
    
    ll l, r;
    cin >> l >> r;
    
    ll n = 0;
    
    for (int i = 62; i >= 0; i--) {
        if (((l^r)>>i)&1 == 1) {
            n += pow(2,i);
        } else {
            if (((ll)(r^(ll)pow(2,i)) >= l && (ll)(r^(ll)pow(2,i)) <= r) ||
                ((ll)(l^(ll)pow(2,i)) >= l && (ll)(l^(ll)pow(2,i)) <= r)) {
    
                n += pow(2,i);
            }
        }
    }
    
    printf("%I64d\n", n);
    
    return 0;
}