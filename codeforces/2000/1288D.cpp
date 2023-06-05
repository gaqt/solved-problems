//https://codeforces.com/problemset/problem/1288/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=300000, m=8, maxa=-1;
    cin >> n >> m;
    int** a = (int**) malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++) {
        a[i] = (int*) malloc(sizeof(int)*m);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            //a[i][j] = rand()%1000000000;
            maxa = max(maxa, a[i][j]);
        }
    }

    int res_l = -1, res_r = -1, res_max = -1; 
    uint8_t goal = (1<<m)-1;

    int l=0, r=maxa+1, mid=(1+maxa)/2;
    while (l < r) { //log(maxa)(nm+4^m) ~= 30*(2400000 + 65536) = 73966080
        int a_[1<<m];
        for (int i = 0; i < 1<<m; i++) a_[i] = -1;
        for (int i = 0; i < n; i++) {
            uint8_t tmp = 0;
            for (int j = 0; j < m; j++) {
                tmp = tmp | ((uint8_t)(a[i][j] >= mid) << j);
            }
            a_[tmp] = i;
        }

        bool found = false;
        for (int i = 0; i < 1<<m; i++) {
            for (int j = i; j < 1<<m; j++) {
                if ((i | j) == goal && a_[i] != -1 && a_[j] != -1 && mid > res_max) {
                    res_max = mid;
                    res_l = a_[i];
                    res_r = a_[j];
                    found = true;
                }
            }
        }

        if (found) {
            l = mid;
            mid = (l+r+1)/2;
        } else {
            r = mid;
            mid = (l+r)/2;
        }
    }

    cout << res_l+1 << " " << res_r+1;

    return 0;
}