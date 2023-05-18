#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N;
    cin >> N;
    int even_i, even_amount = 0;
    int odd_i;
    
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (p%2 == 0) {
            even_i = i;
            even_amount++;
        } else {
            odd_i = i;
        }
    }
    
    if (even_amount == 1)cout << even_i+1;
    else cout << odd_i+1;
}