#include <bits/stdc++.h>
using namespace std;
    
int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
    
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
    
        bool valid = true;
        int i = a[n-1]+1, j = 0;
        while(i <= n && j < n) {
            //printf("j:%d a_j:%d i:%d\n", j, a[j], i);
            if (a[j] >= i) {
                i=a[j]+1;
                if (j == 0) {
                    valid = false;
                    break;
                }
            }
            j++;
        }
        if (i <= n) valid = false;
    
        if (valid) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    
    return 0;
}