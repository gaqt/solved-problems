#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 1123
    
long ver[MAXN][MAXN][2];
long hor[MAXN][MAXN][2];
long v[MAXN][MAXN];
long dp[MAXN][MAXN][2];
    
long long func(long long a, long long b) {
    if (a == 0) return 0;
    
    //cout << a << endl;
    
    long long i = 0;
    long long s = 1;
    while (a % s == 0 && s <= a) {
        s *= b;
        i++;
    }
    
    return i-1;
}
    
int inv(int p) {
    return abs(p-1);
}
    
int main() {
    
    int n;
    cin >> n;
    
    int x0=-1, y0=-1;
    
    //n = 10;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
    
            if (v[i][j] == 0) {
                y0 = i;
                x0 = j;
            }
    
            //v[i][j] = 11;
            //if (i == 1) v[i][j] = 10;
            ver[i][j][0] = ver[i-1][j][0] + func(v[i][j], 2);
            hor[i][j][0] = hor[i][j-1][0] + func(v[i][j], 2);
            ver[i][j][1] = ver[i-1][j][1] + func(v[i][j], 5);
            hor[i][j][1] = hor[i][j-1][1] + func(v[i][j], 5);
        }
    }
    
    
    for (int i = 0; i <= n; i++) {
        dp[0][i][0] = INT_MAX;
        dp[0][i][1] = INT_MAX;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = INT_MAX;
        dp[i][0][1] = INT_MAX;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                dp[i][j][0] = func(v[i][j], 2);
                dp[i][j][1] = func(v[i][j], 5);
                continue;
            }
            dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + ver[i][j][0] - ver[i-1][j][0];
            dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]) + ver[i][j][1] - ver[i-1][j][1];
        }
    }
    
    int p = 0;
    
    if (x0 != -1 && min(dp[n][n][0], dp[n][n][1]) >= 1) {
        cout << 1 << endl;
        for (int i = 1; i < x0; i++) cout << "R";
        for (int i = 1; i < y0; i++) cout << "D";
        for (int i = x0; i < n; i++) cout << "R";
        for (int i = y0; i < n; i++) cout << "D";
        cout << endl;
        return 0;
    }
    
    if (dp[n][n][0] > dp[n][n][1]) {
        p = 1;
        cout << dp[n][n][1] << endl;
    } else {
        cout << dp[n][n][0] << endl;
    }
    
    int i=n, j=n;
    
    vector<char> ans;
    
    while (i > 1 || j > 1) {
        if (i == 1) {
            ans.push_back('R');
            j--;
        } else if (j == 1) {
            ans.push_back('D');
            i--;
        } else if (dp[i-1][j][p] < dp[i][j-1][p]) {
            i--;
            ans.push_back('D');
        } else if (dp[i-1][j][p] > dp[i][j-1][p]) {
            j--;
            ans.push_back('R');
        } else {
            if (ver[i-1][j][inv(p)] > hor[i][j-1][inv(p)]) {
                i--;
                ans.push_back('D');
            } else {
                j--;
                ans.push_back('R');
            }
        }
    }
    
    for (int k = ans.size()-1; k >= 0; k--) cout << ans[k];
    
    cout << endl;
    
    return 0;
}