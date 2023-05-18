#include <bits/stdc++.h>
using namespace std;
    
const int MAXA = 11234567;
const int MAX_SIEVE = sqrt(MAXA);
    
int spf[MAXA];
bool sieve[MAX_SIEVE+1];
    
vector<int> pfact(int x) {
    vector<int> result;
    
    while (x != 1) {
        if (result.empty() || result[result.size()-1] != spf[x]) result.push_back(spf[x]);
        x /= spf[x];
    }
    
    return result;
}
    
int main() {
    int n, max_sieve=0, max_a=0;
    cin >> n;
    int a[n];
    int d1[n];
    int d2[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    
    max_sieve = 1+sqrt(max_a);
    
    for (int i = 2; i <= max_sieve; i++) {
        if (sieve[i]) continue;
    
        spf[i] = i;
    
        for (int j = i+i; j <= max_a; j += i) {
            if (j <= max_sieve) sieve[j] = true;
            spf[j] = i;
        }
    }
    
    for (int i = 0; i <= max_a; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        vector<int> primes = pfact(a[i]);
        if (primes.size() < 2) {
            d1[i] = -1;
            d2[i] = -1;
        } else {
            d1[i] = 1;
            for (int j = 0; j < primes.size()-1; j++) {
                d1[i] *= primes[j];
            }
            d2[i] = primes[primes.size()-1];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << d1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << d2[i] << " ";
    }
    cout << endl;
    
    return 0;
}