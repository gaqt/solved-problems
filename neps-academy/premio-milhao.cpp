// https://neps.academy/br/exercise/48
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    int res = INT_MAX;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum += a;

        if (sum >= 1000000) {
            res = min(res, i);
        }
    }

    cout << res << endl;

    return 0;
}
