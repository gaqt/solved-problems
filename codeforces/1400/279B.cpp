#include <bits/stdc++.h>
using namespace std;
    
int main() {
    int N, T;
    cin >> N >> T;
    
    int a[N];
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int i = 0, j = 0, sum = a[0], maximum_amount = 0;
    
    while(j < N) {
        if(sum <= T) {
            maximum_amount = max(maximum_amount, j -i +1);
            j++;
            sum += a[j];
        } else {
            sum -= a[i];
            i++;
        }
    }
    
    cout << maximum_amount;
    return 0;
}