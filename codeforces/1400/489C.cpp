#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int m, s;
    
    cin >> m >> s;
    
    if (s == 0 && m > 1) {
        cout << -1 << " " << -1;
        return 0;
    }
    
    int maxM[m], minM[m];
    
    int tmp = s;
    
    for (int i = 0; i < m; i++) {
        if (tmp >= 9) {
            tmp -= 9;
            maxM[i] = 9;
        } else {
            maxM[i] = tmp;
            tmp = 0;
        }
    }
    
    if (tmp > 0) {
        cout << -1 << " " << -1;
        return 0;
    }
    
    tmp = s;
    
    for (int i = m-1; i >= 0; i--) {
        if (tmp > 9) {
            tmp -= 9;
            minM[i] = 9;
        } else if (tmp >= 1){
            minM[i] = tmp-1;
            tmp = 1;
        } else {
            minM[i] = 0;
        }
    }
    
    if (tmp == 1) {
        if (minM[0] == 0) {
            minM[0] = 1;
        } else {
            minM[0]++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << minM[i];
    }
    
    cout << " ";
    
    for (int i = 0; i < m; i++) {
        cout << maxM[i];
    }
    
    
    return 0;
}