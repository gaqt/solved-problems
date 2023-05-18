#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int n, s;
    cin >> n >> s;
    
    if (s < 2*n) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int j = s%n;
        for (int i = 0; i < n; i++) {
            if (j > 0) {cout << (int)ceil((double)s/(double)n) << " "; j--;}
            else cout << (int)floor((double)s/(double)n) << " ";
        }
        cout << endl << 1 << endl;
    
    }
    
    
    return 0;
}