#include <bits/stdc++.h>
using namespace std;
    
int main() {
    long long x,k,n,A,B,ans=0;
    
    cin >> n >> k >> A >> B;
    
    x = n;
    
    if (k == 1) {
        cout << A*(x-1);
        return 0;
    }
    
    while (x != 1) {
        long long j;
    
        if (x % k != 0) {
            j = x % k;
            ans += A * j;
            x -= j;
        }
    
        if (x < 1) {
            ans -= A;
            break;
        }
    
        if (x == 1) break;
    
        j = x - x/k;
    
        ans += min(A*j, B);
        x -= j;
    }
    
    cout << ans;
    
    return 0;
}