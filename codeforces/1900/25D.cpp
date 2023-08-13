//https://codeforces.com/problemset/problem/25/D

#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 1123
 
struct v {
    vector<int> u;
};
 
int n;
 
v graph[MAXN];
bool component_verified[MAXN];
bool viable_verified[MAXN];
set<pair<int,int> > viable_for_deletion;
vector<int> components;
 
void find_component(int k) {
    component_verified[k] = true;
    for (int u: graph[k].u) {
        if (!component_verified[u]) find_component(u);
    }
}
 
void find_components() {
    for (int i = 1; i <= n; i++) {
        if (!component_verified[i]) {
            components.push_back(i);
            find_component(i);
        }
    }
}
 
void find_viable_for_deletion(int k, int prev) {
    viable_verified[k] = true;
    for (int u: graph[k].u) {
        if (u == prev) continue;

        if (!viable_verified[u]) find_viable_for_deletion(u, k);
        else viable_for_deletion.insert(make_pair(min(k,u),max(k,u)));
    }
}
 
 
int main() {
    cin >> n;
 
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].u.push_back(b);
        graph[b].u.push_back(a);
    }
 
    find_components();
 
    for (int i = 0; i < components.size(); i++) {
        find_viable_for_deletion(components[i], 0);
    }
 
    //answer
    cout << components.size() - 1 << endl;

    set<pair<int,int> >::iterator it = viable_for_deletion.begin();
 
    for (int i = 1; i < components.size(); i++) {
        cout << (*it).first << " " << (*it).second << " ";
        cout << 1 << " " << components[i] << endl;

        it++;
    }
 
    return 0;
}