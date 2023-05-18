#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
    
        int b[s.length()];
        for (int i = 0; i < s.length(); i++) b[i] = 0;
    
        int minD = 11234;
        int dist = 0;
    
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') {
                b[i] = 1;
                dist++;
            }
        }
    
        minD = dist;
    
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < s.length(); i++) {
                dist -= b[i];
                b[i] = 1 - b[i];
                dist += b[i];
                minD = min(minD, dist);
            }
        }
    
        cout << minD << endl;
    
    }
    
    return 0;
}