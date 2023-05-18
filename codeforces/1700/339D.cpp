#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 131072
    
bool isOr[2*MAXN+2];
int seg[2*MAXN+2];
    
int siz = 0;
    
void build() {
    for (int i = siz-1; i >= 1; i--) {
        if (isOr[i]) seg[i] = seg[2*i] | seg[2*i+1];
        else       seg[i] = seg[2*i] ^ seg[2*i+1];
    }
}
    
void modify(int p, int b) {
    p += siz-1;
    
    seg[p] = b;
    p/=2;
    
    while (p >= 1) {
        if (isOr[p]) seg[p] = seg[2*p] | seg[2*p+1];
        else       seg[p] = seg[2*p] ^ seg[2*p+1];
        p /= 2;
    }
}
    
int main() {
    
    int n, m;
    cin >> n >> m;
    
    siz = round(pow(2, n));
    
    for (int i = 0; i < siz; i++) {
        cin >> seg[siz+i];
    }
    
    bool b = true;
    int aux = siz/2;
    int idx = siz-1;
    
    while (idx >= 1) {
        for (int i = idx; i > idx-aux; i--) isOr[i] = b;
        b = !b;
        idx -= aux;
        aux/=2;
    }
    
    build();
    
    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        modify(p, b);
        cout << seg[1] << endl;
    }
    
    return 0;
}