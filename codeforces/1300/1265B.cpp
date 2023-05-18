#include <bits/stdc++.h>
using namespace std;
    
#define MAXN 212345
    
int main() {
    int t, N, a[MAXN], x,y, mx, pos[MAXN];
    bool res[MAXN];
    scanf("%d", &t);
    
    for (int j = 0; j < t; j++) {
        scanf("%d", &N);
    
        for (int k = 0; k < N; k++) {
            scanf("%d", &a[k]);
            pos[a[k]] = k;
            if (a[k] == 1) {
                x = k;
                y = k;
            }
        }
    
        mx = 1;
    
        for (int i = 1; i <= N; i++) {
            res[i-1] = false;
    
            if (mx != i) {
                if (pos[i] > y) {
                    //cout << "d";
    
                    while (pos[i] > y) {
                        y++;
                        mx = max(mx, a[y]);
                    }
                } else if (pos[i] < x){
                    //cout << "d";
    
                    while (pos[i] < x) {
                        x--;
                        mx = max(mx, a[x]);
                    }
                }
            }
    
            if (mx > i) {
                res[i-1] = false;
                //cout << "a";
            } else if (mx == i) {
                res[i-1] = true;
                //cout << "b";
            }
    
            //cout << " mx: " << mx << endl;
        }
    
        for (int i = 0; i < N; i++) {
            printf("%d", res[i]);
        }
    
        printf("\n");
    
    }
    
    
    return 0;
}