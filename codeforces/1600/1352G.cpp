#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
    
        if (n <= 3) {
            cout << -1 << endl;
            continue;
        }
    
        if (n == 4) {cout << "2 4 1 3" << endl; continue;}
        if (n == 5) {cout << "1 3 5 2 4" << endl; continue;}
    
        int crr = 2-(n%2);
    
        while (crr <= n) {
            cout << crr << " ";
            crr+=2;
        }
        crr-=5; cout << crr << " ";
        crr+=2; cout << crr << " ";
        crr-=4; cout << crr << " ";
        crr-=2;
        while (crr >= 1) {
            cout << crr << " ";
            crr-=2;
        }
    
        cout << endl;
    }
    
    
    
    return 0;
}