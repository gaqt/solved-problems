#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 112
    
int t, n;
int b[MAXN][MAXN];
    
int cnt=1;
set<int> a[MAXN];
    
void rmvDup(int x) {
    bool ver[n];
    for (int i = 0; i < n; i++) ver[i] = false;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
    
        if (ver[p]) {
            if (b[x][p]) b[x][p] = 0;
            else continue;
        } else ver[p] = true;
    
        for (int i = 0; i < n; i++) {
            if (b[p][i]) q.push(i);
        }
    }
}
    
set<int> populate(int x) {
    if (!a[x].empty()) return a[x];
    
    set<int> crr;
    int childCnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (b[i][x]) {
            set<int> tmp;
            tmp = populate(i);
            for (set<int>::iterator it = tmp.begin(); it != tmp.end(); it++) crr.insert(*it);
            childCnt++;
        }
    }
    
    crr.insert(cnt);
    cnt++;
    
    return a[x] = crr;
}
    
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < n; j++) b[i][j] = tmp[j]-48;
        }
        
        for (int i = 0; i < n; i++) a[i].clear();
        for (int i = 0; i < n; i++) rmvDup(i);
        cnt=1;
    
        vector<int> parents;
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (b[i][j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) parents.push_back(i);
        }
    
        for (int i = 0; i < parents.size(); i++) populate(parents[i]);
    
        for (int i = 0; i < n; i++) {
            cout << a[i].size();
            for (set<int>::iterator it = a[i].begin(); it != a[i].end(); it++) cout << " " << *it;
            cout << endl;
        }
    }
    
}