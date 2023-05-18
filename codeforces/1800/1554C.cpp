#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        long n, m;
        cin >> n >> m;
    
        if (m < n) {
            cout << 0 << endl;
            continue;
        }
    
        long l = 0, r = round(pow(2, floor(log2(m+1))+1)) -1, mid=(l+r)/2;
        long x = m+1;
    
        for (long i = floor(log2(m+1)); i >= 0; i--) {
            if ((n>>i)&1) {
                if (x > mid) x -= (r-mid);
                else x = l;
                r = mid;
            } else {
                if (x <= mid) r = mid;
                else l = mid+1;
            }
    
            mid = (l+r)/2;
        }
    
        cout << x << endl;
    }
    
    return 0;
}