#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
ll maxn = 1e5;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int v[n];
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) v[i] = (s[i]=='1')*1;
    
        queue<int> q[2];
        int k = 0;
        int r[n];
    
        for (int i = 0; i < n; i++) {
            if (q[1-v[i]].empty()) {
                k++;
                q[v[i]].push(k);
                r[i] = k;
            }
            else {
                int p = q[1-v[i]].front();
                q[1-v[i]].pop();
                q[v[i]].push(p);
                r[i] = p;
            }
        }
    
        cout << k << endl;
        for (int i = 0; i < n; i++) cout << r[i] << " ";
        cout << endl;
    }
    
    
    
    return 0;
}