#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
ll maxn = 1e5;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
    
        vector<int> v;
    
        if (n0 > 0 || n1 > 0) v.push_back(0);
        if (n0 == 0 && n1 == 0) v.push_back(1);
    
        for (int i = 0; i < n0; i++) v.push_back(0);
        int b = 1;
        for (int i = 0; i < n1; i++) {
            v.push_back(b);
            b = 1-b;
        }
        bool flag = false;
        if (n2 > 0 && v[v.size()-1] == 0) {
            v.pop_back();
            flag = true;
        }
        for (int i = 0; i < n2; i++) v.push_back(1);
        if (flag) v.push_back(0);
    
        for (int i = 0; i < v.size(); i++) cout << v[i];
        cout << endl;
    }
    
    
    
    return 0;
}