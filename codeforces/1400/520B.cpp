#include <bits/stdc++.h>
using namespace std;
    
struct vertex {
    int adj[2];
};
    
int bfs(vertex graph[], int n, int m, int size) {
    queue<pair<int, int> > q;
    
    bool verified[size];
    for (int i = 0; i < size; i++) verified[i] = false;
    
    
    q.push({n, 0});
    verified[n] = true;
    
    
    
    int path = 0;
    while (!q.empty()) {
        int v = q.front().first;
        path = q.front().second;
        q.pop();
    
        verified[v] = true;
    
        if (v == m) break;
    
        for (int i = 0; i < 2; i++) {
            int u = graph[v].adj[i];
            if (u && !verified[u]) q.push({u, path+1});
        }
    
        
    }
    
    return path;
}
    
    
int main() {
    int n, m, size;
    
    cin >> n >> m;
    
    size = 2*max(n, m);
    
    vertex graph[size+1];
    
    for (int i = 1; i <= size; i++) {
        if (2*i > size) graph[i].adj[0] = 0;
        else graph[i].adj[0] = 2*i;
    
        graph[i].adj[1] = i-1;
    }
    
    cout << bfs(graph, n, m, size);
    
    return 0;
}