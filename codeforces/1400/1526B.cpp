#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        long x;
        cin >> x;
    
        bool b = false;
    
        for (long d = 0; d < 11; d++) {
            if (x < d*111) continue;
    
            if ((x-d*111)%11 == 0) {
                b = true;
                break;
            }
        }
    
        if (b) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    
    return 0;
}