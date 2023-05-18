#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N, M;
    
    cin >> N >> M;
    
    int a[N][M];
    
    long long res = N*M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        int tmp[2] = {0,0};
    
        for (int j = 0; j < M; j++) {
            tmp[a[i][j]]++;
        }
    
        for (int j = 0; j < 2; j++) {
            if (tmp[j] < 2) continue;
            res += pow(2, tmp[j]) - tmp[j] - 1;
        }
    }
    
    for (int i = 0; i < M; i++) {
        int tmp[2] = {0,0};
    
        for (int j = 0; j < N; j++) {
            tmp[a[j][i]]++;
        }
    
        for (int j = 0; j < 2; j++) {
            if (tmp[j] < 2) continue;
            res += pow(2, tmp[j]) - tmp[j] - 1;
        }
    }
    
    cout << res;
    
    return 0;
}