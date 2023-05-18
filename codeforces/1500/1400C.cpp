#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
ll maxn = 1e5;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
    
        int n = s.length();
        char w[n];
        for (int i = 0; i < n; i++) w[i] = '1';
    
        bool can = true;
    
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i-x >= 0) w[i-x] = '0';
                if (i+x < n) w[i+x] = '0';
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                bool found = false;
                if (i-x >= 0) if (w[i-x] == '1') found=true;
                if (i+x < n)  if (w[i+x] == '1') found=true;
                if (!found) {can = false; break;}
            }
        }
    
        if (!can) {cout << -1 << endl; continue;}
    
        for (int i = 0; i < n; i++) {
            cout << w[i];
        }
        cout << endl;
    }
    
    
    
    return 0;
}