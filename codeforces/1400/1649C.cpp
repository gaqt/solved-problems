#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
int main() {
    
    ll n, m;
    cin >> n >> m;
    
    int v[n][m];
    map<int, vector<int> > x[2];
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        x[0][v[i][j]].push_back(i);
        x[1][v[i][j]].push_back(j);
    }
    
    ll sum = 0;
    
    for (int h = 0; h < 2; h++) {
        for (map<int,vector<int> >::iterator k = x[h].begin(); k != x[h].end(); k++) {
            vector<int> t = k->second;
            sort(t.begin(), t.end());
    
            ll cm = 0;
            ll typ = 0;
            ll cnt = 1;
    
            for (int i = 1; i < t.size(); i++) {
                if (t[i] == t[i-1]) {
                    cnt++;
                } else {
                    cm += typ*(t[i] - t[i-1]);
                    cm += cnt*(t[i] - t[i-1]);
                    typ += cnt;
    
                    cnt = 1;
                }
                sum += cm;
            }
        }
    }
    
    cout << sum << endl;
    
    return 0;
}