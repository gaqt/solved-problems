//https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
using namespace std;
 
#define INF LLONG_MAX
#define MAXN 112345
 
struct vertex {
    vector<int> u;
    vector<long long> w;
};
 
vertex graph[MAXN];
 
int n, m;
 
vector<int> dijkstra(int origin, int target) {
    long long dist[n+1];
    int prev[n+1];
 
    for (int i = 0; i <= n; i++) dist[i] = INF;
    for (int i = 0; i <= n; i++) prev[i] = -1;
 
    dist[origin] = 0;
    priority_queue<pair<long long, int> > q;
    q.push(make_pair(0, origin));
 
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
 
        if (v == target) break;
 
        for (int i = 0; i < graph[v].u.size(); i++) {
            if (dist[v] + graph[v].w[i] < dist[graph[v].u[i]]) {
                dist[graph[v].u[i]] = dist[v] + graph[v].w[i];
                prev[graph[v].u[i]] = v;
                q.push(make_pair(-dist[graph[v].u[i]], graph[v].u[i]));
            }
        }
    }
 
    vector<int> rpath;
    int crr = target;
 
    if (prev[target] == -1) return {};
 
    while (crr != origin) {
        rpath.push_back(crr);
        crr = prev[crr];
    }
 
    rpath.push_back(origin);
 
    vector<int> path;
 
    for (int i = rpath.size()-1; i >= 0; i--) {
        path.push_back(rpath[i]);
    }
 
    return path;
}
 
 
int main() {
    cin >> n >> m;
 
    for (int i = 0; i < m; i++) {
        int a,b;
        long long w;
        cin >> a >> b >> w;
        graph[a].u.push_back(b);
        graph[a].w.push_back(w);
        graph[b].u.push_back(a);
        graph[b].w.push_back(w);
    }
 
    vector<int> path = dijkstra(1, n);
 
    if (path.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
 
    for (int i: path) {
        cout << i << " ";
    }
    cout << endl;
 
    return 0;
}