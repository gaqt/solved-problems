#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
typedef pair<int,int> pii;
    
    
struct cmp {
    bool operator()(const pii& a, const pii& b) {
        if (a.second - a.first != b.second - b.first)
            return a.second - a.first < b.second - b.first;
        else return a.first > b.first;
    }
};
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
    
        int a[n]; for (int i = 0; i < n; i++) a[i] = 0;
        priority_queue<pii, vector<pii>, cmp> q;
        q.push(make_pair(0,n-1));
    
        for (int i = 1; i <= n && !q.empty(); i++) {
            int l = q.top().first;
            int r = q.top().second;
            int j = (l+r)/2;
            q.pop();
            a[j] = i;
    
            if (l <= j-1) q.push(make_pair(l, j-1));
            if (j+1 <= r) q.push(make_pair(j+1, r));
    
        }
    
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    
    
    return 0;
}