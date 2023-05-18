#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int64_t n, k;
        cin >> n >> k;
        map<int64_t, int64_t> cnt;
        int64_t a[n];
        for (int64_t i = 0 ; i < n; i++) {
            cin >> a[i];
            if (cnt.find(k-(a[i]%k)) == cnt.end()) cnt[k-(a[i]%k)] = 0;
            cnt[k-(a[i]%k)]++;
        }
    
        int64_t step=1, last=0, lastX=0;
        bool b = false;
        do {
            b = false;
            for (map<int64_t,int64_t>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                if (it->first != k && it->second != 0) {
                    step += (it->first) - lastX;
                    (it->second)--;
                    last=step;
                    lastX = (it->first);
                    b = true;
                }
            }
            step += k - lastX;
            lastX=0;
        } while (b);
    
        cout << last << endl;
    }
    
    return 0;
}