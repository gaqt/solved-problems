#include <bits/stdc++.h>
using namespace std;
    
long long m = 998244353;
    
long long n, k, maxS;
    
void gcd(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return;
    }
    
    long long x_, y_;
    gcd(b%a, a, &x_, &y_);
    *x = y_ - x_*(b/a);
    *y = x_;
}
    
long long modInverse(long long a) {
    long long x, y;
    gcd(a, m, &x, &y);
    
    x = (1 - y*m) / a;
    if (x < 0) {
        return x + m*(1+ abs(x)/m);
    } else {
        return x % m;
    }
}
    
int main() {
    
    cin >> n >> k;
    maxS = n - 1;
    
    long fact[maxS+1];
    fact[0] = 1;
    
    long long ans = 0;
    
    for (long long i = 1; i <= maxS; i++) {
        fact[i] = (fact[i-1] * i) % m;
    }
    
    for (long long i = 1; i <= n/k; i++) {
        long S = n/i - 1;
    
        long long bnc = ( ((long long)fact[S]%m) * (((modInverse(fact[k-1])%m) * (modInverse(fact[S-k+1])%m))%m) ) % m;
    
        ans += bnc;
        ans = ans % m;
    }
    
    printf("%lld", ans);
    
    return 0;
}