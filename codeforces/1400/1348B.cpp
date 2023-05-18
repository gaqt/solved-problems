#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int t;
    
    cin >> t;
    
    int n, k;
    
    while(t--) {
        cin >> n >> k;
        
        set<int> kDiff;
    
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
    
            kDiff.insert(tmp);
        }
    
        if (kDiff.size() > k) {
            cout << -1 << endl;
            continue;
        }
    
        int i = 1;
    
        while (kDiff.size() < k) {
            kDiff.insert(i);
            i++;
        }
    
        cout << n*kDiff.size() << endl;
    
        for (int i = 0; i < n; i++) {
            set<int>::iterator it = kDiff.begin();
            for (it = kDiff.begin(); it != kDiff.end(); it++) {
                cout << *it << " ";
            }
        }
    
        cout << endl;
    }
    
    
    return 0;
}