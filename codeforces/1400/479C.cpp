#include <bits/stdc++.h>
using namespace std;
    
bool cmp(pair<int, int> a, pair<int ,int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
    
int main() {
    int n;
    
    cin >> n;
    
    pair<int, int> v[n];
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v, v+n, cmp);
    
    int day = 0;
    
    for (int i = 0; i < n; i++) {
        if (v[i].second >= day)
            day = min(v[i].first, v[i].second);
        else
            day = v[i].first;
    }
    
    cout << day;
    
    return 0;
}