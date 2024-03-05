// https://neps.academy/br/exercise/169
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int diff[n+1];
    for (int i = 0; i < n+1; i++)
        diff[i] = 0;

    long og_sum = 0;

    for (int i = 0; i < m; i++) {
        int x, v, y;
        cin >> x >> v >> y;

        diff[x] -= v;
        diff[y] += v;

        og_sum += (long)v;
    }

    long new_sum = 0;

    for (int i = 1; i <= n; i++) {
        if (diff[i] <= 0) continue;

        new_sum += diff[i];
    }

    if (new_sum < og_sum)
        cout << "S";
    else
        cout << "N";
    cout << endl;

    cout << new_sum << endl;

    return 0;
}
