#include <bits/stdc++.h>
using namespace std;
    
int main() {
    long long n;
    
    cin >> n;
    
    long long s[n];
    
    for (long long i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        s[i] -= tmp;
    }
    
    sort(s, s+n);
    
    //for (long long i = 0; i < n; i++) cout << s[i] << " ";
    
    long long p = 0, res = 0;
    
    while (p < n-1) {
        long long low = p+1, high = n-1, mid = (low+high)/2;
        
        while (low+1 < high) {
            if (s[mid] + s[p] > 0) {
                high = mid;
                mid = (low+high)/2;
            } else if (s[mid] + s[p] == 0) {
                break;
            } else {
                low = mid;
                mid = (low+high)/2;
            }
        }
    
        if (s[mid] + s[p] > 0) {
            while (mid > p && s[mid] + s[p] > 0) mid--;
            mid++;
            res += n - mid;
        } else {
            while (mid < n && s[mid] + s[p] <= 0) mid++;
            res += n - mid;
        }
    
        p++;
    
    }
    
    cout << res;
    
    return 0;
}