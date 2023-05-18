#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, c;
        cin >> n >> c;
    
        int cnt[2*c];
        for (int i = 0; i <= 2*c; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {int h; cin >> h; cnt[h]++;}
    
        int pre[2*c];
        pre[0] = 0;
        for (int i = 1; i <= 2*c; i++) pre[i] = pre[i-1] + cnt[i];
    
        bool b = true;
    
        for (int y = 1; y <= c; y++) {
            if (cnt[y] == 0) continue;
            for (int h = 1; h*y <= c; h++) {
                if (cnt[h] != 0) continue;
                if (pre[y*(h+1)-1] - pre[y*h-1] > 0) {
                    b = false;
                    break;
                }
            }
            if (!b) break;
        }
    
        if (b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}