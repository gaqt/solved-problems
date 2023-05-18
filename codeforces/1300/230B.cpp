#include <bits/stdc++.h>
using namespace std;
    
#define MAXX 1000000
    
int main() {
    
    int N;
    cin >> N;
    uint64_t numbers[N];
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    bool primes[MAXX+1];
    set<uint64_t> tprimes;
    for (uint64_t i = 2; i <= MAXX; i++)primes[i] = true;
    
    for (uint64_t i = 2; i <= MAXX; i++) {
        if (primes[i]) {
            tprimes.insert(i*i);
            for (uint64_t g = 2; g <= MAXX / i; g++) {
                primes[g*i] = false;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (tprimes.find(numbers[i]) != tprimes.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}