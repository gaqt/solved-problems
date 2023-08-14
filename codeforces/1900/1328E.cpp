//https://codeforces.com/problemset/problem/1328/E

#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 212345
 
typedef pair<int,int> pii;
 
struct vertex {
    vector<int> u;
    pii range;
};
 
vertex tree[MAXN];
int n, m;
 
int build_paths(int x, int prev, int crr_path) {
    int min_path = crr_path;
    int max_path = min_path-1;
 
    for (int u: tree[x].u) {
        if (u == prev) continue;
 
        max_path++;
        max_path = max(max_path, build_paths(u, x, max_path));
    }
 
    max_path = max(max_path, min_path);
 
    tree[x].range = make_pair(min_path, max_path);
    return max_path;
}
 
pii intersect(pii r1, pii r2) {
    pii r3 = make_pair(max(r1.first, r2.first), min(r1.second, r2.second));
    if (r3.first > r3.second) return make_pair(0,0);
    else return r3;
}
 
//assuming r1 and r2 intersect or are adjacent
pii union_(pii r1, pii r2) {
    return make_pair(min(r1.first, r2.first), max(r1.second, r2.second));
}
 
int main() {
 
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].u.push_back(b);
        tree[b].u.push_back(a);
    }
 
    build_paths(1, 0, 1);
 
    while(m--) {
        int k; cin>>k;
        int v[k]; for (int i = 0; i < k; i++) cin >> v[i];
 
        pii r = make_pair(0,INT_MAX);
 
        for (int i = 0; i < k; i++) {
            pii _r = tree[v[i]].range;
            for (int u: tree[v[i]].u) {
                _r = union_(_r, tree[u].range);
            }
 
            r = intersect(r, _r);
        }
 
        if (r.first == 0 && r.second == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
 
    return 0;
}