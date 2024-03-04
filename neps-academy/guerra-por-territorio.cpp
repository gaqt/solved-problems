// https://neps.academy/br/exercise/237
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n], sum=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int idx=0, crr=0;
    while (crr < sum/2) {
        crr += a[idx];
        idx++;
    }

    cout << idx << endl;

    return 0;
}
