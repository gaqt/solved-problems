#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
    
        if (n == 1) {
            if (a[0] == k) {
                cout << "yes";
            } else {
                cout << "no";
            }
            cout << endl;
            continue;
        }
    
        bool possible = false;
        bool has_k = false;
    
        for (int i = 0; i < n; i++) {
            if (a[i] == k) {
                has_k = true;
                break;
            }
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n && j-i <= 2; j++) {
                if (a[i] >= k && a[j] >= k) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }
    
        if (!has_k) possible = false;
    
        if (possible) {
            cout << "yes";
        } else {
            cout << "no";
        }
    
        cout << endl;
    }
    
    return 0;
}