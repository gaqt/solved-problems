#include <bits/stdc++.h>
using namespace std;
    
#define INF 1e8
    
int main() {
    
    int v;
    cin >> v;
    
    int a[10];
    a[0] = INF;
    
    int x = 0, minV = INF;
    
    for (int i = 1; i <= 9; i++) {
        cin >> a[i];
        if (a[i] <= minV) {x = i; minV = a[i];}
    }
    
    vector<int> num;
    
    while (v >= minV) {
        num.push_back(x);
        v -= minV;
    }
    
    int y = num.size() - 1;
    bool b = true;
    
    while (v > 0 && y >= 0 && b) {
        b = false;
        for (int i = 9; i > x; i--) {
            if (a[i] <= v + a[x]) {
                b = true;
                num[y] = i;
                v += a[x];
                v -= a[i];
                break;
            }
        }
        y--;
    }
    
    if (num.empty()) {cout << -1; return 0;}
    
    for (int i = num.size()-1; i >= 0; i--) cout << num[i];
    cout << endl;
    
    return 0;
}