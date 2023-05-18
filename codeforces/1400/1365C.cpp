#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int n;
    cin >> n;
    
    int a[2*n];
    int b[n];
    int match[2*n];
    int pos[2*n][2];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
        match[i] = 0;
        match[i+n] = 0;
        pos[a[i]][0] = i;
        pos[a[i]][1] = i+n;
    }
    
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i < n; i++) {
        if (pos[b[i]][0] >= i) match[pos[b[i]][0]-i]++;
        match[pos[b[i]][1]-i]++;
    }
    
    int maxMatch = 0;
    for (int i = 0; i < 2*n; i++) maxMatch = max(maxMatch, match[i]);
    
    cout << maxMatch << endl;
    
    return 0;
}