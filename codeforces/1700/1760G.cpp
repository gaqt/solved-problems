#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 112345
    
int n, a, b;
    
int req[MAXN];
int ach[MAXN];
vector<pair<int, int> > adj[MAXN]; //first: idx, second: weight
    
set<int> reqList;
set<int> achList;
    
void setReq() {
    bool ver[n];
    for (int i = 0; i < n; i++) ver[i] = false;
    queue<int> q;
    q.push(b);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ver[x] = true;
    
        for (int i = 0; i < adj[x].size(); i++) {
            int u = adj[x][i].first;
            int w = adj[x][i].second;
            if (!ver[u]) {
                req[u] = (req[x]&(~w))|((~req[x])&w);
                reqList.insert(req[u]);
                q.push(u);
            }
        }
    }
}
    
void setAch() {
    bool ver[n];
    for (int i = 0; i < n; i++) ver[i] = false;
    queue<int> q;
    q.push(a);
    achList.insert(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ver[x] = true;
    
        for (int i = 0; i < adj[x].size(); i++) {
            int u = adj[x][i].first;
            int w = adj[x][i].second;
            if (!ver[u] && u != b) {
                ach[u] = (ach[x]&(~w))|((~ach[x])&w);
                achList.insert(ach[u]);
                q.push(u);
            }
        }
    }
}
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        a--;
        b--;
    
        for (int i = 0; i < n; i++) adj[i].clear();
        reqList.clear();
        achList.clear();
        req[b] = 0;
        ach[a] = 0;
        
        for (int i = 0; i < n-1; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
    
        setReq();
        setAch();
    
        bool found = false;
    
        for (set<int>::iterator it = achList.begin(); it != achList.end(); it++) {
            if (reqList.find(*it) != reqList.end()) {
                found = true;
                break;
            }
        }
    
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}