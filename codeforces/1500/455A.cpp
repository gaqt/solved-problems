#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
    
unsigned long long dp[MAX], cnt[MAX], N;
    
int main() {
        cout.precision(0);
        cin >> N;
        int max_all = N;
        for(int i=0; i<MAX; i++) {
            dp[i] = 0;
            cnt[i] = 0;
        }
    
        for(int i=0; i<N; i++) {
            int p;
            cin >> p;
            cnt[p]++;
            max_all = max(max_all, p);
        }
    
        dp[1] = cnt[1];
        for(unsigned long long i=2; i<=max_all; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i);
        }
        cout << fixed << (unsigned long long)dp[max_all];
        return 0;
}