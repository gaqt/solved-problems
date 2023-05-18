#include <bits/stdc++.h>
using namespace std;
    
using ll = long long;
    
int main() {
    
    ll k;
    cin >> k;
    
    ll m = 1, j = 0;
    ll v[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    string s = "codeforces";
    
    while (m < k) {
        if (j == 10) j=0;
        m/=v[j];
        v[j]++;
        m*=v[j];
        j++;
    }
    
    for (int i = 0; i < 10; i++) for (int h = 0; h < v[i]; h++) cout << s[i];
    cout << endl;
    
    return 0;
}