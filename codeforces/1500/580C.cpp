#include <bits/stdc++.h>
using namespace std;
    
bool verified[100001];
    
struct vertex {
    vector<int> u;
    vector<int> getChildren() {
    int i=0;
    vector<int> children;
    for(i=0;i<u.size();i++) {
        if(!verified[u[i]]) children.push_back(u[i]);
    }
    return children;
    }
};
    
void verify(int v){
    verified[v]=true;
}
    
vertex graph[100001];
bool red[100001];
int amount=0,n,m;
    
void dfs(int v, int m2) {
    vector<int> children = graph[v].getChildren();
    int children_amount = children.size();
    verify(v);
    if(children_amount==0) {
        amount++;
        return;
    }
    int i=0;
    for(i=0;i<children_amount;i++){
        if(red[children[i]]) {
            if(m2+1<=m) dfs(children[i], m2+1);
        } else dfs(children[i], 0);
    }
}
    
int main() {
    int i=0,p,q,root;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> p;
        red[i+1]=(p==1);
        verified[p]=false;
    }

    for(i=0;i<n-1;i++){
        cin >> p >> q;
        graph[p].u.push_back(q);
        graph[q].u.push_back(p);
    }
    
    if(red[1]) {
        dfs(1,1);
    } else {
        dfs(1,0);
    }
    
    cout << amount;
    return 0;
}