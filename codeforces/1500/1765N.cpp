#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        string xa;
        cin >> xa >> k;
        int n = xa.length();
        int x[n];
        for (int i = 0; i < n; i++) x[i] = xa[i]-48;
    
        vector<int> m[10];
        int lst[10];
        for (int i = 0; i < n; i++) {
            m[x[i]].push_back(i);
            lst[x[i]] = 0;
        }

        int h=0;
        vector<int> ans;

        while(h < n) {
            if (k == 0) {
                while (h < n) {
                    ans.push_back(x[h]);
                    h++;
                }
                break;
            }
            for (int i = 0; i <= 9; i++) {
                if (h == 0 && i == 0) continue;
                if (lst[i] >= m[i].size()) continue;
                if (m[i][lst[i]] <= h+k) {
                    ans.push_back(i);
                    k -= (m[i][lst[i]]-h);
                    h = m[i][lst[i]]+1;
                    break;
                }
            }
            for (int i = 0; i <= 9; i++) {
                if (lst[i] >= m[i].size()) continue;
                while (m[i][lst[i]] < h) {
                    lst[i]++;
                    if (lst[i] >= m[i].size()) break;
                }
            }
        }
        while (k > 0) {
            ans.pop_back();
            k--;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }
}