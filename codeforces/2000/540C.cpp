#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 512
    
char graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
int r1, c1, r2, c2;
    
bool dfs(int i, int j) {
    if (visited[i][j]) return false;
    
    visited[i][j] = true;
    
    if (i+1 == r2 && j == c2) return true;
    if (i-1 == r2 && j == c2) return true;
    if (i == r2 && j+1 == c2) return true;
    if (i == r2 && j-1 == c2) return true;
    
    if (graph[i+1][j] == '.' && dfs(i+1, j)) return true;
    if (graph[i-1][j] == '.' && dfs(i-1, j)) return true;
    if (graph[i][j+1] == '.' && dfs(i, j+1)) return true;
    if (graph[i][j-1] == '.' && dfs(i, j-1)) return true;
    
    return false;
}
    
int main() {
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j+1] = s[j];
        }
    }
    
    cin >> r1 >> c1 >> r2 >> c2;
    
    if (r1 == r2 && c1 == c2) {
        int cnt = 0;
        if (graph[r2+1][c2] == '.') cnt++;
        if (graph[r2-1][c2] == '.') cnt++;
        if (graph[r2][c2+1] == '.') cnt++;
        if (graph[r2][c2-1] == '.') cnt++;
    
        if (graph[r2][c2] == 'X') {
            if (cnt > 0) cout << "YES";
            else cout << "NO";
        } else {
            if (cnt > 1) cout << "YES";
            else cout << "NO";
        }
    } else if (dfs(r1, c1)) {
        if (graph[r2][c2] == 'X') cout << "YES";
        else {
            int cnt = 0;
            if (graph[r2+1][c2] == '.') cnt++;
            if (graph[r2-1][c2] == '.') cnt++;
            if (graph[r2][c2+1] == '.') cnt++;
            if (graph[r2][c2-1] == '.') cnt++;
    
            if (cnt > 1) cout << "YES";
            else {
                if (abs(r2-r1) + abs(c2-c1) == 1 && graph[r1][c1] == 'X' && cnt >= 1) cout << "YES";
                else cout << "NO";
            }
        }
    } else {
        cout << "NO";
    }
    
    return 0;
}