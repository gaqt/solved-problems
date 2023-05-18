#include <bits/stdc++.h>
using namespace std;
    
unsigned long long M = pow(10, 9) + 7;
    
int main() {
        unsigned long long N;
        cin >> N;
        unsigned long long dp[N+1], x = 3;
        dp[0] = 0;
        dp[1] = 0;
    
        for(unsigned long long i=2; i<=N; i++) {
            dp[i] = x;
            x = ( 3LL*(dp[i-1] % M) + 2LL*(x % M) ) % M;
    
        }
        cout.precision(0);
        cout << fixed << dp[N];
        return 0;
}