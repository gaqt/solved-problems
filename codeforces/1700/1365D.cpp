#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    int t;
    cin >> t;
 
    while(t--) {
        int n, m;
        cin >> n >> m;
 
        char v[n+2][m+2];
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++) v[i][j] = s[j-1];
        }
 
        for (int i = 0; i <= n+1; i++) v[i][0] = '#';
        for (int i = 0; i <= m+1; i++) v[0][i] = '#';
        for (int i = 0; i <= n+1; i++) v[i][m+1] = '#';
        for (int i = 0; i <= m+1; i++) v[n+1][i] = '#';
 
        bool ans = true;
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] == 'B') {
                    if (v[i+1][j] == 'G') {ans=false; break;}
                    else if(v[i+1][j] == '.') v[i+1][j] = '#';
 
                    if (v[i][j+1] == 'G') {ans=false; break;}
                    else if(v[i][j+1] == '.') v[i][j+1] = '#';
 
                    if (v[i-1][j] == 'G') {ans=false; break;}
                    else if(v[i-1][j] == '.') v[i-1][j] = '#';
 
                    if (v[i][j-1] == 'G') {ans=false; break;}
                    else if(v[i][j-1] == '.') v[i][j-1] = '#';
                }
            }
        }
 
        if (!ans) {
            cout << "No" << endl;
            continue;
        }
 
        int gcnt = 0, found = 0;
 
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (v[i][j] == 'G') gcnt++;
 
        int verified[n+2][m+2];
        for (int i = 0; i <= n+1; i++) for (int j = 0; j <= m+1; j++) verified[i][j] = false;
 
        queue<pair<int,int> > q;
 
        if (v[n][m] != '#') q.push(make_pair(n,m));
        verified[n][m] = true;
 
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
 
            int i = p.first;
            int j = p.second;
 
            if (v[i][j] == 'G') found++;
            if (v[i][j] == 'B') {ans=false; break;}
 
            if (v[i+1][j] != '#' && !verified[i+1][j]) {q.push(make_pair(i+1,j)); verified[i+1][j] = true;}
            if (v[i][j+1] != '#' && !verified[i][j+1]) {q.push(make_pair(i,j+1)); verified[i][j+1] = true;}
            if (v[i-1][j] != '#' && !verified[i-1][j]) {q.push(make_pair(i-1,j)); verified[i-1][j] = true;}
            if (v[i][j-1] != '#' && !verified[i][j-1]) {q.push(make_pair(i,j-1)); verified[i][j-1] = true;}
        }
 
        if (found != gcnt || !ans) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
 
 
    return 0;
}