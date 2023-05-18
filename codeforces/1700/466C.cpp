#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N;
    cin >> N;
    
    uint64_t v[N];
    unordered_map<uint64_t, uint64_t> sums;
    
    cin >> v[0];
    sums.insert({v[0], 1});
    for (int i = 1; i < N; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        //cout << v[i] << " ";
    
        if (i == N-1)break;
    
        if (sums.find(v[i]) == sums.end()) {
            sums.insert({v[i], 1});
        } else {
            sums[v[i]]++;
        }
    }
    
    uint64_t t = v[N-1], answer = 0;
    
    for (int x = 0; x < N-2; x++) {
        sums[v[x]]--;
    
        uint64_t y = t - v[x];
        if (y % 2 != 0)continue;
    
        if (sums.find(y) != sums.end()) {
            if ( (v[x] == y - v[x]) && (y == t - v[x]) )answer += sums[y];
            //if (v[x] == y - v[x])cout << "1";
            //if (y == t - y)cout << "2";
            //cout << endl;
        }
    }
    
    cout << answer;
    
    return 0;
}