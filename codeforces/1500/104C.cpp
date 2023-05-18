#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 112
    
struct vertex {
    vector<int> adj;
};
    
vertex graph[MAXN];
bool verified[MAXN];
    
int n, m;
    
void dfs(int v) {
    verified[v] = true;
    
    for (int u = 0; u < graph[v].adj.size(); u++) {
        if (!verified[graph[v].adj[u]]) dfs(graph[v].adj[u]);
    }
}
    
int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        graph[x].adj.push_back(y);
        graph[y].adj.push_back(x);
    }
    
    if (n == m) {
        for (int i = 0; i <= n; i++) verified[i] = false;
    
        dfs(1);
    
        bool isConnected = true;
        for (int i = 1; i <= n; i++) {
            if (!verified[i]) {
                isConnected = false;
                break;
            }
        }
    
        if (isConnected) {
            cout << "FHTAGN!";
        } else {
            cout << "NO";
        }
    
    } else {
        cout << "NO";
    }
    
    return 0;
}