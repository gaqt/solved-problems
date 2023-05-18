#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    char n[7];
    
    for (int i = 0; i < 7; i++) n[i] = 'a';
    
    scanf("%s", n);
    
    int q[7], maxq = 0;
    
    for (int i = 0; i < 7; i++) {
        if (n[i] == 'a') {
            q[i] = -1;
            q[i-1] = -1;
            continue;
        } else if (n[i] == '\0' || n[i] == '\n') {
            q[i] = -1;
            continue;
        }
        
        q[i] = n[i] - 48;
        maxq = max(maxq, q[i]);
    }
    
    cout << maxq << endl;
    
    while (1) {
        bool b = true;
        for (int i = 0; i < 7; i++) if (q[i] > 0) b = false;
        if (b) break;
    
        bool lZeros = true;
    
        for (int i = 0; i < 7; i++) {
            if (q[i] > 0) {
                cout << 1;
                q[i]--;
                lZeros = false;
            } else if (q[i] != -1 && !lZeros) {
                cout << 0;
            }
        }
    
        cout << " ";
    }
    
    return 0;
}