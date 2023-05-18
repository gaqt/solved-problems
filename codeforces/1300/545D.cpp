#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N;
    cin >> N;
    vector<unsigned long long> v;
    
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end());
    
    unsigned long long sum = 0, amount = 0;
    
    for (int i = 0; i < N; i++) {
        if (v[i] >= sum) {
            amount++;
            sum += v[i];
        }
    }
    
    cout << amount;
    return 0;
}