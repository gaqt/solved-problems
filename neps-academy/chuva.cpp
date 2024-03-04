// https://neps.academy/br/exercise/58
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int h[n], peak_rev[n], peak[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    peak[0] = h[0];
    peak_rev[n-1] = h[n-1];

    for (int i = n-2; i > 0; i--)
        peak_rev[i] = max(h[i], peak_rev[i+1]);

    for (int i = 1; i < n; i++)
        peak[i] = max(h[i], peak[i-1]);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] < min(peak[i], peak_rev[i]))
            res++;
    }

    cout << res << endl;

    return 0;
}
