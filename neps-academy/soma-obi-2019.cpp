// https://neps.academy/br/exercise/468
#include <iostream>
#include <sys/types.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int x[n+1];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    x[n] = -1;

    int64_t ans = 0;

    if (k == 0) {
        // n + (n-1) + (n-2) + ... = n(n+1)/2

        int64_t crr = 0;
        for (int i = 0; i < n+1; i++) {
            if (x[i] == 0)
                crr++;
            else {
                if (crr != 0)
                    ans += crr*(crr+1)/2;

                crr = 0;
            }
        }

        cout << ans << endl;
        return 0;
    }

    // bz = back zeroes
    int64_t bz=0, sum=x[0];
    int l=0, r=0;

    while (r < n) {
        while (x[r+1] == 0) {
            r++;
            bz++;
        }

        if (sum < k) {
            sum += x[++r];
            bz = 0;
        } else if (sum > k) {
            sum -= x[l++];
        } else {
            ans += bz+1;
            sum -= x[l++];
        }

        if (l > r) {
            r = l;
            sum = x[r];
        }
    }

    cout << ans << endl;

    return 0;
}
