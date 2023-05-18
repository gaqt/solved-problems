#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int n, m;
    cin >> n >> m;
    
    if (!((m+1)/2-1 <= n && n <= m+1)) cout << -1 << endl;
    else {
        if (n < (m+1)/2+1) {
            while (n != 0 || m != 0) {
                if (m > 0) {cout << 1; m--;}
                if (m > 0) {cout << 1; m--;}
                if (n > 0) {cout << 0; n--;}
            }
        } else {
            while (n != 0 || m != 0) {
                if (n > 0) {cout << 0; n--;}
                if (m > 0) {cout << 1; m--;}
                if (m > 0 && n < m) {cout << 1; m--;}
            }
        }
    }
    
    
    return 0;
}