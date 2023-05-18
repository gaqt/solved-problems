#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t; cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
    
        map<int,int> a;
    
        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            if (a.find(h) == a.end()) a[h] = 0;
            a[h]++;
        }
    
        multiset<int> k;
        for (map<int,int>::iterator it = a.begin(); it != a.end(); it++) k.insert(it->second);
    
        while (k.size() > 1) {
            int l = *k.rbegin();
            int r = *(++k.rbegin());
    
            k.erase(k.find(l)); k.erase(k.find(r));
            if (--l > 0) k.insert(l);
            if (--r > 0) k.insert(r);
            //cout << l << " " << r << endl;
        }
    
        long long s = 0;
    
        for (multiset<int>::iterator it = k.begin(); it != k.end(); it++) {
            s += (long long)(*it);
        }
    
        cout << s << endl;
    }
    
    return 0;
}